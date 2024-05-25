%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void yyerror(const char *s);
extern FILE *yyin;
extern FILE *yyout;
extern int yylex();
extern int yylineno;
extern char *yytext;

typedef enum {
    INTEGER_TYPE,
    CHAR_TYPE,
    DOUBLE_TYPE,
    BOOLEAN_TYPE,
    STRING_TYPE,
    VOID_TYPE
} DATA_TYPE;

typedef struct symbol{
    char *name;
    int type; // 0 for variable, 1 for method
    DATA_TYPE data_type;
} symbol;

symbol *symbol_table[1000];
int symbol_count = 0;

symbol* lookup(char *name);
void insert(char *name, int type, DATA_TYPE data_type);
%}

%union {
    int    ival;
    char   *cval;
    char   *sval;
    double dval;
}

%token <ival> CONST
%token <sval> ID CLASS_ID
%token <cval> ANY_CHARACTER
%token <dval> DOUBLE_CONST

%token VAR

%token NEWLINE

%token CLASS
%token PUBLIC PRIVATE
%token INTEGER CHAR DOUBLE BOOLEAN STRING VOID
%token NEW
%token RETURN
%token IF ELIF ELSE SWITCH CASE DEFAULT
%token WHILE DO FOR
%token BREAK
%token TRUE FALSE
%token PRINT
%token SQ_ANYCHAR_SQ DQ_STRING_DQ

%token SEMICOLON
%token COMMA
%token DOT
%token QUESTION COLON
%token DQ SQ
%left ADD SUB
%left MUL DIV MOD
%left POW
%token LP RP
%token LSB RSB
%token LCB RCB
%token ASSIGN
%token EQ NEQ LT GT LE GE
%token AND OR NOT

%%

program: /* nothing */
    | class_declaration none_or_newlines program
    | statement none_or_newlines program
    ;

class_declaration: access_modifier CLASS CLASS_ID LCB none_or_newlines class_body none_or_newlines RCB
    | CLASS CLASS_ID LCB none_or_newlines class_body none_or_newlines RCB
    ;

class_body: /* nothing */
    | class_declaration none_or_newlines class_body
    | statement none_or_newlines class_body
    ;

identifier_list: ID
    | ID COMMA identifier_list
    ;

assignment_list: ID ASSIGN expression {
        insert($1, 0);
    }
    | ID ASSIGN expression COMMA assignment_list {
        insert($1, 0);
    }
    ;

variable_declaration: data_type identifier_list {
        insert($2, 0, $1);
    }
    | access_modifier data_type identifier_list {
        insert($3, 0, $2);
    }
    | access_modifier data_type assignment_list
    | data_type assignment_list
    | assignment_list
    ;

variable_reference: ID {
    symbol *sym = lookup($1);
    if (!sym || sym->type != 0) {  // 0 for variable
        yyerror("Variable not declared");
        YYERROR;
    }
}

method_declaration: access_modifier data_type ID LP none_or_newlines none_or_multiple_parameters none_or_newlines RP LCB none_or_newlines method_body none_or_newlines RCB {
        insert($3, 1);
    }
    | data_type ID LP none_or_newlines none_or_multiple_parameters none_or_newlines RP LCB none_or_newlines method_body none_or_newlines RCB {
        insert($2, 1);
    }
    ;

none_or_multiple_parameters: /* nothing */
    | parameter parameters
    ;

parameters: /* nothing */
    | COMMA none_or_newlines parameter parameters
    ;

parameter: data_type ID
    ;

method_body: /* nothing */
    | statement none_or_newlines method_body
    ;

statement: /* nothing */
    | method_call none_or_newlines statement
    | if_statement none_or_newlines statement
    | do_while_statement none_or_newlines statement 
    | for_statement none_or_newlines statement
    | switch_statement none_or_newlines statement
    | return_statement none_or_newlines statement
    | break_statement none_or_newlines statement
    | print_statement none_or_newlines statement
    | expression SEMICOLON none_or_newlines statement
    | variable_declaration SEMICOLON none_or_newlines statement
    | method_declaration none_or_newlines statement
    | object_creation none_or_newlines statement
    | variable_reference SEMICOLON none_or_newlines statement
    ;

assignment_statement: data_type ID ASSIGN expression {
        symbol *sym = lookup($2);
        if (!sym) {
            yyerror("Variable not declared");
            YYERROR;
        }
        if (sym->data_type != $1) {
            yyerror("Data type mismatch");
            YYERROR;
        }
    }
    ;

method_call: ID LP none_or_newlines none_or_multiple_arguments none_or_newlines RP SEMICOLON {
        symbol *sym = lookup($1);
        if (!sym || sym->type != 1) {  // 1 for method
            yyerror("Method not declared");
            YYERROR;
        }
    }
    ;

none_or_multiple_arguments: /* nothing */
    | expression arguments
    ;

arguments: /* nothing */
    | COMMA none_or_newlines expression arguments
    ;

if_statement: IF LP none_or_newlines expression none_or_newlines RP LCB none_or_newlines statement none_or_newlines RCB none_or_newlines none_or_multiple_elif none_or_newlines none_or_one_else
    ;

none_or_multiple_elif: /* nothing */
    | ELIF LP expression RP LCB none_or_newlines statement none_or_newlines RCB none_or_multiple_elif
    ;

none_or_one_else: /* nothing */
    | ELSE LCB none_or_newlines statement none_or_newlines RCB
    ;

do_while_statement: DO LCB none_or_newlines statement none_or_newlines RCB WHILE LP none_or_newlines expression none_or_newlines RP SEMICOLON
    ;

for_statement: FOR LP none_or_newlines first_and_third_loop_statement SEMICOLON none_or_newlines second_loop_statement SEMICOLON none_or_newlines first_and_third_loop_statement none_or_newlines RP LCB none_or_newlines statement none_or_newlines RCB
    ;

first_and_third_loop_statement: /* nothing */
    | assignment_statement
    ;

second_loop_statement: /* nothing */
    | expression
    ;

switch_statement: SWITCH LP none_or_newlines expression none_or_newlines RP LCB none_or_newlines one_or_more_cases none_or_newlines default_case none_or_newlines RCB
    ;

default_case: /* nothing */
    | DEFAULT COLON none_or_newlines statement
    ;

one_or_more_cases: cases none_or_newlines multiple_cases
    ;

multiple_cases: /* nothing */
    | cases none_or_newlines multiple_cases
    ;

cases: CASE case_expression COLON none_or_newlines statement
    ;

case_expression: CONST
    | any_character
    | text
    ;

return_statement: RETURN expression SEMICOLON
    ;

break_statement: BREAK SEMICOLON
    ;

print_statement: PRINT LP text single_or_multiple_variables RP SEMICOLON
    ;

single_or_multiple_variables: /* nothing */
    | COMMA ID single_or_multiple_variables
    ;

expression: integer_expression { $$ = INTEGER_TYPE; }
    | any_character { $$ = CHAR_TYPE; }
    | double_expression { $$ = DOUBLE_TYPE; }
    | boolean_expression { $$ = BOOLEAN_TYPE; }
    | text { $$ = STRING_TYPE; }
    | variable_reference { $$ = lookup($1)->data_type; }
    | method_call { $$ = lookup($1)->data_type; }
    | operations { $$ = $1; }  // assuming operations returns a DATA_TYPE
    | member_access { $$ = $1; }  // assuming member_access returns a DATA_TYPE
    | LP expression RP { $$ = $2; }
    ;

text: DQ_STRING_DQ
    ;

any_character: SQ_ANYCHAR_SQ
    ;  

object_creation: CLASS_ID ID ASSIGN NEW CLASS_ID LP RP SEMICOLON
    ;

member_access: ID DOT member_access_body none_or_newlines
    ;

member_access_body: ID SEMICOLON
    | method_call
    ;

operations: integer_operations
    | char_operations
    | double_operations
    | boolean_operations
    ;

integer_operations: integer_expression relational_arithmetic_operations integer_expression
    ;

char_operations: any_character relational_arithmetic_operations any_character
    ;

double_operations: double_expression relational_arithmetic_operations double_expression
    ;

boolean_operations: boolean_expression logical_operators boolean_expression
    ;

relational_arithmetic_operations: arithmetic_operators
    | relational_operators
    ;

arithmetic_operators: ADD
    | SUB
    | MUL
    | DIV
    | MOD
    | POW
    ;

relational_operators: EQ
    | NEQ
    | LT
    | GT
    | LE
    | GE
    ;

logical_operators: AND
    | OR
    | NOT
    ;

access_modifier: PUBLIC
    | PRIVATE
    ;

data_type: INTEGER { $$ = INTEGER_TYPE; }
    | CHAR { $$ = CHAR_TYPE; }
    | DOUBLE { $$ = DOUBLE_TYPE; }
    | BOOLEAN { $$ = BOOLEAN_TYPE; }
    | STRING { $$ = STRING_TYPE; }
    | VOID { $$ = VOID_TYPE; }
    ;

integer_expression: CONST
    ;

double_expression: DOUBLE_CONST
    ;

boolean_expression: TRUE
    | FALSE
    ;

string_expression: text
    ;

none_or_newlines: /* nothing */
    | NEWLINE none_or_newlines
    ;
    
%%

symbol* lookup(char *name) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i]->name, name) == 0) {
            return symbol_table[i];
        }
    }
    return NULL;
}

void insert(char *name, int type) {
    symbol *sym = malloc(sizeof(symbol));
    sym->name = strdup(name);
    sym->type = type;
    sym->data_type = data_type;
    symbol_table[symbol_count++] = sym;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error on line %d: %s recognised at the token '%s'\n", yylineno, s, yytext);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (!f) {
        fprintf(stderr, "Cannot open file %s\n", argv[1]);
        return 1;
    }

    yyin = f;
    yyout = fopen("output.txt", "w");

    if (yyparse() == 0) {
        printf("Program is syntactically correct.\n");
        char ch;
        rewind(f); // Reset the file pointer to the beginning for reading
        while ((ch = fgetc(f)) != EOF) {
            putchar(ch);
            fputc(ch, yyout);
        }
    }

    fclose(f);

    return 0;
}