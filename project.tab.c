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
void addSymbol(char *name, char *type, bool isMethod, bool isInitialized, bool isClass, char *value) {
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
    symbolTable[symbolCount].value = value ? strdup(value) : strdup("UNINITIALIZED"); // Use placeholder for uninitialized variables
    symbolCount++;

    // Print the symbol table
    printf("Symbol table:\n");
    for (int i = 0; i < symbolCount; i++) {
        printf("Name: %s, Type: %s, isMethod: %d, isInitialized: %d, Scope: %d, isClass: %d, Value: %s\n\n",
               symbolTable[i].name, symbolTable[i].type, symbolTable[i].isMethod,
               symbolTable[i].isInitialized, symbolTable[i].scope, symbolTable[i].isClass, symbolTable[i].value);
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
void setInitialized(char *name, char *value) {
    if (name == NULL) {
        fprintf(stderr, "Error: Null pointer in setInitialized function\n");
        exit(1);
    }
    for (int i = 0; i < symbolCount; i++) {
        if (symbolTable[i].name != NULL && strcmp(symbolTable[i].name, name) == 0 && symbolTable[i].scope == scope) {
            symbolTable[i].isInitialized = true;
            if (value != NULL) {
                free(symbolTable[i].value); // Free the old value
                symbolTable[i].value = strdup(value); // Set the new value
            }
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

// Function to get the value of a variable
char* getValue(char *name) {
    if (name == NULL) {
        fprintf(stderr, "Error: Null pointer in getValue function\n");
        exit(1);
    }
    for (int i = 0; i < symbolCount; i++) {
        if (symbolTable[i].name != NULL && strcmp(symbolTable[i].name, name) == 0 && symbolTable[i].scope <= scope) {
            return symbolTable[i].value;
        }
    }
    return NULL;
}


#line 251 "project.tab.c"

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
  YYSYMBOL_ANY_CHARACTER = 6,              /* ANY_CHARACTER  */
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
  YYSYMBOL_QUESTION = 39,                  /* QUESTION  */
  YYSYMBOL_COLON = 40,                     /* COLON  */
  YYSYMBOL_DQ = 41,                        /* DQ  */
  YYSYMBOL_SQ = 42,                        /* SQ  */
  YYSYMBOL_LP = 43,                        /* LP  */
  YYSYMBOL_RP = 44,                        /* RP  */
  YYSYMBOL_LSB = 45,                       /* LSB  */
  YYSYMBOL_RSB = 46,                       /* RSB  */
  YYSYMBOL_LCB = 47,                       /* LCB  */
  YYSYMBOL_RCB = 48,                       /* RCB  */
  YYSYMBOL_ASSIGN = 49,                    /* ASSIGN  */
  YYSYMBOL_OR = 50,                        /* OR  */
  YYSYMBOL_AND = 51,                       /* AND  */
  YYSYMBOL_EQ = 52,                        /* EQ  */
  YYSYMBOL_NEQ = 53,                       /* NEQ  */
  YYSYMBOL_LT = 54,                        /* LT  */
  YYSYMBOL_LE = 55,                        /* LE  */
  YYSYMBOL_GT = 56,                        /* GT  */
  YYSYMBOL_GE = 57,                        /* GE  */
  YYSYMBOL_ADD = 58,                       /* ADD  */
  YYSYMBOL_SUB = 59,                       /* SUB  */
  YYSYMBOL_MUL = 60,                       /* MUL  */
  YYSYMBOL_DIV = 61,                       /* DIV  */
  YYSYMBOL_MOD = 62,                       /* MOD  */
  YYSYMBOL_POW = 63,                       /* POW  */
  YYSYMBOL_NOT = 64,                       /* NOT  */
  YYSYMBOL_YYACCEPT = 65,                  /* $accept  */
  YYSYMBOL_program = 66,                   /* program  */
  YYSYMBOL_class_declaration = 67,         /* class_declaration  */
  YYSYMBOL_68_1 = 68,                      /* $@1  */
  YYSYMBOL_69_2 = 69,                      /* $@2  */
  YYSYMBOL_class_body = 70,                /* class_body  */
  YYSYMBOL_identifier_list = 71,           /* identifier_list  */
  YYSYMBOL_identifier_list_int = 72,       /* identifier_list_int  */
  YYSYMBOL_identifier_list_string = 73,    /* identifier_list_string  */
  YYSYMBOL_identifier_list_char = 74,      /* identifier_list_char  */
  YYSYMBOL_identifier_list_double = 75,    /* identifier_list_double  */
  YYSYMBOL_identifier_list_boolean = 76,   /* identifier_list_boolean  */
  YYSYMBOL_identifier_list_variable = 77,  /* identifier_list_variable  */
  YYSYMBOL_assignment_list = 78,           /* assignment_list  */
  YYSYMBOL_assignment_list_int = 79,       /* assignment_list_int  */
  YYSYMBOL_assignment_list_string = 80,    /* assignment_list_string  */
  YYSYMBOL_assignment_list_char = 81,      /* assignment_list_char  */
  YYSYMBOL_assignment_list_double = 82,    /* assignment_list_double  */
  YYSYMBOL_assignment_list_boolean = 83,   /* assignment_list_boolean  */
  YYSYMBOL_assignment_list_variable = 84,  /* assignment_list_variable  */
  YYSYMBOL_assignment_list_method = 85,    /* assignment_list_method  */
  YYSYMBOL_assignment_list_object = 86,    /* assignment_list_object  */
  YYSYMBOL_assignment_list_declared = 87,  /* assignment_list_declared  */
  YYSYMBOL_assignment_list_int_declared = 88, /* assignment_list_int_declared  */
  YYSYMBOL_assignment_list_string_declared = 89, /* assignment_list_string_declared  */
  YYSYMBOL_assignment_list_char_declared = 90, /* assignment_list_char_declared  */
  YYSYMBOL_assignment_list_double_declared = 91, /* assignment_list_double_declared  */
  YYSYMBOL_assignment_list_boolean_declared = 92, /* assignment_list_boolean_declared  */
  YYSYMBOL_assignment_list_variable_declared = 93, /* assignment_list_variable_declared  */
  YYSYMBOL_assignment_list_method_declared = 94, /* assignment_list_method_declared  */
  YYSYMBOL_assignment_list_object_declared = 95, /* assignment_list_object_declared  */
  YYSYMBOL_variable_declaration = 96,      /* variable_declaration  */
  YYSYMBOL_variable_reference = 97,        /* variable_reference  */
  YYSYMBOL_variable_reference_int = 98,    /* variable_reference_int  */
  YYSYMBOL_variable_reference_double = 99, /* variable_reference_double  */
  YYSYMBOL_method_declaration = 100,       /* method_declaration  */
  YYSYMBOL_101_3 = 101,                    /* $@3  */
  YYSYMBOL_102_4 = 102,                    /* $@4  */
  YYSYMBOL_none_or_multiple_parameters = 103, /* none_or_multiple_parameters  */
  YYSYMBOL_parameters = 104,               /* parameters  */
  YYSYMBOL_parameter = 105,                /* parameter  */
  YYSYMBOL_method_body = 106,              /* method_body  */
  YYSYMBOL_statement = 107,                /* statement  */
  YYSYMBOL_assignment_statement = 108,     /* assignment_statement  */
  YYSYMBOL_method_call = 109,              /* method_call  */
  YYSYMBOL_none_or_multiple_arguments = 110, /* none_or_multiple_arguments  */
  YYSYMBOL_arguments = 111,                /* arguments  */
  YYSYMBOL_if_statement = 112,             /* if_statement  */
  YYSYMBOL_if_elif_parenthesis_statement = 113, /* if_elif_parenthesis_statement  */
  YYSYMBOL_none_or_multiple_elif = 114,    /* none_or_multiple_elif  */
  YYSYMBOL_none_or_one_else = 115,         /* none_or_one_else  */
  YYSYMBOL_do_while_statement = 116,       /* do_while_statement  */
  YYSYMBOL_for_statement = 117,            /* for_statement  */
  YYSYMBOL_first_and_third_loop_statement = 118, /* first_and_third_loop_statement  */
  YYSYMBOL_second_loop_statement = 119,    /* second_loop_statement  */
  YYSYMBOL_switch_statement = 120,         /* switch_statement  */
  YYSYMBOL_default_case = 121,             /* default_case  */
  YYSYMBOL_one_or_more_cases = 122,        /* one_or_more_cases  */
  YYSYMBOL_multiple_cases = 123,           /* multiple_cases  */
  YYSYMBOL_cases = 124,                    /* cases  */
  YYSYMBOL_case_expression = 125,          /* case_expression  */
  YYSYMBOL_return_statement = 126,         /* return_statement  */
  YYSYMBOL_break_statement = 127,          /* break_statement  */
  YYSYMBOL_print_statement = 128,          /* print_statement  */
  YYSYMBOL_single_or_multiple_variables = 129, /* single_or_multiple_variables  */
  YYSYMBOL_exp = 130,                      /* exp  */
  YYSYMBOL_exp_int = 131,                  /* exp_int  */
  YYSYMBOL_term_int = 132,                 /* term_int  */
  YYSYMBOL_factor_int = 133,               /* factor_int  */
  YYSYMBOL_exp_double = 134,               /* exp_double  */
  YYSYMBOL_term_double = 135,              /* term_double  */
  YYSYMBOL_factor_double = 136,            /* factor_double  */
  YYSYMBOL_relational_exp = 137,           /* relational_exp  */
  YYSYMBOL_relational_factor = 138,        /* relational_factor  */
  YYSYMBOL_logical_term = 139,             /* logical_term  */
  YYSYMBOL_unary = 140,                    /* unary  */
  YYSYMBOL_primary_int = 141,              /* primary_int  */
  YYSYMBOL_primary_double = 142,           /* primary_double  */
  YYSYMBOL_object_creation = 143,          /* object_creation  */
  YYSYMBOL_144_5 = 144,                    /* $@5  */
  YYSYMBOL_member_access = 145,            /* member_access  */
  YYSYMBOL_146_6 = 146,                    /* $@6  */
  YYSYMBOL_member_access_body = 147,       /* member_access_body  */
  YYSYMBOL_access_modifier = 148,          /* access_modifier  */
  YYSYMBOL_boolean = 149,                  /* boolean  */
  YYSYMBOL_data_type = 150,                /* data_type  */
  YYSYMBOL_none_or_newlines = 151          /* none_or_newlines  */
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
#define YYFINAL  118
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   724

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  87
/* YYNRULES -- Number of rules.  */
#define YYNRULES  218
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  489

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   319


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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   246,   246,   247,   248,   251,   251,   255,   255,   261,
     262,   263,   266,   267,   268,   269,   270,   271,   274,   275,
     278,   279,   282,   283,   286,   287,   290,   291,   294,   295,
     299,   300,   301,   302,   303,   304,   305,   306,   309,   315,
     321,   322,   325,   326,   329,   335,   342,   343,   346,   351,
     357,   361,   366,   367,   370,   371,   372,   373,   374,   375,
     376,   377,   380,   392,   405,   414,   424,   433,   443,   455,
     468,   477,   487,   497,   508,   517,   527,   536,   547,   548,
     549,   550,   551,   555,   565,   575,   586,   586,   590,   590,
     595,   596,   599,   600,   603,   606,   607,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   629,   630,   634,   640,   641,   642,
     645,   646,   647,   650,   653,   654,   655,   656,   657,   660,
     661,   664,   665,   668,   669,   672,   675,   676,   677,   680,
     681,   684,   685,   688,   689,   692,   695,   696,   699,   702,
     703,   706,   707,   708,   711,   714,   717,   718,   726,   727,
     731,   732,   733,   736,   737,   738,   746,   754,   763,   764,
     768,   769,   770,   773,   774,   775,   783,   791,   800,   801,
     804,   805,   806,   807,   808,   809,   810,   813,   814,   815,
     818,   819,   820,   823,   824,   825,   828,   829,   832,   833,
     836,   836,   845,   845,   854,   859,   865,   866,   869,   870,
     873,   874,   875,   876,   877,   878,   879,   882,   883
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
  "CLASS_ID", "ANY_CHARACTER", "DOUBLE_CONST", "SQ_ANYCHAR_SQ",
  "DQ_STRING_DQ", "VAR", "NEWLINE", "CLASS", "PUBLIC", "PRIVATE",
  "INTEGER", "CHAR", "DOUBLE", "BOOLEAN", "STRING", "VOID", "NEW",
  "RETURN", "IF", "ELIF", "ELSE", "SWITCH", "CASE", "DEFAULT", "WHILE",
  "DO", "FOR", "BREAK", "TRUE", "FALSE", "PRINT", "SEMICOLON", "COMMA",
  "DOT", "QUESTION", "COLON", "DQ", "SQ", "LP", "RP", "LSB", "RSB", "LCB",
  "RCB", "ASSIGN", "OR", "AND", "EQ", "NEQ", "LT", "LE", "GT", "GE", "ADD",
  "SUB", "MUL", "DIV", "MOD", "POW", "NOT", "$accept", "program",
  "class_declaration", "$@1", "$@2", "class_body", "identifier_list",
  "identifier_list_int", "identifier_list_string", "identifier_list_char",
  "identifier_list_double", "identifier_list_boolean",
  "identifier_list_variable", "assignment_list", "assignment_list_int",
  "assignment_list_string", "assignment_list_char",
  "assignment_list_double", "assignment_list_boolean",
  "assignment_list_variable", "assignment_list_method",
  "assignment_list_object", "assignment_list_declared",
  "assignment_list_int_declared", "assignment_list_string_declared",
  "assignment_list_char_declared", "assignment_list_double_declared",
  "assignment_list_boolean_declared", "assignment_list_variable_declared",
  "assignment_list_method_declared", "assignment_list_object_declared",
  "variable_declaration", "variable_reference", "variable_reference_int",
  "variable_reference_double", "method_declaration", "$@3", "$@4",
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
  "unary", "primary_int", "primary_double", "object_creation", "$@5",
  "member_access", "$@6", "member_access_body", "access_modifier",
  "boolean", "data_type", "none_or_newlines", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-415)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-211)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     602,  -415,   289,    19,  -415,    -6,    57,    85,  -415,  -415,
      76,    94,   103,   105,   109,  -415,    30,   107,   114,   113,
     120,   150,   122,    46,   234,   234,    24,   178,   181,  -415,
    -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
     153,   172,  -415,  -415,  -415,   181,  -415,  -415,  -415,  -415,
    -415,  -415,  -415,  -415,   176,   183,   362,  -415,   214,   437,
    -415,   194,   250,  -415,  -415,   346,  -415,  -415,  -415,   401,
     229,   235,   181,    36,   173,  -415,    27,  -415,  -415,  -415,
    -415,   210,    89,  -415,  -415,   131,  -415,  -415,   195,  -415,
    -415,   218,  -415,  -415,   222,  -415,  -415,   138,   108,   230,
     238,   242,  -415,   181,   181,   181,   181,  -415,   271,  -415,
     118,   177,   208,  -415,  -415,  -415,  -415,  -415,  -415,   181,
     602,  -415,  -415,   602,  -415,    38,    38,    38,    38,    38,
      38,   112,   112,   112,   112,   112,   112,  -415,    63,    63,
      63,    63,    63,    63,    63,    63,   288,  -415,  -415,   292,
     281,    29,  -415,  -415,   293,   296,   298,   321,  -415,  -415,
     300,   302,    81,   100,   304,   324,   343,    64,  -415,   345,
      38,   349,   358,   350,   112,   359,   283,   365,   341,  -415,
    -415,  -415,    44,    28,   660,   342,   339,  -415,  -415,  -415,
    -415,  -415,  -415,    38,   362,   362,  -415,  -415,  -415,  -415,
    -415,   112,   437,   437,  -415,  -415,  -415,  -415,    63,   250,
     250,   250,   250,   250,   250,  -415,  -415,   337,   351,  -415,
    -415,   181,  -415,  -415,  -415,  -415,  -415,  -415,   348,   348,
     181,   384,   385,   411,   368,   424,   425,   435,   439,   440,
     436,   409,  -415,   404,   443,   418,   429,   181,   430,  -415,
     148,   431,  -415,   441,   447,  -415,   151,   454,  -415,   456,
     464,  -415,   465,  -415,  -415,   181,  -415,   405,  -415,   181,
     181,   181,   417,   427,  -415,  -415,   444,   355,   473,   488,
     461,  -415,  -415,   181,  -415,   181,  -415,  -415,   467,  -415,
     463,  -415,   466,  -415,   509,   470,  -415,   471,  -415,   472,
    -415,   474,  -415,   476,  -415,  -415,   477,   424,   425,   272,
     512,   385,   439,   440,   411,   478,   485,   486,   483,   181,
      76,    94,   103,   105,   109,   487,   339,   496,   181,   181,
     363,   293,   498,   489,  -415,   531,   533,    38,   497,   509,
    -415,  -415,   181,   181,   181,   490,  -415,  -415,  -415,  -415,
    -415,   494,   495,   500,   519,    63,   129,  -415,  -415,   272,
     363,   181,   514,   348,   348,  -415,   532,   404,   513,  -415,
     272,   508,   272,   181,   181,   181,   515,   523,   405,    10,
    -415,  -415,   181,   181,   518,   181,  -415,  -415,  -415,   527,
    -415,  -415,  -415,   660,   538,   538,   181,   181,   520,   522,
     525,   455,  -415,   181,   139,   181,   181,   181,    71,   342,
    -415,   526,   181,   514,   521,  -415,  -415,   530,   539,   538,
     539,     8,   181,   142,   181,   181,   660,  -415,   181,   181,
     534,   181,  -415,   181,   181,   535,   536,   537,   660,   181,
     181,   552,   660,   181,   529,   538,   540,   542,   546,   543,
     181,   541,   660,   544,   181,  -415,   660,  -415,  -415,  -415,
    -415,  -415,   181,   545,  -415,  -415,    44,   559,  -415,   660,
    -415,   547,   549,  -415,   181,   551,   181,   553,   181,   660,
    -415,   660,   181,   181,   554,   560,  -415,   552,  -415
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,   196,    84,     0,   198,     0,     0,     0,   206,   207,
       0,     0,     0,     0,     0,   216,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   217,    78,
      81,    82,    54,    55,    56,    57,    58,    59,    60,    61,
       0,     0,   197,   199,   110,   217,    98,    99,   100,   101,
     102,   103,   104,   105,     0,   158,   160,   163,   159,   170,
     173,     0,   180,   187,   190,   168,   178,   111,   113,   210,
       0,     0,   217,     0,     0,   108,    28,    17,    35,    36,
      37,     0,    18,    12,    30,    22,    14,    32,    24,    15,
      33,    26,    16,    34,    20,    13,    31,    84,     0,     0,
       0,     0,   168,   217,   217,   217,   217,   154,     0,    84,
       0,     0,     0,    84,   194,   195,   191,   193,     1,   217,
       2,   109,   112,     2,   106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    79,    80,     0,
       0,     0,   205,   202,   117,    66,    64,     0,   208,   209,
      72,    74,    62,    68,    70,     0,     0,     0,     7,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   152,
     153,   151,     0,     0,    97,   136,   156,   169,   179,   192,
     218,     3,     4,     0,   161,   162,   164,   165,   166,   167,
      85,     0,   171,   172,   174,   175,   176,   177,     0,   181,
     182,   183,   185,   184,   186,   189,   188,     0,     0,    88,
     204,   217,    83,   211,   212,   213,   214,   215,   120,   120,
     217,     0,     0,     0,    76,     0,     0,     0,     0,     0,
       0,    28,    29,    83,     0,    48,    50,   217,    18,    19,
      38,    22,    23,    42,    24,    25,    44,    26,    27,    46,
      20,    21,    40,   126,   127,   217,   124,   125,   128,   217,
     217,   217,   210,     0,   138,   137,     0,     0,     0,     0,
       0,     5,    86,   217,   203,   217,   119,   118,     0,    94,
       0,    67,     0,    65,     0,     0,    73,     0,    75,     0,
      63,     0,    69,     0,    71,   200,    52,     0,     0,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   217,
       0,     0,     0,     0,     0,     0,   156,     0,   217,   217,
      90,     0,     0,     0,    77,     0,     0,     0,     0,     0,
      49,    51,   217,   217,   217,     0,    39,    43,    45,    47,
      41,     0,     0,     0,     0,   139,     0,   157,   155,     9,
      90,   217,    92,   120,   120,   116,     0,     0,     0,    53,
       9,     0,     9,   217,   217,   217,     0,     0,   140,    84,
     115,   114,   217,   217,     0,   217,    91,   122,   121,     0,
      10,     8,    11,    97,     0,     0,   217,   217,     0,     0,
       0,   210,   201,   217,     0,   217,   217,   217,     0,   136,
       6,     0,   217,    92,     0,   149,   150,     0,   143,   146,
     143,    84,   217,   217,   217,   217,    95,    93,   217,   217,
       0,   217,   145,   217,   217,     0,     0,     0,    95,   217,
     217,   129,    97,   217,     0,   146,     0,     0,     0,     0,
     217,     0,    95,     0,   217,   148,    97,   142,   147,   141,
     134,   133,   217,     0,    89,    96,     0,   131,   144,    97,
      87,     0,     0,   123,   217,     0,   217,     0,   217,    97,
     135,    97,   217,   217,     0,     0,   132,   129,   130
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -415,    23,    11,  -415,  -415,  -116,   -49,   416,   415,   423,
     413,   448,   434,   -43,   316,  -218,  -216,  -226,  -221,  -213,
    -211,  -277,  -415,   373,  -415,  -415,  -415,  -415,  -415,  -415,
    -415,  -178,   -13,  -415,  -415,  -415,  -415,  -415,   267,   216,
    -148,  -414,     0,  -415,   -15,  -415,  -219,  -415,   164,   144,
    -415,  -415,  -415,   226,  -415,  -415,   219,   241,   193,  -390,
    -415,  -415,  -415,  -415,   314,   -12,   -14,   180,   280,   -10,
     188,   374,   -21,   347,   184,   615,    75,  -415,  -415,  -415,
    -415,  -415,  -415,     5,   -59,   -61,   121
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    27,   342,   328,   247,   343,    29,    83,    95,    86,
      89,    92,    77,    30,    84,    96,    87,    90,    93,    78,
      79,    80,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,   329,   283,   361,   386,
     362,   439,   344,   275,    46,   230,   286,    47,   265,   454,
     473,    48,    49,   276,   377,    50,   431,   405,   432,   406,
     417,    51,    52,    53,   280,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,   338,
      68,   221,   153,   272,   268,    70,   120
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,   100,   112,    99,   101,    69,   229,   274,   149,   110,
     287,    28,   302,   111,   164,   293,   291,   334,   304,   -83,
     147,   -83,   296,    74,   450,   298,   148,     1,   113,   433,
      75,     1,   109,     1,    97,     4,   269,     4,   465,     1,
      97,     1,   113,     4,   155,   156,   -83,     1,    97,     1,
     109,     4,   -83,     4,   -83,   433,   152,   157,   161,   162,
     160,    76,   369,   163,   166,   220,     1,   113,   243,   158,
     159,    98,    72,    98,     1,   421,   167,   158,   159,    98,
      82,   193,    24,    25,   110,   244,   348,    23,   111,    23,
      81,   102,   349,   231,   340,   347,   350,   341,    85,   114,
     115,   117,    24,    25,    24,    25,   208,    88,    26,    91,
      26,     1,   109,    94,   208,     4,   200,   259,   237,     4,
      45,    24,    25,    45,   278,    69,   169,    26,    69,    24,
      25,    28,     1,   379,    28,    26,     4,   238,   170,   125,
     126,   228,   415,   191,   387,   388,   192,   416,   102,   -83,
     103,    98,   246,   119,   245,   201,   250,   104,   131,   132,
     105,   267,   187,   106,   256,   108,   123,   264,   171,   263,
     266,   270,    98,   102,   -83,   -83,   125,   126,   118,   110,
     172,    72,   -83,   364,   271,   310,   107,   112,   312,   121,
     277,   111,   119,   154,   138,   139,   140,   141,   142,   143,
     102,   102,   102,   102,   102,   102,   125,   126,   122,   131,
     132,   149,   124,   117,   117,   117,   117,   117,   117,   117,
     117,   188,   165,   147,   182,   183,   184,   185,   147,   148,
     137,   274,   173,   150,   148,   131,   132,     1,   113,   151,
     190,   125,   126,   382,   174,   102,   138,   139,   140,   141,
     142,   143,   189,   413,   390,   175,   392,   168,   102,   177,
     138,   139,   140,   141,   142,   143,   179,   176,   102,   231,
     231,   178,   131,   132,   180,     1,     2,     3,   181,     4,
     186,     5,     6,   117,     7,     8,     9,    10,    11,    12,
      13,    14,    15,   217,    16,    17,   218,   222,    18,   231,
     144,   145,    19,    20,    21,   194,   195,    22,   223,   224,
     225,   226,   227,    15,    69,    23,   158,   159,   363,   202,
     203,   246,   245,   162,   219,   -83,   234,    71,   215,   216,
      24,    25,    72,   232,   378,   233,    26,   235,    73,   236,
     231,   239,   284,   380,   381,   240,   273,   241,   278,   248,
     262,   288,     6,   251,   254,     8,     9,    10,    11,    12,
      13,    14,    15,   257,    69,     6,   253,  -210,   309,   260,
     320,   321,   322,   323,   324,    69,   279,    69,   223,   224,
     225,   226,   227,    15,   281,   285,   315,   423,   289,   290,
     316,   317,   318,   403,   282,   422,  -193,  -193,  -193,  -193,
    -193,  -193,  -193,  -193,   330,   294,   331,   196,   197,   198,
     199,     6,   102,   146,   277,   292,    10,    11,    12,    13,
      14,    15,   127,   128,   129,   130,   440,     6,   295,   297,
     117,   102,    10,    11,    12,    13,    14,    15,   440,   299,
     355,   305,   455,   301,   303,   267,   166,    72,   306,   359,
     360,   264,   440,   263,   266,   307,   468,   138,   139,   140,
     141,   142,   143,   370,   371,   372,   308,   169,   171,   474,
     223,   224,   225,   226,   227,    15,    73,   325,   311,   482,
     319,   483,   384,   117,   173,   209,   210,   211,   212,   213,
     214,   175,   326,   313,   393,   394,   395,   133,   134,   135,
     136,   177,   314,   398,   399,   327,   401,   204,   205,   206,
     207,   332,   172,   333,   339,   178,   345,   408,   409,   335,
     336,   337,   351,   174,   414,   176,   418,   419,   420,   352,
     353,   354,   358,   426,   365,   222,   356,   367,   366,   170,
     368,   373,   374,   435,   436,   437,   438,   375,   376,   441,
     442,   385,   444,   244,   445,   446,   391,   389,   396,   397,
     451,   452,   400,   402,   456,   404,   411,   430,   410,   428,
     429,   463,   412,   425,   443,   467,   453,   457,   460,   447,
     448,   449,   461,   469,   472,   249,   255,   466,   459,   464,
     462,   475,   261,   470,   252,   477,   476,   479,   478,   481,
     242,   480,   486,   484,   485,     1,     2,     3,   487,     4,
     300,     5,     6,   -97,     7,     8,     9,    10,    11,    12,
      13,    14,    15,   258,    16,    17,   346,   383,    18,   427,
     471,   488,    19,    20,    21,   424,   407,    22,   458,   434,
     357,   116,     0,     0,     0,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      24,    25,     0,     1,     2,     3,    26,     4,     0,     5,
       6,     0,     0,     8,     9,    10,    11,    12,    13,    14,
      15,     0,    16,    17,     0,     0,    18,     0,     0,     0,
      19,    20,    21,     0,     0,    22,     0,     0,     0,     0,
       0,     0,     0,    23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,    25,
       0,     0,     0,     0,    26
};

static const yytype_int16 yycheck[] =
{
       0,    16,    23,    16,    16,     0,   154,   185,    69,    23,
     229,     0,   238,    23,    73,   233,   232,   294,   239,    11,
      69,    11,   235,     4,   438,   236,    69,     3,     4,   419,
      36,     3,     4,     3,     4,     7,     8,     7,   452,     3,
       4,     3,     4,     7,     8,     9,    36,     3,     4,     3,
       4,     7,    44,     7,    44,   445,    71,    21,    73,    73,
      73,     4,   339,    73,    37,    36,     3,     4,     4,    33,
      34,    43,    43,    43,     3,     4,    49,    33,    34,    43,
       4,    43,    58,    59,    98,    21,   312,    43,    98,    43,
       5,    16,   313,   154,   307,   311,   314,   308,     4,    24,
      25,    26,    58,    59,    58,    59,    43,     4,    64,     4,
      64,     3,     4,     4,    43,     7,     4,   176,    37,     7,
     120,    58,    59,   123,   185,   120,    37,    64,   123,    58,
      59,   120,     3,     4,   123,    64,     7,    37,    49,    58,
      59,   154,     3,   120,   363,   364,   123,     8,    73,    11,
      43,    43,   167,    11,   167,    43,   170,    43,    58,    59,
      47,   182,    44,    43,   174,    43,    45,   182,    37,   182,
     182,   183,    43,    98,    36,    37,    58,    59,     0,   193,
      49,    43,    44,   331,   184,    37,    36,   208,    37,    36,
     185,   201,    11,    72,    52,    53,    54,    55,    56,    57,
     125,   126,   127,   128,   129,   130,    58,    59,    36,    58,
      59,   272,    36,   138,   139,   140,   141,   142,   143,   144,
     145,    44,    49,   272,   103,   104,   105,   106,   277,   272,
      36,   409,    37,     4,   277,    58,    59,     3,     4,     4,
     119,    58,    59,   359,    49,   170,    52,    53,    54,    55,
      56,    57,    44,   401,   370,    37,   372,    47,   183,    37,
      52,    53,    54,    55,    56,    57,    36,    49,   193,   330,
     331,    49,    58,    59,    36,     3,     4,     5,    36,     7,
       9,     9,    10,   208,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     5,    22,    23,     4,     4,    26,   360,
      50,    51,    30,    31,    32,   125,   126,    35,    15,    16,
      17,    18,    19,    20,   309,    43,    33,    34,   331,   131,
     132,   336,   335,   337,    43,    36,     5,    38,   144,   145,
      58,    59,    43,    37,   355,    37,    64,    37,    49,    37,
     401,    37,   221,   356,   356,    21,     4,     4,   409,     4,
       9,   230,    10,     4,     4,    13,    14,    15,    16,    17,
      18,    19,    20,     4,   359,    10,     8,     4,   247,     4,
      15,    16,    17,    18,    19,   370,    37,   372,    15,    16,
      17,    18,    19,    20,    47,    37,   265,   408,     4,     4,
     269,   270,   271,   393,    43,   408,    50,    51,    52,    53,
      54,    55,    56,    57,   283,    37,   285,   127,   128,   129,
     130,    10,   337,    12,   409,     4,    15,    16,    17,    18,
      19,    20,    60,    61,    62,    63,   426,    10,     4,     4,
     355,   356,    15,    16,    17,    18,    19,    20,   438,     4,
     319,     5,   442,     4,     4,   466,    37,    43,     5,   328,
     329,   466,   452,   466,   466,    37,   456,    52,    53,    54,
      55,    56,    57,   342,   343,   344,    37,    37,    37,   469,
      15,    16,    17,    18,    19,    20,    49,     4,    37,   479,
      36,   481,   361,   408,    37,   138,   139,   140,   141,   142,
     143,    37,     4,    37,   373,   374,   375,    60,    61,    62,
      63,    37,    37,   382,   383,    44,   385,   133,   134,   135,
     136,    44,    49,     4,    37,    49,     4,   396,   397,    49,
      49,    49,    44,    49,   403,    49,   405,   406,   407,    44,
      44,    48,    36,   412,    36,     4,    49,     4,    49,    49,
      43,    47,    47,   422,   423,   424,   425,    47,    29,   428,
     429,    37,   431,    21,   433,   434,    48,    44,    43,    36,
     439,   440,    44,    36,   443,    27,    44,    28,    48,    48,
      40,   450,    47,    47,    40,   454,    24,    48,    36,    44,
      44,    44,    36,   462,    25,   169,   173,    43,    48,    48,
      47,    44,   177,    48,   171,   474,    47,   476,    47,   478,
     166,    48,    48,   482,   483,     3,     4,     5,    48,     7,
     237,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,   175,    22,    23,   310,   360,    26,   413,
     466,   487,    30,    31,    32,   409,   395,    35,   445,   420,
     326,    26,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    -1,     3,     4,     5,    64,     7,    -1,     9,
      10,    -1,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    22,    23,    -1,    -1,    26,    -1,    -1,    -1,
      30,    31,    32,    -1,    -1,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,
      -1,    -1,    -1,    -1,    64
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     7,     9,    10,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    22,    23,    26,    30,
      31,    32,    35,    43,    58,    59,    64,    66,    67,    71,
      78,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   107,   109,   112,   116,   117,
     120,   126,   127,   128,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   145,   148,
     150,    38,    43,    49,     4,    36,     4,    77,    84,    85,
      86,     5,     4,    72,    79,     4,    74,    81,     4,    75,
      82,     4,    76,    83,     4,    73,    80,     4,    43,    97,
     109,   130,   141,    43,    43,    47,    43,    36,    43,     4,
     131,   134,   137,     4,   141,   141,   140,   141,     0,    11,
     151,    36,    36,   151,    36,    58,    59,    60,    61,    62,
      63,    58,    59,    60,    61,    62,    63,    36,    52,    53,
      54,    55,    56,    57,    50,    51,    12,    71,    78,   150,
       4,     4,   109,   147,   151,     8,     9,    21,    33,    34,
      97,   109,   131,   134,   149,    49,    37,    49,    47,    37,
      49,    37,    49,    37,    49,    37,    49,    37,    49,    36,
      36,    36,   151,   151,   151,   151,     9,    44,    44,    44,
     151,    66,    66,    43,   132,   132,   133,   133,   133,   133,
       4,    43,   135,   135,   136,   136,   136,   136,    43,   138,
     138,   138,   138,   138,   138,   139,   139,     5,     4,    43,
      36,   146,     4,    15,    16,    17,    18,    19,    97,   105,
     110,   150,    37,    37,     5,    37,    37,    37,    37,    37,
      21,     4,    77,     4,    21,    97,   109,    69,     4,    72,
     131,     4,    74,     8,     4,    75,   134,     4,    76,   149,
       4,    73,     9,    97,   109,   113,   130,   137,   149,     8,
     130,   107,   148,     4,    96,   108,   118,   148,   150,    37,
     129,    47,    43,   102,   151,    37,   111,   111,   151,     4,
       4,    81,     4,    80,    37,     4,    84,     4,    85,     4,
      88,     4,    82,     4,    83,     5,     5,    37,    37,   151,
      37,    37,    37,    37,    37,   151,   151,   151,   151,    36,
      15,    16,    17,    18,    19,     4,     4,    44,    68,   101,
     151,   151,    44,     4,    86,    49,    49,    49,   144,    37,
      84,    85,    67,    70,   107,     4,    79,    81,    82,    83,
      80,    44,    44,    44,    48,   151,    49,   129,    36,   151,
     151,   103,   105,    97,   105,    36,    49,     4,    43,    86,
     151,   151,   151,    47,    47,    47,    29,   119,   137,     4,
      97,   130,    70,   103,   151,    37,   104,   111,   111,    44,
      70,    48,    70,   151,   151,   151,    43,    36,   151,   151,
      44,   151,    36,   107,    27,   122,   124,   122,   151,   151,
      48,    44,    47,   105,   151,     3,     8,   125,   151,   151,
     151,     4,    97,   137,   118,    47,   151,   104,    48,    40,
      28,   121,   123,   124,   121,   151,   151,   151,   151,   106,
     107,   151,   151,    40,   151,   151,   151,    44,    44,    44,
     106,   151,   151,    24,   114,   107,   151,    48,   123,    48,
      36,    36,    47,   151,    48,   106,    43,   151,   107,   151,
      48,   113,    25,   115,   107,    44,    47,   151,    47,   151,
      48,   151,   107,   107,   151,   151,    48,    48,   114
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    66,    66,    68,    67,    69,    67,    70,
      70,    70,    71,    71,    71,    71,    71,    71,    72,    72,
      73,    73,    74,    74,    75,    75,    76,    76,    77,    77,
      78,    78,    78,    78,    78,    78,    78,    78,    79,    79,
      80,    80,    81,    81,    82,    82,    83,    83,    84,    84,
      85,    85,    86,    86,    87,    87,    87,    87,    87,    87,
      87,    87,    88,    88,    89,    89,    90,    90,    91,    91,
      92,    92,    93,    93,    94,    94,    95,    95,    96,    96,
      96,    96,    96,    97,    98,    99,   101,   100,   102,   100,
     103,   103,   104,   104,   105,   106,   106,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   108,   108,   109,   110,   110,   110,
     111,   111,   111,   112,   113,   113,   113,   113,   113,   114,
     114,   115,   115,   116,   116,   117,   118,   118,   118,   119,
     119,   120,   120,   121,   121,   122,   123,   123,   124,   125,
     125,   126,   126,   126,   127,   128,   129,   129,   130,   130,
     131,   131,   131,   132,   132,   132,   132,   132,   133,   133,
     134,   134,   134,   135,   135,   135,   135,   135,   136,   136,
     137,   137,   137,   137,   137,   137,   137,   138,   138,   138,
     139,   139,   139,   140,   140,   140,   141,   141,   142,   142,
     144,   143,   146,   145,   147,   147,   148,   148,   149,   149,
     150,   150,   150,   150,   150,   150,   150,   151,   151
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     3,     0,     9,     0,     8,     0,
       3,     3,     2,     2,     2,     2,     2,     2,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       2,     2,     2,     2,     2,     2,     2,     2,     3,     5,
       3,     5,     3,     5,     3,     5,     3,     5,     3,     5,
       3,     5,     4,     6,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     5,     3,     5,     3,     5,     3,     5,
       3,     5,     3,     5,     3,     5,     4,     6,     1,     2,
       2,     1,     1,     1,     1,     1,     0,    14,     0,    13,
       0,     2,     0,     4,     2,     0,     3,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       1,     1,     2,     1,     4,     4,     7,     0,     2,     2,
       0,     4,     4,    15,     1,     1,     1,     1,     1,     0,
      10,     0,     6,    13,    13,    17,     0,     1,     1,     0,
       1,    13,    13,     0,     4,     3,     0,     3,     5,     1,
       1,     3,     3,     3,     2,     6,     0,     3,     1,     1,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       1,     2,     3,     1,     2,     2,     1,     1,     1,     1,
       0,     9,     0,     5,     2,     1,     1,     1,     1,     1,
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
  case 5: /* $@1: %empty  */
#line 251 "project.y"
                                                      {
    addSymbol((yyvsp[-1].sval), "class", false, true, true, NULL);
    increaseScope();
}
#line 1786 "project.tab.c"
    break;

  case 6: /* class_declaration: access_modifier CLASS CLASS_ID LCB $@1 none_or_newlines class_body none_or_newlines RCB  */
#line 254 "project.y"
                                                   { decreaseScope(); }
#line 1792 "project.tab.c"
    break;

  case 7: /* $@2: %empty  */
#line 255 "project.y"
                         {
    addSymbol((yyvsp[-1].sval), "class", false, true, true, NULL);
    increaseScope();
}
#line 1801 "project.tab.c"
    break;

  case 8: /* class_declaration: CLASS CLASS_ID LCB $@2 none_or_newlines class_body none_or_newlines RCB  */
#line 258 "project.y"
                                                   { decreaseScope(); }
#line 1807 "project.tab.c"
    break;

  case 18: /* identifier_list_int: ID  */
#line 274 "project.y"
                        { addSymbol((yyvsp[0].sval), "int", false, false, false, NULL); }
#line 1813 "project.tab.c"
    break;

  case 19: /* identifier_list_int: ID COMMA identifier_list_int  */
#line 275 "project.y"
                                   { addSymbol((yyvsp[-2].sval), "int", false, false, false, NULL); }
#line 1819 "project.tab.c"
    break;

  case 20: /* identifier_list_string: ID  */
#line 278 "project.y"
                           { addSymbol((yyvsp[0].sval), "string", false, false, false, NULL); }
#line 1825 "project.tab.c"
    break;

  case 21: /* identifier_list_string: ID COMMA identifier_list_string  */
#line 279 "project.y"
                                      { addSymbol((yyvsp[-2].sval), "string", false, false, false, NULL); }
#line 1831 "project.tab.c"
    break;

  case 22: /* identifier_list_char: ID  */
#line 282 "project.y"
                         { addSymbol((yyvsp[0].sval), "char", false, false, false, NULL); }
#line 1837 "project.tab.c"
    break;

  case 23: /* identifier_list_char: ID COMMA identifier_list_char  */
#line 283 "project.y"
                                    { addSymbol((yyvsp[-2].sval), "char", false, false, false, NULL); }
#line 1843 "project.tab.c"
    break;

  case 24: /* identifier_list_double: ID  */
#line 286 "project.y"
                           { addSymbol((yyvsp[0].sval), "double", false, false, false, NULL); }
#line 1849 "project.tab.c"
    break;

  case 25: /* identifier_list_double: ID COMMA identifier_list_double  */
#line 287 "project.y"
                                      { addSymbol((yyvsp[-2].sval), "double", false, false, false, NULL); }
#line 1855 "project.tab.c"
    break;

  case 26: /* identifier_list_boolean: ID  */
#line 290 "project.y"
                            { addSymbol((yyvsp[0].sval), "boolean", false, false, false, NULL); }
#line 1861 "project.tab.c"
    break;

  case 27: /* identifier_list_boolean: ID COMMA identifier_list_boolean  */
#line 291 "project.y"
                                       { addSymbol((yyvsp[-2].sval), "boolean", false, false, false, NULL); }
#line 1867 "project.tab.c"
    break;

  case 28: /* identifier_list_variable: ID  */
#line 294 "project.y"
                             { addSymbol((yyvsp[0].sval), "var", false, false, false, NULL); }
#line 1873 "project.tab.c"
    break;

  case 29: /* identifier_list_variable: ID COMMA identifier_list_variable  */
#line 295 "project.y"
                                        { addSymbol((yyvsp[-2].sval), "var", false, false, false, NULL); }
#line 1879 "project.tab.c"
    break;

  case 38: /* assignment_list_int: ID ASSIGN exp_int  */
#line 309 "project.y"
                                       {
    char valueStr[32];
    sprintf(valueStr, "%d", (yyvsp[0].ival));
    addSymbol((yyvsp[-2].sval), "int", false, true, false, valueStr);
    printf("Variable %s assigned with value %d\n\n", (yyvsp[-2].sval), (yyvsp[0].ival));
}
#line 1890 "project.tab.c"
    break;

  case 39: /* assignment_list_int: ID ASSIGN exp_int COMMA assignment_list_int  */
#line 315 "project.y"
                                                  {
    char valueStr[32]; sprintf(valueStr, "%d", (yyvsp[-2].ival));
    addSymbol((yyvsp[-4].sval), "int", false, true, false, valueStr);
    printf("Variable %s assigned with value %d\n\n", (yyvsp[-4].sval), (yyvsp[-2].ival));
}
#line 1900 "project.tab.c"
    break;

  case 40: /* assignment_list_string: ID ASSIGN DQ_STRING_DQ  */
#line 321 "project.y"
                                               { addSymbol((yyvsp[-2].sval), "string", false, true, false, (yyvsp[0].sval)); }
#line 1906 "project.tab.c"
    break;

  case 41: /* assignment_list_string: ID ASSIGN DQ_STRING_DQ COMMA assignment_list_string  */
#line 322 "project.y"
                                                          { addSymbol((yyvsp[-4].sval), "string", false, true, false, (yyvsp[-2].sval)); }
#line 1912 "project.tab.c"
    break;

  case 42: /* assignment_list_char: ID ASSIGN SQ_ANYCHAR_SQ  */
#line 325 "project.y"
                                              { addSymbol((yyvsp[-2].sval), "char", false, true, false, (yyvsp[0].cval)); }
#line 1918 "project.tab.c"
    break;

  case 43: /* assignment_list_char: ID ASSIGN SQ_ANYCHAR_SQ COMMA assignment_list_char  */
#line 326 "project.y"
                                                         { addSymbol((yyvsp[-4].sval), "char", false, true, false, (yyvsp[-2].cval)); }
#line 1924 "project.tab.c"
    break;

  case 44: /* assignment_list_double: ID ASSIGN exp_double  */
#line 329 "project.y"
                                             {
    char valueStr[64];
    sprintf(valueStr, "%f", (yyvsp[0].dval));
    addSymbol((yyvsp[-2].sval), "double", false, true, false, valueStr);
    printf("Variable %s assigned with value %f\n\n", (yyvsp[-2].sval), (yyvsp[0].dval));
}
#line 1935 "project.tab.c"
    break;

  case 45: /* assignment_list_double: ID ASSIGN exp_double COMMA assignment_list_double  */
#line 335 "project.y"
                                                        {
    char valueStr[64];
    sprintf(valueStr, "%f", (yyvsp[-2].dval));
    addSymbol((yyvsp[-4].sval), "double", false, true, false, valueStr);
    printf("Variable %s assigned with value %f\n\n", (yyvsp[-4].sval), (yyvsp[-2].dval));
}
#line 1946 "project.tab.c"
    break;

  case 46: /* assignment_list_boolean: ID ASSIGN boolean  */
#line 342 "project.y"
                                           { addSymbol((yyvsp[-2].sval), "boolean", false, true, false, (yyvsp[0].sval)); }
#line 1952 "project.tab.c"
    break;

  case 47: /* assignment_list_boolean: ID ASSIGN boolean COMMA assignment_list_boolean  */
#line 343 "project.y"
                                                      { addSymbol((yyvsp[-4].sval), "boolean", false, true, false, (yyvsp[-2].sval)); }
#line 1958 "project.tab.c"
    break;

  case 48: /* assignment_list_variable: ID ASSIGN variable_reference  */
#line 346 "project.y"
                                                       {
    char* type = getType((yyvsp[0].sval));
    char* value = getValue((yyvsp[0].sval));
    addSymbol((yyvsp[-2].sval), type, false, true, false, value);
}
#line 1968 "project.tab.c"
    break;

  case 49: /* assignment_list_variable: ID ASSIGN variable_reference COMMA assignment_list_variable  */
#line 351 "project.y"
                                                                  {
    char* type = getType((yyvsp[-2].sval));
    char* value = getValue((yyvsp[-2].sval));
    addSymbol((yyvsp[-4].sval), type, false, true, false, value);
}
#line 1978 "project.tab.c"
    break;

  case 50: /* assignment_list_method: ID ASSIGN method_call  */
#line 357 "project.y"
                                              {
    char* type = getType((yyvsp[0].sval));
    addSymbol((yyvsp[-2].sval), type, false, true, false, NULL);
}
#line 1987 "project.tab.c"
    break;

  case 51: /* assignment_list_method: ID ASSIGN method_call COMMA assignment_list_method  */
#line 361 "project.y"
                                                         {
    char* type = getType((yyvsp[-2].sval));
    addSymbol((yyvsp[-4].sval), type, false, true, false, NULL);
}
#line 1996 "project.tab.c"
    break;

  case 52: /* assignment_list_object: ID ASSIGN NEW CLASS_ID  */
#line 366 "project.y"
                                               { addSymbol((yyvsp[-3].sval), "class", false, true, false, NULL); }
#line 2002 "project.tab.c"
    break;

  case 53: /* assignment_list_object: ID ASSIGN NEW CLASS_ID COMMA assignment_list_object  */
#line 367 "project.y"
                                                          { addSymbol((yyvsp[-5].sval), "class", false, true, false, NULL); }
#line 2008 "project.tab.c"
    break;

  case 62: /* assignment_list_int_declared: ID ASSIGN exp_int  */
#line 380 "project.y"
                                                {
    char* type = getType((yyvsp[-2].sval));
    if (type == NULL || strcmp(type, "int") != 0) {
        yyerror("Type mismatch");
        exit(1);
    } else {
        char valueStr[32];
        sprintf(valueStr, "%d", (yyvsp[0].ival));
        setInitialized((yyvsp[-2].sval), valueStr);
        printf("Variable %s assigned with value %d\n\n", (yyvsp[-2].sval), (yyvsp[0].ival));
    }
}
#line 2025 "project.tab.c"
    break;

  case 63: /* assignment_list_int_declared: ID ASSIGN exp_int COMMA assignment_list_int_declared  */
#line 392 "project.y"
                                                           {
    char* type = getType((yyvsp[-4].sval));
    if (type == NULL || strcmp(type, "int") != 0) {
        yyerror("Type mismatch");
        exit(1);
    } else {
        char valueStr[32];
        sprintf(valueStr, "%d", valueStr);
        setInitialized((yyvsp[-4].sval), valueStr);
        printf("Variable %s assigned with value %d\n\n", (yyvsp[-4].sval), (yyvsp[-2].ival));
    }
}
#line 2042 "project.tab.c"
    break;

  case 64: /* assignment_list_string_declared: ID ASSIGN DQ_STRING_DQ  */
#line 405 "project.y"
                                                        {
    char* type = getType((yyvsp[-2].sval));
    if (type == NULL || strcmp(type, "string") != 0) {
        yyerror("Type mismatch");
        exit(1);
    } else {
        setInitialized((yyvsp[-2].sval), (yyvsp[0].sval));
    }
}
#line 2056 "project.tab.c"
    break;

  case 65: /* assignment_list_string_declared: ID ASSIGN DQ_STRING_DQ COMMA assignment_list_string  */
#line 414 "project.y"
                                                          {
    char* type = getType((yyvsp[-4].sval));
    if (type == NULL || strcmp(type, "string") != 0) {
        yyerror("Type mismatch");
        exit(1);
    } else {
        setInitialized((yyvsp[-4].sval), (yyvsp[-2].sval));
    }
}
#line 2070 "project.tab.c"
    break;

  case 66: /* assignment_list_char_declared: ID ASSIGN SQ_ANYCHAR_SQ  */
#line 424 "project.y"
                                                       {
    char* type = getType((yyvsp[-2].sval));
    if (type == NULL || strcmp(type, "char") != 0) {
        yyerror("Type mismatch");
        exit(1);
    } else {
        setInitialized((yyvsp[-2].sval), (yyvsp[0].cval));
    }
}
#line 2084 "project.tab.c"
    break;

  case 67: /* assignment_list_char_declared: ID ASSIGN SQ_ANYCHAR_SQ COMMA assignment_list_char  */
#line 433 "project.y"
                                                         {
    char* type = getType((yyvsp[-4].sval));
    if (type == NULL || strcmp(type, "char") != 0) {
        yyerror("Type mismatch");
        exit(1);
    } else {
        setInitialized((yyvsp[-4].sval), (yyvsp[-2].cval));
    }
}
#line 2098 "project.tab.c"
    break;

  case 68: /* assignment_list_double_declared: ID ASSIGN exp_double  */
#line 443 "project.y"
                                                      {
    char* type = getType((yyvsp[-2].sval));
    if (type == NULL || strcmp(type, "double") != 0) {
        yyerror("Type mismatch");
        exit(1);
    } else {
        char valueStr[64];
        sprintf(valueStr, "%f", (yyvsp[0].dval));
        setInitialized((yyvsp[-2].sval), valueStr);
        printf("Variable %s assigned with value %f\n\n", (yyvsp[-2].sval), (yyvsp[0].dval));
    }
}
#line 2115 "project.tab.c"
    break;

  case 69: /* assignment_list_double_declared: ID ASSIGN exp_double COMMA assignment_list_double  */
#line 455 "project.y"
                                                        {
    char* type = getType((yyvsp[-4].sval));
    if (type == NULL || strcmp(type, "double") != 0) {
        yyerror("Type mismatch");
        exit(1);
    } else {
        char valueStr[64];
        sprintf(valueStr, "%f", (yyvsp[-2].dval));
        setInitialized((yyvsp[-4].sval), valueStr);
        printf("Variable %s assigned with value %f\n\n", (yyvsp[-4].sval), (yyvsp[-2].dval));
    }
}
#line 2132 "project.tab.c"
    break;

  case 70: /* assignment_list_boolean_declared: ID ASSIGN boolean  */
#line 468 "project.y"
                                                    {
    char* type = getType((yyvsp[-2].sval));
    if (type == NULL || strcmp(type, "boolean") != 0) {
        yyerror("Type mismatch");
        exit(1);
    } else {
        setInitialized((yyvsp[-2].sval), (yyvsp[0].sval));
    }
}
#line 2146 "project.tab.c"
    break;

  case 71: /* assignment_list_boolean_declared: ID ASSIGN boolean COMMA assignment_list_boolean  */
#line 477 "project.y"
                                                      {
    char* type = getType((yyvsp[-4].sval));
    if (type == NULL || strcmp(type, "boolean") != 0) {
        yyerror("Type mismatch");
        exit(1);
    } else {
        setInitialized((yyvsp[-4].sval), (yyvsp[-2].sval));
    }
}
#line 2160 "project.tab.c"
    break;

  case 72: /* assignment_list_variable_declared: ID ASSIGN variable_reference  */
#line 487 "project.y"
                                                                {
    char* type = getType((yyvsp[-2].sval));
    char* value = getValue((yyvsp[0].sval));
    if (type == NULL || strcmp(type, getType((yyvsp[0].sval))) != 0) {
        yyerror("Type mismatch");
        exit(1);
    } else {
        setInitialized((yyvsp[-2].sval), value);
    }
}
#line 2175 "project.tab.c"
    break;

  case 73: /* assignment_list_variable_declared: ID ASSIGN variable_reference COMMA assignment_list_variable  */
#line 497 "project.y"
                                                                  {
    char* type = getType((yyvsp[-4].sval));
    char* value = getValue((yyvsp[-2].sval));
    if (type == NULL || strcmp(type, getType((yyvsp[-2].sval))) != 0) {
        yyerror("Type mismatch");
        exit(1);
    } else {
        setInitialized((yyvsp[-4].sval), value);
    }
}
#line 2190 "project.tab.c"
    break;

  case 74: /* assignment_list_method_declared: ID ASSIGN method_call  */
#line 508 "project.y"
                                                       {
    char* type = getType((yyvsp[-2].sval));
    if (type == NULL || strcmp(type, getType((yyvsp[0].sval))) != 0) {
        yyerror("Type mismatch");
        exit(1);
    } else {
        setInitialized((yyvsp[-2].sval), NULL);
    }
}
#line 2204 "project.tab.c"
    break;

  case 75: /* assignment_list_method_declared: ID ASSIGN method_call COMMA assignment_list_method  */
#line 517 "project.y"
                                                         {
    char* type = getType((yyvsp[-4].sval));
    if (type == NULL || strcmp(type, getType((yyvsp[-2].sval))) != 0) {
        yyerror("Type mismatch");
        exit(1);
    } else {
        setInitialized((yyvsp[-4].sval), NULL);
    }
}
#line 2218 "project.tab.c"
    break;

  case 76: /* assignment_list_object_declared: ID ASSIGN NEW CLASS_ID  */
#line 527 "project.y"
                                                        {
    char* type = getType((yyvsp[-3].sval));
    if (type == NULL || strcmp(type, (yyvsp[0].sval)) != 0) {
        yyerror("Type mismatch");
        exit(1);
    } else {
        setInitialized((yyvsp[-3].sval), NULL);
    }
}
#line 2232 "project.tab.c"
    break;

  case 77: /* assignment_list_object_declared: ID ASSIGN NEW CLASS_ID COMMA assignment_list_object  */
#line 536 "project.y"
                                                          {
    char* type = getType((yyvsp[-5].sval));
    if (type == NULL || strcmp(type, (yyvsp[-2].sval)) != 0) {
        yyerror("Type mismatch");
        exit(1);
    } else {
        setInitialized((yyvsp[-5].sval), NULL);
    }
}
#line 2246 "project.tab.c"
    break;

  case 83: /* variable_reference: ID  */
#line 555 "project.y"
                       {
    if (!symbolExists((yyvsp[0].sval), false, false)) {
        yyerror("Variable not declared");
    } else if (!isInitialized((yyvsp[0].sval))) {
        yyerror("Variable not initialized");
    } else {
        (yyval.sval) = getValue((yyvsp[0].sval));
    }
}
#line 2260 "project.tab.c"
    break;

  case 84: /* variable_reference_int: ID  */
#line 565 "project.y"
                           {
    if (!symbolExists((yyvsp[0].sval), false, false)) {
        yyerror("Variable not declared");
    } else if (!isInitialized((yyvsp[0].sval))) {
        yyerror("Variable not initialized");
    } else {
        (yyval.ival) = atoi(getValue((yyvsp[0].sval)));
    }
}
#line 2274 "project.tab.c"
    break;

  case 85: /* variable_reference_double: ID  */
#line 575 "project.y"
                              {
    if (!symbolExists((yyvsp[0].sval), false, false)) {
        yyerror("Variable not declared");
    } else if (!isInitialized((yyvsp[0].sval))) {
        yyerror("Variable not initialized");
    } else {
        (yyval.dval) = atof(getValue((yyvsp[0].sval)));
    }
}
#line 2288 "project.tab.c"
    break;

  case 86: /* $@3: %empty  */
#line 586 "project.y"
                                                    { increaseScope(); }
#line 2294 "project.tab.c"
    break;

  case 87: /* method_declaration: access_modifier data_type ID LP $@3 none_or_newlines none_or_multiple_parameters none_or_newlines RP LCB none_or_newlines method_body none_or_newlines RCB  */
#line 586 "project.y"
                                                                                                                                                                                                {
    addSymbol("sum", (yyvsp[-12].sval), true, true, false, NULL);
    decreaseScope();
}
#line 2303 "project.tab.c"
    break;

  case 88: /* $@4: %empty  */
#line 590 "project.y"
                      { increaseScope(); }
#line 2309 "project.tab.c"
    break;

  case 89: /* method_declaration: data_type ID LP $@4 none_or_newlines none_or_multiple_parameters none_or_newlines RP LCB none_or_newlines method_body none_or_newlines RCB  */
#line 590 "project.y"
                                                                                                                                                                  {
    addSymbol((yyvsp[-11].sval), (yyvsp[-12].sval), true, true, false, NULL);
    decreaseScope();
}
#line 2318 "project.tab.c"
    break;

  case 94: /* parameter: data_type ID  */
#line 603 "project.y"
                        { addSymbol((yyvsp[0].sval), (yyvsp[-1].sval), false, true, false, NULL); }
#line 2324 "project.tab.c"
    break;

  case 116: /* method_call: ID LP none_or_newlines none_or_multiple_arguments none_or_newlines RP SEMICOLON  */
#line 634 "project.y"
                                                                                             {
    if (!symbolExists((yyvsp[-6].sval), true, false)) {
        yyerror("Method not declared");
    }
}
#line 2334 "project.tab.c"
    break;

  case 157: /* single_or_multiple_variables: COMMA ID single_or_multiple_variables  */
#line 718 "project.y"
                                            {
    if (!symbolExists((yyvsp[-1].sval), false, false)) {
        yyerror("Variable not declared");
    } else if (!isInitialized((yyvsp[-1].sval))) {
        yyerror("Variable not initialized");
    }
}
#line 2346 "project.tab.c"
    break;

  case 160: /* exp_int: term_int  */
#line 731 "project.y"
                  { (yyval.ival) = (yyvsp[0].ival); }
#line 2352 "project.tab.c"
    break;

  case 161: /* exp_int: exp_int ADD term_int  */
#line 732 "project.y"
                           { (yyval.ival) = (yyvsp[-2].ival) + (yyvsp[0].ival); }
#line 2358 "project.tab.c"
    break;

  case 162: /* exp_int: exp_int SUB term_int  */
#line 733 "project.y"
                           { (yyval.ival) = (yyvsp[-2].ival) - (yyvsp[0].ival); }
#line 2364 "project.tab.c"
    break;

  case 163: /* term_int: factor_int  */
#line 736 "project.y"
                     { (yyval.ival) = (yyvsp[0].ival);}
#line 2370 "project.tab.c"
    break;

  case 164: /* term_int: term_int MUL factor_int  */
#line 737 "project.y"
                              { (yyval.ival) = (yyvsp[-2].ival) * (yyvsp[0].ival); }
#line 2376 "project.tab.c"
    break;

  case 165: /* term_int: term_int DIV factor_int  */
#line 738 "project.y"
                              {
    if ((yyvsp[0].ival) == 0) {
        yyerror("Division by zero");
        YYABORT;
    } else {
        (yyval.ival) = (yyvsp[-2].ival) / (yyvsp[0].ival);
    }
}
#line 2389 "project.tab.c"
    break;

  case 166: /* term_int: term_int MOD factor_int  */
#line 746 "project.y"
                              {
    if ((yyvsp[0].ival) == 0) {
        yyerror("Division by zero");
        YYABORT;
    } else {
        (yyval.ival) = fmod((yyvsp[-2].ival), (yyvsp[0].ival));
    }
}
#line 2402 "project.tab.c"
    break;

  case 167: /* term_int: term_int POW factor_int  */
#line 754 "project.y"
                              {
    if ((yyvsp[0].ival) == 0) {
        yyerror("Exponentiation by zero");
        YYABORT;
    } else {
        (yyval.ival) = pow((yyvsp[-2].ival), (yyvsp[0].ival));
    }
}
#line 2415 "project.tab.c"
    break;

  case 168: /* factor_int: primary_int  */
#line 763 "project.y"
                        { (yyval.ival) = (yyvsp[0].ival); }
#line 2421 "project.tab.c"
    break;

  case 169: /* factor_int: LP exp_int RP  */
#line 764 "project.y"
                    { (yyval.ival) = (yyvsp[-1].ival); }
#line 2427 "project.tab.c"
    break;

  case 170: /* exp_double: term_double  */
#line 768 "project.y"
                        { (yyval.dval) = (yyvsp[0].dval); }
#line 2433 "project.tab.c"
    break;

  case 171: /* exp_double: exp_double ADD term_double  */
#line 769 "project.y"
                                 { (yyval.dval) = (yyvsp[-2].dval) + (yyvsp[0].dval); }
#line 2439 "project.tab.c"
    break;

  case 172: /* exp_double: exp_double SUB term_double  */
#line 770 "project.y"
                                 { (yyval.dval) = (yyvsp[-2].dval) - (yyvsp[0].dval); }
#line 2445 "project.tab.c"
    break;

  case 173: /* term_double: factor_double  */
#line 773 "project.y"
                           { (yyval.dval) = (yyvsp[0].dval); }
#line 2451 "project.tab.c"
    break;

  case 174: /* term_double: term_double MUL factor_double  */
#line 774 "project.y"
                                    { (yyval.dval) = (yyvsp[-2].dval) * (yyvsp[0].dval); }
#line 2457 "project.tab.c"
    break;

  case 175: /* term_double: term_double DIV factor_double  */
#line 775 "project.y"
                                    {
    if ((yyvsp[0].dval) == 0) {
        yyerror("Division by zero");
        YYABORT;
    } else {
        (yyval.dval) = (yyvsp[-2].dval) / (yyvsp[0].dval);
    }
}
#line 2470 "project.tab.c"
    break;

  case 176: /* term_double: term_double MOD factor_double  */
#line 783 "project.y"
                                    {
    if ((yyvsp[0].dval) == 0) {
        yyerror("Division by zero");
        YYABORT;
    } else {
        (yyval.dval) = fmod((yyvsp[-2].dval), (yyvsp[0].dval));
    }
}
#line 2483 "project.tab.c"
    break;

  case 177: /* term_double: term_double POW factor_double  */
#line 791 "project.y"
                                    {
    if ((yyvsp[0].dval) == 0) {
        yyerror("Exponentiation by zero");
        YYABORT;
    } else {
        (yyval.dval) = pow((yyvsp[-2].dval), (yyvsp[0].dval));
    }
}
#line 2496 "project.tab.c"
    break;

  case 178: /* factor_double: primary_double  */
#line 800 "project.y"
                              { (yyval.dval) = (yyvsp[0].dval); }
#line 2502 "project.tab.c"
    break;

  case 179: /* factor_double: LP exp_double RP  */
#line 801 "project.y"
                       { (yyval.dval) = (yyvsp[-1].dval); }
#line 2508 "project.tab.c"
    break;

  case 193: /* unary: primary_int  */
#line 823 "project.y"
                   { (yyval.ival) = (yyvsp[0].ival); }
#line 2514 "project.tab.c"
    break;

  case 194: /* unary: ADD primary_int  */
#line 824 "project.y"
                      { (yyval.ival) = (yyvsp[0].ival); }
#line 2520 "project.tab.c"
    break;

  case 195: /* unary: SUB primary_int  */
#line 825 "project.y"
                      { (yyval.ival) = -(yyvsp[0].ival); }
#line 2526 "project.tab.c"
    break;

  case 196: /* primary_int: CONST  */
#line 828 "project.y"
                   { (yyval.ival) = (yyvsp[0].ival); }
#line 2532 "project.tab.c"
    break;

  case 197: /* primary_int: variable_reference_int  */
#line 829 "project.y"
                             { (yyval.ival) = (yyvsp[0].ival); }
#line 2538 "project.tab.c"
    break;

  case 198: /* primary_double: DOUBLE_CONST  */
#line 832 "project.y"
                             { (yyval.dval) = (yyvsp[0].dval); }
#line 2544 "project.tab.c"
    break;

  case 199: /* primary_double: variable_reference_double  */
#line 833 "project.y"
                                { (yyval.dval) = (yyvsp[0].dval); }
#line 2550 "project.tab.c"
    break;

  case 200: /* $@5: %empty  */
#line 836 "project.y"
                                                 {
    if (!symbolExists((yyvsp[-4].sval), false, true)) {
        yyerror("Class not declared");
    } else {
        addSymbol((yyvsp[-3].sval), (yyvsp[-4].sval), false, true, false, (yyvsp[0].sval));
    }
}
#line 2562 "project.tab.c"
    break;

  case 202: /* $@6: %empty  */
#line 845 "project.y"
                                         {
    if (!symbolExists((yyvsp[-2].sval), false, true)) {
        yyerror("Class not declared");
    } else if (!symbolExists((yyvsp[0].sval), false, false)) {
        yyerror("Member not declared");
    }
}
#line 2574 "project.tab.c"
    break;

  case 204: /* member_access_body: ID SEMICOLON  */
#line 854 "project.y"
                                 {
    if (!symbolExists((yyvsp[-1].sval), false, false)) {
        yyerror("Variable not declared");
    }
}
#line 2584 "project.tab.c"
    break;

  case 205: /* member_access_body: method_call  */
#line 859 "project.y"
                  {
    if (!symbolExists((yyvsp[0].sval), true, false)) {
        yyerror("Method not declared");
    }
}
#line 2594 "project.tab.c"
    break;

  case 208: /* boolean: TRUE  */
#line 869 "project.y"
              { (yyval.sval) = "true"; }
#line 2600 "project.tab.c"
    break;

  case 209: /* boolean: FALSE  */
#line 870 "project.y"
            { (yyval.sval) = "false"; }
#line 2606 "project.tab.c"
    break;

  case 210: /* data_type: %empty  */
#line 873 "project.y"
                         { (yyval.sval) = ""; }
#line 2612 "project.tab.c"
    break;

  case 211: /* data_type: INTEGER  */
#line 874 "project.y"
              { (yyval.sval) = "int"; }
#line 2618 "project.tab.c"
    break;

  case 212: /* data_type: CHAR  */
#line 875 "project.y"
           { (yyval.sval) = "char"; }
#line 2624 "project.tab.c"
    break;

  case 213: /* data_type: DOUBLE  */
#line 876 "project.y"
             { (yyval.sval) = "double"; }
#line 2630 "project.tab.c"
    break;

  case 214: /* data_type: BOOLEAN  */
#line 877 "project.y"
              { (yyval.sval) = "boolean"; }
#line 2636 "project.tab.c"
    break;

  case 215: /* data_type: STRING  */
#line 878 "project.y"
             { (yyval.sval) = "string"; }
#line 2642 "project.tab.c"
    break;

  case 216: /* data_type: VOID  */
#line 879 "project.y"
           { (yyval.sval) = "void"; }
#line 2648 "project.tab.c"
    break;


#line 2652 "project.tab.c"

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

#line 886 "project.y"


void yyerror(const char *s) {
    fprintf(stderr, "Error on line %d: %s recognised at the token '%s'\n", yylineno, s, yytext);
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

    printf("\n\nSymbol table:\n");
    for (int i = 0; i < symbolCount; i++) {
        printf("Name: %s, Type: %s, isMethod: %d, isInitialized: %d, Scope: %d, isClass: %d, Value: %s\n",
               symbolTable[i].name, symbolTable[i].type, symbolTable[i].isMethod,
               symbolTable[i].isInitialized, symbolTable[i].scope, symbolTable[i].isClass, symbolTable[i].value);
    }

    fclose(f);

    return 0;
}
