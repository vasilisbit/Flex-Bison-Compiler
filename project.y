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

assignment_list: ID ASSIGN exp
    | ID ASSIGN exp COMMA assignment_list
    | ID ASSIGN DQ_STRING_DQ
    | ID ASSIGN DQ_STRING_DQ COMMA assignment_list
    | ID ASSIGN variable_reference
    | ID ASSIGN variable_reference COMMA assignment_list
    | ID ASSIGN method_call
    | ID ASSIGN method_call COMMA assignment_list
    | ID ASSIGN object_creation
    | ID ASSIGN object_creation COMMA assignment_list
    ;

variable_declaration: data_type identifier_list
    | access_modifier data_type identifier_list
    | access_modifier data_type assignment_list
    | data_type assignment_list
    | assignment_list
    ;

variable_reference: ID
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
    | method_call none_or_newlines statement
    | if_statement none_or_newlines statement
    | do_while_statement none_or_newlines statement
    | for_statement none_or_newlines statement
    | switch_statement none_or_newlines statement
    | return_statement none_or_newlines statement
    | break_statement none_or_newlines statement
    | print_statement none_or_newlines statement
    | exp SEMICOLON none_or_newlines statement
    | relational_exp SEMICOLON none_or_newlines statement
    | DQ_STRING_DQ SEMICOLON none_or_newlines statement
    | variable_declaration SEMICOLON none_or_newlines statement
    | method_declaration none_or_newlines statement
    | object_creation none_or_newlines statement
    | variable_reference SEMICOLON none_or_newlines statement
    ;

assignment_statement: data_type ID ASSIGN exp
    | data_type ID ASSIGN variable_reference
    ;

method_call: ID LP none_or_newlines none_or_multiple_arguments none_or_newlines RP SEMICOLON
    ;

none_or_multiple_arguments: /* nothing */
    | parameter arguments
    | variable_reference arguments
    ;

arguments: /* nothing */
    | COMMA none_or_newlines parameter arguments
    | COMMA none_or_newlines variable_reference arguments
    ;

if_statement: IF LP none_or_newlines exp none_or_newlines RP LCB none_or_newlines statement none_or_newlines RCB none_or_newlines none_or_multiple_elif none_or_newlines none_or_one_else
    | IF LP none_or_newlines relational_exp none_or_newlines RP LCB none_or_newlines statement none_or_newlines RCB none_or_newlines none_or_multiple_elif none_or_newlines none_or_one_else
    | IF LP none_or_newlines variable_reference none_or_newlines RP LCB none_or_newlines statement none_or_newlines RCB none_or_newlines none_or_multiple_elif none_or_newlines none_or_one_else
    | IF LP none_or_newlines method_call none_or_newlines RP LCB none_or_newlines statement none_or_newlines RCB none_or_newlines none_or_multiple_elif none_or_newlines none_or_one_else
    ;

none_or_multiple_elif: /* nothing */
    | ELIF LP exp RP LCB none_or_newlines statement none_or_newlines RCB none_or_multiple_elif
    | ELIF LP relational_exp RP LCB none_or_newlines statement none_or_newlines RCB none_or_multiple_elif
    | ELIF LP variable_reference RP LCB none_or_newlines statement none_or_newlines RCB none_or_multiple_elif
    | ELIF LP method_call RP LCB none_or_newlines statement none_or_newlines RCB none_or_multiple_elif
    ;

none_or_one_else: /* nothing */
    | ELSE LCB none_or_newlines statement none_or_newlines RCB
    ;

do_while_statement: DO LCB none_or_newlines statement none_or_newlines RCB WHILE LP none_or_newlines relational_exp none_or_newlines RP SEMICOLON
    | DO LCB none_or_newlines statement none_or_newlines RCB WHILE LP none_or_newlines variable_reference none_or_newlines RP SEMICOLON
    ;

for_statement: FOR LP none_or_newlines first_and_third_loop_statement SEMICOLON none_or_newlines second_loop_statement SEMICOLON none_or_newlines first_and_third_loop_statement none_or_newlines RP LCB none_or_newlines statement none_or_newlines RCB
    ;

first_and_third_loop_statement: /* nothing */
    | assignment_statement
    ;

second_loop_statement: /* nothing */
    | relational_exp
    ;

switch_statement: SWITCH LP none_or_newlines exp none_or_newlines RP LCB none_or_newlines one_or_more_cases none_or_newlines default_case none_or_newlines RCB
    | SWITCH LP none_or_newlines SQ_ANYCHAR_SQ none_or_newlines RP LCB none_or_newlines one_or_more_cases none_or_newlines default_case none_or_newlines RCB
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
    | SQ_ANYCHAR_SQ
    ;

return_statement: RETURN exp SEMICOLON
    | RETURN variable_reference SEMICOLON
    | RETURN method_call SEMICOLON
    ;

break_statement: BREAK SEMICOLON
    ;

print_statement: PRINT LP DQ_STRING_DQ single_or_multiple_variables RP SEMICOLON
    ;

single_or_multiple_variables: /* nothing */
    | COMMA ID single_or_multiple_variables
    ;

exp: factor
    | exp ADD factor
    | exp SUB factor
    ;

factor: term
    | factor MUL term
    | factor DIV term
    | factor MOD term
    ;

term: unary
    | term POW unary
    ;

relational_exp: relational_factor
    | relational_exp EQ relational_factor
    | relational_exp NEQ relational_factor
    | relational_exp LT relational_factor
    | relational_exp GT relational_factor
    | relational_exp LE relational_factor
    | relational_exp GE relational_factor
    ;

relational_factor: logical_term
    | relational_factor AND logical_term
    | relational_factor OR logical_term
    ;

logical_term: unary
    | NOT unary
    ;

unary: primary
    | ADD primary
    | SUB primary
    ;

primary: CONST
    | DOUBLE_CONST
    | variable_reference
    | LP exp RP
    | LP relational_exp RP
    ;

object_creation: CLASS_ID ID ASSIGN NEW CLASS_ID LP RP SEMICOLON
    ;

member_access: ID DOT member_access_body none_or_newlines
    ;

member_access_body: ID SEMICOLON
    | method_call
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

data_type: /* nothing */
    | INTEGER
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

string_expression: DQ_STRING_DQ
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