%{
#include "project.tab.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "error.h"
#define YYLTYPE int
%}

%option yylineno

id [A-Za-z_][A-Za-z0-9_]*
methodID [A-Za-z_][A-Za-z0-9_]*[(]
class_ID [A-Z_][A-Za-z0-9_]*
const [0-9]+

%x COMMENT

%%

"/*" { BEGIN COMMENT; }
<COMMENT>"\r\n" { yylineno; }
<COMMENT>[^*\r\n] { }
<COMMENT>"*/" { BEGIN(INITIAL); }
<COMMENT><<EOF>> {
    addError(yylineno, "Unterminated comment", "/*");
    yyterminate(); // Terminate the lexer to stop further processing
}
"//".* { yylineno++; }

"\r\n" { return NEWLINE; }
"\t" { /* return TAB; */ }
" " { /* return SPACEBAR; */ }

";" { return SEMICOLON; }
"," { return COMMA; }
"." { return DOT; }
"(" { return LP; }
")" { return RP; }
"{" { return LCB; }
"}" { return RCB; }
":" { return COLON; }

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

[0-9]+\.[0-9]+[d] { yytext[yyleng - 1] = '\0'; yylval.dval = atof(yytext); return DOUBLE_CONST; }
"\'"[^'\n]"\'" { yylval.sval = strdup(yytext); return SQ_ANYCHAR_SQ; }
"\'"[^'\n]*"\'" { addError(yylineno, "Invalid character literal", yytext); }
"\""[^"\n]*"\"" { yylval.sval = strdup(yytext); return DQ_STRING_DQ; }
"\""[^"\n]* { addError(yylineno, "Unterminated string", yytext); }
{class_ID} { yylval.sval = strdup(yytext); return CLASS_ID; }
{id} { yylval.sval = strdup(yytext); return ID; }
{methodID} { yylval.sval = strdup(yytext); return METHOD_ID; }
{const} { yylval.ival = atoi(yytext); return CONST; }
. { addError(yylineno, "Unexpected character", yytext); }

%%

int yywrap(){
    return 1;
}