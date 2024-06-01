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
  YYSYMBOL_none_or_multiple_elif = 88,     /* none_or_multiple_elif  */
  YYSYMBOL_none_or_one_else = 89,          /* none_or_one_else  */
  YYSYMBOL_do_while_statement = 90,        /* do_while_statement  */
  YYSYMBOL_for_statement = 91,             /* for_statement  */
  YYSYMBOL_first_and_third_loop_statement = 92, /* first_and_third_loop_statement  */
  YYSYMBOL_second_loop_statement = 93,     /* second_loop_statement  */
  YYSYMBOL_switch_statement = 94,          /* switch_statement  */
  YYSYMBOL_default_case = 95,              /* default_case  */
  YYSYMBOL_one_or_more_cases = 96,         /* one_or_more_cases  */
  YYSYMBOL_multiple_cases = 97,            /* multiple_cases  */
  YYSYMBOL_cases = 98,                     /* cases  */
  YYSYMBOL_case_expression = 99,           /* case_expression  */
  YYSYMBOL_return_statement = 100,         /* return_statement  */
  YYSYMBOL_break_statement = 101,          /* break_statement  */
  YYSYMBOL_print_statement = 102,          /* print_statement  */
  YYSYMBOL_single_or_multiple_variables = 103, /* single_or_multiple_variables  */
  YYSYMBOL_exp = 104,                      /* exp  */
  YYSYMBOL_factor = 105,                   /* factor  */
  YYSYMBOL_term = 106,                     /* term  */
  YYSYMBOL_relational_exp = 107,           /* relational_exp  */
  YYSYMBOL_relational_factor = 108,        /* relational_factor  */
  YYSYMBOL_logical_term = 109,             /* logical_term  */
  YYSYMBOL_unary = 110,                    /* unary  */
  YYSYMBOL_primary = 111,                  /* primary  */
  YYSYMBOL_object_creation = 112,          /* object_creation  */
  YYSYMBOL_member_access = 113,            /* member_access  */
  YYSYMBOL_114_5 = 114,                    /* $@5  */
  YYSYMBOL_member_access_body = 115,       /* member_access_body  */
  YYSYMBOL_access_modifier = 116,          /* access_modifier  */
  YYSYMBOL_data_type = 117,                /* data_type  */
  YYSYMBOL_none_or_newlines = 118          /* none_or_newlines  */
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
#define YYFINAL  77
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   711

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  146
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  432

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
     228,   228,   229,   229,   232,   233,   236,   237,   240,   243,
     244,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   266,   267,
     271,   274,   275,   276,   279,   280,   281,   284,   285,   286,
     287,   290,   291,   292,   293,   294,   297,   298,   301,   302,
     305,   308,   309,   312,   313,   316,   317,   320,   321,   324,
     327,   328,   331,   334,   335,   338,   339,   340,   343,   346,
     349,   350,   353,   354,   355,   358,   359,   360,   361,   364,
     365,   368,   369,   370,   371,   372,   373,   374,   377,   378,
     379,   382,   383,   386,   387,   388,   391,   392,   393,   394,
     395,   398,   401,   401,   404,   405,   408,   409,   412,   413,
     414,   415,   416,   417,   418,   421,   422
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
  "arguments", "if_statement", "none_or_multiple_elif", "none_or_one_else",
  "do_while_statement", "for_statement", "first_and_third_loop_statement",
  "second_loop_statement", "switch_statement", "default_case",
  "one_or_more_cases", "multiple_cases", "cases", "case_expression",
  "return_statement", "break_statement", "print_statement",
  "single_or_multiple_variables", "exp", "factor", "term",
  "relational_exp", "relational_factor", "logical_term", "unary",
  "primary", "object_creation", "member_access", "$@5",
  "member_access_body", "access_modifier", "data_type", "none_or_newlines", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-343)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-139)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     495,  -343,    57,    22,  -343,    18,  -343,  -343,  -343,  -343,
    -343,  -343,  -343,  -343,   194,   -45,   -17,   -16,    15,    16,
      17,    32,    47,    47,   142,   257,   130,   106,  -343,    58,
     121,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,    37,   115,   124,   307,    80,  -343,   489,  -343,   106,
     106,   519,   159,   183,   106,   370,   144,   152,   158,   177,
     180,    82,  -343,   106,   106,   106,   106,  -343,   182,   106,
    -343,  -343,  -343,  -343,    85,   407,  -343,  -343,   106,   495,
     106,   106,   604,   495,   604,   604,   604,   604,   604,   604,
     604,   604,   106,   257,   257,   257,   257,   257,   257,   106,
     142,   142,   142,   142,   142,   142,   142,   142,   604,   604,
     213,   218,    20,  -343,  -343,    23,  -343,  -343,   380,   187,
     111,   188,    76,   196,   216,  -343,  -343,  -343,  -343,   151,
      27,   604,   438,   202,   604,  -343,  -343,  -343,  -343,   604,
     604,  -343,   587,  -343,  -343,  -343,  -343,  -343,  -343,  -343,
    -343,  -343,   604,   115,   115,   124,   124,   124,  -343,   604,
      80,  -343,    80,    80,    80,    80,    80,  -343,  -343,  -343,
    -343,   189,    55,  -343,  -343,   236,   106,  -343,   106,   204,
     204,   106,   247,   248,   248,   248,   248,   248,   249,   106,
     106,   106,    34,   171,   106,    34,   106,  -343,   217,   251,
     253,   209,  -343,  -343,  -343,  -343,  -343,  -343,   106,   225,
    -343,   438,  -343,   106,  -343,  -343,   215,  -343,   208,  -343,
    -343,  -343,  -343,  -343,   219,   550,   220,   221,   224,   226,
     232,   237,   212,   106,   234,   202,   231,   106,   438,   106,
     258,   380,   260,   262,   106,   106,   106,   245,   246,   261,
     264,   265,   266,   293,   142,   257,  -343,  -343,   550,   106,
     273,   106,  -343,   204,   204,  -343,   288,   550,   271,   550,
     106,   106,   106,   106,   106,   106,   277,   291,   598,    13,
     135,   106,   279,   280,   587,  -343,  -343,  -343,  -343,  -343,
    -343,   604,   604,   604,   604,   305,   305,   106,   106,   282,
     281,  -343,   258,   106,   106,   106,   106,    -1,   106,   106,
     106,   142,   438,  -343,  -343,   106,  -343,   283,   284,   290,
     294,  -343,  -343,   309,   321,   305,   321,   106,   171,   106,
     106,   604,   106,   106,   106,   106,   106,   311,   106,  -343,
     106,   106,   303,   308,   310,   604,   106,   106,   337,   337,
     337,   337,   604,   106,   316,   305,   318,   325,   347,   346,
     106,   348,   604,   352,   106,   106,   106,   106,  -343,   604,
    -343,  -343,  -343,  -343,  -343,   106,   349,  -343,  -343,   151,
     383,   383,   383,   383,  -343,   604,  -343,   358,   366,    94,
     419,   364,  -343,  -343,  -343,  -343,   106,   365,   367,   368,
     369,   106,   377,   106,   106,   106,   106,   604,  -343,   604,
     604,   604,   604,   106,   106,   106,   106,   106,   386,   387,
     389,   392,   393,  -343,   337,   337,   337,   337,  -343,  -343,
    -343,  -343
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,   126,    29,     0,   127,     0,   136,   137,   139,   140,
     141,   142,   143,   144,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   145,    28,     0,
     128,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,     0,   102,   105,     0,   111,   118,   109,   123,   145,
     145,   138,     0,     0,   145,     0,     0,     0,    29,   128,
       0,     0,   109,   145,   145,   145,   145,    98,     0,   145,
      29,   128,   124,   125,     0,     0,   122,     1,   145,     2,
     145,   145,    41,     2,    41,    41,    41,    41,    41,    41,
      41,    41,   145,     0,     0,     0,     0,     0,     0,   145,
       0,     0,     0,     0,     0,     0,     0,     0,    41,    41,
       0,     0,    12,    24,    27,     0,   135,   132,    61,    16,
     128,    20,    14,    22,     0,     7,    96,    97,    95,     0,
       0,    41,    81,   100,    41,   129,   130,   146,     3,    41,
      41,    54,   138,     4,    42,    43,    44,    45,    46,    47,
      48,    49,    41,   103,   104,   106,   107,   108,   110,    41,
     112,   121,   113,   114,   115,   116,   117,   119,   120,    55,
      57,     0,    12,    25,    26,     0,   145,   134,   145,    64,
      64,   145,     0,     0,     0,     0,     0,     0,     0,   145,
     128,   145,   145,   145,   145,   145,   145,    82,     0,     0,
       0,     0,    52,    53,    56,    50,    51,     5,   145,    12,
      13,    34,   133,   145,    63,    62,     0,    38,     0,    17,
      19,    21,    15,    23,     0,     9,     0,     0,     0,     0,
       0,     0,     0,   145,     0,   100,     0,   145,    34,   145,
      36,     0,     0,     0,   145,   145,   145,     0,     0,     0,
       0,     0,     0,     0,    83,     0,   101,    99,     9,   145,
       0,   145,    35,    64,    64,    60,     0,     9,     0,     9,
     145,   145,   145,   145,   145,   145,     0,     0,    84,   128,
      58,   145,     0,     0,   138,    66,    65,   131,    10,     8,
      11,    41,    41,    41,    41,     0,     0,   145,   145,     0,
       0,    32,    36,   145,   145,   145,   145,     0,   145,   145,
     145,     0,    81,     6,    30,   145,    37,     0,     0,     0,
       0,    93,    94,     0,    87,    90,    87,   128,   145,   145,
     145,    39,   145,   145,   145,   145,   145,     0,   145,    89,
     145,   145,     0,     0,     0,    39,   145,   145,    71,    71,
      71,    71,    41,   145,     0,    90,     0,     0,     0,     0,
     145,     0,    39,     0,   145,   145,   145,   145,    92,    41,
      86,    91,    85,    79,    78,   145,     0,    33,    40,     0,
      76,    76,    76,    76,    88,    41,    31,   128,     0,     0,
       0,     0,    69,    70,    67,    68,   145,     0,     0,     0,
       0,   145,     0,   145,   145,   145,   145,    41,    80,    41,
      41,    41,    41,   145,   145,   145,   145,   145,     0,     0,
       0,     0,     0,    77,    71,    71,    71,    71,    74,    75,
      72,    73
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -343,    14,    28,  -343,  -343,  -153,  -110,   -10,  -343,   332,
    -343,  -343,  -343,   185,   122,  -100,  -342,     0,  -343,     7,
    -343,  -164,  -343,  -303,  -179,  -343,  -343,   132,  -343,  -343,
     123,   162,    93,  -320,  -343,  -343,  -343,  -343,   235,     3,
      88,   114,    21,   560,    83,   390,   170,   404,  -343,  -343,
    -343,    19,   -15,   -25
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    26,   244,   237,   189,   245,   113,    28,    29,    30,
      31,   330,   315,   239,   262,   240,   346,   246,   197,    33,
     181,   214,    34,   364,   392,    35,    36,   198,   277,    37,
     338,   308,   339,   309,   323,    38,    39,    40,   201,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,   178,
     117,   142,    52,    79
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,   173,   321,   360,    63,   340,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,   215,    61,   180,    51,
     378,    60,   -59,    57,   108,   109,    56,    74,    27,   118,
       1,    70,    64,   322,     4,   340,   111,    65,   129,   130,
     131,   132,   114,    78,   134,    75,   365,   366,   367,   -59,
       1,    70,    67,   137,     4,   139,   140,   175,   122,   177,
     116,   194,   121,   -59,    66,   210,    68,   152,    69,   176,
      22,    23,    54,    92,   159,    55,    24,    93,    94,    32,
      93,    94,   141,    32,   144,   145,   146,   147,   148,   149,
     150,   151,   175,   138,    80,    53,    24,   143,    51,   285,
     286,   174,    51,   182,   208,   281,    54,    27,   169,   170,
      55,    27,    55,   186,   288,    78,   290,   199,   128,    93,
      94,   428,   429,   430,   431,    93,    94,   111,    93,    94,
      77,   196,   192,   195,   202,   135,   191,    93,    94,   203,
     204,   264,   106,   107,   399,     1,    70,   -18,   184,     4,
     193,   211,   205,   212,     1,    58,   216,    81,     4,   206,
      95,    96,    97,   112,   225,   226,   227,   228,   229,   230,
     231,   232,    98,   219,   220,   221,   222,   223,    93,    94,
      78,   153,   154,   238,   302,    22,    23,   115,   241,   167,
     168,    24,    72,    73,    22,    23,   182,     1,    58,   124,
      24,     4,   393,   394,   395,   125,    25,    54,   254,   155,
     156,   157,   258,   126,   260,    25,   127,   133,   171,   267,
     268,   269,   172,   182,   183,   185,   182,   100,   101,   102,
     103,   104,   105,   187,   282,   188,   284,    22,    23,   200,
     209,   213,   207,    24,    51,   291,   292,   293,   294,   295,
     296,   217,   218,   233,   224,   234,   299,   235,   280,   236,
       1,    70,   175,    55,     4,   242,   253,   257,   243,   182,
     247,   248,   311,   312,   249,   278,   250,    51,   317,   318,
     319,   320,   251,   324,   325,   326,    51,   252,    51,   255,
     331,   303,   304,   305,   306,   261,   265,   199,   270,   271,
      22,    23,   342,   343,   344,   345,    24,   348,   349,   350,
     351,   352,   266,   354,   272,   355,   356,   273,   274,   275,
     276,   361,   362,   283,   287,   289,   297,   298,   369,   300,
     307,   347,   328,   301,   314,   376,   313,   332,   333,   380,
     381,   382,   383,    99,   334,   347,    59,   337,   335,   336,
     385,   353,   368,   357,    71,    71,    71,    71,   358,   363,
     359,   373,   347,   100,   101,   102,   103,   104,   105,   384,
     370,   402,   372,     1,    58,     3,   407,     4,   409,   410,
     411,   412,   389,   374,    70,   396,   388,   120,   418,   419,
     420,   421,   422,     8,     9,    10,    11,    12,    13,   375,
     390,   379,   377,   386,    62,   119,   391,   413,   397,   414,
     415,   416,   417,    22,    23,    76,   398,   401,   403,    24,
     404,   405,   406,   259,   316,    71,    71,    71,    71,    71,
      71,   408,    71,    71,    71,    71,    71,    71,    71,    71,
     423,   424,  -138,   425,   329,    62,   426,   427,   371,   341,
     179,     8,     9,    10,    11,    12,    13,   136,   310,   123,
       0,   190,    71,   100,   101,   102,   103,   104,   105,   400,
     256,     0,     0,     0,     0,   100,   101,   102,   103,   104,
     105,     0,     0,    62,    62,    62,    62,    62,   158,     0,
     161,   161,   161,   161,   161,   161,   161,   161,     1,     2,
       3,     0,     4,     0,   -41,     5,     6,     7,     8,     9,
      10,    11,    12,    13,     0,    14,    15,     0,     0,    16,
      62,     0,     0,    17,    18,    19,     0,     0,    20,   110,
      21,     0,     8,     9,    10,    11,    12,    13,    22,    23,
       0,     0,     0,     0,    24,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,     1,     2,     3,     0,     4,     0,    25,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     0,
      14,    15,     0,   263,    16,     0,     0,     0,    17,    18,
      19,     0,     0,    20,     0,    21,    71,   279,     0,     0,
       0,     0,     0,    22,    23,     0,     0,     0,     0,    24,
       8,     9,    10,    11,    12,    13,     0,     1,     2,     3,
       0,     4,     0,     0,    25,     6,     7,     8,     9,    10,
      11,    12,    13,     0,    14,    15,     0,     0,    16,     0,
       0,     0,    17,    18,    19,     0,     0,    20,     0,    21,
       0,     0,     0,   327,   161,    62,     0,    22,    23,     0,
       0,     0,     0,    24,   100,   101,   102,   103,   104,   105,
     160,   162,   163,   164,   165,   166,     0,     0,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   161,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   387
};

static const yytype_int16 yycheck[] =
{
       0,   111,     3,   345,    49,   325,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,   180,    14,   118,     0,
     362,    14,     9,     5,    49,    50,     4,    24,     0,    54,
       3,     4,    49,    34,     7,   355,    51,    53,    63,    64,
      65,    66,    52,     9,    69,    24,   349,   350,   351,    36,
       3,     4,    36,    78,     7,    80,    81,    37,    55,    36,
      53,    34,    55,    50,    49,   175,    49,    92,    36,    49,
      43,    44,    49,    36,    99,    55,    49,    43,    44,    79,
      43,    44,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    37,    79,    36,    38,    49,    83,    79,   263,
     264,   111,    83,   118,    49,   258,    49,    79,   108,   109,
      55,    83,    55,    37,   267,     9,   269,   132,    36,    43,
      44,   424,   425,   426,   427,    43,    44,   142,    43,    44,
       0,   131,   129,   130,   134,    50,   129,    43,    44,   139,
     140,   241,    62,    63,    50,     3,     4,    36,    37,     7,
     129,   176,   152,   178,     3,     4,   181,    36,     7,   159,
      45,    46,    47,     4,   189,   190,   191,   192,   193,   194,
     195,   196,    48,   183,   184,   185,   186,   187,    43,    44,
       9,    93,    94,   208,   284,    43,    44,     4,   213,   106,
     107,    49,    22,    23,    43,    44,   211,     3,     4,    55,
      49,     7,   381,   382,   383,    53,    64,    49,   233,    95,
      96,    97,   237,    36,   239,    64,    36,    35,     5,   244,
     245,   246,     4,   238,    37,    37,   241,    56,    57,    58,
      59,    60,    61,    37,   259,    19,   261,    43,    44,    37,
       4,    37,    53,    49,   225,   270,   271,   272,   273,   274,
     275,     4,     4,    36,     5,     4,   281,     4,   255,    50,
       3,     4,    37,    55,     7,    50,    54,    36,    49,   284,
      50,    50,   297,   298,    50,   254,    50,   258,   303,   304,
     305,   306,    50,   308,   309,   310,   267,    50,   269,    55,
     315,   291,   292,   293,   294,    37,    36,   312,    53,    53,
      43,    44,   327,   328,   329,   330,    49,   332,   333,   334,
     335,   336,    50,   338,    53,   340,   341,    53,    53,    53,
      27,   346,   347,    50,    36,    54,    49,    36,   353,    50,
      25,   331,   311,    53,    53,   360,    54,    54,    54,   364,
     365,   366,   367,    36,    54,   345,    14,    26,    54,    40,
     375,    40,   352,    50,    22,    23,    24,    25,    50,    22,
      50,    36,   362,    56,    57,    58,    59,    60,    61,   369,
      54,   396,    54,     3,     4,     5,   401,     7,   403,   404,
     405,   406,   379,    36,     4,   385,   379,    55,   413,   414,
     415,   416,   417,    13,    14,    15,    16,    17,    18,    53,
     379,    49,    54,    54,    14,    35,    23,   407,    50,   409,
     410,   411,   412,    43,    44,    25,    50,    53,    53,    49,
      53,    53,    53,   238,   302,    93,    94,    95,    96,    97,
      98,    54,   100,   101,   102,   103,   104,   105,   106,   107,
      54,    54,     4,    54,   312,    55,    54,    54,   355,   326,
     118,    13,    14,    15,    16,    17,    18,    50,   296,    55,
      -1,   129,   130,    56,    57,    58,    59,    60,    61,    50,
     235,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    60,
      61,    -1,    -1,    93,    94,    95,    96,    97,    98,    -1,
     100,   101,   102,   103,   104,   105,   106,   107,     3,     4,
       5,    -1,     7,    -1,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    -1,    20,    21,    -1,    -1,    24,
     130,    -1,    -1,    28,    29,    30,    -1,    -1,    33,    10,
      35,    -1,    13,    14,    15,    16,    17,    18,    43,    44,
      -1,    -1,    -1,    -1,    49,    56,    57,    58,    59,    60,
      61,    62,    63,     3,     4,     5,    -1,     7,    -1,    64,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      20,    21,    -1,   241,    24,    -1,    -1,    -1,    28,    29,
      30,    -1,    -1,    33,    -1,    35,   254,   255,    -1,    -1,
      -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    -1,    49,
      13,    14,    15,    16,    17,    18,    -1,     3,     4,     5,
      -1,     7,    -1,    -1,    64,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    20,    21,    -1,    -1,    24,    -1,
      -1,    -1,    28,    29,    30,    -1,    -1,    33,    -1,    35,
      -1,    -1,    -1,   311,   254,   255,    -1,    43,    44,    -1,
      -1,    -1,    -1,    49,    56,    57,    58,    59,    60,    61,
     100,   101,   102,   103,   104,   105,    -1,    -1,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   311,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   379
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     7,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    20,    21,    24,    28,    29,    30,
      33,    35,    43,    44,    49,    64,    66,    67,    72,    73,
      74,    75,    82,    84,    87,    90,    91,    94,   100,   101,
     102,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   116,   117,    38,    49,    55,     4,     5,     4,    74,
      84,   104,   110,    49,    49,    53,    49,    36,    49,    36,
       4,    74,   111,   111,   104,   107,   110,     0,     9,   118,
      36,    36,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,    36,    43,    44,    45,    46,    47,    48,    36,
      56,    57,    58,    59,    60,    61,    62,    63,   118,   118,
      10,   117,     4,    71,    72,     4,    84,   115,   118,    35,
      74,    84,   104,   112,    55,    53,    36,    36,    36,   118,
     118,   118,   118,    35,   118,    50,    50,   118,    66,   118,
     118,    82,   116,    66,    82,    82,    82,    82,    82,    82,
      82,    82,   118,   105,   105,   106,   106,   106,   110,   118,
     108,   110,   108,   108,   108,   108,   108,   109,   109,    82,
      82,     5,     4,    71,    72,    37,    49,    36,   114,    74,
      80,    85,   117,    37,    37,    37,    37,    37,    19,    69,
      74,    84,   104,   107,    34,   104,    82,    83,    92,   117,
      37,   103,    82,    82,    82,    82,    82,    53,    49,     4,
      71,   118,   118,    37,    86,    86,   118,     4,     4,    72,
      72,    72,    72,    72,     5,   118,   118,   118,   118,   118,
     118,   118,   118,    36,     4,     4,    50,    68,   118,    78,
      80,   118,    50,    49,    67,    70,    82,    50,    50,    50,
      50,    50,    50,    54,   118,    55,   103,    36,   118,    78,
     118,    37,    79,    74,    80,    36,    50,   118,   118,   118,
      53,    53,    53,    53,    53,    53,    27,    93,   107,    74,
     104,    70,   118,    50,   118,    86,    86,    36,    70,    54,
      70,   118,   118,   118,   118,   118,   118,    49,    36,   118,
      50,    53,    80,    82,    82,    82,    82,    25,    96,    98,
      96,   118,   118,    54,    53,    77,    79,   118,   118,   118,
     118,     3,    34,    99,   118,   118,   118,    74,   107,    92,
      76,   118,    54,    54,    54,    54,    40,    26,    95,    97,
      98,    95,   118,   118,   118,   118,    81,    82,   118,   118,
     118,   118,   118,    40,   118,   118,   118,    50,    50,    50,
      81,   118,   118,    22,    88,    88,    88,    88,    82,   118,
      54,    97,    54,    36,    36,    53,   118,    54,    81,    49,
     118,   118,   118,   118,    82,   118,    54,    74,    84,   104,
     107,    23,    89,    89,    89,    89,    82,    50,    50,    50,
      50,    53,   118,    53,    53,    53,    53,   118,    54,   118,
     118,   118,   118,    82,    82,    82,    82,    82,   118,   118,
     118,   118,   118,    54,    54,    54,    54,    54,    88,    88,
      88,    88
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
      84,    85,    85,    85,    86,    86,    86,    87,    87,    87,
      87,    88,    88,    88,    88,    88,    89,    89,    90,    90,
      91,    92,    92,    93,    93,    94,    94,    95,    95,    96,
      97,    97,    98,    99,    99,   100,   100,   100,   101,   102,
     103,   103,   104,   104,   104,   105,   105,   105,   105,   106,
     106,   107,   107,   107,   107,   107,   107,   107,   108,   108,
     108,   109,   109,   110,   110,   110,   111,   111,   111,   111,
     111,   112,   114,   113,   115,   115,   116,   116,   117,   117,
     117,   117,   117,   117,   117,   118,   118
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
       7,     0,     2,     2,     0,     4,     4,    15,    15,    15,
      15,     0,    10,    10,    10,    10,     0,     6,    13,    13,
      17,     0,     1,     0,     1,    13,    13,     0,     4,     3,
       0,     3,     5,     1,     1,     3,     3,     3,     2,     6,
       0,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       3,     1,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     1,     2,     1,     2,     2,     1,     1,     1,     3,
       3,     8,     0,     5,     2,     1,     1,     1,     0,     1,
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
  case 5: /* $@1: %empty  */
#line 188 "project.y"
                                                      { increaseScope(); }
#line 1640 "project.tab.c"
    break;

  case 6: /* class_declaration: access_modifier CLASS CLASS_ID LCB $@1 none_or_newlines class_body none_or_newlines RCB  */
#line 188 "project.y"
                                                                                                                            { decreaseScope(); }
#line 1646 "project.tab.c"
    break;

  case 7: /* $@2: %empty  */
#line 189 "project.y"
                         { increaseScope(); }
#line 1652 "project.tab.c"
    break;

  case 8: /* class_declaration: CLASS CLASS_ID LCB $@2 none_or_newlines class_body none_or_newlines RCB  */
#line 189 "project.y"
                                                                                               { decreaseScope(); }
#line 1658 "project.tab.c"
    break;

  case 14: /* assignment_list: ID ASSIGN exp  */
#line 202 "project.y"
                               { char* type = getType((yyvsp[-2].sval)); if (type == NULL || strcmp(type, "int") != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-2].sval)); }
#line 1664 "project.tab.c"
    break;

  case 15: /* assignment_list: ID ASSIGN exp COMMA assignment_list  */
#line 203 "project.y"
                                          { char* type = getType((yyvsp[-4].sval)); if (type == NULL || strcmp(type, "int") != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-4].sval)); }
#line 1670 "project.tab.c"
    break;

  case 16: /* assignment_list: ID ASSIGN DQ_STRING_DQ  */
#line 204 "project.y"
                             { char* type = getType((yyvsp[-2].sval)); if (type == NULL || strcmp(type, "string") != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-2].sval)); }
#line 1676 "project.tab.c"
    break;

  case 17: /* assignment_list: ID ASSIGN DQ_STRING_DQ COMMA assignment_list  */
#line 205 "project.y"
                                                   { char* type = getType((yyvsp[-4].sval)); if (type == NULL || strcmp(type, "string") != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-4].sval)); }
#line 1682 "project.tab.c"
    break;

  case 18: /* assignment_list: ID ASSIGN variable_reference  */
#line 206 "project.y"
                                   { char* type = getType((yyvsp[-2].sval)); if (type == NULL || strcmp(type, getType((yyvsp[0].sval))) != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-2].sval)); }
#line 1688 "project.tab.c"
    break;

  case 19: /* assignment_list: ID ASSIGN variable_reference COMMA assignment_list  */
#line 207 "project.y"
                                                         { char* type = getType((yyvsp[-4].sval)); if (type == NULL || strcmp(type, getType((yyvsp[-2].sval))) != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-4].sval)); }
#line 1694 "project.tab.c"
    break;

  case 20: /* assignment_list: ID ASSIGN method_call  */
#line 208 "project.y"
                            { char* type = getType((yyvsp[-2].sval)); if (type == NULL || strcmp(type, "int") != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-2].sval)); }
#line 1700 "project.tab.c"
    break;

  case 21: /* assignment_list: ID ASSIGN method_call COMMA assignment_list  */
#line 209 "project.y"
                                                  { char* type = getType((yyvsp[-4].sval)); if (type == NULL || strcmp(type, "int") != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-4].sval)); }
#line 1706 "project.tab.c"
    break;

  case 22: /* assignment_list: ID ASSIGN object_creation  */
#line 210 "project.y"
                                { char* type = getType((yyvsp[-2].sval)); if (type == NULL || strcmp(type, "object") != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-2].sval)); }
#line 1712 "project.tab.c"
    break;

  case 23: /* assignment_list: ID ASSIGN object_creation COMMA assignment_list  */
#line 211 "project.y"
                                                      { char* type = getType((yyvsp[-4].sval)); if (type == NULL || strcmp(type, "object") != 0) { yyerror("Type mismatch"); } setInitialized((yyvsp[-4].sval)); }
#line 1718 "project.tab.c"
    break;

  case 24: /* variable_declaration: data_type identifier_list  */
#line 215 "project.y"
                                                { addSymbol((yyvsp[0].sval), (yyvsp[-1].sval), false, false); }
#line 1724 "project.tab.c"
    break;

  case 25: /* variable_declaration: access_modifier data_type identifier_list  */
#line 216 "project.y"
                                                { addSymbol((yyvsp[0].sval), (yyvsp[-1].sval), false, false); }
#line 1730 "project.tab.c"
    break;

  case 26: /* variable_declaration: access_modifier data_type assignment_list  */
#line 217 "project.y"
                                                { addSymbol((yyvsp[0].sval), (yyvsp[-1].sval), false, true); }
#line 1736 "project.tab.c"
    break;

  case 27: /* variable_declaration: data_type assignment_list  */
#line 218 "project.y"
                                { addSymbol((yyvsp[0].sval), (yyvsp[-1].sval), false, true); }
#line 1742 "project.tab.c"
    break;

  case 28: /* variable_declaration: assignment_list  */
#line 219 "project.y"
                      { addSymbol((yyvsp[0].sval), NULL, false, true); }
#line 1748 "project.tab.c"
    break;

  case 29: /* variable_reference: ID  */
#line 223 "project.y"
                       { if (!symbolExists((yyvsp[0].sval), false)) { yyerror("Variable not declared"); } else if (!isInitialized((yyvsp[0].sval))) { yyerror("Variable not initialized"); } }
#line 1754 "project.tab.c"
    break;

  case 30: /* $@3: %empty  */
#line 228 "project.y"
                                                                                                                         { increaseScope(); }
#line 1760 "project.tab.c"
    break;

  case 31: /* method_declaration: access_modifier data_type ID LP none_or_newlines none_or_multiple_parameters none_or_newlines RP LCB $@3 none_or_newlines method_body none_or_newlines RCB  */
#line 228 "project.y"
                                                                                                                                                                                                { addSymbol((yyvsp[-11].sval), (yyvsp[-12].sval), true, true); decreaseScope(); }
#line 1766 "project.tab.c"
    break;

  case 32: /* $@4: %empty  */
#line 229 "project.y"
                                                                                           { increaseScope(); }
#line 1772 "project.tab.c"
    break;

  case 33: /* method_declaration: data_type ID LP none_or_newlines none_or_multiple_parameters none_or_newlines RP LCB $@4 none_or_newlines method_body none_or_newlines RCB  */
#line 229 "project.y"
                                                                                                                                                                  { addSymbol((yyvsp[-11].sval), (yyvsp[-12].sval), true, true); decreaseScope(); }
#line 1778 "project.tab.c"
    break;

  case 60: /* method_call: ID LP none_or_newlines none_or_multiple_arguments none_or_newlines RP SEMICOLON  */
#line 271 "project.y"
                                                                                             { if (!symbolExists((yyvsp[-6].sval), true)) { yyerror("Method not declared"); } }
#line 1784 "project.tab.c"
    break;

  case 101: /* single_or_multiple_variables: COMMA ID single_or_multiple_variables  */
#line 350 "project.y"
                                            { if (!symbolExists((yyvsp[-1].sval), false)) { yyerror("Variable not declared"); } else if (!isInitialized((yyvsp[-1].sval))) { yyerror("Variable not initialized"); } }
#line 1790 "project.tab.c"
    break;

  case 132: /* $@5: %empty  */
#line 401 "project.y"
                                         { if (!symbolExists((yyvsp[-2].sval), false)) { yyerror("Class not declared"); } if (!symbolExists((yyvsp[0].sval), false)) { yyerror("Member not declared"); } }
#line 1796 "project.tab.c"
    break;

  case 134: /* member_access_body: ID SEMICOLON  */
#line 404 "project.y"
                                 { if (!symbolExists((yyvsp[-1].sval), false)) { yyerror("Variable not declared"); } }
#line 1802 "project.tab.c"
    break;

  case 135: /* member_access_body: method_call  */
#line 405 "project.y"
                  { if (!symbolExists((yyvsp[0].sval), true)) { yyerror("Method not declared"); } }
#line 1808 "project.tab.c"
    break;

  case 138: /* data_type: %empty  */
#line 412 "project.y"
                         { (yyval.sval) = ""; }
#line 1814 "project.tab.c"
    break;

  case 139: /* data_type: INTEGER  */
#line 413 "project.y"
              { (yyval.sval) = "int"; }
#line 1820 "project.tab.c"
    break;

  case 140: /* data_type: CHAR  */
#line 414 "project.y"
           { (yyval.sval) = "char"; }
#line 1826 "project.tab.c"
    break;

  case 141: /* data_type: DOUBLE  */
#line 415 "project.y"
             { (yyval.sval) = "double"; }
#line 1832 "project.tab.c"
    break;

  case 142: /* data_type: BOOLEAN  */
#line 416 "project.y"
              { (yyval.sval) = "boolean"; }
#line 1838 "project.tab.c"
    break;

  case 143: /* data_type: STRING  */
#line 417 "project.y"
             { (yyval.sval) = "string"; }
#line 1844 "project.tab.c"
    break;

  case 144: /* data_type: VOID  */
#line 418 "project.y"
           { (yyval.sval) = "void"; }
#line 1850 "project.tab.c"
    break;


#line 1854 "project.tab.c"

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

#line 425 "project.y"


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
