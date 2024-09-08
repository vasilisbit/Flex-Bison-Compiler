/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "project.y"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "error.h"
#include <errno.h>

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
    printf("Collected Assignments:\n");
    for (int i = 0; i < assignmentCount; i++) {
        printf("%d) Variable %s assigned with value %s\n", i + 1, assignments[i].variable, assignments[i].value);
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


// Function to check if a class is defined
bool classExists(char *name) {
    log_message("classExists", "Entering classExists function");
    if (name == NULL) {
        log_message("classExists", "Null pointer in function\n");
        yyerror("Null pointer in classExists function\n");
        return false;
    }
    for (int i = 0; i < symbolCount; i++) {
        if (symbolTable[i].name != NULL && strcmp(symbolTable[i].name, name) == 0 && symbolTable[i].isClass) {
            log_message("classExists", "Class found\n");
            return true;
        }
    }
    log_message("classExists", "Class not found\n");
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


#line 365 "project.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "project.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CONST = 3,                      /* CONST  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_CLASS_ID = 5,                   /* CLASS_ID  */
  YYSYMBOL_METHOD_ID = 6,                  /* METHOD_ID  */
  YYSYMBOL_DOUBLE_CONST = 7,               /* DOUBLE_CONST  */
  YYSYMBOL_SQ_ANYCHAR_SQ = 8,              /* SQ_ANYCHAR_SQ  */
  YYSYMBOL_DQ_STRING_DQ = 9,               /* DQ_STRING_DQ  */
  YYSYMBOL_VAR = 10,                       /* VAR  */
  YYSYMBOL_NEWLINE = 11,                   /* NEWLINE  */
  YYSYMBOL_CLASS = 12,                     /* CLASS  */
  YYSYMBOL_PUBLIC = 13,                    /* PUBLIC  */
  YYSYMBOL_PRIVATE = 14,                   /* PRIVATE  */
  YYSYMBOL_INTEGER = 15,                   /* INTEGER  */
  YYSYMBOL_CHAR = 16,                      /* CHAR  */
  YYSYMBOL_DOUBLE = 17,                    /* DOUBLE  */
  YYSYMBOL_BOOLEAN = 18,                   /* BOOLEAN  */
  YYSYMBOL_STRING = 19,                    /* STRING  */
  YYSYMBOL_VOID = 20,                      /* VOID  */
  YYSYMBOL_NEW = 21,                       /* NEW  */
  YYSYMBOL_RETURN = 22,                    /* RETURN  */
  YYSYMBOL_IF = 23,                        /* IF  */
  YYSYMBOL_ELIF = 24,                      /* ELIF  */
  YYSYMBOL_ELSE = 25,                      /* ELSE  */
  YYSYMBOL_SWITCH = 26,                    /* SWITCH  */
  YYSYMBOL_CASE = 27,                      /* CASE  */
  YYSYMBOL_DEFAULT = 28,                   /* DEFAULT  */
  YYSYMBOL_WHILE = 29,                     /* WHILE  */
  YYSYMBOL_DO = 30,                        /* DO  */
  YYSYMBOL_FOR = 31,                       /* FOR  */
  YYSYMBOL_BREAK = 32,                     /* BREAK  */
  YYSYMBOL_TRUE = 33,                      /* TRUE  */
  YYSYMBOL_FALSE = 34,                     /* FALSE  */
  YYSYMBOL_PRINT = 35,                     /* PRINT  */
  YYSYMBOL_SEMICOLON = 36,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 37,                     /* COMMA  */
  YYSYMBOL_DOT = 38,                       /* DOT  */
  YYSYMBOL_COLON = 39,                     /* COLON  */
  YYSYMBOL_LP = 40,                        /* LP  */
  YYSYMBOL_RP = 41,                        /* RP  */
  YYSYMBOL_LCB = 42,                       /* LCB  */
  YYSYMBOL_RCB = 43,                       /* RCB  */
  YYSYMBOL_ASSIGN = 44,                    /* ASSIGN  */
  YYSYMBOL_OR = 45,                        /* OR  */
  YYSYMBOL_AND = 46,                       /* AND  */
  YYSYMBOL_EQ = 47,                        /* EQ  */
  YYSYMBOL_NEQ = 48,                       /* NEQ  */
  YYSYMBOL_LT = 49,                        /* LT  */
  YYSYMBOL_LE = 50,                        /* LE  */
  YYSYMBOL_GT = 51,                        /* GT  */
  YYSYMBOL_GE = 52,                        /* GE  */
  YYSYMBOL_ADD = 53,                       /* ADD  */
  YYSYMBOL_SUB = 54,                       /* SUB  */
  YYSYMBOL_MUL = 55,                       /* MUL  */
  YYSYMBOL_DIV = 56,                       /* DIV  */
  YYSYMBOL_MOD = 57,                       /* MOD  */
  YYSYMBOL_POW = 58,                       /* POW  */
  YYSYMBOL_NOT = 59,                       /* NOT  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_program = 61,                   /* program  */
  YYSYMBOL_62_1 = 62,                      /* $@1  */
  YYSYMBOL_63_2 = 63,                      /* $@2  */
  YYSYMBOL_64_3 = 64,                      /* $@3  */
  YYSYMBOL_class_declaration = 65,         /* class_declaration  */
  YYSYMBOL_66_4 = 66,                      /* $@4  */
  YYSYMBOL_67_5 = 67,                      /* $@5  */
  YYSYMBOL_class_body = 68,                /* class_body  */
  YYSYMBOL_identifier_list = 69,           /* identifier_list  */
  YYSYMBOL_identifier_list_int = 70,       /* identifier_list_int  */
  YYSYMBOL_identifier_list_string = 71,    /* identifier_list_string  */
  YYSYMBOL_identifier_list_char = 72,      /* identifier_list_char  */
  YYSYMBOL_identifier_list_double = 73,    /* identifier_list_double  */
  YYSYMBOL_identifier_list_boolean = 74,   /* identifier_list_boolean  */
  YYSYMBOL_identifier_list_variable = 75,  /* identifier_list_variable  */
  YYSYMBOL_assignment_list = 76,           /* assignment_list  */
  YYSYMBOL_assignment_list_int = 77,       /* assignment_list_int  */
  YYSYMBOL_assignment_list_string = 78,    /* assignment_list_string  */
  YYSYMBOL_assignment_list_char = 79,      /* assignment_list_char  */
  YYSYMBOL_assignment_list_double = 80,    /* assignment_list_double  */
  YYSYMBOL_assignment_list_boolean = 81,   /* assignment_list_boolean  */
  YYSYMBOL_assignment_list_method = 82,    /* assignment_list_method  */
  YYSYMBOL_assignment_list_object = 83,    /* assignment_list_object  */
  YYSYMBOL_assignment_list_declared = 84,  /* assignment_list_declared  */
  YYSYMBOL_assignment_list_int_declared = 85, /* assignment_list_int_declared  */
  YYSYMBOL_assignment_list_string_declared = 86, /* assignment_list_string_declared  */
  YYSYMBOL_assignment_list_char_declared = 87, /* assignment_list_char_declared  */
  YYSYMBOL_assignment_list_double_declared = 88, /* assignment_list_double_declared  */
  YYSYMBOL_assignment_list_boolean_declared = 89, /* assignment_list_boolean_declared  */
  YYSYMBOL_assignment_list_variable_declared = 90, /* assignment_list_variable_declared  */
  YYSYMBOL_assignment_list_method_declared = 91, /* assignment_list_method_declared  */
  YYSYMBOL_assignment_list_object_declared = 92, /* assignment_list_object_declared  */
  YYSYMBOL_variable_declaration = 93,      /* variable_declaration  */
  YYSYMBOL_variable_reference = 94,        /* variable_reference  */
  YYSYMBOL_method_declaration = 95,        /* method_declaration  */
  YYSYMBOL_96_6 = 96,                      /* $@6  */
  YYSYMBOL_97_7 = 97,                      /* $@7  */
  YYSYMBOL_none_or_multiple_parameters = 98, /* none_or_multiple_parameters  */
  YYSYMBOL_parameters = 99,                /* parameters  */
  YYSYMBOL_parameter = 100,                /* parameter  */
  YYSYMBOL_method_body = 101,              /* method_body  */
  YYSYMBOL_statement = 102,                /* statement  */
  YYSYMBOL_assignment_statement = 103,     /* assignment_statement  */
  YYSYMBOL_method_call = 104,              /* method_call  */
  YYSYMBOL_none_or_multiple_arguments = 105, /* none_or_multiple_arguments  */
  YYSYMBOL_arguments = 106,                /* arguments  */
  YYSYMBOL_if_statement = 107,             /* if_statement  */
  YYSYMBOL_if_elif_parenthesis_statement = 108, /* if_elif_parenthesis_statement  */
  YYSYMBOL_none_or_multiple_elif = 109,    /* none_or_multiple_elif  */
  YYSYMBOL_none_or_one_else = 110,         /* none_or_one_else  */
  YYSYMBOL_do_while_statement = 111,       /* do_while_statement  */
  YYSYMBOL_for_statement = 112,            /* for_statement  */
  YYSYMBOL_first_and_third_loop_statement = 113, /* first_and_third_loop_statement  */
  YYSYMBOL_second_loop_statement = 114,    /* second_loop_statement  */
  YYSYMBOL_switch_statement = 115,         /* switch_statement  */
  YYSYMBOL_default_case = 116,             /* default_case  */
  YYSYMBOL_one_or_more_cases = 117,        /* one_or_more_cases  */
  YYSYMBOL_multiple_cases = 118,           /* multiple_cases  */
  YYSYMBOL_cases = 119,                    /* cases  */
  YYSYMBOL_case_expression = 120,          /* case_expression  */
  YYSYMBOL_return_statement = 121,         /* return_statement  */
  YYSYMBOL_break_statement = 122,          /* break_statement  */
  YYSYMBOL_print_statement = 123,          /* print_statement  */
  YYSYMBOL_single_or_multiple_variables = 124, /* single_or_multiple_variables  */
  YYSYMBOL_exp = 125,                      /* exp  */
  YYSYMBOL_exp_int = 126,                  /* exp_int  */
  YYSYMBOL_term_int = 127,                 /* term_int  */
  YYSYMBOL_factor_int = 128,               /* factor_int  */
  YYSYMBOL_exp_double = 129,               /* exp_double  */
  YYSYMBOL_term_double = 130,              /* term_double  */
  YYSYMBOL_factor_double = 131,            /* factor_double  */
  YYSYMBOL_relational_exp = 132,           /* relational_exp  */
  YYSYMBOL_relational_factor = 133,        /* relational_factor  */
  YYSYMBOL_logical_term = 134,             /* logical_term  */
  YYSYMBOL_unary = 135,                    /* unary  */
  YYSYMBOL_primary_int = 136,              /* primary_int  */
  YYSYMBOL_primary_double = 137,           /* primary_double  */
  YYSYMBOL_object_creation = 138,          /* object_creation  */
  YYSYMBOL_139_8 = 139,                    /* $@8  */
  YYSYMBOL_member_access = 140,            /* member_access  */
  YYSYMBOL_member_access_body = 141,       /* member_access_body  */
  YYSYMBOL_access_modifier = 142,          /* access_modifier  */
  YYSYMBOL_boolean = 143,                  /* boolean  */
  YYSYMBOL_data_type = 144,                /* data_type  */
  YYSYMBOL_none_or_newlines = 145          /* none_or_newlines  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  120
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   838

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  86
/* YYNRULES -- Number of rules.  */
#define YYNRULES  218
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  496

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   314


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   356,   356,   357,   357,   358,   358,   359,   359,   362,
     362,   367,   367,   374,   375,   376,   379,   380,   381,   382,
     383,   384,   387,   388,   391,   392,   395,   396,   399,   400,
     403,   404,   407,   408,   411,   412,   413,   414,   415,   416,
     417,   420,   426,   432,   433,   436,   437,   440,   446,   453,
     454,   457,   461,   466,   467,   470,   471,   472,   473,   474,
     475,   476,   477,   480,   491,   503,   511,   520,   528,   537,
     548,   560,   568,   577,   591,   606,   614,   623,   631,   640,
     641,   642,   643,   644,   647,   659,   659,   671,   671,   684,
     685,   688,   689,   692,   695,   696,   699,   700,   701,   702,
     703,   704,   705,   706,   707,   708,   709,   710,   711,   712,
     713,   714,   715,   718,   719,   722,   728,   729,   730,   733,
     734,   735,   738,   741,   742,   743,   744,   745,   748,   749,
     752,   753,   756,   757,   760,   763,   764,   765,   768,   769,
     772,   773,   776,   777,   780,   783,   784,   787,   790,   791,
     794,   795,   796,   799,   802,   805,   806,   814,   815,   819,
     820,   821,   822,   825,   826,   827,   834,   841,   849,   850,
     854,   855,   856,   857,   860,   861,   862,   869,   876,   884,
     885,   889,   890,   891,   892,   893,   894,   895,   898,   899,
     900,   903,   904,   905,   908,   909,   910,   914,   915,   925,
     926,   935,   935,   944,   953,   958,   964,   965,   968,   969,
     972,   973,   974,   975,   976,   977,   978,   981,   982
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "CONST", "ID",
  "CLASS_ID", "METHOD_ID", "DOUBLE_CONST", "SQ_ANYCHAR_SQ", "DQ_STRING_DQ",
  "VAR", "NEWLINE", "CLASS", "PUBLIC", "PRIVATE", "INTEGER", "CHAR",
  "DOUBLE", "BOOLEAN", "STRING", "VOID", "NEW", "RETURN", "IF", "ELIF",
  "ELSE", "SWITCH", "CASE", "DEFAULT", "WHILE", "DO", "FOR", "BREAK",
  "TRUE", "FALSE", "PRINT", "SEMICOLON", "COMMA", "DOT", "COLON", "LP",
  "RP", "LCB", "RCB", "ASSIGN", "OR", "AND", "EQ", "NEQ", "LT", "LE", "GT",
  "GE", "ADD", "SUB", "MUL", "DIV", "MOD", "POW", "NOT", "$accept",
  "program", "$@1", "$@2", "$@3", "class_declaration", "$@4", "$@5",
  "class_body", "identifier_list", "identifier_list_int",
  "identifier_list_string", "identifier_list_char",
  "identifier_list_double", "identifier_list_boolean",
  "identifier_list_variable", "assignment_list", "assignment_list_int",
  "assignment_list_string", "assignment_list_char",
  "assignment_list_double", "assignment_list_boolean",
  "assignment_list_method", "assignment_list_object",
  "assignment_list_declared", "assignment_list_int_declared",
  "assignment_list_string_declared", "assignment_list_char_declared",
  "assignment_list_double_declared", "assignment_list_boolean_declared",
  "assignment_list_variable_declared", "assignment_list_method_declared",
  "assignment_list_object_declared", "variable_declaration",
  "variable_reference", "method_declaration", "$@6", "$@7",
  "none_or_multiple_parameters", "parameters", "parameter", "method_body",
  "statement", "assignment_statement", "method_call",
  "none_or_multiple_arguments", "arguments", "if_statement",
  "if_elif_parenthesis_statement", "none_or_multiple_elif",
  "none_or_one_else", "do_while_statement", "for_statement",
  "first_and_third_loop_statement", "second_loop_statement",
  "switch_statement", "default_case", "one_or_more_cases",
  "multiple_cases", "cases", "case_expression", "return_statement",
  "break_statement", "print_statement", "single_or_multiple_variables",
  "exp", "exp_int", "term_int", "factor_int", "exp_double", "term_double",
  "factor_double", "relational_exp", "relational_factor", "logical_term",
  "unary", "primary_int", "primary_double", "object_creation", "$@8",
  "member_access", "member_access_body", "access_modifier", "boolean",
  "data_type", "none_or_newlines", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-419)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-211)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     551,    -9,  -419,    60,    44,    56,  -419,    67,    71,   112,
    -419,  -419,   168,   183,   195,   207,   212,  -419,    25,    68,
     174,   201,   205,   211,   232,    65,   216,   216,    39,   293,
      56,  -419,  -419,  -419,  -419,  -419,  -419,  -419,  -419,  -419,
    -419,  -419,   258,   266,  -419,    56,  -419,  -419,  -419,  -419,
    -419,  -419,  -419,  -419,   267,   169,   149,  -419,   179,   171,
    -419,   210,   193,  -419,  -419,   469,  -419,  -419,  -419,   577,
     299,   551,   121,   491,   264,    56,   272,  -419,     2,  -419,
    -419,  -419,   268,    84,  -419,  -419,   139,  -419,  -419,   145,
    -419,  -419,   153,  -419,  -419,   154,  -419,  -419,  -419,  -419,
     119,   273,   282,   284,  -419,    56,    56,    56,    56,  -419,
     313,  -419,   107,   155,   392,  -419,  -419,  -419,  -419,  -419,
    -419,  -419,  -419,  -419,  -419,  -419,   103,   103,   103,   103,
     103,   103,    48,    48,    48,    48,    48,    48,  -419,    91,
      91,    91,    91,    91,    91,    91,    91,   325,  -419,  -419,
     326,  -419,  -419,   295,  -419,    56,   296,   298,   331,  -419,
    -419,   128,   300,   -20,    59,   302,   319,  -419,  -419,  -419,
    -419,  -419,  -419,   307,   307,    56,   343,   352,    15,  -419,
     353,    98,   355,   357,   356,    46,   362,   208,   369,   365,
    -419,  -419,  -419,    57,    37,   722,   526,   346,  -419,  -419,
    -419,   551,   551,    98,   149,   149,  -419,  -419,  -419,  -419,
      46,  -419,   171,   171,  -419,  -419,  -419,  -419,    91,   193,
     193,   193,   193,   193,   193,  -419,  -419,   347,  -419,    56,
    -419,  -419,   389,   390,   358,   393,   394,   395,   399,   401,
     404,    56,  -419,  -419,   373,  -419,   379,  -419,   415,   384,
      56,   387,  -419,  -419,    93,   388,  -419,   391,   397,  -419,
    -419,   120,   400,  -419,   411,   412,  -419,   414,    13,  -419,
      56,  -419,   420,  -419,    56,    56,    56,   360,   382,  -419,
    -419,   417,   335,   425,   426,   413,  -419,  -419,  -419,    56,
     297,   416,  -419,   418,  -419,   427,   429,  -419,   431,  -419,
     432,  -419,   434,  -419,   435,  -419,  -419,   272,   445,   446,
     478,   665,   481,   483,   485,   487,   489,   449,   468,   482,
     467,    56,   168,   183,   195,   207,   212,   484,   346,   490,
      56,   297,    56,   492,   514,   523,   493,  -419,   529,   528,
      98,    46,   208,   495,   307,   307,  -419,   544,   506,  -419,
      56,    56,    56,   509,  -419,   531,  -419,   532,  -419,   534,
    -419,   535,  -419,   530,   538,   542,   556,    91,   119,  -419,
    -419,   665,    56,   547,    56,  -419,   569,   570,   565,  -419,
    -419,   564,  -419,   528,   665,   573,   665,    56,    56,    56,
     580,   593,   420,    73,  -419,    56,   591,   595,   486,   597,
     620,  -419,  -419,  -419,   722,   615,   615,    56,    56,   601,
     603,    56,   492,  -419,    56,    27,    56,    56,    56,    91,
     526,  -419,    56,   779,  -419,   604,  -419,  -419,   607,   621,
     615,   621,    56,   104,    56,   779,    56,    56,    56,    56,
     611,    56,  -419,    56,    56,   612,   613,   614,    56,   609,
     779,   632,   608,    56,   616,   615,   617,   622,   627,   623,
     630,  -419,  -419,   624,    56,  -419,   722,  -419,  -419,  -419,
    -419,  -419,    56,  -419,    57,   661,  -419,   722,   648,   650,
    -419,    56,   651,    56,   647,    56,   722,  -419,   722,    56,
      56,   655,   656,  -419,   632,  -419
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     7,   197,    84,     0,   217,   199,     0,     0,     0,
     206,   207,   211,   212,   213,   214,   215,   216,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     217,    79,    82,    83,    55,    56,    57,    58,    59,    60,
      61,    62,     0,   198,   109,   217,    97,    98,    99,   100,
     101,   102,   103,   104,     0,   157,   159,   163,   158,   170,
     174,     0,   181,   188,   191,   168,   179,   110,   112,   210,
       0,     0,     0,     0,     0,   217,   116,   107,    32,    21,
      39,    40,     0,    22,    16,    34,    26,    18,    36,    28,
      19,    37,    30,    20,    38,    24,    17,    35,   162,    84,
       0,   198,     0,     0,   168,   217,   217,   217,   217,   153,
       0,   198,     0,     0,     0,   198,   195,   196,   192,   194,
       1,     3,   108,   111,     5,   105,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   106,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    80,    81,
       0,    87,     8,     0,   205,   217,    67,    65,     0,   208,
     209,   198,    75,    63,    69,    71,     0,   218,   211,   212,
     213,   214,   215,   119,   119,   217,     0,     0,     0,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     151,   152,   150,     0,     0,     0,   135,   155,   169,   180,
     193,     0,     0,     0,   160,   161,   164,   165,   166,   167,
       0,   200,   171,   172,   175,   176,   177,   178,     0,   182,
     183,   184,   186,   185,   187,   190,   189,     0,    85,   217,
     204,   203,     0,     0,    77,     0,     0,     0,     0,     0,
       0,   217,   118,   117,     0,    93,    32,    33,     0,    51,
     217,    22,    23,   162,    41,    26,    27,    45,    28,    29,
     173,    47,    30,    31,    49,    24,    25,    43,   198,   126,
     217,   123,   124,   127,   217,   217,   217,   210,     0,   137,
     136,     0,     0,     0,     0,     0,     4,     6,     9,   217,
      89,     0,    68,     0,    66,     0,     0,    74,     0,    76,
       0,    64,     0,    70,     0,    72,   201,     0,     0,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,     0,     0,     0,     0,     0,     0,   155,     0,
     217,    89,   217,    91,     0,     0,     0,    78,     0,     0,
       0,     0,     0,     0,   119,   119,   115,     0,     0,    52,
     217,   217,   217,     0,    42,     0,    46,     0,    48,     0,
      50,     0,    44,     0,     0,     0,     0,   138,     0,   156,
     154,     0,   217,     0,   217,    90,     0,    73,     0,   121,
     120,     0,    54,     0,     0,     0,     0,   217,   217,   217,
       0,     0,   139,   198,   113,   217,     0,     0,   210,     0,
       0,    14,    12,    15,     0,     0,     0,   217,   217,     0,
       0,   217,    91,   202,   217,     0,   217,   217,   217,     0,
     135,    10,   217,     0,    92,     0,   148,   149,     0,   142,
     145,   142,   198,   217,   217,     0,   217,   217,   217,   217,
       0,   217,   144,   217,   217,     0,     0,     0,   217,     0,
       0,   128,     0,   217,     0,   145,     0,     0,     0,     0,
       0,    88,    95,     0,   217,   147,     0,   141,   146,   140,
     133,   132,   217,    86,     0,   130,   143,     0,     0,     0,
     122,   217,     0,   217,     0,   217,     0,   134,     0,   217,
     217,     0,     0,   131,   128,   129
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -419,   -60,  -419,  -419,  -419,  -301,  -419,  -419,  -200,   -47,
     477,   513,   512,   518,   517,   527,   -46,   398,   396,   402,
     403,   405,   406,   359,  -419,   470,   476,   479,   475,   504,
     499,   494,   419,  -195,     0,  -419,  -419,  -419,   424,   309,
     -70,  -376,    61,  -419,   -16,  -419,  -166,  -419,   248,   252,
    -419,  -419,  -419,   327,  -419,  -419,   318,   344,   301,  -418,
    -419,  -419,  -419,  -419,   423,   -13,   -11,   138,   124,   -22,
     141,   163,   -18,   459,   132,   730,   140,  -419,  -419,  -419,
    -419,  -419,    16,  -178,   -56,   -26
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    29,   201,   202,    71,    30,   330,   250,   351,    31,
      84,    96,    87,    90,    93,    79,    32,    85,    97,    88,
      91,    94,    80,    81,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,   115,    44,   289,   229,   332,   375,
     333,   436,    45,   280,    46,   175,   242,    47,   270,   464,
     480,    48,    49,   281,   391,    50,   441,   416,   442,   417,
     428,    51,    52,    53,   285,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,   343,
      68,   155,   277,   165,    70,    76
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,   279,   102,   113,   121,   103,   174,   114,   243,   264,
     350,   152,   443,   150,   112,   273,    69,   237,   101,   124,
     176,     5,   148,   149,  -125,   111,    98,  -162,     2,    99,
     426,     5,     6,   126,   127,   427,   248,   443,    98,   177,
       2,    99,     2,    99,     6,   274,   178,   260,    74,   167,
      99,   164,    99,     6,  -125,     6,   154,   162,    98,   448,
       2,    99,   163,     5,     6,   100,    98,    75,     2,    99,
     350,    43,     6,   161,   462,    78,   173,   100,   113,   193,
     194,   195,   196,   350,  -114,   350,   210,    69,   210,   112,
     159,   160,    26,    27,     2,    99,   238,    25,    72,   253,
     111,     2,    99,    77,    73,    25,     2,    99,   105,  -114,
      26,    27,   132,   133,  -114,    75,    28,    82,    26,    27,
      98,   180,     2,    99,    28,   153,     6,     5,   181,   231,
     312,   218,   211,   211,   211,   211,   211,   211,   203,   -73,
     283,   286,   287,   203,    26,    27,   126,   127,   198,   244,
      28,   139,   140,   141,   142,   143,   144,   314,   104,   100,
     126,   127,   249,   261,   -73,   235,   116,   117,   119,   -73,
     254,   395,    83,   132,   133,   272,   182,   269,   379,   380,
     271,   275,   184,   183,   401,   211,   403,    86,   113,   185,
     186,   188,   112,   268,   111,    43,   199,   187,   189,    89,
     114,    43,    43,   290,   128,   129,   130,   131,   132,   133,
     211,    92,   282,   104,   106,   307,    95,    69,    69,     2,
      99,   150,   126,   127,   311,   279,   134,   135,   136,   137,
     148,   149,   132,   133,   176,   148,   149,   345,   145,   146,
     104,   159,   160,   107,   317,   108,   138,   109,   318,   319,
     320,   176,   206,   207,   208,   209,   276,   139,   140,   141,
     142,   143,   144,   331,   204,   205,   104,   104,   104,   104,
     104,   104,   110,   212,   213,   176,    99,   225,   226,   119,
     119,   119,   119,   119,   119,   119,   119,   168,   169,   170,
     171,   172,    17,   120,   122,   367,   273,   214,   215,   216,
     217,  -210,   123,   125,   371,   151,   373,   344,   166,   190,
     179,    43,   168,   169,   170,   171,   172,    17,   191,   164,
     192,   104,   197,   162,   384,   385,   386,    69,   412,   163,
     227,   230,   228,   232,   104,   233,   234,   236,   377,   239,
     240,   211,   176,   104,   241,     8,   396,   245,   398,   392,
     322,   323,   324,   325,   326,   394,   246,   251,   119,   255,
     258,   404,   405,   406,   283,   257,   262,   249,   393,   409,
       8,    43,   352,   265,   267,    12,    13,    14,    15,    16,
      17,   419,   420,   284,    43,   423,    43,    69,   425,   288,
     429,   430,   431,   291,   293,   295,   435,   296,   298,   300,
      69,   433,    69,   302,    43,   304,   445,   446,   447,   306,
     449,   450,   451,   452,   308,   454,   177,   455,   456,   432,
     309,   310,   460,    43,   180,   182,    73,   466,   313,   327,
     328,   336,   352,   200,   184,    43,   282,   186,   475,   139,
     140,   141,   142,   143,   144,   352,   477,   352,   315,   188,
      43,   316,    43,   321,   329,   484,   272,   486,   269,   488,
     334,   271,   335,   491,   492,   414,    43,   139,   140,   141,
     142,   143,   144,   338,   268,   339,   340,    43,   341,   342,
     104,   346,   348,   347,   437,   353,    43,   355,    43,   357,
     363,   359,    98,   361,     2,    99,   437,     5,     6,   156,
     157,   168,   169,   170,   171,   172,    17,   119,   104,   364,
     366,   437,   158,   465,  -194,  -194,  -194,  -194,  -194,  -194,
    -194,  -194,   156,   365,   159,   160,   370,   476,   368,   374,
     278,   100,   157,    99,     5,   378,     8,   376,   481,    10,
      11,    12,    13,    14,    15,    16,    17,   489,   381,   490,
     383,    -2,     1,   181,     2,     3,     4,     5,     6,   119,
       7,     8,   -96,     9,    10,    11,    12,    13,    14,    15,
      16,    17,   387,    18,    19,   183,   185,    20,   187,   189,
     388,    21,    22,    23,   389,   390,    24,     8,   397,   147,
     158,    25,    12,    13,    14,    15,    16,    17,   219,   220,
     221,   222,   223,   224,    26,    27,   399,   235,   400,    98,
      28,     2,     3,     4,     5,     6,   402,     7,     8,   -96,
     407,    10,    11,    12,    13,    14,    15,    16,    17,   408,
      18,    19,   410,   413,    20,   -96,   -96,   411,    21,    22,
      23,   248,   415,    24,   421,   422,   439,   438,    25,   440,
     453,   -96,   461,   457,   458,   459,   463,   252,   470,   467,
     469,    26,    27,   471,   474,   472,    98,    28,     2,     3,
       4,     5,     6,   473,     7,     8,   -13,     9,    10,    11,
      12,    13,    14,    15,    16,    17,   479,    18,    19,   482,
     487,    20,   483,   485,   256,    21,    22,    23,   493,   494,
      24,   266,   259,   263,   247,    25,   382,   301,   -13,   294,
     354,   292,   362,   303,   337,   356,   349,   358,    26,    27,
     360,   424,   478,    98,    28,     2,     3,     4,     5,     6,
     299,     7,     8,   -96,   297,    10,    11,    12,    13,    14,
      15,    16,    17,   305,    18,    19,   495,   434,    20,   444,
     418,   369,    21,    22,    23,   372,   468,    24,   118,     0,
       0,     0,    25,     0,     0,   -96,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,    27,     0,     0,     0,
      98,    28,     2,     3,     4,     5,     6,     0,     7,     8,
     -94,     0,    10,    11,    12,    13,    14,    15,    16,    17,
       0,    18,    19,     0,     0,    20,     0,     0,     0,    21,
      22,    23,     0,     0,    24,     0,     0,     0,     0,    25,
       0,     0,   -94,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,    27,     0,     0,     0,     0,    28
};

static const yytype_int16 yycheck[] =
{
       0,   196,    18,    25,    30,    18,    76,    25,   174,   187,
     311,    71,   430,    69,    25,   193,     0,    37,    18,    45,
      76,     6,    69,    69,    11,    25,     1,    36,     3,     4,
       3,     6,     7,    53,    54,     8,    21,   455,     1,    37,
       3,     4,     3,     4,     7,     8,    44,     1,     4,    75,
       4,    73,     4,     7,    41,     7,    72,    73,     1,   435,
       3,     4,    73,     6,     7,    40,     1,    11,     3,     4,
     371,    71,     7,    73,   450,     4,    76,    40,   100,   105,
     106,   107,   108,   384,    11,   386,    40,    71,    40,   100,
      33,    34,    53,    54,     3,     4,    37,    40,    38,     1,
     100,     3,     4,    36,    44,    40,     3,     4,    40,    36,
      53,    54,    53,    54,    41,    11,    59,     5,    53,    54,
       1,    37,     3,     4,    59,     4,     7,     6,    44,   155,
      37,    40,   132,   133,   134,   135,   136,   137,    40,    11,
     196,   201,   202,    40,    53,    54,    53,    54,    41,   175,
      59,    47,    48,    49,    50,    51,    52,    37,    18,    40,
      53,    54,   178,   185,    36,    37,    26,    27,    28,    41,
     181,   371,     4,    53,    54,   193,    37,   193,   344,   345,
     193,   194,    37,    44,   384,   185,   386,     4,   210,    44,
      37,    37,   203,   193,   194,   195,    41,    44,    44,     4,
     218,   201,   202,   229,    55,    56,    57,    58,    53,    54,
     210,     4,   196,    73,    40,   241,     4,   201,   202,     3,
       4,   277,    53,    54,   250,   420,    55,    56,    57,    58,
     277,   277,    53,    54,   290,   282,   282,   307,    45,    46,
     100,    33,    34,    42,   270,    40,    36,    36,   274,   275,
     276,   307,   128,   129,   130,   131,   195,    47,    48,    49,
      50,    51,    52,   289,   126,   127,   126,   127,   128,   129,
     130,   131,    40,   132,   133,   331,     4,   145,   146,   139,
     140,   141,   142,   143,   144,   145,   146,    15,    16,    17,
      18,    19,    20,     0,    36,   321,   474,   134,   135,   136,
     137,     4,    36,    36,   330,     6,   332,   307,    44,    36,
      42,   311,    15,    16,    17,    18,    19,    20,    36,   341,
      36,   181,     9,   339,   350,   351,   352,   311,   398,   340,
       5,    36,     6,    37,   194,    37,     5,    37,   338,    37,
      21,   341,   398,   203,    37,    10,   372,     4,   374,   367,
      15,    16,    17,    18,    19,   368,     4,     4,   218,     4,
       4,   387,   388,   389,   420,     8,     4,   383,   368,   395,
      10,   371,   311,     4,     9,    15,    16,    17,    18,    19,
      20,   407,   408,    37,   384,   411,   386,   371,   414,    42,
     416,   417,   418,     4,     4,    37,   422,     4,     4,     4,
     384,   419,   386,     4,   404,     4,   432,   433,   434,     5,
     436,   437,   438,   439,    41,   441,    37,   443,   444,   419,
       5,    37,   448,   423,    37,    37,    44,   453,    37,     4,
       4,     4,   371,    41,    37,   435,   420,    37,   464,    47,
      48,    49,    50,    51,    52,   384,   472,   386,    37,    37,
     450,    37,   452,    36,    41,   481,   474,   483,   474,   485,
      44,   474,    44,   489,   490,   404,   466,    47,    48,    49,
      50,    51,    52,    44,   474,    44,    44,   477,    44,    44,
     340,    36,     4,    37,   423,     4,   486,     4,   488,     4,
      41,     4,     1,     4,     3,     4,   435,     6,     7,     8,
       9,    15,    16,    17,    18,    19,    20,   367,   368,    41,
      43,   450,    21,   452,    45,    46,    47,    48,    49,    50,
      51,    52,     8,    41,    33,    34,    36,   466,    44,    37,
       4,    40,     9,     4,     6,    40,    10,    44,   477,    13,
      14,    15,    16,    17,    18,    19,    20,   486,     4,   488,
      44,     0,     1,    44,     3,     4,     5,     6,     7,   419,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    42,    22,    23,    44,    44,    26,    44,    44,
      42,    30,    31,    32,    42,    29,    35,    10,    41,    12,
      21,    40,    15,    16,    17,    18,    19,    20,   139,   140,
     141,   142,   143,   144,    53,    54,    41,    37,    44,     1,
      59,     3,     4,     5,     6,     7,    43,     9,    10,    11,
      40,    13,    14,    15,    16,    17,    18,    19,    20,    36,
      22,    23,    41,    36,    26,    27,    28,    42,    30,    31,
      32,    21,    27,    35,    43,    42,    39,    43,    40,    28,
      39,    43,    43,    41,    41,    41,    24,   180,    36,    43,
      43,    53,    54,    36,    40,    42,     1,    59,     3,     4,
       5,     6,     7,    43,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    25,    22,    23,    41,
      43,    26,    42,    42,   182,    30,    31,    32,    43,    43,
      35,   188,   184,   186,   177,    40,   347,   237,    43,   233,
     312,   232,   316,   238,   295,   313,   310,   314,    53,    54,
     315,   412,   474,     1,    59,     3,     4,     5,     6,     7,
     236,     9,    10,    11,   235,    13,    14,    15,    16,    17,
      18,    19,    20,   239,    22,    23,   494,   420,    26,   431,
     406,   328,    30,    31,    32,   331,   455,    35,    28,    -1,
      -1,    -1,    40,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    -1,    -1,    -1,
       1,    59,     3,     4,     5,     6,     7,    -1,     9,    10,
      11,    -1,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    -1,    -1,    26,    -1,    -1,    -1,    30,
      31,    32,    -1,    -1,    35,    -1,    -1,    -1,    -1,    40,
      -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    59
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     9,    10,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    22,    23,
      26,    30,    31,    32,    35,    40,    53,    54,    59,    61,
      65,    69,    76,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,   102,   104,   107,   111,   112,
     115,   121,   122,   123,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   140,   142,
     144,    64,    38,    44,     4,    11,   145,    36,     4,    75,
      82,    83,     5,     4,    70,    77,     4,    72,    79,     4,
      73,    80,     4,    74,    81,     4,    71,    78,     1,     4,
      40,    94,   104,   125,   136,    40,    40,    42,    40,    36,
      40,    94,   126,   129,   132,    94,   136,   136,   135,   136,
       0,   145,    36,    36,   145,    36,    53,    54,    55,    56,
      57,    58,    53,    54,    55,    56,    57,    58,    36,    47,
      48,    49,    50,    51,    52,    45,    46,    12,    69,    76,
     144,     6,    61,     4,   104,   141,     8,     9,    21,    33,
      34,    94,   104,   126,   129,   143,    44,   145,    15,    16,
      17,    18,    19,    94,   100,   105,   144,    37,    44,    42,
      37,    44,    37,    44,    37,    44,    37,    44,    37,    44,
      36,    36,    36,   145,   145,   145,   145,     9,    41,    41,
      41,    62,    63,    40,   127,   127,   128,   128,   128,   128,
      40,    94,   130,   130,   131,   131,   131,   131,    40,   133,
     133,   133,   133,   133,   133,   134,   134,     5,     6,    97,
      36,   145,    37,    37,     5,    37,    37,    37,    37,    37,
      21,    37,   106,   106,   145,     4,     4,    75,    21,   104,
      67,     4,    70,     1,   126,     4,    72,     8,     4,    73,
       1,   129,     4,    74,   143,     4,    71,     9,    94,   104,
     108,   125,   132,   143,     8,   125,   102,   142,     4,    93,
     103,   113,   142,   144,    37,   124,    61,    61,    42,    96,
     145,     4,    87,     4,    86,    37,     4,    90,     4,    91,
       4,    85,     4,    88,     4,    89,     5,   145,    41,     5,
      37,   145,    37,    37,    37,    37,    37,   145,   145,   145,
     145,    36,    15,    16,    17,    18,    19,     4,     4,    41,
      66,   145,    98,   100,    44,    44,     4,    92,    44,    44,
      44,    44,    44,   139,    94,   100,    36,    37,     4,    82,
      65,    68,   102,     4,    77,     4,    79,     4,    80,     4,
      81,     4,    78,    41,    41,    41,    43,   145,    44,   124,
      36,   145,    98,   145,    37,    99,    44,    94,    40,   106,
     106,     4,    83,    44,   145,   145,   145,    42,    42,    42,
      29,   114,   132,    94,   125,    68,   145,    41,   145,    41,
      44,    68,    43,    68,   145,   145,   145,    40,    36,   145,
      41,    42,   100,    36,   102,    27,   117,   119,   117,   145,
     145,    43,    42,   145,    99,   145,     3,     8,   120,   145,
     145,   145,    94,   132,   113,   145,   101,   102,    43,    39,
      28,   116,   118,   119,   116,   145,   145,   145,   101,   145,
     145,   145,   145,    39,   145,   145,   145,    41,    41,    41,
     145,    43,   101,    24,   109,   102,   145,    43,   118,    43,
      36,    36,    42,    43,    40,   145,   102,   145,   108,    25,
     110,   102,    41,    42,   145,    42,   145,    43,   145,   102,
     102,   145,   145,    43,    43,   109
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    62,    61,    63,    61,    64,    61,    66,
      65,    67,    65,    68,    68,    68,    69,    69,    69,    69,
      69,    69,    70,    70,    71,    71,    72,    72,    73,    73,
      74,    74,    75,    75,    76,    76,    76,    76,    76,    76,
      76,    77,    77,    78,    78,    79,    79,    80,    80,    81,
      81,    82,    82,    83,    83,    84,    84,    84,    84,    84,
      84,    84,    84,    85,    85,    86,    86,    87,    87,    88,
      88,    89,    89,    90,    90,    91,    91,    92,    92,    93,
      93,    93,    93,    93,    94,    96,    95,    97,    95,    98,
      98,    99,    99,   100,   101,   101,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   103,   103,   104,   105,   105,   105,   106,
     106,   106,   107,   108,   108,   108,   108,   108,   109,   109,
     110,   110,   111,   111,   112,   113,   113,   113,   114,   114,
     115,   115,   116,   116,   117,   118,   118,   119,   120,   120,
     121,   121,   121,   122,   123,   124,   124,   125,   125,   126,
     126,   126,   126,   127,   127,   127,   127,   127,   128,   128,
     129,   129,   129,   129,   130,   130,   130,   130,   130,   131,
     131,   132,   132,   132,   132,   132,   132,   132,   133,   133,
     133,   134,   134,   134,   135,   135,   135,   136,   136,   137,
     137,   139,   138,   140,   141,   141,   142,   142,   143,   143,
     144,   144,   144,   144,   144,   144,   144,   145,   145
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     4,     0,     4,     0,     3,     0,
       9,     0,     8,     0,     3,     3,     2,     2,     2,     2,
       2,     2,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     2,     2,     2,     2,     2,     2,
       2,     3,     5,     3,     5,     3,     5,     3,     5,     3,
       5,     3,     5,     4,     6,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     5,     3,     5,     3,     5,     3,
       5,     3,     5,     3,     5,     3,     5,     4,     6,     1,
       2,     2,     1,     1,     1,     0,    13,     0,    12,     0,
       2,     0,     4,     2,     0,     3,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     1,
       1,     2,     1,     4,     4,     6,     0,     2,     2,     0,
       4,     4,    15,     1,     1,     1,     1,     1,     0,    10,
       0,     6,    13,    13,    17,     0,     1,     1,     0,     1,
      13,    13,     0,     4,     3,     0,     3,     5,     1,     1,
       3,     3,     3,     2,     6,     0,     3,     1,     1,     1,
       3,     3,     1,     1,     3,     3,     3,     3,     1,     3,
       1,     3,     3,     1,     1,     3,     3,     3,     3,     1,
       3,     1,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     1,     2,     3,     1,     2,     2,     1,     1,     1,
       1,     0,     9,     4,     2,     1,     1,     1,     1,     1,
       0,     1,     1,     1,     1,     1,     1,     0,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3: /* $@1: %empty  */
#line 357 "project.y"
                                         { log_message("program", "Entering program\n"); }
#line 1915 "project.tab.c"
    break;

  case 4: /* program: class_declaration none_or_newlines $@1 program  */
#line 357 "project.y"
                                                                                                   { log_message("program", "Exiting program\n"); }
#line 1921 "project.tab.c"
    break;

  case 5: /* $@2: %empty  */
#line 358 "project.y"
                                 { log_message("program", "Entering program\n"); }
#line 1927 "project.tab.c"
    break;

  case 6: /* program: statement none_or_newlines $@2 program  */
#line 358 "project.y"
                                                                                           { log_message("program", "Exiting program\n"); }
#line 1933 "project.tab.c"
    break;

  case 7: /* $@3: %empty  */
#line 359 "project.y"
            { log_message("program", "Entering program\n"); }
#line 1939 "project.tab.c"
    break;

  case 8: /* program: error $@3 program  */
#line 359 "project.y"
                                                                      { log_message("program", "Exiting program\n"); yyerrok; }
#line 1945 "project.tab.c"
    break;

  case 9: /* $@4: %empty  */
#line 362 "project.y"
                                                      {
    log_message("class_declaration", "Entering class_declaration\n");
    addSymbol((yyvsp[-1].sval), "class", false, true, true, NULL);
    increaseScope();
    }
#line 1955 "project.tab.c"
    break;

  case 10: /* class_declaration: access_modifier CLASS CLASS_ID LCB $@4 none_or_newlines class_body none_or_newlines RCB  */
#line 366 "project.y"
                                                       { decreaseScope(); log_message("class_declaration", "Exiting class_declaration\n"); }
#line 1961 "project.tab.c"
    break;

  case 11: /* $@5: %empty  */
#line 367 "project.y"
                         {
    log_message("class_declaration", "Entering class_declaration\n");
    addSymbol((yyvsp[-1].sval), "class", false, true, true, NULL);
    increaseScope();
    }
#line 1971 "project.tab.c"
    break;

  case 12: /* class_declaration: CLASS CLASS_ID LCB $@5 none_or_newlines class_body none_or_newlines RCB  */
#line 371 "project.y"
                                                       { decreaseScope(); log_message("class_declaration", "Exiting class_declaration\n"); }
#line 1977 "project.tab.c"
    break;

  case 22: /* identifier_list_int: ID  */
#line 387 "project.y"
                        { addSymbol((yyvsp[0].sval), "int", false, false, false, NULL); }
#line 1983 "project.tab.c"
    break;

  case 23: /* identifier_list_int: ID COMMA identifier_list_int  */
#line 388 "project.y"
                                   { addSymbol((yyvsp[-2].sval), "int", false, false, false, NULL); }
#line 1989 "project.tab.c"
    break;

  case 24: /* identifier_list_string: ID  */
#line 391 "project.y"
                           { addSymbol((yyvsp[0].sval), "string", false, false, false, NULL); }
#line 1995 "project.tab.c"
    break;

  case 25: /* identifier_list_string: ID COMMA identifier_list_string  */
#line 392 "project.y"
                                      { addSymbol((yyvsp[-2].sval), "string", false, false, false, NULL); }
#line 2001 "project.tab.c"
    break;

  case 26: /* identifier_list_char: ID  */
#line 395 "project.y"
                         { addSymbol((yyvsp[0].sval), "char", false, false, false, NULL); }
#line 2007 "project.tab.c"
    break;

  case 27: /* identifier_list_char: ID COMMA identifier_list_char  */
#line 396 "project.y"
                                    { addSymbol((yyvsp[-2].sval), "char", false, false, false, NULL); }
#line 2013 "project.tab.c"
    break;

  case 28: /* identifier_list_double: ID  */
#line 399 "project.y"
                           { addSymbol((yyvsp[0].sval), "double", false, false, false, NULL); }
#line 2019 "project.tab.c"
    break;

  case 29: /* identifier_list_double: ID COMMA identifier_list_double  */
#line 400 "project.y"
                                      { addSymbol((yyvsp[-2].sval), "double", false, false, false, NULL); }
#line 2025 "project.tab.c"
    break;

  case 30: /* identifier_list_boolean: ID  */
#line 403 "project.y"
                            { addSymbol((yyvsp[0].sval), "boolean", false, false, false, NULL); }
#line 2031 "project.tab.c"
    break;

  case 31: /* identifier_list_boolean: ID COMMA identifier_list_boolean  */
#line 404 "project.y"
                                       { addSymbol((yyvsp[-2].sval), "boolean", false, false, false, NULL); }
#line 2037 "project.tab.c"
    break;

  case 32: /* identifier_list_variable: ID  */
#line 407 "project.y"
                             { addSymbol((yyvsp[0].sval), "var", false, false, false, NULL); }
#line 2043 "project.tab.c"
    break;

  case 33: /* identifier_list_variable: ID COMMA identifier_list_variable  */
#line 408 "project.y"
                                        { addSymbol((yyvsp[-2].sval), "var", false, false, false, NULL); }
#line 2049 "project.tab.c"
    break;

  case 41: /* assignment_list_int: ID ASSIGN exp_int  */
#line 420 "project.y"
                                       {
    char valueStr[32];
    sprintf(valueStr, "%d", (yyvsp[0].ival));
    addSymbol((yyvsp[-2].sval), "int", false, true, false, valueStr);
    addAssignment((yyvsp[-2].sval), valueStr);
    }
#line 2060 "project.tab.c"
    break;

  case 42: /* assignment_list_int: ID ASSIGN exp_int COMMA assignment_list_int  */
#line 426 "project.y"
                                                  {
    char valueStr[32]; sprintf(valueStr, "%d", (yyvsp[-2].ival));
    addSymbol((yyvsp[-4].sval), "int", false, true, false, valueStr);
    addAssignment((yyvsp[-4].sval), valueStr);
    }
#line 2070 "project.tab.c"
    break;

  case 43: /* assignment_list_string: ID ASSIGN DQ_STRING_DQ  */
#line 432 "project.y"
                                               { addSymbol((yyvsp[-2].sval), "string", false, true, false, (yyvsp[0].sval)); }
#line 2076 "project.tab.c"
    break;

  case 44: /* assignment_list_string: ID ASSIGN DQ_STRING_DQ COMMA assignment_list_string  */
#line 433 "project.y"
                                                          { addSymbol((yyvsp[-4].sval), "string", false, true, false, (yyvsp[-2].sval)); }
#line 2082 "project.tab.c"
    break;

  case 45: /* assignment_list_char: ID ASSIGN SQ_ANYCHAR_SQ  */
#line 436 "project.y"
                                              { addSymbol((yyvsp[-2].sval), "char", false, true, false, (yyvsp[0].cval)); }
#line 2088 "project.tab.c"
    break;

  case 46: /* assignment_list_char: ID ASSIGN SQ_ANYCHAR_SQ COMMA assignment_list_char  */
#line 437 "project.y"
                                                         { addSymbol((yyvsp[-4].sval), "char", false, true, false, (yyvsp[-2].cval)); }
#line 2094 "project.tab.c"
    break;

  case 47: /* assignment_list_double: ID ASSIGN exp_double  */
#line 440 "project.y"
                                             {
    char valueStr[64];
    sprintf(valueStr, "%f", (yyvsp[0].dval));
    addSymbol((yyvsp[-2].sval), "double", false, true, false, valueStr);
    addAssignment((yyvsp[-2].sval), valueStr);
    }
#line 2105 "project.tab.c"
    break;

  case 48: /* assignment_list_double: ID ASSIGN exp_double COMMA assignment_list_double  */
#line 446 "project.y"
                                                        {
    char valueStr[64];
    sprintf(valueStr, "%f", (yyvsp[-2].dval));
    addSymbol((yyvsp[-4].sval), "double", false, true, false, valueStr);
    addAssignment((yyvsp[-4].sval), valueStr);
    }
#line 2116 "project.tab.c"
    break;

  case 49: /* assignment_list_boolean: ID ASSIGN boolean  */
#line 453 "project.y"
                                           { addSymbol((yyvsp[-2].sval), "boolean", false, true, false, (yyvsp[0].sval)); }
#line 2122 "project.tab.c"
    break;

  case 50: /* assignment_list_boolean: ID ASSIGN boolean COMMA assignment_list_boolean  */
#line 454 "project.y"
                                                      { addSymbol((yyvsp[-4].sval), "boolean", false, true, false, (yyvsp[-2].sval)); }
#line 2128 "project.tab.c"
    break;

  case 51: /* assignment_list_method: ID ASSIGN method_call  */
#line 457 "project.y"
                                              {
    char* type = getType((yyvsp[0].sval));
    addSymbol((yyvsp[-2].sval), type, false, true, false, NULL);
    }
#line 2137 "project.tab.c"
    break;

  case 52: /* assignment_list_method: ID ASSIGN method_call COMMA assignment_list_method  */
#line 461 "project.y"
                                                         {
    char* type = getType((yyvsp[-2].sval));
    addSymbol((yyvsp[-4].sval), type, false, true, false, NULL);
    }
#line 2146 "project.tab.c"
    break;

  case 53: /* assignment_list_object: ID ASSIGN NEW CLASS_ID  */
#line 466 "project.y"
                                               { addSymbol((yyvsp[-3].sval), "class", false, true, false, NULL); }
#line 2152 "project.tab.c"
    break;

  case 54: /* assignment_list_object: ID ASSIGN NEW CLASS_ID COMMA assignment_list_object  */
#line 467 "project.y"
                                                          { addSymbol((yyvsp[-5].sval), "class", false, true, false, NULL); }
#line 2158 "project.tab.c"
    break;

  case 63: /* assignment_list_int_declared: ID ASSIGN exp_int  */
#line 480 "project.y"
                                                {
    char* type = getType((yyvsp[-2].sval));
    if (type == NULL || strcmp(type, "int") != 0) {
        yyerror("Type mismatch");
    } else {
        char valueStr[32];
        sprintf(valueStr, "%d", (yyvsp[0].ival));
        setInitialized((yyvsp[-2].sval), valueStr);
        addAssignment((yyvsp[-2].sval), valueStr);
    }
    }
#line 2174 "project.tab.c"
    break;

  case 64: /* assignment_list_int_declared: ID ASSIGN exp_int COMMA assignment_list_int_declared  */
#line 491 "project.y"
                                                           {
    char* type = getType((yyvsp[-4].sval));
    if (type == NULL || strcmp(type, "int") != 0) {
        yyerror("Type mismatch");
    } else {
        char valueStr[32];
        sprintf(valueStr, "%d", (yyvsp[-2].ival));
        setInitialized((yyvsp[-4].sval), valueStr);
        addAssignment((yyvsp[-4].sval), valueStr);
    }
    }
#line 2190 "project.tab.c"
    break;

  case 65: /* assignment_list_string_declared: ID ASSIGN DQ_STRING_DQ  */
#line 503 "project.y"
                                                        {
    char* type = getType((yyvsp[-2].sval));
    if (type == NULL || strcmp(type, "string") != 0) {
        yyerror("Type mismatch");
    } else {
        setInitialized((yyvsp[-2].sval), (yyvsp[0].sval));
    }
    }
#line 2203 "project.tab.c"
    break;

  case 66: /* assignment_list_string_declared: ID ASSIGN DQ_STRING_DQ COMMA assignment_list_string_declared  */
#line 511 "project.y"
                                                                   {
    char* type = getType((yyvsp[-4].sval));
    if (type == NULL || strcmp(type, "string") != 0) {
        yyerror("Type mismatch");
    } else {
        setInitialized((yyvsp[-4].sval), (yyvsp[-2].sval));
    }
    }
#line 2216 "project.tab.c"
    break;

  case 67: /* assignment_list_char_declared: ID ASSIGN SQ_ANYCHAR_SQ  */
#line 520 "project.y"
                                                       {
    char* type = getType((yyvsp[-2].sval));
    if (type == NULL || strcmp(type, "char") != 0) {
        yyerror("Type mismatch");
    } else {
        setInitialized((yyvsp[-2].sval), (yyvsp[0].cval));
    }
    }
#line 2229 "project.tab.c"
    break;

  case 68: /* assignment_list_char_declared: ID ASSIGN SQ_ANYCHAR_SQ COMMA assignment_list_char_declared  */
#line 528 "project.y"
                                                                  {
    char* type = getType((yyvsp[-4].sval));
    if (type == NULL || strcmp(type, "char") != 0) {
        yyerror("Type mismatch");
    } else {
        setInitialized((yyvsp[-4].sval), (yyvsp[-2].cval));
    }
    }
#line 2242 "project.tab.c"
    break;

  case 69: /* assignment_list_double_declared: ID ASSIGN exp_double  */
#line 537 "project.y"
                                                      {
    char* type = getType((yyvsp[-2].sval));
    if (type == NULL || strcmp(type, "double") != 0) {
        yyerror("Type mismatch");
    } else {
        char valueStr[64];
        sprintf(valueStr, "%f", (yyvsp[0].dval));
        setInitialized((yyvsp[-2].sval), valueStr);
        addAssignment((yyvsp[-2].sval), valueStr);
    }
    }
#line 2258 "project.tab.c"
    break;

  case 70: /* assignment_list_double_declared: ID ASSIGN exp_double COMMA assignment_list_double_declared  */
#line 548 "project.y"
                                                                 {
    char* type = getType((yyvsp[-4].sval));
    if (type == NULL || strcmp(type, "double") != 0) {
        yyerror("Type mismatch");
    } else {
        char valueStr[64];
        sprintf(valueStr, "%f", (yyvsp[-2].dval));
        setInitialized((yyvsp[-4].sval), valueStr);
        addAssignment((yyvsp[-4].sval), valueStr);
    }
    }
#line 2274 "project.tab.c"
    break;

  case 71: /* assignment_list_boolean_declared: ID ASSIGN boolean  */
#line 560 "project.y"
                                                    {
    char* type = getType((yyvsp[-2].sval));
    if (type == NULL || strcmp(type, "boolean") != 0) {
        yyerror("Type mismatch");
    } else {
        setInitialized((yyvsp[-2].sval), (yyvsp[0].sval));
    }
    }
#line 2287 "project.tab.c"
    break;

  case 72: /* assignment_list_boolean_declared: ID ASSIGN boolean COMMA assignment_list_boolean_declared  */
#line 568 "project.y"
                                                               {
    char* type = getType((yyvsp[-4].sval));
    if (type == NULL || strcmp(type, "boolean") != 0) {
        yyerror("Type mismatch");
    } else {
        setInitialized((yyvsp[-4].sval), (yyvsp[-2].sval));
    }
    }
#line 2300 "project.tab.c"
    break;

  case 73: /* assignment_list_variable_declared: ID ASSIGN variable_reference  */
#line 577 "project.y"
                                                                {
    if (strcmp((yyvsp[0].sval), "ERROR") == 0) {
        yyerror("Variable not declared");
    } else {
        char* type = getType((yyvsp[-2].sval));
        char* value = getValue((yyvsp[0].sval));
        if (type == NULL || strcmp(type, getType((yyvsp[0].sval))) != 0) {
            yyerror("Type mismatch");
        } else {
            setInitialized((yyvsp[-2].sval), value);
            addAssignment((yyvsp[-2].sval), value);
        }
    }
    }
#line 2319 "project.tab.c"
    break;

  case 74: /* assignment_list_variable_declared: ID ASSIGN variable_reference COMMA assignment_list_variable_declared  */
#line 591 "project.y"
                                                                           {
    if (strcmp((yyvsp[-2].sval), "ERROR") == 0) {
        yyerror("Variable not declared");
    } else {
        char* type = getType((yyvsp[-4].sval));
        char* value = getValue((yyvsp[-2].sval));
        if (type == NULL || strcmp(type, getType((yyvsp[-2].sval))) != 0) {
            yyerror("Type mismatch");
        } else {
            setInitialized((yyvsp[-4].sval), value);
            addAssignment((yyvsp[-4].sval), value);
        }
    }
    }
#line 2338 "project.tab.c"
    break;

  case 75: /* assignment_list_method_declared: ID ASSIGN method_call  */
#line 606 "project.y"
                                                       {
    char* type = getType((yyvsp[-2].sval));
    if (type == NULL || strcmp(type, getType((yyvsp[0].sval))) != 0) {
        yyerror("Type mismatch");
    } else {
        setInitialized((yyvsp[-2].sval), NULL);
    }
    }
#line 2351 "project.tab.c"
    break;

  case 76: /* assignment_list_method_declared: ID ASSIGN method_call COMMA assignment_list_method_declared  */
#line 614 "project.y"
                                                                  {
    char* type = getType((yyvsp[-4].sval));
    if (type == NULL || strcmp(type, getType((yyvsp[-2].sval))) != 0) {
        yyerror("Type mismatch");
    } else {
        setInitialized((yyvsp[-4].sval), NULL);
    }
    }
#line 2364 "project.tab.c"
    break;

  case 77: /* assignment_list_object_declared: ID ASSIGN NEW CLASS_ID  */
#line 623 "project.y"
                                                        {
    char* type = getType((yyvsp[-3].sval));
    if (type == NULL || strcmp(type, (yyvsp[0].sval)) != 0) {
        yyerror("Type mismatch");
    } else {
        setInitialized((yyvsp[-3].sval), NULL);
    }
    }
#line 2377 "project.tab.c"
    break;

  case 78: /* assignment_list_object_declared: ID ASSIGN NEW CLASS_ID COMMA assignment_list_object_declared  */
#line 631 "project.y"
                                                                   {
    char* type = getType((yyvsp[-5].sval));
    if (type == NULL || strcmp(type, (yyvsp[-2].sval)) != 0) {
        yyerror("Type mismatch");
    } else {
        setInitialized((yyvsp[-5].sval), NULL);
    }
    }
#line 2390 "project.tab.c"
    break;

  case 84: /* variable_reference: ID  */
#line 647 "project.y"
                       {
    if (!symbolExists((yyvsp[0].sval), false, false)) {
        yyerror("Variable not declared");
        (yyval.sval) = strdup("ERROR");
    } else if (!isInitialized((yyvsp[0].sval))) {
        yyerror("Variable not initialized");
        (yyval.sval) = strdup("ERROR");
    } else {
        (yyval.sval) = (yyvsp[0].sval);
    }
    }
#line 2406 "project.tab.c"
    break;

  case 85: /* $@6: %empty  */
#line 659 "project.y"
                                                        {
    log_message("method_declaration", "Entering method_declaration\n");
    if (!symbolExists((yyvsp[0].sval), false, false)) {
        addSymbol((yyvsp[0].sval), (yyvsp[-1].sval), true, true, false, NULL);
    } else {
        yyerror("Method already declared");
    }
    increaseScope();
    }
#line 2420 "project.tab.c"
    break;

  case 86: /* method_declaration: access_modifier data_type METHOD_ID $@6 none_or_newlines none_or_multiple_parameters none_or_newlines RP LCB none_or_newlines method_body none_or_newlines RCB  */
#line 667 "project.y"
                                                                                                                             {
    decreaseScope();
    log_message("method_declaration", "Exiting method_declaration\n");
    }
#line 2429 "project.tab.c"
    break;

  case 87: /* $@7: %empty  */
#line 671 "project.y"
                          {
    log_message("method_declaration", "Entering method_declaration\n");
    if (!symbolExists((yyvsp[0].sval), false, false)) {
        addSymbol((yyvsp[0].sval), (yyvsp[-1].sval), true, true, false, NULL);
    } else {
        yyerror("Method already declared");
    }
    increaseScope();
    }
#line 2443 "project.tab.c"
    break;

  case 88: /* method_declaration: data_type METHOD_ID $@7 none_or_newlines none_or_multiple_parameters none_or_newlines RP LCB none_or_newlines method_body none_or_newlines RCB  */
#line 679 "project.y"
                                                                                                                             {
    decreaseScope();
    log_message("method_declaration", "Exiting method_declaration\n");
    }
#line 2452 "project.tab.c"
    break;

  case 93: /* parameter: data_type ID  */
#line 692 "project.y"
                        { addSymbol((yyvsp[0].sval), (yyvsp[-1].sval), false, true, false, NULL); }
#line 2458 "project.tab.c"
    break;

  case 115: /* method_call: METHOD_ID none_or_newlines none_or_multiple_arguments none_or_newlines RP SEMICOLON  */
#line 722 "project.y"
                                                                                                 {
    if (!symbolExists((yyvsp[-5].sval), true, false)) {
        yyerror("Method not declared");
    }
    }
#line 2468 "project.tab.c"
    break;

  case 156: /* single_or_multiple_variables: COMMA ID single_or_multiple_variables  */
#line 806 "project.y"
                                            {
    if (!symbolExists((yyvsp[-1].sval), false, false)) {
        yyerror("Variable not declared");
    } else if (!isInitialized((yyvsp[-1].sval))) {
        yyerror("Variable not initialized");
    }
    }
#line 2480 "project.tab.c"
    break;

  case 159: /* exp_int: term_int  */
#line 819 "project.y"
                  { (yyval.ival) = (yyvsp[0].ival); }
#line 2486 "project.tab.c"
    break;

  case 160: /* exp_int: exp_int ADD term_int  */
#line 820 "project.y"
                           { (yyval.ival) = (yyvsp[-2].ival) + (yyvsp[0].ival); }
#line 2492 "project.tab.c"
    break;

  case 161: /* exp_int: exp_int SUB term_int  */
#line 821 "project.y"
                           { (yyval.ival) = (yyvsp[-2].ival) - (yyvsp[0].ival); }
#line 2498 "project.tab.c"
    break;

  case 162: /* exp_int: error  */
#line 822 "project.y"
            { (yyval.ival) = 0; yyerrok; }
#line 2504 "project.tab.c"
    break;

  case 163: /* term_int: factor_int  */
#line 825 "project.y"
                     { (yyval.ival) = (yyvsp[0].ival); }
#line 2510 "project.tab.c"
    break;

  case 164: /* term_int: term_int MUL factor_int  */
#line 826 "project.y"
                              { (yyval.ival) = (yyvsp[-2].ival) * (yyvsp[0].ival); }
#line 2516 "project.tab.c"
    break;

  case 165: /* term_int: term_int DIV factor_int  */
#line 827 "project.y"
                              {
    if ((yyvsp[0].ival) == 0) {
        yyerror("Division by zero");
    } else {
        (yyval.ival) = (yyvsp[-2].ival) / (yyvsp[0].ival);
    }
    }
#line 2528 "project.tab.c"
    break;

  case 166: /* term_int: term_int MOD factor_int  */
#line 834 "project.y"
                              {
    if ((yyvsp[0].ival) == 0) {
        yyerror("Division by zero");
    } else {
        (yyval.ival) = fmod((yyvsp[-2].ival), (yyvsp[0].ival));
    }
    }
#line 2540 "project.tab.c"
    break;

  case 167: /* term_int: term_int POW factor_int  */
#line 841 "project.y"
                              {
    if ((yyvsp[-2].ival) == 0 && (yyvsp[0].ival) == 0) {
        yyerror("Exponentiation by zero");
    } else {
        (yyval.ival) = pow((yyvsp[-2].ival), (yyvsp[0].ival));
    }
    }
#line 2552 "project.tab.c"
    break;

  case 168: /* factor_int: primary_int  */
#line 849 "project.y"
                        { (yyval.ival) = (yyvsp[0].ival); }
#line 2558 "project.tab.c"
    break;

  case 169: /* factor_int: LP exp_int RP  */
#line 850 "project.y"
                    { (yyval.ival) = (yyvsp[-1].ival); }
#line 2564 "project.tab.c"
    break;

  case 170: /* exp_double: term_double  */
#line 854 "project.y"
                        { (yyval.dval) = (yyvsp[0].dval); }
#line 2570 "project.tab.c"
    break;

  case 171: /* exp_double: exp_double ADD term_double  */
#line 855 "project.y"
                                 { (yyval.dval) = (yyvsp[-2].dval) + (yyvsp[0].dval); }
#line 2576 "project.tab.c"
    break;

  case 172: /* exp_double: exp_double SUB term_double  */
#line 856 "project.y"
                                 { (yyval.dval) = (yyvsp[-2].dval) - (yyvsp[0].dval); }
#line 2582 "project.tab.c"
    break;

  case 173: /* exp_double: error  */
#line 857 "project.y"
            { (yyval.dval) = 0.0; yyerrok; }
#line 2588 "project.tab.c"
    break;

  case 174: /* term_double: factor_double  */
#line 860 "project.y"
                           { (yyval.dval) = (yyvsp[0].dval); }
#line 2594 "project.tab.c"
    break;

  case 175: /* term_double: term_double MUL factor_double  */
#line 861 "project.y"
                                    { (yyval.dval) = (yyvsp[-2].dval) * (yyvsp[0].dval); }
#line 2600 "project.tab.c"
    break;

  case 176: /* term_double: term_double DIV factor_double  */
#line 862 "project.y"
                                    {
    if ((yyvsp[0].dval) == 0) {
        yyerror("Division by zero");
    } else {
        (yyval.dval) = (yyvsp[-2].dval) / (yyvsp[0].dval);
    }
    }
#line 2612 "project.tab.c"
    break;

  case 177: /* term_double: term_double MOD factor_double  */
#line 869 "project.y"
                                    {
    if ((yyvsp[0].dval) == 0) {
        yyerror("Division by zero");
    } else {
        (yyval.dval) = fmod((yyvsp[-2].dval), (yyvsp[0].dval));
    }
    }
#line 2624 "project.tab.c"
    break;

  case 178: /* term_double: term_double POW factor_double  */
#line 876 "project.y"
                                    {
    if ((yyvsp[-2].dval) == 0 && (yyvsp[0].dval) == 0) {
        yyerror("Exponentiation by zero");
    } else {
        (yyval.dval) = pow((yyvsp[-2].dval), (yyvsp[0].dval));
    }
    }
#line 2636 "project.tab.c"
    break;

  case 179: /* factor_double: primary_double  */
#line 884 "project.y"
                              { (yyval.dval) = (yyvsp[0].dval); }
#line 2642 "project.tab.c"
    break;

  case 180: /* factor_double: LP exp_double RP  */
#line 885 "project.y"
                       { (yyval.dval) = (yyvsp[-1].dval); }
#line 2648 "project.tab.c"
    break;

  case 194: /* unary: primary_int  */
#line 908 "project.y"
                   { (yyval.ival) = (yyvsp[0].ival); }
#line 2654 "project.tab.c"
    break;

  case 195: /* unary: ADD primary_int  */
#line 909 "project.y"
                      { (yyval.ival) = (yyvsp[0].ival); }
#line 2660 "project.tab.c"
    break;

  case 196: /* unary: SUB primary_int  */
#line 910 "project.y"
                      { (yyval.ival) = -(yyvsp[0].ival); }
#line 2666 "project.tab.c"
    break;

  case 197: /* primary_int: CONST  */
#line 914 "project.y"
                   { (yyval.ival) = (yyvsp[0].ival); }
#line 2672 "project.tab.c"
    break;

  case 198: /* primary_int: variable_reference  */
#line 915 "project.y"
                         {
    if (strcmp((yyvsp[0].sval), "ERROR") == 0) {
        (yyval.ival) = 0;
    } else {
        (yyval.ival) = atoi(getValue((yyvsp[0].sval)));
    }
    }
#line 2684 "project.tab.c"
    break;

  case 199: /* primary_double: DOUBLE_CONST  */
#line 925 "project.y"
                             { (yyval.dval) = (yyvsp[0].dval); }
#line 2690 "project.tab.c"
    break;

  case 200: /* primary_double: variable_reference  */
#line 926 "project.y"
                         {
    if (strcmp((yyvsp[0].sval), "ERROR") == 0) {
        (yyval.dval) = 0.0;
    } else {
        (yyval.dval) = atof(getValue((yyvsp[0].sval)));
    }
    }
#line 2702 "project.tab.c"
    break;

  case 201: /* $@8: %empty  */
#line 935 "project.y"
                                                 {
    if (!symbolExists((yyvsp[-4].sval), false, true)) {
        yyerror("Class not declared");
    } else {
        addSymbol((yyvsp[-3].sval), (yyvsp[-4].sval), false, true, false, (yyvsp[0].sval));
    }
    }
#line 2714 "project.tab.c"
    break;

  case 203: /* member_access: ID DOT member_access_body none_or_newlines  */
#line 944 "project.y"
                                                          {
    if (!symbolExists((yyvsp[-3].sval), false, true)) {
        yyerror("Class not declared");
    } else if (!symbolExists((yyvsp[-1].sval), false, false)) {
        yyerror("Member not declared");
    }
    }
#line 2726 "project.tab.c"
    break;

  case 204: /* member_access_body: ID SEMICOLON  */
#line 953 "project.y"
                                 {
    if (!symbolExists((yyvsp[-1].sval), false, false)) {
        yyerror("Variable not declared");
    }
    }
#line 2736 "project.tab.c"
    break;

  case 205: /* member_access_body: method_call  */
#line 958 "project.y"
                  {
    if (!symbolExists((yyvsp[0].sval), true, false)) {
        yyerror("Method not declared");
    }
    }
#line 2746 "project.tab.c"
    break;

  case 208: /* boolean: TRUE  */
#line 968 "project.y"
              { (yyval.sval) = "true"; }
#line 2752 "project.tab.c"
    break;

  case 209: /* boolean: FALSE  */
#line 969 "project.y"
            { (yyval.sval) = "false"; }
#line 2758 "project.tab.c"
    break;

  case 210: /* data_type: %empty  */
#line 972 "project.y"
                         { (yyval.sval) = ""; }
#line 2764 "project.tab.c"
    break;

  case 211: /* data_type: INTEGER  */
#line 973 "project.y"
              { (yyval.sval) = "int"; }
#line 2770 "project.tab.c"
    break;

  case 212: /* data_type: CHAR  */
#line 974 "project.y"
           { (yyval.sval) = "char"; }
#line 2776 "project.tab.c"
    break;

  case 213: /* data_type: DOUBLE  */
#line 975 "project.y"
             { (yyval.sval) = "double"; }
#line 2782 "project.tab.c"
    break;

  case 214: /* data_type: BOOLEAN  */
#line 976 "project.y"
              { (yyval.sval) = "boolean"; }
#line 2788 "project.tab.c"
    break;

  case 215: /* data_type: STRING  */
#line 977 "project.y"
             { (yyval.sval) = "string"; }
#line 2794 "project.tab.c"
    break;

  case 216: /* data_type: VOID  */
#line 978 "project.y"
           { (yyval.sval) = "void"; }
#line 2800 "project.tab.c"
    break;


#line 2804 "project.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 985 "project.y"


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
    while ((ch = fgetc(f)) != EOF) {
        putchar(ch);
        fputc(ch, yyout);
        if (ch == '\n' && !feof(f)) {
            line_number++;
            printf("%4d  | ", line_number);
            fprintf(yyout, "%4d  | ", line_number);
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
