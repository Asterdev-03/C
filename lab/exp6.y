%{
#include <stdio.h>
int valid=1;
%}
%token num id op
%%
start: id'='s';'
s: '-' id x|id x|num x|'-'num x|'('s')'x;
x:op s|'-'s|
%%
int yyerror()
{
valid=0;
printf("\nInvalid expr\n");
return 0;
}
int main()
{
printf("Enter expr: ");
yyparse();
if(valid) 
{
printf("Valid expr\n");
}
}
