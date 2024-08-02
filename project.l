%{
#include "project.tab.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#define YYLTYPE int
%}

%option yylineno

id [A-Za-z_][A-Za-z0-9_]*
class_ID [A-Z_][A-Za-z0-9_]*
const [0-9]+
any_character [A-Za-z0-9_!@#\$%\^&\*\(\)-+=\|\\:;\"'<>,\.\?/~`\[\]\{\} ]

%x COMMENT

%%

"/*" { BEGIN COMMENT; }
<COMMENT>"\r\n" { yylineno; }
<COMMENT>[^*\r\n] { }
<COMMENT>"*/" { BEGIN(INITIAL); }
<COMMENT><<EOF>> {
    printf("Error: Unterminated comment\n");
    exit(1);
}
"//".*"\r\n" { /* Ignore single line comment */ }

"\r\n" { return NEWLINE; }
"\t" { /* return TAB; */ }
" " { /* return SPACEBAR; */ }

";" { return SEMICOLON; }
"," { return COMMA; }
"." { return DOT; }
"(" { return LP; }
")" { return RP; }
"[" { return LSB; }
"]" { return RSB; }
"{" { return LCB; }
"}" { return RCB; }
"?" { return QUESTION; }
":" { return COLON; }
"\"" { return DQ; }
"\'" { return SQ; }

"+" { return ADD; }
"-" { return SUB; }
"*" { return MUL; }
"^" { return POW; }
"/" { return DIV; }
"%" { return MOD; }

"=" { return ASSIGN; }
"==" { return EQ; }
"!=" { return NEQ; }
"<" {return LT; }
"<=" { return LE; }
">" { return GT; }
">=" {return GE; }

"&&" { return AND; }
"||" { return OR; }
"!" { return NOT; }

"class" { return CLASS; }
"var" { return VAR; }
"int" { return INTEGER; }
"char" { return CHAR; }
"double" { return DOUBLE; }
"boolean" { return BOOLEAN; }
"String" { return STRING; }
"new" { return NEW; }
"return" { return RETURN; }
"void" {return VOID; }
"if" { return IF; }
"else" { return ELSE; }
"else if" { return ELIF; }
"while" { return WHILE; }
"do" { return DO; }
"for" { return FOR; }
"switch" { return SWITCH; }
"case" { return CASE; }
"default" { return DEFAULT; }
"break" { return BREAK; }
"true" { return TRUE; }
"false" { return FALSE; }
"public" { return PUBLIC; }
"private" { return PRIVATE; }
"out.print" { return PRINT; }

[0-9]+\.[0-9]+[d] { yylval.dval = atof(yytext); return DOUBLE_CONST; }
"\'"[^'\n]"\'" { yylval.sval = strdup(yytext); return SQ_ANYCHAR_SQ; }
"\""[^"\n]*"\"" { yylval.sval = strdup(yytext); return DQ_STRING_DQ; }
{class_ID} { yylval.sval = strdup(yytext); return CLASS_ID; }
{id} { yylval.sval = strdup(yytext); return ID; }
{const} { yylval.ival = atoi(yytext); return CONST; }
{any_character} { yylval.cval = strdup(yytext); return ANY_CHARACTER; }
. { fprintf(stderr, "Error at line %d: Unexpected character '%s'\n", yylineno, yytext); }
%%