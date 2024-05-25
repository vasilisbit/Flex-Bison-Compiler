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

typedef enum {
    INTEGER_TYPE,
    CHAR_TYPE,
    DOUBLE_TYPE,
    BOOLEAN_TYPE,
    STRING_TYPE,
    VOID_TYPE
} DATA_TYPE;

typedef struct symbol{
    char *name;
    int type; // 0 for variable, 1 for method
    DATA_TYPE data_type;
} symbol;

symbol *symbol_table[1000];
int symbol_count = 0;

symbol* lookup(char *name);
void insert(char *name, int type, DATA_TYPE data_type);

#line 105 "project.tab.c"

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
  YYSYMBOL_expression = 100,               /* expression  */
  YYSYMBOL_text = 101,                     /* text  */
  YYSYMBOL_any_character = 102,            /* any_character  */
  YYSYMBOL_object_creation = 103,          /* object_creation  */
  YYSYMBOL_member_access = 104,            /* member_access  */
  YYSYMBOL_member_access_body = 105,       /* member_access_body  */
  YYSYMBOL_operations = 106,               /* operations  */
  YYSYMBOL_integer_operations = 107,       /* integer_operations  */
  YYSYMBOL_char_operations = 108,          /* char_operations  */
  YYSYMBOL_double_operations = 109,        /* double_operations  */
  YYSYMBOL_boolean_operations = 110,       /* boolean_operations  */
  YYSYMBOL_relational_arithmetic_operations = 111, /* relational_arithmetic_operations  */
  YYSYMBOL_arithmetic_operators = 112,     /* arithmetic_operators  */
  YYSYMBOL_relational_operators = 113,     /* relational_operators  */
  YYSYMBOL_logical_operators = 114,        /* logical_operators  */
  YYSYMBOL_access_modifier = 115,          /* access_modifier  */
  YYSYMBOL_data_type = 116,                /* data_type  */
  YYSYMBOL_integer_expression = 117,       /* integer_expression  */
  YYSYMBOL_double_expression = 118,        /* double_expression  */
  YYSYMBOL_boolean_expression = 119,       /* boolean_expression  */
  YYSYMBOL_none_or_newlines = 120          /* none_or_newlines  */
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
#define YYFINAL  72
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   575

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  129
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  318

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
       0,    86,    86,    87,    88,    91,    92,    95,    96,    97,
     100,   101,   104,   107,   112,   115,   118,   119,   120,   123,
     131,   134,   139,   140,   143,   144,   147,   150,   151,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   170,   183,   192,   193,   196,   197,   200,
     203,   204,   207,   208,   211,   214,   217,   218,   221,   222,
     225,   228,   229,   232,   235,   236,   239,   242,   243,   244,
     247,   250,   253,   256,   257,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   272,   275,   278,   281,   284,
     285,   288,   289,   290,   291,   294,   297,   300,   303,   306,
     307,   310,   311,   312,   313,   314,   315,   318,   319,   320,
     321,   322,   323,   326,   327,   328,   331,   332,   335,   336,
     337,   338,   339,   340,   343,   346,   349,   350,   356,   357
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
  "single_or_multiple_variables", "expression", "text", "any_character",
  "object_creation", "member_access", "member_access_body", "operations",
  "integer_operations", "char_operations", "double_operations",
  "boolean_operations", "relational_arithmetic_operations",
  "arithmetic_operators", "relational_operators", "logical_operators",
  "access_modifier", "data_type", "integer_expression",
  "double_expression", "boolean_expression", "none_or_newlines", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-237)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-82)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     447,  -237,    51,    18,  -237,    19,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,     3,    -8,    -5,    -7,    -1,    31,
    -237,  -237,    39,  -237,  -237,     3,    90,    83,  -237,    57,
      59,    83,    83,     6,    83,    83,    83,    83,    83,    83,
      83,    60,  -237,    12,    83,  -237,  -237,  -237,  -237,  -237,
    -237,   120,    93,    12,    12,     2,    95,    83,     3,    46,
      49,   -21,  -237,  -237,    68,    83,    83,    83,    83,  -237,
      89,    76,  -237,    83,   447,    83,    83,   526,   447,   526,
     526,   526,   526,   526,   526,   526,   526,    83,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
      94,  -237,  -237,   526,   122,   125,   -26,  -237,  -237,   136,
     133,  -237,  -237,  -237,    44,   -10,  -237,    83,     3,   104,
     123,    83,  -237,     3,     3,   526,   105,   106,  -237,  -237,
    -237,   526,   526,  -237,   105,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,   526,  -237,  -237,    92,   -19,  -237,
    -237,   142,    83,  -237,  -237,  -237,  -237,  -237,    83,   110,
     145,   146,   487,    83,    83,    83,  -237,   114,   148,   149,
     107,  -237,  -237,  -237,    83,    83,   117,  -237,   105,   108,
      83,  -237,   100,  -237,   112,    83,    83,    83,   109,   113,
     102,    83,   111,   106,   126,   487,   105,    83,   127,   161,
     131,     3,   129,   487,   130,   487,   132,   134,   156,     3,
       3,  -237,  -237,    83,    83,   139,    83,  -237,  -237,  -237,
     110,   150,  -237,  -237,  -237,    83,    83,   144,   155,  -237,
    -237,   141,   157,   153,   105,  -237,  -237,   526,   183,    83,
      83,  -237,   158,    83,   127,    83,    16,    83,    83,     3,
     105,    83,   526,  -237,   160,  -237,   169,  -237,  -237,   191,
     183,    83,    83,   526,    83,    83,    83,    83,   178,    83,
    -237,    83,   170,   171,    83,   165,   526,   200,   526,    83,
     172,   183,   192,   174,   175,  -237,  -237,   181,    83,  -237,
     526,  -237,  -237,  -237,    83,  -237,     3,   208,  -237,   526,
     184,   180,  -237,    83,   182,    83,   185,    83,   526,  -237,
     526,    83,    83,   187,   188,  -237,   200,  -237
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,   124,    19,     0,   125,     0,   116,   117,   118,   119,
     120,   121,   122,   123,     0,     0,     0,     0,     0,     0,
     126,   127,     0,    86,    85,     0,     0,   128,    18,     0,
       0,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,     0,    79,    76,   128,    83,    82,    91,    92,    93,
      94,     0,     0,    75,    77,    78,     0,   128,     0,     0,
       0,    19,    80,    81,     0,   128,   128,   128,   128,    71,
       0,     0,     1,   128,     2,   128,   128,    29,     2,    29,
      29,    29,    29,    29,    29,    29,    29,   128,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
       0,    99,   100,    29,     0,     0,    10,    14,    17,     0,
       0,   113,   114,   115,     0,     0,    90,   128,    45,    12,
       0,   128,    70,     0,     0,    29,    56,    73,    84,   129,
       3,    29,    29,    40,     0,     4,    30,    31,    32,    33,
      34,    35,    36,    37,    29,    96,    41,     0,    10,    15,
      16,     0,   128,    95,    97,    98,    89,    88,   128,    47,
       0,     0,     7,   128,   128,   128,    57,     0,     0,     0,
       0,    39,    42,    38,   128,   128,    10,    11,    22,     0,
     128,    46,     0,    13,     0,   128,   128,   128,     0,     0,
       0,   128,     0,    73,     0,     7,    22,   128,    24,     0,
       0,     0,     0,     7,     0,     7,     0,     0,     0,    58,
       0,    74,    72,   128,   128,     0,   128,    23,    26,    44,
      47,     0,     8,     6,     9,   128,   128,     0,     0,    59,
      43,     0,     0,     0,     0,    48,    87,    29,     0,   128,
     128,     5,     0,   128,    24,   128,     0,   128,   128,     0,
      56,   128,    27,    25,     0,    67,     0,    69,    68,    61,
      64,   128,   128,    27,   128,   128,   128,   128,     0,   128,
      63,   128,     0,     0,   128,     0,    27,    50,    29,   128,
       0,    64,     0,     0,     0,    21,    28,     0,   128,    66,
      29,    60,    65,    54,   128,    20,     0,    52,    62,    29,
       0,     0,    49,   128,     0,   128,     0,   128,    29,    55,
      29,   128,   128,     0,     0,    53,    50,    51
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -237,   -53,    13,  -142,   -97,   -43,  -237,   -11,  -237,    47,
       1,    10,  -236,     0,  -237,   -13,  -237,    26,  -237,   -69,
    -237,  -237,  -237,    -2,  -237,  -237,  -237,  -237,   -32,    15,
    -237,  -237,  -237,  -237,    58,    -9,   -66,   -98,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,   -22,  -237,  -237,  -237,
      20,   -18,   147,   140,   143,   137
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    26,   185,   186,   107,    28,    29,    30,    31,   197,
     217,   198,   264,   187,   166,    33,   158,   181,    34,   288,
     302,    35,    36,   167,   228,    37,   269,   247,   270,   271,
     256,    38,    39,    40,   170,    41,    42,    43,    44,    45,
     117,    46,    47,    48,    49,    50,   100,   101,   102,   114,
     134,    52,    53,    54,    55,    74
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,    63,   145,    62,   127,    64,     1,    61,   149,   108,
       4,   151,    63,    27,    62,    73,    71,    56,   151,   255,
      51,   130,    59,   152,    60,   135,   156,   274,    57,    58,
     175,   109,   110,   105,    20,    21,    58,    23,    24,    57,
     286,    65,   -81,   116,    66,    63,    67,    62,    68,   119,
      23,    24,    25,   213,   177,    88,    89,    90,    91,    92,
      93,   222,   150,   224,   111,   112,   113,    69,    94,    95,
      96,    97,    98,    99,    32,    20,    21,   133,    32,   136,
     137,   138,   139,   140,   141,   142,   143,    27,    70,    56,
      72,    27,    73,    75,    51,    76,    87,   106,    51,   115,
      57,   120,   121,   146,   122,    63,    58,    62,   168,   159,
      63,    63,    62,    62,   163,   164,   105,   183,     8,     9,
      10,    11,    12,    13,    24,   165,   128,   147,    23,   148,
     104,   171,   172,     8,     9,    10,    11,    12,    13,     1,
       4,   160,   161,   169,   173,   174,   176,   180,   258,   182,
     191,   184,   192,   193,   151,    58,   208,   194,   200,   206,
     199,   202,   212,   207,   216,   218,   210,   219,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,   199,   221,
     257,   103,    51,   227,   223,   225,   236,   226,    63,   233,
      62,   240,   220,   239,   118,   241,    63,    63,    62,    62,
     229,   230,   123,   124,   125,   126,   243,   242,   246,   267,
     129,   251,   131,   132,   266,    51,   199,   268,   279,   285,
     282,   283,   287,    51,   144,    51,   291,   294,   293,   295,
     296,   301,   168,   305,   304,   307,    63,   245,    62,   309,
     261,   315,   316,   214,   244,   253,   235,   317,   262,   292,
     154,   211,   265,   248,   157,     0,   153,   155,   162,     0,
       0,     0,     0,   265,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   265,     0,   289,     0,
       0,     0,     0,    63,     0,    62,     0,   300,     0,   178,
     298,     0,     0,     0,     0,   179,     0,     0,     0,   303,
     188,   189,   190,     0,     0,     0,     0,     0,   311,     0,
     312,   195,   196,     0,     0,     0,     0,   201,     0,     0,
       0,     0,   203,   204,   205,     0,     0,     0,   209,     0,
       0,     0,     0,     0,   215,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     231,   232,     0,   234,     0,     0,     0,     0,     0,     0,
       0,     0,   237,   238,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   249,   250,     0,     0,
     252,     0,   254,     0,   259,   260,     0,     0,   263,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   272,   273,
       0,   275,   276,   277,   278,     0,   280,     0,   281,     0,
       0,   284,     0,     0,     0,     0,   290,     0,     0,     0,
       0,     0,     0,     0,     0,   297,     0,     0,     0,     0,
       0,   299,     0,     0,     0,     0,     0,     0,     0,     0,
     306,     0,   308,     0,   310,     0,     0,     0,   313,   314,
       1,     2,     3,     0,     4,     0,   -29,     5,     6,     7,
       8,     9,    10,    11,    12,    13,     0,    14,    15,     0,
       0,    16,     0,     0,     0,    17,    18,    19,    20,    21,
      22,    23,    24,     0,     0,     0,     0,     0,     0,     0,
       1,     2,     3,     0,     4,     0,    25,     5,     6,     7,
       8,     9,    10,    11,    12,    13,     0,    14,    15,     0,
       0,    16,     0,     0,     0,    17,    18,    19,    20,    21,
      22,    23,    24,     0,     0,     0,     0,     0,     0,     1,
       2,     3,     0,     4,     0,     0,    25,     6,     7,     8,
       9,    10,    11,    12,    13,     0,    14,    15,     0,     0,
      16,     0,     0,     0,    17,    18,    19,    20,    21,    22,
      23,    24,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    25
};

static const yytype_int16 yycheck[] =
{
       0,    14,   100,    14,    70,    14,     3,     4,   105,    52,
       7,    37,    25,     0,    25,     9,    25,    38,    37,     3,
       0,    74,     4,    49,     5,    78,    36,   263,    49,    55,
      49,    53,    54,    51,    31,    32,    55,    34,    35,    49,
     276,    49,    36,    56,    49,    58,    53,    58,    49,    58,
      34,    35,    49,   195,   151,    43,    44,    45,    46,    47,
      48,   203,   105,   205,    62,    63,    64,    36,    56,    57,
      58,    59,    60,    61,    74,    31,    32,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    74,    49,    38,
       0,    78,     9,    36,    74,    36,    36,     4,    78,     4,
      49,    55,    53,   103,    36,   118,    55,   118,   126,   118,
     123,   124,   123,   124,   123,   124,   134,   160,    13,    14,
      15,    16,    17,    18,    35,   125,    50,     5,    34,     4,
      10,   131,   132,    13,    14,    15,    16,    17,    18,     3,
       7,    37,    19,    37,   144,    53,     4,    37,   246,     4,
      36,     5,     4,     4,    37,    55,    54,    50,    50,    50,
     178,    49,    36,    50,    37,     4,    55,    36,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,   196,    50,
     246,    44,   162,    27,    54,    53,    36,    53,   201,    50,
     201,    36,   201,    49,    57,    54,   209,   210,   209,   210,
     209,   210,    65,    66,    67,    68,    53,    50,    25,    40,
      73,    53,    75,    76,    54,   195,   234,    26,    40,    54,
      50,    50,    22,   203,    87,   205,    54,    53,    36,    54,
      49,    23,   250,    53,    50,    53,   249,   237,   249,    54,
     249,    54,    54,   196,   234,   244,   220,   316,   250,   281,
     110,   193,   252,   238,   117,    -1,   109,   114,   121,    -1,
      -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   276,    -1,   278,    -1,
      -1,    -1,    -1,   296,    -1,   296,    -1,   296,    -1,   152,
     290,    -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,   299,
     163,   164,   165,    -1,    -1,    -1,    -1,    -1,   308,    -1,
     310,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,    -1,
      -1,    -1,   185,   186,   187,    -1,    -1,    -1,   191,    -1,
      -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     213,   214,    -1,   216,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   239,   240,    -1,    -1,
     243,    -1,   245,    -1,   247,   248,    -1,    -1,   251,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   261,   262,
      -1,   264,   265,   266,   267,    -1,   269,    -1,   271,    -1,
      -1,   274,    -1,    -1,    -1,    -1,   279,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   288,    -1,    -1,    -1,    -1,
      -1,   294,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     303,    -1,   305,    -1,   307,    -1,    -1,    -1,   311,   312,
       3,     4,     5,    -1,     7,    -1,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    20,    21,    -1,
      -1,    24,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,     7,    -1,    49,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    20,    21,    -1,
      -1,    24,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,     7,    -1,    -1,    49,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    20,    21,    -1,    -1,
      24,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     7,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    20,    21,    24,    28,    29,    30,
      31,    32,    33,    34,    35,    49,    66,    67,    70,    71,
      72,    73,    78,    80,    83,    86,    87,    90,    96,    97,
      98,   100,   101,   102,   103,   104,   106,   107,   108,   109,
     110,   115,   116,   117,   118,   119,    38,    49,    55,     4,
       5,     4,    72,    80,   100,    49,    49,    53,    49,    36,
      49,   100,     0,     9,   120,    36,    36,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,    36,    43,    44,
      45,    46,    47,    48,    56,    57,    58,    59,    60,    61,
     111,   112,   113,   120,    10,   116,     4,    69,    70,   111,
     111,    62,    63,    64,   114,     4,    80,   105,   120,   100,
      55,    53,    36,   120,   120,   120,   120,   101,    50,   120,
      66,   120,   120,    78,   115,    66,    78,    78,    78,    78,
      78,    78,    78,    78,   120,   102,    78,     5,     4,    69,
      70,    37,    49,   117,   118,   119,    36,   120,    81,   100,
      37,    19,   120,   100,   100,    78,    79,    88,   116,    37,
      99,    78,    78,    78,    53,    49,     4,    69,   120,   120,
      37,    82,     4,    70,     5,    67,    68,    78,   120,   120,
     120,    36,     4,     4,    50,   120,   120,    74,    76,   116,
      50,   120,    49,   120,   120,   120,    50,    50,    54,   120,
      55,    99,    36,    68,    74,   120,    37,    75,     4,    36,
     100,    50,    68,    54,    68,    53,    53,    27,    89,   100,
     100,   120,   120,    50,   120,    82,    36,   120,   120,    49,
      36,    54,    50,    53,    76,    78,    25,    92,    94,   120,
     120,    53,   120,    75,   120,     3,    95,   101,   102,   120,
     120,   100,    88,   120,    77,    78,    54,    40,    26,    91,
      93,    94,   120,   120,    77,   120,   120,   120,   120,    40,
     120,   120,    50,    50,   120,    54,    77,    22,    84,    78,
     120,    54,    93,    36,    53,    54,    49,   120,    78,   120,
     100,    23,    85,    78,    50,    53,   120,    53,   120,    54,
     120,    78,    78,   120,   120,    54,    54,    84
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    66,    66,    66,    67,    67,    68,    68,    68,
      69,    69,    70,    70,    71,    71,    71,    71,    71,    72,
      73,    73,    74,    74,    75,    75,    76,    77,    77,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    79,    80,    81,    81,    82,    82,    83,
      84,    84,    85,    85,    86,    87,    88,    88,    89,    89,
      90,    91,    91,    92,    93,    93,    94,    95,    95,    95,
      96,    97,    98,    99,    99,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   101,   102,   103,   104,   105,
     105,   106,   106,   106,   106,   107,   108,   109,   110,   111,
     111,   112,   112,   112,   112,   112,   112,   113,   113,   113,
     113,   113,   113,   114,   114,   114,   115,   115,   116,   116,
     116,   116,   116,   116,   117,   118,   119,   119,   120,   120
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     3,     8,     7,     0,     3,     3,
       1,     3,     3,     5,     2,     3,     3,     2,     1,     1,
      13,    12,     0,     2,     0,     4,     2,     0,     3,     0,
       3,     3,     3,     3,     3,     3,     3,     3,     4,     4,
       3,     3,     4,     4,     7,     0,     2,     0,     4,    15,
       0,    10,     0,     6,    13,    17,     0,     1,     0,     1,
      13,     0,     4,     3,     0,     3,     5,     1,     1,     1,
       3,     2,     6,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     8,     4,     2,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     2
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
  case 12: /* assignment_list: ID ASSIGN expression  */
#line 104 "project.y"
                                      {
        insert((yyvsp[-2].sval), 0);
    }
#line 1483 "project.tab.c"
    break;

  case 13: /* assignment_list: ID ASSIGN expression COMMA assignment_list  */
#line 107 "project.y"
                                                 {
        insert((yyvsp[-4].sval), 0);
    }
#line 1491 "project.tab.c"
    break;

  case 14: /* variable_declaration: data_type identifier_list  */
#line 112 "project.y"
                                                {
        insert((yyvsp[0].sval), 0, (yyvsp[-1].ival));
    }
#line 1499 "project.tab.c"
    break;

  case 15: /* variable_declaration: access_modifier data_type identifier_list  */
#line 115 "project.y"
                                                {
        insert((yyvsp[0].sval), 0, (yyvsp[-1].ival));
    }
#line 1507 "project.tab.c"
    break;

  case 19: /* variable_reference: ID  */
#line 123 "project.y"
                       {
    symbol *sym = lookup((yyvsp[0].sval));
    if (!sym || sym->type != 0) {  // 0 for variable
        yyerror("Variable not declared");
        YYERROR;
    }
}
#line 1519 "project.tab.c"
    break;

  case 20: /* method_declaration: access_modifier data_type ID LP none_or_newlines none_or_multiple_parameters none_or_newlines RP LCB none_or_newlines method_body none_or_newlines RCB  */
#line 131 "project.y"
                                                                                                                                                                           {
        insert((yyvsp[-10].sval), 1);
    }
#line 1527 "project.tab.c"
    break;

  case 21: /* method_declaration: data_type ID LP none_or_newlines none_or_multiple_parameters none_or_newlines RP LCB none_or_newlines method_body none_or_newlines RCB  */
#line 134 "project.y"
                                                                                                                                             {
        insert((yyvsp[-10].sval), 1);
    }
#line 1535 "project.tab.c"
    break;

  case 43: /* assignment_statement: data_type ID ASSIGN expression  */
#line 170 "project.y"
                                                     {
        symbol *sym = lookup((yyvsp[-2].sval));
        if (!sym) {
            yyerror("Variable not declared");
            YYERROR;
        }
        if (sym->data_type != (yyvsp[-3].ival)) {
            yyerror("Data type mismatch");
            YYERROR;
        }
    }
#line 1551 "project.tab.c"
    break;

  case 44: /* method_call: ID LP none_or_newlines none_or_multiple_arguments none_or_newlines RP SEMICOLON  */
#line 183 "project.y"
                                                                                             {
        symbol *sym = lookup((yyvsp[-6].sval));
        if (!sym || sym->type != 1) {  // 1 for method
            yyerror("Method not declared");
            YYERROR;
        }
    }
#line 1563 "project.tab.c"
    break;

  case 75: /* expression: integer_expression  */
#line 260 "project.y"
                               { (yyval.ival) = INTEGER_TYPE; }
#line 1569 "project.tab.c"
    break;

  case 76: /* expression: any_character  */
#line 261 "project.y"
                    { (yyval.ival) = CHAR_TYPE; }
#line 1575 "project.tab.c"
    break;

  case 77: /* expression: double_expression  */
#line 262 "project.y"
                        { (yyval.ival) = DOUBLE_TYPE; }
#line 1581 "project.tab.c"
    break;

  case 78: /* expression: boolean_expression  */
#line 263 "project.y"
                         { (yyval.ival) = BOOLEAN_TYPE; }
#line 1587 "project.tab.c"
    break;

  case 79: /* expression: text  */
#line 264 "project.y"
           { (yyval.ival) = STRING_TYPE; }
#line 1593 "project.tab.c"
    break;

  case 80: /* expression: variable_reference  */
#line 265 "project.y"
                         { (yyval.ival) = lookup((yyvsp[0].ival))->data_type; }
#line 1599 "project.tab.c"
    break;

  case 81: /* expression: method_call  */
#line 266 "project.y"
                  { (yyval.ival) = lookup((yyvsp[0].ival))->data_type; }
#line 1605 "project.tab.c"
    break;

  case 82: /* expression: operations  */
#line 267 "project.y"
                 { (yyval.ival) = (yyvsp[0].ival); }
#line 1611 "project.tab.c"
    break;

  case 83: /* expression: member_access  */
#line 268 "project.y"
                    { (yyval.ival) = (yyvsp[0].ival); }
#line 1617 "project.tab.c"
    break;

  case 84: /* expression: LP expression RP  */
#line 269 "project.y"
                       { (yyval.ival) = (yyvsp[-1].ival); }
#line 1623 "project.tab.c"
    break;

  case 118: /* data_type: INTEGER  */
#line 335 "project.y"
                   { (yyval.ival) = INTEGER_TYPE; }
#line 1629 "project.tab.c"
    break;

  case 119: /* data_type: CHAR  */
#line 336 "project.y"
           { (yyval.ival) = CHAR_TYPE; }
#line 1635 "project.tab.c"
    break;

  case 120: /* data_type: DOUBLE  */
#line 337 "project.y"
             { (yyval.ival) = DOUBLE_TYPE; }
#line 1641 "project.tab.c"
    break;

  case 121: /* data_type: BOOLEAN  */
#line 338 "project.y"
              { (yyval.ival) = BOOLEAN_TYPE; }
#line 1647 "project.tab.c"
    break;

  case 122: /* data_type: STRING  */
#line 339 "project.y"
             { (yyval.ival) = STRING_TYPE; }
#line 1653 "project.tab.c"
    break;

  case 123: /* data_type: VOID  */
#line 340 "project.y"
           { (yyval.ival) = VOID_TYPE; }
#line 1659 "project.tab.c"
    break;


#line 1663 "project.tab.c"

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

#line 360 "project.y"


symbol* lookup(char *name) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i]->name, name) == 0) {
            return symbol_table[i];
        }
    }
    return NULL;
}

void insert(char *name, int type) {
    symbol *sym = malloc(sizeof(symbol));
    sym->name = strdup(name);
    sym->type = type;
    sym->data_type = data_type;
    symbol_table[symbol_count++] = sym;
}

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
