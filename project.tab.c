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

struct error {
    int line;
    char *message;
    char *token;
};

struct error errorTable[1000];
int errorCount = 0;

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
        yyerror("Null pointer in addSymbol function\n");
    }

    // Check for duplicate symbol in the current scope
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0 && symbolTable[i].scope == scope) {
            yyerror("Duplicate symbol declared in the current scope\n");
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
}

// Function to check if a symbol is in the symbol table
bool symbolExists(char *name, bool isMethod, bool isClass) {
    if (name == NULL) {
        yyerror("Null pointer in symbolExists function\n");
    }
    for (int i = 0; i < symbolCount; i++) {
        if (symbolTable[i].name != NULL && strcmp(symbolTable[i].name, name) == 0 && symbolTable[i].isMethod == isMethod && symbolTable[i].isClass == isClass && symbolTable[i].scope <= scope) {
            return true;
        }
    }
    return false;
}


// Function to check if a class is defined
bool classExists(char *name) {
    if (name == NULL) {
        yyerror("Null pointer in classExists function\n");
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
        yyerror("Null pointer in isInitialized function\n");
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
        yyerror("Null pointer in setInitialized function\n");
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
}

// Function to get the type of a variable
char* getType(char *name) {
    if (name == NULL) {
        yyerror("Null pointer in getType function\n");
    }
    for (int i = 0; i < symbolCount; i++) {
        if (symbolTable[i].name != NULL && strcmp(symbolTable[i].name, name) == 0 && symbolTable[i].scope <= scope) {
            return symbolTable[i].type;
        }
    }
    return NULL;
}

// Function to get the value of a variable
char* getValue(char *name) {
    if (name == NULL) {
        yyerror("Null pointer in getValue function\n");
    }
    for (int i = 0; i < symbolCount; i++) {
        if (symbolTable[i].name != NULL && strcmp(symbolTable[i].name, name) == 0 && symbolTable[i].scope <= scope) {
            return symbolTable[i].value;
        }
    }
    return NULL;
}


#line 226 "project.tab.c"

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
  YYSYMBOL_LCB = 41,                       /* LCB  */
  YYSYMBOL_RCB = 42,                       /* RCB  */
  YYSYMBOL_ASSIGN = 43,                    /* ASSIGN  */
  YYSYMBOL_OR = 44,                        /* OR  */
  YYSYMBOL_AND = 45,                       /* AND  */
  YYSYMBOL_EQ = 46,                        /* EQ  */
  YYSYMBOL_NEQ = 47,                       /* NEQ  */
  YYSYMBOL_LT = 48,                        /* LT  */
  YYSYMBOL_LE = 49,                        /* LE  */
  YYSYMBOL_GT = 50,                        /* GT  */
  YYSYMBOL_GE = 51,                        /* GE  */
  YYSYMBOL_ADD = 52,                       /* ADD  */
  YYSYMBOL_SUB = 53,                       /* SUB  */
  YYSYMBOL_MUL = 54,                       /* MUL  */
  YYSYMBOL_DIV = 55,                       /* DIV  */
  YYSYMBOL_MOD = 56,                       /* MOD  */
  YYSYMBOL_POW = 57,                       /* POW  */
  YYSYMBOL_NOT = 58,                       /* NOT  */
  YYSYMBOL_YYACCEPT = 59,                  /* $accept  */
  YYSYMBOL_program = 60,                   /* program  */
  YYSYMBOL_class_declaration = 61,         /* class_declaration  */
  YYSYMBOL_62_1 = 62,                      /* $@1  */
  YYSYMBOL_63_2 = 63,                      /* $@2  */
  YYSYMBOL_class_body = 64,                /* class_body  */
  YYSYMBOL_identifier_list = 65,           /* identifier_list  */
  YYSYMBOL_identifier_list_int = 66,       /* identifier_list_int  */
  YYSYMBOL_identifier_list_string = 67,    /* identifier_list_string  */
  YYSYMBOL_identifier_list_char = 68,      /* identifier_list_char  */
  YYSYMBOL_identifier_list_double = 69,    /* identifier_list_double  */
  YYSYMBOL_identifier_list_boolean = 70,   /* identifier_list_boolean  */
  YYSYMBOL_identifier_list_variable = 71,  /* identifier_list_variable  */
  YYSYMBOL_assignment_list = 72,           /* assignment_list  */
  YYSYMBOL_assignment_list_int = 73,       /* assignment_list_int  */
  YYSYMBOL_assignment_list_string = 74,    /* assignment_list_string  */
  YYSYMBOL_assignment_list_char = 75,      /* assignment_list_char  */
  YYSYMBOL_assignment_list_double = 76,    /* assignment_list_double  */
  YYSYMBOL_assignment_list_boolean = 77,   /* assignment_list_boolean  */
  YYSYMBOL_assignment_list_variable = 78,  /* assignment_list_variable  */
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
  YYSYMBOL_variable_reference_int = 92,    /* variable_reference_int  */
  YYSYMBOL_variable_reference_double = 93, /* variable_reference_double  */
  YYSYMBOL_method_declaration = 94,        /* method_declaration  */
  YYSYMBOL_95_3 = 95,                      /* $@3  */
  YYSYMBOL_96_4 = 96,                      /* $@4  */
  YYSYMBOL_none_or_multiple_parameters = 97, /* none_or_multiple_parameters  */
  YYSYMBOL_parameters = 98,                /* parameters  */
  YYSYMBOL_parameter = 99,                 /* parameter  */
  YYSYMBOL_method_body = 100,              /* method_body  */
  YYSYMBOL_statement = 101,                /* statement  */
  YYSYMBOL_assignment_statement = 102,     /* assignment_statement  */
  YYSYMBOL_method_call = 103,              /* method_call  */
  YYSYMBOL_none_or_multiple_arguments = 104, /* none_or_multiple_arguments  */
  YYSYMBOL_arguments = 105,                /* arguments  */
  YYSYMBOL_if_statement = 106,             /* if_statement  */
  YYSYMBOL_if_elif_parenthesis_statement = 107, /* if_elif_parenthesis_statement  */
  YYSYMBOL_none_or_multiple_elif = 108,    /* none_or_multiple_elif  */
  YYSYMBOL_none_or_one_else = 109,         /* none_or_one_else  */
  YYSYMBOL_do_while_statement = 110,       /* do_while_statement  */
  YYSYMBOL_for_statement = 111,            /* for_statement  */
  YYSYMBOL_first_and_third_loop_statement = 112, /* first_and_third_loop_statement  */
  YYSYMBOL_second_loop_statement = 113,    /* second_loop_statement  */
  YYSYMBOL_switch_statement = 114,         /* switch_statement  */
  YYSYMBOL_default_case = 115,             /* default_case  */
  YYSYMBOL_one_or_more_cases = 116,        /* one_or_more_cases  */
  YYSYMBOL_multiple_cases = 117,           /* multiple_cases  */
  YYSYMBOL_cases = 118,                    /* cases  */
  YYSYMBOL_case_expression = 119,          /* case_expression  */
  YYSYMBOL_return_statement = 120,         /* return_statement  */
  YYSYMBOL_break_statement = 121,          /* break_statement  */
  YYSYMBOL_print_statement = 122,          /* print_statement  */
  YYSYMBOL_single_or_multiple_variables = 123, /* single_or_multiple_variables  */
  YYSYMBOL_exp = 124,                      /* exp  */
  YYSYMBOL_exp_int = 125,                  /* exp_int  */
  YYSYMBOL_term_int = 126,                 /* term_int  */
  YYSYMBOL_factor_int = 127,               /* factor_int  */
  YYSYMBOL_exp_double = 128,               /* exp_double  */
  YYSYMBOL_term_double = 129,              /* term_double  */
  YYSYMBOL_factor_double = 130,            /* factor_double  */
  YYSYMBOL_relational_exp = 131,           /* relational_exp  */
  YYSYMBOL_relational_factor = 132,        /* relational_factor  */
  YYSYMBOL_logical_term = 133,             /* logical_term  */
  YYSYMBOL_unary = 134,                    /* unary  */
  YYSYMBOL_primary_int = 135,              /* primary_int  */
  YYSYMBOL_primary_double = 136,           /* primary_double  */
  YYSYMBOL_object_creation = 137,          /* object_creation  */
  YYSYMBOL_138_5 = 138,                    /* $@5  */
  YYSYMBOL_member_access = 139,            /* member_access  */
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
#define YYFINAL  120
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   701

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  86
/* YYNRULES -- Number of rules.  */
#define YYNRULES  218
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  505

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   313


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
      55,    56,    57,    58
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   218,   218,   219,   220,   221,   224,   224,   228,   228,
     234,   235,   236,   239,   240,   241,   242,   243,   244,   247,
     248,   251,   252,   255,   256,   259,   260,   263,   264,   267,
     268,   271,   272,   273,   274,   275,   276,   277,   278,   281,
     287,   293,   294,   297,   298,   301,   307,   314,   315,   318,
     323,   329,   333,   338,   339,   342,   343,   344,   345,   346,
     347,   348,   349,   352,   363,   375,   383,   392,   400,   409,
     420,   432,   440,   449,   458,   468,   476,   485,   493,   502,
     503,   504,   505,   506,   509,   519,   529,   539,   539,   549,
     549,   560,   561,   564,   565,   568,   571,   572,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   594,   595,   598,   604,   605,
     606,   609,   610,   611,   614,   617,   618,   619,   620,   621,
     624,   625,   628,   629,   632,   633,   636,   639,   640,   641,
     644,   645,   648,   649,   652,   653,   656,   659,   660,   663,
     666,   667,   670,   671,   672,   675,   678,   681,   682,   690,
     691,   695,   696,   697,   700,   701,   702,   709,   716,   724,
     725,   729,   730,   731,   734,   735,   736,   743,   750,   758,
     759,   763,   764,   765,   766,   767,   768,   769,   772,   773,
     774,   777,   778,   779,   782,   783,   784,   788,   789,   794,
     795,   798,   798,   807,   816,   821,   827,   828,   831,   832,
     835,   836,   837,   838,   839,   840,   841,   844,   845
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
  "LCB", "RCB", "ASSIGN", "OR", "AND", "EQ", "NEQ", "LT", "LE", "GT", "GE",
  "ADD", "SUB", "MUL", "DIV", "MOD", "POW", "NOT", "$accept", "program",
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
  "member_access", "member_access_body", "access_modifier", "boolean",
  "data_type", "none_or_newlines", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-447)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-211)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     504,    33,  -447,   223,     7,  -447,    25,    48,    89,  -447,
    -447,    87,    93,   102,   127,   177,  -447,    17,    79,   152,
     153,   157,   174,   172,    28,    38,    38,    43,   225,   232,
    -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,
    -447,   218,   222,  -447,  -447,  -447,   232,  -447,  -447,  -447,
    -447,  -447,  -447,  -447,  -447,   230,   155,   184,  -447,   199,
     231,  -447,   137,   226,  -447,  -447,   500,  -447,  -447,  -447,
     462,   251,   504,   271,   232,   241,   236,  -447,   119,  -447,
    -447,  -447,  -447,   248,   120,  -447,  -447,   146,  -447,  -447,
     163,  -447,  -447,   187,  -447,  -447,   220,  -447,  -447,    94,
      34,   261,   273,   276,  -447,   232,   232,   232,   232,  -447,
     298,  -447,    75,    84,   254,  -447,  -447,  -447,  -447,  -447,
    -447,   232,   504,  -447,  -447,   504,  -447,    45,    45,    45,
      45,    45,    45,    29,    29,    29,    29,    29,    29,  -447,
      50,    50,    50,    50,    50,    50,    50,    50,   307,  -447,
    -447,   319,   288,  -447,    40,  -447,   232,   217,   292,   293,
     326,  -447,  -447,   296,   297,    86,   114,   301,   320,   335,
      35,  -447,   337,    45,   339,   338,   340,    29,   353,   249,
     354,   351,  -447,  -447,  -447,    12,    23,   606,   370,   325,
    -447,  -447,  -447,  -447,  -447,  -447,    45,   184,   184,  -447,
    -447,  -447,  -447,  -447,    29,   231,   231,  -447,  -447,  -447,
    -447,    50,   226,   226,   226,   226,   226,   226,  -447,  -447,
     321,   324,  -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,
    -447,   329,   329,   232,   363,   371,   372,   342,   376,   386,
     387,   392,   395,   400,   364,  -447,   367,   410,   382,   383,
     232,   384,  -447,   123,   385,  -447,   388,   393,  -447,   125,
     397,  -447,   398,   401,  -447,   402,  -447,  -447,   232,  -447,
     549,  -447,   232,   232,   232,   474,   379,  -447,  -447,   396,
     355,   424,   426,   399,  -447,  -447,   232,   232,  -447,  -447,
     406,  -447,   404,  -447,   407,  -447,   432,   409,  -447,   412,
    -447,   413,  -447,   414,  -447,   415,  -447,  -447,   428,   458,
     464,   555,   465,   468,   471,   480,   481,   446,   447,   455,
     457,   232,    87,    93,   102,   127,   177,   463,   325,   466,
     232,   232,   394,   217,   476,   493,   516,   484,  -447,   524,
     526,    45,    29,   249,   492,   528,   494,  -447,   496,  -447,
     232,   232,   232,   497,  -447,   498,  -447,   499,  -447,   509,
    -447,   510,  -447,   495,   513,   514,   537,    50,   110,  -447,
    -447,   555,   394,   232,   539,   329,   329,  -447,   558,   367,
     541,   536,  -447,   524,   526,   555,   540,   555,   232,   232,
     232,   544,   552,   549,    26,  -447,  -447,   232,   232,   548,
     232,  -447,  -447,  -447,   556,   570,  -447,  -447,  -447,   606,
     566,   566,   232,   232,   551,   576,   585,   587,  -447,   232,
     144,   232,   232,   232,    68,   370,  -447,   588,   232,   539,
     575,  -447,  -447,   592,   605,   566,   605,    77,   232,    95,
     232,   232,   606,  -447,   232,   232,   595,   232,  -447,   232,
     232,   594,   598,   599,   606,   232,   232,   618,   606,   232,
     600,   566,   601,   609,   617,   612,   232,   613,   606,   615,
     232,  -447,   606,  -447,  -447,  -447,  -447,  -447,   232,   614,
    -447,  -447,    12,   633,  -447,   606,  -447,   620,   621,  -447,
     232,   622,   232,   619,   232,   606,  -447,   606,   232,   232,
     623,   624,  -447,   618,  -447
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,   197,    85,     0,   199,     0,     0,     0,   206,
     207,     0,     0,     0,     0,     0,   216,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   217,
      79,    82,    83,    55,    56,    57,    58,    59,    60,    61,
      62,     0,     0,   198,   200,   111,   217,    99,   100,   101,
     102,   103,   104,   105,   106,     0,   159,   161,   164,   160,
     171,   174,     0,   181,   188,   191,   169,   179,   112,   114,
     210,     0,     0,     0,   217,     0,     0,   109,    29,    18,
      36,    37,    38,     0,    19,    13,    31,    23,    15,    33,
      25,    16,    34,    27,    17,    35,    21,    14,    32,    85,
       0,     0,     0,     0,   169,   217,   217,   217,   217,   155,
       0,    85,     0,     0,     0,    85,   195,   196,   192,   194,
       1,   217,     0,   110,   113,     0,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    80,
      81,     0,     0,     5,     0,   205,   217,   118,    67,    65,
       0,   208,   209,    73,    75,    63,    69,    71,     0,     0,
       0,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   153,   154,   152,     0,     0,    98,   137,   157,
     170,   180,   193,   218,     3,     4,     0,   162,   163,   165,
     166,   167,   168,    86,     0,   172,   173,   175,   176,   177,
     178,     0,   182,   183,   184,   186,   185,   187,   190,   189,
       0,     0,    89,   204,   203,    84,   211,   212,   213,   214,
     215,   121,   121,   217,     0,     0,     0,    77,     0,     0,
       0,     0,     0,     0,    29,    30,    84,     0,    49,    51,
     217,    19,    20,    39,    23,    24,    43,    25,    26,    45,
      27,    28,    47,    21,    22,    41,   127,   128,   217,   125,
     126,   129,   217,   217,   217,   210,     0,   139,   138,     0,
       0,     0,     0,     0,     6,    87,   217,   217,   120,   119,
       0,    95,     0,    68,     0,    66,     0,     0,    74,     0,
      76,     0,    64,     0,    70,     0,    72,   201,    53,     0,
       0,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,     0,     0,     0,     0,     0,     0,   157,     0,
     217,   217,    91,     0,     0,     0,     0,     0,    78,     0,
       0,     0,     0,     0,     0,     0,     0,    50,     0,    52,
     217,   217,   217,     0,    40,     0,    44,     0,    46,     0,
      48,     0,    42,     0,     0,     0,     0,   140,     0,   158,
     156,    10,    91,   217,    93,   121,   121,   117,     0,     0,
       0,     0,    54,     0,     0,    10,     0,    10,   217,   217,
     217,     0,     0,   141,    85,   116,   115,   217,   217,     0,
     217,    92,   123,   122,     0,     0,    11,     9,    12,    98,
       0,     0,   217,   217,     0,     0,     0,   210,   202,   217,
       0,   217,   217,   217,     0,   137,     7,     0,   217,    93,
       0,   150,   151,     0,   144,   147,   144,    85,   217,   217,
     217,   217,    96,    94,   217,   217,     0,   217,   146,   217,
     217,     0,     0,     0,    96,   217,   217,   130,    98,   217,
       0,   147,     0,     0,     0,     0,   217,     0,    96,     0,
     217,   149,    98,   143,   148,   142,   135,   134,   217,     0,
      90,    97,     0,   132,   145,    98,    88,     0,     0,   124,
     217,     0,   217,     0,   217,    98,   136,    98,   217,   217,
       0,     0,   133,   130,   131
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -447,   -48,  -302,  -447,  -447,  -192,   -53,   501,   487,   502,
     503,   490,   505,   -51,   357,   356,   358,   361,   362,   369,
     360,   336,  -447,   440,   448,   450,   441,   444,   445,   449,
     391,  -182,   -17,  -447,  -447,  -447,  -447,  -447,   317,   262,
    -153,  -446,  -159,  -447,   -16,  -447,  -218,  -447,   208,   189,
    -447,  -447,  -447,   268,  -447,  -447,   258,   284,   235,  -342,
    -447,  -447,  -447,  -447,   373,   -15,     1,   165,   188,   -12,
     164,   212,   -21,   506,   168,   670,    73,  -447,  -447,  -447,
    -447,  -447,    10,  -172,   -65,     4
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    28,    29,   330,   250,   351,    30,    85,    97,    88,
      91,    94,    79,    31,    86,    98,    89,    92,    95,    80,
      81,    82,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,   331,   286,   373,   401,
     374,   455,    46,   278,    47,   233,   288,    48,   268,   470,
     489,    49,    50,   279,   392,    51,   447,   421,   448,   422,
     433,    52,    53,    54,   283,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   344,
      69,   156,   275,   167,    71,   122
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     101,   102,   103,   114,   232,   151,   277,   262,   466,   350,
      70,    76,   113,   271,   289,     2,    99,   149,     5,   150,
       2,    99,   481,     5,   153,   112,     2,   111,   274,     5,
     272,     2,   111,   203,     5,     5,   -84,     2,   111,   246,
       5,     2,   115,    72,   161,   162,     2,   115,     2,   115,
     125,    24,    78,     2,   115,   247,   100,   155,   163,   164,
      77,   -84,   100,   166,    25,    26,   -84,    24,   204,   350,
      27,     2,   437,   100,   194,   223,   165,   195,   157,    74,
      25,    26,    70,   350,   196,   350,    27,   -84,   113,   211,
     104,    84,   234,   449,    83,    25,    26,    87,   116,   117,
     119,   112,    25,    26,   -84,   121,    90,   211,    27,   185,
     186,   187,   188,     2,   394,   190,     5,   -84,   105,   449,
      25,    26,   240,   281,   191,   193,    27,   127,   128,   -84,
     -84,    93,    70,    74,   -84,    70,   133,   134,   127,   128,
     231,   140,   141,   142,   143,   144,   145,   431,   104,   100,
     241,   432,   352,   248,   249,   169,   172,   402,   403,   312,
     224,   314,   170,   173,   270,   259,   133,   134,   266,   267,
     269,   273,   139,   104,   253,   127,   128,   133,   134,   397,
     376,    96,   174,   140,   141,   142,   143,   144,   145,   175,
     114,   106,   113,   406,   107,   408,   108,   112,   280,   176,
     104,   104,   104,   104,   104,   104,   177,   127,   128,   109,
     151,   110,   352,   119,   119,   119,   119,   119,   119,   119,
     119,   225,   149,   178,   150,   120,   352,   149,   352,   150,
     179,   226,   227,   228,   229,   230,    16,   290,   129,   130,
     131,   132,   121,   277,     2,    99,   104,     5,   158,   159,
     419,   133,   134,   123,   311,   152,   180,   124,   -84,   104,
      73,   160,    74,   181,   429,   126,    75,   234,   234,   104,
     146,   147,   317,   161,   162,   154,   318,   319,   320,   168,
     100,   161,   162,   456,   119,   135,   136,   137,   138,   171,
     332,   333,   197,   198,   192,   456,   182,   205,   206,   471,
     140,   141,   142,   143,   144,   145,   189,   234,   183,   456,
     271,   184,   220,   484,   218,   219,   375,   199,   200,   201,
     202,    70,   163,   221,   164,   367,   490,   222,   235,   236,
     166,   237,   238,   239,   371,   372,   498,   242,   499,   244,
     243,   251,   165,   254,   257,   256,   393,   207,   208,   209,
     210,   395,   234,   396,   385,   386,   387,   260,   263,   265,
     281,   282,   284,   285,     7,   287,   248,   291,   249,   322,
     323,   324,   325,   326,   276,   292,   294,   399,   296,     7,
     297,    70,     9,    10,    11,    12,    13,    14,    15,    16,
     299,   301,   409,   410,   411,    70,   303,    70,  -210,   305,
     169,   414,   415,   439,   417,   307,    74,   438,   226,   227,
     228,   229,   230,    16,   104,   308,   424,   425,   309,   310,
     172,   174,    75,   430,   313,   434,   435,   436,   327,   176,
     328,   321,   442,   178,   315,   280,   337,   180,   316,   329,
     119,   104,   451,   452,   453,   454,   334,   335,   457,   458,
     336,   460,   339,   461,   462,   340,   341,   342,   343,   467,
     468,   270,   346,   472,   345,   266,   267,   269,   348,   353,
     479,     7,   355,   148,   483,   357,    11,    12,    13,    14,
      15,    16,   485,     7,   359,   361,   363,   364,    11,    12,
      13,    14,    15,    16,   493,   365,   495,   119,   497,   366,
     158,   370,   500,   501,    -2,     1,   368,     2,     3,     4,
       5,   377,     6,     7,   -98,     8,     9,    10,    11,    12,
      13,    14,    15,    16,   159,    17,    18,   378,   225,    19,
     379,   380,   381,    20,    21,    22,   388,   383,    23,   384,
     173,   175,   177,    24,  -194,  -194,  -194,  -194,  -194,  -194,
    -194,  -194,   179,   181,   389,   390,    25,    26,     2,     3,
       4,     5,    27,     6,     7,   391,     8,     9,    10,    11,
      12,    13,    14,    15,    16,   400,    17,    18,   160,   405,
      19,   404,   407,   412,    20,    21,    22,   413,   416,    23,
     247,   418,   420,   426,    24,   140,   141,   142,   143,   144,
     145,   226,   227,   228,   229,   230,    16,    25,    26,     2,
       3,     4,     5,    27,     6,     7,   427,   444,     9,    10,
      11,    12,    13,    14,    15,    16,   428,    17,    18,   441,
     445,    19,   446,   459,   463,    20,    21,    22,   464,   465,
      23,   469,   473,   475,   476,    24,   212,   213,   214,   215,
     216,   217,   477,   478,   482,   480,   486,   488,    25,    26,
     491,   496,   492,   494,    27,   502,   503,   264,   261,   354,
     349,   356,   362,   252,   245,   358,   255,   360,   347,   258,
     302,   382,   304,   298,   295,   293,   306,   338,   300,   398,
     487,   443,   504,   440,   450,   423,   474,   118,     0,     0,
       0,   369
};

static const yytype_int16 yycheck[] =
{
      17,    17,    17,    24,   157,    70,   188,   179,   454,   311,
       0,     4,    24,   185,   232,     3,     4,    70,     6,    70,
       3,     4,   468,     6,    72,    24,     3,     4,   187,     6,
       7,     3,     4,     4,     6,     6,    10,     3,     4,     4,
       6,     3,     4,    10,    32,    33,     3,     4,     3,     4,
      46,    39,     4,     3,     4,    20,    39,    73,    75,    75,
      35,    35,    39,    75,    52,    53,    40,    39,    39,   371,
      58,     3,     4,    39,   122,    35,    75,   125,    74,    39,
      52,    53,    72,   385,    39,   387,    58,    10,   100,    39,
      17,     4,   157,   435,     5,    52,    53,     4,    25,    26,
      27,   100,    52,    53,    10,    10,     4,    39,    58,   105,
     106,   107,   108,     3,     4,    40,     6,    40,    39,   461,
      52,    53,    36,   188,    40,   121,    58,    52,    53,    35,
      36,     4,   122,    39,    40,   125,    52,    53,    52,    53,
     157,    46,    47,    48,    49,    50,    51,     3,    75,    39,
      36,     7,   311,   170,   170,    36,    36,   375,   376,    36,
     156,    36,    43,    43,   185,   177,    52,    53,   185,   185,
     185,   186,    35,   100,   173,    52,    53,    52,    53,   371,
     333,     4,    36,    46,    47,    48,    49,    50,    51,    43,
     211,    39,   204,   385,    41,   387,    39,   196,   188,    36,
     127,   128,   129,   130,   131,   132,    43,    52,    53,    35,
     275,    39,   371,   140,   141,   142,   143,   144,   145,   146,
     147,     4,   275,    36,   275,     0,   385,   280,   387,   280,
      43,    14,    15,    16,    17,    18,    19,   233,    54,    55,
      56,    57,    10,   425,     3,     4,   173,     6,     7,     8,
     409,    52,    53,    35,   250,     4,    36,    35,    35,   186,
      37,    20,    39,    43,   417,    35,    43,   332,   333,   196,
      44,    45,   268,    32,    33,     4,   272,   273,   274,    43,
      39,    32,    33,   442,   211,    54,    55,    56,    57,    41,
     286,   287,   127,   128,    40,   454,    35,   133,   134,   458,
      46,    47,    48,    49,    50,    51,     8,   372,    35,   468,
     482,    35,     5,   472,   146,   147,   333,   129,   130,   131,
     132,   311,   339,     4,   340,   321,   485,    39,    36,    36,
     342,     5,    36,    36,   330,   331,   495,    36,   497,     4,
      20,     4,   341,     4,     4,     7,   367,   135,   136,   137,
     138,   368,   417,   368,   350,   351,   352,     4,     4,     8,
     425,    36,    41,    39,     9,    36,   383,     4,   384,    14,
      15,    16,    17,    18,     4,     4,     4,   373,    36,     9,
       4,   371,    12,    13,    14,    15,    16,    17,    18,    19,
       4,     4,   388,   389,   390,   385,     4,   387,     4,     4,
      36,   397,   398,   424,   400,     5,    39,   424,    14,    15,
      16,    17,    18,    19,   341,     5,   412,   413,    36,    36,
      36,    36,    43,   419,    36,   421,   422,   423,     4,    36,
       4,    35,   428,    36,    36,   425,     4,    36,    36,    40,
     367,   368,   438,   439,   440,   441,    40,    43,   444,   445,
      43,   447,    43,   449,   450,    43,    43,    43,    43,   455,
     456,   482,     4,   459,    36,   482,   482,   482,     4,     4,
     466,     9,     4,    11,   470,     4,    14,    15,    16,    17,
      18,    19,   478,     9,     4,     4,    40,    40,    14,    15,
      16,    17,    18,    19,   490,    40,   492,   424,   494,    42,
       7,    35,   498,   499,     0,     1,    43,     3,     4,     5,
       6,    35,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,     8,    21,    22,    43,     4,    25,
       4,    39,     4,    29,    30,    31,    41,    43,    34,    43,
      43,    43,    43,    39,    44,    45,    46,    47,    48,    49,
      50,    51,    43,    43,    41,    41,    52,    53,     3,     4,
       5,     6,    58,     8,     9,    28,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    36,    21,    22,    20,    43,
      25,    40,    42,    39,    29,    30,    31,    35,    40,    34,
      20,    35,    26,    42,    39,    46,    47,    48,    49,    50,
      51,    14,    15,    16,    17,    18,    19,    52,    53,     3,
       4,     5,     6,    58,     8,     9,    40,    42,    12,    13,
      14,    15,    16,    17,    18,    19,    41,    21,    22,    41,
      38,    25,    27,    38,    40,    29,    30,    31,    40,    40,
      34,    23,    42,    42,    35,    39,   140,   141,   142,   143,
     144,   145,    35,    41,    39,    42,    42,    24,    52,    53,
      40,    42,    41,    41,    58,    42,    42,   180,   178,   312,
     310,   313,   316,   172,   169,   314,   174,   315,   309,   176,
     240,   345,   241,   238,   236,   235,   242,   296,   239,   372,
     482,   429,   503,   425,   436,   411,   461,    27,    -1,    -1,
      -1,   328
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     8,     9,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    21,    22,    25,
      29,    30,    31,    34,    39,    52,    53,    58,    60,    61,
      65,    72,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,   101,   103,   106,   110,
     111,   114,   120,   121,   122,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   139,
     141,   143,    10,    37,    39,    43,     4,    35,     4,    71,
      78,    79,    80,     5,     4,    66,    73,     4,    68,    75,
       4,    69,    76,     4,    70,    77,     4,    67,    74,     4,
      39,    91,   103,   124,   135,    39,    39,    41,    39,    35,
      39,     4,   125,   128,   131,     4,   135,   135,   134,   135,
       0,    10,   144,    35,    35,   144,    35,    52,    53,    54,
      55,    56,    57,    52,    53,    54,    55,    56,    57,    35,
      46,    47,    48,    49,    50,    51,    44,    45,    11,    65,
      72,   143,     4,    60,     4,   103,   140,   144,     7,     8,
      20,    32,    33,    91,   103,   125,   128,   142,    43,    36,
      43,    41,    36,    43,    36,    43,    36,    43,    36,    43,
      36,    43,    35,    35,    35,   144,   144,   144,   144,     8,
      40,    40,    40,   144,    60,    60,    39,   126,   126,   127,
     127,   127,   127,     4,    39,   129,   129,   130,   130,   130,
     130,    39,   132,   132,   132,   132,   132,   132,   133,   133,
       5,     4,    39,    35,   144,     4,    14,    15,    16,    17,
      18,    91,    99,   104,   143,    36,    36,     5,    36,    36,
      36,    36,    36,    20,     4,    71,     4,    20,    91,   103,
      63,     4,    66,   125,     4,    68,     7,     4,    69,   128,
       4,    70,   142,     4,    67,     8,    91,   103,   107,   124,
     131,   142,     7,   124,   101,   141,     4,    90,   102,   112,
     141,   143,    36,   123,    41,    39,    96,    36,   105,   105,
     144,     4,     4,    84,     4,    83,    36,     4,    87,     4,
      88,     4,    82,     4,    85,     4,    86,     5,     5,    36,
      36,   144,    36,    36,    36,    36,    36,   144,   144,   144,
     144,    35,    14,    15,    16,    17,    18,     4,     4,    40,
      62,    95,   144,   144,    40,    43,    43,     4,    89,    43,
      43,    43,    43,    43,   138,    36,     4,    78,     4,    79,
      61,    64,   101,     4,    73,     4,    75,     4,    76,     4,
      77,     4,    74,    40,    40,    40,    42,   144,    43,   123,
      35,   144,   144,    97,    99,    91,    99,    35,    43,     4,
      39,     4,    80,    43,    43,   144,   144,   144,    41,    41,
      41,    28,   113,   131,     4,    91,   124,    64,    97,   144,
      36,    98,   105,   105,    40,    43,    64,    42,    64,   144,
     144,   144,    39,    35,   144,   144,    40,   144,    35,   101,
      26,   116,   118,   116,   144,   144,    42,    40,    41,    99,
     144,     3,     7,   119,   144,   144,   144,     4,    91,   131,
     112,    41,   144,    98,    42,    38,    27,   115,   117,   118,
     115,   144,   144,   144,   144,   100,   101,   144,   144,    38,
     144,   144,   144,    40,    40,    40,   100,   144,   144,    23,
     108,   101,   144,    42,   117,    42,    35,    35,    41,   144,
      42,   100,    39,   144,   101,   144,    42,   107,    24,   109,
     101,    40,    41,   144,    41,   144,    42,   144,   101,   101,
     144,   144,    42,    42,   108
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    60,    60,    60,    62,    61,    63,    61,
      64,    64,    64,    65,    65,    65,    65,    65,    65,    66,
      66,    67,    67,    68,    68,    69,    69,    70,    70,    71,
      71,    72,    72,    72,    72,    72,    72,    72,    72,    73,
      73,    74,    74,    75,    75,    76,    76,    77,    77,    78,
      78,    79,    79,    80,    80,    81,    81,    81,    81,    81,
      81,    81,    81,    82,    82,    83,    83,    84,    84,    85,
      85,    86,    86,    87,    87,    88,    88,    89,    89,    90,
      90,    90,    90,    90,    91,    92,    93,    95,    94,    96,
      94,    97,    97,    98,    98,    99,   100,   100,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   102,   102,   103,   104,   104,
     104,   105,   105,   105,   106,   107,   107,   107,   107,   107,
     108,   108,   109,   109,   110,   110,   111,   112,   112,   112,
     113,   113,   114,   114,   115,   115,   116,   117,   117,   118,
     119,   119,   120,   120,   120,   121,   122,   123,   123,   124,
     124,   125,   125,   125,   126,   126,   126,   126,   126,   127,
     127,   128,   128,   128,   129,   129,   129,   129,   129,   130,
     130,   131,   131,   131,   131,   131,   131,   131,   132,   132,
     132,   133,   133,   133,   134,   134,   134,   135,   135,   136,
     136,   138,   137,   139,   140,   140,   141,   141,   142,   142,
     143,   143,   143,   143,   143,   143,   143,   144,   144
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     3,     3,     0,     9,     0,     8,
       0,     3,     3,     2,     2,     2,     2,     2,     2,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     2,     2,     2,     2,     2,     2,     2,     2,     3,
       5,     3,     5,     3,     5,     3,     5,     3,     5,     3,
       5,     3,     5,     4,     6,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     5,     3,     5,     3,     5,     3,
       5,     3,     5,     3,     5,     3,     5,     4,     6,     1,
       2,     2,     1,     1,     1,     1,     1,     0,    14,     0,
      13,     0,     2,     0,     4,     2,     0,     3,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     1,     1,     2,     1,     4,     4,     7,     0,     2,
       2,     0,     4,     4,    15,     1,     1,     1,     1,     1,
       0,    10,     0,     6,    13,    13,    17,     0,     1,     1,
       0,     1,    13,    13,     0,     4,     3,     0,     3,     5,
       1,     1,     3,     3,     3,     2,     6,     0,     3,     1,
       1,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
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
  case 5: /* program: error NEWLINE program  */
#line 221 "project.y"
                            { yyerrok; }
#line 1752 "project.tab.c"
    break;

  case 6: /* $@1: %empty  */
#line 224 "project.y"
                                                      {
    addSymbol((yyvsp[-1].sval), "class", false, true, true, NULL);
    increaseScope();
    }
#line 1761 "project.tab.c"
    break;

  case 7: /* class_declaration: access_modifier CLASS CLASS_ID LCB $@1 none_or_newlines class_body none_or_newlines RCB  */
#line 227 "project.y"
                                                       { decreaseScope(); }
#line 1767 "project.tab.c"
    break;

  case 8: /* $@2: %empty  */
#line 228 "project.y"
                         {
    addSymbol((yyvsp[-1].sval), "class", false, true, true, NULL);
    increaseScope();
    }
#line 1776 "project.tab.c"
    break;

  case 9: /* class_declaration: CLASS CLASS_ID LCB $@2 none_or_newlines class_body none_or_newlines RCB  */
#line 231 "project.y"
                                                       { decreaseScope(); }
#line 1782 "project.tab.c"
    break;

  case 19: /* identifier_list_int: ID  */
#line 247 "project.y"
                        { addSymbol((yyvsp[0].sval), "int", false, false, false, NULL); }
#line 1788 "project.tab.c"
    break;

  case 20: /* identifier_list_int: ID COMMA identifier_list_int  */
#line 248 "project.y"
                                   { addSymbol((yyvsp[-2].sval), "int", false, false, false, NULL); }
#line 1794 "project.tab.c"
    break;

  case 21: /* identifier_list_string: ID  */
#line 251 "project.y"
                           { addSymbol((yyvsp[0].sval), "string", false, false, false, NULL); }
#line 1800 "project.tab.c"
    break;

  case 22: /* identifier_list_string: ID COMMA identifier_list_string  */
#line 252 "project.y"
                                      { addSymbol((yyvsp[-2].sval), "string", false, false, false, NULL); }
#line 1806 "project.tab.c"
    break;

  case 23: /* identifier_list_char: ID  */
#line 255 "project.y"
                         { addSymbol((yyvsp[0].sval), "char", false, false, false, NULL); }
#line 1812 "project.tab.c"
    break;

  case 24: /* identifier_list_char: ID COMMA identifier_list_char  */
#line 256 "project.y"
                                    { addSymbol((yyvsp[-2].sval), "char", false, false, false, NULL); }
#line 1818 "project.tab.c"
    break;

  case 25: /* identifier_list_double: ID  */
#line 259 "project.y"
                           { addSymbol((yyvsp[0].sval), "double", false, false, false, NULL); }
#line 1824 "project.tab.c"
    break;

  case 26: /* identifier_list_double: ID COMMA identifier_list_double  */
#line 260 "project.y"
                                      { addSymbol((yyvsp[-2].sval), "double", false, false, false, NULL); }
#line 1830 "project.tab.c"
    break;

  case 27: /* identifier_list_boolean: ID  */
#line 263 "project.y"
                            { addSymbol((yyvsp[0].sval), "boolean", false, false, false, NULL); }
#line 1836 "project.tab.c"
    break;

  case 28: /* identifier_list_boolean: ID COMMA identifier_list_boolean  */
#line 264 "project.y"
                                       { addSymbol((yyvsp[-2].sval), "boolean", false, false, false, NULL); }
#line 1842 "project.tab.c"
    break;

  case 29: /* identifier_list_variable: ID  */
#line 267 "project.y"
                             { addSymbol((yyvsp[0].sval), "var", false, false, false, NULL); }
#line 1848 "project.tab.c"
    break;

  case 30: /* identifier_list_variable: ID COMMA identifier_list_variable  */
#line 268 "project.y"
                                        { addSymbol((yyvsp[-2].sval), "var", false, false, false, NULL); }
#line 1854 "project.tab.c"
    break;

  case 39: /* assignment_list_int: ID ASSIGN exp_int  */
#line 281 "project.y"
                                       {
    char valueStr[32];
    sprintf(valueStr, "%d", (yyvsp[0].ival));
    addSymbol((yyvsp[-2].sval), "int", false, true, false, valueStr);
    printf("Variable %s assigned with value %d\n\n", (yyvsp[-2].sval), (yyvsp[0].ival));
    }
#line 1865 "project.tab.c"
    break;

  case 40: /* assignment_list_int: ID ASSIGN exp_int COMMA assignment_list_int  */
#line 287 "project.y"
                                                  {
    char valueStr[32]; sprintf(valueStr, "%d", (yyvsp[-2].ival));
    addSymbol((yyvsp[-4].sval), "int", false, true, false, valueStr);
    printf("Variable %s assigned with value %d\n\n", (yyvsp[-4].sval), (yyvsp[-2].ival));
    }
#line 1875 "project.tab.c"
    break;

  case 41: /* assignment_list_string: ID ASSIGN DQ_STRING_DQ  */
#line 293 "project.y"
                                               { addSymbol((yyvsp[-2].sval), "string", false, true, false, (yyvsp[0].sval)); }
#line 1881 "project.tab.c"
    break;

  case 42: /* assignment_list_string: ID ASSIGN DQ_STRING_DQ COMMA assignment_list_string  */
#line 294 "project.y"
                                                          { addSymbol((yyvsp[-4].sval), "string", false, true, false, (yyvsp[-2].sval)); }
#line 1887 "project.tab.c"
    break;

  case 43: /* assignment_list_char: ID ASSIGN SQ_ANYCHAR_SQ  */
#line 297 "project.y"
                                              { addSymbol((yyvsp[-2].sval), "char", false, true, false, (yyvsp[0].cval)); }
#line 1893 "project.tab.c"
    break;

  case 44: /* assignment_list_char: ID ASSIGN SQ_ANYCHAR_SQ COMMA assignment_list_char  */
#line 298 "project.y"
                                                         { addSymbol((yyvsp[-4].sval), "char", false, true, false, (yyvsp[-2].cval)); }
#line 1899 "project.tab.c"
    break;

  case 45: /* assignment_list_double: ID ASSIGN exp_double  */
#line 301 "project.y"
                                             {
    char valueStr[64];
    sprintf(valueStr, "%f", (yyvsp[0].dval));
    addSymbol((yyvsp[-2].sval), "double", false, true, false, valueStr);
    printf("Variable %s assigned with value %f\n\n", (yyvsp[-2].sval), (yyvsp[0].dval));
    }
#line 1910 "project.tab.c"
    break;

  case 46: /* assignment_list_double: ID ASSIGN exp_double COMMA assignment_list_double  */
#line 307 "project.y"
                                                        {
    char valueStr[64];
    sprintf(valueStr, "%f", (yyvsp[-2].dval));
    addSymbol((yyvsp[-4].sval), "double", false, true, false, valueStr);
    printf("Variable %s assigned with value %f\n\n", (yyvsp[-4].sval), (yyvsp[-2].dval));
    }
#line 1921 "project.tab.c"
    break;

  case 47: /* assignment_list_boolean: ID ASSIGN boolean  */
#line 314 "project.y"
                                           { addSymbol((yyvsp[-2].sval), "boolean", false, true, false, (yyvsp[0].sval)); }
#line 1927 "project.tab.c"
    break;

  case 48: /* assignment_list_boolean: ID ASSIGN boolean COMMA assignment_list_boolean  */
#line 315 "project.y"
                                                      { addSymbol((yyvsp[-4].sval), "boolean", false, true, false, (yyvsp[-2].sval)); }
#line 1933 "project.tab.c"
    break;

  case 49: /* assignment_list_variable: ID ASSIGN variable_reference  */
#line 318 "project.y"
                                                       {
    char* type = getType((yyvsp[0].sval));
    char* value = getValue((yyvsp[0].sval));
    addSymbol((yyvsp[-2].sval), type, false, true, false, value);
    }
#line 1943 "project.tab.c"
    break;

  case 50: /* assignment_list_variable: ID ASSIGN variable_reference COMMA assignment_list_variable  */
#line 323 "project.y"
                                                                  {
    char* type = getType((yyvsp[-2].sval));
    char* value = getValue((yyvsp[-2].sval));
    addSymbol((yyvsp[-4].sval), type, false, true, false, value);
    }
#line 1953 "project.tab.c"
    break;

  case 51: /* assignment_list_method: ID ASSIGN method_call  */
#line 329 "project.y"
                                              {
    char* type = getType((yyvsp[0].sval));
    addSymbol((yyvsp[-2].sval), type, false, true, false, NULL);
    }
#line 1962 "project.tab.c"
    break;

  case 52: /* assignment_list_method: ID ASSIGN method_call COMMA assignment_list_method  */
#line 333 "project.y"
                                                         {
    char* type = getType((yyvsp[-2].sval));
    addSymbol((yyvsp[-4].sval), type, false, true, false, NULL);
    }
#line 1971 "project.tab.c"
    break;

  case 53: /* assignment_list_object: ID ASSIGN NEW CLASS_ID  */
#line 338 "project.y"
                                               { addSymbol((yyvsp[-3].sval), "class", false, true, false, NULL); }
#line 1977 "project.tab.c"
    break;

  case 54: /* assignment_list_object: ID ASSIGN NEW CLASS_ID COMMA assignment_list_object  */
#line 339 "project.y"
                                                          { addSymbol((yyvsp[-5].sval), "class", false, true, false, NULL); }
#line 1983 "project.tab.c"
    break;

  case 63: /* assignment_list_int_declared: ID ASSIGN exp_int  */
#line 352 "project.y"
                                                {
    char* type = getType((yyvsp[-2].sval));
    if (type == NULL || strcmp(type, "int") != 0) {
        yyerror("Type mismatch");
    } else {
        char valueStr[32];
        sprintf(valueStr, "%d", (yyvsp[0].ival));
        setInitialized((yyvsp[-2].sval), valueStr);
        printf("Variable %s assigned with value %d\n\n", (yyvsp[-2].sval), (yyvsp[0].ival));
    }
    }
#line 1999 "project.tab.c"
    break;

  case 64: /* assignment_list_int_declared: ID ASSIGN exp_int COMMA assignment_list_int_declared  */
#line 363 "project.y"
                                                           {
    char* type = getType((yyvsp[-4].sval));
    if (type == NULL || strcmp(type, "int") != 0) {
        yyerror("Type mismatch");
    } else {
        char valueStr[32];
        sprintf(valueStr, "%d", (yyvsp[-2].ival));
        setInitialized((yyvsp[-4].sval), valueStr);
        printf("Variable %s assigned with value %d\n\n", (yyvsp[-4].sval), (yyvsp[-2].ival));
    }
    }
#line 2015 "project.tab.c"
    break;

  case 65: /* assignment_list_string_declared: ID ASSIGN DQ_STRING_DQ  */
#line 375 "project.y"
                                                        {
    char* type = getType((yyvsp[-2].sval));
    if (type == NULL || strcmp(type, "string") != 0) {
        yyerror("Type mismatch");
    } else {
        setInitialized((yyvsp[-2].sval), (yyvsp[0].sval));
    }
    }
#line 2028 "project.tab.c"
    break;

  case 66: /* assignment_list_string_declared: ID ASSIGN DQ_STRING_DQ COMMA assignment_list_string_declared  */
#line 383 "project.y"
                                                                   {
    char* type = getType((yyvsp[-4].sval));
    if (type == NULL || strcmp(type, "string") != 0) {
        yyerror("Type mismatch");
    } else {
        setInitialized((yyvsp[-4].sval), (yyvsp[-2].sval));
    }
    }
#line 2041 "project.tab.c"
    break;

  case 67: /* assignment_list_char_declared: ID ASSIGN SQ_ANYCHAR_SQ  */
#line 392 "project.y"
                                                       {
    char* type = getType((yyvsp[-2].sval));
    if (type == NULL || strcmp(type, "char") != 0) {
        yyerror("Type mismatch");
    } else {
        setInitialized((yyvsp[-2].sval), (yyvsp[0].cval));
    }
    }
#line 2054 "project.tab.c"
    break;

  case 68: /* assignment_list_char_declared: ID ASSIGN SQ_ANYCHAR_SQ COMMA assignment_list_char_declared  */
#line 400 "project.y"
                                                                  {
    char* type = getType((yyvsp[-4].sval));
    if (type == NULL || strcmp(type, "char") != 0) {
        yyerror("Type mismatch");
    } else {
        setInitialized((yyvsp[-4].sval), (yyvsp[-2].cval));
    }
    }
#line 2067 "project.tab.c"
    break;

  case 69: /* assignment_list_double_declared: ID ASSIGN exp_double  */
#line 409 "project.y"
                                                      {
    char* type = getType((yyvsp[-2].sval));
    if (type == NULL || strcmp(type, "double") != 0) {
        yyerror("Type mismatch");
    } else {
        char valueStr[64];
        sprintf(valueStr, "%f", (yyvsp[0].dval));
        setInitialized((yyvsp[-2].sval), valueStr);
        printf("Variable %s assigned with value %f\n\n", (yyvsp[-2].sval), (yyvsp[0].dval));
    }
    }
#line 2083 "project.tab.c"
    break;

  case 70: /* assignment_list_double_declared: ID ASSIGN exp_double COMMA assignment_list_double_declared  */
#line 420 "project.y"
                                                                 {
    char* type = getType((yyvsp[-4].sval));
    if (type == NULL || strcmp(type, "double") != 0) {
        yyerror("Type mismatch");
    } else {
        char valueStr[64];
        sprintf(valueStr, "%f", (yyvsp[-2].dval));
        setInitialized((yyvsp[-4].sval), valueStr);
        printf("Variable %s assigned with value %f\n\n", (yyvsp[-4].sval), (yyvsp[-2].dval));
    }
    }
#line 2099 "project.tab.c"
    break;

  case 71: /* assignment_list_boolean_declared: ID ASSIGN boolean  */
#line 432 "project.y"
                                                    {
    char* type = getType((yyvsp[-2].sval));
    if (type == NULL || strcmp(type, "boolean") != 0) {
        yyerror("Type mismatch");
    } else {
        setInitialized((yyvsp[-2].sval), (yyvsp[0].sval));
    }
    }
#line 2112 "project.tab.c"
    break;

  case 72: /* assignment_list_boolean_declared: ID ASSIGN boolean COMMA assignment_list_boolean_declared  */
#line 440 "project.y"
                                                               {
    char* type = getType((yyvsp[-4].sval));
    if (type == NULL || strcmp(type, "boolean") != 0) {
        yyerror("Type mismatch");
    } else {
        setInitialized((yyvsp[-4].sval), (yyvsp[-2].sval));
    }
    }
#line 2125 "project.tab.c"
    break;

  case 73: /* assignment_list_variable_declared: ID ASSIGN variable_reference  */
#line 449 "project.y"
                                                                {
    char* type = getType((yyvsp[-2].sval));
    char* value = getValue((yyvsp[0].sval));
    if (type == NULL || strcmp(type, getType((yyvsp[0].sval))) != 0) {
        yyerror("Type mismatch");
    } else {
        setInitialized((yyvsp[-2].sval), value);
    }
    }
#line 2139 "project.tab.c"
    break;

  case 74: /* assignment_list_variable_declared: ID ASSIGN variable_reference COMMA assignment_list_variable_declared  */
#line 458 "project.y"
                                                                           {
    char* type = getType((yyvsp[-4].sval));
    char* value = getValue((yyvsp[-2].sval));
    if (type == NULL || strcmp(type, getType((yyvsp[-2].sval))) != 0) {
        yyerror("Type mismatch");
    } else {
        setInitialized((yyvsp[-4].sval), value);
    }
    }
#line 2153 "project.tab.c"
    break;

  case 75: /* assignment_list_method_declared: ID ASSIGN method_call  */
#line 468 "project.y"
                                                       {
    char* type = getType((yyvsp[-2].sval));
    if (type == NULL || strcmp(type, getType((yyvsp[0].sval))) != 0) {
        yyerror("Type mismatch");
    } else {
        setInitialized((yyvsp[-2].sval), NULL);
    }
    }
#line 2166 "project.tab.c"
    break;

  case 76: /* assignment_list_method_declared: ID ASSIGN method_call COMMA assignment_list_method_declared  */
#line 476 "project.y"
                                                                  {
    char* type = getType((yyvsp[-4].sval));
    if (type == NULL || strcmp(type, getType((yyvsp[-2].sval))) != 0) {
        yyerror("Type mismatch");
    } else {
        setInitialized((yyvsp[-4].sval), NULL);
    }
    }
#line 2179 "project.tab.c"
    break;

  case 77: /* assignment_list_object_declared: ID ASSIGN NEW CLASS_ID  */
#line 485 "project.y"
                                                        {
    char* type = getType((yyvsp[-3].sval));
    if (type == NULL || strcmp(type, (yyvsp[0].sval)) != 0) {
        yyerror("Type mismatch");
    } else {
        setInitialized((yyvsp[-3].sval), NULL);
    }
    }
#line 2192 "project.tab.c"
    break;

  case 78: /* assignment_list_object_declared: ID ASSIGN NEW CLASS_ID COMMA assignment_list_object_declared  */
#line 493 "project.y"
                                                                   {
    char* type = getType((yyvsp[-5].sval));
    if (type == NULL || strcmp(type, (yyvsp[-2].sval)) != 0) {
        yyerror("Type mismatch");
    } else {
        setInitialized((yyvsp[-5].sval), NULL);
    }
    }
#line 2205 "project.tab.c"
    break;

  case 84: /* variable_reference: ID  */
#line 509 "project.y"
                       {
    if (!symbolExists((yyvsp[0].sval), false, false)) {
        yyerror("Variable not declared");
    } else if (!isInitialized((yyvsp[0].sval))) {
        yyerror("Variable not initialized");
    } else {
        (yyval.sval) = getValue((yyvsp[0].sval));
    }
    }
#line 2219 "project.tab.c"
    break;

  case 85: /* variable_reference_int: ID  */
#line 519 "project.y"
                           {
    if (!symbolExists((yyvsp[0].sval), false, false)) {
        yyerror("Variable not declared");
    } else if (!isInitialized((yyvsp[0].sval))) {
        yyerror("Variable not initialized");
    } else {
        (yyval.ival) = atoi(getValue((yyvsp[0].sval)));
    }
    }
#line 2233 "project.tab.c"
    break;

  case 86: /* variable_reference_double: ID  */
#line 529 "project.y"
                              {
    if (!symbolExists((yyvsp[0].sval), false, false)) {
        yyerror("Variable not declared");
    } else if (!isInitialized((yyvsp[0].sval))) {
        yyerror("Variable not initialized");
    } else {
        (yyval.dval) = atof(getValue((yyvsp[0].sval)));
    }
    }
#line 2247 "project.tab.c"
    break;

  case 87: /* $@3: %empty  */
#line 539 "project.y"
                                                    {
    if (!symbolExists((yyvsp[-1].sval), false, false)) {
        addSymbol((yyvsp[-1].sval), (yyvsp[-2].sval), true, true, false, NULL);
    } else {
        yyerror("Method already declared");
    }
    increaseScope();
    }
#line 2260 "project.tab.c"
    break;

  case 88: /* method_declaration: access_modifier data_type ID LP $@3 none_or_newlines none_or_multiple_parameters none_or_newlines RP LCB none_or_newlines method_body none_or_newlines RCB  */
#line 546 "project.y"
                                                                                                                             {
    decreaseScope();
    }
#line 2268 "project.tab.c"
    break;

  case 89: /* $@4: %empty  */
#line 549 "project.y"
                      {
    if (!symbolExists((yyvsp[-1].sval), false, false)) {
        addSymbol((yyvsp[-1].sval), (yyvsp[-2].sval), true, true, false, NULL);
    } else {
        yyerror("Method already declared");
    }
    increaseScope();
    }
#line 2281 "project.tab.c"
    break;

  case 90: /* method_declaration: data_type ID LP $@4 none_or_newlines none_or_multiple_parameters none_or_newlines RP LCB none_or_newlines method_body none_or_newlines RCB  */
#line 556 "project.y"
                                                                                                                             {
    decreaseScope();
    }
#line 2289 "project.tab.c"
    break;

  case 95: /* parameter: data_type ID  */
#line 568 "project.y"
                        { addSymbol((yyvsp[0].sval), (yyvsp[-1].sval), false, true, false, NULL); }
#line 2295 "project.tab.c"
    break;

  case 117: /* method_call: ID LP none_or_newlines none_or_multiple_arguments none_or_newlines RP SEMICOLON  */
#line 598 "project.y"
                                                                                             {
    if (!symbolExists((yyvsp[-6].sval), true, false)) {
        yyerror("Method not declared");
    }
    }
#line 2305 "project.tab.c"
    break;

  case 158: /* single_or_multiple_variables: COMMA ID single_or_multiple_variables  */
#line 682 "project.y"
                                            {
    if (!symbolExists((yyvsp[-1].sval), false, false)) {
        yyerror("Variable not declared");
    } else if (!isInitialized((yyvsp[-1].sval))) {
        yyerror("Variable not initialized");
    }
    }
#line 2317 "project.tab.c"
    break;

  case 161: /* exp_int: term_int  */
#line 695 "project.y"
                  { (yyval.ival) = (yyvsp[0].ival); }
#line 2323 "project.tab.c"
    break;

  case 162: /* exp_int: exp_int ADD term_int  */
#line 696 "project.y"
                           { (yyval.ival) = (yyvsp[-2].ival) + (yyvsp[0].ival); }
#line 2329 "project.tab.c"
    break;

  case 163: /* exp_int: exp_int SUB term_int  */
#line 697 "project.y"
                           { (yyval.ival) = (yyvsp[-2].ival) - (yyvsp[0].ival); }
#line 2335 "project.tab.c"
    break;

  case 164: /* term_int: factor_int  */
#line 700 "project.y"
                     { (yyval.ival) = (yyvsp[0].ival); }
#line 2341 "project.tab.c"
    break;

  case 165: /* term_int: term_int MUL factor_int  */
#line 701 "project.y"
                              { (yyval.ival) = (yyvsp[-2].ival) * (yyvsp[0].ival); }
#line 2347 "project.tab.c"
    break;

  case 166: /* term_int: term_int DIV factor_int  */
#line 702 "project.y"
                              {
    if ((yyvsp[0].ival) == 0) {
        yyerror("Division by zero");
    } else {
        (yyval.ival) = (yyvsp[-2].ival) / (yyvsp[0].ival);
    }
    }
#line 2359 "project.tab.c"
    break;

  case 167: /* term_int: term_int MOD factor_int  */
#line 709 "project.y"
                              {
    if ((yyvsp[0].ival) == 0) {
        yyerror("Division by zero");
    } else {
        (yyval.ival) = fmod((yyvsp[-2].ival), (yyvsp[0].ival));
    }
    }
#line 2371 "project.tab.c"
    break;

  case 168: /* term_int: term_int POW factor_int  */
#line 716 "project.y"
                              {
    if ((yyvsp[-2].ival) == 0 && (yyvsp[0].ival) == 0) {
        yyerror("Exponentiation by zero");
    } else {
        (yyval.ival) = pow((yyvsp[-2].ival), (yyvsp[0].ival));
    }
    }
#line 2383 "project.tab.c"
    break;

  case 169: /* factor_int: primary_int  */
#line 724 "project.y"
                        { (yyval.ival) = (yyvsp[0].ival); }
#line 2389 "project.tab.c"
    break;

  case 170: /* factor_int: LP exp_int RP  */
#line 725 "project.y"
                    { (yyval.ival) = (yyvsp[-1].ival); }
#line 2395 "project.tab.c"
    break;

  case 171: /* exp_double: term_double  */
#line 729 "project.y"
                        { (yyval.dval) = (yyvsp[0].dval); }
#line 2401 "project.tab.c"
    break;

  case 172: /* exp_double: exp_double ADD term_double  */
#line 730 "project.y"
                                 { (yyval.dval) = (yyvsp[-2].dval) + (yyvsp[0].dval); }
#line 2407 "project.tab.c"
    break;

  case 173: /* exp_double: exp_double SUB term_double  */
#line 731 "project.y"
                                 { (yyval.dval) = (yyvsp[-2].dval) - (yyvsp[0].dval); }
#line 2413 "project.tab.c"
    break;

  case 174: /* term_double: factor_double  */
#line 734 "project.y"
                           { (yyval.dval) = (yyvsp[0].dval); }
#line 2419 "project.tab.c"
    break;

  case 175: /* term_double: term_double MUL factor_double  */
#line 735 "project.y"
                                    { (yyval.dval) = (yyvsp[-2].dval) * (yyvsp[0].dval); }
#line 2425 "project.tab.c"
    break;

  case 176: /* term_double: term_double DIV factor_double  */
#line 736 "project.y"
                                    {
    if ((yyvsp[0].dval) == 0) {
        yyerror("Division by zero");
    } else {
        (yyval.dval) = (yyvsp[-2].dval) / (yyvsp[0].dval);
    }
    }
#line 2437 "project.tab.c"
    break;

  case 177: /* term_double: term_double MOD factor_double  */
#line 743 "project.y"
                                    {
    if ((yyvsp[0].dval) == 0) {
        yyerror("Division by zero");
    } else {
        (yyval.dval) = fmod((yyvsp[-2].dval), (yyvsp[0].dval));
    }
    }
#line 2449 "project.tab.c"
    break;

  case 178: /* term_double: term_double POW factor_double  */
#line 750 "project.y"
                                    {
    if ((yyvsp[-2].dval) == 0 && (yyvsp[0].dval) == 0) {
        yyerror("Exponentiation by zero");
    } else {
        (yyval.dval) = pow((yyvsp[-2].dval), (yyvsp[0].dval));
    }
    }
#line 2461 "project.tab.c"
    break;

  case 179: /* factor_double: primary_double  */
#line 758 "project.y"
                              { (yyval.dval) = (yyvsp[0].dval); }
#line 2467 "project.tab.c"
    break;

  case 180: /* factor_double: LP exp_double RP  */
#line 759 "project.y"
                       { (yyval.dval) = (yyvsp[-1].dval); }
#line 2473 "project.tab.c"
    break;

  case 194: /* unary: primary_int  */
#line 782 "project.y"
                   { (yyval.ival) = (yyvsp[0].ival); }
#line 2479 "project.tab.c"
    break;

  case 195: /* unary: ADD primary_int  */
#line 783 "project.y"
                      { (yyval.ival) = (yyvsp[0].ival); }
#line 2485 "project.tab.c"
    break;

  case 196: /* unary: SUB primary_int  */
#line 784 "project.y"
                      { (yyval.ival) = -(yyvsp[0].ival); }
#line 2491 "project.tab.c"
    break;

  case 197: /* primary_int: CONST  */
#line 788 "project.y"
                   { (yyval.ival) = (yyvsp[0].ival); }
#line 2497 "project.tab.c"
    break;

  case 198: /* primary_int: variable_reference_int  */
#line 789 "project.y"
                             { (yyval.ival) = (yyvsp[0].ival); }
#line 2503 "project.tab.c"
    break;

  case 199: /* primary_double: DOUBLE_CONST  */
#line 794 "project.y"
                             { (yyval.dval) = (yyvsp[0].dval); }
#line 2509 "project.tab.c"
    break;

  case 200: /* primary_double: variable_reference_double  */
#line 795 "project.y"
                                { (yyval.dval) = (yyvsp[0].dval); }
#line 2515 "project.tab.c"
    break;

  case 201: /* $@5: %empty  */
#line 798 "project.y"
                                                 {
    if (!symbolExists((yyvsp[-4].sval), false, true)) {
        yyerror("Class not declared");
    } else {
        addSymbol((yyvsp[-3].sval), (yyvsp[-4].sval), false, true, false, (yyvsp[0].sval));
    }
    }
#line 2527 "project.tab.c"
    break;

  case 203: /* member_access: ID DOT member_access_body none_or_newlines  */
#line 807 "project.y"
                                                          {
    if (!symbolExists((yyvsp[-3].sval), false, true)) {
        yyerror("Class not declared");
    } else if (!symbolExists((yyvsp[-1].sval), false, false)) {
        yyerror("Member not declared");
    }
    }
#line 2539 "project.tab.c"
    break;

  case 204: /* member_access_body: ID SEMICOLON  */
#line 816 "project.y"
                                 {
    if (!symbolExists((yyvsp[-1].sval), false, false)) {
        yyerror("Variable not declared");
    }
    }
#line 2549 "project.tab.c"
    break;

  case 205: /* member_access_body: method_call  */
#line 821 "project.y"
                  {
    if (!symbolExists((yyvsp[0].sval), true, false)) {
        yyerror("Method not declared");
    }
    }
#line 2559 "project.tab.c"
    break;

  case 208: /* boolean: TRUE  */
#line 831 "project.y"
              { (yyval.sval) = "true"; }
#line 2565 "project.tab.c"
    break;

  case 209: /* boolean: FALSE  */
#line 832 "project.y"
            { (yyval.sval) = "false"; }
#line 2571 "project.tab.c"
    break;

  case 210: /* data_type: %empty  */
#line 835 "project.y"
                         { (yyval.sval) = ""; }
#line 2577 "project.tab.c"
    break;

  case 211: /* data_type: INTEGER  */
#line 836 "project.y"
              { (yyval.sval) = "int"; }
#line 2583 "project.tab.c"
    break;

  case 212: /* data_type: CHAR  */
#line 837 "project.y"
           { (yyval.sval) = "char"; }
#line 2589 "project.tab.c"
    break;

  case 213: /* data_type: DOUBLE  */
#line 838 "project.y"
             { (yyval.sval) = "double"; }
#line 2595 "project.tab.c"
    break;

  case 214: /* data_type: BOOLEAN  */
#line 839 "project.y"
              { (yyval.sval) = "boolean"; }
#line 2601 "project.tab.c"
    break;

  case 215: /* data_type: STRING  */
#line 840 "project.y"
             { (yyval.sval) = "string"; }
#line 2607 "project.tab.c"
    break;

  case 216: /* data_type: VOID  */
#line 841 "project.y"
           { (yyval.sval) = "void"; }
#line 2613 "project.tab.c"
    break;


#line 2617 "project.tab.c"

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

#line 848 "project.y"


void yyerror(const char *s) {
    if (errorCount < 1000) {
        errorTable[errorCount].line = yylineno;
        errorTable[errorCount].message = strdup(s);
        errorTable[errorCount].token = strdup(yytext);
        errorCount++;
    }
    else {
        fprintf(stderr, "Error:\n\nToo many errors\n");
        exit(1);
    }
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

    yyparse();

    printf("Input Program:\n");
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

    if (errorCount == 0) {
        printf("\n\nProgram is syntactically correct.");
    } else {
        printf("\n\nErrors:\n\n");
        for (int i = 0; i < errorCount; i++) {
            fprintf(stderr, "Error %d at line %d: %s recognised at the token '%s'\n", i+1, errorTable[i].line, errorTable[i].message, errorTable[i].token);
        }
    }

    fclose(f);

    return 0;
}
