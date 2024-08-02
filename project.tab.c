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
  YYSYMBOL_DOUBLE_CONST = 6,               /* DOUBLE_CONST  */
  YYSYMBOL_SQ_ANYCHAR_SQ = 7,              /* SQ_ANYCHAR_SQ  */
  YYSYMBOL_DQ_STRING_DQ = 8,               /* DQ_STRING_DQ  */
  YYSYMBOL_VAR = 9,                        /* VAR  */
  YYSYMBOL_NEWLINE = 10,                   /* NEWLINE  */
  YYSYMBOL_CLASS = 11,                     /* CLASS  */
  YYSYMBOL_PUBLIC = 12,                    /* PUBLIC  */
  YYSYMBOL_PRIVATE = 13,                   /* PRIVATE  */
  YYSYMBOL_INTEGER = 14,                   /* INTEGER  */
  YYSYMBOL_CHAR = 15,                      /* CHAR  */
  YYSYMBOL_DOUBLE = 16,                    /* DOUBLE  */
  YYSYMBOL_BOOLEAN = 17,                   /* BOOLEAN  */
  YYSYMBOL_STRING = 18,                    /* STRING  */
  YYSYMBOL_VOID = 19,                      /* VOID  */
  YYSYMBOL_NEW = 20,                       /* NEW  */
  YYSYMBOL_RETURN = 21,                    /* RETURN  */
  YYSYMBOL_IF = 22,                        /* IF  */
  YYSYMBOL_ELIF = 23,                      /* ELIF  */
  YYSYMBOL_ELSE = 24,                      /* ELSE  */
  YYSYMBOL_SWITCH = 25,                    /* SWITCH  */
  YYSYMBOL_CASE = 26,                      /* CASE  */
  YYSYMBOL_DEFAULT = 27,                   /* DEFAULT  */
  YYSYMBOL_WHILE = 28,                     /* WHILE  */
  YYSYMBOL_DO = 29,                        /* DO  */
  YYSYMBOL_FOR = 30,                       /* FOR  */
  YYSYMBOL_BREAK = 31,                     /* BREAK  */
  YYSYMBOL_TRUE = 32,                      /* TRUE  */
  YYSYMBOL_FALSE = 33,                     /* FALSE  */
  YYSYMBOL_PRINT = 34,                     /* PRINT  */
  YYSYMBOL_SEMICOLON = 35,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 36,                     /* COMMA  */
  YYSYMBOL_DOT = 37,                       /* DOT  */
  YYSYMBOL_COLON = 38,                     /* COLON  */
  YYSYMBOL_LP = 39,                        /* LP  */
  YYSYMBOL_RP = 40,                        /* RP  */
  YYSYMBOL_LSB = 41,                       /* LSB  */
  YYSYMBOL_RSB = 42,                       /* RSB  */
  YYSYMBOL_LCB = 43,                       /* LCB  */
  YYSYMBOL_RCB = 44,                       /* RCB  */
  YYSYMBOL_ASSIGN = 45,                    /* ASSIGN  */
  YYSYMBOL_OR = 46,                        /* OR  */
  YYSYMBOL_AND = 47,                       /* AND  */
  YYSYMBOL_EQ = 48,                        /* EQ  */
  YYSYMBOL_NEQ = 49,                       /* NEQ  */
  YYSYMBOL_LT = 50,                        /* LT  */
  YYSYMBOL_LE = 51,                        /* LE  */
  YYSYMBOL_GT = 52,                        /* GT  */
  YYSYMBOL_GE = 53,                        /* GE  */
  YYSYMBOL_ADD = 54,                       /* ADD  */
  YYSYMBOL_SUB = 55,                       /* SUB  */
  YYSYMBOL_MUL = 56,                       /* MUL  */
  YYSYMBOL_DIV = 57,                       /* DIV  */
  YYSYMBOL_MOD = 58,                       /* MOD  */
  YYSYMBOL_POW = 59,                       /* POW  */
  YYSYMBOL_NOT = 60,                       /* NOT  */
  YYSYMBOL_YYACCEPT = 61,                  /* $accept  */
  YYSYMBOL_program = 62,                   /* program  */
  YYSYMBOL_class_declaration = 63,         /* class_declaration  */
  YYSYMBOL_64_1 = 64,                      /* $@1  */
  YYSYMBOL_65_2 = 65,                      /* $@2  */
  YYSYMBOL_class_body = 66,                /* class_body  */
  YYSYMBOL_identifier_list = 67,           /* identifier_list  */
  YYSYMBOL_identifier_list_int = 68,       /* identifier_list_int  */
  YYSYMBOL_identifier_list_string = 69,    /* identifier_list_string  */
  YYSYMBOL_identifier_list_char = 70,      /* identifier_list_char  */
  YYSYMBOL_identifier_list_double = 71,    /* identifier_list_double  */
  YYSYMBOL_identifier_list_boolean = 72,   /* identifier_list_boolean  */
  YYSYMBOL_identifier_list_variable = 73,  /* identifier_list_variable  */
  YYSYMBOL_assignment_list = 74,           /* assignment_list  */
  YYSYMBOL_assignment_list_int = 75,       /* assignment_list_int  */
  YYSYMBOL_assignment_list_string = 76,    /* assignment_list_string  */
  YYSYMBOL_assignment_list_char = 77,      /* assignment_list_char  */
  YYSYMBOL_assignment_list_double = 78,    /* assignment_list_double  */
  YYSYMBOL_assignment_list_boolean = 79,   /* assignment_list_boolean  */
  YYSYMBOL_assignment_list_variable = 80,  /* assignment_list_variable  */
  YYSYMBOL_assignment_list_method = 81,    /* assignment_list_method  */
  YYSYMBOL_assignment_list_object = 82,    /* assignment_list_object  */
  YYSYMBOL_assignment_list_declared = 83,  /* assignment_list_declared  */
  YYSYMBOL_assignment_list_int_declared = 84, /* assignment_list_int_declared  */
  YYSYMBOL_assignment_list_string_declared = 85, /* assignment_list_string_declared  */
  YYSYMBOL_assignment_list_char_declared = 86, /* assignment_list_char_declared  */
  YYSYMBOL_assignment_list_double_declared = 87, /* assignment_list_double_declared  */
  YYSYMBOL_assignment_list_boolean_declared = 88, /* assignment_list_boolean_declared  */
  YYSYMBOL_assignment_list_variable_declared = 89, /* assignment_list_variable_declared  */
  YYSYMBOL_assignment_list_method_declared = 90, /* assignment_list_method_declared  */
  YYSYMBOL_assignment_list_object_declared = 91, /* assignment_list_object_declared  */
  YYSYMBOL_variable_declaration = 92,      /* variable_declaration  */
  YYSYMBOL_variable_reference = 93,        /* variable_reference  */
  YYSYMBOL_variable_reference_int = 94,    /* variable_reference_int  */
  YYSYMBOL_variable_reference_double = 95, /* variable_reference_double  */
  YYSYMBOL_method_declaration = 96,        /* method_declaration  */
  YYSYMBOL_97_3 = 97,                      /* $@3  */
  YYSYMBOL_98_4 = 98,                      /* $@4  */
  YYSYMBOL_none_or_multiple_parameters = 99, /* none_or_multiple_parameters  */
  YYSYMBOL_parameters = 100,               /* parameters  */
  YYSYMBOL_parameter = 101,                /* parameter  */
  YYSYMBOL_method_body = 102,              /* method_body  */
  YYSYMBOL_statement = 103,                /* statement  */
  YYSYMBOL_assignment_statement = 104,     /* assignment_statement  */
  YYSYMBOL_method_call = 105,              /* method_call  */
  YYSYMBOL_none_or_multiple_arguments = 106, /* none_or_multiple_arguments  */
  YYSYMBOL_arguments = 107,                /* arguments  */
  YYSYMBOL_if_statement = 108,             /* if_statement  */
  YYSYMBOL_if_elif_parenthesis_statement = 109, /* if_elif_parenthesis_statement  */
  YYSYMBOL_none_or_multiple_elif = 110,    /* none_or_multiple_elif  */
  YYSYMBOL_none_or_one_else = 111,         /* none_or_one_else  */
  YYSYMBOL_do_while_statement = 112,       /* do_while_statement  */
  YYSYMBOL_for_statement = 113,            /* for_statement  */
  YYSYMBOL_first_and_third_loop_statement = 114, /* first_and_third_loop_statement  */
  YYSYMBOL_second_loop_statement = 115,    /* second_loop_statement  */
  YYSYMBOL_switch_statement = 116,         /* switch_statement  */
  YYSYMBOL_default_case = 117,             /* default_case  */
  YYSYMBOL_one_or_more_cases = 118,        /* one_or_more_cases  */
  YYSYMBOL_multiple_cases = 119,           /* multiple_cases  */
  YYSYMBOL_cases = 120,                    /* cases  */
  YYSYMBOL_case_expression = 121,          /* case_expression  */
  YYSYMBOL_return_statement = 122,         /* return_statement  */
  YYSYMBOL_break_statement = 123,          /* break_statement  */
  YYSYMBOL_print_statement = 124,          /* print_statement  */
  YYSYMBOL_single_or_multiple_variables = 125, /* single_or_multiple_variables  */
  YYSYMBOL_exp = 126,                      /* exp  */
  YYSYMBOL_exp_int = 127,                  /* exp_int  */
  YYSYMBOL_term_int = 128,                 /* term_int  */
  YYSYMBOL_factor_int = 129,               /* factor_int  */
  YYSYMBOL_exp_double = 130,               /* exp_double  */
  YYSYMBOL_term_double = 131,              /* term_double  */
  YYSYMBOL_factor_double = 132,            /* factor_double  */
  YYSYMBOL_relational_exp = 133,           /* relational_exp  */
  YYSYMBOL_relational_factor = 134,        /* relational_factor  */
  YYSYMBOL_logical_term = 135,             /* logical_term  */
  YYSYMBOL_unary = 136,                    /* unary  */
  YYSYMBOL_primary_int = 137,              /* primary_int  */
  YYSYMBOL_primary_double = 138,           /* primary_double  */
  YYSYMBOL_object_creation = 139,          /* object_creation  */
  YYSYMBOL_140_5 = 140,                    /* $@5  */
  YYSYMBOL_member_access = 141,            /* member_access  */
  YYSYMBOL_142_6 = 142,                    /* $@6  */
  YYSYMBOL_member_access_body = 143,       /* member_access_body  */
  YYSYMBOL_access_modifier = 144,          /* access_modifier  */
  YYSYMBOL_boolean = 145,                  /* boolean  */
  YYSYMBOL_data_type = 146,                /* data_type  */
  YYSYMBOL_none_or_newlines = 147          /* none_or_newlines  */
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
#define YYLAST   715

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  87
/* YYNRULES -- Number of rules.  */
#define YYNRULES  218
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  489

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   315


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
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   244,   244,   245,   246,   249,   249,   253,   253,   259,
     260,   261,   264,   265,   266,   267,   268,   269,   272,   273,
     276,   277,   280,   281,   284,   285,   288,   289,   292,   293,
     297,   298,   299,   300,   301,   302,   303,   304,   307,   313,
     319,   320,   323,   324,   327,   333,   340,   341,   344,   349,
     355,   359,   364,   365,   368,   369,   370,   371,   372,   373,
     374,   375,   378,   390,   403,   412,   422,   431,   441,   453,
     466,   475,   485,   495,   506,   515,   525,   534,   545,   546,
     547,   548,   549,   553,   563,   577,   592,   592,   596,   596,
     601,   602,   605,   606,   609,   612,   613,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   628,
     629,   630,   631,   632,   635,   636,   640,   646,   647,   648,
     651,   652,   653,   656,   659,   660,   661,   662,   663,   666,
     667,   670,   671,   674,   675,   678,   681,   682,   683,   686,
     687,   690,   691,   694,   695,   698,   701,   702,   705,   708,
     709,   712,   713,   714,   717,   720,   723,   724,   732,   733,
     737,   738,   739,   742,   743,   744,   751,   758,   766,   767,
     771,   772,   773,   776,   777,   778,   785,   792,   800,   801,
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
  "CLASS_ID", "DOUBLE_CONST", "SQ_ANYCHAR_SQ", "DQ_STRING_DQ", "VAR",
  "NEWLINE", "CLASS", "PUBLIC", "PRIVATE", "INTEGER", "CHAR", "DOUBLE",
  "BOOLEAN", "STRING", "VOID", "NEW", "RETURN", "IF", "ELIF", "ELSE",
  "SWITCH", "CASE", "DEFAULT", "WHILE", "DO", "FOR", "BREAK", "TRUE",
  "FALSE", "PRINT", "SEMICOLON", "COMMA", "DOT", "COLON", "LP", "RP",
  "LSB", "RSB", "LCB", "RCB", "ASSIGN", "OR", "AND", "EQ", "NEQ", "LT",
  "LE", "GT", "GE", "ADD", "SUB", "MUL", "DIV", "MOD", "POW", "NOT",
  "$accept", "program", "class_declaration", "$@1", "$@2", "class_body",
  "identifier_list", "identifier_list_int", "identifier_list_string",
  "identifier_list_char", "identifier_list_double",
  "identifier_list_boolean", "identifier_list_variable", "assignment_list",
  "assignment_list_int", "assignment_list_string", "assignment_list_char",
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

#define YYPACT_NINF (-409)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-211)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     276,  -409,   302,    15,  -409,     3,    51,    16,  -409,  -409,
      81,    86,    94,   105,   112,  -409,    39,    40,    97,   114,
     133,   124,   143,    67,   239,   239,    20,   192,   189,  -409,
    -409,  -409,  -409,  -409,  -409,  -409,  -409,  -409,  -409,  -409,
     187,   209,  -409,  -409,  -409,   189,  -409,  -409,  -409,  -409,
    -409,  -409,  -409,  -409,   236,   200,   314,  -409,   249,   351,
    -409,   224,   262,  -409,  -409,   424,  -409,  -409,  -409,   402,
     229,   252,   189,    33,   233,  -409,    31,  -409,  -409,  -409,
    -409,   253,    32,  -409,  -409,   149,  -409,  -409,   153,  -409,
    -409,   176,  -409,  -409,   196,  -409,  -409,    79,    43,   265,
     267,   278,  -409,   189,   189,   189,   189,  -409,   312,  -409,
     120,   155,   348,  -409,  -409,  -409,  -409,  -409,  -409,   189,
     276,  -409,  -409,   276,  -409,    30,    30,    30,    30,    30,
      30,    44,    44,    44,    44,    44,    44,  -409,   108,   108,
     108,   108,   108,   108,   108,   108,   330,  -409,  -409,   334,
     307,    98,  -409,  -409,   341,   316,   317,   349,  -409,  -409,
     325,   326,    96,   122,   327,   345,   362,   106,  -409,   363,
      30,   370,   369,   374,    44,   381,   279,   385,   386,  -409,
    -409,  -409,    48,    25,   655,   248,   366,  -409,  -409,  -409,
    -409,  -409,  -409,    30,   314,   314,  -409,  -409,  -409,  -409,
    -409,    44,   351,   351,  -409,  -409,  -409,  -409,   108,   262,
     262,   262,   262,   262,   262,  -409,  -409,   360,   376,  -409,
    -409,   189,  -409,  -409,  -409,  -409,  -409,  -409,   391,   391,
     189,   401,   425,   435,   392,   437,   439,   440,   442,   444,
     450,   411,  -409,   427,   462,   432,   461,   189,   463,  -409,
     142,   464,  -409,   465,   466,  -409,   152,   469,  -409,   471,
     472,  -409,   473,  -409,  -409,   189,  -409,   384,  -409,   189,
     189,   189,   310,   433,  -409,  -409,   445,   221,   494,   506,
     474,  -409,  -409,   189,  -409,   189,  -409,  -409,   475,  -409,
     467,  -409,   468,  -409,   507,   476,  -409,   477,  -409,   478,
    -409,   480,  -409,   484,  -409,  -409,   483,   437,   439,   602,
     512,   425,   442,   444,   435,   490,   491,   492,   493,   189,
      81,    86,    94,   105,   112,   489,   366,   485,   189,   189,
     365,   341,   500,   495,  -409,   532,   534,    30,   502,   507,
    -409,  -409,   189,   189,   189,   497,  -409,  -409,  -409,  -409,
    -409,   496,   504,   505,   523,   108,   101,  -409,  -409,   602,
     365,   189,   517,   391,   391,  -409,   536,   427,   518,  -409,
     602,   513,   602,   189,   189,   189,   520,   527,   384,   103,
    -409,  -409,   189,   189,   525,   189,  -409,  -409,  -409,   528,
    -409,  -409,  -409,   655,   540,   540,   189,   189,   524,   529,
     530,   443,  -409,   189,   132,   189,   189,   189,   126,   248,
    -409,   531,   189,   517,   526,  -409,  -409,   538,   545,   540,
     545,    17,   189,   198,   189,   189,   655,  -409,   189,   189,
     539,   189,  -409,   189,   189,   541,   542,   544,   655,   189,
     189,   555,   655,   189,   535,   540,   543,   550,   551,   537,
     189,   546,   655,   549,   189,  -409,   655,  -409,  -409,  -409,
    -409,  -409,   189,   547,  -409,  -409,    48,   565,  -409,   655,
    -409,   552,   553,  -409,   189,   557,   189,   554,   189,   655,
    -409,   655,   189,   189,   558,   568,  -409,   555,  -409
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
    -409,    26,    11,  -409,  -409,  -217,   -49,   398,   416,   423,
     428,   434,   456,   -43,   315,  -218,  -216,  -226,  -221,  -213,
    -211,  -277,  -409,   389,  -409,  -409,  -409,  -409,  -409,  -409,
    -409,  -178,   -13,  -409,  -409,  -409,  -409,  -409,   268,   216,
    -148,  -408,     0,  -409,   -15,  -409,  -219,  -409,   164,   147,
    -409,  -409,  -409,   226,  -409,  -409,   217,   243,   194,  -384,
    -409,  -409,  -409,  -409,   318,   -12,   -14,   191,   295,   -10,
     201,   357,   -21,   346,   205,   614,    75,  -409,  -409,  -409,
    -409,  -409,  -409,     5,   -59,   -61,   121
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
     287,    28,   302,   111,   164,   293,   291,   334,   304,    74,
     147,    81,   296,     1,   113,   298,   148,   -83,     1,   109,
     450,     4,   269,     1,   113,   433,     1,    97,    75,     4,
     155,   156,     1,    97,   465,     4,     1,   109,   200,     4,
       4,     1,    97,   157,     4,    76,   152,   -83,   161,   162,
     160,   433,   369,   163,    98,   158,   159,   166,   169,   193,
       1,   109,    98,     4,    24,    25,   167,   170,    98,   103,
     158,   159,    98,   201,   110,    82,   348,    23,   111,   -83,
      85,   102,   349,   231,   340,   347,   350,   341,    88,   114,
     115,   117,    24,    25,     1,   379,    23,     4,    26,    91,
     243,     1,   113,   -83,   -83,   -83,    94,   259,    72,   -83,
      45,    24,    25,    45,   278,    69,   244,    26,    69,     1,
     421,    28,   237,   220,    28,   415,   104,    72,   -83,   416,
      98,   228,   382,   -83,   387,   388,   191,   208,   102,   192,
     125,   126,   246,   390,   245,   392,   250,   105,   238,   107,
     187,   267,    24,    25,   256,   208,   123,   264,    26,   263,
     266,   270,   106,   102,   125,   126,   131,   132,   310,   110,
      24,    25,   108,   364,   271,   171,    26,   112,   312,   173,
     277,   111,   118,   154,   172,   188,   125,   126,   174,   119,
     102,   102,   102,   102,   102,   102,   131,   132,   119,   131,
     132,   149,   175,   117,   117,   117,   117,   117,   117,   117,
     117,   176,   121,   147,   182,   183,   184,   185,   147,   148,
       6,   274,   177,   150,   148,   320,   321,   322,   323,   324,
     190,   178,     1,   113,   122,   102,   138,   139,   140,   141,
     142,   143,   273,   413,   125,   126,   151,     6,   102,   137,
       8,     9,    10,    11,    12,    13,    14,    15,   102,   231,
     231,   124,   138,   139,   140,   141,   142,   143,   165,     1,
       2,     3,     4,   117,     5,     6,   -97,     7,     8,     9,
      10,    11,    12,    13,    14,    15,   168,    16,    17,   231,
     179,    18,   180,   131,   132,    19,    20,    21,   144,   145,
      22,   158,   159,   181,    69,    23,   194,   195,   363,     6,
     186,   246,   245,   162,    10,    11,    12,    13,    14,    15,
      24,    25,   202,   203,   378,   217,    26,   -83,   218,    71,
     231,    72,   284,   380,   381,   222,   219,    73,   278,   215,
     216,   288,   232,   233,   234,   223,   224,   225,   226,   227,
      15,   235,   236,   239,    69,   240,   241,   248,   309,  -210,
     127,   128,   129,   130,   251,    69,   253,    69,   254,   223,
     224,   225,   226,   227,    15,   257,   315,   423,   189,   260,
     316,   317,   318,   403,   262,   422,   138,   139,   140,   141,
     142,   143,   279,   281,   330,   289,   331,   133,   134,   135,
     136,     6,   102,   146,   277,   282,    10,    11,    12,    13,
      14,    15,   196,   197,   198,   199,   440,   285,   294,   290,
     117,   102,   138,   139,   140,   141,   142,   143,   440,   292,
     355,   295,   455,   297,   299,   267,   301,   166,   303,   359,
     360,   264,   440,   263,   266,   305,   468,   223,   224,   225,
     226,   227,    15,   370,   371,   372,    72,   306,   307,   474,
    -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,    73,   482,
     319,   483,   384,   117,   209,   210,   211,   212,   213,   214,
     204,   205,   206,   207,   393,   394,   395,   308,   325,   169,
     171,   311,   173,   398,   399,   175,   401,   313,   177,   314,
     326,   333,   172,   178,   327,   332,   345,   408,   409,   339,
     358,   335,   336,   337,   414,   174,   418,   419,   420,   176,
     351,   352,   353,   426,   356,   365,   222,   354,   367,   373,
     366,   368,   170,   435,   436,   437,   438,   374,   375,   441,
     442,   376,   444,   385,   445,   446,   244,   391,   389,   396,
     451,   452,   397,   402,   456,   400,   404,   249,   410,   411,
     428,   463,   430,   412,   425,   467,   429,   443,   453,   457,
     462,   447,   448,   469,   449,   460,   461,   459,   466,   472,
     464,   470,   475,   261,   252,   477,   476,   479,   480,   481,
     478,   255,   486,   484,   485,     1,     2,     3,     4,   258,
       5,     6,   487,     7,     8,     9,    10,    11,    12,    13,
      14,    15,   242,    16,    17,   346,   300,    18,   383,   427,
     471,    19,    20,    21,   488,   424,    22,   434,   407,   458,
     116,    23,     0,     0,   357,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    24,    25,     1,     2,
       3,     4,    26,     5,     6,     0,     0,     8,     9,    10,
      11,    12,    13,    14,    15,     0,    16,    17,     0,     0,
      18,     0,     0,     0,    19,    20,    21,     0,     0,    22,
       0,     0,     0,     0,    23,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
      25,     0,     0,     0,     0,    26
};

static const yytype_int16 yycheck[] =
{
       0,    16,    23,    16,    16,     0,   154,   185,    69,    23,
     229,     0,   238,    23,    73,   233,   232,   294,   239,     4,
      69,     5,   235,     3,     4,   236,    69,    10,     3,     4,
     438,     6,     7,     3,     4,   419,     3,     4,    35,     6,
       7,     8,     3,     4,   452,     6,     3,     4,     4,     6,
       6,     3,     4,    20,     6,     4,    71,    40,    73,    73,
      73,   445,   339,    73,    39,    32,    33,    36,    36,    39,
       3,     4,    39,     6,    54,    55,    45,    45,    39,    39,
      32,    33,    39,    39,    98,     4,   312,    39,    98,    10,
       4,    16,   313,   154,   307,   311,   314,   308,     4,    24,
      25,    26,    54,    55,     3,     4,    39,     6,    60,     4,
       4,     3,     4,    10,    35,    36,     4,   176,    39,    40,
     120,    54,    55,   123,   185,   120,    20,    60,   123,     3,
       4,   120,    36,    35,   123,     3,    39,    39,    35,     7,
      39,   154,   359,    40,   363,   364,   120,    39,    73,   123,
      54,    55,   167,   370,   167,   372,   170,    43,    36,    35,
      40,   182,    54,    55,   174,    39,    45,   182,    60,   182,
     182,   183,    39,    98,    54,    55,    54,    55,    36,   193,
      54,    55,    39,   331,   184,    36,    60,   208,    36,    36,
     185,   201,     0,    72,    45,    40,    54,    55,    45,    10,
     125,   126,   127,   128,   129,   130,    54,    55,    10,    54,
      55,   272,    36,   138,   139,   140,   141,   142,   143,   144,
     145,    45,    35,   272,   103,   104,   105,   106,   277,   272,
       9,   409,    36,     4,   277,    14,    15,    16,    17,    18,
     119,    45,     3,     4,    35,   170,    48,    49,    50,    51,
      52,    53,     4,   401,    54,    55,     4,     9,   183,    35,
      12,    13,    14,    15,    16,    17,    18,    19,   193,   330,
     331,    35,    48,    49,    50,    51,    52,    53,    45,     3,
       4,     5,     6,   208,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    43,    21,    22,   360,
      35,    25,    35,    54,    55,    29,    30,    31,    46,    47,
      34,    32,    33,    35,   309,    39,   125,   126,   331,     9,
       8,   336,   335,   337,    14,    15,    16,    17,    18,    19,
      54,    55,   131,   132,   355,     5,    60,    35,     4,    37,
     401,    39,   221,   356,   356,     4,    39,    45,   409,   144,
     145,   230,    36,    36,     5,    14,    15,    16,    17,    18,
      19,    36,    36,    36,   359,    20,     4,     4,   247,     4,
      56,    57,    58,    59,     4,   370,     7,   372,     4,    14,
      15,    16,    17,    18,    19,     4,   265,   408,    40,     4,
     269,   270,   271,   393,     8,   408,    48,    49,    50,    51,
      52,    53,    36,    43,   283,     4,   285,    56,    57,    58,
      59,     9,   337,    11,   409,    39,    14,    15,    16,    17,
      18,    19,   127,   128,   129,   130,   426,    36,    36,     4,
     355,   356,    48,    49,    50,    51,    52,    53,   438,     4,
     319,     4,   442,     4,     4,   466,     4,    36,     4,   328,
     329,   466,   452,   466,   466,     5,   456,    14,    15,    16,
      17,    18,    19,   342,   343,   344,    39,     5,    36,   469,
      46,    47,    48,    49,    50,    51,    52,    53,    45,   479,
      35,   481,   361,   408,   138,   139,   140,   141,   142,   143,
     133,   134,   135,   136,   373,   374,   375,    36,     4,    36,
      36,    36,    36,   382,   383,    36,   385,    36,    36,    36,
       4,     4,    45,    45,    40,    40,     4,   396,   397,    36,
      35,    45,    45,    45,   403,    45,   405,   406,   407,    45,
      40,    40,    40,   412,    45,    35,     4,    44,     4,    43,
      45,    39,    45,   422,   423,   424,   425,    43,    43,   428,
     429,    28,   431,    36,   433,   434,    20,    44,    40,    39,
     439,   440,    35,    35,   443,    40,    26,   169,    44,    40,
      44,   450,    27,    43,    43,   454,    38,    38,    23,    44,
      43,    40,    40,   462,    40,    35,    35,    44,    39,    24,
      44,    44,    40,   177,   171,   474,    43,   476,    44,   478,
      43,   173,    44,   482,   483,     3,     4,     5,     6,   175,
       8,     9,    44,    11,    12,    13,    14,    15,    16,    17,
      18,    19,   166,    21,    22,   310,   237,    25,   360,   413,
     466,    29,    30,    31,   487,   409,    34,   420,   395,   445,
      26,    39,    -1,    -1,   326,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    55,     3,     4,
       5,     6,    60,     8,     9,    -1,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      25,    -1,    -1,    -1,    29,    30,    31,    -1,    -1,    34,
      -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    60
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     8,     9,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    21,    22,    25,    29,
      30,    31,    34,    39,    54,    55,    60,    62,    63,    67,
      74,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,   103,   105,   108,   112,   113,
     116,   122,   123,   124,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   141,   144,
     146,    37,    39,    45,     4,    35,     4,    73,    80,    81,
      82,     5,     4,    68,    75,     4,    70,    77,     4,    71,
      78,     4,    72,    79,     4,    69,    76,     4,    39,    93,
     105,   126,   137,    39,    39,    43,    39,    35,    39,     4,
     127,   130,   133,     4,   137,   137,   136,   137,     0,    10,
     147,    35,    35,   147,    35,    54,    55,    56,    57,    58,
      59,    54,    55,    56,    57,    58,    59,    35,    48,    49,
      50,    51,    52,    53,    46,    47,    11,    67,    74,   146,
       4,     4,   105,   143,   147,     7,     8,    20,    32,    33,
      93,   105,   127,   130,   145,    45,    36,    45,    43,    36,
      45,    36,    45,    36,    45,    36,    45,    36,    45,    35,
      35,    35,   147,   147,   147,   147,     8,    40,    40,    40,
     147,    62,    62,    39,   128,   128,   129,   129,   129,   129,
       4,    39,   131,   131,   132,   132,   132,   132,    39,   134,
     134,   134,   134,   134,   134,   135,   135,     5,     4,    39,
      35,   142,     4,    14,    15,    16,    17,    18,    93,   101,
     106,   146,    36,    36,     5,    36,    36,    36,    36,    36,
      20,     4,    73,     4,    20,    93,   105,    65,     4,    68,
     127,     4,    70,     7,     4,    71,   130,     4,    72,   145,
       4,    69,     8,    93,   105,   109,   126,   133,   145,     7,
     126,   103,   144,     4,    92,   104,   114,   144,   146,    36,
     125,    43,    39,    98,   147,    36,   107,   107,   147,     4,
       4,    77,     4,    76,    36,     4,    80,     4,    81,     4,
      84,     4,    78,     4,    79,     5,     5,    36,    36,   147,
      36,    36,    36,    36,    36,   147,   147,   147,   147,    35,
      14,    15,    16,    17,    18,     4,     4,    40,    64,    97,
     147,   147,    40,     4,    82,    45,    45,    45,   140,    36,
      80,    81,    63,    66,   103,     4,    75,    77,    78,    79,
      76,    40,    40,    40,    44,   147,    45,   125,    35,   147,
     147,    99,   101,    93,   101,    35,    45,     4,    39,    82,
     147,   147,   147,    43,    43,    43,    28,   115,   133,     4,
      93,   126,    66,    99,   147,    36,   100,   107,   107,    40,
      66,    44,    66,   147,   147,   147,    39,    35,   147,   147,
      40,   147,    35,   103,    26,   118,   120,   118,   147,   147,
      44,    40,    43,   101,   147,     3,     7,   121,   147,   147,
     147,     4,    93,   133,   114,    43,   147,   100,    44,    38,
      27,   117,   119,   120,   117,   147,   147,   147,   147,   102,
     103,   147,   147,    38,   147,   147,   147,    40,    40,    40,
     102,   147,   147,    23,   110,   103,   147,    44,   119,    44,
      35,    35,    43,   147,    44,   102,    39,   147,   103,   147,
      44,   109,    24,   111,   103,    40,    43,   147,    43,   147,
      44,   147,   103,   103,   147,   147,    44,    44,   110
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    62,    62,    64,    63,    65,    63,    66,
      66,    66,    67,    67,    67,    67,    67,    67,    68,    68,
      69,    69,    70,    70,    71,    71,    72,    72,    73,    73,
      74,    74,    74,    74,    74,    74,    74,    74,    75,    75,
      76,    76,    77,    77,    78,    78,    79,    79,    80,    80,
      81,    81,    82,    82,    83,    83,    83,    83,    83,    83,
      83,    83,    84,    84,    85,    85,    86,    86,    87,    87,
      88,    88,    89,    89,    90,    90,    91,    91,    92,    92,
      92,    92,    92,    93,    94,    95,    97,    96,    98,    96,
      99,    99,   100,   100,   101,   102,   102,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   104,   104,   105,   106,   106,   106,
     107,   107,   107,   108,   109,   109,   109,   109,   109,   110,
     110,   111,   111,   112,   112,   113,   114,   114,   114,   115,
     115,   116,   116,   117,   117,   118,   119,   119,   120,   121,
     121,   122,   122,   122,   123,   124,   125,   125,   126,   126,
     127,   127,   127,   128,   128,   128,   128,   128,   129,   129,
     130,   130,   130,   131,   131,   131,   131,   131,   132,   132,
     133,   133,   133,   133,   133,   133,   133,   134,   134,   134,
     135,   135,   135,   136,   136,   136,   137,   137,   138,   138,
     140,   139,   142,   141,   143,   143,   144,   144,   145,   145,
     146,   146,   146,   146,   146,   146,   146,   147,   147
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
#line 249 "project.y"
                                                      {
    addSymbol((yyvsp[-1].sval), "class", false, true, true, NULL);
    increaseScope();
}
#line 1779 "project.tab.c"
    break;

  case 6: /* class_declaration: access_modifier CLASS CLASS_ID LCB $@1 none_or_newlines class_body none_or_newlines RCB  */
#line 252 "project.y"
                                                   { decreaseScope(); }
#line 1785 "project.tab.c"
    break;

  case 7: /* $@2: %empty  */
#line 253 "project.y"
                         {
    addSymbol((yyvsp[-1].sval), "class", false, true, true, NULL);
    increaseScope();
}
#line 1794 "project.tab.c"
    break;

  case 8: /* class_declaration: CLASS CLASS_ID LCB $@2 none_or_newlines class_body none_or_newlines RCB  */
#line 256 "project.y"
                                                   { decreaseScope(); }
#line 1800 "project.tab.c"
    break;

  case 18: /* identifier_list_int: ID  */
#line 272 "project.y"
                        { addSymbol((yyvsp[0].sval), "int", false, false, false, NULL); }
#line 1806 "project.tab.c"
    break;

  case 19: /* identifier_list_int: ID COMMA identifier_list_int  */
#line 273 "project.y"
                                   { addSymbol((yyvsp[-2].sval), "int", false, false, false, NULL); }
#line 1812 "project.tab.c"
    break;

  case 20: /* identifier_list_string: ID  */
#line 276 "project.y"
                           { addSymbol((yyvsp[0].sval), "string", false, false, false, NULL); }
#line 1818 "project.tab.c"
    break;

  case 21: /* identifier_list_string: ID COMMA identifier_list_string  */
#line 277 "project.y"
                                      { addSymbol((yyvsp[-2].sval), "string", false, false, false, NULL); }
#line 1824 "project.tab.c"
    break;

  case 22: /* identifier_list_char: ID  */
#line 280 "project.y"
                         { addSymbol((yyvsp[0].sval), "char", false, false, false, NULL); }
#line 1830 "project.tab.c"
    break;

  case 23: /* identifier_list_char: ID COMMA identifier_list_char  */
#line 281 "project.y"
                                    { addSymbol((yyvsp[-2].sval), "char", false, false, false, NULL); }
#line 1836 "project.tab.c"
    break;

  case 24: /* identifier_list_double: ID  */
#line 284 "project.y"
                           { addSymbol((yyvsp[0].sval), "double", false, false, false, NULL); }
#line 1842 "project.tab.c"
    break;

  case 25: /* identifier_list_double: ID COMMA identifier_list_double  */
#line 285 "project.y"
                                      { addSymbol((yyvsp[-2].sval), "double", false, false, false, NULL); }
#line 1848 "project.tab.c"
    break;

  case 26: /* identifier_list_boolean: ID  */
#line 288 "project.y"
                            { addSymbol((yyvsp[0].sval), "boolean", false, false, false, NULL); }
#line 1854 "project.tab.c"
    break;

  case 27: /* identifier_list_boolean: ID COMMA identifier_list_boolean  */
#line 289 "project.y"
                                       { addSymbol((yyvsp[-2].sval), "boolean", false, false, false, NULL); }
#line 1860 "project.tab.c"
    break;

  case 28: /* identifier_list_variable: ID  */
#line 292 "project.y"
                             { addSymbol((yyvsp[0].sval), "var", false, false, false, NULL); }
#line 1866 "project.tab.c"
    break;

  case 29: /* identifier_list_variable: ID COMMA identifier_list_variable  */
#line 293 "project.y"
                                        { addSymbol((yyvsp[-2].sval), "var", false, false, false, NULL); }
#line 1872 "project.tab.c"
    break;

  case 38: /* assignment_list_int: ID ASSIGN exp_int  */
#line 307 "project.y"
                                       {
    char valueStr[32];
    sprintf(valueStr, "%d", (yyvsp[0].ival));
    addSymbol((yyvsp[-2].sval), "int", false, true, false, valueStr);
    printf("Variable %s assigned with value %d\n\n", (yyvsp[-2].sval), (yyvsp[0].ival));
}
#line 1883 "project.tab.c"
    break;

  case 39: /* assignment_list_int: ID ASSIGN exp_int COMMA assignment_list_int  */
#line 313 "project.y"
                                                  {
    char valueStr[32]; sprintf(valueStr, "%d", (yyvsp[-2].ival));
    addSymbol((yyvsp[-4].sval), "int", false, true, false, valueStr);
    printf("Variable %s assigned with value %d\n\n", (yyvsp[-4].sval), (yyvsp[-2].ival));
}
#line 1893 "project.tab.c"
    break;

  case 40: /* assignment_list_string: ID ASSIGN DQ_STRING_DQ  */
#line 319 "project.y"
                                               { addSymbol((yyvsp[-2].sval), "string", false, true, false, (yyvsp[0].sval)); }
#line 1899 "project.tab.c"
    break;

  case 41: /* assignment_list_string: ID ASSIGN DQ_STRING_DQ COMMA assignment_list_string  */
#line 320 "project.y"
                                                          { addSymbol((yyvsp[-4].sval), "string", false, true, false, (yyvsp[-2].sval)); }
#line 1905 "project.tab.c"
    break;

  case 42: /* assignment_list_char: ID ASSIGN SQ_ANYCHAR_SQ  */
#line 323 "project.y"
                                              { addSymbol((yyvsp[-2].sval), "char", false, true, false, (yyvsp[0].cval)); }
#line 1911 "project.tab.c"
    break;

  case 43: /* assignment_list_char: ID ASSIGN SQ_ANYCHAR_SQ COMMA assignment_list_char  */
#line 324 "project.y"
                                                         { addSymbol((yyvsp[-4].sval), "char", false, true, false, (yyvsp[-2].cval)); }
#line 1917 "project.tab.c"
    break;

  case 44: /* assignment_list_double: ID ASSIGN exp_double  */
#line 327 "project.y"
                                             {
    char valueStr[64];
    sprintf(valueStr, "%f", (yyvsp[0].dval));
    addSymbol((yyvsp[-2].sval), "double", false, true, false, valueStr);
    printf("Variable %s assigned with value %f\n\n", (yyvsp[-2].sval), (yyvsp[0].dval));
}
#line 1928 "project.tab.c"
    break;

  case 45: /* assignment_list_double: ID ASSIGN exp_double COMMA assignment_list_double  */
#line 333 "project.y"
                                                        {
    char valueStr[64];
    sprintf(valueStr, "%f", (yyvsp[-2].dval));
    addSymbol((yyvsp[-4].sval), "double", false, true, false, valueStr);
    printf("Variable %s assigned with value %f\n\n", (yyvsp[-4].sval), (yyvsp[-2].dval));
}
#line 1939 "project.tab.c"
    break;

  case 46: /* assignment_list_boolean: ID ASSIGN boolean  */
#line 340 "project.y"
                                           { addSymbol((yyvsp[-2].sval), "boolean", false, true, false, (yyvsp[0].sval)); }
#line 1945 "project.tab.c"
    break;

  case 47: /* assignment_list_boolean: ID ASSIGN boolean COMMA assignment_list_boolean  */
#line 341 "project.y"
                                                      { addSymbol((yyvsp[-4].sval), "boolean", false, true, false, (yyvsp[-2].sval)); }
#line 1951 "project.tab.c"
    break;

  case 48: /* assignment_list_variable: ID ASSIGN variable_reference  */
#line 344 "project.y"
                                                       {
    char* type = getType((yyvsp[0].sval));
    char* value = getValue((yyvsp[0].sval));
    addSymbol((yyvsp[-2].sval), type, false, true, false, value);
}
#line 1961 "project.tab.c"
    break;

  case 49: /* assignment_list_variable: ID ASSIGN variable_reference COMMA assignment_list_variable  */
#line 349 "project.y"
                                                                  {
    char* type = getType((yyvsp[-2].sval));
    char* value = getValue((yyvsp[-2].sval));
    addSymbol((yyvsp[-4].sval), type, false, true, false, value);
}
#line 1971 "project.tab.c"
    break;

  case 50: /* assignment_list_method: ID ASSIGN method_call  */
#line 355 "project.y"
                                              {
    char* type = getType((yyvsp[0].sval));
    addSymbol((yyvsp[-2].sval), type, false, true, false, NULL);
}
#line 1980 "project.tab.c"
    break;

  case 51: /* assignment_list_method: ID ASSIGN method_call COMMA assignment_list_method  */
#line 359 "project.y"
                                                         {
    char* type = getType((yyvsp[-2].sval));
    addSymbol((yyvsp[-4].sval), type, false, true, false, NULL);
}
#line 1989 "project.tab.c"
    break;

  case 52: /* assignment_list_object: ID ASSIGN NEW CLASS_ID  */
#line 364 "project.y"
                                               { addSymbol((yyvsp[-3].sval), "class", false, true, false, NULL); }
#line 1995 "project.tab.c"
    break;

  case 53: /* assignment_list_object: ID ASSIGN NEW CLASS_ID COMMA assignment_list_object  */
#line 365 "project.y"
                                                          { addSymbol((yyvsp[-5].sval), "class", false, true, false, NULL); }
#line 2001 "project.tab.c"
    break;

  case 62: /* assignment_list_int_declared: ID ASSIGN exp_int  */
#line 378 "project.y"
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
#line 2018 "project.tab.c"
    break;

  case 63: /* assignment_list_int_declared: ID ASSIGN exp_int COMMA assignment_list_int_declared  */
#line 390 "project.y"
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
#line 2035 "project.tab.c"
    break;

  case 64: /* assignment_list_string_declared: ID ASSIGN DQ_STRING_DQ  */
#line 403 "project.y"
                                                        {
    char* type = getType((yyvsp[-2].sval));
    if (type == NULL || strcmp(type, "string") != 0) {
        yyerror("Type mismatch");
        exit(1);
    } else {
        setInitialized((yyvsp[-2].sval), (yyvsp[0].sval));
    }
}
#line 2049 "project.tab.c"
    break;

  case 65: /* assignment_list_string_declared: ID ASSIGN DQ_STRING_DQ COMMA assignment_list_string  */
#line 412 "project.y"
                                                          {
    char* type = getType((yyvsp[-4].sval));
    if (type == NULL || strcmp(type, "string") != 0) {
        yyerror("Type mismatch");
        exit(1);
    } else {
        setInitialized((yyvsp[-4].sval), (yyvsp[-2].sval));
    }
}
#line 2063 "project.tab.c"
    break;

  case 66: /* assignment_list_char_declared: ID ASSIGN SQ_ANYCHAR_SQ  */
#line 422 "project.y"
                                                       {
    char* type = getType((yyvsp[-2].sval));
    if (type == NULL || strcmp(type, "char") != 0) {
        yyerror("Type mismatch");
        exit(1);
    } else {
        setInitialized((yyvsp[-2].sval), (yyvsp[0].cval));
    }
}
#line 2077 "project.tab.c"
    break;

  case 67: /* assignment_list_char_declared: ID ASSIGN SQ_ANYCHAR_SQ COMMA assignment_list_char  */
#line 431 "project.y"
                                                         {
    char* type = getType((yyvsp[-4].sval));
    if (type == NULL || strcmp(type, "char") != 0) {
        yyerror("Type mismatch");
        exit(1);
    } else {
        setInitialized((yyvsp[-4].sval), (yyvsp[-2].cval));
    }
}
#line 2091 "project.tab.c"
    break;

  case 68: /* assignment_list_double_declared: ID ASSIGN exp_double  */
#line 441 "project.y"
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
#line 2108 "project.tab.c"
    break;

  case 69: /* assignment_list_double_declared: ID ASSIGN exp_double COMMA assignment_list_double  */
#line 453 "project.y"
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
#line 2125 "project.tab.c"
    break;

  case 70: /* assignment_list_boolean_declared: ID ASSIGN boolean  */
#line 466 "project.y"
                                                    {
    char* type = getType((yyvsp[-2].sval));
    if (type == NULL || strcmp(type, "boolean") != 0) {
        yyerror("Type mismatch");
        exit(1);
    } else {
        setInitialized((yyvsp[-2].sval), (yyvsp[0].sval));
    }
}
#line 2139 "project.tab.c"
    break;

  case 71: /* assignment_list_boolean_declared: ID ASSIGN boolean COMMA assignment_list_boolean  */
#line 475 "project.y"
                                                      {
    char* type = getType((yyvsp[-4].sval));
    if (type == NULL || strcmp(type, "boolean") != 0) {
        yyerror("Type mismatch");
        exit(1);
    } else {
        setInitialized((yyvsp[-4].sval), (yyvsp[-2].sval));
    }
}
#line 2153 "project.tab.c"
    break;

  case 72: /* assignment_list_variable_declared: ID ASSIGN variable_reference  */
#line 485 "project.y"
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
#line 2168 "project.tab.c"
    break;

  case 73: /* assignment_list_variable_declared: ID ASSIGN variable_reference COMMA assignment_list_variable  */
#line 495 "project.y"
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
#line 2183 "project.tab.c"
    break;

  case 74: /* assignment_list_method_declared: ID ASSIGN method_call  */
#line 506 "project.y"
                                                       {
    char* type = getType((yyvsp[-2].sval));
    if (type == NULL || strcmp(type, getType((yyvsp[0].sval))) != 0) {
        yyerror("Type mismatch");
        exit(1);
    } else {
        setInitialized((yyvsp[-2].sval), NULL);
    }
}
#line 2197 "project.tab.c"
    break;

  case 75: /* assignment_list_method_declared: ID ASSIGN method_call COMMA assignment_list_method  */
#line 515 "project.y"
                                                         {
    char* type = getType((yyvsp[-4].sval));
    if (type == NULL || strcmp(type, getType((yyvsp[-2].sval))) != 0) {
        yyerror("Type mismatch");
        exit(1);
    } else {
        setInitialized((yyvsp[-4].sval), NULL);
    }
}
#line 2211 "project.tab.c"
    break;

  case 76: /* assignment_list_object_declared: ID ASSIGN NEW CLASS_ID  */
#line 525 "project.y"
                                                        {
    char* type = getType((yyvsp[-3].sval));
    if (type == NULL || strcmp(type, (yyvsp[0].sval)) != 0) {
        yyerror("Type mismatch");
        exit(1);
    } else {
        setInitialized((yyvsp[-3].sval), NULL);
    }
}
#line 2225 "project.tab.c"
    break;

  case 77: /* assignment_list_object_declared: ID ASSIGN NEW CLASS_ID COMMA assignment_list_object  */
#line 534 "project.y"
                                                          {
    char* type = getType((yyvsp[-5].sval));
    if (type == NULL || strcmp(type, (yyvsp[-2].sval)) != 0) {
        yyerror("Type mismatch");
        exit(1);
    } else {
        setInitialized((yyvsp[-5].sval), NULL);
    }
}
#line 2239 "project.tab.c"
    break;

  case 83: /* variable_reference: ID  */
#line 553 "project.y"
                       {
    if (!symbolExists((yyvsp[0].sval), false, false)) {
        yyerror("Variable not declared");
    } else if (!isInitialized((yyvsp[0].sval))) {
        yyerror("Variable not initialized");
    } else {
        (yyval.sval) = getValue((yyvsp[0].sval));
    }
}
#line 2253 "project.tab.c"
    break;

  case 84: /* variable_reference_int: ID  */
#line 563 "project.y"
                           {
    if (!symbolExists((yyvsp[0].sval), false, false)) {
        yyerror("Variable not declared");
    } else if (!isInitialized((yyvsp[0].sval))) {
        yyerror("Variable not initialized");
    } else {
        if (strcmp(getType((yyvsp[0].sval)), "double") == 0) {
            (yyval.ival) = (int) atof(getValue((yyvsp[0].sval)));
        } else {
            (yyval.ival) = atoi(getValue((yyvsp[0].sval)));
        }
    }
}
#line 2271 "project.tab.c"
    break;

  case 85: /* variable_reference_double: ID  */
#line 577 "project.y"
                              {
    if (!symbolExists((yyvsp[0].sval), false, false)) {
        yyerror("Variable not declared");
    } else if (!isInitialized((yyvsp[0].sval))) {
        yyerror("Variable not initialized");
    } else {
        if (strcmp(getType((yyvsp[0].sval)), "int") == 0) {
            (yyval.dval) = (double) atoi(getValue((yyvsp[0].sval)));
        } else {
            (yyval.dval) = atof(getValue((yyvsp[0].sval)));
        }
    }
}
#line 2289 "project.tab.c"
    break;

  case 86: /* $@3: %empty  */
#line 592 "project.y"
                                                    { increaseScope(); }
#line 2295 "project.tab.c"
    break;

  case 87: /* method_declaration: access_modifier data_type ID LP $@3 none_or_newlines none_or_multiple_parameters none_or_newlines RP LCB none_or_newlines method_body none_or_newlines RCB  */
#line 592 "project.y"
                                                                                                                                                                                                {
    addSymbol("sum", (yyvsp[-12].sval), true, true, false, NULL);
    decreaseScope();
}
#line 2304 "project.tab.c"
    break;

  case 88: /* $@4: %empty  */
#line 596 "project.y"
                      { increaseScope(); }
#line 2310 "project.tab.c"
    break;

  case 89: /* method_declaration: data_type ID LP $@4 none_or_newlines none_or_multiple_parameters none_or_newlines RP LCB none_or_newlines method_body none_or_newlines RCB  */
#line 596 "project.y"
                                                                                                                                                                  {
    addSymbol((yyvsp[-11].sval), (yyvsp[-12].sval), true, true, false, NULL);
    decreaseScope();
}
#line 2319 "project.tab.c"
    break;

  case 94: /* parameter: data_type ID  */
#line 609 "project.y"
                        { addSymbol((yyvsp[0].sval), (yyvsp[-1].sval), false, true, false, NULL); }
#line 2325 "project.tab.c"
    break;

  case 116: /* method_call: ID LP none_or_newlines none_or_multiple_arguments none_or_newlines RP SEMICOLON  */
#line 640 "project.y"
                                                                                             {
    if (!symbolExists((yyvsp[-6].sval), true, false)) {
        yyerror("Method not declared");
    }
}
#line 2335 "project.tab.c"
    break;

  case 157: /* single_or_multiple_variables: COMMA ID single_or_multiple_variables  */
#line 724 "project.y"
                                            {
    if (!symbolExists((yyvsp[-1].sval), false, false)) {
        yyerror("Variable not declared");
    } else if (!isInitialized((yyvsp[-1].sval))) {
        yyerror("Variable not initialized");
    }
}
#line 2347 "project.tab.c"
    break;

  case 160: /* exp_int: term_int  */
#line 737 "project.y"
                  { (yyval.ival) = (yyvsp[0].ival); }
#line 2353 "project.tab.c"
    break;

  case 161: /* exp_int: exp_int ADD term_int  */
#line 738 "project.y"
                           { (yyval.ival) = (yyvsp[-2].ival) + (yyvsp[0].ival); }
#line 2359 "project.tab.c"
    break;

  case 162: /* exp_int: exp_int SUB term_int  */
#line 739 "project.y"
                           { (yyval.ival) = (yyvsp[-2].ival) - (yyvsp[0].ival); }
#line 2365 "project.tab.c"
    break;

  case 163: /* term_int: factor_int  */
#line 742 "project.y"
                     { (yyval.ival) = (yyvsp[0].ival);}
#line 2371 "project.tab.c"
    break;

  case 164: /* term_int: term_int MUL factor_int  */
#line 743 "project.y"
                              { (yyval.ival) = (yyvsp[-2].ival) * (yyvsp[0].ival); }
#line 2377 "project.tab.c"
    break;

  case 165: /* term_int: term_int DIV factor_int  */
#line 744 "project.y"
                              {
    if ((yyvsp[0].ival) == 0) {
        yyerror("Division by zero");
    } else {
        (yyval.ival) = (yyvsp[-2].ival) / (yyvsp[0].ival);
    }
}
#line 2389 "project.tab.c"
    break;

  case 166: /* term_int: term_int MOD factor_int  */
#line 751 "project.y"
                              {
    if ((yyvsp[0].ival) == 0) {
        yyerror("Division by zero");
    } else {
        (yyval.ival) = fmod((yyvsp[-2].ival), (yyvsp[0].ival));
    }
}
#line 2401 "project.tab.c"
    break;

  case 167: /* term_int: term_int POW factor_int  */
#line 758 "project.y"
                              {
    if ((yyvsp[0].ival) == 0) {
        yyerror("Exponentiation by zero");
    } else {
        (yyval.ival) = pow((yyvsp[-2].ival), (yyvsp[0].ival));
    }
}
#line 2413 "project.tab.c"
    break;

  case 168: /* factor_int: primary_int  */
#line 766 "project.y"
                        { (yyval.ival) = (yyvsp[0].ival); }
#line 2419 "project.tab.c"
    break;

  case 169: /* factor_int: LP exp_int RP  */
#line 767 "project.y"
                    { (yyval.ival) = (yyvsp[-1].ival); }
#line 2425 "project.tab.c"
    break;

  case 170: /* exp_double: term_double  */
#line 771 "project.y"
                        { (yyval.dval) = (yyvsp[0].dval); }
#line 2431 "project.tab.c"
    break;

  case 171: /* exp_double: exp_double ADD term_double  */
#line 772 "project.y"
                                 { (yyval.dval) = (yyvsp[-2].dval) + (yyvsp[0].dval); }
#line 2437 "project.tab.c"
    break;

  case 172: /* exp_double: exp_double SUB term_double  */
#line 773 "project.y"
                                 { (yyval.dval) = (yyvsp[-2].dval) - (yyvsp[0].dval); }
#line 2443 "project.tab.c"
    break;

  case 173: /* term_double: factor_double  */
#line 776 "project.y"
                           { (yyval.dval) = (yyvsp[0].dval); }
#line 2449 "project.tab.c"
    break;

  case 174: /* term_double: term_double MUL factor_double  */
#line 777 "project.y"
                                    { (yyval.dval) = (yyvsp[-2].dval) * (yyvsp[0].dval); }
#line 2455 "project.tab.c"
    break;

  case 175: /* term_double: term_double DIV factor_double  */
#line 778 "project.y"
                                    {
    if ((yyvsp[0].dval) == 0) {
        yyerror("Division by zero");
    } else {
        (yyval.dval) = (yyvsp[-2].dval) / (yyvsp[0].dval);
    }
}
#line 2467 "project.tab.c"
    break;

  case 176: /* term_double: term_double MOD factor_double  */
#line 785 "project.y"
                                    {
    if ((yyvsp[0].dval) == 0) {
        yyerror("Division by zero");
    } else {
        (yyval.dval) = fmod((yyvsp[-2].dval), (yyvsp[0].dval));
    }
}
#line 2479 "project.tab.c"
    break;

  case 177: /* term_double: term_double POW factor_double  */
#line 792 "project.y"
                                    {
    if ((yyvsp[0].dval) == 0) {
        yyerror("Exponentiation by zero");
    } else {
        (yyval.dval) = pow((yyvsp[-2].dval), (yyvsp[0].dval));
    }
}
#line 2491 "project.tab.c"
    break;

  case 178: /* factor_double: primary_double  */
#line 800 "project.y"
                              { (yyval.dval) = (yyvsp[0].dval); }
#line 2497 "project.tab.c"
    break;

  case 179: /* factor_double: LP exp_double RP  */
#line 801 "project.y"
                       { (yyval.dval) = (yyvsp[-1].dval); }
#line 2503 "project.tab.c"
    break;

  case 193: /* unary: primary_int  */
#line 823 "project.y"
                   { (yyval.ival) = (yyvsp[0].ival); }
#line 2509 "project.tab.c"
    break;

  case 194: /* unary: ADD primary_int  */
#line 824 "project.y"
                      { (yyval.ival) = (yyvsp[0].ival); }
#line 2515 "project.tab.c"
    break;

  case 195: /* unary: SUB primary_int  */
#line 825 "project.y"
                      { (yyval.ival) = -(yyvsp[0].ival); }
#line 2521 "project.tab.c"
    break;

  case 196: /* primary_int: CONST  */
#line 828 "project.y"
                   { (yyval.ival) = (yyvsp[0].ival); }
#line 2527 "project.tab.c"
    break;

  case 197: /* primary_int: variable_reference_int  */
#line 829 "project.y"
                             { (yyval.ival) = (yyvsp[0].ival); }
#line 2533 "project.tab.c"
    break;

  case 198: /* primary_double: DOUBLE_CONST  */
#line 832 "project.y"
                             { (yyval.dval) = (yyvsp[0].dval); }
#line 2539 "project.tab.c"
    break;

  case 199: /* primary_double: variable_reference_double  */
#line 833 "project.y"
                                { (yyval.dval) = (yyvsp[0].dval); }
#line 2545 "project.tab.c"
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
#line 2557 "project.tab.c"
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
#line 2569 "project.tab.c"
    break;

  case 204: /* member_access_body: ID SEMICOLON  */
#line 854 "project.y"
                                 {
    if (!symbolExists((yyvsp[-1].sval), false, false)) {
        yyerror("Variable not declared");
    }
}
#line 2579 "project.tab.c"
    break;

  case 205: /* member_access_body: method_call  */
#line 859 "project.y"
                  {
    if (!symbolExists((yyvsp[0].sval), true, false)) {
        yyerror("Method not declared");
    }
}
#line 2589 "project.tab.c"
    break;

  case 208: /* boolean: TRUE  */
#line 869 "project.y"
              { (yyval.sval) = "true"; }
#line 2595 "project.tab.c"
    break;

  case 209: /* boolean: FALSE  */
#line 870 "project.y"
            { (yyval.sval) = "false"; }
#line 2601 "project.tab.c"
    break;

  case 210: /* data_type: %empty  */
#line 873 "project.y"
                         { (yyval.sval) = ""; }
#line 2607 "project.tab.c"
    break;

  case 211: /* data_type: INTEGER  */
#line 874 "project.y"
              { (yyval.sval) = "int"; }
#line 2613 "project.tab.c"
    break;

  case 212: /* data_type: CHAR  */
#line 875 "project.y"
           { (yyval.sval) = "char"; }
#line 2619 "project.tab.c"
    break;

  case 213: /* data_type: DOUBLE  */
#line 876 "project.y"
             { (yyval.sval) = "double"; }
#line 2625 "project.tab.c"
    break;

  case 214: /* data_type: BOOLEAN  */
#line 877 "project.y"
              { (yyval.sval) = "boolean"; }
#line 2631 "project.tab.c"
    break;

  case 215: /* data_type: STRING  */
#line 878 "project.y"
             { (yyval.sval) = "string"; }
#line 2637 "project.tab.c"
    break;

  case 216: /* data_type: VOID  */
#line 879 "project.y"
           { (yyval.sval) = "void"; }
#line 2643 "project.tab.c"
    break;


#line 2647 "project.tab.c"

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

    printf("\n\nSymbol table:\n");
    for (int i = 0; i < symbolCount; i++) {
        printf("Name: %s, Type: %s, isMethod: %d, isInitialized: %d, Scope: %d, isClass: %d, Value: %s\n",
               symbolTable[i].name, symbolTable[i].type, symbolTable[i].isMethod,
               symbolTable[i].isInitialized, symbolTable[i].scope, symbolTable[i].isClass, symbolTable[i].value);
    }

    fclose(f);

    return 0;
}
