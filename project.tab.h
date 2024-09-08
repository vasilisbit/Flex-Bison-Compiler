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
    METHOD_ID = 261,               /* METHOD_ID  */
    DOUBLE_CONST = 262,            /* DOUBLE_CONST  */
    SQ_ANYCHAR_SQ = 263,           /* SQ_ANYCHAR_SQ  */
    DQ_STRING_DQ = 264,            /* DQ_STRING_DQ  */
    VAR = 265,                     /* VAR  */
    NEWLINE = 266,                 /* NEWLINE  */
    CLASS = 267,                   /* CLASS  */
    PUBLIC = 268,                  /* PUBLIC  */
    PRIVATE = 269,                 /* PRIVATE  */
    INTEGER = 270,                 /* INTEGER  */
    CHAR = 271,                    /* CHAR  */
    DOUBLE = 272,                  /* DOUBLE  */
    BOOLEAN = 273,                 /* BOOLEAN  */
    STRING = 274,                  /* STRING  */
    VOID = 275,                    /* VOID  */
    NEW = 276,                     /* NEW  */
    RETURN = 277,                  /* RETURN  */
    IF = 278,                      /* IF  */
    ELIF = 279,                    /* ELIF  */
    ELSE = 280,                    /* ELSE  */
    SWITCH = 281,                  /* SWITCH  */
    CASE = 282,                    /* CASE  */
    DEFAULT = 283,                 /* DEFAULT  */
    WHILE = 284,                   /* WHILE  */
    DO = 285,                      /* DO  */
    FOR = 286,                     /* FOR  */
    BREAK = 287,                   /* BREAK  */
    TRUE = 288,                    /* TRUE  */
    FALSE = 289,                   /* FALSE  */
    PRINT = 290,                   /* PRINT  */
    SEMICOLON = 291,               /* SEMICOLON  */
    COMMA = 292,                   /* COMMA  */
    DOT = 293,                     /* DOT  */
    COLON = 294,                   /* COLON  */
    LP = 295,                      /* LP  */
    RP = 296,                      /* RP  */
    LCB = 297,                     /* LCB  */
    RCB = 298,                     /* RCB  */
    ASSIGN = 299,                  /* ASSIGN  */
    OR = 300,                      /* OR  */
    AND = 301,                     /* AND  */
    EQ = 302,                      /* EQ  */
    NEQ = 303,                     /* NEQ  */
    LT = 304,                      /* LT  */
    LE = 305,                      /* LE  */
    GT = 306,                      /* GT  */
    GE = 307,                      /* GE  */
    ADD = 308,                     /* ADD  */
    SUB = 309,                     /* SUB  */
    MUL = 310,                     /* MUL  */
    DIV = 311,                     /* DIV  */
    MOD = 312,                     /* MOD  */
    POW = 313,                     /* POW  */
    NOT = 314                      /* NOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 295 "project.y"

    int    ival;
    char   *cval;
    char   *sval;
    double dval;

#line 130 "project.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PROJECT_TAB_H_INCLUDED  */
