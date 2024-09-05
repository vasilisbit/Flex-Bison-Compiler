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
  YYSYMBOL_assignment_list_variable = 79,  /* assignment_list_variable  */
  YYSYMBOL_assignment_list_method = 80,    /* assignment_list_method  */
  YYSYMBOL_assignment_list_object = 81,    /* assignment_list_object  */
  YYSYMBOL_assignment_list_declared = 82,  /* assignment_list_declared  */
  YYSYMBOL_assignment_list_int_declared = 83, /* assignment_list_int_declared  */
  YYSYMBOL_assignment_list_string_declared = 84, /* assignment_list_string_declared  */
  YYSYMBOL_assignment_list_char_declared = 85, /* assignment_list_char_declared  */
  YYSYMBOL_assignment_list_double_declared = 86, /* assignment_list_double_declared  */
  YYSYMBOL_assignment_list_boolean_declared = 87, /* assignment_list_boolean_declared  */
  YYSYMBOL_assignment_list_variable_declared = 88, /* assignment_list_variable_declared  */
  YYSYMBOL_assignment_list_method_declared = 89, /* assignment_list_method_declared  */
  YYSYMBOL_assignment_list_object_declared = 90, /* assignment_list_object_declared  */
  YYSYMBOL_variable_declaration = 91,      /* variable_declaration  */
  YYSYMBOL_variable_reference = 92,        /* variable_reference  */
  YYSYMBOL_method_declaration = 93,        /* method_declaration  */
  YYSYMBOL_94_3 = 94,                      /* $@3  */
  YYSYMBOL_95_4 = 95,                      /* $@4  */
  YYSYMBOL_none_or_multiple_parameters = 96, /* none_or_multiple_parameters  */
  YYSYMBOL_parameters = 97,                /* parameters  */
  YYSYMBOL_parameter = 98,                 /* parameter  */
  YYSYMBOL_method_body = 99,               /* method_body  */
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
#define YYFINAL  120
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   748

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  84
/* YYNRULES -- Number of rules.  */
#define YYNRULES  216
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  497

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
       0,   218,   218,   219,   220,   221,   224,   224,   228,   228,
     234,   235,   236,   239,   240,   241,   242,   243,   244,   247,
     248,   251,   252,   255,   256,   259,   260,   263,   264,   267,
     268,   271,   272,   273,   274,   275,   276,   277,   278,   281,
     287,   293,   294,   297,   298,   301,   307,   314,   315,   318,
     323,   329,   333,   338,   339,   342,   343,   344,   345,   346,
     347,   348,   349,   352,   363,   375,   383,   392,   400,   409,
     420,   432,   440,   449,   458,   468,   476,   485,   493,   502,
     503,   504,   505,   506,   509,   519,   519,   529,   529,   540,
     541,   544,   545,   548,   551,   552,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   574,   575,   578,   584,   585,   586,   589,
     590,   591,   594,   597,   598,   599,   600,   601,   604,   605,
     608,   609,   612,   613,   616,   619,   620,   621,   624,   625,
     628,   629,   632,   633,   636,   639,   640,   643,   646,   647,
     650,   651,   652,   655,   658,   661,   662,   670,   671,   675,
     676,   677,   680,   681,   682,   689,   696,   704,   705,   709,
     710,   711,   714,   715,   716,   723,   730,   738,   739,   743,
     744,   745,   746,   747,   748,   749,   752,   753,   754,   757,
     758,   759,   762,   763,   764,   768,   769,   774,   775,   778,
     778,   787,   796,   801,   807,   808,   811,   812,   815,   816,
     817,   818,   819,   820,   821,   824,   825
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

#define YYPACT_NINF (-403)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-209)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     575,     6,  -403,    63,    66,    12,  -403,     8,    70,    98,
    -403,  -403,   126,   145,   153,   156,   169,  -403,    32,   135,
     144,   150,   158,   191,   195,    27,   102,   102,   183,   248,
      12,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,   218,   220,  -403,    12,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,   234,   171,   211,  -403,   186,   274,
    -403,   237,   206,  -403,  -403,   462,  -403,  -403,  -403,   411,
     271,   575,    22,   238,   235,    12,   380,  -403,    20,  -403,
    -403,  -403,  -403,   239,    67,  -403,  -403,   167,  -403,  -403,
     176,  -403,  -403,   185,  -403,  -403,   213,  -403,  -403,  -403,
     119,   247,   254,   257,  -403,    12,    12,    12,    12,  -403,
     288,  -403,   109,   155,   251,  -403,  -403,  -403,  -403,  -403,
    -403,   575,  -403,  -403,   575,  -403,    44,    44,    44,    44,
      44,    44,    59,    59,    59,    59,    59,    59,  -403,    38,
      38,    38,    38,    38,    38,    38,    38,   303,  -403,  -403,
     307,  -403,  -403,   278,  -403,    12,   280,   282,   310,  -403,
    -403,   166,   284,   -21,    40,   285,   302,  -403,  -403,  -403,
    -403,  -403,  -403,   290,   290,    12,   329,   331,    16,  -403,
     333,    44,   334,   335,   337,    59,   338,   242,   341,   340,
    -403,  -403,  -403,    55,    42,   689,   360,   309,  -403,  -403,
    -403,  -403,  -403,    44,   211,   211,  -403,  -403,  -403,  -403,
      59,  -403,   274,   274,  -403,  -403,  -403,  -403,    38,   206,
     206,   206,   206,   206,   206,  -403,  -403,   305,  -403,    12,
    -403,  -403,   346,   347,   316,   351,   361,   368,   377,   378,
     381,    12,  -403,  -403,   348,  -403,   354,  -403,   383,   357,
     375,    12,   385,  -403,    92,   388,  -403,   395,   400,  -403,
      94,   401,  -403,   402,   404,  -403,   405,    -1,  -403,    12,
    -403,   491,  -403,    12,    12,    12,   466,   403,  -403,  -403,
     407,   245,   440,   442,   408,  -403,    12,   399,   406,  -403,
     410,  -403,   444,   415,  -403,   416,  -403,   419,  -403,   420,
    -403,   421,  -403,  -403,   380,   426,   429,   448,   464,   632,
     465,   470,   473,   476,   484,   449,   452,   453,   427,    12,
     126,   145,   153,   156,   169,   455,   309,   460,    12,   399,
      12,   467,   489,   494,   461,  -403,   511,   513,    44,    59,
     242,   486,   290,   290,  -403,   520,   485,  -403,   487,  -403,
      12,    12,    12,   490,  -403,   492,  -403,   500,  -403,   501,
    -403,   502,  -403,   488,   493,   505,   504,    38,   119,  -403,
    -403,   632,    12,   514,    12,  -403,   542,   527,   525,  -403,
    -403,   524,  -403,   511,   513,   632,   528,   632,    12,    12,
      12,   530,   536,   491,   190,  -403,    12,   555,   535,   534,
     547,   578,  -403,  -403,  -403,   689,   573,   573,    12,    12,
     559,   561,    12,   467,  -403,    12,   136,    12,    12,    12,
      38,   360,  -403,    12,   689,  -403,   565,  -403,  -403,   570,
     576,   573,   576,    12,    68,    12,   689,    12,    12,    12,
      12,   572,    12,  -403,    12,    12,   571,   577,   579,    12,
     574,   689,   589,   689,    12,   580,   573,   581,   583,   585,
     584,   582,  -403,  -403,   587,    12,  -403,   689,  -403,  -403,
    -403,  -403,  -403,    12,  -403,    55,   591,  -403,   689,   590,
     588,  -403,    12,   598,    12,   600,    12,   689,  -403,   689,
      12,    12,   610,   613,  -403,   589,  -403
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,   195,    84,     0,   215,   197,     0,     0,     0,
     204,   205,   209,   210,   211,   212,   213,   214,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     215,    79,    82,    83,    55,    56,    57,    58,    59,    60,
      61,    62,     0,   196,   109,   215,    97,    98,    99,   100,
     101,   102,   103,   104,     0,   157,   159,   162,   158,   169,
     172,     0,   179,   186,   189,   167,   177,   110,   112,   208,
       0,     0,     0,     0,     0,   215,   116,   107,    29,    18,
      36,    37,    38,     0,    19,    13,    31,    23,    15,    33,
      25,    16,    34,    27,    17,    35,    21,    14,    32,    84,
       0,   196,     0,     0,   167,   215,   215,   215,   215,   153,
       0,   196,     0,     0,     0,   196,   193,   194,   190,   192,
       1,     0,   108,   111,     0,   105,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   106,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    80,    81,
       0,    87,     5,     0,   203,   215,    67,    65,     0,   206,
     207,   196,    75,    63,    69,    71,     0,   216,   209,   210,
     211,   212,   213,   119,   119,   215,     0,     0,     0,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     151,   152,   150,     0,     0,    96,   135,   155,   168,   178,
     191,     3,     4,     0,   160,   161,   163,   164,   165,   166,
       0,   198,   170,   171,   173,   174,   175,   176,     0,   180,
     181,   182,   184,   183,   185,   188,   187,     0,    85,   215,
     202,   201,     0,     0,    77,     0,     0,     0,     0,     0,
       0,   215,   118,   117,     0,    93,    29,    30,     0,    49,
      51,   215,    19,    20,    39,    23,    24,    43,    25,    26,
      45,    27,    28,    47,    21,    22,    41,   196,   126,   215,
     123,   124,   127,   215,   215,   215,   208,     0,   137,   136,
       0,     0,     0,     0,     0,     6,   215,    89,     0,    68,
       0,    66,     0,     0,    74,     0,    76,     0,    64,     0,
      70,     0,    72,   199,     0,     0,    53,     0,     0,    10,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   215,
       0,     0,     0,     0,     0,     0,   155,     0,   215,    89,
     215,    91,     0,     0,     0,    78,     0,     0,     0,     0,
       0,     0,   119,   119,   115,     0,     0,    50,     0,    52,
     215,   215,   215,     0,    40,     0,    44,     0,    46,     0,
      48,     0,    42,     0,     0,     0,     0,   138,     0,   156,
     154,    10,   215,     0,   215,    90,     0,    73,     0,   121,
     120,     0,    54,     0,     0,    10,     0,    10,   215,   215,
     215,     0,     0,   139,   196,   113,   215,     0,     0,   208,
       0,     0,    11,     9,    12,    96,     0,     0,   215,   215,
       0,     0,   215,    91,   200,   215,     0,   215,   215,   215,
       0,   135,     7,   215,    94,    92,     0,   148,   149,     0,
     142,   145,   142,   196,   215,   215,    94,   215,   215,   215,
     215,     0,   215,   144,   215,   215,     0,     0,     0,   215,
       0,    94,   128,    96,   215,     0,   145,     0,     0,     0,
       0,     0,    88,    95,     0,   215,   147,    96,   141,   146,
     140,   133,   132,   215,    86,     0,   130,   143,    96,     0,
       0,   122,   215,     0,   215,     0,   215,    96,   134,    96,
     215,   215,     0,     0,   131,   128,   129
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -403,   -56,  -302,  -403,  -403,  -275,   -64,   434,   445,   450,
     438,   471,   482,   -58,   350,   352,   358,   349,   355,   363,
     365,   320,  -403,   437,   443,   439,   441,   436,   446,   447,
     386,  -188,     0,  -403,  -403,  -403,   353,   264,   -74,  -309,
    -171,  -403,   -17,  -403,  -161,  -403,   205,   189,  -403,  -403,
    -403,   266,  -403,  -403,   256,   283,   233,  -402,  -403,  -403,
    -403,  -403,   371,   -14,     2,   168,   231,   -13,   173,   273,
     -19,   418,   165,   672,    25,  -403,  -403,  -403,  -403,  -403,
      19,  -184,   -55,    83
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    29,    30,   328,   251,   351,    31,    85,    97,    88,
      91,    94,    79,    32,    86,    98,    89,    92,    95,    80,
      81,    82,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,   115,    44,   286,   229,   330,   375,   331,   437,
      45,   279,    46,   175,   242,    47,   269,   465,   481,    48,
      49,   280,   392,    50,   442,   417,   443,   418,   429,    51,
      52,    53,   284,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,   341,    68,   155,
     276,   165,    70,    76
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,   102,   174,   263,   103,   148,   114,   350,   278,   272,
    -125,   149,   113,   243,   150,   152,   237,    71,   101,    69,
      99,   176,     5,    75,   275,   111,   153,   112,     5,   444,
       2,    99,   126,   127,     6,     2,    99,   248,     5,     6,
    -125,     2,    99,   104,    77,     2,    99,     2,    99,     6,
     273,   116,   117,   119,   444,   154,   162,   177,     2,    99,
     164,     5,     6,    99,   178,   201,     6,    25,   202,   350,
      74,    43,   100,   161,    78,   163,   173,   238,   218,    75,
      26,    27,   100,   350,   203,   350,    28,   113,   159,   160,
      69,    26,    27,   132,   133,    25,   396,    28,   104,   210,
     111,    72,   112,    83,   180,     2,    99,    73,    26,    27,
     402,   181,   404,   121,    28,   139,   140,   141,   142,   143,
     144,    43,     2,    99,    43,   104,     6,   449,   124,   310,
      84,   312,   211,   211,   211,   211,   211,   211,   352,   427,
      69,   282,   463,    69,   428,   126,   127,   132,   133,    87,
     198,   104,   104,   104,   104,   104,   104,    90,   167,   100,
      93,   250,   126,   127,   119,   119,   119,   119,   119,   119,
     119,   119,   260,    96,   271,   105,   268,   -73,   249,   270,
     274,   379,   380,   254,   106,   211,     2,    99,   193,   194,
     195,   196,   107,   267,   111,    43,   199,   113,   108,   114,
     352,  -114,   -73,   235,   182,   112,   104,   -73,   132,   133,
     211,   183,   148,   184,   352,   281,   352,   148,   149,   104,
     185,   150,   186,   149,   126,   127,  -114,   109,   104,   187,
     343,  -114,   176,   278,   415,   110,    26,    27,   231,   132,
     133,     2,    99,   119,     5,     6,   156,   157,   120,   176,
     188,   145,   146,   438,   122,     8,   123,   189,   244,   158,
     320,   321,   322,   323,   324,   438,   128,   129,   130,   131,
     125,   159,   160,   138,   176,   159,   160,   151,   100,   166,
     438,   179,   466,   190,   139,   140,   141,   142,   143,   144,
     191,   272,   200,   192,   204,   205,   477,   197,   139,   140,
     141,   142,   143,   144,   342,   212,   213,   482,   227,    43,
     225,   226,   287,   228,   230,   234,   490,   232,   491,   233,
     162,   236,   239,   240,   304,   413,   164,   241,    69,   134,
     135,   136,   137,   245,   309,   246,   377,   252,   255,   211,
     163,   258,   261,   257,   176,   264,   283,   285,   393,   266,
     288,   290,   315,   292,   395,   293,   316,   317,   318,   206,
     207,   208,   209,   104,   277,   295,   282,   250,   394,   329,
       8,    43,   297,    10,    11,    12,    13,    14,    15,    16,
      17,   299,   301,   249,    99,    43,   303,    43,   306,   305,
      69,   177,   119,   104,   307,   168,   169,   170,   171,   172,
      17,   434,   367,  -208,    69,    43,    69,   214,   215,   216,
     217,   371,   308,   373,   168,   169,   170,   171,   172,    17,
     433,     8,   180,   147,    43,   182,    12,    13,    14,    15,
      16,    17,   311,   385,   386,   387,    43,   184,   186,   313,
     281,   188,   314,   319,   325,   119,   326,    73,   334,   327,
     332,    43,   346,    43,   333,   397,   271,   399,   268,   336,
     337,   270,   344,   338,   339,   340,   345,    43,   348,   353,
     366,   405,   406,   407,   355,   267,     8,   357,    43,   410,
     359,    12,    13,    14,    15,    16,    17,    43,   361,    43,
     363,   420,   421,   364,   365,   424,   370,   156,   426,   368,
     430,   431,   432,   157,   374,   376,   436,  -192,  -192,  -192,
    -192,  -192,  -192,  -192,  -192,    99,   446,   447,   448,     5,
     450,   451,   452,   453,   381,   455,   378,   456,   457,   383,
     388,   384,   461,   391,   181,   389,   183,   467,   139,   140,
     141,   142,   143,   144,   185,   187,   189,   390,   476,   168,
     169,   170,   171,   172,    17,   398,   478,   219,   220,   221,
     222,   223,   224,   158,   235,   485,   400,   487,   401,   489,
     408,   403,   409,   492,   493,    -2,     1,   412,     2,     3,
       4,     5,     6,   414,     7,     8,   -96,     9,    10,    11,
      12,    13,    14,    15,    16,    17,   411,    18,    19,   248,
     416,    20,   422,   423,   441,    21,    22,    23,   439,   440,
      24,   454,   458,   464,   253,    25,   480,   462,   459,   471,
     460,   472,   259,   468,   470,   474,   473,   475,    26,    27,
     484,   483,   256,   265,    28,     2,     3,     4,     5,     6,
     486,     7,     8,   488,     9,    10,    11,    12,    13,    14,
      15,    16,    17,   494,    18,    19,   495,   262,    20,   247,
     354,   358,    21,    22,    23,   382,   362,    24,   360,   356,
     347,   289,    25,   349,   298,   302,   291,   425,   335,   300,
     479,   294,   372,   296,   496,    26,    27,   435,   445,   469,
     419,    28,     2,     3,     4,     5,     6,   369,     7,     8,
     118,     0,    10,    11,    12,    13,    14,    15,    16,    17,
       0,    18,    19,     0,     0,    20,     0,     0,     0,    21,
      22,    23,     0,     0,    24,     0,     0,     0,     0,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,    27,     0,     0,     0,     0,    28
};

static const yytype_int16 yycheck[] =
{
       0,    18,    76,   187,    18,    69,    25,   309,   196,   193,
      11,    69,    25,   174,    69,    71,    37,    11,    18,     0,
       4,    76,     6,    11,   195,    25,     4,    25,     6,   431,
       3,     4,    53,    54,     7,     3,     4,    21,     6,     7,
      41,     3,     4,    18,    36,     3,     4,     3,     4,     7,
       8,    26,    27,    28,   456,    72,    73,    37,     3,     4,
      73,     6,     7,     4,    44,   121,     7,    40,   124,   371,
       4,    71,    40,    73,     4,    73,    76,    37,    40,    11,
      53,    54,    40,   385,    40,   387,    59,   100,    33,    34,
      71,    53,    54,    53,    54,    40,   371,    59,    73,    40,
     100,    38,   100,     5,    37,     3,     4,    44,    53,    54,
     385,    44,   387,    30,    59,    47,    48,    49,    50,    51,
      52,   121,     3,     4,   124,   100,     7,   436,    45,    37,
       4,    37,   132,   133,   134,   135,   136,   137,   309,     3,
     121,   196,   451,   124,     8,    53,    54,    53,    54,     4,
      41,   126,   127,   128,   129,   130,   131,     4,    75,    40,
       4,   178,    53,    54,   139,   140,   141,   142,   143,   144,
     145,   146,   185,     4,   193,    40,   193,    11,   178,   193,
     194,   342,   343,   181,    40,   185,     3,     4,   105,   106,
     107,   108,    42,   193,   194,   195,    41,   210,    40,   218,
     371,    11,    36,    37,    37,   203,   181,    41,    53,    54,
     210,    44,   276,    37,   385,   196,   387,   281,   276,   194,
      44,   276,    37,   281,    53,    54,    36,    36,   203,    44,
     304,    41,   287,   421,   405,    40,    53,    54,   155,    53,
      54,     3,     4,   218,     6,     7,     8,     9,     0,   304,
      37,    45,    46,   424,    36,    10,    36,    44,   175,    21,
      15,    16,    17,    18,    19,   436,    55,    56,    57,    58,
      36,    33,    34,    36,   329,    33,    34,     6,    40,    44,
     451,    42,   453,    36,    47,    48,    49,    50,    51,    52,
      36,   475,    41,    36,   126,   127,   467,     9,    47,    48,
      49,    50,    51,    52,   304,   132,   133,   478,     5,   309,
     145,   146,   229,     6,    36,     5,   487,    37,   489,    37,
     337,    37,    37,    21,   241,   399,   339,    37,   309,    55,
      56,    57,    58,     4,   251,     4,   336,     4,     4,   339,
     338,     4,     4,     8,   399,     4,    37,    42,   367,     9,
       4,     4,   269,    37,   368,     4,   273,   274,   275,   128,
     129,   130,   131,   338,     4,     4,   421,   384,   368,   286,
      10,   371,     4,    13,    14,    15,    16,    17,    18,    19,
      20,     4,     4,   383,     4,   385,     5,   387,     5,    41,
     371,    37,   367,   368,    37,    15,    16,    17,    18,    19,
      20,   420,   319,     4,   385,   405,   387,   134,   135,   136,
     137,   328,    37,   330,    15,    16,    17,    18,    19,    20,
     420,    10,    37,    12,   424,    37,    15,    16,    17,    18,
      19,    20,    37,   350,   351,   352,   436,    37,    37,    37,
     421,    37,    37,    36,     4,   420,     4,    44,     4,    41,
      44,   451,     4,   453,    44,   372,   475,   374,   475,    44,
      44,   475,    36,    44,    44,    44,    37,   467,     4,     4,
      43,   388,   389,   390,     4,   475,    10,     4,   478,   396,
       4,    15,    16,    17,    18,    19,    20,   487,     4,   489,
      41,   408,   409,    41,    41,   412,    36,     8,   415,    44,
     417,   418,   419,     9,    37,    44,   423,    45,    46,    47,
      48,    49,    50,    51,    52,     4,   433,   434,   435,     6,
     437,   438,   439,   440,     4,   442,    40,   444,   445,    44,
      42,    44,   449,    29,    44,    42,    44,   454,    47,    48,
      49,    50,    51,    52,    44,    44,    44,    42,   465,    15,
      16,    17,    18,    19,    20,    41,   473,   139,   140,   141,
     142,   143,   144,    21,    37,   482,    41,   484,    44,   486,
      40,    43,    36,   490,   491,     0,     1,    42,     3,     4,
       5,     6,     7,    36,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    41,    22,    23,    21,
      27,    26,    43,    42,    28,    30,    31,    32,    43,    39,
      35,    39,    41,    24,   180,    40,    25,    43,    41,    36,
      41,    36,   184,    43,    43,    43,    42,    40,    53,    54,
      42,    41,   182,   188,    59,     3,     4,     5,     6,     7,
      42,     9,    10,    43,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    43,    22,    23,    43,   186,    26,   177,
     310,   312,    30,    31,    32,   345,   314,    35,   313,   311,
     307,   232,    40,   308,   237,   239,   233,   413,   292,   238,
     475,   235,   329,   236,   495,    53,    54,   421,   432,   456,
     407,    59,     3,     4,     5,     6,     7,   326,     9,    10,
      28,    -1,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    -1,    -1,    26,    -1,    -1,    -1,    30,
      31,    32,    -1,    -1,    35,    -1,    -1,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    59
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     9,    10,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    22,    23,
      26,    30,    31,    32,    35,    40,    53,    54,    59,    61,
      62,    66,    73,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,   100,   102,   105,   109,   110,
     113,   119,   120,   121,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   138,   140,
     142,    11,    38,    44,     4,    11,   143,    36,     4,    72,
      79,    80,    81,     5,     4,    67,    74,     4,    69,    76,
       4,    70,    77,     4,    71,    78,     4,    68,    75,     4,
      40,    92,   102,   123,   134,    40,    40,    42,    40,    36,
      40,    92,   124,   127,   130,    92,   134,   134,   133,   134,
       0,   143,    36,    36,   143,    36,    53,    54,    55,    56,
      57,    58,    53,    54,    55,    56,    57,    58,    36,    47,
      48,    49,    50,    51,    52,    45,    46,    12,    66,    73,
     142,     6,    61,     4,   102,   139,     8,     9,    21,    33,
      34,    92,   102,   124,   127,   141,    44,   143,    15,    16,
      17,    18,    19,    92,    98,   103,   142,    37,    44,    42,
      37,    44,    37,    44,    37,    44,    37,    44,    37,    44,
      36,    36,    36,   143,   143,   143,   143,     9,    41,    41,
      41,    61,    61,    40,   125,   125,   126,   126,   126,   126,
      40,    92,   128,   128,   129,   129,   129,   129,    40,   131,
     131,   131,   131,   131,   131,   132,   132,     5,     6,    95,
      36,   143,    37,    37,     5,    37,    37,    37,    37,    37,
      21,    37,   104,   104,   143,     4,     4,    72,    21,    92,
     102,    64,     4,    67,   124,     4,    69,     8,     4,    70,
     127,     4,    71,   141,     4,    68,     9,    92,   102,   106,
     123,   130,   141,     8,   123,   100,   140,     4,    91,   101,
     111,   140,   142,    37,   122,    42,    94,   143,     4,    85,
       4,    84,    37,     4,    88,     4,    89,     4,    83,     4,
      86,     4,    87,     5,   143,    41,     5,    37,    37,   143,
      37,    37,    37,    37,    37,   143,   143,   143,   143,    36,
      15,    16,    17,    18,    19,     4,     4,    41,    63,   143,
      96,    98,    44,    44,     4,    90,    44,    44,    44,    44,
      44,   137,    92,    98,    36,    37,     4,    79,     4,    80,
      62,    65,   100,     4,    74,     4,    76,     4,    77,     4,
      78,     4,    75,    41,    41,    41,    43,   143,    44,   122,
      36,   143,    96,   143,    37,    97,    44,    92,    40,   104,
     104,     4,    81,    44,    44,   143,   143,   143,    42,    42,
      42,    29,   112,   130,    92,   123,    65,   143,    41,   143,
      41,    44,    65,    43,    65,   143,   143,   143,    40,    36,
     143,    41,    42,    98,    36,   100,    27,   115,   117,   115,
     143,   143,    43,    42,   143,    97,   143,     3,     8,   118,
     143,   143,   143,    92,   130,   111,   143,    99,   100,    43,
      39,    28,   114,   116,   117,   114,   143,   143,   143,    99,
     143,   143,   143,   143,    39,   143,   143,   143,    41,    41,
      41,   143,    43,    99,    24,   107,   100,   143,    43,   116,
      43,    36,    36,    42,    43,    40,   143,   100,   143,   106,
      25,   108,   100,    41,    42,   143,    42,   143,    43,   143,
     100,   100,   143,   143,    43,    43,   107
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    61,    61,    61,    63,    62,    64,    62,
      65,    65,    65,    66,    66,    66,    66,    66,    66,    67,
      67,    68,    68,    69,    69,    70,    70,    71,    71,    72,
      72,    73,    73,    73,    73,    73,    73,    73,    73,    74,
      74,    75,    75,    76,    76,    77,    77,    78,    78,    79,
      79,    80,    80,    81,    81,    82,    82,    82,    82,    82,
      82,    82,    82,    83,    83,    84,    84,    85,    85,    86,
      86,    87,    87,    88,    88,    89,    89,    90,    90,    91,
      91,    91,    91,    91,    92,    94,    93,    95,    93,    96,
      96,    97,    97,    98,    99,    99,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   101,   101,   102,   103,   103,   103,   104,
     104,   104,   105,   106,   106,   106,   106,   106,   107,   107,
     108,   108,   109,   109,   110,   111,   111,   111,   112,   112,
     113,   113,   114,   114,   115,   116,   116,   117,   118,   118,
     119,   119,   119,   120,   121,   122,   122,   123,   123,   124,
     124,   124,   125,   125,   125,   125,   125,   126,   126,   127,
     127,   127,   128,   128,   128,   128,   128,   129,   129,   130,
     130,   130,   130,   130,   130,   130,   131,   131,   131,   132,
     132,   132,   133,   133,   133,   134,   134,   135,   135,   137,
     136,   138,   139,   139,   140,   140,   141,   141,   142,   142,
     142,   142,   142,   142,   142,   143,   143
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
       2,     2,     1,     1,     1,     0,    13,     0,    12,     0,
       2,     0,     4,     2,     0,     3,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     1,
       1,     2,     1,     4,     4,     6,     0,     2,     2,     0,
       4,     4,    15,     1,     1,     1,     1,     1,     0,    10,
       0,     6,    13,    13,    17,     0,     1,     1,     0,     1,
      13,    13,     0,     4,     3,     0,     3,     5,     1,     1,
       3,     3,     3,     2,     6,     0,     3,     1,     1,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     1,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     1,
       2,     3,     1,     2,     2,     1,     1,     1,     1,     0,
       9,     4,     2,     1,     1,     1,     1,     1,     0,     1,
       1,     1,     1,     1,     1,     0,     2
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
#line 1755 "project.tab.c"
    break;

  case 6: /* $@1: %empty  */
#line 224 "project.y"
                                                      {
    addSymbol((yyvsp[-1].sval), "class", false, true, true, NULL);
    increaseScope();
    }
#line 1764 "project.tab.c"
    break;

  case 7: /* class_declaration: access_modifier CLASS CLASS_ID LCB $@1 none_or_newlines class_body none_or_newlines RCB  */
#line 227 "project.y"
                                                       { decreaseScope(); }
#line 1770 "project.tab.c"
    break;

  case 8: /* $@2: %empty  */
#line 228 "project.y"
                         {
    addSymbol((yyvsp[-1].sval), "class", false, true, true, NULL);
    increaseScope();
    }
#line 1779 "project.tab.c"
    break;

  case 9: /* class_declaration: CLASS CLASS_ID LCB $@2 none_or_newlines class_body none_or_newlines RCB  */
#line 231 "project.y"
                                                       { decreaseScope(); }
#line 1785 "project.tab.c"
    break;

  case 19: /* identifier_list_int: ID  */
#line 247 "project.y"
                        { addSymbol((yyvsp[0].sval), "int", false, false, false, NULL); }
#line 1791 "project.tab.c"
    break;

  case 20: /* identifier_list_int: ID COMMA identifier_list_int  */
#line 248 "project.y"
                                   { addSymbol((yyvsp[-2].sval), "int", false, false, false, NULL); }
#line 1797 "project.tab.c"
    break;

  case 21: /* identifier_list_string: ID  */
#line 251 "project.y"
                           { addSymbol((yyvsp[0].sval), "string", false, false, false, NULL); }
#line 1803 "project.tab.c"
    break;

  case 22: /* identifier_list_string: ID COMMA identifier_list_string  */
#line 252 "project.y"
                                      { addSymbol((yyvsp[-2].sval), "string", false, false, false, NULL); }
#line 1809 "project.tab.c"
    break;

  case 23: /* identifier_list_char: ID  */
#line 255 "project.y"
                         { addSymbol((yyvsp[0].sval), "char", false, false, false, NULL); }
#line 1815 "project.tab.c"
    break;

  case 24: /* identifier_list_char: ID COMMA identifier_list_char  */
#line 256 "project.y"
                                    { addSymbol((yyvsp[-2].sval), "char", false, false, false, NULL); }
#line 1821 "project.tab.c"
    break;

  case 25: /* identifier_list_double: ID  */
#line 259 "project.y"
                           { addSymbol((yyvsp[0].sval), "double", false, false, false, NULL); }
#line 1827 "project.tab.c"
    break;

  case 26: /* identifier_list_double: ID COMMA identifier_list_double  */
#line 260 "project.y"
                                      { addSymbol((yyvsp[-2].sval), "double", false, false, false, NULL); }
#line 1833 "project.tab.c"
    break;

  case 27: /* identifier_list_boolean: ID  */
#line 263 "project.y"
                            { addSymbol((yyvsp[0].sval), "boolean", false, false, false, NULL); }
#line 1839 "project.tab.c"
    break;

  case 28: /* identifier_list_boolean: ID COMMA identifier_list_boolean  */
#line 264 "project.y"
                                       { addSymbol((yyvsp[-2].sval), "boolean", false, false, false, NULL); }
#line 1845 "project.tab.c"
    break;

  case 29: /* identifier_list_variable: ID  */
#line 267 "project.y"
                             { addSymbol((yyvsp[0].sval), "var", false, false, false, NULL); }
#line 1851 "project.tab.c"
    break;

  case 30: /* identifier_list_variable: ID COMMA identifier_list_variable  */
#line 268 "project.y"
                                        { addSymbol((yyvsp[-2].sval), "var", false, false, false, NULL); }
#line 1857 "project.tab.c"
    break;

  case 39: /* assignment_list_int: ID ASSIGN exp_int  */
#line 281 "project.y"
                                       {
    char valueStr[32];
    sprintf(valueStr, "%d", (yyvsp[0].ival));
    addSymbol((yyvsp[-2].sval), "int", false, true, false, valueStr);
    printf("Variable %s assigned with value %d\n\n", (yyvsp[-2].sval), (yyvsp[0].ival));
    }
#line 1868 "project.tab.c"
    break;

  case 40: /* assignment_list_int: ID ASSIGN exp_int COMMA assignment_list_int  */
#line 287 "project.y"
                                                  {
    char valueStr[32]; sprintf(valueStr, "%d", (yyvsp[-2].ival));
    addSymbol((yyvsp[-4].sval), "int", false, true, false, valueStr);
    printf("Variable %s assigned with value %d\n\n", (yyvsp[-4].sval), (yyvsp[-2].ival));
    }
#line 1878 "project.tab.c"
    break;

  case 41: /* assignment_list_string: ID ASSIGN DQ_STRING_DQ  */
#line 293 "project.y"
                                               { addSymbol((yyvsp[-2].sval), "string", false, true, false, (yyvsp[0].sval)); }
#line 1884 "project.tab.c"
    break;

  case 42: /* assignment_list_string: ID ASSIGN DQ_STRING_DQ COMMA assignment_list_string  */
#line 294 "project.y"
                                                          { addSymbol((yyvsp[-4].sval), "string", false, true, false, (yyvsp[-2].sval)); }
#line 1890 "project.tab.c"
    break;

  case 43: /* assignment_list_char: ID ASSIGN SQ_ANYCHAR_SQ  */
#line 297 "project.y"
                                              { addSymbol((yyvsp[-2].sval), "char", false, true, false, (yyvsp[0].cval)); }
#line 1896 "project.tab.c"
    break;

  case 44: /* assignment_list_char: ID ASSIGN SQ_ANYCHAR_SQ COMMA assignment_list_char  */
#line 298 "project.y"
                                                         { addSymbol((yyvsp[-4].sval), "char", false, true, false, (yyvsp[-2].cval)); }
#line 1902 "project.tab.c"
    break;

  case 45: /* assignment_list_double: ID ASSIGN exp_double  */
#line 301 "project.y"
                                             {
    char valueStr[64];
    sprintf(valueStr, "%f", (yyvsp[0].dval));
    addSymbol((yyvsp[-2].sval), "double", false, true, false, valueStr);
    printf("Variable %s assigned with value %f\n\n", (yyvsp[-2].sval), (yyvsp[0].dval));
    }
#line 1913 "project.tab.c"
    break;

  case 46: /* assignment_list_double: ID ASSIGN exp_double COMMA assignment_list_double  */
#line 307 "project.y"
                                                        {
    char valueStr[64];
    sprintf(valueStr, "%f", (yyvsp[-2].dval));
    addSymbol((yyvsp[-4].sval), "double", false, true, false, valueStr);
    printf("Variable %s assigned with value %f\n\n", (yyvsp[-4].sval), (yyvsp[-2].dval));
    }
#line 1924 "project.tab.c"
    break;

  case 47: /* assignment_list_boolean: ID ASSIGN boolean  */
#line 314 "project.y"
                                           { addSymbol((yyvsp[-2].sval), "boolean", false, true, false, (yyvsp[0].sval)); }
#line 1930 "project.tab.c"
    break;

  case 48: /* assignment_list_boolean: ID ASSIGN boolean COMMA assignment_list_boolean  */
#line 315 "project.y"
                                                      { addSymbol((yyvsp[-4].sval), "boolean", false, true, false, (yyvsp[-2].sval)); }
#line 1936 "project.tab.c"
    break;

  case 49: /* assignment_list_variable: ID ASSIGN variable_reference  */
#line 318 "project.y"
                                                       {
    char* type = getType((yyvsp[0].sval));
    char* value = getValue((yyvsp[0].sval));
    addSymbol((yyvsp[-2].sval), type, false, true, false, value);
    }
#line 1946 "project.tab.c"
    break;

  case 50: /* assignment_list_variable: ID ASSIGN variable_reference COMMA assignment_list_variable  */
#line 323 "project.y"
                                                                  {
    char* type = getType((yyvsp[-2].sval));
    char* value = getValue((yyvsp[-2].sval));
    addSymbol((yyvsp[-4].sval), type, false, true, false, value);
    }
#line 1956 "project.tab.c"
    break;

  case 51: /* assignment_list_method: ID ASSIGN method_call  */
#line 329 "project.y"
                                              {
    char* type = getType((yyvsp[0].sval));
    addSymbol((yyvsp[-2].sval), type, false, true, false, NULL);
    }
#line 1965 "project.tab.c"
    break;

  case 52: /* assignment_list_method: ID ASSIGN method_call COMMA assignment_list_method  */
#line 333 "project.y"
                                                         {
    char* type = getType((yyvsp[-2].sval));
    addSymbol((yyvsp[-4].sval), type, false, true, false, NULL);
    }
#line 1974 "project.tab.c"
    break;

  case 53: /* assignment_list_object: ID ASSIGN NEW CLASS_ID  */
#line 338 "project.y"
                                               { addSymbol((yyvsp[-3].sval), "class", false, true, false, NULL); }
#line 1980 "project.tab.c"
    break;

  case 54: /* assignment_list_object: ID ASSIGN NEW CLASS_ID COMMA assignment_list_object  */
#line 339 "project.y"
                                                          { addSymbol((yyvsp[-5].sval), "class", false, true, false, NULL); }
#line 1986 "project.tab.c"
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
#line 2002 "project.tab.c"
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
#line 2018 "project.tab.c"
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
#line 2031 "project.tab.c"
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
#line 2044 "project.tab.c"
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
#line 2057 "project.tab.c"
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
#line 2070 "project.tab.c"
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
#line 2086 "project.tab.c"
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
#line 2102 "project.tab.c"
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
#line 2115 "project.tab.c"
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
#line 2128 "project.tab.c"
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
#line 2142 "project.tab.c"
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
#line 2156 "project.tab.c"
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
#line 2169 "project.tab.c"
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
#line 2182 "project.tab.c"
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
#line 2195 "project.tab.c"
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
#line 2208 "project.tab.c"
    break;

  case 84: /* variable_reference: ID  */
#line 509 "project.y"
                       {
    if (!symbolExists((yyvsp[0].sval), false, false)) {
        yyerror("Variable not declared");
    } else if (!isInitialized((yyvsp[0].sval))) {
        yyerror("Variable not initialized");
    } else {
        (yyval.sval) = (yyvsp[0].sval);
    }
    }
#line 2222 "project.tab.c"
    break;

  case 85: /* $@3: %empty  */
#line 519 "project.y"
                                                        {
    if (!symbolExists((yyvsp[0].sval), false, false)) {
        addSymbol((yyvsp[0].sval), (yyvsp[-1].sval), true, true, false, NULL);
    } else {
        yyerror("Method already declared");
    }
    increaseScope();
    }
#line 2235 "project.tab.c"
    break;

  case 86: /* method_declaration: access_modifier data_type METHOD_ID $@3 none_or_newlines none_or_multiple_parameters none_or_newlines RP LCB none_or_newlines method_body none_or_newlines RCB  */
#line 526 "project.y"
                                                                                                                             {
    decreaseScope();
    }
#line 2243 "project.tab.c"
    break;

  case 87: /* $@4: %empty  */
#line 529 "project.y"
                          {
    if (!symbolExists((yyvsp[0].sval), false, false)) {
        addSymbol((yyvsp[0].sval), (yyvsp[-1].sval), true, true, false, NULL);
    } else {
        yyerror("Method already declared");
    }
    increaseScope();
    }
#line 2256 "project.tab.c"
    break;

  case 88: /* method_declaration: data_type METHOD_ID $@4 none_or_newlines none_or_multiple_parameters none_or_newlines RP LCB none_or_newlines method_body none_or_newlines RCB  */
#line 536 "project.y"
                                                                                                                             {
    decreaseScope();
    }
#line 2264 "project.tab.c"
    break;

  case 93: /* parameter: data_type ID  */
#line 548 "project.y"
                        { addSymbol((yyvsp[0].sval), (yyvsp[-1].sval), false, true, false, NULL); }
#line 2270 "project.tab.c"
    break;

  case 115: /* method_call: METHOD_ID none_or_newlines none_or_multiple_arguments none_or_newlines RP SEMICOLON  */
#line 578 "project.y"
                                                                                                 {
    if (!symbolExists((yyvsp[-5].sval), true, false)) {
        yyerror("Method not declared");
    }
    }
#line 2280 "project.tab.c"
    break;

  case 156: /* single_or_multiple_variables: COMMA ID single_or_multiple_variables  */
#line 662 "project.y"
                                            {
    if (!symbolExists((yyvsp[-1].sval), false, false)) {
        yyerror("Variable not declared");
    } else if (!isInitialized((yyvsp[-1].sval))) {
        yyerror("Variable not initialized");
    }
    }
#line 2292 "project.tab.c"
    break;

  case 159: /* exp_int: term_int  */
#line 675 "project.y"
                  { (yyval.ival) = (yyvsp[0].ival); }
#line 2298 "project.tab.c"
    break;

  case 160: /* exp_int: exp_int ADD term_int  */
#line 676 "project.y"
                           { (yyval.ival) = (yyvsp[-2].ival) + (yyvsp[0].ival); }
#line 2304 "project.tab.c"
    break;

  case 161: /* exp_int: exp_int SUB term_int  */
#line 677 "project.y"
                           { (yyval.ival) = (yyvsp[-2].ival) - (yyvsp[0].ival); }
#line 2310 "project.tab.c"
    break;

  case 162: /* term_int: factor_int  */
#line 680 "project.y"
                     { (yyval.ival) = (yyvsp[0].ival); }
#line 2316 "project.tab.c"
    break;

  case 163: /* term_int: term_int MUL factor_int  */
#line 681 "project.y"
                              { (yyval.ival) = (yyvsp[-2].ival) * (yyvsp[0].ival); }
#line 2322 "project.tab.c"
    break;

  case 164: /* term_int: term_int DIV factor_int  */
#line 682 "project.y"
                              {
    if ((yyvsp[0].ival) == 0) {
        yyerror("Division by zero");
    } else {
        (yyval.ival) = (yyvsp[-2].ival) / (yyvsp[0].ival);
    }
    }
#line 2334 "project.tab.c"
    break;

  case 165: /* term_int: term_int MOD factor_int  */
#line 689 "project.y"
                              {
    if ((yyvsp[0].ival) == 0) {
        yyerror("Division by zero");
    } else {
        (yyval.ival) = fmod((yyvsp[-2].ival), (yyvsp[0].ival));
    }
    }
#line 2346 "project.tab.c"
    break;

  case 166: /* term_int: term_int POW factor_int  */
#line 696 "project.y"
                              {
    if ((yyvsp[-2].ival) == 0 && (yyvsp[0].ival) == 0) {
        yyerror("Exponentiation by zero");
    } else {
        (yyval.ival) = pow((yyvsp[-2].ival), (yyvsp[0].ival));
    }
    }
#line 2358 "project.tab.c"
    break;

  case 167: /* factor_int: primary_int  */
#line 704 "project.y"
                        { (yyval.ival) = (yyvsp[0].ival); }
#line 2364 "project.tab.c"
    break;

  case 168: /* factor_int: LP exp_int RP  */
#line 705 "project.y"
                    { (yyval.ival) = (yyvsp[-1].ival); }
#line 2370 "project.tab.c"
    break;

  case 169: /* exp_double: term_double  */
#line 709 "project.y"
                        { (yyval.dval) = (yyvsp[0].dval); }
#line 2376 "project.tab.c"
    break;

  case 170: /* exp_double: exp_double ADD term_double  */
#line 710 "project.y"
                                 { (yyval.dval) = (yyvsp[-2].dval) + (yyvsp[0].dval); }
#line 2382 "project.tab.c"
    break;

  case 171: /* exp_double: exp_double SUB term_double  */
#line 711 "project.y"
                                 { (yyval.dval) = (yyvsp[-2].dval) - (yyvsp[0].dval); }
#line 2388 "project.tab.c"
    break;

  case 172: /* term_double: factor_double  */
#line 714 "project.y"
                           { (yyval.dval) = (yyvsp[0].dval); }
#line 2394 "project.tab.c"
    break;

  case 173: /* term_double: term_double MUL factor_double  */
#line 715 "project.y"
                                    { (yyval.dval) = (yyvsp[-2].dval) * (yyvsp[0].dval); }
#line 2400 "project.tab.c"
    break;

  case 174: /* term_double: term_double DIV factor_double  */
#line 716 "project.y"
                                    {
    if ((yyvsp[0].dval) == 0) {
        yyerror("Division by zero");
    } else {
        (yyval.dval) = (yyvsp[-2].dval) / (yyvsp[0].dval);
    }
    }
#line 2412 "project.tab.c"
    break;

  case 175: /* term_double: term_double MOD factor_double  */
#line 723 "project.y"
                                    {
    if ((yyvsp[0].dval) == 0) {
        yyerror("Division by zero");
    } else {
        (yyval.dval) = fmod((yyvsp[-2].dval), (yyvsp[0].dval));
    }
    }
#line 2424 "project.tab.c"
    break;

  case 176: /* term_double: term_double POW factor_double  */
#line 730 "project.y"
                                    {
    if ((yyvsp[-2].dval) == 0 && (yyvsp[0].dval) == 0) {
        yyerror("Exponentiation by zero");
    } else {
        (yyval.dval) = pow((yyvsp[-2].dval), (yyvsp[0].dval));
    }
    }
#line 2436 "project.tab.c"
    break;

  case 177: /* factor_double: primary_double  */
#line 738 "project.y"
                              { (yyval.dval) = (yyvsp[0].dval); }
#line 2442 "project.tab.c"
    break;

  case 178: /* factor_double: LP exp_double RP  */
#line 739 "project.y"
                       { (yyval.dval) = (yyvsp[-1].dval); }
#line 2448 "project.tab.c"
    break;

  case 192: /* unary: primary_int  */
#line 762 "project.y"
                   { (yyval.ival) = (yyvsp[0].ival); }
#line 2454 "project.tab.c"
    break;

  case 193: /* unary: ADD primary_int  */
#line 763 "project.y"
                      { (yyval.ival) = (yyvsp[0].ival); }
#line 2460 "project.tab.c"
    break;

  case 194: /* unary: SUB primary_int  */
#line 764 "project.y"
                      { (yyval.ival) = -(yyvsp[0].ival); }
#line 2466 "project.tab.c"
    break;

  case 195: /* primary_int: CONST  */
#line 768 "project.y"
                   { (yyval.ival) = (yyvsp[0].ival); }
#line 2472 "project.tab.c"
    break;

  case 196: /* primary_int: variable_reference  */
#line 769 "project.y"
                         { (yyval.ival) = atoi(getValue((yyvsp[0].sval))); }
#line 2478 "project.tab.c"
    break;

  case 197: /* primary_double: DOUBLE_CONST  */
#line 774 "project.y"
                             { (yyval.dval) = (yyvsp[0].dval); }
#line 2484 "project.tab.c"
    break;

  case 198: /* primary_double: variable_reference  */
#line 775 "project.y"
                         { (yyval.dval) = atof(getValue((yyvsp[0].sval))); }
#line 2490 "project.tab.c"
    break;

  case 199: /* $@5: %empty  */
#line 778 "project.y"
                                                 {
    if (!symbolExists((yyvsp[-4].sval), false, true)) {
        yyerror("Class not declared");
    } else {
        addSymbol((yyvsp[-3].sval), (yyvsp[-4].sval), false, true, false, (yyvsp[0].sval));
    }
    }
#line 2502 "project.tab.c"
    break;

  case 201: /* member_access: ID DOT member_access_body none_or_newlines  */
#line 787 "project.y"
                                                          {
    if (!symbolExists((yyvsp[-3].sval), false, true)) {
        yyerror("Class not declared");
    } else if (!symbolExists((yyvsp[-1].sval), false, false)) {
        yyerror("Member not declared");
    }
    }
#line 2514 "project.tab.c"
    break;

  case 202: /* member_access_body: ID SEMICOLON  */
#line 796 "project.y"
                                 {
    if (!symbolExists((yyvsp[-1].sval), false, false)) {
        yyerror("Variable not declared");
    }
    }
#line 2524 "project.tab.c"
    break;

  case 203: /* member_access_body: method_call  */
#line 801 "project.y"
                  {
    if (!symbolExists((yyvsp[0].sval), true, false)) {
        yyerror("Method not declared");
    }
    }
#line 2534 "project.tab.c"
    break;

  case 206: /* boolean: TRUE  */
#line 811 "project.y"
              { (yyval.sval) = "true"; }
#line 2540 "project.tab.c"
    break;

  case 207: /* boolean: FALSE  */
#line 812 "project.y"
            { (yyval.sval) = "false"; }
#line 2546 "project.tab.c"
    break;

  case 208: /* data_type: %empty  */
#line 815 "project.y"
                         { (yyval.sval) = ""; }
#line 2552 "project.tab.c"
    break;

  case 209: /* data_type: INTEGER  */
#line 816 "project.y"
              { (yyval.sval) = "int"; }
#line 2558 "project.tab.c"
    break;

  case 210: /* data_type: CHAR  */
#line 817 "project.y"
           { (yyval.sval) = "char"; }
#line 2564 "project.tab.c"
    break;

  case 211: /* data_type: DOUBLE  */
#line 818 "project.y"
             { (yyval.sval) = "double"; }
#line 2570 "project.tab.c"
    break;

  case 212: /* data_type: BOOLEAN  */
#line 819 "project.y"
              { (yyval.sval) = "boolean"; }
#line 2576 "project.tab.c"
    break;

  case 213: /* data_type: STRING  */
#line 820 "project.y"
             { (yyval.sval) = "string"; }
#line 2582 "project.tab.c"
    break;

  case 214: /* data_type: VOID  */
#line 821 "project.y"
           { (yyval.sval) = "void"; }
#line 2588 "project.tab.c"
    break;


#line 2592 "project.tab.c"

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

#line 828 "project.y"


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
