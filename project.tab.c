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
void yyerror(const char *s);
extern FILE *yyin;
extern FILE *yyout;
extern int yylex();
extern int yylineno;
extern char *yytext;

#line 83 "project.tab.c"

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
  YYSYMBOL_variable_declaration = 69,      /* variable_declaration  */
  YYSYMBOL_method_declaration = 70,        /* method_declaration  */
  YYSYMBOL_none_or_multiple_parameters = 71, /* none_or_multiple_parameters  */
  YYSYMBOL_parameters = 72,                /* parameters  */
  YYSYMBOL_parameter = 73,                 /* parameter  */
  YYSYMBOL_method_body = 74,               /* method_body  */
  YYSYMBOL_statement = 75,                 /* statement  */
  YYSYMBOL_assignment_statement = 76,      /* assignment_statement  */
  YYSYMBOL_method_call = 77,               /* method_call  */
  YYSYMBOL_none_or_multiple_arguments = 78, /* none_or_multiple_arguments  */
  YYSYMBOL_arguments = 79,                 /* arguments  */
  YYSYMBOL_if_statement = 80,              /* if_statement  */
  YYSYMBOL_none_or_multiple_elif = 81,     /* none_or_multiple_elif  */
  YYSYMBOL_none_or_one_else = 82,          /* none_or_one_else  */
  YYSYMBOL_do_while_statement = 83,        /* do_while_statement  */
  YYSYMBOL_for_statement = 84,             /* for_statement  */
  YYSYMBOL_first_and_third_loop_statement = 85, /* first_and_third_loop_statement  */
  YYSYMBOL_second_loop_statement = 86,     /* second_loop_statement  */
  YYSYMBOL_switch_statement = 87,          /* switch_statement  */
  YYSYMBOL_default_case = 88,              /* default_case  */
  YYSYMBOL_one_or_more_cases = 89,         /* one_or_more_cases  */
  YYSYMBOL_multiple_cases = 90,            /* multiple_cases  */
  YYSYMBOL_cases = 91,                     /* cases  */
  YYSYMBOL_case_expression = 92,           /* case_expression  */
  YYSYMBOL_return_statement = 93,          /* return_statement  */
  YYSYMBOL_break_statement = 94,           /* break_statement  */
  YYSYMBOL_print_statement = 95,           /* print_statement  */
  YYSYMBOL_single_or_multiple_variables = 96, /* single_or_multiple_variables  */
  YYSYMBOL_expression = 97,                /* expression  */
  YYSYMBOL_text = 98,                      /* text  */
  YYSYMBOL_any_character = 99,             /* any_character  */
  YYSYMBOL_object_creation = 100,          /* object_creation  */
  YYSYMBOL_member_access = 101,            /* member_access  */
  YYSYMBOL_member_access_body = 102,       /* member_access_body  */
  YYSYMBOL_operations = 103,               /* operations  */
  YYSYMBOL_integer_operations = 104,       /* integer_operations  */
  YYSYMBOL_char_operations = 105,          /* char_operations  */
  YYSYMBOL_double_operations = 106,        /* double_operations  */
  YYSYMBOL_boolean_operations = 107,       /* boolean_operations  */
  YYSYMBOL_relational_arithmetic_operations = 108, /* relational_arithmetic_operations  */
  YYSYMBOL_arithmetic_operators = 109,     /* arithmetic_operators  */
  YYSYMBOL_relational_operators = 110,     /* relational_operators  */
  YYSYMBOL_logical_operators = 111,        /* logical_operators  */
  YYSYMBOL_access_modifier = 112,          /* access_modifier  */
  YYSYMBOL_data_type = 113,                /* data_type  */
  YYSYMBOL_integer_expression = 114,       /* integer_expression  */
  YYSYMBOL_double_expression = 115,        /* double_expression  */
  YYSYMBOL_boolean_expression = 116,       /* boolean_expression  */
  YYSYMBOL_string_expression = 117,        /* string_expression  */
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
#define YYFINAL  75
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   441

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  127
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  329

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
       0,    58,    58,    59,    60,    63,    64,    67,    68,    69,
      72,    73,    76,    77,    80,    81,    84,    85,    88,    91,
      92,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   111,   112,   113,   114,   115,
     116,   119,   122,   123,   126,   127,   130,   133,   134,   137,
     138,   141,   144,   147,   148,   151,   152,   155,   158,   159,
     162,   165,   166,   169,   172,   173,   174,   177,   180,   183,
     186,   187,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   202,   205,   208,   211,   214,   215,   218,   219,
     220,   221,   224,   227,   230,   233,   236,   237,   240,   241,
     242,   243,   244,   245,   248,   249,   250,   251,   252,   253,
     256,   257,   258,   261,   262,   265,   266,   267,   268,   269,
     270,   273,   276,   279,   280,   283,   286,   287
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
  "class_declaration", "class_body", "variable_declaration",
  "method_declaration", "none_or_multiple_parameters", "parameters",
  "parameter", "method_body", "statement", "assignment_statement",
  "method_call", "none_or_multiple_arguments", "arguments", "if_statement",
  "none_or_multiple_elif", "none_or_one_else", "do_while_statement",
  "for_statement", "first_and_third_loop_statement",
  "second_loop_statement", "switch_statement", "default_case",
  "one_or_more_cases", "multiple_cases", "cases", "case_expression",
  "return_statement", "break_statement", "print_statement",
  "single_or_multiple_variables", "expression", "text", "any_character",
  "object_creation", "member_access", "member_access_body", "operations",
  "integer_operations", "char_operations", "double_operations",
  "boolean_operations", "relational_arithmetic_operations",
  "arithmetic_operators", "relational_operators", "logical_operators",
  "access_modifier", "data_type", "integer_expression",
  "double_expression", "boolean_expression", "string_expression",
  "none_or_newlines", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-250)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-22)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     313,  -250,   -23,    17,  -250,    36,  -250,  -250,    67,    70,
      71,    72,    73,  -250,    88,    33,    41,    40,    47,    61,
    -250,  -250,    49,  -250,  -250,    88,   102,   313,    94,    94,
      94,    69,    74,    94,    94,    94,    94,    94,    94,    94,
      81,  -250,    68,    94,  -250,  -250,  -250,  -250,  -250,  -250,
     224,   100,    68,    68,    -3,   103,    94,    88,    53,    56,
      63,    66,    76,    78,    80,    -9,  -250,   105,    94,    94,
      94,    94,  -250,   104,    98,  -250,  -250,    94,   392,   392,
     313,    94,    94,   392,   392,   392,   392,   392,   392,   392,
      94,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,   110,  -250,  -250,   392,   133,  -250,  -250,
    -250,  -250,  -250,   145,   -13,   150,   148,  -250,  -250,  -250,
      22,   -12,   120,  -250,    88,  -250,   138,    94,   150,   110,
     148,    22,   104,  -250,    88,    88,   392,   175,   121,  -250,
    -250,  -250,   191,  -250,  -250,   392,   392,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,   392,  -250,  -250,   107,    -1,  -250,
      94,  -250,  -250,  -250,  -250,  -250,    94,   124,   158,   353,
    -250,  -250,  -250,  -250,  -250,  -250,    94,    94,    94,   109,
      67,    70,    71,    72,    73,  -250,   129,   165,   122,  -250,
    -250,  -250,    94,  -250,    94,   191,   123,    94,  -250,   132,
      94,    94,    94,   134,   136,   128,    94,   121,   147,   353,
     191,    94,   156,   183,  -250,    88,   144,   353,   141,   353,
     143,   146,   186,    88,  -250,  -250,    94,    94,   152,    94,
    -250,  -250,   124,   178,  -250,  -250,  -250,    94,    94,   166,
     180,  -250,   163,   169,   168,   191,  -250,  -250,   392,   197,
      94,    94,  -250,   173,    94,   156,    94,    15,    94,    94,
      88,   175,    94,   392,  -250,   181,  -250,   187,  -250,  -250,
     203,   197,    94,    94,   392,    94,    94,    94,    94,   204,
      94,  -250,    94,   193,   195,    94,   199,   392,   233,   392,
      94,   206,   197,   221,   208,   211,  -250,  -250,   213,    94,
    -250,   392,  -250,  -250,  -250,    94,  -250,    88,   244,  -250,
     392,   219,   217,  -250,    94,   218,    94,   222,    94,   392,
    -250,   392,    94,    94,   223,   226,  -250,   233,  -250
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,   121,    77,     0,   122,     0,   113,   114,     0,     0,
       0,     0,     0,   120,     0,     0,     0,     0,     0,     0,
     123,   124,     0,    83,    82,     0,     0,     2,   126,   126,
     126,     0,     0,   126,   126,   126,   126,   126,   126,   126,
       0,    76,    73,   126,    80,    79,    88,    89,    90,    91,
       0,     0,    72,    74,    75,     0,   126,     0,     0,     0,
       0,     0,     0,     0,     0,    77,    78,     0,   126,   126,
     126,   126,    68,     0,     0,     1,     3,   126,    21,    21,
       2,   126,   126,    21,    21,    21,    21,    21,    21,    21,
     126,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,    96,    97,    21,     0,   115,   116,
     117,   118,   119,     0,     0,     0,     0,   110,   111,   112,
       0,     0,     0,    85,    42,    35,     0,   126,     0,     0,
       0,     0,     0,    67,     0,     0,    21,    53,    70,    81,
     127,    32,     0,    33,     4,    21,    21,    24,    25,    26,
      27,    28,    29,    30,    21,    93,    34,     0,     0,    10,
     126,    92,    94,    95,    86,    87,   126,    44,     0,     7,
      36,    37,    38,    39,   125,    40,   126,   126,   126,     0,
       0,     0,     0,     0,     0,    54,     0,     0,     0,    22,
      23,    31,   126,    11,   126,    14,     0,   126,    43,     0,
     126,   126,   126,     0,     0,     0,   126,    70,     0,     7,
      14,   126,    16,     0,    41,     0,     0,     7,     0,     7,
       0,     0,     0,    55,    71,    69,   126,   126,     0,   126,
      15,    18,    44,     0,     8,     6,     9,   126,   126,     0,
       0,    56,     0,     0,     0,     0,    45,    84,    21,     0,
     126,   126,     5,     0,   126,    16,   126,     0,   126,   126,
       0,    53,   126,    19,    17,     0,    64,     0,    66,    65,
      58,    61,   126,   126,    19,   126,   126,   126,   126,     0,
     126,    60,   126,     0,     0,   126,     0,    19,    47,    21,
     126,     0,    61,     0,     0,     0,    13,    20,     0,   126,
      63,    21,    57,    62,    51,   126,    12,     0,    49,    59,
      21,     0,     0,    46,   126,     0,   126,     0,   126,    21,
      52,    21,   126,   126,     0,     0,    50,    47,    48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -250,   -11,    19,  -147,  -250,  -250,    62,    20,    37,  -249,
       0,  -131,     8,  -250,    46,  -250,   -46,  -250,  -250,  -250,
      23,  -250,  -250,  -250,  -250,    -7,    34,  -250,  -250,  -250,
    -250,    79,    43,   -59,   -98,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,    14,  -250,  -250,  -250,     1,   -48,   -76,
     -96,   -73,  -250,   -26
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    26,   200,   201,    28,    29,   211,   230,   212,   275,
     202,    31,    32,   166,   198,    33,   299,   313,    34,    35,
     186,   240,    36,   280,   258,   281,   282,   267,    37,    38,
      39,   188,    40,    41,    42,    43,    44,   123,    45,    46,
      47,    48,    49,   103,   104,   105,   120,   142,    51,    52,
      53,    54,   175,    78
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      30,    50,   113,    79,    80,   155,   185,    83,    84,    85,
      86,    87,    88,    89,   138,    55,    76,   106,   266,    27,
     162,    58,    66,   159,   164,   285,    56,    30,    50,    55,
     124,   171,    57,    66,   172,   193,   160,    56,   297,   161,
      56,    59,   134,   135,   136,   137,    27,   163,   194,    23,
      24,   140,   170,    20,    21,   145,   146,    67,   173,   117,
     118,   119,   226,   122,   154,    66,   115,   116,    74,   144,
     234,    60,   236,   174,    61,    62,    63,    64,   141,   143,
      30,    50,    68,   147,   148,   149,   150,   151,   152,   153,
      69,     1,    65,    70,   113,     4,    71,    72,    73,    27,
     125,   169,    75,    77,   114,    81,   156,   121,   126,   127,
      82,    91,    92,    93,    94,    95,    96,    90,   128,    20,
      21,   129,    23,    24,    97,    98,    99,   100,   101,   102,
     185,   130,    66,   131,   195,   132,   178,    25,   157,    24,
     196,   133,    66,    66,    23,   189,   190,   213,   139,   158,
     203,   204,   205,     1,   191,     4,   165,   168,   187,   269,
     192,   197,   213,   199,    57,   206,   209,   167,   210,   207,
      50,   215,   208,   214,   217,   218,   219,   176,   177,   179,
     223,   216,   222,   225,   220,   228,   221,   231,   180,   181,
     182,   183,   184,   229,   233,   235,   237,   213,   268,   238,
     242,   243,   244,   245,   108,   109,   110,   111,   112,    13,
      50,   248,   249,   239,   247,   250,   251,   252,    50,   253,
      50,   254,   257,    66,   260,   261,   262,   278,   263,   279,
     265,    66,   270,   271,   107,   277,   274,   108,   109,   110,
     111,   112,    13,   293,   290,   294,   283,   284,   256,   286,
     287,   288,   289,   296,   291,   298,   292,   304,   232,   295,
     302,   305,   307,   276,   301,   306,   241,   312,    66,   315,
     316,   318,   227,   308,   276,   264,   320,   326,   246,   310,
     327,   328,   255,   259,   273,   303,   224,   276,   317,   300,
     319,     0,   321,     0,     0,     0,   324,   325,     0,     0,
       0,   309,     0,   272,     0,     0,     0,     0,     0,     0,
     314,     0,     0,     0,     0,    66,     1,     2,     3,   322,
       4,   323,   -21,     5,     6,     7,     8,     9,    10,    11,
      12,    13,     0,    14,    15,     0,     0,    16,     0,     0,
       0,    17,    18,    19,    20,    21,    22,    23,    24,     0,
     311,     0,     0,     0,     0,     0,     1,     2,     3,     0,
       4,     0,    25,     5,     6,     7,     8,     9,    10,    11,
      12,    13,     0,    14,    15,     0,     0,    16,     0,     0,
       0,    17,    18,    19,    20,    21,    22,    23,    24,     0,
       0,     0,     0,     0,     0,     1,     2,     3,     0,     4,
       0,     0,    25,     6,     7,     8,     9,    10,    11,    12,
      13,     0,    14,    15,     0,     0,    16,     0,     0,     0,
      17,    18,    19,    20,    21,    22,    23,    24,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25
};

static const yytype_int16 yycheck[] =
{
       0,     0,    50,    29,    30,   103,   137,    33,    34,    35,
      36,    37,    38,    39,    73,    38,    27,    43,     3,     0,
     116,     4,    14,    36,    36,   274,    49,    27,    27,    38,
      56,   129,    55,    25,   130,    36,    49,    49,   287,   115,
      49,     5,    68,    69,    70,    71,    27,   120,    49,    34,
      35,    77,   128,    31,    32,    81,    82,    14,   131,    62,
      63,    64,   209,    55,    90,    57,    52,    53,    25,    80,
     217,     4,   219,   132,     4,     4,     4,     4,    78,    79,
      80,    80,    49,    83,    84,    85,    86,    87,    88,    89,
      49,     3,     4,    53,   142,     7,    49,    36,    49,    80,
      57,   127,     0,     9,     4,    36,   106,     4,    55,    53,
      36,    43,    44,    45,    46,    47,    48,    36,    55,    31,
      32,    55,    34,    35,    56,    57,    58,    59,    60,    61,
     261,    55,   124,    55,   160,    55,   136,    49,     5,    35,
     166,    36,   134,   135,    34,   145,   146,   195,    50,     4,
     176,   177,   178,     3,   154,     7,    36,    19,    37,   257,
      53,    37,   210,     5,    55,    36,   192,   124,   194,     4,
     169,   197,    50,    50,   200,   201,   202,   134,   135,     4,
     206,    49,    54,    36,    50,   211,    50,     4,    13,    14,
      15,    16,    17,    37,    50,    54,    53,   245,   257,    53,
     226,   227,    50,   229,    13,    14,    15,    16,    17,    18,
     209,   237,   238,    27,    36,    49,    36,    54,   217,    50,
     219,    53,    25,   215,   250,   251,    53,    40,   254,    26,
     256,   223,   258,   259,    10,    54,   262,    13,    14,    15,
      16,    17,    18,    50,    40,    50,   272,   273,   248,   275,
     276,   277,   278,    54,   280,    22,   282,    36,   215,   285,
      54,    53,    49,   263,   290,    54,   223,    23,   260,    50,
      53,    53,   210,   299,   274,   255,    54,    54,   232,   305,
      54,   327,   245,   249,   261,   292,   207,   287,   314,   289,
     316,    -1,   318,    -1,    -1,    -1,   322,   323,    -1,    -1,
      -1,   301,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,
     310,    -1,    -1,    -1,    -1,   307,     3,     4,     5,   319,
       7,   321,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,    20,    21,    -1,    -1,    24,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
     307,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
       7,    -1,    49,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,    20,    21,    -1,    -1,    24,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,
      -1,    -1,    49,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    -1,    -1,    24,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     7,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    20,    21,    24,    28,    29,    30,
      31,    32,    33,    34,    35,    49,    66,    67,    69,    70,
      75,    76,    77,    80,    83,    84,    87,    93,    94,    95,
      97,    98,    99,   100,   101,   103,   104,   105,   106,   107,
     112,   113,   114,   115,   116,    38,    49,    55,     4,     5,
       4,     4,     4,     4,     4,     4,    77,    97,    49,    49,
      53,    49,    36,    49,    97,     0,    66,     9,   118,   118,
     118,    36,    36,   118,   118,   118,   118,   118,   118,   118,
      36,    43,    44,    45,    46,    47,    48,    56,    57,    58,
      59,    60,    61,   108,   109,   110,   118,    10,    13,    14,
      15,    16,    17,   113,     4,   108,   108,    62,    63,    64,
     111,     4,    77,   102,   118,    97,    55,    53,    55,    55,
      55,    55,    55,    36,   118,   118,   118,   118,    98,    50,
     118,    75,   112,    75,    66,   118,   118,    75,    75,    75,
      75,    75,    75,    75,   118,    99,    75,     5,     4,    36,
      49,   114,   115,   116,    36,    36,    78,    97,    19,   118,
     114,    99,   115,   116,    98,   117,    97,    97,    75,     4,
      13,    14,    15,    16,    17,    76,    85,    37,    96,    75,
      75,    75,    53,    36,    49,   118,   118,    37,    79,     5,
      67,    68,    75,   118,   118,   118,    36,     4,    50,   118,
     118,    71,    73,   113,    50,   118,    49,   118,   118,   118,
      50,    50,    54,   118,    96,    36,    68,    71,   118,    37,
      72,     4,    97,    50,    68,    54,    68,    53,    53,    27,
      86,    97,   118,   118,    50,   118,    79,    36,   118,   118,
      49,    36,    54,    50,    53,    73,    75,    25,    89,    91,
     118,   118,    53,   118,    72,   118,     3,    92,    98,    99,
     118,   118,    97,    85,   118,    74,    75,    54,    40,    26,
      88,    90,    91,   118,   118,    74,   118,   118,   118,   118,
      40,   118,   118,    50,    50,   118,    54,    74,    22,    81,
      75,   118,    54,    90,    36,    53,    54,    49,   118,    75,
     118,    97,    23,    82,    75,    50,    53,   118,    53,   118,
      54,   118,    75,    75,   118,   118,    54,    54,    81
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    66,    66,    66,    67,    67,    68,    68,    68,
      69,    69,    70,    70,    71,    71,    72,    72,    73,    74,
      74,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    76,    76,    76,    76,    76,
      76,    77,    78,    78,    79,    79,    80,    81,    81,    82,
      82,    83,    84,    85,    85,    86,    86,    87,    88,    88,
      89,    90,    90,    91,    92,    92,    92,    93,    94,    95,
      96,    96,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    98,    99,   100,   101,   102,   102,   103,   103,
     103,   103,   104,   105,   106,   107,   108,   108,   109,   109,
     109,   109,   109,   109,   110,   110,   110,   110,   110,   110,
     111,   111,   111,   112,   112,   113,   113,   113,   113,   113,
     113,   114,   115,   116,   116,   117,   118,   118
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     3,     8,     7,     0,     3,     3,
       3,     4,    13,    12,     0,     2,     0,     4,     2,     0,
       3,     0,     4,     4,     3,     3,     3,     3,     3,     3,
       3,     4,     3,     3,     3,     3,     4,     4,     4,     4,
       4,     6,     0,     2,     0,     4,    15,     0,    10,     0,
       6,    13,    17,     0,     1,     0,     1,    13,     0,     4,
       3,     0,     3,     5,     1,     1,     1,     3,     2,     6,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     8,     3,     2,     2,     1,     1,
       1,     1,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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

#line 1432 "project.tab.c"

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

#line 290 "project.y"


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
