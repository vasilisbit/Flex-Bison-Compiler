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
    DOUBLE_CONST = 261,            /* DOUBLE_CONST  */
    SQ_ANYCHAR_SQ = 262,           /* SQ_ANYCHAR_SQ  */
    DQ_STRING_DQ = 263,            /* DQ_STRING_DQ  */
    VAR = 264,                     /* VAR  */
    NEWLINE = 265,                 /* NEWLINE  */
    CLASS = 266,                   /* CLASS  */
    PUBLIC = 267,                  /* PUBLIC  */
    PRIVATE = 268,                 /* PRIVATE  */
    INTEGER = 269,                 /* INTEGER  */
    CHAR = 270,                    /* CHAR  */
    DOUBLE = 271,                  /* DOUBLE  */
    BOOLEAN = 272,                 /* BOOLEAN  */
    STRING = 273,                  /* STRING  */
    VOID = 274,                    /* VOID  */
    NEW = 275,                     /* NEW  */
    RETURN = 276,                  /* RETURN  */
    IF = 277,                      /* IF  */
    ELIF = 278,                    /* ELIF  */
    ELSE = 279,                    /* ELSE  */
    SWITCH = 280,                  /* SWITCH  */
    CASE = 281,                    /* CASE  */
    DEFAULT = 282,                 /* DEFAULT  */
    WHILE = 283,                   /* WHILE  */
    DO = 284,                      /* DO  */
    FOR = 285,                     /* FOR  */
    BREAK = 286,                   /* BREAK  */
    TRUE = 287,                    /* TRUE  */
    FALSE = 288,                   /* FALSE  */
    PRINT = 289,                   /* PRINT  */
    SEMICOLON = 290,               /* SEMICOLON  */
    COMMA = 291,                   /* COMMA  */
    DOT = 292,                     /* DOT  */
    COLON = 293,                   /* COLON  */
    LP = 294,                      /* LP  */
    RP = 295,                      /* RP  */
    LCB = 296,                     /* LCB  */
    RCB = 297,                     /* RCB  */
    ASSIGN = 298,                  /* ASSIGN  */
    OR = 299,                      /* OR  */
    AND = 300,                     /* AND  */
    EQ = 301,                      /* EQ  */
    NEQ = 302,                     /* NEQ  */
    LT = 303,                      /* LT  */
    LE = 304,                      /* LE  */
    GT = 305,                      /* GT  */
    GE = 306,                      /* GE  */
    ADD = 307,                     /* ADD  */
    SUB = 308,                     /* SUB  */
    MUL = 309,                     /* MUL  */
    DIV = 310,                     /* DIV  */
    MOD = 311,                     /* MOD  */
    POW = 312,                     /* POW  */
    NOT = 313                      /* NOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 156 "project.y"

    int    ival;
    char   *cval;
    char   *sval;
    double dval;

#line 129 "project.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PROJECT_TAB_H_INCLUDED  */
