%{
#include <stdio.h>
%}
%token NUMBER ID;
%left '+''-'
%left '*''/'
%%

E: T {printf("result=%d\n",$$);return 0;}
T: T'+'T {$$=$1+$3;}
|T'-'T {$$=$1-$3;}
|T'*'T {$$=$1*$3;}
|T'/'T {$$=$1/$3;}
|'-'NUMBER {$$=-$2;}
|'('T')' {$$=$2;}
|NUMBER {$$=$1;};
%%
int yyerror()
{
printf("\nInput correct format for the calculaor\n");
}
int main()
{
printf("\nEnter the expression:\n");
yyparse();
}
