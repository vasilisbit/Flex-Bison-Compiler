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
        printf("Name: %s, Type: %s, isMethod: %d, isInitialized: %d, Scope: %d\n, isClass: %d\n",
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
        if (symbolTable[i].scope > scope) {
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


#line 222 "project.tab.c"

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
  YYSYMBOL_VAR = 8,                        /* VAR  */
  YYSYMBOL_NEWLINE = 9,                    /* NEWLINE  */
  YYSYMBOL_CLASS = 10,                     /* CLASS  */
  YYSYMBOL_PUBLIC = 11,                    /* PUBLIC  */
  YYSYMBOL_PRIVATE = 12,                   /* PRIVATE  */
  YYSYMBOL_INTEGER = 13,                   /* INTEGER  */
  YYSYMBOL_CHAR = 14,                      /* CHAR  */
  YYSYMBOL_DOUBLE = 15,                    /* DOUBLE  */
  YYSYMBOL_BOOLEAN = 16,                   /* BOOLEAN  */
  YYSYMBOL_STRING = 17,                    /* STRING  */
  YYSYMBOL_VOID = 18,                      /* VOID  */
  YYSYMBOL_NEW = 19,                       /* NEW  */
  YYSYMBOL_RETURN = 20,                    /* RETURN  */
  YYSYMBOL_IF = 21,                        /* IF  */
  YYSYMBOL_ELIF = 22,                      /* ELIF  */
  YYSYMBOL_ELSE = 23,                      /* ELSE  */
  YYSYMBOL_SWITCH = 24,                    /* SWITCH  */
  YYSYMBOL_CASE = 25,                      /* CASE  */
  YYSYMBOL_DEFAULT = 26,                   /* DEFAULT  */
  YYSYMBOL_WHILE = 27,                     /* WHILE  */
  YYSYMBOL_DO = 28,                        /* DO  */
  YYSYMBOL_FOR = 29,                       /* FOR  */
  YYSYMBOL_BREAK = 30,                     /* BREAK  */
  YYSYMBOL_TRUE = 31,                      /* TRUE  */
  YYSYMBOL_FALSE = 32,                     /* FALSE  */
  YYSYMBOL_PRINT = 33,                     /* PRINT  */
  YYSYMBOL_SQ_ANYCHAR_SQ = 34,             /* SQ_ANYCHAR_SQ  */
  YYSYMBOL_DQ_STRING_DQ = 35,              /* DQ_STRING_DQ  */
  YYSYMBOL_SEMICOLON = 36,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 37,                     /* COMMA  */
  YYSYMBOL_DOT = 38,                       /* DOT  */
  YYSYMBOL_QUESTION = 39,                  /* QUESTION  */
  YYSYMBOL_COLON = 40,                     /* COLON  */
  YYSYMBOL_DQ = 41,                        /* DQ  */
  YYSYMBOL_SQ = 42,                        /* SQ  */
  YYSYMBOL_ADD = 43,                       /* ADD  */
  YYSYMBOL_SUB = 44,                       /* SUB  */
  YYSYMBOL_MUL = 45,                       /* MUL  */
  YYSYMBOL_DIV = 46,                       /* DIV  */
  YYSYMBOL_MOD = 47,                       /* MOD  */
  YYSYMBOL_POW = 48,                       /* POW  */
  YYSYMBOL_LP = 49,                        /* LP  */
  YYSYMBOL_RP = 50,                        /* RP  */
  YYSYMBOL_LSB = 51,                       /* LSB  */
  YYSYMBOL_RSB = 52,                       /* RSB  */
  YYSYMBOL_LCB = 53,                       /* LCB  */
  YYSYMBOL_RCB = 54,                       /* RCB  */
  YYSYMBOL_ASSIGN = 55,                    /* ASSIGN  */
  YYSYMBOL_EQ = 56,                        /* EQ  */
  YYSYMBOL_NEQ = 57,                       /* NEQ  */
  YYSYMBOL_LT = 58,                        /* LT  */
  YYSYMBOL_GT = 59,                        /* GT  */
  YYSYMBOL_LE = 60,                        /* LE  */
  YYSYMBOL_GE = 61,                        /* GE  */
  YYSYMBOL_AND = 62,                       /* AND  */
  YYSYMBOL_OR = 63,                        /* OR  */
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
  YYSYMBOL_method_declaration = 98,        /* method_declaration  */
  YYSYMBOL_99_3 = 99,                      /* $@3  */
  YYSYMBOL_100_4 = 100,                    /* $@4  */
  YYSYMBOL_none_or_multiple_parameters = 101, /* none_or_multiple_parameters  */
  YYSYMBOL_parameters = 102,               /* parameters  */
  YYSYMBOL_parameter = 103,                /* parameter  */
  YYSYMBOL_method_body = 104,              /* method_body  */
  YYSYMBOL_statement = 105,                /* statement  */
  YYSYMBOL_assignment_statement = 106,     /* assignment_statement  */
  YYSYMBOL_method_call = 107,              /* method_call  */
  YYSYMBOL_none_or_multiple_arguments = 108, /* none_or_multiple_arguments  */
  YYSYMBOL_arguments = 109,                /* arguments  */
  YYSYMBOL_if_statement = 110,             /* if_statement  */
  YYSYMBOL_if_elif_parenthesis_statement = 111, /* if_elif_parenthesis_statement  */
  YYSYMBOL_none_or_multiple_elif = 112,    /* none_or_multiple_elif  */
  YYSYMBOL_none_or_one_else = 113,         /* none_or_one_else  */
  YYSYMBOL_do_while_statement = 114,       /* do_while_statement  */
  YYSYMBOL_for_statement = 115,            /* for_statement  */
  YYSYMBOL_first_and_third_loop_statement = 116, /* first_and_third_loop_statement  */
  YYSYMBOL_second_loop_statement = 117,    /* second_loop_statement  */
  YYSYMBOL_switch_statement = 118,         /* switch_statement  */
  YYSYMBOL_default_case = 119,             /* default_case  */
  YYSYMBOL_one_or_more_cases = 120,        /* one_or_more_cases  */
  YYSYMBOL_multiple_cases = 121,           /* multiple_cases  */
  YYSYMBOL_cases = 122,                    /* cases  */
  YYSYMBOL_case_expression = 123,          /* case_expression  */
  YYSYMBOL_return_statement = 124,         /* return_statement  */
  YYSYMBOL_break_statement = 125,          /* break_statement  */
  YYSYMBOL_print_statement = 126,          /* print_statement  */
  YYSYMBOL_single_or_multiple_variables = 127, /* single_or_multiple_variables  */
  YYSYMBOL_exp = 128,                      /* exp  */
  YYSYMBOL_factor = 129,                   /* factor  */
  YYSYMBOL_term = 130,                     /* term  */
  YYSYMBOL_relational_exp = 131,           /* relational_exp  */
  YYSYMBOL_relational_factor = 132,        /* relational_factor  */
  YYSYMBOL_logical_term = 133,             /* logical_term  */
  YYSYMBOL_unary = 134,                    /* unary  */
  YYSYMBOL_primary = 135,                  /* primary  */
  YYSYMBOL_object_creation = 136,          /* object_creation  */
  YYSYMBOL_137_5 = 137,                    /* $@5  */
  YYSYMBOL_member_access = 138,            /* member_access  */
  YYSYMBOL_139_6 = 139,                    /* $@6  */
  YYSYMBOL_member_access_body = 140,       /* member_access_body  */
  YYSYMBOL_access_modifier = 141,          /* access_modifier  */
  YYSYMBOL_boolean = 142,                  /* boolean  */
  YYSYMBOL_data_type = 143,                /* data_type  */
  YYSYMBOL_none_or_newlines = 144          /* none_or_newlines  */
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
#define YYFINAL  107
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   791

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  80
/* YYNRULES -- Number of rules.  */
#define YYNRULES  202
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  490

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
       0,   210,   210,   211,   212,   215,   215,   216,   216,   219,
     220,   221,   224,   225,   226,   227,   228,   229,   232,   233,
     236,   237,   240,   241,   244,   245,   248,   249,   252,   253,
     257,   258,   259,   260,   261,   262,   263,   264,   267,   268,
     271,   272,   275,   276,   279,   280,   283,   284,   287,   288,
     291,   292,   295,   296,   299,   300,   301,   302,   303,   304,
     305,   306,   309,   310,   313,   314,   317,   318,   321,   322,
     325,   326,   329,   330,   333,   334,   337,   338,   342,   343,
     344,   345,   346,   350,   354,   354,   355,   355,   358,   359,
     362,   363,   366,   369,   370,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   392,   393,   397,   400,   401,   402,   405,   406,
     407,   410,   413,   414,   415,   416,   417,   420,   421,   424,
     425,   428,   429,   432,   435,   436,   437,   440,   441,   444,
     445,   448,   449,   452,   455,   456,   459,   462,   463,   466,
     467,   468,   471,   474,   477,   478,   481,   482,   483,   486,
     487,   488,   489,   492,   493,   496,   497,   498,   499,   500,
     501,   502,   505,   506,   507,   510,   511,   514,   515,   516,
     519,   520,   521,   522,   525,   525,   528,   528,   531,   532,
     535,   536,   539,   540,   543,   544,   545,   546,   547,   548,
     549,   552,   553
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
  "CLASS_ID", "ANY_CHARACTER", "DOUBLE_CONST", "VAR", "NEWLINE", "CLASS",
  "PUBLIC", "PRIVATE", "INTEGER", "CHAR", "DOUBLE", "BOOLEAN", "STRING",
  "VOID", "NEW", "RETURN", "IF", "ELIF", "ELSE", "SWITCH", "CASE",
  "DEFAULT", "WHILE", "DO", "FOR", "BREAK", "TRUE", "FALSE", "PRINT",
  "SQ_ANYCHAR_SQ", "DQ_STRING_DQ", "SEMICOLON", "COMMA", "DOT", "QUESTION",
  "COLON", "DQ", "SQ", "ADD", "SUB", "MUL", "DIV", "MOD", "POW", "LP",
  "RP", "LSB", "RSB", "LCB", "RCB", "ASSIGN", "EQ", "NEQ", "LT", "GT",
  "LE", "GE", "AND", "OR", "NOT", "$accept", "program",
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
  "variable_declaration", "variable_reference", "method_declaration",
  "$@3", "$@4", "none_or_multiple_parameters", "parameters", "parameter",
  "method_body", "statement", "assignment_statement", "method_call",
  "none_or_multiple_arguments", "arguments", "if_statement",
  "if_elif_parenthesis_statement", "none_or_multiple_elif",
  "none_or_one_else", "do_while_statement", "for_statement",
  "first_and_third_loop_statement", "second_loop_statement",
  "switch_statement", "default_case", "one_or_more_cases",
  "multiple_cases", "cases", "case_expression", "return_statement",
  "break_statement", "print_statement", "single_or_multiple_variables",
  "exp", "factor", "term", "relational_exp", "relational_factor",
  "logical_term", "unary", "primary", "object_creation", "$@5",
  "member_access", "$@6", "member_access_body", "access_modifier",
  "boolean", "data_type", "none_or_newlines", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-408)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-195)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     643,  -408,     5,    36,    44,    26,  -408,  -408,    72,    75,
      92,   101,   136,  -408,    38,    59,    62,   129,   154,   169,
     178,   199,    24,    24,    22,   151,   128,   228,  -408,  -408,
    -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,   219,
     221,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   220,   206,   233,   113,   134,  -408,   264,  -408,   228,
     228,   352,   294,   328,   228,   235,   213,    52,  -408,  -408,
    -408,  -408,   234,   104,  -408,  -408,   111,  -408,  -408,   124,
    -408,  -408,   130,  -408,  -408,   143,  -408,  -408,   287,   298,
     313,   239,  -408,   228,   228,   228,   228,  -408,   315,   228,
    -408,  -408,  -408,  -408,   107,   285,  -408,  -408,   228,   643,
     228,   228,   727,   643,   727,   727,   727,   727,   727,   727,
     727,   727,   228,   151,   151,   151,   151,   151,   151,   228,
      22,    22,    22,    22,    22,    22,    22,    22,   727,   727,
     346,  -408,  -408,   348,   310,     3,  -408,  -408,   276,   319,
     358,  -408,  -408,   327,   334,     8,   335,   140,   336,   355,
     372,    32,  -408,   373,   151,   382,   353,   385,   386,   387,
      53,   390,   375,  -408,  -408,  -408,    31,    34,   727,   232,
     383,   727,  -408,  -408,  -408,  -408,   727,   727,  -408,   367,
    -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,   727,
     206,   206,   233,   233,   233,  -408,   727,   134,  -408,   134,
     134,   134,   134,   134,  -408,  -408,  -408,  -408,   366,   374,
    -408,  -408,   228,  -408,  -408,  -408,  -408,  -408,   388,   388,
     228,   417,   422,   391,   425,   427,   428,   429,   433,   434,
     435,   404,  -408,   437,   407,   408,   228,   409,  -408,   311,
     412,  -408,   413,   414,  -408,   421,   424,  -408,   426,   430,
    -408,   431,     9,  -408,   228,   188,   161,  -408,   228,    60,
     228,   410,  -408,  -408,   436,   384,   458,   460,   419,  -408,
    -408,  -408,  -408,  -408,  -408,  -408,   228,  -408,   228,  -408,
    -408,   423,  -408,   416,  -408,   470,   420,  -408,   432,  -408,
     438,  -408,   439,  -408,   440,  -408,   441,  -408,  -408,   442,
     428,   429,   685,   472,   425,   422,   434,   427,   449,   450,
     451,   448,   228,    72,    75,    92,   101,   136,   452,   383,
     445,   228,   228,   301,   276,   447,   453,  -408,   473,   474,
     151,   443,   470,  -408,  -408,   228,   228,   228,   454,  -408,
    -408,  -408,  -408,  -408,   457,   461,   462,   459,    22,   151,
    -408,  -408,   685,   301,   228,   466,   388,   388,  -408,   465,
     287,   455,  -408,   685,   463,   685,   228,   228,   228,   469,
     468,   161,    20,   188,   228,   228,   456,   228,  -408,  -408,
    -408,   483,  -408,  -408,  -408,   727,   464,   464,   228,   228,
     467,   475,   471,   389,  -408,   228,    27,   228,   228,   228,
      22,   232,  -408,   476,   228,   466,   477,  -408,  -408,   480,
     496,   464,   496,   228,    41,   228,   228,   727,  -408,   228,
     228,   486,   228,  -408,   228,   228,   478,   482,   487,   727,
     228,   228,   501,   727,   228,   479,   464,   484,   491,   500,
     488,   228,   485,   727,   497,   228,  -408,   727,  -408,  -408,
    -408,  -408,  -408,   228,   493,  -408,  -408,    31,   517,  -408,
     727,  -408,   495,   499,  -408,   228,   502,   228,   494,   228,
     727,  -408,   727,   228,   228,   503,   504,  -408,   501,  -408
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,   180,    83,     0,     0,     0,   190,   191,     0,     0,
       0,     0,     0,   200,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   201,    78,    81,
      82,    54,    55,    56,    57,    58,    59,    60,    61,     0,
     181,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,     0,   156,   159,     0,   165,   172,   163,   177,   201,
     201,   194,     0,     0,   201,     0,     0,    28,    17,    35,
      36,    37,     0,    18,    12,    30,    22,    14,    32,    24,
      15,    33,    26,    16,    34,    20,    13,    31,    83,   181,
       0,     0,   163,   201,   201,   201,   201,   152,     0,   201,
      83,   181,   178,   179,     0,     0,   176,     1,   201,     2,
     201,   201,    95,     2,    95,    95,    95,    95,    95,    95,
      95,    95,   201,     0,     0,     0,     0,     0,     0,   201,
       0,     0,     0,     0,     0,     0,     0,     0,    95,    95,
       0,    79,    80,     0,     0,     0,   189,   186,   115,    68,
       0,   192,   193,    66,    64,   181,    74,    62,    70,     0,
       0,     0,     7,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   150,   151,   149,     0,     0,    95,   134,
     154,    95,   182,   183,   202,     3,    95,    95,   108,   194,
       4,    96,    97,    98,    99,   100,   101,   102,   103,    95,
     157,   158,   160,   161,   162,   164,    95,   166,   175,   167,
     168,   169,   170,   171,   173,   174,   109,   111,     0,     0,
      86,   188,   201,   195,   196,   197,   198,   199,   118,   118,
     201,     0,     0,    76,     0,     0,     0,     0,     0,     0,
       0,    28,    29,     0,    48,    50,   201,    18,    19,    38,
      22,    23,    42,    24,    25,    44,    26,    27,    46,    20,
      21,    40,   181,   125,   201,   122,   123,   126,   201,   201,
     201,     0,   136,   135,     0,     0,     0,     0,     0,   106,
     107,   110,   104,   105,     5,    84,   201,   187,   201,   117,
     116,     0,    92,     0,    69,     0,     0,    67,     0,    65,
       0,    73,     0,    75,     0,    63,     0,    71,   184,    52,
       0,     0,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   201,     0,     0,     0,     0,     0,     0,   154,
       0,   201,   201,    88,     0,     0,     0,    77,     0,     0,
       0,     0,     0,    49,    51,   201,   201,   201,     0,    39,
      43,    45,    47,    41,     0,     0,     0,     0,   137,     0,
     155,   153,     9,    88,   201,    90,   118,   118,   114,     0,
       0,     0,    53,     9,     0,     9,   201,   201,   201,     0,
       0,   138,   181,   112,   201,   201,     0,   201,    89,   120,
     119,     0,    10,     8,    11,    95,     0,     0,   201,   201,
       0,     0,     0,   194,   185,   201,     0,   201,   201,   201,
       0,   134,     6,     0,   201,    90,     0,   147,   148,     0,
     141,   144,   141,   181,   201,   201,   201,    93,    91,   201,
     201,     0,   201,   143,   201,   201,     0,     0,     0,    93,
     201,   201,   127,    95,   201,     0,   144,     0,     0,     0,
       0,   201,     0,    93,     0,   201,   146,    95,   140,   145,
     139,   132,   131,   201,     0,    87,    94,     0,   129,   142,
      95,    85,     0,     0,   121,   201,     0,   201,     0,   201,
      95,   133,    95,   201,   201,     0,     0,   130,   127,   128
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -408,    79,    33,  -408,  -408,  -171,   -52,   322,   320,   325,
     392,   380,   394,   -46,   243,  -225,  -220,  -224,  -228,  -217,
    -221,  -275,  -408,   323,  -408,  -408,  -408,  -408,  -408,  -408,
    -408,  -178,    -1,  -408,  -408,  -408,   197,   147,  -145,  -407,
       0,  -408,    -8,  -408,  -222,  -408,    96,    78,  -408,  -408,
    -408,   156,  -408,  -408,   148,   171,   123,  -374,  -408,  -408,
    -408,  -408,   247,   -12,   162,   146,   -20,   283,   160,   176,
     307,  -408,  -408,  -408,  -408,  -408,    49,   -60,    45,   166
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    26,   345,   331,   246,   346,    28,    74,    86,    77,
      80,    83,    68,    29,    75,    87,    78,    81,    84,    69,
      70,    71,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,   332,   286,   364,   388,   365,   440,
     347,   273,    43,   230,   289,    44,   264,   455,   474,    45,
      46,   274,   380,    47,   432,   407,   433,   408,   419,    48,
      49,    50,   278,    51,    52,    53,    54,    55,    56,    57,
      58,    59,   341,    60,   222,   147,   189,   267,    62,   109
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,   272,    91,   229,   105,   158,    90,   290,   294,   141,
     299,   307,   104,    89,   297,   142,   303,   -72,  -124,   301,
     337,   101,   101,   101,   101,     1,   100,     1,   100,  -113,
     417,    72,   451,    27,     1,    88,    88,     1,   100,   221,
      66,     1,    88,    63,   -72,   236,   466,   434,    67,    61,
     108,   243,    64,   157,    64,   146,  -113,   156,   -72,  -124,
      65,   418,   151,   152,   155,    22,    23,   372,   268,   108,
    -113,    24,   434,    24,    22,    23,    73,    22,    23,    76,
      24,    22,    23,    24,   151,   152,    25,    24,   352,   160,
     344,   351,   353,   343,   350,    25,    79,   130,   131,   132,
     133,   134,   135,   123,   124,    82,   143,   161,    93,    42,
     258,    94,   188,    42,   191,   192,   193,   194,   195,   196,
     197,   198,   101,   101,   101,   101,   101,   101,   107,   101,
     101,   101,   101,   101,   101,   101,   101,   141,   216,   217,
      85,   163,    27,   142,   389,   390,    27,   228,   165,   129,
     123,   124,   249,   245,     1,   100,   266,   182,    61,   164,
     244,   167,    61,   101,   265,   269,   166,   169,   263,   130,
     131,   132,   133,   134,   135,   262,   101,   238,   270,   168,
     171,   279,    95,   123,   124,   170,   280,   281,   185,   367,
      92,   384,   190,   231,    22,    23,   136,   137,   172,   282,
      24,   106,   392,    96,   394,    97,   283,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   130,   131,   132,
     133,   134,   135,   141,   276,   138,   139,    98,   275,   142,
     148,   123,   124,   272,   143,    99,   271,   108,     1,    88,
       4,    92,   149,     6,     7,     8,     9,    10,    11,    12,
      13,   125,   126,   127,   150,   110,   122,   111,   415,   176,
     177,   178,   179,   123,   124,   181,   151,   152,   159,   153,
     154,   202,   203,   204,   184,   175,   186,   187,    22,    23,
     100,   128,   123,   124,    24,   200,   201,   162,   199,   223,
     224,   225,   226,   227,    13,   206,   214,   215,   144,    92,
      92,    92,    92,    92,   205,  -194,   208,   208,   208,   208,
     208,   208,   208,   208,   223,   224,   225,   226,   227,    13,
    -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,   157,   102,
     103,   245,   145,   366,   173,   183,    64,   244,   381,   101,
      92,   130,   131,   132,   133,   134,   135,   383,   313,   174,
     180,   218,   219,    92,   123,   124,   232,   101,   382,   220,
       4,    61,   140,   233,   234,     8,     9,    10,    11,    12,
      13,   235,   237,   239,   240,     4,   241,   247,   231,   231,
       8,     9,    10,    11,    12,    13,   250,   252,   287,   253,
     424,   256,     4,   255,   259,   405,   291,   323,   324,   325,
     326,   327,   223,   224,   225,   226,   227,    13,   231,   423,
     261,    61,   312,   207,   209,   210,   211,   212,   213,   284,
     277,   292,    61,   285,    61,   288,   293,   441,   295,   296,
     318,   298,   300,   302,   319,   320,   321,   304,   306,   441,
     308,   160,   309,   456,   310,   311,   163,   266,   231,   165,
     314,   167,   333,   441,   334,   265,   276,   469,   315,   263,
     275,   169,   328,   316,   329,    65,   262,   171,   317,   330,
     475,   168,   322,   335,   336,   166,   348,   100,   370,   342,
     483,   361,   484,   368,   243,   248,   379,   172,   358,   406,
     251,   260,   371,   338,   339,   340,   170,   362,   363,   354,
     355,   356,   357,   387,   399,   391,   402,   359,   369,   164,
     376,   373,   374,   375,   377,   378,    92,   393,   398,   404,
     430,   412,   431,   454,   414,   413,   444,   461,   448,   426,
     386,   429,   449,   458,   208,    92,   462,   450,   460,   465,
     473,   463,   395,   396,   397,   476,   467,   471,   481,   257,
     400,   401,   477,   403,   242,   479,   349,   487,   488,   254,
     385,   305,   428,   472,   410,   411,   489,   425,   409,   459,
     435,   416,     0,   420,   421,   422,   360,     0,     0,     0,
     427,     0,     0,     0,     0,     0,   208,     0,     0,   436,
     437,   438,   439,     0,     0,   442,   443,     0,   445,     0,
     446,   447,     0,     0,     0,     0,   452,   453,     0,     0,
     457,     0,     0,     0,     0,     0,     0,   464,     0,     0,
       0,   468,     0,     0,     0,     0,     0,     0,     0,   470,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   478,     0,   480,     0,   482,     1,     2,     3,   485,
     486,     4,   -95,     5,     6,     7,     8,     9,    10,    11,
      12,    13,     0,    14,    15,     0,     0,    16,     0,     0,
       0,    17,    18,    19,     0,     0,    20,     0,    21,     0,
       0,     0,     0,     0,     0,     0,    22,    23,     1,     2,
       3,     0,    24,     4,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,     0,    14,    15,    25,     0,    16,
       0,     0,     0,    17,    18,    19,     0,     0,    20,     0,
      21,     0,     0,     0,     0,     0,     0,     0,    22,    23,
       1,     2,     3,     0,    24,     4,     0,     0,     6,     7,
       8,     9,    10,    11,    12,    13,     0,    14,    15,    25,
       0,    16,     0,     0,     0,    17,    18,    19,     0,     0,
      20,     0,    21,     0,     0,     0,     0,     0,     0,     0,
      22,    23,     0,     0,     0,     0,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25
};

static const yytype_int16 yycheck[] =
{
       0,   179,    14,   148,    24,    65,    14,   229,   232,    61,
     235,   239,    24,    14,   234,    61,   237,     9,     9,   236,
     295,    22,    23,    24,    25,     3,     4,     3,     4,     9,
       3,     5,   439,     0,     3,     4,     4,     3,     4,    36,
       4,     3,     4,    38,    36,    37,   453,   421,     4,     0,
       9,    19,    49,    65,    49,    63,    36,    65,    50,    50,
      55,    34,    31,    32,    65,    43,    44,   342,    34,     9,
      50,    49,   446,    49,    43,    44,     4,    43,    44,     4,
      49,    43,    44,    49,    31,    32,    64,    49,   316,    37,
     311,   315,   317,   310,   314,    64,     4,    56,    57,    58,
      59,    60,    61,    43,    44,     4,    61,    55,    49,   109,
     170,    49,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   123,   124,   125,   126,   127,   128,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   189,   138,   139,
       4,    37,   109,   189,   366,   367,   113,   148,    37,    36,
      43,    44,   164,   161,     3,     4,   176,    50,   109,    55,
     161,    37,   113,   164,   176,   177,    55,    37,   176,    56,
      57,    58,    59,    60,    61,   176,   177,    37,   178,    55,
      37,   181,    53,    43,    44,    55,   186,   187,   109,   334,
      14,   362,   113,   148,    43,    44,    62,    63,    55,   199,
      49,    25,   373,    49,   375,    36,   206,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    56,    57,    58,
      59,    60,    61,   275,   179,    59,    60,    49,   179,   275,
      64,    43,    44,   411,   189,    36,     4,     9,     3,     4,
       8,    65,     7,    11,    12,    13,    14,    15,    16,    17,
      18,    45,    46,    47,    19,    36,    36,    36,   403,    93,
      94,    95,    96,    43,    44,    99,    31,    32,    55,    34,
      35,   125,   126,   127,   108,    36,   110,   111,    43,    44,
       4,    48,    43,    44,    49,   123,   124,    53,   122,    13,
      14,    15,    16,    17,    18,   129,   136,   137,     4,   123,
     124,   125,   126,   127,   128,     4,   130,   131,   132,   133,
     134,   135,   136,   137,    13,    14,    15,    16,    17,    18,
      56,    57,    58,    59,    60,    61,    62,    63,   340,    22,
      23,   339,     4,   334,    36,    50,    49,   338,   358,   340,
     164,    56,    57,    58,    59,    60,    61,   359,    37,    36,
      35,     5,     4,   177,    43,    44,    37,   358,   359,    49,
       8,   312,    10,     5,    37,    13,    14,    15,    16,    17,
      18,    37,    37,    37,    19,     8,     4,     4,   333,   334,
      13,    14,    15,    16,    17,    18,     4,    34,   222,     4,
     410,     4,     8,     7,     4,   395,   230,    13,    14,    15,
      16,    17,    13,    14,    15,    16,    17,    18,   363,   410,
      35,   362,   246,   130,   131,   132,   133,   134,   135,    53,
      37,     4,   373,    49,   375,    37,     4,   427,    37,     4,
     264,     4,     4,     4,   268,   269,   270,     4,     4,   439,
       5,    37,     5,   443,    37,    37,    37,   467,   403,    37,
      37,    37,   286,   453,   288,   467,   411,   457,    37,   467,
     411,    37,     4,    37,     4,    55,   467,    37,    37,    50,
     470,    55,    36,    50,     4,    55,     4,     4,     4,    37,
     480,    36,   482,    36,    19,   163,    27,    55,   322,    25,
     165,   171,    49,    55,    55,    55,    55,   331,   332,    50,
      50,    50,    54,    37,    36,    50,    50,    55,    55,    55,
      53,   345,   346,   347,    53,    53,   340,    54,    49,    36,
      40,    54,    26,    22,    53,    50,    40,    36,    50,    53,
     364,    54,    50,    54,   358,   359,    36,    50,    54,    54,
      23,    53,   376,   377,   378,    50,    49,    54,    54,   169,
     384,   385,    53,   387,   160,    53,   313,    54,    54,   167,
     363,   238,   415,   467,   398,   399,   488,   411,   397,   446,
     422,   405,    -1,   407,   408,   409,   329,    -1,    -1,    -1,
     414,    -1,    -1,    -1,    -1,    -1,   410,    -1,    -1,   423,
     424,   425,   426,    -1,    -1,   429,   430,    -1,   432,    -1,
     434,   435,    -1,    -1,    -1,    -1,   440,   441,    -1,    -1,
     444,    -1,    -1,    -1,    -1,    -1,    -1,   451,    -1,    -1,
      -1,   455,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   463,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   475,    -1,   477,    -1,   479,     3,     4,     5,   483,
     484,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,    20,    21,    -1,    -1,    24,    -1,    -1,
      -1,    28,    29,    30,    -1,    -1,    33,    -1,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,     3,     4,
       5,    -1,    49,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    -1,    20,    21,    64,    -1,    24,
      -1,    -1,    -1,    28,    29,    30,    -1,    -1,    33,    -1,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
       3,     4,     5,    -1,    49,     8,    -1,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    20,    21,    64,
      -1,    24,    -1,    -1,    -1,    28,    29,    30,    -1,    -1,
      33,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     8,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    20,    21,    24,    28,    29,    30,
      33,    35,    43,    44,    49,    64,    66,    67,    71,    78,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,   105,   107,   110,   114,   115,   118,   124,   125,
     126,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     138,   141,   143,    38,    49,    55,     4,     4,    77,    84,
      85,    86,     5,     4,    72,    79,     4,    74,    81,     4,
      75,    82,     4,    76,    83,     4,    73,    80,     4,    97,
     107,   128,   134,    49,    49,    53,    49,    36,    49,    36,
       4,    97,   135,   135,   128,   131,   134,     0,     9,   144,
      36,    36,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,    36,    43,    44,    45,    46,    47,    48,    36,
      56,    57,    58,    59,    60,    61,    62,    63,   144,   144,
      10,    71,    78,   143,     4,     4,   107,   140,   144,     7,
      19,    31,    32,    34,    35,    97,   107,   128,   142,    55,
      37,    55,    53,    37,    55,    37,    55,    37,    55,    37,
      55,    37,    55,    36,    36,    36,   144,   144,   144,   144,
      35,   144,    50,    50,   144,    66,   144,   144,   105,   141,
      66,   105,   105,   105,   105,   105,   105,   105,   105,   144,
     129,   129,   130,   130,   130,   134,   144,   132,   134,   132,
     132,   132,   132,   132,   133,   133,   105,   105,     5,     4,
      49,    36,   139,    13,    14,    15,    16,    17,    97,   103,
     108,   143,    37,     5,    37,    37,    37,    37,    37,    37,
      19,     4,    77,    19,    97,   107,    69,     4,    72,   128,
       4,    74,    34,     4,    75,     7,     4,    76,   142,     4,
      73,    35,    97,   107,   111,   128,   131,   142,    34,   128,
     105,     4,    96,   106,   116,   141,   143,    37,   127,   105,
     105,   105,   105,   105,    53,    49,   100,   144,    37,   109,
     109,   144,     4,     4,    82,    37,     4,    81,     4,    80,
       4,    84,     4,    85,     4,    88,     4,    83,     5,     5,
      37,    37,   144,    37,    37,    37,    37,    37,   144,   144,
     144,   144,    36,    13,    14,    15,    16,    17,     4,     4,
      50,    68,    99,   144,   144,    50,     4,    86,    55,    55,
      55,   137,    37,    84,    85,    67,    70,   105,     4,    79,
      81,    82,    83,    80,    50,    50,    50,    54,   144,    55,
     127,    36,   144,   144,   101,   103,    97,   103,    36,    55,
       4,    49,    86,   144,   144,   144,    53,    53,    53,    27,
     117,   131,    97,   128,    70,   101,   144,    37,   102,   109,
     109,    50,    70,    54,    70,   144,   144,   144,    49,    36,
     144,   144,    50,   144,    36,   105,    25,   120,   122,   120,
     144,   144,    54,    50,    53,   103,   144,     3,    34,   123,
     144,   144,   144,    97,   131,   116,    53,   144,   102,    54,
      40,    26,   119,   121,   122,   119,   144,   144,   144,   144,
     104,   105,   144,   144,    40,   144,   144,   144,    50,    50,
      50,   104,   144,   144,    22,   112,   105,   144,    54,   121,
      54,    36,    36,    53,   144,    54,   104,    49,   144,   105,
     144,    54,   111,    23,   113,   105,    50,    53,   144,    53,
     144,    54,   144,   105,   105,   144,   144,    54,    54,   112
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
      96,    96,    96,    97,    99,    98,   100,    98,   101,   101,
     102,   102,   103,   104,   104,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   106,   106,   107,   108,   108,   108,   109,   109,
     109,   110,   111,   111,   111,   111,   111,   112,   112,   113,
     113,   114,   114,   115,   116,   116,   116,   117,   117,   118,
     118,   119,   119,   120,   121,   121,   122,   123,   123,   124,
     124,   124,   125,   126,   127,   127,   128,   128,   128,   129,
     129,   129,   129,   130,   130,   131,   131,   131,   131,   131,
     131,   131,   132,   132,   132,   133,   133,   134,   134,   134,
     135,   135,   135,   135,   137,   136,   139,   138,   140,   140,
     141,   141,   142,   142,   143,   143,   143,   143,   143,   143,
     143,   144,   144
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
       2,     1,     1,     1,     0,    14,     0,    13,     0,     2,
       0,     4,     2,     0,     3,     0,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     4,     4,     4,     3,     3,
       4,     3,     4,     4,     7,     0,     2,     2,     0,     4,
       4,    15,     1,     1,     1,     1,     1,     0,    10,     0,
       6,    13,    13,    17,     0,     1,     1,     0,     1,    13,
      13,     0,     4,     3,     0,     3,     5,     1,     1,     3,
       3,     3,     2,     6,     0,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     3,     1,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     1,     2,     1,     2,     2,
       1,     1,     3,     3,     0,     9,     0,     5,     2,     1,
       1,     1,     1,     1,     0,     1,     1,     1,     1,     1,
       1,     0,     2
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
#line 215 "project.y"
                                                      { increaseScope(); addSymbol((yyvsp[-1].sval), "class", false, true, true); }
#line 1754 "project.tab.c"
    break;

  case 6: /* class_declaration: access_modifier CLASS CLASS_ID LCB $@1 none_or_newlines class_body none_or_newlines RCB  */
#line 215 "project.y"
                                                                                                                                                                       { decreaseScope(); }
#line 1760 "project.tab.c"
    break;

  case 7: /* $@2: %empty  */
#line 216 "project.y"
                         { increaseScope(); addSymbol((yyvsp[-1].sval), "class", false, true, true); }
#line 1766 "project.tab.c"
    break;

  case 8: /* class_declaration: CLASS CLASS_ID LCB $@2 none_or_newlines class_body none_or_newlines RCB  */
#line 216 "project.y"
                                                                                                                                          { decreaseScope(); }
#line 1772 "project.tab.c"
    break;

  case 18: /* identifier_list_int: ID  */
#line 232 "project.y"
                        { addSymbol((yyvsp[0].sval), "int", false, false, false); }
#line 1778 "project.tab.c"
    break;

  case 19: /* identifier_list_int: ID COMMA identifier_list_int  */
#line 233 "project.y"
                                   { addSymbol((yyvsp[-2].sval), "int", false, false, false); }
#line 1784 "project.tab.c"
    break;

  case 20: /* identifier_list_string: ID  */
#line 236 "project.y"
                           { addSymbol((yyvsp[0].sval), "string", false, false, false); }
#line 1790 "project.tab.c"
    break;

  case 21: /* identifier_list_string: ID COMMA identifier_list_string  */
#line 237 "project.y"
                                      { addSymbol((yyvsp[-2].sval), "string", false, false, false); }
#line 1796 "project.tab.c"
    break;

  case 22: /* identifier_list_char: ID  */
#line 240 "project.y"
                         { addSymbol((yyvsp[0].sval), "char", false, false, false); }
#line 1802 "project.tab.c"
    break;

  case 23: /* identifier_list_char: ID COMMA identifier_list_char  */
#line 241 "project.y"
                                    { addSymbol((yyvsp[-2].sval), "char", false, false, false); }
#line 1808 "project.tab.c"
    break;

  case 24: /* identifier_list_double: ID  */
#line 244 "project.y"
                           { addSymbol((yyvsp[0].sval), "double", false, false, false); }
#line 1814 "project.tab.c"
    break;

  case 25: /* identifier_list_double: ID COMMA identifier_list_double  */
#line 245 "project.y"
                                      { addSymbol((yyvsp[-2].sval), "double", false, false, false); }
#line 1820 "project.tab.c"
    break;

  case 26: /* identifier_list_boolean: ID  */
#line 248 "project.y"
                            { addSymbol((yyvsp[0].sval), "boolean", false, false, false); }
#line 1826 "project.tab.c"
    break;

  case 27: /* identifier_list_boolean: ID COMMA identifier_list_boolean  */
#line 249 "project.y"
                                       { addSymbol((yyvsp[-2].sval), "boolean", false, false, false); }
#line 1832 "project.tab.c"
    break;

  case 28: /* identifier_list_variable: ID  */
#line 252 "project.y"
                             { addSymbol((yyvsp[0].sval), "var", false, false, false); }
#line 1838 "project.tab.c"
    break;

  case 29: /* identifier_list_variable: ID COMMA identifier_list_variable  */
#line 253 "project.y"
                                        { addSymbol((yyvsp[-2].sval), "var", false, false, false); }
#line 1844 "project.tab.c"
    break;

  case 38: /* assignment_list_int: ID ASSIGN exp  */
#line 267 "project.y"
                                   { addSymbol((yyvsp[-2].sval), "int", false, true, false); }
#line 1850 "project.tab.c"
    break;

  case 39: /* assignment_list_int: ID ASSIGN exp COMMA assignment_list_int  */
#line 268 "project.y"
                                              { addSymbol((yyvsp[-4].sval), "int", false, true, false); }
#line 1856 "project.tab.c"
    break;

  case 40: /* assignment_list_string: ID ASSIGN DQ_STRING_DQ  */
#line 271 "project.y"
                                               { addSymbol((yyvsp[-2].sval), "string", false, true, false); }
#line 1862 "project.tab.c"
    break;

  case 41: /* assignment_list_string: ID ASSIGN DQ_STRING_DQ COMMA assignment_list_string  */
#line 272 "project.y"
                                                          { addSymbol((yyvsp[-4].sval), "string", false, true, false); }
#line 1868 "project.tab.c"
    break;

  case 42: /* assignment_list_char: ID ASSIGN SQ_ANYCHAR_SQ  */
#line 275 "project.y"
                                              { addSymbol((yyvsp[-2].sval), "char", false, true, false); }
#line 1874 "project.tab.c"
    break;

  case 43: /* assignment_list_char: ID ASSIGN SQ_ANYCHAR_SQ COMMA assignment_list_char  */
#line 276 "project.y"
                                                         { addSymbol((yyvsp[-4].sval), "char", false, true, false); }
#line 1880 "project.tab.c"
    break;

  case 44: /* assignment_list_double: ID ASSIGN DOUBLE_CONST  */
#line 279 "project.y"
                                               { addSymbol((yyvsp[-2].sval), "double", false, true, false); }
#line 1886 "project.tab.c"
    break;

  case 45: /* assignment_list_double: ID ASSIGN DOUBLE_CONST COMMA assignment_list_double  */
#line 280 "project.y"
                                                          { addSymbol((yyvsp[-4].sval), "double", false, true, false); }
#line 1892 "project.tab.c"
    break;

  case 46: /* assignment_list_boolean: ID ASSIGN boolean  */
#line 283 "project.y"
                                           { addSymbol((yyvsp[-2].sval), "boolean", false, true, false); }
#line 1898 "project.tab.c"
    break;

  case 47: /* assignment_list_boolean: ID ASSIGN boolean COMMA assignment_list_boolean  */
#line 284 "project.y"
                                                      { addSymbol((yyvsp[-4].sval), "boolean", false, true, false); }
#line 1904 "project.tab.c"
    break;

  case 48: /* assignment_list_variable: ID ASSIGN variable_reference  */
#line 287 "project.y"
                                                       { char* type = getType((yyvsp[0].sval)); addSymbol((yyvsp[-2].sval), type, false, true, false); }
#line 1910 "project.tab.c"
    break;

  case 49: /* assignment_list_variable: ID ASSIGN variable_reference COMMA assignment_list_variable  */
#line 288 "project.y"
                                                                  { char* type = getType((yyvsp[-2].sval)); addSymbol((yyvsp[-4].sval), type, false, true, false); }
#line 1916 "project.tab.c"
    break;

  case 50: /* assignment_list_method: ID ASSIGN method_call  */
#line 291 "project.y"
                                              { char* type = getType((yyvsp[0].sval)); addSymbol((yyvsp[-2].sval), type, false, true, false); }
#line 1922 "project.tab.c"
    break;

  case 51: /* assignment_list_method: ID ASSIGN method_call COMMA assignment_list_method  */
#line 292 "project.y"
                                                         { char* type = getType((yyvsp[-2].sval)); addSymbol((yyvsp[-4].sval), type, false, true, false); }
#line 1928 "project.tab.c"
    break;

  case 52: /* assignment_list_object: ID ASSIGN NEW CLASS_ID  */
#line 295 "project.y"
                                               { addSymbol((yyvsp[-3].sval), "class", false, true, false); }
#line 1934 "project.tab.c"
    break;

  case 53: /* assignment_list_object: ID ASSIGN NEW CLASS_ID COMMA assignment_list_object  */
#line 296 "project.y"
                                                          { addSymbol((yyvsp[-5].sval), "class", false, true, false); }
#line 1940 "project.tab.c"
    break;

  case 62: /* assignment_list_int_declared: ID ASSIGN exp  */
#line 309 "project.y"
                                            { char* type = getType((yyvsp[-2].sval)); if (type == NULL || strcmp(type, "int") != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-2].sval)); }
#line 1946 "project.tab.c"
    break;

  case 63: /* assignment_list_int_declared: ID ASSIGN exp COMMA assignment_list_int_declared  */
#line 310 "project.y"
                                                       { char* type = getType((yyvsp[-4].sval)); if (type == NULL || strcmp(type, "int") != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-4].sval)); }
#line 1952 "project.tab.c"
    break;

  case 64: /* assignment_list_string_declared: ID ASSIGN DQ_STRING_DQ  */
#line 313 "project.y"
                                                        { char* type = getType((yyvsp[-2].sval)); if (type == NULL || strcmp(type, "string") != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-2].sval)); }
#line 1958 "project.tab.c"
    break;

  case 65: /* assignment_list_string_declared: ID ASSIGN DQ_STRING_DQ COMMA assignment_list_string  */
#line 314 "project.y"
                                                          { char* type = getType((yyvsp[-4].sval)); if (type == NULL || strcmp(type, "string") != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-4].sval)); }
#line 1964 "project.tab.c"
    break;

  case 66: /* assignment_list_char_declared: ID ASSIGN SQ_ANYCHAR_SQ  */
#line 317 "project.y"
                                                       { char* type = getType((yyvsp[-2].sval)); if (type == NULL || strcmp(type, "char") != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-2].sval)); }
#line 1970 "project.tab.c"
    break;

  case 67: /* assignment_list_char_declared: ID ASSIGN SQ_ANYCHAR_SQ COMMA assignment_list_char  */
#line 318 "project.y"
                                                         { char* type = getType((yyvsp[-4].sval)); if (type == NULL || strcmp(type, "char") != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-4].sval)); }
#line 1976 "project.tab.c"
    break;

  case 68: /* assignment_list_double_declared: ID ASSIGN DOUBLE_CONST  */
#line 321 "project.y"
                                                        { char* type = getType((yyvsp[-2].sval)); if (type == NULL || strcmp(type, "double") != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-2].sval)); }
#line 1982 "project.tab.c"
    break;

  case 69: /* assignment_list_double_declared: ID ASSIGN DOUBLE_CONST COMMA assignment_list_double  */
#line 322 "project.y"
                                                          { char* type = getType((yyvsp[-4].sval)); if (type == NULL || strcmp(type, "double") != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-4].sval)); }
#line 1988 "project.tab.c"
    break;

  case 70: /* assignment_list_boolean_declared: ID ASSIGN boolean  */
#line 325 "project.y"
                                                    { char* type = getType((yyvsp[-2].sval)); if (type == NULL || strcmp(type, "boolean") != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-2].sval)); }
#line 1994 "project.tab.c"
    break;

  case 71: /* assignment_list_boolean_declared: ID ASSIGN boolean COMMA assignment_list_boolean  */
#line 326 "project.y"
                                                      { char* type = getType((yyvsp[-4].sval)); if (type == NULL || strcmp(type, "boolean") != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-4].sval)); }
#line 2000 "project.tab.c"
    break;

  case 72: /* assignment_list_variable_declared: ID ASSIGN variable_reference  */
#line 329 "project.y"
                                                                { char* type = getType((yyvsp[-2].sval)); if (type == NULL || strcmp(type, getType((yyvsp[0].sval))) != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-2].sval)); }
#line 2006 "project.tab.c"
    break;

  case 73: /* assignment_list_variable_declared: ID ASSIGN variable_reference COMMA assignment_list_variable  */
#line 330 "project.y"
                                                                  { char* type = getType((yyvsp[-4].sval)); if (type == NULL || strcmp(type, getType((yyvsp[-2].sval))) != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-4].sval)); }
#line 2012 "project.tab.c"
    break;

  case 74: /* assignment_list_method_declared: ID ASSIGN method_call  */
#line 333 "project.y"
                                                       { char* type = getType((yyvsp[-2].sval)); if (type == NULL || strcmp(type, getType((yyvsp[0].sval))) != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-2].sval)); }
#line 2018 "project.tab.c"
    break;

  case 75: /* assignment_list_method_declared: ID ASSIGN method_call COMMA assignment_list_method  */
#line 334 "project.y"
                                                         { char* type = getType((yyvsp[-4].sval)); if (type == NULL || strcmp(type, getType((yyvsp[-2].sval))) != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-4].sval)); }
#line 2024 "project.tab.c"
    break;

  case 76: /* assignment_list_object_declared: ID ASSIGN NEW CLASS_ID  */
#line 337 "project.y"
                                                        { char* type = getType((yyvsp[-3].sval)); if (type == NULL || strcmp(type, (yyvsp[0].sval)) != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-3].sval)); }
#line 2030 "project.tab.c"
    break;

  case 77: /* assignment_list_object_declared: ID ASSIGN NEW CLASS_ID COMMA assignment_list_object  */
#line 338 "project.y"
                                                          { char* type = getType((yyvsp[-5].sval)); if (type == NULL || strcmp(type, (yyvsp[-2].sval)) != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-5].sval)); }
#line 2036 "project.tab.c"
    break;

  case 83: /* variable_reference: ID  */
#line 350 "project.y"
                       { if (!symbolExists((yyvsp[0].sval), false, false)) { yyerror("Variable not declared"); } else if (!isInitialized((yyvsp[0].sval))) { yyerror("Variable not initialized"); } }
#line 2042 "project.tab.c"
    break;

  case 84: /* $@3: %empty  */
#line 354 "project.y"
                                                    { increaseScope(); }
#line 2048 "project.tab.c"
    break;

  case 85: /* method_declaration: access_modifier data_type ID LP $@3 none_or_newlines none_or_multiple_parameters none_or_newlines RP LCB none_or_newlines method_body none_or_newlines RCB  */
#line 354 "project.y"
                                                                                                                                                                                                { addSymbol("sum", (yyvsp[-12].sval), true, true, false); decreaseScope(); }
#line 2054 "project.tab.c"
    break;

  case 86: /* $@4: %empty  */
#line 355 "project.y"
                      { increaseScope(); }
#line 2060 "project.tab.c"
    break;

  case 87: /* method_declaration: data_type ID LP $@4 none_or_newlines none_or_multiple_parameters none_or_newlines RP LCB none_or_newlines method_body none_or_newlines RCB  */
#line 355 "project.y"
                                                                                                                                                                  { addSymbol((yyvsp[-11].sval), (yyvsp[-12].sval), true, true, false); decreaseScope(); }
#line 2066 "project.tab.c"
    break;

  case 92: /* parameter: data_type ID  */
#line 366 "project.y"
                        { addSymbol((yyvsp[0].sval), (yyvsp[-1].sval), false, true, false); }
#line 2072 "project.tab.c"
    break;

  case 114: /* method_call: ID LP none_or_newlines none_or_multiple_arguments none_or_newlines RP SEMICOLON  */
#line 397 "project.y"
                                                                                             { if (!symbolExists((yyvsp[-6].sval), true, false)) { yyerror("Method not declared"); } }
#line 2078 "project.tab.c"
    break;

  case 155: /* single_or_multiple_variables: COMMA ID single_or_multiple_variables  */
#line 478 "project.y"
                                            { if (!symbolExists((yyvsp[-1].sval), false, false)) { yyerror("Variable not declared"); } else if (!isInitialized((yyvsp[-1].sval))) { yyerror("Variable not initialized"); } }
#line 2084 "project.tab.c"
    break;

  case 184: /* $@5: %empty  */
#line 525 "project.y"
                                                 { if (!classExists((yyvsp[-4].sval))) { yyerror("Class not declared"); } }
#line 2090 "project.tab.c"
    break;

  case 186: /* $@6: %empty  */
#line 528 "project.y"
                                         { if (!symbolExists((yyvsp[-2].sval), false, true)) { yyerror("Class not declared"); } if (!symbolExists((yyvsp[0].sval), false, false)) { yyerror("Member not declared"); } }
#line 2096 "project.tab.c"
    break;

  case 188: /* member_access_body: ID SEMICOLON  */
#line 531 "project.y"
                                 { if (!symbolExists((yyvsp[-1].sval), false, false)) { yyerror("Variable not declared"); } }
#line 2102 "project.tab.c"
    break;

  case 189: /* member_access_body: method_call  */
#line 532 "project.y"
                  { if (!symbolExists((yyvsp[0].sval), true, false)) { yyerror("Method not declared"); } }
#line 2108 "project.tab.c"
    break;

  case 194: /* data_type: %empty  */
#line 543 "project.y"
                         { (yyval.sval) = ""; }
#line 2114 "project.tab.c"
    break;

  case 195: /* data_type: INTEGER  */
#line 544 "project.y"
              { (yyval.sval) = "int"; }
#line 2120 "project.tab.c"
    break;

  case 196: /* data_type: CHAR  */
#line 545 "project.y"
           { (yyval.sval) = "char"; }
#line 2126 "project.tab.c"
    break;

  case 197: /* data_type: DOUBLE  */
#line 546 "project.y"
             { (yyval.sval) = "double"; }
#line 2132 "project.tab.c"
    break;

  case 198: /* data_type: BOOLEAN  */
#line 547 "project.y"
              { (yyval.sval) = "boolean"; }
#line 2138 "project.tab.c"
    break;

  case 199: /* data_type: STRING  */
#line 548 "project.y"
             { (yyval.sval) = "string"; }
#line 2144 "project.tab.c"
    break;

  case 200: /* data_type: VOID  */
#line 549 "project.y"
           { (yyval.sval) = "void"; }
#line 2150 "project.tab.c"
    break;


#line 2154 "project.tab.c"

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

#line 556 "project.y"


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
