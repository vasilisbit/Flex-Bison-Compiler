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
void yyerror(const char *s);
extern FILE *yyin;
extern FILE *yyout;
extern int yylex();
extern int yylineno;
extern char *yytext;

#line 84 "project.tab.c"

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
  YYSYMBOL_class_body = 68,                /* class_body  */
  YYSYMBOL_identifier_list = 69,           /* identifier_list  */
  YYSYMBOL_assignment_list = 70,           /* assignment_list  */
  YYSYMBOL_variable_declaration = 71,      /* variable_declaration  */
  YYSYMBOL_variable_reference = 72,        /* variable_reference  */
  YYSYMBOL_method_declaration = 73,        /* method_declaration  */
  YYSYMBOL_none_or_multiple_parameters = 74, /* none_or_multiple_parameters  */
  YYSYMBOL_parameters = 75,                /* parameters  */
  YYSYMBOL_parameter = 76,                 /* parameter  */
  YYSYMBOL_method_body = 77,               /* method_body  */
  YYSYMBOL_statement = 78,                 /* statement  */
  YYSYMBOL_assignment_statement = 79,      /* assignment_statement  */
  YYSYMBOL_method_call = 80,               /* method_call  */
  YYSYMBOL_none_or_multiple_arguments = 81, /* none_or_multiple_arguments  */
  YYSYMBOL_arguments = 82,                 /* arguments  */
  YYSYMBOL_if_statement = 83,              /* if_statement  */
  YYSYMBOL_none_or_multiple_elif = 84,     /* none_or_multiple_elif  */
  YYSYMBOL_none_or_one_else = 85,          /* none_or_one_else  */
  YYSYMBOL_do_while_statement = 86,        /* do_while_statement  */
  YYSYMBOL_for_statement = 87,             /* for_statement  */
  YYSYMBOL_first_and_third_loop_statement = 88, /* first_and_third_loop_statement  */
  YYSYMBOL_second_loop_statement = 89,     /* second_loop_statement  */
  YYSYMBOL_switch_statement = 90,          /* switch_statement  */
  YYSYMBOL_default_case = 91,              /* default_case  */
  YYSYMBOL_one_or_more_cases = 92,         /* one_or_more_cases  */
  YYSYMBOL_multiple_cases = 93,            /* multiple_cases  */
  YYSYMBOL_cases = 94,                     /* cases  */
  YYSYMBOL_case_expression = 95,           /* case_expression  */
  YYSYMBOL_return_statement = 96,          /* return_statement  */
  YYSYMBOL_break_statement = 97,           /* break_statement  */
  YYSYMBOL_print_statement = 98,           /* print_statement  */
  YYSYMBOL_single_or_multiple_variables = 99, /* single_or_multiple_variables  */
  YYSYMBOL_exp = 100,                      /* exp  */
  YYSYMBOL_factor = 101,                   /* factor  */
  YYSYMBOL_term = 102,                     /* term  */
  YYSYMBOL_relational_exp = 103,           /* relational_exp  */
  YYSYMBOL_relational_factor = 104,        /* relational_factor  */
  YYSYMBOL_logical_term = 105,             /* logical_term  */
  YYSYMBOL_unary = 106,                    /* unary  */
  YYSYMBOL_primary = 107,                  /* primary  */
  YYSYMBOL_object_creation = 108,          /* object_creation  */
  YYSYMBOL_access_modifier = 109,          /* access_modifier  */
  YYSYMBOL_data_type = 110,                /* data_type  */
  YYSYMBOL_none_or_newlines = 111          /* none_or_newlines  */
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
#define YYFINAL  75
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   676

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  137
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  418

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
       0,    59,    59,    60,    61,    64,    65,    68,    69,    70,
      73,    74,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    89,    90,    91,    92,    93,    96,   100,   101,
     104,   105,   108,   109,   112,   115,   116,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   137,   138,   141,   144,   145,   146,   149,
     150,   151,   154,   155,   156,   157,   160,   161,   162,   163,
     164,   167,   168,   171,   172,   175,   178,   179,   182,   183,
     186,   187,   190,   191,   194,   197,   198,   201,   204,   205,
     208,   209,   210,   213,   216,   219,   220,   223,   224,   225,
     228,   229,   230,   231,   234,   235,   238,   239,   240,   241,
     242,   243,   244,   247,   248,   249,   252,   253,   256,   257,
     258,   261,   262,   263,   264,   265,   268,   299,   300,   303,
     304,   305,   306,   307,   308,   309,   325,   326
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
  "class_declaration", "class_body", "identifier_list", "assignment_list",
  "variable_declaration", "variable_reference", "method_declaration",
  "none_or_multiple_parameters", "parameters", "parameter", "method_body",
  "statement", "assignment_statement", "method_call",
  "none_or_multiple_arguments", "arguments", "if_statement",
  "none_or_multiple_elif", "none_or_one_else", "do_while_statement",
  "for_statement", "first_and_third_loop_statement",
  "second_loop_statement", "switch_statement", "default_case",
  "one_or_more_cases", "multiple_cases", "cases", "case_expression",
  "return_statement", "break_statement", "print_statement",
  "single_or_multiple_variables", "exp", "factor", "term",
  "relational_exp", "relational_factor", "logical_term", "unary",
  "primary", "object_creation", "access_modifier", "data_type",
  "none_or_newlines", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-297)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-130)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     451,  -297,   -29,     1,  -297,    62,  -297,  -297,  -297,  -297,
    -297,  -297,  -297,  -297,   272,   -14,    -8,    37,    29,    35,
      44,    68,    43,    43,   145,   303,   113,   118,  -297,    99,
     102,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,    93,    76,    97,   162,    36,  -297,   329,  -297,   118,
     413,   159,   118,   161,   115,   142,   148,   167,   171,   133,
    -297,   118,   118,   118,   118,  -297,   192,   118,  -297,  -297,
    -297,  -297,   143,   432,  -297,  -297,   118,   451,   118,   118,
     570,   451,   570,   570,   570,   570,   570,   570,   570,   570,
     118,   303,   303,   303,   303,   303,   303,   118,   145,   145,
     145,   145,   145,   145,   145,   145,   570,   231,   241,    42,
    -297,  -297,   366,   209,    39,   210,    18,   212,   232,   118,
    -297,  -297,  -297,   168,    25,   570,   403,   213,   570,  -297,
    -297,  -297,  -297,   570,   570,  -297,   545,  -297,  -297,  -297,
    -297,  -297,  -297,  -297,  -297,  -297,   570,    76,    76,    97,
      97,    97,  -297,   570,    36,  -297,    36,    36,    36,    36,
      36,  -297,  -297,  -297,   199,    71,  -297,  -297,   249,   118,
     219,   219,   118,   254,   256,   256,   256,   256,   256,   258,
     506,   118,   118,    14,   123,   118,    14,   118,  -297,   228,
     262,   267,   235,  -297,  -297,  -297,  -297,  -297,   118,   118,
     250,  -297,   403,   118,  -297,  -297,   236,  -297,   233,  -297,
    -297,  -297,  -297,  -297,   240,   118,   118,   118,   243,   251,
     261,   263,   264,   269,   266,   118,   253,   213,   276,   506,
     403,   118,   285,   366,   287,   275,   506,   273,   506,   284,
     289,   290,   292,   295,   296,   299,   145,   303,  -297,  -297,
     118,   118,   288,   118,  -297,   219,   219,  -297,   304,  -297,
    -297,  -297,   118,   118,   118,   118,   118,   118,   301,   315,
     508,    13,   107,   300,   305,   306,   545,  -297,  -297,  -297,
     570,   570,   570,   570,   331,   331,   118,   118,  -297,   308,
     118,   285,   118,   118,   118,   118,    22,   118,   118,   118,
     145,   403,   118,   570,  -297,   314,   340,   370,   371,  -297,
    -297,   360,   343,   331,   343,   118,   123,   118,   570,   118,
     118,   118,   118,   118,   118,   118,   392,   118,  -297,   118,
     118,   385,   386,   393,   118,   398,   570,   431,   431,   431,
     431,   570,   118,   405,   331,   419,   421,   438,   423,   424,
    -297,  -297,   428,   118,   118,   118,   118,  -297,   570,  -297,
    -297,  -297,  -297,  -297,   118,  -297,   168,   460,   460,   460,
     460,  -297,   570,   435,   437,   158,   446,   444,  -297,  -297,
    -297,  -297,   118,   445,   448,   455,   459,   118,   471,   118,
     118,   118,   118,   570,  -297,   570,   570,   570,   570,   118,
     118,   118,   118,   118,   474,   475,   477,   478,   479,  -297,
     431,   431,   431,   431,  -297,  -297,  -297,  -297
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,   121,    27,     0,   122,     0,   127,   128,   130,   131,
     132,   133,   134,   135,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   136,    26,     0,
     123,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,     0,    97,   100,     0,   106,   113,   104,   118,   136,
     129,     0,   136,     0,     0,     0,    27,   123,     0,     0,
     104,   136,   136,   136,   136,    93,     0,   136,    27,   123,
     119,   120,     0,     0,   117,     1,   136,     2,   136,   136,
      37,     2,    37,    37,    37,    37,    37,    37,    37,    37,
     136,     0,     0,     0,     0,     0,     0,   136,     0,     0,
       0,     0,     0,     0,     0,     0,    37,     0,     0,    10,
      22,    25,    56,    14,   123,    18,    12,    20,     0,   136,
      91,    92,    90,     0,     0,    37,    76,    95,    37,   124,
     125,   137,     3,    37,    37,    50,   129,     4,    38,    39,
      40,    41,    42,    43,    44,    45,    37,    98,    99,   101,
     102,   103,   105,    37,   107,   116,   108,   109,   110,   111,
     112,   114,   115,    51,     0,    10,    23,    24,     0,   136,
      59,    59,   136,     0,     0,     0,     0,     0,     0,     0,
       7,   123,   136,   136,   136,   136,   136,   136,    77,     0,
       0,     0,     0,    48,    49,    52,    46,    47,   136,   136,
      10,    11,    30,   136,    58,    57,     0,    34,     0,    15,
      17,    19,    13,    21,     0,   136,   136,   136,     0,     0,
       0,     0,     0,     0,     0,   136,     0,    95,     0,     7,
      30,   136,    32,     0,     0,     0,     7,     0,     7,     0,
       0,     0,     0,     0,     0,     0,    78,     0,    96,    94,
     136,   136,     0,   136,    31,    59,    59,    55,     0,     8,
       6,     9,   136,   136,   136,   136,   136,   136,     0,     0,
      79,   123,    53,     0,     0,     0,   129,    61,    60,   126,
      37,    37,    37,    37,     0,     0,   136,   136,     5,     0,
     136,    32,   136,   136,   136,   136,     0,   136,   136,   136,
       0,    76,   136,    35,    33,     0,     0,     0,     0,    88,
      89,     0,    82,    85,    82,   123,   136,   136,    35,   136,
     136,   136,   136,   136,   136,   136,     0,   136,    84,   136,
     136,     0,     0,     0,   136,     0,    35,    66,    66,    66,
      66,    37,   136,     0,    85,     0,     0,     0,     0,     0,
      29,    36,     0,   136,   136,   136,   136,    87,    37,    81,
      86,    80,    74,    73,   136,    28,     0,    71,    71,    71,
      71,    83,    37,   123,     0,     0,     0,     0,    64,    65,
      62,    63,   136,     0,     0,     0,     0,   136,     0,   136,
     136,   136,   136,    37,    75,    37,    37,    37,    37,   136,
     136,   136,   136,   136,     0,     0,     0,     0,     0,    72,
      66,    66,    66,    66,    69,    70,    67,    68
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -297,   -11,    30,  -124,  -104,   -35,  -297,   310,  -297,   307,
     208,  -109,  -284,     0,  -297,   -13,  -297,  -153,  -297,  -295,
    -139,  -297,  -297,   237,  -297,  -297,   200,   255,   198,  -296,
    -297,  -297,  -297,  -297,   317,     7,    63,   140,   -22,   522,
     110,   346,   221,   492,    19,   -17,   -25
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    26,   215,   216,   110,    28,    29,    30,    31,   231,
     254,   232,   319,   217,   188,    33,   172,   204,    34,   353,
     378,    35,    36,   189,   269,    37,   327,   297,   328,   298,
     311,    38,    39,    40,   192,    41,    42,    43,    44,    45,
      46,    47,    48,    49,   136,    51,    77
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,    58,    73,   171,   166,    54,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,   111,   329,   205,    50,
      52,    59,   -54,    76,   106,   309,    53,   112,     1,    68,
      27,    72,     4,   108,   334,    61,   123,   124,   125,   126,
     115,    62,   128,   354,   355,   356,     1,    68,   329,   -54,
       4,   131,   351,   133,   134,   177,   310,    91,    92,   185,
     116,    91,    92,   -54,   201,   146,   132,    55,    22,    23,
     137,    65,   153,   167,    24,   -16,   175,    32,    64,   168,
     135,    32,   138,   139,   140,   141,   142,   143,   144,   145,
      63,   169,    24,    66,   180,   173,    50,    53,   104,   105,
      50,   184,   277,   278,    67,   250,   163,    27,   168,   190,
     182,    27,   259,    75,   261,   414,   415,   416,   417,   108,
     199,    93,    94,    95,   256,   187,    53,    76,   193,    90,
     183,   186,    76,   194,   195,    78,    91,    92,    79,   209,
     210,   211,   212,   213,   202,    96,   196,   206,     1,    68,
      91,    92,     4,   197,   147,   148,   218,   219,   220,   221,
     222,   223,   224,   109,     1,    56,     3,   291,     4,   122,
     118,     1,    56,   229,   230,     4,    91,    92,   233,    98,
      99,   100,   101,   102,   103,   173,    91,    92,    22,    23,
     236,   237,   238,   129,    24,   119,   113,    52,    97,    50,
     246,    91,    92,   120,    22,    23,   252,   121,   385,    25,
      24,    22,    23,   173,   161,   162,   173,    24,    98,    99,
     100,   101,   102,   103,   270,   273,   274,   127,   276,   379,
     380,   381,    25,   149,   150,   151,   164,   280,   281,   282,
     283,   284,   285,    70,    71,   165,   174,   176,    50,   178,
     191,   179,   198,   200,   272,    50,   203,    50,   207,   173,
     208,   300,   301,   214,   225,   303,   226,   305,   306,   307,
     308,   227,   312,   313,   314,     1,    56,   318,   316,     4,
     292,   293,   294,   295,   190,   228,   234,   168,    53,   235,
     331,   332,   333,   239,   335,   336,   337,   338,   339,   340,
     341,   240,   343,   320,   344,   345,     1,    68,   247,   349,
       4,   241,   249,   242,   243,    22,    23,   358,   320,   244,
     245,    24,   253,   257,    57,   258,   268,   260,   367,   368,
     369,   370,    69,    69,    69,    69,   320,   262,   275,   372,
     279,   357,   263,   264,   376,   265,    22,    23,   266,   267,
     286,   287,    24,   374,   288,   289,   296,   388,   371,   290,
      60,   302,   393,   114,   395,   396,   397,   398,   321,   326,
      68,    74,   382,   375,   404,   405,   406,   407,   408,     8,
       9,    10,    11,    12,    13,  -116,  -116,  -116,  -116,  -116,
    -116,  -116,  -116,   399,   322,   400,   401,   402,   403,    60,
     325,    69,    69,    69,    69,    69,    69,  -129,    69,    69,
      69,    69,    69,    69,    69,    69,     8,     9,    10,    11,
      12,    13,   170,   107,   323,   324,     8,     9,    10,    11,
      12,    13,   342,   181,    69,   346,   347,    60,    60,    60,
      60,    60,   152,   348,   155,   155,   155,   155,   155,   155,
     155,   155,   350,   352,     1,     2,     3,   362,     4,   359,
     -37,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      60,    14,    15,   361,   363,    16,   364,   366,   365,    17,
      18,    19,   130,   377,    20,   383,    21,   384,    98,    99,
     100,   101,   102,   103,    22,    23,   386,   387,   389,   304,
      24,   390,    98,    99,   100,   101,   102,   103,   391,     1,
       2,     3,   392,     4,   330,    25,     5,     6,     7,     8,
       9,    10,    11,    12,    13,   394,    14,    15,   409,   410,
      16,   411,   412,   413,    17,    18,    19,   251,   317,    20,
     299,    21,   360,   255,   248,   117,     0,     0,     0,    22,
      23,     0,     0,     0,     0,    24,    69,   271,     8,     9,
      10,    11,    12,    13,    98,    99,   100,   101,   102,   103,
      25,     0,     0,     1,     2,     3,     0,     4,     0,     0,
       0,     6,     7,     8,     9,    10,    11,    12,    13,     0,
      14,    15,   155,    60,    16,     0,     0,     0,    17,    18,
      19,     0,     0,    20,     0,    21,     0,     0,     0,     0,
     315,     0,     0,    22,    23,     0,     0,     0,     0,    24,
     154,   156,   157,   158,   159,   160,     0,     0,     0,     0,
       0,     0,     0,     0,    25,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   155,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   373
};

static const yytype_int16 yycheck[] =
{
       0,    14,    24,   112,   108,     4,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    51,   313,   171,     0,
      49,    14,     9,     9,    49,     3,    55,    52,     3,     4,
       0,    24,     7,    50,   318,    49,    61,    62,    63,    64,
      53,    49,    67,   338,   339,   340,     3,     4,   344,    36,
       7,    76,   336,    78,    79,    37,    34,    43,    44,    34,
      53,    43,    44,    50,   168,    90,    77,     5,    43,    44,
      81,    36,    97,   108,    49,    36,    37,    77,    49,    37,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      53,    49,    49,    49,   119,   112,    77,    55,    62,    63,
      81,   123,   255,   256,    36,   229,   106,    77,    37,   126,
     123,    81,   236,     0,   238,   410,   411,   412,   413,   136,
      49,    45,    46,    47,   233,   125,    55,     9,   128,    36,
     123,   124,     9,   133,   134,    36,    43,    44,    36,   174,
     175,   176,   177,   178,   169,    48,   146,   172,     3,     4,
      43,    44,     7,   153,    91,    92,   181,   182,   183,   184,
     185,   186,   187,     4,     3,     4,     5,   276,     7,    36,
      55,     3,     4,   198,   199,     7,    43,    44,   203,    56,
      57,    58,    59,    60,    61,   202,    43,    44,    43,    44,
     215,   216,   217,    50,    49,    53,    35,    49,    36,   180,
     225,    43,    44,    36,    43,    44,   231,    36,    50,    64,
      49,    43,    44,   230,   104,   105,   233,    49,    56,    57,
      58,    59,    60,    61,   246,   250,   251,    35,   253,   368,
     369,   370,    64,    93,    94,    95,     5,   262,   263,   264,
     265,   266,   267,    22,    23,     4,    37,    37,   229,    37,
      37,    19,    53,     4,   247,   236,    37,   238,     4,   276,
       4,   286,   287,     5,    36,   290,     4,   292,   293,   294,
     295,     4,   297,   298,   299,     3,     4,   302,   300,     7,
     280,   281,   282,   283,   301,    50,    50,    37,    55,    49,
     315,   316,   317,    50,   319,   320,   321,   322,   323,   324,
     325,    50,   327,   303,   329,   330,     3,     4,    55,   334,
       7,    50,    36,    50,    50,    43,    44,   342,   318,    50,
      54,    49,    37,    36,    14,    50,    27,    54,   353,   354,
     355,   356,    22,    23,    24,    25,   336,    53,    50,   364,
      36,   341,    53,    53,   366,    53,    43,    44,    53,    53,
      49,    36,    49,   366,    54,    50,    25,   382,   358,    53,
      14,    53,   387,    53,   389,   390,   391,   392,    54,    26,
       4,    25,   372,   366,   399,   400,   401,   402,   403,    13,
      14,    15,    16,    17,    18,    56,    57,    58,    59,    60,
      61,    62,    63,   393,    54,   395,   396,   397,   398,    53,
      40,    91,    92,    93,    94,    95,    96,     4,    98,    99,
     100,   101,   102,   103,   104,   105,    13,    14,    15,    16,
      17,    18,   112,    10,    54,    54,    13,    14,    15,    16,
      17,    18,    40,   123,   124,    50,    50,    91,    92,    93,
      94,    95,    96,    50,    98,    99,   100,   101,   102,   103,
     104,   105,    54,    22,     3,     4,     5,    36,     7,    54,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
     124,    20,    21,    54,    36,    24,    53,    49,    54,    28,
      29,    30,    50,    23,    33,    50,    35,    50,    56,    57,
      58,    59,    60,    61,    43,    44,    50,    53,    53,   291,
      49,    53,    56,    57,    58,    59,    60,    61,    53,     3,
       4,     5,    53,     7,   314,    64,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    54,    20,    21,    54,    54,
      24,    54,    54,    54,    28,    29,    30,   230,   301,    33,
     285,    35,   344,   233,   227,    53,    -1,    -1,    -1,    43,
      44,    -1,    -1,    -1,    -1,    49,   246,   247,    13,    14,
      15,    16,    17,    18,    56,    57,    58,    59,    60,    61,
      64,    -1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      20,    21,   246,   247,    24,    -1,    -1,    -1,    28,    29,
      30,    -1,    -1,    33,    -1,    35,    -1,    -1,    -1,    -1,
     300,    -1,    -1,    43,    44,    -1,    -1,    -1,    -1,    49,
      98,    99,   100,   101,   102,   103,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   300,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   366
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     7,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    20,    21,    24,    28,    29,    30,
      33,    35,    43,    44,    49,    64,    66,    67,    70,    71,
      72,    73,    78,    80,    83,    86,    87,    90,    96,    97,
      98,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,    49,    55,     4,     5,     4,    72,    80,   100,
     106,    49,    49,    53,    49,    36,    49,    36,     4,    72,
     107,   107,   100,   103,   106,     0,     9,   111,    36,    36,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
      36,    43,    44,    45,    46,    47,    48,    36,    56,    57,
      58,    59,    60,    61,    62,    63,   111,    10,   110,     4,
      69,    70,   111,    35,    72,    80,   100,   108,    55,    53,
      36,    36,    36,   111,   111,   111,   111,    35,   111,    50,
      50,   111,    66,   111,   111,    78,   109,    66,    78,    78,
      78,    78,    78,    78,    78,    78,   111,   101,   101,   102,
     102,   102,   106,   111,   104,   106,   104,   104,   104,   104,
     104,   105,   105,    78,     5,     4,    69,    70,    37,    49,
      72,    76,    81,   110,    37,    37,    37,    37,    37,    19,
     111,    72,    80,   100,   103,    34,   100,    78,    79,    88,
     110,    37,    99,    78,    78,    78,    78,    78,    53,    49,
       4,    69,   111,    37,    82,    82,   111,     4,     4,    70,
      70,    70,    70,    70,     5,    67,    68,    78,   111,   111,
     111,   111,   111,   111,   111,    36,     4,     4,    50,   111,
     111,    74,    76,   111,    50,    49,   111,   111,   111,    50,
      50,    50,    50,    50,    50,    54,   111,    55,    99,    36,
      68,    74,   111,    37,    75,    72,    76,    36,    50,    68,
      54,    68,    53,    53,    53,    53,    53,    53,    27,    89,
     103,    72,   100,   111,   111,    50,   111,    82,    82,    36,
     111,   111,   111,   111,   111,   111,    49,    36,    54,    50,
      53,    76,    78,    78,    78,    78,    25,    92,    94,    92,
     111,   111,    53,   111,    75,   111,   111,   111,   111,     3,
      34,    95,   111,   111,   111,    72,   103,    88,   111,    77,
      78,    54,    54,    54,    54,    40,    26,    91,    93,    94,
      91,   111,   111,   111,    77,   111,   111,   111,   111,   111,
     111,   111,    40,   111,   111,   111,    50,    50,    50,   111,
      54,    77,    22,    84,    84,    84,    84,    78,   111,    54,
      93,    54,    36,    36,    53,    54,    49,   111,   111,   111,
     111,    78,   111,    72,    80,   100,   103,    23,    85,    85,
      85,    85,    78,    50,    50,    50,    50,    53,   111,    53,
      53,    53,    53,   111,    54,   111,   111,   111,   111,    78,
      78,    78,    78,    78,   111,   111,   111,   111,   111,    54,
      54,    54,    54,    54,    84,    84,    84,    84
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    66,    66,    66,    67,    67,    68,    68,    68,
      69,    69,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    71,    71,    71,    71,    71,    72,    73,    73,
      74,    74,    75,    75,    76,    77,    77,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    79,    79,    80,    81,    81,    81,    82,
      82,    82,    83,    83,    83,    83,    84,    84,    84,    84,
      84,    85,    85,    86,    86,    87,    88,    88,    89,    89,
      90,    90,    91,    91,    92,    93,    93,    94,    95,    95,
      96,    96,    96,    97,    98,    99,    99,   100,   100,   100,
     101,   101,   101,   101,   102,   102,   103,   103,   103,   103,
     103,   103,   103,   104,   104,   104,   105,   105,   106,   106,
     106,   107,   107,   107,   107,   107,   108,   109,   109,   110,
     110,   110,   110,   110,   110,   110,   111,   111
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     3,     8,     7,     0,     3,     3,
       1,     3,     3,     5,     3,     5,     3,     5,     3,     5,
       3,     5,     2,     3,     3,     2,     1,     1,    13,    12,
       0,     2,     0,     4,     2,     0,     3,     0,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     4,     4,     4,
       3,     3,     4,     4,     4,     7,     0,     2,     2,     0,
       4,     4,    15,    15,    15,    15,     0,    10,    10,    10,
      10,     0,     6,    13,    13,    17,     0,     1,     0,     1,
      13,    13,     0,     4,     3,     0,     3,     5,     1,     1,
       3,     3,     3,     2,     6,     0,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     3,     1,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     2,     1,     2,
       2,     1,     1,     1,     3,     3,     8,     1,     1,     0,
       1,     1,     1,     1,     1,     1,     0,     2
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

#line 1497 "project.tab.c"

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

#line 329 "project.y"


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
