%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void yyerror(const char *s);
extern FILE *yyin;
extern FILE *yyout;
extern int yylex();
extern int yylineno;
extern char *yytext;
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
    | class_declaration program
    | statement none_or_newlines program
    ;

class_declaration: access_modifier CLASS CLASS_ID LCB none_or_newlines class_body none_or_newlines RCB
    | CLASS CLASS_ID LCB none_or_newlines class_body none_or_newlines RCB
    ;

class_body: /* nothing */
    | class_declaration none_or_newlines class_body
    | statement none_or_newlines class_body
    ;

variable_declaration: data_type ID SEMICOLON
    | access_modifier data_type ID SEMICOLON
    ;

method_declaration: access_modifier data_type ID LP none_or_newlines none_or_multiple_parameters none_or_newlines RP LCB none_or_newlines method_body none_or_newlines RCB
    | data_type ID LP none_or_newlines none_or_multiple_parameters none_or_newlines RP LCB none_or_newlines method_body none_or_newlines RCB
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
    | assignment_statement SEMICOLON none_or_newlines statement
    | method_call SEMICOLON none_or_newlines statement
    | if_statement none_or_newlines statement
    | do_while_statement none_or_newlines statement 
    | for_statement none_or_newlines statement
    | switch_statement none_or_newlines statement
    | return_statement none_or_newlines statement
    | break_statement none_or_newlines statement
    | print_statement none_or_newlines statement
    | expression SEMICOLON none_or_newlines statement
    | variable_declaration none_or_newlines statement
    | method_declaration none_or_newlines statement
    | object_creation none_or_newlines statement
    ;

assignment_statement: ID ASSIGN expression
    | INTEGER ID ASSIGN integer_expression
    | CHAR ID ASSIGN any_character
    | DOUBLE ID ASSIGN double_expression
    | BOOLEAN ID ASSIGN boolean_expression
    | STRING ID ASSIGN string_expression
    ;

method_call: ID LP none_or_newlines none_or_multiple_arguments none_or_newlines RP
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

expression: integer_expression
    | any_character
    | double_expression
    | boolean_expression
    | text
    | ID
    | method_call
    | operations
    | member_access
    | LP expression RP
    ;

text: DQ_STRING_DQ
    ;

any_character: SQ_ANYCHAR_SQ
    ;  

object_creation: CLASS_ID ID ASSIGN NEW CLASS_ID LP RP SEMICOLON
    ;

member_access: ID DOT member_access_body
    ;

member_access_body: ID SEMICOLON
    | method_call SEMICOLON
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

data_type: INTEGER
    | CHAR
    | DOUBLE
    | BOOLEAN
    | STRING
    | VOID
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