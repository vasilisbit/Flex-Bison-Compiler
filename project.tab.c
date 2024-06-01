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
void addSymbol(char *name, char *type, bool isMethod, bool isInitialized) {
    if (name == NULL || type == NULL) {
        fprintf(stderr, "Error: Null pointer in addSymbol function\n");
        exit(1);
    }
    symbolTable[symbolCount].name = strdup(name);
    symbolTable[symbolCount].type = strdup(type);
    symbolTable[symbolCount].isMethod = isMethod;
    symbolTable[symbolCount].isInitialized = isInitialized;
    symbolTable[symbolCount].scope = scope;
    symbolCount++;
}

// Function to check if a symbol is in the symbol table
bool symbolExists(char *name, bool isMethod) {
    if (name == NULL) {
        fprintf(stderr, "Error: Null pointer in symbolExists function\n");
        exit(1);
    }
    for (int i = 0; i < symbolCount; i++) {
        if (symbolTable[i].name != NULL && strcmp(symbolTable[i].name, name) == 0 && symbolTable[i].isMethod == isMethod && symbolTable[i].scope <= scope) {
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


#line 199 "project.tab.c"

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
  YYSYMBOL_assignment_list = 72,           /* assignment_list  */
  YYSYMBOL_variable_declaration = 73,      /* variable_declaration  */
  YYSYMBOL_variable_reference = 74,        /* variable_reference  */
  YYSYMBOL_method_declaration = 75,        /* method_declaration  */
  YYSYMBOL_76_3 = 76,                      /* $@3  */
  YYSYMBOL_77_4 = 77,                      /* $@4  */
  YYSYMBOL_none_or_multiple_parameters = 78, /* none_or_multiple_parameters  */
  YYSYMBOL_parameters = 79,                /* parameters  */
  YYSYMBOL_parameter = 80,                 /* parameter  */
  YYSYMBOL_method_body = 81,               /* method_body  */
  YYSYMBOL_statement = 82,                 /* statement  */
  YYSYMBOL_assignment_statement = 83,      /* assignment_statement  */
  YYSYMBOL_method_call = 84,               /* method_call  */
  YYSYMBOL_none_or_multiple_arguments = 85, /* none_or_multiple_arguments  */
  YYSYMBOL_arguments = 86,                 /* arguments  */
  YYSYMBOL_if_statement = 87,              /* if_statement  */
  YYSYMBOL_88_5 = 88,                      /* $@5  */
  YYSYMBOL_89_6 = 89,                      /* $@6  */
  YYSYMBOL_90_7 = 90,                      /* $@7  */
  YYSYMBOL_91_8 = 91,                      /* $@8  */
  YYSYMBOL_none_or_multiple_elif = 92,     /* none_or_multiple_elif  */
  YYSYMBOL_none_or_one_else = 93,          /* none_or_one_else  */
  YYSYMBOL_do_while_statement = 94,        /* do_while_statement  */
  YYSYMBOL_95_9 = 95,                      /* $@9  */
  YYSYMBOL_96_10 = 96,                     /* $@10  */
  YYSYMBOL_for_statement = 97,             /* for_statement  */
  YYSYMBOL_98_11 = 98,                     /* $@11  */
  YYSYMBOL_first_and_third_loop_statement = 99, /* first_and_third_loop_statement  */
  YYSYMBOL_second_loop_statement = 100,    /* second_loop_statement  */
  YYSYMBOL_switch_statement = 101,         /* switch_statement  */
  YYSYMBOL_102_12 = 102,                   /* $@12  */
  YYSYMBOL_103_13 = 103,                   /* $@13  */
  YYSYMBOL_default_case = 104,             /* default_case  */
  YYSYMBOL_one_or_more_cases = 105,        /* one_or_more_cases  */
  YYSYMBOL_multiple_cases = 106,           /* multiple_cases  */
  YYSYMBOL_cases = 107,                    /* cases  */
  YYSYMBOL_case_expression = 108,          /* case_expression  */
  YYSYMBOL_return_statement = 109,         /* return_statement  */
  YYSYMBOL_break_statement = 110,          /* break_statement  */
  YYSYMBOL_print_statement = 111,          /* print_statement  */
  YYSYMBOL_single_or_multiple_variables = 112, /* single_or_multiple_variables  */
  YYSYMBOL_exp = 113,                      /* exp  */
  YYSYMBOL_factor = 114,                   /* factor  */
  YYSYMBOL_term = 115,                     /* term  */
  YYSYMBOL_relational_exp = 116,           /* relational_exp  */
  YYSYMBOL_relational_factor = 117,        /* relational_factor  */
  YYSYMBOL_logical_term = 118,             /* logical_term  */
  YYSYMBOL_unary = 119,                    /* unary  */
  YYSYMBOL_primary = 120,                  /* primary  */
  YYSYMBOL_object_creation = 121,          /* object_creation  */
  YYSYMBOL_member_access = 122,            /* member_access  */
  YYSYMBOL_123_14 = 123,                   /* $@14  */
  YYSYMBOL_member_access_body = 124,       /* member_access_body  */
  YYSYMBOL_access_modifier = 125,          /* access_modifier  */
  YYSYMBOL_data_type = 126,                /* data_type  */
  YYSYMBOL_none_or_newlines = 127          /* none_or_newlines  */
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
#define YYFINAL  78
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   833

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  155
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  449

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
       0,   183,   183,   184,   185,   188,   188,   189,   189,   192,
     193,   194,   197,   198,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   215,   216,   217,   218,   219,   223,
     239,   239,   240,   240,   243,   244,   247,   248,   251,   254,
     255,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   277,   278,
     282,   294,   295,   296,   299,   300,   301,   304,   304,   305,
     305,   306,   306,   307,   307,   310,   311,   312,   313,   314,
     317,   318,   321,   321,   322,   322,   325,   325,   328,   329,
     332,   333,   336,   336,   337,   337,   340,   341,   344,   347,
     348,   351,   354,   355,   358,   359,   360,   363,   366,   369,
     370,   373,   374,   375,   378,   379,   380,   381,   384,   385,
     388,   389,   390,   391,   392,   393,   394,   397,   398,   399,
     402,   403,   406,   407,   408,   411,   412,   413,   414,   415,
     418,   421,   421,   436,   437,   461,   462,   465,   466,   467,
     468,   469,   470,   471,   487,   488
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
  "assignment_list", "variable_declaration", "variable_reference",
  "method_declaration", "$@3", "$@4", "none_or_multiple_parameters",
  "parameters", "parameter", "method_body", "statement",
  "assignment_statement", "method_call", "none_or_multiple_arguments",
  "arguments", "if_statement", "$@5", "$@6", "$@7", "$@8",
  "none_or_multiple_elif", "none_or_one_else", "do_while_statement", "$@9",
  "$@10", "for_statement", "$@11", "first_and_third_loop_statement",
  "second_loop_statement", "switch_statement", "$@12", "$@13",
  "default_case", "one_or_more_cases", "multiple_cases", "cases",
  "case_expression", "return_statement", "break_statement",
  "print_statement", "single_or_multiple_variables", "exp", "factor",
  "term", "relational_exp", "relational_factor", "logical_term", "unary",
  "primary", "object_creation", "member_access", "$@14",
  "member_access_body", "access_modifier", "data_type", "none_or_newlines", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-345)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-148)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     608,  -345,    68,    10,  -345,    16,  -345,  -345,  -345,  -345,
    -345,  -345,  -345,  -345,    29,   -21,   -19,  -345,   -14,     2,
      -7,    14,   155,   155,    12,   124,    45,    53,  -345,    33,
      41,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    31,    88,     6,   133,    19,  -345,   358,  -345,    53,
      53,   256,   104,   112,    53,    22,    67,   102,   108,   136,
     152,    96,  -345,    53,    53,   107,   142,    53,  -345,   168,
      53,  -345,  -345,  -345,  -345,   120,   174,  -345,  -345,    53,
     608,    53,    53,   721,   608,   721,   721,   721,   721,   721,
     721,   721,   721,    53,   124,   124,   124,   124,   124,   124,
      53,    12,    12,    12,    12,    12,    12,    12,    12,   721,
     721,   201,   196,     9,  -345,  -345,    -5,  -345,  -345,   241,
     176,   101,   182,   200,   188,   208,  -345,  -345,  -345,  -345,
      56,   122,    53,    53,   247,   205,   721,  -345,  -345,  -345,
    -345,   721,   721,  -345,   305,  -345,  -345,  -345,  -345,  -345,
    -345,  -345,  -345,  -345,   721,    88,    88,     6,     6,     6,
    -345,   721,    19,  -345,    19,    19,    19,    19,    19,  -345,
    -345,  -345,  -345,   193,    66,  -345,  -345,   245,    53,  -345,
      53,   215,   215,    53,   271,   273,   273,   273,   273,   273,
     279,    53,    53,    53,     8,    92,    53,     8,   721,   721,
    -345,   250,   287,   294,   257,  -345,  -345,  -345,  -345,  -345,
    -345,    53,   272,  -345,   247,  -345,    53,  -345,  -345,   266,
    -345,   269,  -345,  -345,  -345,  -345,  -345,   277,   663,   281,
     282,   283,   284,   286,   296,    53,    53,    53,   293,   205,
     301,    53,   247,    53,   310,   241,   314,   307,    53,    53,
      53,  -345,  -345,  -345,  -345,  -345,  -345,   306,   308,    12,
     124,  -345,  -345,   663,    53,   309,    53,  -345,   215,   215,
    -345,   325,   663,   311,   663,   313,   315,   316,   317,   318,
     320,   337,   354,   350,   319,    -2,   195,    53,   342,   334,
     305,  -345,  -345,  -345,  -345,  -345,  -345,    53,    53,    53,
      53,    53,    53,   344,   345,    53,   346,   348,  -345,   310,
     721,   721,   721,   721,   373,   373,    53,    53,   247,  -345,
    -345,    53,  -345,    53,    53,    53,    53,     3,    53,    53,
      53,    12,   395,    53,    53,   721,   356,   368,   369,   371,
    -345,  -345,   362,   386,   373,   386,    92,    53,   380,   721,
      53,    53,    53,    53,    53,    53,    53,   391,    53,  -345,
      53,    53,   382,   383,  -345,    53,   381,   721,   414,   414,
     414,   414,   721,    53,   384,   373,   385,   401,   404,   388,
     396,  -345,  -345,   393,    53,    53,    53,    53,  -345,   721,
    -345,  -345,  -345,  -345,  -345,    53,  -345,    56,   428,   428,
     428,   428,  -345,   721,   403,   405,   165,   295,   406,  -345,
    -345,  -345,  -345,    53,   407,   408,   409,   412,    53,   400,
      53,    53,    53,    53,   721,  -345,   721,   721,   721,   721,
      53,    53,    53,    53,    53,   402,   413,   415,   420,   424,
    -345,   414,   414,   414,   414,  -345,  -345,  -345,  -345
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,   135,    29,     0,   136,     0,   145,   146,   148,   149,
     150,   151,   152,   153,     0,     0,     0,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   154,    28,     0,
     137,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     154,     0,   111,   114,     0,   120,   127,   118,   132,   154,
     154,   147,     0,     0,   154,     0,     0,     0,    29,   137,
       0,     0,   118,   154,   154,     0,     0,   154,   107,     0,
     154,    29,   137,   133,   134,     0,     0,   131,     1,   154,
       2,   154,   154,    41,     2,    41,    41,    41,    41,    41,
      41,    41,    41,   154,     0,     0,     0,     0,     0,     0,
     154,     0,     0,     0,     0,     0,     0,     0,     0,    41,
      41,     0,     0,    12,    24,    27,     0,   144,   141,    61,
      16,   137,    20,    14,    22,     0,     7,   105,   106,   104,
       0,     0,   154,   154,    88,   109,    41,   138,   139,   155,
       3,    41,    41,    54,   147,     4,    42,    43,    44,    45,
      46,    47,    48,    49,    41,   112,   113,   115,   116,   117,
     119,    41,   121,   130,   122,   123,   124,   125,   126,   128,
     129,    55,    57,     0,    12,    25,    26,     0,   154,   143,
     154,    64,    64,   154,     0,     0,     0,     0,     0,     0,
       0,   154,   137,   154,   154,   154,   154,   154,    41,    41,
      89,     0,     0,     0,     0,    52,    53,    56,    50,    51,
       5,   154,    12,    13,    34,   142,   154,    63,    62,     0,
      38,     0,    17,    19,    21,    15,    23,     0,     9,     0,
       0,     0,     0,     0,     0,   154,   154,   154,     0,   109,
       0,   154,    34,   154,    36,     0,     0,     0,   154,   154,
     154,    71,    73,    67,    69,    94,    92,     0,     0,    90,
       0,   110,   108,     9,   154,     0,   154,    35,    64,    64,
      60,     0,     9,     0,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    91,   137,    58,   154,     0,     0,
     147,    66,    65,   140,    10,     8,    11,   154,   154,   154,
     154,   154,   154,     0,     0,   154,     0,     0,    32,    36,
      41,    41,    41,    41,     0,     0,   154,   154,    88,     6,
      30,   154,    37,   154,   154,   154,   154,     0,   154,   154,
     154,     0,     0,   154,   154,    39,     0,     0,     0,     0,
     102,   103,     0,    96,    99,    96,   154,   154,     0,    39,
     154,   154,   154,   154,   154,   154,   154,     0,   154,    98,
     154,   154,     0,     0,    86,   154,     0,    39,    75,    75,
      75,    75,    41,   154,     0,    99,     0,     0,     0,     0,
       0,    33,    40,     0,   154,   154,   154,   154,   101,    41,
      95,   100,    93,    83,    85,   154,    31,     0,    80,    80,
      80,    80,    97,    41,   137,     0,     0,     0,     0,    72,
      74,    68,    70,   154,     0,     0,     0,     0,   154,     0,
     154,   154,   154,   154,    41,    87,    41,    41,    41,    41,
     154,   154,   154,   154,   154,     0,     0,     0,     0,     0,
      81,    75,    75,    75,    75,    78,    79,    76,    77
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -345,   -60,    18,  -345,  -345,   -56,  -109,   -42,  -345,   198,
    -345,  -345,  -345,   224,   170,  -115,  -344,     0,  -345,    -6,
    -345,  -173,  -345,  -345,  -345,  -345,  -345,  -330,  -118,  -345,
    -345,  -345,  -345,  -345,   164,  -345,  -345,  -345,  -345,   138,
     169,   110,  -322,  -345,  -345,  -345,  -345,   248,   -12,    82,
     192,   -23,   303,   160,   502,   292,   431,  -345,  -345,  -345,
      13,   -40,   147
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    26,   248,   241,   191,   249,   114,    28,    29,    30,
      31,   334,   321,   243,   267,   244,   350,   250,   200,    33,
     183,   217,    34,   277,   278,   275,   276,   384,   409,    35,
      65,    66,    36,   379,   201,   283,    37,   280,   279,   358,
     328,   359,   329,   342,    38,    39,    40,   204,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,   180,   118,
     144,    52,    80
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,    76,    61,   175,   182,   365,   340,   -59,    60,   218,
     115,   112,    75,    51,    56,     1,    71,    79,    27,     4,
     140,    57,   360,   382,   145,     1,    58,     3,    63,     4,
      64,   179,     1,    58,   -59,    67,     4,   341,    68,   385,
     386,   387,    69,   123,    54,    78,   177,   117,   -59,   122,
      70,    94,    95,   360,    99,    22,    23,   120,   178,     1,
      58,    24,    79,     4,    55,    22,    23,    93,   213,    81,
     176,    24,    22,    23,    94,    95,    25,    82,    24,   184,
      32,   107,   108,   143,    32,   146,   147,   148,   149,   150,
     151,   152,   153,    51,   202,   291,   292,    51,    27,    22,
      23,    79,    27,   177,   112,    24,    53,   195,   113,   171,
     172,   445,   446,   447,   448,   211,   116,    54,   194,   197,
      25,    55,   125,    55,   193,     1,    71,     1,    71,     4,
     269,     4,   129,    96,    97,    98,   205,   -18,   186,    94,
      95,   206,   207,   222,   223,   224,   225,   226,   101,   102,
     103,   104,   105,   106,   208,   126,   196,    54,     1,    71,
     132,   209,     4,    94,    95,    22,    23,    22,    23,   100,
     137,    24,   127,    24,   184,   309,   155,   156,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,   128,   101,
     102,   103,   104,   105,   106,   133,   109,   110,   235,   236,
     174,   119,   184,   135,    24,   184,   173,   287,    94,    95,
     130,   131,    59,   185,   134,   416,   294,   136,   296,   187,
      72,    72,    72,    72,   138,   189,   139,   190,   141,   142,
     101,   102,   103,   104,   105,   106,   284,   188,    94,    95,
     154,    51,   203,    94,    95,    71,   210,   161,   286,   212,
     184,  -147,   216,   121,     8,     9,    10,    11,    12,    13,
       8,     9,    10,    11,    12,    13,   111,   169,   170,     8,
       9,    10,    11,    12,    13,   220,    51,   221,   202,   198,
     199,   410,   411,   412,   227,    51,   237,    51,   157,   158,
     159,   238,    72,    72,    72,    72,    72,    72,   239,    72,
      72,    72,    72,    72,    72,    72,    72,   240,   346,   177,
     323,   324,   325,   326,    73,    74,   246,   181,     8,     9,
      10,    11,    12,    13,    55,   214,   247,   215,   192,    72,
     219,   251,   252,   253,   254,   351,   255,   262,   228,   229,
     230,   231,   232,   233,   234,   417,   256,   266,   260,   351,
     270,   101,   102,   103,   104,   105,   106,   271,   242,   289,
     281,   293,   282,   245,   303,   295,   297,   351,   298,   299,
     300,   301,   388,   302,   407,   101,   102,   103,   104,   105,
     106,   304,   257,   258,   259,   406,   305,   308,   263,   402,
     265,   405,   307,   316,   317,   272,   273,   274,   327,    71,
     319,   320,   356,   413,   162,   164,   165,   166,   167,   168,
     352,   288,   357,   290,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,   353,   354,   430,   355,   431,   432,   433,   434,
     364,   373,   377,   378,   306,   381,   383,   393,   390,   392,
     394,   395,   397,   268,   310,   311,   312,   313,   314,   315,
     396,   408,   318,   414,   425,   415,   440,    72,   285,   418,
     420,   421,   422,   331,   332,   423,   264,   441,   335,   442,
     336,   337,   338,   339,   443,   343,   344,   345,   444,   322,
     348,   349,   333,   361,   330,   391,   124,   261,     0,     0,
       0,     0,     0,   362,   363,     0,     0,   366,   367,   368,
     369,   370,   371,   372,     0,   374,     0,   375,   376,     0,
       0,     0,   380,     0,     0,     0,    62,     0,     0,     0,
     389,     0,     0,     0,     0,     0,     0,    77,     0,    72,
     347,   398,   399,   400,   401,     0,     0,     0,     0,     0,
       0,     0,   403,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    62,     0,     0,
     419,     0,     0,     0,     0,   424,     0,   426,   427,   428,
     429,     0,     0,     0,     0,     0,     0,   435,   436,   437,
     438,   439,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   404,    62,    62,    62,    62,
      62,   160,     0,   163,   163,   163,   163,   163,   163,   163,
     163,     1,     2,     3,     0,     4,     0,   -41,     5,     6,
       7,     8,     9,    10,    11,    12,    13,     0,    14,    15,
       0,     0,    16,    62,     0,     0,    17,    18,    19,     0,
       0,    20,     0,    21,     0,     0,     0,     0,     0,     0,
       0,    22,    23,     0,     0,     0,     0,    24,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     2,     3,     0,
       4,     0,    25,     5,     6,     7,     8,     9,    10,    11,
      12,    13,     0,    14,    15,     0,     0,    16,     0,     0,
       0,    17,    18,    19,     0,     0,    20,     0,    21,     0,
       0,     0,     0,     0,     0,     0,    22,    23,     0,     0,
       0,     0,    24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     3,    25,     4,     0,
       0,     0,     6,     7,     8,     9,    10,    11,    12,    13,
       0,    14,    15,     0,     0,    16,     0,     0,     0,    17,
      18,    19,     0,     0,    20,     0,    21,     0,     0,     0,
       0,   163,    62,     0,    22,    23,     0,     0,     0,     0,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   163
};

static const yytype_int16 yycheck[] =
{
       0,    24,    14,   112,   119,   349,     3,     9,    14,   182,
      52,    51,    24,     0,     4,     3,     4,     9,     0,     7,
      80,     5,   344,   367,    84,     3,     4,     5,    49,     7,
      49,    36,     3,     4,    36,    49,     7,    34,    36,   369,
     370,   371,    49,    55,    49,     0,    37,    53,    50,    55,
      36,    43,    44,   375,    48,    43,    44,    35,    49,     3,
       4,    49,     9,     7,    55,    43,    44,    36,   177,    36,
     112,    49,    43,    44,    43,    44,    64,    36,    49,   119,
      80,    62,    63,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    80,   134,   268,   269,    84,    80,    43,
      44,     9,    84,    37,   144,    49,    38,   130,     4,   109,
     110,   441,   442,   443,   444,    49,     4,    49,   130,   131,
      64,    55,    55,    55,   130,     3,     4,     3,     4,     7,
     245,     7,    36,    45,    46,    47,   136,    36,    37,    43,
      44,   141,   142,   185,   186,   187,   188,   189,    56,    57,
      58,    59,    60,    61,   154,    53,    34,    49,     3,     4,
      53,   161,     7,    43,    44,    43,    44,    43,    44,    36,
      50,    49,    36,    49,   214,   290,    94,    95,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    36,    56,
      57,    58,    59,    60,    61,    53,    49,    50,   198,   199,
       4,    54,   242,    35,    49,   245,     5,   263,    43,    44,
      63,    64,    14,    37,    67,    50,   272,    70,   274,    37,
      22,    23,    24,    25,    50,    37,    79,    19,    81,    82,
      56,    57,    58,    59,    60,    61,   259,    37,    43,    44,
      93,   228,    37,    43,    44,     4,    53,   100,   260,     4,
     290,     4,    37,    55,    13,    14,    15,    16,    17,    18,
      13,    14,    15,    16,    17,    18,    10,   107,   108,    13,
      14,    15,    16,    17,    18,     4,   263,     4,   318,   132,
     133,   399,   400,   401,     5,   272,    36,   274,    96,    97,
      98,     4,    94,    95,    96,    97,    98,    99,     4,   101,
     102,   103,   104,   105,   106,   107,   108,    50,   331,    37,
     310,   311,   312,   313,    22,    23,    50,   119,    13,    14,
      15,    16,    17,    18,    55,   178,    49,   180,   130,   131,
     183,    50,    50,    50,    50,   335,    50,    36,   191,   192,
     193,   194,   195,   196,   197,    50,    50,    37,    55,   349,
      36,    56,    57,    58,    59,    60,    61,    50,   211,    50,
      54,    36,    54,   216,    27,    54,    53,   367,    53,    53,
      53,    53,   372,    53,   397,    56,    57,    58,    59,    60,
      61,    27,   235,   236,   237,   397,    36,    53,   241,   389,
     243,   397,    50,    49,    49,   248,   249,   250,    25,     4,
      54,    53,    40,   403,   101,   102,   103,   104,   105,   106,
      54,   264,    26,   266,    56,    57,    58,    59,    60,    61,
      62,    63,    54,    54,   424,    54,   426,   427,   428,   429,
      50,    40,    50,    50,   287,    54,    22,    36,    54,    54,
      36,    53,    49,   245,   297,   298,   299,   300,   301,   302,
      54,    23,   305,    50,    54,    50,    54,   259,   260,    53,
      53,    53,    53,   316,   317,    53,   242,    54,   321,    54,
     323,   324,   325,   326,    54,   328,   329,   330,    54,   309,
     333,   334,   318,   345,   315,   375,    55,   239,    -1,    -1,
      -1,    -1,    -1,   346,   347,    -1,    -1,   350,   351,   352,
     353,   354,   355,   356,    -1,   358,    -1,   360,   361,    -1,
      -1,    -1,   365,    -1,    -1,    -1,    14,    -1,    -1,    -1,
     373,    -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,   331,
     332,   384,   385,   386,   387,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   395,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,
     413,    -1,    -1,    -1,    -1,   418,    -1,   420,   421,   422,
     423,    -1,    -1,    -1,    -1,    -1,    -1,   430,   431,   432,
     433,   434,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   397,    94,    95,    96,    97,
      98,    99,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,     3,     4,     5,    -1,     7,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    -1,    20,    21,
      -1,    -1,    24,   131,    -1,    -1,    28,    29,    30,    -1,
      -1,    33,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    -1,    -1,    -1,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
       7,    -1,    64,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,    20,    21,    -1,    -1,    24,    -1,    -1,
      -1,    28,    29,    30,    -1,    -1,    33,    -1,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    64,     7,    -1,
      -1,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
      -1,    20,    21,    -1,    -1,    24,    -1,    -1,    -1,    28,
      29,    30,    -1,    -1,    33,    -1,    35,    -1,    -1,    -1,
      -1,   259,   260,    -1,    43,    44,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   331
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     7,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    20,    21,    24,    28,    29,    30,
      33,    35,    43,    44,    49,    64,    66,    67,    72,    73,
      74,    75,    82,    84,    87,    94,    97,   101,   109,   110,
     111,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   125,   126,    38,    49,    55,     4,     5,     4,    74,
      84,   113,   119,    49,    49,    95,    96,    49,    36,    49,
      36,     4,    74,   120,   120,   113,   116,   119,     0,     9,
     127,    36,    36,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,    36,    43,    44,    45,    46,    47,    48,
      36,    56,    57,    58,    59,    60,    61,    62,    63,   127,
     127,    10,   126,     4,    71,    72,     4,    84,   124,   127,
      35,    74,    84,   113,   121,    55,    53,    36,    36,    36,
     127,   127,    53,    53,   127,    35,   127,    50,    50,   127,
      66,   127,   127,    82,   125,    66,    82,    82,    82,    82,
      82,    82,    82,    82,   127,   114,   114,   115,   115,   115,
     119,   127,   117,   119,   117,   117,   117,   117,   117,   118,
     118,    82,    82,     5,     4,    71,    72,    37,    49,    36,
     123,    74,    80,    85,   126,    37,    37,    37,    37,    37,
      19,    69,    74,    84,   113,   116,    34,   113,   127,   127,
      83,    99,   126,    37,   112,    82,    82,    82,    82,    82,
      53,    49,     4,    71,   127,   127,    37,    86,    86,   127,
       4,     4,    72,    72,    72,    72,    72,     5,   127,   127,
     127,   127,   127,   127,   127,    82,    82,    36,     4,     4,
      50,    68,   127,    78,    80,   127,    50,    49,    67,    70,
      82,    50,    50,    50,    50,    50,    50,   127,   127,   127,
      55,   112,    36,   127,    78,   127,    37,    79,    74,    80,
      36,    50,   127,   127,   127,    90,    91,    88,    89,   103,
     102,    54,    54,   100,   116,    74,   113,    70,   127,    50,
     127,    86,    86,    36,    70,    54,    70,    53,    53,    53,
      53,    53,    53,    27,    27,    36,   127,    50,    53,    80,
     127,   127,   127,   127,   127,   127,    49,    49,   127,    54,
      53,    77,    79,    82,    82,    82,    82,    25,   105,   107,
     105,   127,   127,    99,    76,   127,   127,   127,   127,   127,
       3,    34,   108,   127,   127,   127,   116,    74,   127,   127,
      81,    82,    54,    54,    54,    54,    40,    26,   104,   106,
     107,   104,   127,   127,    50,    81,   127,   127,   127,   127,
     127,   127,   127,    40,   127,   127,   127,    50,    50,    98,
     127,    54,    81,    22,    92,    92,    92,    92,    82,   127,
      54,   106,    54,    36,    36,    53,    54,    49,   127,   127,
     127,   127,    82,   127,    74,    84,   113,   116,    23,    93,
      93,    93,    93,    82,    50,    50,    50,    50,    53,   127,
      53,    53,    53,    53,   127,    54,   127,   127,   127,   127,
      82,    82,    82,    82,    82,   127,   127,   127,   127,   127,
      54,    54,    54,    54,    54,    92,    92,    92,    92
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    66,    66,    66,    68,    67,    69,    67,    70,
      70,    70,    71,    71,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    73,    73,    73,    73,    73,    74,
      76,    75,    77,    75,    78,    78,    79,    79,    80,    81,
      81,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    83,    83,
      84,    85,    85,    85,    86,    86,    86,    88,    87,    89,
      87,    90,    87,    91,    87,    92,    92,    92,    92,    92,
      93,    93,    95,    94,    96,    94,    98,    97,    99,    99,
     100,   100,   102,   101,   103,   101,   104,   104,   105,   106,
     106,   107,   108,   108,   109,   109,   109,   110,   111,   112,
     112,   113,   113,   113,   114,   114,   114,   114,   115,   115,
     116,   116,   116,   116,   116,   116,   116,   117,   117,   117,
     118,   118,   119,   119,   119,   120,   120,   120,   120,   120,
     121,   123,   122,   124,   124,   125,   125,   126,   126,   126,
     126,   126,   126,   126,   127,   127
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     3,     0,     9,     0,     8,     0,
       3,     3,     1,     3,     3,     5,     3,     5,     3,     5,
       3,     5,     3,     5,     2,     3,     3,     2,     1,     1,
       0,    14,     0,    13,     0,     2,     0,     4,     2,     0,
       3,     0,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     4,     4,     4,     3,     3,     4,     3,     4,     4,
       7,     0,     2,     2,     0,     4,     4,     0,    16,     0,
      16,     0,    16,     0,    16,     0,    10,    10,    10,    10,
       0,     6,     0,    14,     0,    14,     0,    18,     0,     1,
       0,     1,     0,    14,     0,    14,     0,     4,     3,     0,
       3,     5,     1,     1,     3,     3,     3,     2,     6,     0,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     3,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       1,     2,     1,     2,     2,     1,     1,     1,     3,     3,
       8,     0,     5,     2,     1,     1,     1,     0,     1,     1,
       1,     1,     1,     1,     0,     2
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
#line 188 "project.y"
                                                      { increaseScope(); }
#line 1682 "project.tab.c"
    break;

  case 6: /* class_declaration: access_modifier CLASS CLASS_ID LCB $@1 none_or_newlines class_body none_or_newlines RCB  */
#line 188 "project.y"
                                                                                                                            { decreaseScope(); }
#line 1688 "project.tab.c"
    break;

  case 7: /* $@2: %empty  */
#line 189 "project.y"
                         { increaseScope(); }
#line 1694 "project.tab.c"
    break;

  case 8: /* class_declaration: CLASS CLASS_ID LCB $@2 none_or_newlines class_body none_or_newlines RCB  */
#line 189 "project.y"
                                                                                               { decreaseScope(); }
#line 1700 "project.tab.c"
    break;

  case 14: /* assignment_list: ID ASSIGN exp  */
#line 202 "project.y"
                               { if (strcmp(getType((yyvsp[-2].sval)), "int") != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-2].sval)); }
#line 1706 "project.tab.c"
    break;

  case 15: /* assignment_list: ID ASSIGN exp COMMA assignment_list  */
#line 203 "project.y"
                                          { if (strcmp(getType((yyvsp[-4].sval)), "int") != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-4].sval)); }
#line 1712 "project.tab.c"
    break;

  case 16: /* assignment_list: ID ASSIGN DQ_STRING_DQ  */
#line 204 "project.y"
                             { if (strcmp(getType((yyvsp[-2].sval)), "string") != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-2].sval)); }
#line 1718 "project.tab.c"
    break;

  case 17: /* assignment_list: ID ASSIGN DQ_STRING_DQ COMMA assignment_list  */
#line 205 "project.y"
                                                   { if (strcmp(getType((yyvsp[-4].sval)), "string") != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-4].sval)); }
#line 1724 "project.tab.c"
    break;

  case 18: /* assignment_list: ID ASSIGN variable_reference  */
#line 206 "project.y"
                                   { if (strcmp(getType((yyvsp[-2].sval)), getType((yyvsp[0].sval))) != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-2].sval)); }
#line 1730 "project.tab.c"
    break;

  case 19: /* assignment_list: ID ASSIGN variable_reference COMMA assignment_list  */
#line 207 "project.y"
                                                         { if (strcmp(getType((yyvsp[-4].sval)), getType((yyvsp[-2].sval))) != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-4].sval)); }
#line 1736 "project.tab.c"
    break;

  case 20: /* assignment_list: ID ASSIGN method_call  */
#line 208 "project.y"
                            { if (strcmp(getType((yyvsp[-2].sval)), "int") != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-2].sval)); }
#line 1742 "project.tab.c"
    break;

  case 21: /* assignment_list: ID ASSIGN method_call COMMA assignment_list  */
#line 209 "project.y"
                                                  { if (strcmp(getType((yyvsp[-4].sval)), "int") != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-4].sval)); }
#line 1748 "project.tab.c"
    break;

  case 22: /* assignment_list: ID ASSIGN object_creation  */
#line 210 "project.y"
                                { if (strcmp(getType((yyvsp[-2].sval)), "object") != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-2].sval)); }
#line 1754 "project.tab.c"
    break;

  case 23: /* assignment_list: ID ASSIGN object_creation COMMA assignment_list  */
#line 211 "project.y"
                                                      { if (strcmp(getType((yyvsp[-4].sval)), "object") != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-4].sval)); }
#line 1760 "project.tab.c"
    break;

  case 24: /* variable_declaration: data_type identifier_list  */
#line 215 "project.y"
                                                { addSymbol((yyvsp[0].sval), (yyvsp[-1].sval), false, false); }
#line 1766 "project.tab.c"
    break;

  case 25: /* variable_declaration: access_modifier data_type identifier_list  */
#line 216 "project.y"
                                                { addSymbol((yyvsp[0].sval), (yyvsp[-1].sval), false, false); }
#line 1772 "project.tab.c"
    break;

  case 26: /* variable_declaration: access_modifier data_type assignment_list  */
#line 217 "project.y"
                                                { addSymbol((yyvsp[0].sval), (yyvsp[-1].sval), false, true); }
#line 1778 "project.tab.c"
    break;

  case 27: /* variable_declaration: data_type assignment_list  */
#line 218 "project.y"
                                { addSymbol((yyvsp[0].sval), (yyvsp[-1].sval), false, true); }
#line 1784 "project.tab.c"
    break;

  case 28: /* variable_declaration: assignment_list  */
#line 219 "project.y"
                      { addSymbol((yyvsp[0].sval), NULL, false, true); }
#line 1790 "project.tab.c"
    break;

  case 29: /* variable_reference: ID  */
#line 223 "project.y"
                       {
    char *name = (yyvsp[0].sval);
    if (name == NULL) {
        yyerror("Name is null");
        return;
    }
    if (!symbolExists(name, false)) {
        yyerror("Variable not declared");
    } else if (!isInitialized(name)) {
        yyerror("Variable not initialized");
    }
}
#line 1807 "project.tab.c"
    break;

  case 30: /* $@3: %empty  */
#line 239 "project.y"
                                                                                                                         { increaseScope(); }
#line 1813 "project.tab.c"
    break;

  case 31: /* method_declaration: access_modifier data_type ID LP none_or_newlines none_or_multiple_parameters none_or_newlines RP LCB $@3 none_or_newlines method_body none_or_newlines RCB  */
#line 239 "project.y"
                                                                                                                                                                                                { addSymbol((yyvsp[-11].sval), (yyvsp[-12].sval), true, true); decreaseScope(); }
#line 1819 "project.tab.c"
    break;

  case 32: /* $@4: %empty  */
#line 240 "project.y"
                                                                                           { increaseScope(); }
#line 1825 "project.tab.c"
    break;

  case 33: /* method_declaration: data_type ID LP none_or_newlines none_or_multiple_parameters none_or_newlines RP LCB $@4 none_or_newlines method_body none_or_newlines RCB  */
#line 240 "project.y"
                                                                                                                                                                  { addSymbol((yyvsp[-11].sval), (yyvsp[-12].sval), true, true); decreaseScope(); }
#line 1831 "project.tab.c"
    break;

  case 60: /* method_call: ID LP none_or_newlines none_or_multiple_arguments none_or_newlines RP SEMICOLON  */
#line 282 "project.y"
                                                                                             {
    char *name = (yyvsp[-6].sval);
    if (name == NULL) {
        yyerror("Name is null");
        return;
    }
    if (!symbolExists(name, true)) {
        yyerror("Method not declared");
    }
}
#line 1846 "project.tab.c"
    break;

  case 67: /* $@5: %empty  */
#line 304 "project.y"
                                                             { increaseScope(); }
#line 1852 "project.tab.c"
    break;

  case 68: /* if_statement: IF LP none_or_newlines exp none_or_newlines RP $@5 LCB none_or_newlines statement none_or_newlines RCB none_or_newlines none_or_multiple_elif none_or_newlines none_or_one_else  */
#line 304 "project.y"
                                                                                                                                                                                                               { decreaseScope(); }
#line 1858 "project.tab.c"
    break;

  case 69: /* $@6: %empty  */
#line 305 "project.y"
                                                                { increaseScope(); }
#line 1864 "project.tab.c"
    break;

  case 70: /* if_statement: IF LP none_or_newlines relational_exp none_or_newlines RP $@6 LCB none_or_newlines statement none_or_newlines RCB none_or_newlines none_or_multiple_elif none_or_newlines none_or_one_else  */
#line 305 "project.y"
                                                                                                                                                                                                                  { decreaseScope(); }
#line 1870 "project.tab.c"
    break;

  case 71: /* $@7: %empty  */
#line 306 "project.y"
                                                                    { increaseScope(); }
#line 1876 "project.tab.c"
    break;

  case 72: /* if_statement: IF LP none_or_newlines variable_reference none_or_newlines RP $@7 LCB none_or_newlines statement none_or_newlines RCB none_or_newlines none_or_multiple_elif none_or_newlines none_or_one_else  */
#line 306 "project.y"
                                                                                                                                                                                                                      { decreaseScope(); }
#line 1882 "project.tab.c"
    break;

  case 73: /* $@8: %empty  */
#line 307 "project.y"
                                                             { increaseScope(); }
#line 1888 "project.tab.c"
    break;

  case 74: /* if_statement: IF LP none_or_newlines method_call none_or_newlines RP $@8 LCB none_or_newlines statement none_or_newlines RCB none_or_newlines none_or_multiple_elif none_or_newlines none_or_one_else  */
#line 307 "project.y"
                                                                                                                                                                                                               { decreaseScope(); }
#line 1894 "project.tab.c"
    break;

  case 82: /* $@9: %empty  */
#line 321 "project.y"
                       { increaseScope(); }
#line 1900 "project.tab.c"
    break;

  case 83: /* do_while_statement: DO $@9 LCB none_or_newlines statement none_or_newlines RCB WHILE LP none_or_newlines relational_exp none_or_newlines RP SEMICOLON  */
#line 321 "project.y"
                                                                                                                                                                       { decreaseScope(); }
#line 1906 "project.tab.c"
    break;

  case 84: /* $@10: %empty  */
#line 322 "project.y"
         { increaseScope(); }
#line 1912 "project.tab.c"
    break;

  case 85: /* do_while_statement: DO $@10 LCB none_or_newlines statement none_or_newlines RCB WHILE LP none_or_newlines variable_reference none_or_newlines RP SEMICOLON  */
#line 322 "project.y"
                                                                                                                                                             { decreaseScope(); }
#line 1918 "project.tab.c"
    break;

  case 86: /* $@11: %empty  */
#line 325 "project.y"
                                                                                                                                                                                                     { increaseScope(); }
#line 1924 "project.tab.c"
    break;

  case 87: /* for_statement: FOR LP none_or_newlines first_and_third_loop_statement SEMICOLON none_or_newlines second_loop_statement SEMICOLON none_or_newlines first_and_third_loop_statement none_or_newlines RP $@11 LCB none_or_newlines statement none_or_newlines RCB  */
#line 325 "project.y"
                                                                                                                                                                                                                                                                              { decreaseScope(); }
#line 1930 "project.tab.c"
    break;

  case 92: /* $@12: %empty  */
#line 336 "project.y"
                                                                     { increaseScope(); }
#line 1936 "project.tab.c"
    break;

  case 93: /* switch_statement: SWITCH LP none_or_newlines exp none_or_newlines RP $@12 LCB none_or_newlines one_or_more_cases none_or_newlines default_case none_or_newlines RCB  */
#line 336 "project.y"
                                                                                                                                                                                    { decreaseScope(); }
#line 1942 "project.tab.c"
    break;

  case 94: /* $@13: %empty  */
#line 337 "project.y"
                                                                   { increaseScope(); }
#line 1948 "project.tab.c"
    break;

  case 95: /* switch_statement: SWITCH LP none_or_newlines SQ_ANYCHAR_SQ none_or_newlines RP $@13 LCB none_or_newlines one_or_more_cases none_or_newlines default_case none_or_newlines RCB  */
#line 337 "project.y"
                                                                                                                                                                                  { decreaseScope(); }
#line 1954 "project.tab.c"
    break;

  case 110: /* single_or_multiple_variables: COMMA ID single_or_multiple_variables  */
#line 370 "project.y"
                                            { if (!symbolExists((yyvsp[-1].sval), false)) { yyerror("Variable not declared"); } else if (!isInitialized((yyvsp[-1].sval))) { yyerror("Variable not initialized"); } }
#line 1960 "project.tab.c"
    break;

  case 141: /* $@14: %empty  */
#line 421 "project.y"
                                         {
    char *name = (yyvsp[-2].sval);
    if (name == NULL) {
        yyerror("Name is null");
        return;
    }
    if (!symbolExists(name, false)) {
        yyerror("Class not declared");
    }
    if (!symbolExists((yyvsp[0].sval), false)) {
        yyerror("Member not declared");
    }
}
#line 1978 "project.tab.c"
    break;

  case 143: /* member_access_body: ID SEMICOLON  */
#line 436 "project.y"
                                 { if (!symbolExists((yyvsp[-1].sval), false)) { yyerror("Variable not declared"); } }
#line 1984 "project.tab.c"
    break;

  case 144: /* member_access_body: method_call  */
#line 437 "project.y"
                  { if (!symbolExists((yyvsp[0].sval), true)) { yyerror("Method not declared"); } }
#line 1990 "project.tab.c"
    break;

  case 147: /* data_type: %empty  */
#line 465 "project.y"
                         { (yyval.sval) = ""; }
#line 1996 "project.tab.c"
    break;

  case 148: /* data_type: INTEGER  */
#line 466 "project.y"
              { (yyval.sval) = "int"; }
#line 2002 "project.tab.c"
    break;

  case 149: /* data_type: CHAR  */
#line 467 "project.y"
           { (yyval.sval) = "char"; }
#line 2008 "project.tab.c"
    break;

  case 150: /* data_type: DOUBLE  */
#line 468 "project.y"
             { (yyval.sval) = "double"; }
#line 2014 "project.tab.c"
    break;

  case 151: /* data_type: BOOLEAN  */
#line 469 "project.y"
              { (yyval.sval) = "boolean"; }
#line 2020 "project.tab.c"
    break;

  case 152: /* data_type: STRING  */
#line 470 "project.y"
             { (yyval.sval) = "string"; }
#line 2026 "project.tab.c"
    break;

  case 153: /* data_type: VOID  */
#line 471 "project.y"
           { (yyval.sval) = "void"; }
#line 2032 "project.tab.c"
    break;


#line 2036 "project.tab.c"

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

#line 491 "project.y"


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
