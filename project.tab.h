/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PROJECT_TAB_H_INCLUDED
# define YY_YY_PROJECT_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    CONST = 258,                   /* CONST  */
    ID = 259,                      /* ID  */
    CLASS_ID = 260,                /* CLASS_ID  */
    ANY_CHARACTER = 261,           /* ANY_CHARACTER  */
    DOUBLE_CONST = 262,            /* DOUBLE_CONST  */
    VAR = 263,                     /* VAR  */
    NEWLINE = 264,                 /* NEWLINE  */
    CLASS = 265,                   /* CLASS  */
    PUBLIC = 266,                  /* PUBLIC  */
    PRIVATE = 267,                 /* PRIVATE  */
    INTEGER = 268,                 /* INTEGER  */
    CHAR = 269,                    /* CHAR  */
    DOUBLE = 270,                  /* DOUBLE  */
    BOOLEAN = 271,                 /* BOOLEAN  */
    STRING = 272,                  /* STRING  */
    VOID = 273,                    /* VOID  */
    NEW = 274,                     /* NEW  */
    RETURN = 275,                  /* RETURN  */
    IF = 276,                      /* IF  */
    ELIF = 277,                    /* ELIF  */
    ELSE = 278,                    /* ELSE  */
    SWITCH = 279,                  /* SWITCH  */
    CASE = 280,                    /* CASE  */
    DEFAULT = 281,                 /* DEFAULT  */
    WHILE = 282,                   /* WHILE  */
    DO = 283,                      /* DO  */
    FOR = 284,                     /* FOR  */
    BREAK = 285,                   /* BREAK  */
    TRUE = 286,                    /* TRUE  */
    FALSE = 287,                   /* FALSE  */
    PRINT = 288,                   /* PRINT  */
    SQ_ANYCHAR_SQ = 289,           /* SQ_ANYCHAR_SQ  */
    DQ_STRING_DQ = 290,            /* DQ_STRING_DQ  */
    SEMICOLON = 291,               /* SEMICOLON  */
    COMMA = 292,                   /* COMMA  */
    DOT = 293,                     /* DOT  */
    QUESTION = 294,                /* QUESTION  */
    COLON = 295,                   /* COLON  */
    DQ = 296,                      /* DQ  */
    SQ = 297,                      /* SQ  */
    ADD = 298,                     /* ADD  */
    SUB = 299,                     /* SUB  */
    MUL = 300,                     /* MUL  */
    DIV = 301,                     /* DIV  */
    MOD = 302,                     /* MOD  */
    POW = 303,                     /* POW  */
    LP = 304,                      /* LP  */
    RP = 305,                      /* RP  */
    LSB = 306,                     /* LSB  */
    RSB = 307,                     /* RSB  */
    LCB = 308,                     /* LCB  */
    RCB = 309,                     /* RCB  */
    ASSIGN = 310,                  /* ASSIGN  */
    EQ = 311,                      /* EQ  */
    NEQ = 312,                     /* NEQ  */
    LT = 313,                      /* LT  */
    GT = 314,                      /* GT  */
    LE = 315,                      /* LE  */
    GE = 316,                      /* GE  */
    AND = 317,                     /* AND  */
    OR = 318,                      /* OR  */
    NOT = 319                      /* NOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "project.y"

    int    ival;
    char   *cval;
    char   *sval;
    double dval;

#line 135 "project.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PROJECT_TAB_H_INCLUDED  */
