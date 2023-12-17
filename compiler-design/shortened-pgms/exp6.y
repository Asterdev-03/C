%{
#include <stdio.h>
#include <stdlib.h>
%}
%token num id op
%%

start: id'='s';'
s: '-'id x|id x|num x|'-'num x|'('s')'x
x: op s|'-'s|
%%

int yyerror()
{
printf("\nInvalid expr\n");
exit(0);
}
int main()
{
printf("Enter expr: ");
yyparse();
printf("Valid expr\n");
}
