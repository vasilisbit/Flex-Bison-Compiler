%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "error.h"
#include <errno.h>
#include <unistd.h>
#include <sys/ioctl.h>

// Define a symbol table
struct symbol {
    char *name;
    char *type;
    bool isMethod;
    bool isInitialized;
    bool isClass;
    int scope;
    char *value;
};

// Define a structure to store assignment information
struct assignment {
    char *variable;
    char *value;
};

struct assignment assignments[5000];
int assignmentCount = 0;

struct symbol symbolTable[5000];
int symbolCount = 0;
int scope = 0;

void yyerror(const char *s);
extern FILE *yyin;
extern FILE *yyout;
extern int yylex();
extern int yylineno;
extern char *yytext;

void log_message(const char* function_name, const char* message) {
    FILE* log_file = fopen("parser_log.txt", "a");
    if (log_file == NULL) {
        fprintf(stderr, "Error opening log file: %s\n", strerror(errno));
        return;
    }
    fprintf(log_file, "[%s] %s\n", function_name, message);
    fclose(log_file);
}

int get_terminal_width() {
    struct winsize w;
    log_message("get_terminal_width", "Debug: Calling ioctl to get terminal size...");
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1) {
        perror("ioctl");
        log_message("get_terminal_width", "Debug: ioctl failed, returning default width 80.\n");
        return 80; // Default width if ioctl fails
    }
    char message[50];
    snprintf(message, sizeof(message), "Debug: ioctl succeeded, terminal width is %d.\n", w.ws_col);
    log_message("get_terminal_width", message);
    return w.ws_col;
}

// Function to add an assignment to the list
void addAssignment(char *variable, char *value) {
    if (assignmentCount < 5000) {
        assignments[assignmentCount].variable = strdup(variable);
        assignments[assignmentCount].value = strdup(value);
        assignmentCount++;
    } else {
        fprintf(stderr, "Error: Too many assignments\n");
        exit(1);
    }
}

// Function to print all assignments
void printAssignments() {
    if (assignmentCount > 0) {
        printf("Collected Assignments:\n");
        for (int i = 0; i < assignmentCount; i++) {
            printf("%d) Variable %s assigned with value %s\n", i + 1, assignments[i].variable, assignments[i].value);
        }
    }
}

// Function to add a symbol to the symbol table
void addSymbol(char *name, char *type, bool isMethod, bool isInitialized, bool isClass, char *value) {
    log_message("addSymbol", "Entering addSymbol function");

    if (name == NULL || type == NULL) {
        log_message("addSymbol", "Null pointer in addSymbol function\n");
        yyerror("Null pointer in addSymbol function");
        return;
    }

    if (symbolCount >= 5000) {
        log_message("addSymbol", "Symbol table full\n");
        yyerror("Symbol table full");
        return;
    }

    // Check for duplicate symbol in the current scope
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0 && symbolTable[i].scope == scope) {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "Duplicate symbol declared: %s\n", name);
            log_message("addSymbol", error_msg);
            yyerror(error_msg);
            return;
        }
    }

    symbolTable[symbolCount].name = strdup(name);
    if (symbolTable[symbolCount].name == NULL) {
        log_message("addSymbol", "Memory allocation failed for symbol name\n");
        yyerror("Memory allocation failed");
        return;
    }

    symbolTable[symbolCount].type = strdup(type);
    if (symbolTable[symbolCount].type == NULL) {
        log_message("addSymbol", "Memory allocation failed for symbol type\n");
        yyerror("Memory allocation failed");
        free(symbolTable[symbolCount].name);
        return;
    }

    symbolTable[symbolCount].isMethod = isMethod;
    symbolTable[symbolCount].isInitialized = isInitialized;
    symbolTable[symbolCount].isClass = isClass;
    symbolTable[symbolCount].scope = scope;

    if (value) {
        symbolTable[symbolCount].value = strdup(value);
        if (symbolTable[symbolCount].value == NULL) {
            log_message("addSymbol", "Memory allocation failed for symbol value\n");
            yyerror("Memory allocation failed");
            free(symbolTable[symbolCount].name);
            free(symbolTable[symbolCount].type);
            return;
        }
    } else {
        symbolTable[symbolCount].value = strdup("UNINITIALIZED");
        if (symbolTable[symbolCount].value == NULL) {
            log_message("addSymbol", "Memory allocation failed for symbol value\n");
            yyerror("Memory allocation failed");
            free(symbolTable[symbolCount].name);
            free(symbolTable[symbolCount].type);
            return;
        }
    }

    symbolCount++;

    char log_msg[200];
    snprintf(log_msg, sizeof(log_msg), "Added symbol: name=%s, type=%s, isMethod=%d, isInitialized=%d, isClass=%d, scope=%d, value=%s\n",
             name, type, isMethod, isInitialized, isClass, scope, value ? value : "UNINITIALIZED");
    log_message("addSymbol", log_msg);
}

// Function to check if a symbol is in the symbol table
bool symbolExists(char *name, bool isMethod, bool isClass) {
    log_message("symbolExists", "Entering symbolExists function");
    if (name == NULL) {
        log_message("symbolExists", "Null pointer in function\n");
        yyerror("Null pointer in symbolExists function");
        return false;
    }
    for (int i = 0; i < symbolCount; i++) {
        if (symbolTable[i].name != NULL && strcmp(symbolTable[i].name, name) == 0 &&
            symbolTable[i].isMethod == isMethod && symbolTable[i].isClass == isClass &&
            symbolTable[i].scope <= scope) {
            log_message("symbolExists", "Symbol found\n");
            return true;
        }
    }
    log_message("symbolExists", "Symbol not found\n");
    return false;
}

// Function to check if a variable has been initialized
bool isInitialized(char *name) {
    log_message("isInitialized", "Entering isInitialized function");
    if (name == NULL) {
        log_message("isInitialized", "Null pointer in function\n");
        yyerror("Null pointer in isInitialized function\n");
        return false;
    }
    for (int i = 0; i < symbolCount; i++) {
        if (symbolTable[i].name != NULL && strcmp(symbolTable[i].name, name) == 0 && symbolTable[i].scope <= scope) {
            log_message("isInitialized", name);
            log_message("isInitialized", "\n");
            return symbolTable[i].isInitialized;
        }
    }
    log_message("isInitialized", "Variable not found\n");
    return false;
}

// Function to set a variable as initialized
void setInitialized(char *name, char *value) {
    log_message("setInitialized", "Entering setInitialized function");
    if (name == NULL) {
        log_message("setInitialized", "Null pointer in function\n");
        yyerror("Null pointer in setInitialized function\n");
        return;
    }
    for (int i = 0; i < symbolCount; i++) {
        if (symbolTable[i].name != NULL && strcmp(symbolTable[i].name, name) == 0 && symbolTable[i].scope == scope) {
            symbolTable[i].isInitialized = true;
            if (value != NULL) {
                if (symbolTable[i].value != NULL){
                    free(symbolTable[i].value);
                }
                symbolTable[i].value = strdup(value);
                if (symbolTable[i].value == NULL) {
                    log_message("setInitialized", "Memory allocation failed for value\n");
                    yyerror("Memory allocation failed in setInitialized");
                    return;
                }
            }
            char log_msg[100];
            snprintf(log_msg, sizeof(log_msg), "Variable %s initialized with value %s\n", name, value ? value : "NULL");
            log_message("setInitialized", log_msg);
            return;
        }
    }
    log_message("setInitialized", "Variable not found\n");
}

// Function to increase the scope
void increaseScope() {
    scope++;
    char log_msg[50];
    snprintf(log_msg, sizeof(log_msg), "Scope increased to %d\n", scope);
    log_message("increaseScope", log_msg);
}

// Function to decrease the scope
void decreaseScope() {
    scope--;
    char log_msg[50];
    snprintf(log_msg, sizeof(log_msg), "Scope decreased to %d\n", scope);
    log_message("decreaseScope", log_msg);
}

// Function to get the type of a variable
char* getType(char *name) {
    log_message("getType", "Entering getType function");
    if (name == NULL) {
        log_message("getType", "Null pointer in function\n");
        yyerror("Null pointer in getType function\n");
        return NULL;
    }
    for (int i = 0; i < symbolCount; i++) {
        if (symbolTable[i].name != NULL && strcmp(symbolTable[i].name, name) == 0 && symbolTable[i].scope <= scope) {
            char log_msg[100];
            snprintf(log_msg, sizeof(log_msg), "Type of %s is %s\n", name, symbolTable[i].type);
            log_message("getType", log_msg);
            return symbolTable[i].type;
        }
    }
    log_message("getType", "Variable not found\n");
    yyerror("Variable not declared");
    return NULL;
}

// Function to get the value of a variable
char* getValue(char *name) {
    log_message("getValue", "Entering getValue function");
    if (name == NULL) {
        log_message("getValue", "Null pointer in function\n");
        yyerror("Null pointer in getValue function\n");
        return NULL;
    }
    for (int i = 0; i < symbolCount; i++) {
        if (symbolTable[i].name != NULL && strcmp(symbolTable[i].name, name) == 0 && symbolTable[i].scope <= scope) {
            char log_msg[100];
            snprintf(log_msg, sizeof(log_msg), "Value of %s is %s\n", name, symbolTable[i].value);
            log_message("getValue", log_msg);
            return symbolTable[i].value;
        }
    }
    log_message("getValue", "Variable not found\n");
    yyerror("Variable not declared");
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
%token <sval> ID CLASS_ID METHOD_ID
%token <dval> DOUBLE_CONST
%token <cval> SQ_ANYCHAR_SQ
%token <sval> DQ_STRING_DQ

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

%token SEMICOLON
%token COMMA
%token DOT
%token COLON
%token LP RP
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
%type <sval> assignment_list_method
%type <sval> assignment_list_object
%type variable_declaration
%type <sval> member_access
%type <sval> member_access_body
%type <sval> variable_reference
%type <sval> method_call
%type identifier_list
%type <ival> exp_int factor_int term_int unary primary_int
%type <sval> boolean
%type <dval> exp_double factor_double term_double primary_double

%%

program: /* nothing */
    | class_declaration none_or_newlines { log_message("program", "Entering program\n"); } program { log_message("program", "Exiting program\n"); }
    | statement none_or_newlines { log_message("program", "Entering program\n"); } program { log_message("program", "Exiting program\n"); }
    | error { log_message("program", "Entering program\n"); } program { log_message("program", "Exiting program\n"); yyerrok; }
    ;

class_declaration: access_modifier CLASS CLASS_ID LCB {
    log_message("class_declaration", "Entering class_declaration\n");
    addSymbol($3, "class", false, true, true, NULL);
    increaseScope();
    } none_or_newlines class_body none_or_newlines RCB { decreaseScope(); log_message("class_declaration", "Exiting class_declaration\n"); }
    | CLASS CLASS_ID LCB {
    log_message("class_declaration", "Entering class_declaration\n");
    addSymbol($2, "class", false, true, true, NULL);
    increaseScope();
    } none_or_newlines class_body none_or_newlines RCB { decreaseScope(); log_message("class_declaration", "Exiting class_declaration\n"); }
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

identifier_list_int: ID { addSymbol($1, "int", false, false, false, NULL); }
    | ID COMMA identifier_list_int { addSymbol($1, "int", false, false, false, NULL); }
    ;

identifier_list_string: ID { addSymbol($1, "string", false, false, false, NULL); }
    | ID COMMA identifier_list_string { addSymbol($1, "string", false, false, false, NULL); }
    ;

identifier_list_char: ID { addSymbol($1, "char", false, false, false, NULL); }
    | ID COMMA identifier_list_char { addSymbol($1, "char", false, false, false, NULL); }
    ;

identifier_list_double: ID { addSymbol($1, "double", false, false, false, NULL); }
    | ID COMMA identifier_list_double { addSymbol($1, "double", false, false, false, NULL); }
    ;

identifier_list_boolean: ID { addSymbol($1, "boolean", false, false, false, NULL); }
    | ID COMMA identifier_list_boolean { addSymbol($1, "boolean", false, false, false, NULL); }
    ;

identifier_list_variable: ID { addSymbol($1, "var", false, false, false, NULL); }
    | ID COMMA identifier_list_variable { addSymbol($1, "var", false, false, false, NULL); }
    ;

assignment_list: INTEGER assignment_list_int
    | STRING assignment_list_string
    | CHAR assignment_list_char
    | DOUBLE assignment_list_double
    | BOOLEAN assignment_list_boolean
    | VAR assignment_list_method
    | VAR assignment_list_object
    ;

assignment_list_int: ID ASSIGN exp_int {
    char valueStr[32];
    sprintf(valueStr, "%d", $3);
    addSymbol($1, "int", false, true, false, valueStr);
    addAssignment($1, valueStr);
    }
    | ID ASSIGN exp_int COMMA assignment_list_int {
    char valueStr[32]; sprintf(valueStr, "%d", $3);
    addSymbol($1, "int", false, true, false, valueStr);
    addAssignment($1, valueStr);
    };

assignment_list_string: ID ASSIGN DQ_STRING_DQ { addSymbol($1, "string", false, true, false, $3); }
    | ID ASSIGN DQ_STRING_DQ COMMA assignment_list_string { addSymbol($1, "string", false, true, false, $3); }
    ;

assignment_list_char: ID ASSIGN SQ_ANYCHAR_SQ { addSymbol($1, "char", false, true, false, $3); }
    | ID ASSIGN SQ_ANYCHAR_SQ COMMA assignment_list_char { addSymbol($1, "char", false, true, false, $3); }
    ;

assignment_list_double: ID ASSIGN exp_double {
    char valueStr[64];
    sprintf(valueStr, "%f", $3);
    addSymbol($1, "double", false, true, false, valueStr);
    addAssignment($1, valueStr);
    }
    | ID ASSIGN exp_double COMMA assignment_list_double {
    char valueStr[64];
    sprintf(valueStr, "%f", $3);
    addSymbol($1, "double", false, true, false, valueStr);
    addAssignment($1, valueStr);
    };

assignment_list_boolean: ID ASSIGN boolean { addSymbol($1, "boolean", false, true, false, $3); }
    | ID ASSIGN boolean COMMA assignment_list_boolean { addSymbol($1, "boolean", false, true, false, $3); }
    ;

assignment_list_method: ID ASSIGN method_call {
    char* type = getType($3);
    addSymbol($1, type, false, true, false, NULL);
    }
    | ID ASSIGN method_call COMMA assignment_list_method {
    char* type = getType($3);
    addSymbol($1, type, false, true, false, NULL);
    };

assignment_list_object: ID ASSIGN NEW CLASS_ID { addSymbol($1, "class", false, true, false, NULL); }
    | ID ASSIGN NEW CLASS_ID COMMA assignment_list_object { addSymbol($1, "class", false, true, false, NULL); }
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

assignment_list_int_declared: ID ASSIGN exp_int {
    char* type = getType($1);
    if (type == NULL || strcmp(type, "int") != 0) {
        yyerror("Type mismatch");
    } else {
        char valueStr[32];
        sprintf(valueStr, "%d", $3);
        setInitialized($1, valueStr);
        addAssignment($1, valueStr);
    }
    }
    | ID ASSIGN exp_int COMMA assignment_list_int_declared {
    char* type = getType($1);
    if (type == NULL || strcmp(type, "int") != 0) {
        yyerror("Type mismatch");
    } else {
        char valueStr[32];
        sprintf(valueStr, "%d", $3);
        setInitialized($1, valueStr);
        addAssignment($1, valueStr);
    }
    };

assignment_list_string_declared: ID ASSIGN DQ_STRING_DQ {
    char* type = getType($1);
    if (type == NULL || strcmp(type, "string") != 0) {
        yyerror("Type mismatch");
    } else {
        setInitialized($1, $3);
    }
    }
    | ID ASSIGN DQ_STRING_DQ COMMA assignment_list_string_declared {
    char* type = getType($1);
    if (type == NULL || strcmp(type, "string") != 0) {
        yyerror("Type mismatch");
    } else {
        setInitialized($1, $3);
    }
    };

assignment_list_char_declared: ID ASSIGN SQ_ANYCHAR_SQ {
    char* type = getType($1);
    if (type == NULL || strcmp(type, "char") != 0) {
        yyerror("Type mismatch");
    } else {
        setInitialized($1, $3);
    }
    }
    | ID ASSIGN SQ_ANYCHAR_SQ COMMA assignment_list_char_declared {
    char* type = getType($1);
    if (type == NULL || strcmp(type, "char") != 0) {
        yyerror("Type mismatch");
    } else {
        setInitialized($1, $3);
    }
    };

assignment_list_double_declared: ID ASSIGN exp_double {
    char* type = getType($1);
    if (type == NULL || strcmp(type, "double") != 0) {
        yyerror("Type mismatch");
    } else {
        char valueStr[64];
        sprintf(valueStr, "%f", $3);
        setInitialized($1, valueStr);
        addAssignment($1, valueStr);
    }
    }
    | ID ASSIGN exp_double COMMA assignment_list_double_declared {
    char* type = getType($1);
    if (type == NULL || strcmp(type, "double") != 0) {
        yyerror("Type mismatch");
    } else {
        char valueStr[64];
        sprintf(valueStr, "%f", $3);
        setInitialized($1, valueStr);
        addAssignment($1, valueStr);
    }
    };

assignment_list_boolean_declared: ID ASSIGN boolean {
    char* type = getType($1);
    if (type == NULL || strcmp(type, "boolean") != 0) {
        yyerror("Type mismatch");
    } else {
        setInitialized($1, $3);
    }
    }
    | ID ASSIGN boolean COMMA assignment_list_boolean_declared {
    char* type = getType($1);
    if (type == NULL || strcmp(type, "boolean") != 0) {
        yyerror("Type mismatch");
    } else {
        setInitialized($1, $3);
    }
    };

assignment_list_variable_declared: ID ASSIGN variable_reference {
    if (strcmp($3, "ERROR") == 0) {
        yyerror("Variable not declared");
    } else {
        char* type = getType($1);
        char* value = getValue($3);
        if (type == NULL || strcmp(type, getType($3)) != 0) {
            yyerror("Type mismatch");
        } else {
            setInitialized($1, value);
            addAssignment($1, value);
        }
    }
    }
    | ID ASSIGN variable_reference COMMA assignment_list_variable_declared {
    if (strcmp($3, "ERROR") == 0) {
        yyerror("Variable not declared");
    } else {
        char* type = getType($1);
        char* value = getValue($3);
        if (type == NULL || strcmp(type, getType($3)) != 0) {
            yyerror("Type mismatch");
        } else {
            setInitialized($1, value);
            addAssignment($1, value);
        }
    }
    };

assignment_list_method_declared: ID ASSIGN method_call {
    char* type = getType($1);
    if (type == NULL || strcmp(type, getType($3)) != 0) {
        yyerror("Type mismatch");
    } else {
        setInitialized($1, NULL);
    }
    }
    | ID ASSIGN method_call COMMA assignment_list_method_declared {
    char* type = getType($1);
    if (type == NULL || strcmp(type, getType($3)) != 0) {
        yyerror("Type mismatch");
    } else {
        setInitialized($1, NULL);
    }
    };

assignment_list_object_declared: ID ASSIGN NEW CLASS_ID {
    char* type = getType($1);
    if (type == NULL || strcmp(type, $4) != 0) {
        yyerror("Type mismatch");
    } else {
        setInitialized($1, NULL);
    }
    }
    | ID ASSIGN NEW CLASS_ID COMMA assignment_list_object_declared {
    char* type = getType($1);
    if (type == NULL || strcmp(type, $4) != 0) {
        yyerror("Type mismatch");
    } else {
        setInitialized($1, NULL);
    }
    };

variable_declaration: identifier_list
    | access_modifier identifier_list
    | access_modifier assignment_list
    | assignment_list
    | assignment_list_declared
    ;

variable_reference: ID {
    if (!symbolExists($1, false, false)) {
        yyerror("Variable not declared");
        $$ = strdup("ERROR");
    } else if (!isInitialized($1)) {
        yyerror("Variable not initialized");
        $$ = strdup("ERROR");
    } else {
        $$ = $1;
    }
    };

method_declaration: access_modifier data_type METHOD_ID {
    log_message("method_declaration", "Entering method_declaration\n");
    if (!symbolExists($3, false, false)) {
        addSymbol($3, $2, true, true, false, NULL);
    } else {
        yyerror("Method already declared");
    }
    increaseScope();
    } none_or_newlines none_or_multiple_parameters none_or_newlines RP LCB none_or_newlines method_body none_or_newlines RCB {
    decreaseScope();
    log_message("method_declaration", "Exiting method_declaration\n");
    }
    | data_type METHOD_ID {
    log_message("method_declaration", "Entering method_declaration\n");
    if (!symbolExists($2, false, false)) {
        addSymbol($2, $1, true, true, false, NULL);
    } else {
        yyerror("Method already declared");
    }
    increaseScope();
    } none_or_newlines none_or_multiple_parameters none_or_newlines RP LCB none_or_newlines method_body none_or_newlines RCB {
    decreaseScope();
    log_message("method_declaration", "Exiting method_declaration\n");
    };

none_or_multiple_parameters: /* nothing */
    | parameter parameters
    ;

parameters: /* nothing */
    | COMMA none_or_newlines parameter parameters
    ;

parameter: data_type ID { addSymbol($2, $1, false, true, false, NULL); }
    ;

method_body: /* nothing */
    | statement none_or_newlines method_body
    ;

statement: /* nothing */
    | method_call
    | if_statement
    | do_while_statement
    | for_statement
    | switch_statement
    | return_statement
    | break_statement
    | print_statement
    | exp SEMICOLON
    | relational_exp SEMICOLON
    | DQ_STRING_DQ SEMICOLON
    | variable_declaration SEMICOLON
    | method_declaration
    | object_creation
    | variable_reference SEMICOLON
    | member_access
    ;

assignment_statement: data_type ID ASSIGN exp
    | data_type ID ASSIGN variable_reference
    ;

method_call: METHOD_ID none_or_newlines none_or_multiple_arguments none_or_newlines RP SEMICOLON {
    if (!symbolExists($1, true, false)) {
        yyerror("Method not declared");
    }
    };

none_or_multiple_arguments: /* nothing */
    | parameter arguments
    | variable_reference arguments
    ;

arguments: /* nothing */
    | COMMA none_or_newlines parameter arguments
    | COMMA none_or_newlines variable_reference arguments
    ;

if_statement: IF LP none_or_newlines if_elif_parenthesis_statement none_or_newlines RP LCB none_or_newlines statement none_or_newlines RCB none_or_newlines none_or_multiple_elif none_or_newlines none_or_one_else
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
    | COMMA ID single_or_multiple_variables {
    if (!symbolExists($2, false, false)) {
        yyerror("Variable not declared");
    } else if (!isInitialized($2)) {
        yyerror("Variable not initialized");
    }
    };

exp: exp_int
    | exp_double
    ;

//Expression for int
exp_int: term_int { $$ = $1; }
    | exp_int ADD term_int { $$ = $1 + $3; }
    | exp_int SUB term_int { $$ = $1 - $3; }
    | error { $$ = 0; yyerrok; }  // Handle error cases
    ;

term_int: factor_int { $$ = $1; }
    | term_int MUL factor_int { $$ = $1 * $3; }
    | term_int DIV factor_int {
    if ($3 == 0) {
        yyerror("Division by zero");
    } else {
        $$ = $1 / $3;
    }
    }
    | term_int MOD factor_int {
    if ($3 == 0) {
        yyerror("Division by zero");
    } else {
        $$ = fmod($1, $3);
    }
    }
    | term_int POW factor_int {
    if ($1 == 0 && $3 == 0) {
        yyerror("Exponentiation by zero");
    } else {
        $$ = pow($1, $3);
    }
    };

factor_int: primary_int { $$ = $1; }
    | LP exp_int RP { $$ = $2; }
    ;

//Expression for double
exp_double: term_double { $$ = $1; }
    | exp_double ADD term_double { $$ = $1 + $3; }
    | exp_double SUB term_double { $$ = $1 - $3; }
    | error { $$ = 0.0; yyerrok; }  // Handle error cases
    ;

term_double: factor_double { $$ = $1; }
    | term_double MUL factor_double { $$ = $1 * $3; }
    | term_double DIV factor_double {
    if ($3 == 0) {
        yyerror("Division by zero");
    } else {
        $$ = $1 / $3;
    }
    }
    | term_double MOD factor_double {
    if ($3 == 0) {
        yyerror("Division by zero");
    } else {
        $$ = fmod($1, $3);
    }
    }
    | term_double POW factor_double {
    if ($1 == 0 && $3 == 0) {
        yyerror("Exponentiation by zero");
    } else {
        $$ = pow($1, $3);
    }
    };

factor_double: primary_double { $$ = $1; }
    | LP exp_double RP { $$ = $2; }
    ;

// Relationanl expressions
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
    | LP relational_exp RP
    ;

unary: primary_int { $$ = $1; }
    | ADD primary_int { $$ = $2; }
    | SUB primary_int { $$ = -$2; }
    ;

// Primary integer
primary_int: CONST { $$ = $1; }
    | variable_reference {
    if (strcmp($1, "ERROR") == 0) {
        $$ = 0;
    } else {
        $$ = atoi(getValue($1));
    }
    }
    ;

// Primary double
primary_double: DOUBLE_CONST { $$ = $1; }
    | variable_reference {
    if (strcmp($1, "ERROR") == 0) {
        $$ = 0.0;
    } else {
        $$ = atof(getValue($1));
    }
    }
    ;

object_creation: CLASS_ID ID ASSIGN NEW CLASS_ID {
    if (!symbolExists($1, false, true)) {
        yyerror("Class not declared");
    } else {
        addSymbol($2, $1, false, true, false, $5);
    }
    } LP RP SEMICOLON
    ;

member_access: ID DOT member_access_body none_or_newlines {
    if (!symbolExists($1, false, true)) {
        yyerror("Class not declared");
    } else if (!symbolExists($3, false, false)) {
        yyerror("Member not declared");
    }
    }
    ;

member_access_body: ID SEMICOLON {
    if (!symbolExists($1, false, false)) {
        yyerror("Variable not declared");
    }
    }
    | method_call {
    if (!symbolExists($1, true, false)) {
        yyerror("Method not declared");
    }
    };

access_modifier: PUBLIC
    | PRIVATE
    ;

boolean: TRUE { $$ = "true"; }
    | FALSE { $$ = "false"; }
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
    char error_msg[200];
    snprintf(error_msg, sizeof(error_msg), "Error at line %d: %s\n", yylineno, s);
    log_message("yyerror", error_msg);

    if (yytext != NULL) {
        addError(yylineno, s, yytext);
    } else {
        addError(yylineno, s, "Unknown token");
    }
}

int main(int argc, char **argv) {
    // Clear the log file at the start
    FILE *log_file = fopen("parser_log.txt", "w");
    if (log_file != NULL) {
        fclose(log_file);
    }

    int width = get_terminal_width();

    log_message("main", "Starting parser");

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_filename> [output_filename]\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (!f) {
        fprintf(stderr, "Cannot open file %s: %s\n", argv[1], strerror(errno));
        return 1;
    }

    yyin = f;
    // Determine the output file
    const char *output_filename = (argc > 2) ? argv[2] : "output.txt";
    FILE *yyout = fopen(output_filename, "w");
    if (!yyout) {
        fprintf(stderr, "Cannot open output file: %s\n", strerror(errno));
        fclose(f);
        return 1;
    }

    log_message("main", "Starting yyparse\n");
    int parse_result = yyparse();
    log_message("main", "yyparse completed");

    printAssignments();

    printf("\nInput Program:\n");
    char ch;
    int line_number = 1;
    rewind(f);
    printf("%4d  | ", line_number);
    fprintf(yyout, "%4d  | ", line_number);
    int char_count = 0;
    while ((ch = fgetc(f)) != EOF) {
        putchar(ch);
        fputc(ch, yyout);
        char_count++;
        if (ch == '\n' && !feof(f)) {
            line_number++;
            char_count = 0;
            printf("%4d  | ", line_number);
            fprintf(yyout, "%4d  | ", line_number);
        } else if (char_count >= width - 8) {
            char_count = 0;
            printf("\n%4d  | ", line_number);
        }
    }

    FILE *error_file = fopen("errors.txt", "w");
    if (!error_file) {
        fprintf(stderr, "Cannot open error file: %s\n", strerror(errno));
        fclose(f);
        fclose(yyout);
        return 1;
    }

    if (errorCount == 0) {
        log_message("main", "Program is syntactically correct");
        printf("\n\nProgram is syntactically correct.");
    } else {
        log_message("main", "Errors found in the program");
        printf("\n\nErrors:\n\n");
        for (int i = 0; i < errorCount; i++) {
            char error_msg[200];
            snprintf(error_msg, sizeof(error_msg), "Error %d at line %d: %s recognised at the token '%s'",
                     i+1, errorTable[i].line, errorTable[i].message, errorTable[i].token);
            log_message("main", error_msg);
            fprintf(stderr, "%s\n", error_msg);
            fprintf(error_file, "%s\n", error_msg); // Write error to the file
        }
    }

    fclose(f);
    fclose(yyout);
    fclose(error_file);
    log_message("main", "Parser completed");

    return parse_result;
}