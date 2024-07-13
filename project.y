%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

// Define a symbol table
struct symbol {
    char *name;
    char *type;
    bool isMethod;
    bool isInitialized;
    bool isClass;
    int scope;
};

struct symbol symbolTable[1000];
int symbolCount = 0;
int scope = 0;

void yyerror(const char *s);
extern FILE *yyin;
extern FILE *yyout;
extern int yylex();
extern int yylineno;
extern char *yytext;

// Function to add a symbol to the symbol table
void addSymbol(char *name, char *type, bool isMethod, bool isInitialized, bool isClass) {
    if (name == NULL || type == NULL) {
        fprintf(stderr, "Error: Null pointer in addSymbol function\n");
        exit(1);
    }

    // Check for duplicate symbol in the current scope
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0 && symbolTable[i].scope == scope) {
            fprintf(stderr, "Error: Duplicate symbol '%s' declared in the current scope\n", name);
            exit(1);
        }
    }

    symbolTable[symbolCount].name = strdup(name);
    symbolTable[symbolCount].type = strdup(type);
    symbolTable[symbolCount].isMethod = isMethod;
    symbolTable[symbolCount].isInitialized = isInitialized;
    symbolTable[symbolCount].isClass = isClass;
    symbolTable[symbolCount].scope = scope;
    symbolCount++;

    // Print the symbol table
    printf("Symbol table:\n");
    for (int i = 0; i < symbolCount; i++) {
        printf("Name: %s, Type: %s, isMethod: %d, isInitialized: %d, Scope: %d\n, isClass: %d\n\n",
               symbolTable[i].name, symbolTable[i].type, symbolTable[i].isMethod,
               symbolTable[i].isInitialized, symbolTable[i].scope, symbolTable[i].isClass);
    }
}

// Function to check if a symbol is in the symbol table
bool symbolExists(char *name, bool isMethod, bool isClass) {
    if (name == NULL) {
        fprintf(stderr, "Error: Null pointer in symbolExists function\n");
        exit(1);
    }
    for (int i = 0; i < symbolCount; i++) {
        if (symbolTable[i].name != NULL && strcmp(symbolTable[i].name, name) == 0 && symbolTable[i].isMethod == isMethod && symbolTable[i].isClass == isClass && symbolTable[i].scope <= scope) {
            return true;
        }
    }
    return false;
}

bool classExists(char *name) {
    if (name == NULL) {
        fprintf(stderr, "Error: Null pointer in classExists function\n");
        exit(1);
    }
    for (int i = 0; i < symbolCount; i++) {
        if (symbolTable[i].name != NULL && strcmp(symbolTable[i].name, name) == 0 && symbolTable[i].isClass) {
            return true;
        }
    }
    return false;
}

// Function to check if a variable has been initialized
bool isInitialized(char *name) {
    if (name == NULL) {
        fprintf(stderr, "Error: Null pointer in isInitialized function\n");
        exit(1);
    }
    for (int i = 0; i < symbolCount; i++) {
        if (symbolTable[i].name != NULL && strcmp(symbolTable[i].name, name) == 0 && symbolTable[i].scope <= scope) {
            return symbolTable[i].isInitialized;
        }
    }
    return false;
}

// Function to set a variable as initialized
void setInitialized(char *name) {
    if (name == NULL) {
        fprintf(stderr, "Error: Null pointer in setInitialized function\n");
        exit(1);
    }
    for (int i = 0; i < symbolCount; i++) {
        if (symbolTable[i].name != NULL && strcmp(symbolTable[i].name, name) == 0 && symbolTable[i].scope == scope) {
            symbolTable[i].isInitialized = true;
        }
    }
}

// Function to increase the scope
void increaseScope() {
    scope++;
}

// Function to decrease the scope
void decreaseScope() {
    scope--;
    // Remove all symbols in the symbol table that are out of scope
    int i = 0;
    while (i < symbolCount) {
        if (symbolTable[i].scope > scope && !symbolTable[i].isClass) {
            free(symbolTable[i].name);
            free(symbolTable[i].type);
            // Shift all elements to the left
            for (int j = i; j < symbolCount - 1; j++) {
                symbolTable[j] = symbolTable[j + 1];
            }
            symbolCount--;
        } else {
            i++;
        }
    }
    // Free the memory allocated for the name and type of the last symbol
    if (symbolCount > 0) {
        free(symbolTable[symbolCount - 1].name);
        free(symbolTable[symbolCount - 1].type);
    }
}

// Function to get the type of a variable
char* getType(char *name) {
    if (name == NULL) {
        fprintf(stderr, "Error: Null pointer in getType function\n");
        exit(1);
    }
    for (int i = 0; i < symbolCount; i++) {
        if (symbolTable[i].name != NULL && strcmp(symbolTable[i].name, name) == 0 && symbolTable[i].scope == scope) {
            return symbolTable[i].type;
        }
    }
    return NULL;
}

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
%token LP RP
%token LSB RSB
%token LCB RCB
%token ASSIGN
%left OR
%left AND
%left EQ NEQ
%left LT LE GT GE
%left ADD SUB
%left MUL DIV MOD
%right POW
%right NOT

%type <sval> data_type
%type <sval> assignment_list_int
%type <sval> assignment_list_string
%type <sval> assignment_list_variable
%type <sval> assignment_list_method
%type <sval> assignment_list_object
%type variable_declaration
%type <sval> member_access
%type <sval> member_access_body
%type <sval> variable_reference
%type <sval> method_call
%type identifier_list

%%

program: /* nothing */
    | class_declaration none_or_newlines program
    | statement none_or_newlines program
    ;

class_declaration: access_modifier CLASS CLASS_ID LCB { increaseScope(); addSymbol($3, "class", false, true, true); } none_or_newlines class_body none_or_newlines RCB { decreaseScope(); }
    | CLASS CLASS_ID LCB { increaseScope(); addSymbol($2, "class", false, true, true); } none_or_newlines class_body none_or_newlines RCB { decreaseScope(); }
    ;

class_body: /* nothing */
    | class_declaration none_or_newlines class_body
    | statement none_or_newlines class_body
    ;

identifier_list: INTEGER identifier_list_int
    | STRING identifier_list_string
    | CHAR identifier_list_char
    | DOUBLE identifier_list_double
    | BOOLEAN identifier_list_boolean
    | VAR identifier_list_variable
    ;

identifier_list_int: ID { addSymbol($1, "int", false, false, false); }
    | ID COMMA identifier_list_int { addSymbol($1, "int", false, false, false); }
    ;

identifier_list_string: ID { addSymbol($1, "string", false, false, false); }
    | ID COMMA identifier_list_string { addSymbol($1, "string", false, false, false); }
    ;

identifier_list_char: ID { addSymbol($1, "char", false, false, false); }
    | ID COMMA identifier_list_char { addSymbol($1, "char", false, false, false); }
    ;

identifier_list_double: ID { addSymbol($1, "double", false, false, false); }
    | ID COMMA identifier_list_double { addSymbol($1, "double", false, false, false); }
    ;

identifier_list_boolean: ID { addSymbol($1, "boolean", false, false, false); }
    | ID COMMA identifier_list_boolean { addSymbol($1, "boolean", false, false, false); }
    ;

identifier_list_variable: ID { addSymbol($1, "var", false, false, false); }
    | ID COMMA identifier_list_variable { addSymbol($1, "var", false, false, false); }
    ;

// Modify your assignment_list rule to check the type of the variable and the expression
assignment_list: INTEGER assignment_list_int
    | STRING assignment_list_string
    | CHAR assignment_list_char
    | DOUBLE assignment_list_double
    | BOOLEAN assignment_list_boolean
    | VAR assignment_list_variable
    | VAR assignment_list_method
    | VAR assignment_list_object
    ;

assignment_list_int: ID ASSIGN exp { addSymbol($1, "int", false, true, false); }
    | ID ASSIGN exp COMMA assignment_list_int { addSymbol($1, "int", false, true, false); }
    ;

assignment_list_string: ID ASSIGN DQ_STRING_DQ { addSymbol($1, "string", false, true, false); }
    | ID ASSIGN DQ_STRING_DQ COMMA assignment_list_string { addSymbol($1, "string", false, true, false); }
    ;

assignment_list_char: ID ASSIGN SQ_ANYCHAR_SQ { addSymbol($1, "char", false, true, false); }
    | ID ASSIGN SQ_ANYCHAR_SQ COMMA assignment_list_char { addSymbol($1, "char", false, true, false); }
    ;

assignment_list_double: ID ASSIGN DOUBLE_CONST { addSymbol($1, "double", false, true, false); }
    | ID ASSIGN DOUBLE_CONST COMMA assignment_list_double { addSymbol($1, "double", false, true, false); }
    ;

assignment_list_boolean: ID ASSIGN boolean { addSymbol($1, "boolean", false, true, false); }
    | ID ASSIGN boolean COMMA assignment_list_boolean { addSymbol($1, "boolean", false, true, false); }
    ;

assignment_list_variable: ID ASSIGN variable_reference { char* type = getType($3); addSymbol($1, type, false, true, false); }
    | ID ASSIGN variable_reference COMMA assignment_list_variable { char* type = getType($3); addSymbol($1, type, false, true, false); }
    ;

assignment_list_method: ID ASSIGN method_call { char* type = getType($3); addSymbol($1, type, false, true, false); }
    | ID ASSIGN method_call COMMA assignment_list_method { char* type = getType($3); addSymbol($1, type, false, true, false); }
    ;

assignment_list_object: ID ASSIGN NEW CLASS_ID { addSymbol($1, "class", false, true, false); }
    | ID ASSIGN NEW CLASS_ID COMMA assignment_list_object { addSymbol($1, "class", false, true, false); }
    ;

assignment_list_declared: assignment_list_int_declared
    | assignment_list_string_declared
    | assignment_list_char_declared
    | assignment_list_double_declared
    | assignment_list_boolean_declared
    | assignment_list_variable_declared
    | assignment_list_method_declared
    | assignment_list_object_declared
    ;

assignment_list_int_declared: ID ASSIGN exp { char* type = getType($1); if (type == NULL || strcmp(type, "int") != 0) { yyerror("Type mismatch"); } setInitialized($1); }
    | ID ASSIGN exp COMMA assignment_list_int_declared { char* type = getType($1); if (type == NULL || strcmp(type, "int") != 0) { yyerror("Type mismatch"); } setInitialized($1); }
    ;

assignment_list_string_declared: ID ASSIGN DQ_STRING_DQ { char* type = getType($1); if (type == NULL || strcmp(type, "string") != 0) { yyerror("Type mismatch"); } setInitialized($1); }
    | ID ASSIGN DQ_STRING_DQ COMMA assignment_list_string { char* type = getType($1); if (type == NULL || strcmp(type, "string") != 0) { yyerror("Type mismatch"); } setInitialized($1); }
    ;

assignment_list_char_declared: ID ASSIGN SQ_ANYCHAR_SQ { char* type = getType($1); if (type == NULL || strcmp(type, "char") != 0) { yyerror("Type mismatch"); } setInitialized($1); }
    | ID ASSIGN SQ_ANYCHAR_SQ COMMA assignment_list_char { char* type = getType($1); if (type == NULL || strcmp(type, "char") != 0) { yyerror("Type mismatch"); } setInitialized($1); }
    ;

assignment_list_double_declared: ID ASSIGN DOUBLE_CONST { char* type = getType($1); if (type == NULL || strcmp(type, "double") != 0) { yyerror("Type mismatch"); } setInitialized($1); }
    | ID ASSIGN DOUBLE_CONST COMMA assignment_list_double { char* type = getType($1); if (type == NULL || strcmp(type, "double") != 0) { yyerror("Type mismatch"); } setInitialized($1); }
    ;

assignment_list_boolean_declared: ID ASSIGN boolean { char* type = getType($1); if (type == NULL || strcmp(type, "boolean") != 0) { yyerror("Type mismatch"); } setInitialized($1); }
    | ID ASSIGN boolean COMMA assignment_list_boolean { char* type = getType($1); if (type == NULL || strcmp(type, "boolean") != 0) { yyerror("Type mismatch"); } setInitialized($1); }
    ;

assignment_list_variable_declared: ID ASSIGN variable_reference { char* type = getType($1); if (type == NULL || strcmp(type, getType($3)) != 0) { yyerror("Type mismatch"); } setInitialized($1); }
    | ID ASSIGN variable_reference COMMA assignment_list_variable { char* type = getType($1); if (type == NULL || strcmp(type, getType($3)) != 0) { yyerror("Type mismatch"); } setInitialized($1); }
    ;

assignment_list_method_declared: ID ASSIGN method_call { char* type = getType($1); if (type == NULL || strcmp(type, getType($3)) != 0) { yyerror("Type mismatch"); } setInitialized($1); }
    | ID ASSIGN method_call COMMA assignment_list_method { char* type = getType($1); if (type == NULL || strcmp(type, getType($3)) != 0) { yyerror("Type mismatch"); } setInitialized($1); }
    ;

assignment_list_object_declared: ID ASSIGN NEW CLASS_ID { char* type = getType($1); if (type == NULL || strcmp(type, $4) != 0) { yyerror("Type mismatch"); } setInitialized($1); }
    | ID ASSIGN NEW CLASS_ID COMMA assignment_list_object { char* type = getType($1); if (type == NULL || strcmp(type, $4) != 0) { yyerror("Type mismatch"); } setInitialized($1); }
    ;

// Modify your variable_declaration rule to add symbols to the symbol table
variable_declaration: identifier_list
    | access_modifier identifier_list
    | access_modifier assignment_list
    | assignment_list
    | assignment_list_declared
    ;

// Modify your variable_reference rule to check symbols against the symbol table
variable_reference: ID { if (!symbolExists($1, false, false)) { yyerror("Variable not declared"); } else if (!isInitialized($1)) { yyerror("Variable not initialized"); } }
    ;

// Modify your method_declaration rule to add symbols to the symbol table
method_declaration: access_modifier data_type ID LP { increaseScope(); } none_or_newlines none_or_multiple_parameters none_or_newlines RP LCB none_or_newlines method_body none_or_newlines RCB { addSymbol("sum", $2, true, true, false); decreaseScope(); }
    | data_type ID LP { increaseScope(); } none_or_newlines none_or_multiple_parameters none_or_newlines RP LCB none_or_newlines method_body none_or_newlines RCB { addSymbol($2, $1, true, true, false); decreaseScope(); }
    ;

none_or_multiple_parameters: /* nothing */
    | parameter parameters
    ;

parameters: /* nothing */
    | COMMA none_or_newlines parameter parameters
    ;

parameter: data_type ID { addSymbol($2, $1, false, true, false); }
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
    | member_access none_or_newlines statement
    ;

assignment_statement: data_type ID ASSIGN exp
    | data_type ID ASSIGN variable_reference
    ;

// Modify your method_call rule to check symbols against the symbol table
method_call: ID LP none_or_newlines none_or_multiple_arguments none_or_newlines RP SEMICOLON { if (!symbolExists($1, true, false)) { yyerror("Method not declared"); } }
    ;

none_or_multiple_arguments: /* nothing */
    | parameter arguments
    | variable_reference arguments
    ;

arguments: /* nothing */
    | COMMA none_or_newlines parameter arguments
    | COMMA none_or_newlines variable_reference arguments
    ;

if_statement: IF LP  none_or_newlines if_elif_parenthesis_statement none_or_newlines RP LCB none_or_newlines statement none_or_newlines RCB none_or_newlines none_or_multiple_elif none_or_newlines none_or_one_else
    ;

if_elif_parenthesis_statement: exp
    | relational_exp
    | variable_reference
    | method_call
    | boolean
    ;

none_or_multiple_elif: /* nothing */
    | ELIF LP if_elif_parenthesis_statement RP LCB none_or_newlines statement none_or_newlines RCB none_or_multiple_elif
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
    | variable_declaration
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
    | COMMA ID single_or_multiple_variables { if (!symbolExists($2, false, false)) { yyerror("Variable not declared"); } else if (!isInitialized($2)) { yyerror("Variable not initialized"); } }
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
    | variable_reference
    | LP exp RP
    | LP relational_exp RP
    ;

object_creation: CLASS_ID ID ASSIGN NEW CLASS_ID { if (!classExists($1)) { yyerror("Class not declared"); } } LP RP SEMICOLON
    ;

member_access: ID DOT member_access_body { if (!symbolExists($1, false, true)) { yyerror("Class not declared"); } if (!symbolExists($3, false, false)) { yyerror("Member not declared"); } } none_or_newlines
    ;

member_access_body: ID SEMICOLON { if (!symbolExists($1, false, false)) { yyerror("Variable not declared"); } }
    | method_call { if (!symbolExists($1, true, false)) { yyerror("Method not declared"); } }
    ;

access_modifier: PUBLIC
    | PRIVATE
    ;

boolean: TRUE
    | FALSE
    ;

data_type: /* nothing */ { $$ = ""; }
    | INTEGER { $$ = "int"; }
    | CHAR { $$ = "char"; }
    | DOUBLE { $$ = "double"; }
    | BOOLEAN { $$ = "boolean"; }
    | STRING { $$ = "string"; }
    | VOID { $$ = "void"; }
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
        printf("Program is syntactically correct.\n\n");
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