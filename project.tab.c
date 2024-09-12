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


#line 364 "project.tab.c"

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
  YYSYMBOL_class_declaration = 62,         /* class_declaration  */
  YYSYMBOL_63_1 = 63,                      /* $@1  */
  YYSYMBOL_64_2 = 64,                      /* $@2  */
  YYSYMBOL_class_body = 65,                /* class_body  */
  YYSYMBOL_identifier_list = 66,           /* identifier_list  */
  YYSYMBOL_identifier_list_int = 67,       /* identifier_list_int  */
  YYSYMBOL_identifier_list_string = 68,    /* identifier_list_string  */
  YYSYMBOL_identifier_list_char = 69,      /* identifier_list_char  */
  YYSYMBOL_identifier_list_double = 70,    /* identifier_list_double  */
  YYSYMBOL_identifier_list_boolean = 71,   /* identifier_list_boolean  */
  YYSYMBOL_identifier_list_variable = 72,  /* identifier_list_variable  */
  YYSYMBOL_assignment_list = 73,           /* assignment_list  */
  YYSYMBOL_assignment_list_int = 74,       /* assignment_list_int  */
  YYSYMBOL_assignment_list_string = 75,    /* assignment_list_string  */
  YYSYMBOL_assignment_list_char = 76,      /* assignment_list_char  */
  YYSYMBOL_assignment_list_double = 77,    /* assignment_list_double  */
  YYSYMBOL_assignment_list_boolean = 78,   /* assignment_list_boolean  */
  YYSYMBOL_assignment_list_method = 79,    /* assignment_list_method  */
  YYSYMBOL_assignment_list_object = 80,    /* assignment_list_object  */
  YYSYMBOL_assignment_list_declared = 81,  /* assignment_list_declared  */
  YYSYMBOL_assignment_list_int_declared = 82, /* assignment_list_int_declared  */
  YYSYMBOL_assignment_list_string_declared = 83, /* assignment_list_string_declared  */
  YYSYMBOL_assignment_list_char_declared = 84, /* assignment_list_char_declared  */
  YYSYMBOL_assignment_list_double_declared = 85, /* assignment_list_double_declared  */
  YYSYMBOL_assignment_list_boolean_declared = 86, /* assignment_list_boolean_declared  */
  YYSYMBOL_assignment_list_variable_declared = 87, /* assignment_list_variable_declared  */
  YYSYMBOL_assignment_list_method_declared = 88, /* assignment_list_method_declared  */
  YYSYMBOL_assignment_list_object_declared = 89, /* assignment_list_object_declared  */
  YYSYMBOL_variable_declaration = 90,      /* variable_declaration  */
  YYSYMBOL_variable_reference = 91,        /* variable_reference  */
  YYSYMBOL_method_declaration = 92,        /* method_declaration  */
  YYSYMBOL_93_3 = 93,                      /* $@3  */
  YYSYMBOL_94_4 = 94,                      /* $@4  */
  YYSYMBOL_none_or_multiple_parameters = 95, /* none_or_multiple_parameters  */
  YYSYMBOL_parameters = 96,                /* parameters  */
  YYSYMBOL_parameter = 97,                 /* parameter  */
  YYSYMBOL_method_body = 98,               /* method_body  */
  YYSYMBOL_statement_list = 99,            /* statement_list  */
  YYSYMBOL_statement = 100,                /* statement  */
  YYSYMBOL_assignment_statement = 101,     /* assignment_statement  */
  YYSYMBOL_method_call = 102,              /* method_call  */
  YYSYMBOL_none_or_multiple_arguments = 103, /* none_or_multiple_arguments  */
  YYSYMBOL_arguments = 104,                /* arguments  */
  YYSYMBOL_if_statement = 105,             /* if_statement  */
  YYSYMBOL_if_elif_parenthesis_statement = 106, /* if_elif_parenthesis_statement  */
  YYSYMBOL_none_or_multiple_elif = 107,    /* none_or_multiple_elif  */
  YYSYMBOL_none_or_one_else = 108,         /* none_or_one_else  */
  YYSYMBOL_do_while_statement = 109,       /* do_while_statement  */
  YYSYMBOL_for_statement = 110,            /* for_statement  */
  YYSYMBOL_first_and_third_loop_statement = 111, /* first_and_third_loop_statement  */
  YYSYMBOL_second_loop_statement = 112,    /* second_loop_statement  */
  YYSYMBOL_switch_statement = 113,         /* switch_statement  */
  YYSYMBOL_default_case = 114,             /* default_case  */
  YYSYMBOL_one_or_more_cases = 115,        /* one_or_more_cases  */
  YYSYMBOL_multiple_cases = 116,           /* multiple_cases  */
  YYSYMBOL_cases = 117,                    /* cases  */
  YYSYMBOL_case_expression = 118,          /* case_expression  */
  YYSYMBOL_return_statement = 119,         /* return_statement  */
  YYSYMBOL_break_statement = 120,          /* break_statement  */
  YYSYMBOL_print_statement = 121,          /* print_statement  */
  YYSYMBOL_single_or_multiple_variables = 122, /* single_or_multiple_variables  */
  YYSYMBOL_exp = 123,                      /* exp  */
  YYSYMBOL_exp_int = 124,                  /* exp_int  */
  YYSYMBOL_term_int = 125,                 /* term_int  */
  YYSYMBOL_factor_int = 126,               /* factor_int  */
  YYSYMBOL_exp_double = 127,               /* exp_double  */
  YYSYMBOL_term_double = 128,              /* term_double  */
  YYSYMBOL_factor_double = 129,            /* factor_double  */
  YYSYMBOL_relational_exp = 130,           /* relational_exp  */
  YYSYMBOL_relational_factor = 131,        /* relational_factor  */
  YYSYMBOL_logical_term = 132,             /* logical_term  */
  YYSYMBOL_unary = 133,                    /* unary  */
  YYSYMBOL_primary_int = 134,              /* primary_int  */
  YYSYMBOL_primary_double = 135,           /* primary_double  */
  YYSYMBOL_object_creation = 136,          /* object_creation  */
  YYSYMBOL_137_5 = 137,                    /* $@5  */
  YYSYMBOL_member_access = 138,            /* member_access  */
  YYSYMBOL_member_access_body = 139,       /* member_access_body  */
  YYSYMBOL_access_modifier = 140,          /* access_modifier  */
  YYSYMBOL_boolean = 141,                  /* boolean  */
  YYSYMBOL_data_type = 142,                /* data_type  */
  YYSYMBOL_none_or_newlines = 143          /* none_or_newlines  */
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
#define YYFINAL  121
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1010

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  84
/* YYNRULES -- Number of rules.  */
#define YYNRULES  218
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  491

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
       0,   355,   355,   356,   357,   358,   361,   361,   365,   365,
     371,   372,   373,   376,   377,   378,   379,   380,   381,   384,
     385,   388,   389,   392,   393,   396,   397,   400,   401,   404,
     405,   408,   409,   410,   411,   412,   413,   414,   417,   423,
     429,   430,   433,   434,   437,   443,   450,   451,   454,   458,
     463,   464,   467,   468,   469,   470,   471,   472,   473,   474,
     477,   488,   500,   508,   517,   525,   534,   545,   557,   565,
     574,   588,   603,   611,   620,   628,   637,   638,   639,   640,
     641,   644,   656,   656,   666,   666,   677,   678,   681,   682,
     685,   688,   689,   692,   693,   696,   697,   698,   699,   700,
     701,   702,   703,   704,   705,   706,   707,   708,   709,   710,
     711,   712,   713,   716,   717,   720,   726,   727,   728,   731,
     732,   733,   736,   739,   740,   741,   742,   743,   746,   747,
     750,   751,   754,   755,   758,   761,   762,   763,   766,   767,
     770,   771,   774,   775,   778,   781,   782,   785,   788,   789,
     792,   793,   794,   797,   800,   803,   804,   812,   813,   817,
     818,   819,   820,   823,   824,   825,   832,   839,   847,   848,
     852,   853,   854,   855,   858,   859,   860,   867,   874,   882,
     883,   887,   888,   889,   890,   891,   892,   893,   896,   897,
     898,   901,   902,   903,   906,   907,   908,   912,   913,   923,
     924,   933,   933,   942,   951,   956,   962,   963,   966,   967,
     970,   971,   972,   973,   974,   975,   976,   979,   980
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
  "program", "class_declaration", "$@1", "$@2", "class_body",
  "identifier_list", "identifier_list_int", "identifier_list_string",
  "identifier_list_char", "identifier_list_double",
  "identifier_list_boolean", "identifier_list_variable", "assignment_list",
  "assignment_list_int", "assignment_list_string", "assignment_list_char",
  "assignment_list_double", "assignment_list_boolean",
  "assignment_list_method", "assignment_list_object",
  "assignment_list_declared", "assignment_list_int_declared",
  "assignment_list_string_declared", "assignment_list_char_declared",
  "assignment_list_double_declared", "assignment_list_boolean_declared",
  "assignment_list_variable_declared", "assignment_list_method_declared",
  "assignment_list_object_declared", "variable_declaration",
  "variable_reference", "method_declaration", "$@3", "$@4",
  "none_or_multiple_parameters", "parameters", "parameter", "method_body",
  "statement_list", "statement", "assignment_statement", "method_call",
  "none_or_multiple_arguments", "arguments", "if_statement",
  "if_elif_parenthesis_statement", "none_or_multiple_elif",
  "none_or_one_else", "do_while_statement", "for_statement",
  "first_and_third_loop_statement", "second_loop_statement",
  "switch_statement", "default_case", "one_or_more_cases",
  "multiple_cases", "cases", "case_expression", "return_statement",
  "break_statement", "print_statement", "single_or_multiple_variables",
  "exp", "exp_int", "term_int", "factor_int", "exp_double", "term_double",
  "factor_double", "relational_exp", "relational_factor", "logical_term",
  "unary", "primary_int", "primary_double", "object_creation", "$@5",
  "member_access", "member_access_body", "access_modifier", "boolean",
  "data_type", "none_or_newlines", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-370)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-211)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     718,   641,  -370,    11,    83,   141,  -370,   108,   151,   202,
    -370,  -370,   222,   225,   227,   230,   234,  -370,    23,   215,
     231,   233,   239,   255,   259,    41,    95,    95,    50,   308,
     141,  -370,  -370,  -370,  -370,  -370,  -370,  -370,  -370,  -370,
    -370,  -370,   275,   284,  -370,  -370,    62,  -370,  -370,  -370,
    -370,  -370,  -370,  -370,  -370,   296,   130,   195,  -370,   157,
     240,  -370,   212,   172,  -370,  -370,   481,  -370,  -370,  -370,
     297,   328,  -370,   103,   120,   292,   141,   250,  -370,   -21,
    -370,  -370,  -370,   300,    27,  -370,  -370,   112,  -370,  -370,
     129,  -370,  -370,   152,  -370,  -370,   169,  -370,  -370,  -370,
    -370,   197,   302,   315,   316,  -370,   141,   141,   141,   141,
    -370,   359,  -370,    89,   133,   253,  -370,  -370,  -370,  -370,
    -370,  -370,   718,  -370,  -370,   584,  -370,    28,    28,    28,
      28,    28,    28,    52,    52,    52,    52,    52,    52,  -370,
      43,    43,    43,    43,    43,    43,    43,    43,   366,  -370,
    -370,   367,  -370,   336,  -370,   141,   337,   339,   373,  -370,
    -370,   121,   343,   114,   124,   344,   361,  -370,  -370,  -370,
    -370,  -370,  -370,   347,   347,   141,   381,   382,    87,  -370,
     384,    66,   391,   388,   394,    36,   395,   224,   396,   397,
    -370,  -370,  -370,    32,   168,   894,   226,   368,  -370,  -370,
    -370,  -370,   371,  -370,   311,    66,   195,   195,  -370,  -370,
    -370,  -370,    36,  -370,   240,   240,  -370,  -370,  -370,  -370,
      43,   172,   172,   172,   172,   172,   172,  -370,  -370,   369,
    -370,   141,  -370,  -370,   406,   409,   377,   417,   418,   420,
     421,   423,   424,   141,  -370,  -370,   387,  -370,   393,  -370,
     426,   399,   141,   401,  -370,  -370,   162,   404,  -370,   414,
     415,  -370,  -370,   166,   422,  -370,   425,   427,  -370,   428,
      10,  -370,   141,  -370,   314,  -370,   141,   141,   141,   410,
    -370,  -370,   407,   331,   451,   454,   429,  -370,   141,   270,
     430,  -370,   431,  -370,   462,   432,  -370,   435,  -370,   441,
    -370,   442,  -370,   443,  -370,  -370,   250,   437,   459,   463,
     837,   464,   494,   495,   496,   497,   461,   483,   493,   492,
     141,   222,   225,   227,   230,   234,   498,   368,   500,   141,
     270,   141,   502,   529,   531,   499,  -370,   537,   538,    66,
      36,   224,   505,   347,   347,  -370,   542,   503,  -370,   141,
     141,  -370,   504,  -370,   506,  -370,   507,  -370,   508,  -370,
     509,  -370,   512,   513,   514,   530,    43,   197,  -370,  -370,
     837,   141,   520,   141,  -370,   541,   526,   523,  -370,  -370,
     521,  -370,   538,   837,   524,   141,   141,   141,   528,   533,
     314,   109,  -370,   141,   525,   532,   475,   535,   551,  -370,
    -370,   894,   546,   546,   141,   141,   534,   536,   141,   502,
    -370,   141,   206,   141,   141,   141,    43,   226,  -370,   141,
     951,  -370,   539,  -370,  -370,   540,   547,   546,   547,   141,
      67,   141,   951,   141,  -370,   141,   141,   544,   141,  -370,
     141,   141,   545,   564,   567,   141,   549,   552,   780,   141,
     566,   546,   570,   581,   582,   578,   579,  -370,   583,   141,
    -370,   894,  -370,  -370,  -370,  -370,  -370,   141,  -370,    32,
     555,  -370,   894,   580,   586,  -370,   141,   587,   141,   588,
     141,   894,  -370,   894,   141,   141,   589,   590,  -370,   552,
    -370
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,   197,    81,     0,   217,   199,     0,     0,     0,
     206,   207,   211,   212,   213,   214,   215,   216,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     217,    76,    79,    80,    52,    53,    54,    55,    56,    57,
      58,    59,     0,   198,   108,     4,   217,    96,    97,    98,
      99,   100,   101,   102,   103,     0,   157,   159,   163,   158,
     170,   174,     0,   181,   188,   191,   168,   179,   109,   111,
     210,     0,     5,     0,     0,     0,   217,   116,   106,    29,
      18,    36,    37,     0,    19,    13,    31,    23,    15,    33,
      25,    16,    34,    27,    17,    35,    21,    14,    32,   162,
      81,     0,   198,     0,     0,   168,   217,   217,   217,   217,
     153,     0,   198,     0,     0,     0,   198,   195,   196,   192,
     194,     1,     0,   107,   110,     0,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   105,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    77,
      78,     0,    84,     0,   205,   217,    64,    62,     0,   208,
     209,   198,    72,    60,    66,    68,     0,   218,   211,   212,
     213,   214,   215,   119,   119,   217,     0,     0,     0,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     151,   152,   150,     0,     0,     0,   135,   155,   169,   180,
     193,     3,   112,    94,   210,     0,   160,   161,   164,   165,
     166,   167,     0,   200,   171,   172,   175,   176,   177,   178,
       0,   182,   183,   184,   186,   185,   187,   190,   189,     0,
      82,   217,   204,   203,     0,     0,    74,     0,     0,     0,
       0,     0,     0,   217,   118,   117,     0,    90,    29,    30,
       0,    48,   217,    19,    20,   162,    38,    23,    24,    42,
      25,    26,   173,    44,    27,    28,    46,    21,    22,    40,
     198,   126,   217,   123,   124,   127,   217,   217,   217,     0,
     136,   137,     0,     0,     0,     0,     0,     6,   217,    86,
       0,    65,     0,    63,     0,     0,    71,     0,    73,     0,
      61,     0,    67,     0,    69,   201,     0,     0,    50,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     217,     0,     0,     0,     0,     0,     0,   155,     0,   217,
      86,   217,    88,     0,     0,     0,    75,     0,     0,     0,
       0,     0,     0,   119,   119,   115,     0,     0,    49,   217,
     217,    12,     0,    39,     0,    43,     0,    45,     0,    47,
       0,    41,     0,     0,     0,     0,   138,     0,   156,   154,
       0,   217,     0,   217,    87,     0,    70,     0,   121,   120,
       0,    51,     0,     0,     0,   217,   217,   217,     0,     0,
     139,   198,   113,   217,     0,     0,   210,     0,     0,    11,
       9,     0,     0,     0,   217,   217,     0,     0,   217,    88,
     202,   217,     0,   217,   217,   217,     0,   135,     7,   217,
       0,    89,     0,   148,   149,     0,   142,   145,   142,   198,
     217,   217,     0,   217,    92,   217,   217,     0,   217,   144,
     217,   217,     0,     0,     0,   217,     0,   128,     0,   217,
       0,   145,     0,     0,     0,     0,     0,    85,     0,   217,
     147,     0,   141,   146,   140,   133,   132,   217,    83,     0,
     130,   143,     0,     0,     0,   122,   217,     0,   217,     0,
     217,     0,   134,     0,   217,   217,     0,     0,   131,   128,
     129
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -370,    18,  -295,  -370,  -370,  -342,   -58,   445,   438,   448,
     450,   449,   472,   -56,   325,   324,   350,   327,   351,   357,
     322,  -370,   436,   434,   440,   439,   444,   433,   446,   386,
    -189,     0,  -370,  -370,  -370,   348,   273,   -73,   251,    77,
    -370,  -370,   -13,  -370,  -152,  -370,   217,   198,  -370,  -370,
    -370,   271,  -370,  -370,   261,   287,   241,  -369,  -370,  -370,
    -370,  -370,   364,   -12,   -17,   150,    92,   -22,   211,   221,
     -23,   370,   137,   665,   376,  -370,  -370,  -370,  -370,  -370,
       9,  -176,   -57,     4
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    29,    30,   329,   252,   350,    31,    85,    97,    88,
      91,    94,    80,    32,    86,    98,    89,    92,    95,    81,
      82,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   116,    44,   288,   231,   331,   374,   332,   433,    45,
      46,   281,    47,   175,   244,    48,   272,   459,   475,    49,
      50,   282,   389,    51,   438,   413,   439,   414,   425,    52,
      53,    54,   286,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   342,    69,   155,
     204,   165,    71,    77
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,    43,   115,   114,   174,   103,   104,   280,   113,    70,
      70,   266,   149,   151,   150,   349,   177,   275,   102,    72,
     176,  -125,   245,   178,    99,   112,     2,   100,   393,     5,
       6,     2,   100,    99,   122,     2,   100,   262,     5,     6,
     100,   399,    99,     6,     2,   100,     2,   100,     6,    73,
     125,  -125,   164,     2,   100,    74,   100,   163,   440,     6,
     154,   162,   -93,   101,   180,   159,   160,   255,   205,     2,
     100,   181,    25,    76,   161,   349,   212,   173,    76,   114,
     167,    25,   440,   220,   113,    26,    27,    75,   349,   -93,
     -93,    28,   212,     5,    26,    27,    26,    27,     2,   100,
      28,   112,    28,    26,    27,   -93,   205,   153,   250,     5,
     193,   194,   195,   196,   140,   141,   142,   143,   144,   145,
    -114,    99,    43,     2,   100,    43,     5,     6,   156,   157,
     198,    70,   -70,   213,   213,   213,   213,   213,   213,   284,
     201,   158,   127,   128,    78,  -114,   149,   151,   150,   182,
    -114,   239,    76,   159,   160,    79,   183,   -70,   237,   233,
     101,   240,   -70,   263,   256,   251,   184,   127,   128,    99,
     274,     2,   100,   185,   199,     6,   276,   133,   134,   246,
     271,   273,   277,   127,   128,   213,   133,   134,   113,   186,
     114,   378,   379,   270,   112,    43,   187,   115,    99,   311,
       2,   100,   203,   313,     6,   283,   188,    83,   101,   423,
     133,   134,   213,   189,   424,   127,   128,   146,   147,   133,
     134,   208,   209,   210,   211,   149,    84,   150,   280,    87,
     279,    90,   176,   344,    93,   289,     8,   101,    96,    10,
      11,    12,    13,    14,    15,    16,    17,   306,   139,   176,
     129,   130,   131,   132,   100,   106,   310,   159,   160,   140,
     141,   142,   143,   144,   145,   168,   169,   170,   171,   172,
      17,   107,   278,   176,  -210,   108,   316,   206,   207,   109,
     317,   318,   319,   227,   228,   168,   169,   170,   171,   172,
      17,   110,   330,   275,   200,   135,   136,   137,   138,   111,
     140,   141,   142,   143,   144,   145,   343,     8,   121,   148,
      43,   123,    12,    13,    14,    15,    16,    17,   164,    70,
     124,     8,   163,   409,   366,   162,    12,    13,    14,    15,
      16,    17,   126,   370,   152,   372,   166,   376,   190,   176,
     213,     8,   179,   390,   214,   215,   321,   322,   323,   324,
     325,   191,   192,   383,   384,   392,   216,   217,   218,   219,
     284,   140,   141,   142,   143,   144,   145,   391,   197,   251,
      43,   229,   232,   230,   234,   394,   235,   396,   236,    70,
     238,   241,   242,    43,   243,   247,   248,   351,   253,   401,
     402,   403,    70,   430,   105,   257,   259,   406,   260,   264,
     267,    43,   117,   118,   120,   285,   269,  -162,   416,   417,
     290,   287,   420,   292,   294,   422,   429,   426,   427,   428,
      43,   295,   297,   432,   299,   301,   283,   303,   307,   305,
     177,   308,    43,   442,   443,   444,   309,   446,   180,   447,
     448,   182,   450,   320,   451,   452,   274,   351,    43,   456,
     105,   312,   184,   461,    74,   326,   271,   273,   327,   186,
     351,    43,   314,   470,   188,   315,   335,   347,   352,   270,
     328,   472,    43,   345,   333,   334,   337,   105,   411,   338,
     479,    43,   481,    43,   483,   339,   340,   341,   486,   487,
     168,   169,   170,   171,   172,    17,   346,   434,   354,   356,
     358,   360,   362,   105,   105,   105,   105,   105,   105,   434,
     221,   222,   223,   224,   225,   226,   120,   120,   120,   120,
     120,   120,   120,   120,   363,   460,  -194,  -194,  -194,  -194,
    -194,  -194,  -194,  -194,   364,   365,   369,   156,   471,   373,
     157,   100,   367,   375,     5,   377,   380,   382,   181,   476,
     183,   185,   187,   189,   385,   386,   387,   105,   484,   388,
     485,   395,   158,   237,   397,   398,   407,   400,   404,   405,
     105,   410,   250,   412,   408,   437,   458,   418,   419,   436,
     474,   105,   435,   449,   -95,   202,   453,     2,     3,     4,
       5,     6,   457,     7,     8,   -95,   120,    10,    11,    12,
      13,    14,    15,    16,    17,   454,    18,    19,   455,   462,
      20,   -95,   -95,   464,    21,    22,    23,   465,   466,    24,
     467,   477,   468,   469,    25,   254,   268,   -95,   478,   480,
     258,   482,   488,   489,   261,   265,   353,    26,    27,   361,
     357,    -2,     1,    28,     2,     3,     4,     5,     6,   249,
       7,     8,   -95,     9,    10,    11,    12,    13,    14,    15,
      16,    17,   355,    18,    19,   359,   348,    20,   381,   293,
     296,    21,    22,    23,   291,   300,    24,  -162,   371,   302,
     336,    25,   421,   445,   298,   304,   473,   490,   431,   441,
     415,   368,   463,   119,    26,    27,     0,     0,     0,     0,
      28,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   105,     0,     0,    -2,     1,
       0,     2,     3,     4,     5,     6,     0,     7,     8,   -95,
       9,    10,    11,    12,    13,    14,    15,    16,    17,     0,
      18,    19,   120,   105,    20,     0,     0,     0,    21,    22,
      23,     0,     0,    24,     0,     0,     0,     0,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,    27,     0,     0,     0,     0,    28,     0,     0,
       0,   202,     0,     2,     3,     4,     5,     6,     0,     7,
       8,   -95,   120,    10,    11,    12,    13,    14,    15,    16,
      17,     0,    18,    19,     0,     0,    20,   -95,   -95,     0,
      21,    22,    23,     0,     0,    24,     0,     0,     0,     0,
      25,     0,     0,   -95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,    27,     0,     0,     0,   202,    28,
       2,     3,     4,     5,     6,     0,     7,     8,   -10,     9,
      10,    11,    12,    13,    14,    15,    16,    17,     0,    18,
      19,     0,     0,    20,     0,     0,     0,    21,    22,    23,
       0,     0,    24,     0,     0,     0,     0,    25,     0,     0,
     -10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,    27,     0,     0,     0,   202,    28,     2,     3,     4,
       5,     6,     0,     7,     8,   -95,     0,    10,    11,    12,
      13,    14,    15,    16,    17,     0,    18,    19,     0,     0,
      20,     0,     0,     0,    21,    22,    23,     0,     0,    24,
       0,     0,     0,     0,    25,     0,     0,   -95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    26,    27,     0,
       0,     0,   202,    28,     2,     3,     4,     5,     6,     0,
       7,     8,   -91,     0,    10,    11,    12,    13,    14,    15,
      16,    17,     0,    18,    19,     0,     0,    20,     0,     0,
       0,    21,    22,    23,     0,     0,    24,     0,     0,     0,
       0,    25,     0,     0,   -91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,    27,     0,     0,     0,     0,
      28
};

static const yytype_int16 yycheck[] =
{
       0,     1,    25,    25,    77,    18,    18,   196,    25,     0,
       1,   187,    70,    70,    70,   310,    37,   193,    18,     1,
      77,    11,   174,    44,     1,    25,     3,     4,   370,     6,
       7,     3,     4,     1,    30,     3,     4,     1,     6,     7,
       4,   383,     1,     7,     3,     4,     3,     4,     7,    38,
      46,    41,    74,     3,     4,    44,     4,    74,   427,     7,
      73,    74,     0,    40,    37,    33,    34,     1,    40,     3,
       4,    44,    40,    11,    74,   370,    40,    77,    11,   101,
      76,    40,   451,    40,   101,    53,    54,     4,   383,    27,
      28,    59,    40,     6,    53,    54,    53,    54,     3,     4,
      59,   101,    59,    53,    54,    43,    40,     4,    21,     6,
     106,   107,   108,   109,    47,    48,    49,    50,    51,    52,
      11,     1,   122,     3,     4,   125,     6,     7,     8,     9,
      41,   122,    11,   133,   134,   135,   136,   137,   138,   196,
     122,    21,    53,    54,    36,    36,   204,   204,   204,    37,
      41,    37,    11,    33,    34,     4,    44,    36,    37,   155,
      40,    37,    41,   185,   181,   178,    37,    53,    54,     1,
     193,     3,     4,    44,    41,     7,     8,    53,    54,   175,
     193,   193,   194,    53,    54,   185,    53,    54,   205,    37,
     212,   343,   344,   193,   194,   195,    44,   220,     1,    37,
       3,     4,   125,    37,     7,   196,    37,     5,    40,     3,
      53,    54,   212,    44,     8,    53,    54,    45,    46,    53,
      54,   129,   130,   131,   132,   283,     4,   283,   417,     4,
       4,     4,   289,   306,     4,   231,    10,    40,     4,    13,
      14,    15,    16,    17,    18,    19,    20,   243,    36,   306,
      55,    56,    57,    58,     4,    40,   252,    33,    34,    47,
      48,    49,    50,    51,    52,    15,    16,    17,    18,    19,
      20,    40,   195,   330,     4,    42,   272,   127,   128,    40,
     276,   277,   278,   146,   147,    15,    16,    17,    18,    19,
      20,    36,   288,   469,    41,    55,    56,    57,    58,    40,
      47,    48,    49,    50,    51,    52,   306,    10,     0,    12,
     310,    36,    15,    16,    17,    18,    19,    20,   340,   310,
      36,    10,   339,   396,   320,   338,    15,    16,    17,    18,
      19,    20,    36,   329,     6,   331,    44,   337,    36,   396,
     340,    10,    42,   366,   133,   134,    15,    16,    17,    18,
      19,    36,    36,   349,   350,   367,   135,   136,   137,   138,
     417,    47,    48,    49,    50,    51,    52,   367,     9,   382,
     370,     5,    36,     6,    37,   371,    37,   373,     5,   370,
      37,    37,    21,   383,    37,     4,     4,   310,     4,   385,
     386,   387,   383,   416,    18,     4,     8,   393,     4,     4,
       4,   401,    26,    27,    28,    37,     9,    36,   404,   405,
       4,    42,   408,     4,    37,   411,   416,   413,   414,   415,
     420,     4,     4,   419,     4,     4,   417,     4,    41,     5,
      37,     5,   432,   429,   430,   431,    37,   433,    37,   435,
     436,    37,   438,    36,   440,   441,   469,   370,   448,   445,
      74,    37,    37,   449,    44,     4,   469,   469,     4,    37,
     383,   461,    37,   459,    37,    37,     4,     4,     4,   469,
      41,   467,   472,    36,    44,    44,    44,   101,   401,    44,
     476,   481,   478,   483,   480,    44,    44,    44,   484,   485,
      15,    16,    17,    18,    19,    20,    37,   420,     4,     4,
       4,     4,    41,   127,   128,   129,   130,   131,   132,   432,
     140,   141,   142,   143,   144,   145,   140,   141,   142,   143,
     144,   145,   146,   147,    41,   448,    45,    46,    47,    48,
      49,    50,    51,    52,    41,    43,    36,     8,   461,    37,
       9,     4,    44,    44,     6,    40,     4,    44,    44,   472,
      44,    44,    44,    44,    42,    42,    42,   181,   481,    29,
     483,    41,    21,    37,    41,    44,    41,    43,    40,    36,
     194,    36,    21,    27,    42,    28,    24,    43,    42,    39,
      25,   205,    43,    39,     0,     1,    41,     3,     4,     5,
       6,     7,    43,     9,    10,    11,   220,    13,    14,    15,
      16,    17,    18,    19,    20,    41,    22,    23,    41,    43,
      26,    27,    28,    43,    30,    31,    32,    36,    36,    35,
      42,    41,    43,    40,    40,   180,   188,    43,    42,    42,
     182,    43,    43,    43,   184,   186,   311,    53,    54,   315,
     313,     0,     1,    59,     3,     4,     5,     6,     7,   177,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,   312,    22,    23,   314,   309,    26,   346,   235,
     237,    30,    31,    32,   234,   239,    35,    36,   330,   240,
     294,    40,   409,   432,   238,   241,   469,   489,   417,   428,
     403,   327,   451,    28,    53,    54,    -1,    -1,    -1,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   339,    -1,    -1,     0,     1,
      -1,     3,     4,     5,     6,     7,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      22,    23,   366,   367,    26,    -1,    -1,    -1,    30,    31,
      32,    -1,    -1,    35,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    54,    -1,    -1,    -1,    -1,    59,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,     7,    -1,     9,
      10,    11,   416,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    22,    23,    -1,    -1,    26,    27,    28,    -1,
      30,    31,    32,    -1,    -1,    35,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    -1,    -1,    -1,     1,    59,
       3,     4,     5,     6,     7,    -1,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    -1,    -1,    26,    -1,    -1,    -1,    30,    31,    32,
      -1,    -1,    35,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    54,    -1,    -1,    -1,     1,    59,     3,     4,     5,
       6,     7,    -1,     9,    10,    11,    -1,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    22,    23,    -1,    -1,
      26,    -1,    -1,    -1,    30,    31,    32,    -1,    -1,    35,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    -1,
      -1,    -1,     1,    59,     3,     4,     5,     6,     7,    -1,
       9,    10,    11,    -1,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    -1,    -1,    26,    -1,    -1,
      -1,    30,    31,    32,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,
      59
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     9,    10,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    22,    23,
      26,    30,    31,    32,    35,    40,    53,    54,    59,    61,
      62,    66,    73,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    99,   100,   102,   105,   109,
     110,   113,   119,   120,   121,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   138,
     140,   142,    61,    38,    44,     4,    11,   143,    36,     4,
      72,    79,    80,     5,     4,    67,    74,     4,    69,    76,
       4,    70,    77,     4,    71,    78,     4,    68,    75,     1,
       4,    40,    91,   102,   123,   134,    40,    40,    42,    40,
      36,    40,    91,   124,   127,   130,    91,   134,   134,   133,
     134,     0,   143,    36,    36,   143,    36,    53,    54,    55,
      56,    57,    58,    53,    54,    55,    56,    57,    58,    36,
      47,    48,    49,    50,    51,    52,    45,    46,    12,    66,
      73,   142,     6,     4,   102,   139,     8,     9,    21,    33,
      34,    91,   102,   124,   127,   141,    44,   143,    15,    16,
      17,    18,    19,    91,    97,   103,   142,    37,    44,    42,
      37,    44,    37,    44,    37,    44,    37,    44,    37,    44,
      36,    36,    36,   143,   143,   143,   143,     9,    41,    41,
      41,    61,     1,    99,   140,    40,   125,   125,   126,   126,
     126,   126,    40,    91,   128,   128,   129,   129,   129,   129,
      40,   131,   131,   131,   131,   131,   131,   132,   132,     5,
       6,    94,    36,   143,    37,    37,     5,    37,    37,    37,
      37,    37,    21,    37,   104,   104,   143,     4,     4,    72,
      21,   102,    64,     4,    67,     1,   124,     4,    69,     8,
       4,    70,     1,   127,     4,    71,   141,     4,    68,     9,
      91,   102,   106,   123,   130,   141,     8,   123,    99,     4,
      90,   101,   111,   140,   142,    37,   122,    42,    93,   143,
       4,    84,     4,    83,    37,     4,    87,     4,    88,     4,
      82,     4,    85,     4,    86,     5,   143,    41,     5,    37,
     143,    37,    37,    37,    37,    37,   143,   143,   143,   143,
      36,    15,    16,    17,    18,    19,     4,     4,    41,    63,
     143,    95,    97,    44,    44,     4,    89,    44,    44,    44,
      44,    44,   137,    91,    97,    36,    37,     4,    79,    62,
      65,    99,     4,    74,     4,    76,     4,    77,     4,    78,
       4,    75,    41,    41,    41,    43,   143,    44,   122,    36,
     143,    95,   143,    37,    96,    44,    91,    40,   104,   104,
       4,    80,    44,   143,   143,    42,    42,    42,    29,   112,
     130,    91,   123,    65,   143,    41,   143,    41,    44,    65,
      43,   143,   143,   143,    40,    36,   143,    41,    42,    97,
      36,    99,    27,   115,   117,   115,   143,   143,    43,    42,
     143,    96,   143,     3,     8,   118,   143,   143,   143,    91,
     130,   111,   143,    98,    99,    43,    39,    28,   114,   116,
     117,   114,   143,   143,   143,    98,   143,   143,   143,    39,
     143,   143,   143,    41,    41,    41,   143,    43,    24,   107,
      99,   143,    43,   116,    43,    36,    36,    42,    43,    40,
     143,    99,   143,   106,    25,   108,    99,    41,    42,   143,
      42,   143,    43,   143,    99,    99,   143,   143,    43,    43,
     107
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    61,    61,    61,    63,    62,    64,    62,
      65,    65,    65,    66,    66,    66,    66,    66,    66,    67,
      67,    68,    68,    69,    69,    70,    70,    71,    71,    72,
      72,    73,    73,    73,    73,    73,    73,    73,    74,    74,
      75,    75,    76,    76,    77,    77,    78,    78,    79,    79,
      80,    80,    81,    81,    81,    81,    81,    81,    81,    81,
      82,    82,    83,    83,    84,    84,    85,    85,    86,    86,
      87,    87,    88,    88,    89,    89,    90,    90,    90,    90,
      90,    91,    93,    92,    94,    92,    95,    95,    96,    96,
      97,    98,    98,    99,    99,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   101,   101,   102,   103,   103,   103,   104,
     104,   104,   105,   106,   106,   106,   106,   106,   107,   107,
     108,   108,   109,   109,   110,   111,   111,   111,   112,   112,
     113,   113,   114,   114,   115,   116,   116,   117,   118,   118,
     119,   119,   119,   120,   121,   122,   122,   123,   123,   124,
     124,   124,   124,   125,   125,   125,   125,   125,   126,   126,
     127,   127,   127,   127,   128,   128,   128,   128,   128,   129,
     129,   130,   130,   130,   130,   130,   130,   130,   131,   131,
     131,   132,   132,   132,   133,   133,   133,   134,   134,   135,
     135,   137,   136,   138,   139,   139,   140,   140,   141,   141,
     142,   142,   142,   142,   142,   142,   142,   143,   143
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     1,     2,     0,     9,     0,     8,
       0,     3,     1,     2,     2,     2,     2,     2,     2,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     2,     2,     2,     2,     2,     2,     2,     3,     5,
       3,     5,     3,     5,     3,     5,     3,     5,     3,     5,
       4,     6,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     5,     3,     5,     3,     5,     3,     5,     3,     5,
       3,     5,     3,     5,     4,     6,     1,     2,     2,     1,
       1,     1,     0,    13,     0,    12,     0,     2,     0,     4,
       2,     0,     1,     1,     3,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     1,     1,
       2,     1,     1,     4,     4,     6,     0,     2,     2,     0,
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
  case 5: /* program: error program  */
#line 358 "project.y"
                    { yyerrok; }
#line 1947 "project.tab.c"
    break;

  case 6: /* $@1: %empty  */
#line 361 "project.y"
                                                      {
    addSymbol((yyvsp[-1].sval), "class", false, true, true, NULL);
    increaseScope();
    }
#line 1956 "project.tab.c"
    break;

  case 7: /* class_declaration: access_modifier CLASS CLASS_ID LCB $@1 none_or_newlines class_body none_or_newlines RCB  */
#line 364 "project.y"
                                                       { decreaseScope(); }
#line 1962 "project.tab.c"
    break;

  case 8: /* $@2: %empty  */
#line 365 "project.y"
                         {
    addSymbol((yyvsp[-1].sval), "class", false, true, true, NULL);
    increaseScope();
    }
#line 1971 "project.tab.c"
    break;

  case 9: /* class_declaration: CLASS CLASS_ID LCB $@2 none_or_newlines class_body none_or_newlines RCB  */
#line 368 "project.y"
                                                       { decreaseScope(); }
#line 1977 "project.tab.c"
    break;

  case 19: /* identifier_list_int: ID  */
#line 384 "project.y"
                        { addSymbol((yyvsp[0].sval), "int", false, false, false, NULL); }
#line 1983 "project.tab.c"
    break;

  case 20: /* identifier_list_int: ID COMMA identifier_list_int  */
#line 385 "project.y"
                                   { addSymbol((yyvsp[-2].sval), "int", false, false, false, NULL); }
#line 1989 "project.tab.c"
    break;

  case 21: /* identifier_list_string: ID  */
#line 388 "project.y"
                           { addSymbol((yyvsp[0].sval), "string", false, false, false, NULL); }
#line 1995 "project.tab.c"
    break;

  case 22: /* identifier_list_string: ID COMMA identifier_list_string  */
#line 389 "project.y"
                                      { addSymbol((yyvsp[-2].sval), "string", false, false, false, NULL); }
#line 2001 "project.tab.c"
    break;

  case 23: /* identifier_list_char: ID  */
#line 392 "project.y"
                         { addSymbol((yyvsp[0].sval), "char", false, false, false, NULL); }
#line 2007 "project.tab.c"
    break;

  case 24: /* identifier_list_char: ID COMMA identifier_list_char  */
#line 393 "project.y"
                                    { addSymbol((yyvsp[-2].sval), "char", false, false, false, NULL); }
#line 2013 "project.tab.c"
    break;

  case 25: /* identifier_list_double: ID  */
#line 396 "project.y"
                           { addSymbol((yyvsp[0].sval), "double", false, false, false, NULL); }
#line 2019 "project.tab.c"
    break;

  case 26: /* identifier_list_double: ID COMMA identifier_list_double  */
#line 397 "project.y"
                                      { addSymbol((yyvsp[-2].sval), "double", false, false, false, NULL); }
#line 2025 "project.tab.c"
    break;

  case 27: /* identifier_list_boolean: ID  */
#line 400 "project.y"
                            { addSymbol((yyvsp[0].sval), "boolean", false, false, false, NULL); }
#line 2031 "project.tab.c"
    break;

  case 28: /* identifier_list_boolean: ID COMMA identifier_list_boolean  */
#line 401 "project.y"
                                       { addSymbol((yyvsp[-2].sval), "boolean", false, false, false, NULL); }
#line 2037 "project.tab.c"
    break;

  case 29: /* identifier_list_variable: ID  */
#line 404 "project.y"
                             { addSymbol((yyvsp[0].sval), "var", false, false, false, NULL); }
#line 2043 "project.tab.c"
    break;

  case 30: /* identifier_list_variable: ID COMMA identifier_list_variable  */
#line 405 "project.y"
                                        { addSymbol((yyvsp[-2].sval), "var", false, false, false, NULL); }
#line 2049 "project.tab.c"
    break;

  case 38: /* assignment_list_int: ID ASSIGN exp_int  */
#line 417 "project.y"
                                       {
    char valueStr[32];
    sprintf(valueStr, "%d", (yyvsp[0].ival));
    addSymbol((yyvsp[-2].sval), "int", false, true, false, valueStr);
    addAssignment((yyvsp[-2].sval), valueStr);
    }
#line 2060 "project.tab.c"
    break;

  case 39: /* assignment_list_int: ID ASSIGN exp_int COMMA assignment_list_int  */
#line 423 "project.y"
                                                  {
    char valueStr[32]; sprintf(valueStr, "%d", (yyvsp[-2].ival));
    addSymbol((yyvsp[-4].sval), "int", false, true, false, valueStr);
    addAssignment((yyvsp[-4].sval), valueStr);
    }
#line 2070 "project.tab.c"
    break;

  case 40: /* assignment_list_string: ID ASSIGN DQ_STRING_DQ  */
#line 429 "project.y"
                                               { addSymbol((yyvsp[-2].sval), "string", false, true, false, (yyvsp[0].sval)); }
#line 2076 "project.tab.c"
    break;

  case 41: /* assignment_list_string: ID ASSIGN DQ_STRING_DQ COMMA assignment_list_string  */
#line 430 "project.y"
                                                          { addSymbol((yyvsp[-4].sval), "string", false, true, false, (yyvsp[-2].sval)); }
#line 2082 "project.tab.c"
    break;

  case 42: /* assignment_list_char: ID ASSIGN SQ_ANYCHAR_SQ  */
#line 433 "project.y"
                                              { addSymbol((yyvsp[-2].sval), "char", false, true, false, (yyvsp[0].cval)); }
#line 2088 "project.tab.c"
    break;

  case 43: /* assignment_list_char: ID ASSIGN SQ_ANYCHAR_SQ COMMA assignment_list_char  */
#line 434 "project.y"
                                                         { addSymbol((yyvsp[-4].sval), "char", false, true, false, (yyvsp[-2].cval)); }
#line 2094 "project.tab.c"
    break;

  case 44: /* assignment_list_double: ID ASSIGN exp_double  */
#line 437 "project.y"
                                             {
    char valueStr[64];
    sprintf(valueStr, "%f", (yyvsp[0].dval));
    addSymbol((yyvsp[-2].sval), "double", false, true, false, valueStr);
    addAssignment((yyvsp[-2].sval), valueStr);
    }
#line 2105 "project.tab.c"
    break;

  case 45: /* assignment_list_double: ID ASSIGN exp_double COMMA assignment_list_double  */
#line 443 "project.y"
                                                        {
    char valueStr[64];
    sprintf(valueStr, "%f", (yyvsp[-2].dval));
    addSymbol((yyvsp[-4].sval), "double", false, true, false, valueStr);
    addAssignment((yyvsp[-4].sval), valueStr);
    }
#line 2116 "project.tab.c"
    break;

  case 46: /* assignment_list_boolean: ID ASSIGN boolean  */
#line 450 "project.y"
                                           { addSymbol((yyvsp[-2].sval), "boolean", false, true, false, (yyvsp[0].sval)); }
#line 2122 "project.tab.c"
    break;

  case 47: /* assignment_list_boolean: ID ASSIGN boolean COMMA assignment_list_boolean  */
#line 451 "project.y"
                                                      { addSymbol((yyvsp[-4].sval), "boolean", false, true, false, (yyvsp[-2].sval)); }
#line 2128 "project.tab.c"
    break;

  case 48: /* assignment_list_method: ID ASSIGN method_call  */
#line 454 "project.y"
                                              {
    char* type = getType((yyvsp[0].sval));
    addSymbol((yyvsp[-2].sval), type, false, true, false, NULL);
    }
#line 2137 "project.tab.c"
    break;

  case 49: /* assignment_list_method: ID ASSIGN method_call COMMA assignment_list_method  */
#line 458 "project.y"
                                                         {
    char* type = getType((yyvsp[-2].sval));
    addSymbol((yyvsp[-4].sval), type, false, true, false, NULL);
    }
#line 2146 "project.tab.c"
    break;

  case 50: /* assignment_list_object: ID ASSIGN NEW CLASS_ID  */
#line 463 "project.y"
                                               { addSymbol((yyvsp[-3].sval), "class", false, true, false, NULL); }
#line 2152 "project.tab.c"
    break;

  case 51: /* assignment_list_object: ID ASSIGN NEW CLASS_ID COMMA assignment_list_object  */
#line 464 "project.y"
                                                          { addSymbol((yyvsp[-5].sval), "class", false, true, false, NULL); }
#line 2158 "project.tab.c"
    break;

  case 60: /* assignment_list_int_declared: ID ASSIGN exp_int  */
#line 477 "project.y"
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

  case 61: /* assignment_list_int_declared: ID ASSIGN exp_int COMMA assignment_list_int_declared  */
#line 488 "project.y"
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

  case 62: /* assignment_list_string_declared: ID ASSIGN DQ_STRING_DQ  */
#line 500 "project.y"
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

  case 63: /* assignment_list_string_declared: ID ASSIGN DQ_STRING_DQ COMMA assignment_list_string_declared  */
#line 508 "project.y"
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

  case 64: /* assignment_list_char_declared: ID ASSIGN SQ_ANYCHAR_SQ  */
#line 517 "project.y"
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

  case 65: /* assignment_list_char_declared: ID ASSIGN SQ_ANYCHAR_SQ COMMA assignment_list_char_declared  */
#line 525 "project.y"
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

  case 66: /* assignment_list_double_declared: ID ASSIGN exp_double  */
#line 534 "project.y"
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

  case 67: /* assignment_list_double_declared: ID ASSIGN exp_double COMMA assignment_list_double_declared  */
#line 545 "project.y"
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

  case 68: /* assignment_list_boolean_declared: ID ASSIGN boolean  */
#line 557 "project.y"
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

  case 69: /* assignment_list_boolean_declared: ID ASSIGN boolean COMMA assignment_list_boolean_declared  */
#line 565 "project.y"
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

  case 70: /* assignment_list_variable_declared: ID ASSIGN variable_reference  */
#line 574 "project.y"
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

  case 71: /* assignment_list_variable_declared: ID ASSIGN variable_reference COMMA assignment_list_variable_declared  */
#line 588 "project.y"
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

  case 72: /* assignment_list_method_declared: ID ASSIGN method_call  */
#line 603 "project.y"
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

  case 73: /* assignment_list_method_declared: ID ASSIGN method_call COMMA assignment_list_method_declared  */
#line 611 "project.y"
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

  case 74: /* assignment_list_object_declared: ID ASSIGN NEW CLASS_ID  */
#line 620 "project.y"
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

  case 75: /* assignment_list_object_declared: ID ASSIGN NEW CLASS_ID COMMA assignment_list_object_declared  */
#line 628 "project.y"
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

  case 81: /* variable_reference: ID  */
#line 644 "project.y"
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

  case 82: /* $@3: %empty  */
#line 656 "project.y"
                                                        {
    if (!symbolExists((yyvsp[0].sval), false, false)) {
        addSymbol((yyvsp[0].sval), (yyvsp[-1].sval), true, true, false, NULL);
    } else {
        yyerror("Method already declared");
    }
    increaseScope();
    }
#line 2419 "project.tab.c"
    break;

  case 83: /* method_declaration: access_modifier data_type METHOD_ID $@3 none_or_newlines none_or_multiple_parameters none_or_newlines RP LCB none_or_newlines method_body none_or_newlines RCB  */
#line 663 "project.y"
                                                                                                                             {
    decreaseScope();
    }
#line 2427 "project.tab.c"
    break;

  case 84: /* $@4: %empty  */
#line 666 "project.y"
                          {
    if (!symbolExists((yyvsp[0].sval), false, false)) {
        addSymbol((yyvsp[0].sval), (yyvsp[-1].sval), true, true, false, NULL);
    } else {
        yyerror("Method already declared");
    }
    increaseScope();
    }
#line 2440 "project.tab.c"
    break;

  case 85: /* method_declaration: data_type METHOD_ID $@4 none_or_newlines none_or_multiple_parameters none_or_newlines RP LCB none_or_newlines method_body none_or_newlines RCB  */
#line 673 "project.y"
                                                                                                                             {
    decreaseScope();
    }
#line 2448 "project.tab.c"
    break;

  case 90: /* parameter: data_type ID  */
#line 685 "project.y"
                        { addSymbol((yyvsp[0].sval), (yyvsp[-1].sval), false, true, false, NULL); }
#line 2454 "project.tab.c"
    break;

  case 112: /* statement: error  */
#line 713 "project.y"
            { yyerrok; }
#line 2460 "project.tab.c"
    break;

  case 115: /* method_call: METHOD_ID none_or_newlines none_or_multiple_arguments none_or_newlines RP SEMICOLON  */
#line 720 "project.y"
                                                                                                 {
    if (!symbolExists((yyvsp[-5].sval), true, false)) {
        yyerror("Method not declared");
    }
    }
#line 2470 "project.tab.c"
    break;

  case 156: /* single_or_multiple_variables: COMMA ID single_or_multiple_variables  */
#line 804 "project.y"
                                            {
    if (!symbolExists((yyvsp[-1].sval), false, false)) {
        yyerror("Variable not declared");
    } else if (!isInitialized((yyvsp[-1].sval))) {
        yyerror("Variable not initialized");
    }
    }
#line 2482 "project.tab.c"
    break;

  case 159: /* exp_int: term_int  */
#line 817 "project.y"
                  { (yyval.ival) = (yyvsp[0].ival); }
#line 2488 "project.tab.c"
    break;

  case 160: /* exp_int: exp_int ADD term_int  */
#line 818 "project.y"
                           { (yyval.ival) = (yyvsp[-2].ival) + (yyvsp[0].ival); }
#line 2494 "project.tab.c"
    break;

  case 161: /* exp_int: exp_int SUB term_int  */
#line 819 "project.y"
                           { (yyval.ival) = (yyvsp[-2].ival) - (yyvsp[0].ival); }
#line 2500 "project.tab.c"
    break;

  case 162: /* exp_int: error  */
#line 820 "project.y"
            { (yyval.ival) = 0; yyerrok; }
#line 2506 "project.tab.c"
    break;

  case 163: /* term_int: factor_int  */
#line 823 "project.y"
                     { (yyval.ival) = (yyvsp[0].ival); }
#line 2512 "project.tab.c"
    break;

  case 164: /* term_int: term_int MUL factor_int  */
#line 824 "project.y"
                              { (yyval.ival) = (yyvsp[-2].ival) * (yyvsp[0].ival); }
#line 2518 "project.tab.c"
    break;

  case 165: /* term_int: term_int DIV factor_int  */
#line 825 "project.y"
                              {
    if ((yyvsp[0].ival) == 0) {
        yyerror("Division by zero");
    } else {
        (yyval.ival) = (yyvsp[-2].ival) / (yyvsp[0].ival);
    }
    }
#line 2530 "project.tab.c"
    break;

  case 166: /* term_int: term_int MOD factor_int  */
#line 832 "project.y"
                              {
    if ((yyvsp[0].ival) == 0) {
        yyerror("Division by zero");
    } else {
        (yyval.ival) = fmod((yyvsp[-2].ival), (yyvsp[0].ival));
    }
    }
#line 2542 "project.tab.c"
    break;

  case 167: /* term_int: term_int POW factor_int  */
#line 839 "project.y"
                              {
    if ((yyvsp[-2].ival) == 0 && (yyvsp[0].ival) == 0) {
        yyerror("Exponentiation by zero");
    } else {
        (yyval.ival) = pow((yyvsp[-2].ival), (yyvsp[0].ival));
    }
    }
#line 2554 "project.tab.c"
    break;

  case 168: /* factor_int: primary_int  */
#line 847 "project.y"
                        { (yyval.ival) = (yyvsp[0].ival); }
#line 2560 "project.tab.c"
    break;

  case 169: /* factor_int: LP exp_int RP  */
#line 848 "project.y"
                    { (yyval.ival) = (yyvsp[-1].ival); }
#line 2566 "project.tab.c"
    break;

  case 170: /* exp_double: term_double  */
#line 852 "project.y"
                        { (yyval.dval) = (yyvsp[0].dval); }
#line 2572 "project.tab.c"
    break;

  case 171: /* exp_double: exp_double ADD term_double  */
#line 853 "project.y"
                                 { (yyval.dval) = (yyvsp[-2].dval) + (yyvsp[0].dval); }
#line 2578 "project.tab.c"
    break;

  case 172: /* exp_double: exp_double SUB term_double  */
#line 854 "project.y"
                                 { (yyval.dval) = (yyvsp[-2].dval) - (yyvsp[0].dval); }
#line 2584 "project.tab.c"
    break;

  case 173: /* exp_double: error  */
#line 855 "project.y"
            { (yyval.dval) = 0.0; yyerrok; }
#line 2590 "project.tab.c"
    break;

  case 174: /* term_double: factor_double  */
#line 858 "project.y"
                           { (yyval.dval) = (yyvsp[0].dval); }
#line 2596 "project.tab.c"
    break;

  case 175: /* term_double: term_double MUL factor_double  */
#line 859 "project.y"
                                    { (yyval.dval) = (yyvsp[-2].dval) * (yyvsp[0].dval); }
#line 2602 "project.tab.c"
    break;

  case 176: /* term_double: term_double DIV factor_double  */
#line 860 "project.y"
                                    {
    if ((yyvsp[0].dval) == 0) {
        yyerror("Division by zero");
    } else {
        (yyval.dval) = (yyvsp[-2].dval) / (yyvsp[0].dval);
    }
    }
#line 2614 "project.tab.c"
    break;

  case 177: /* term_double: term_double MOD factor_double  */
#line 867 "project.y"
                                    {
    if ((yyvsp[0].dval) == 0) {
        yyerror("Division by zero");
    } else {
        (yyval.dval) = fmod((yyvsp[-2].dval), (yyvsp[0].dval));
    }
    }
#line 2626 "project.tab.c"
    break;

  case 178: /* term_double: term_double POW factor_double  */
#line 874 "project.y"
                                    {
    if ((yyvsp[-2].dval) == 0 && (yyvsp[0].dval) == 0) {
        yyerror("Exponentiation by zero");
    } else {
        (yyval.dval) = pow((yyvsp[-2].dval), (yyvsp[0].dval));
    }
    }
#line 2638 "project.tab.c"
    break;

  case 179: /* factor_double: primary_double  */
#line 882 "project.y"
                              { (yyval.dval) = (yyvsp[0].dval); }
#line 2644 "project.tab.c"
    break;

  case 180: /* factor_double: LP exp_double RP  */
#line 883 "project.y"
                       { (yyval.dval) = (yyvsp[-1].dval); }
#line 2650 "project.tab.c"
    break;

  case 194: /* unary: primary_int  */
#line 906 "project.y"
                   { (yyval.ival) = (yyvsp[0].ival); }
#line 2656 "project.tab.c"
    break;

  case 195: /* unary: ADD primary_int  */
#line 907 "project.y"
                      { (yyval.ival) = (yyvsp[0].ival); }
#line 2662 "project.tab.c"
    break;

  case 196: /* unary: SUB primary_int  */
#line 908 "project.y"
                      { (yyval.ival) = -(yyvsp[0].ival); }
#line 2668 "project.tab.c"
    break;

  case 197: /* primary_int: CONST  */
#line 912 "project.y"
                   { (yyval.ival) = (yyvsp[0].ival); }
#line 2674 "project.tab.c"
    break;

  case 198: /* primary_int: variable_reference  */
#line 913 "project.y"
                         {
    if (strcmp((yyvsp[0].sval), "ERROR") == 0) {
        (yyval.ival) = 0;
    } else {
        (yyval.ival) = atoi(getValue((yyvsp[0].sval)));
    }
    }
#line 2686 "project.tab.c"
    break;

  case 199: /* primary_double: DOUBLE_CONST  */
#line 923 "project.y"
                             { (yyval.dval) = (yyvsp[0].dval); }
#line 2692 "project.tab.c"
    break;

  case 200: /* primary_double: variable_reference  */
#line 924 "project.y"
                         {
    if (strcmp((yyvsp[0].sval), "ERROR") == 0) {
        (yyval.dval) = 0.0;
    } else {
        (yyval.dval) = atof(getValue((yyvsp[0].sval)));
    }
    }
#line 2704 "project.tab.c"
    break;

  case 201: /* $@5: %empty  */
#line 933 "project.y"
                                                 {
    if (!symbolExists((yyvsp[-4].sval), false, true)) {
        yyerror("Class not declared");
    } else {
        addSymbol((yyvsp[-3].sval), (yyvsp[-4].sval), false, true, false, (yyvsp[0].sval));
    }
    }
#line 2716 "project.tab.c"
    break;

  case 203: /* member_access: ID DOT member_access_body none_or_newlines  */
#line 942 "project.y"
                                                          {
    if (!symbolExists((yyvsp[-3].sval), false, true)) {
        yyerror("Class not declared");
    } else if (!symbolExists((yyvsp[-1].sval), false, false)) {
        yyerror("Member not declared");
    }
    }
#line 2728 "project.tab.c"
    break;

  case 204: /* member_access_body: ID SEMICOLON  */
#line 951 "project.y"
                                 {
    if (!symbolExists((yyvsp[-1].sval), false, false)) {
        yyerror("Variable not declared");
    }
    }
#line 2738 "project.tab.c"
    break;

  case 205: /* member_access_body: method_call  */
#line 956 "project.y"
                  {
    if (!symbolExists((yyvsp[0].sval), true, false)) {
        yyerror("Method not declared");
    }
    }
#line 2748 "project.tab.c"
    break;

  case 208: /* boolean: TRUE  */
#line 966 "project.y"
              { (yyval.sval) = "true"; }
#line 2754 "project.tab.c"
    break;

  case 209: /* boolean: FALSE  */
#line 967 "project.y"
            { (yyval.sval) = "false"; }
#line 2760 "project.tab.c"
    break;

  case 210: /* data_type: %empty  */
#line 970 "project.y"
                         { (yyval.sval) = ""; }
#line 2766 "project.tab.c"
    break;

  case 211: /* data_type: INTEGER  */
#line 971 "project.y"
              { (yyval.sval) = "int"; }
#line 2772 "project.tab.c"
    break;

  case 212: /* data_type: CHAR  */
#line 972 "project.y"
           { (yyval.sval) = "char"; }
#line 2778 "project.tab.c"
    break;

  case 213: /* data_type: DOUBLE  */
#line 973 "project.y"
             { (yyval.sval) = "double"; }
#line 2784 "project.tab.c"
    break;

  case 214: /* data_type: BOOLEAN  */
#line 974 "project.y"
              { (yyval.sval) = "boolean"; }
#line 2790 "project.tab.c"
    break;

  case 215: /* data_type: STRING  */
#line 975 "project.y"
             { (yyval.sval) = "string"; }
#line 2796 "project.tab.c"
    break;

  case 216: /* data_type: VOID  */
#line 976 "project.y"
           { (yyval.sval) = "void"; }
#line 2802 "project.tab.c"
    break;


#line 2806 "project.tab.c"

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

#line 983 "project.y"


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
            fprintf(yyout, "\n%4d  | ", line_number);
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
