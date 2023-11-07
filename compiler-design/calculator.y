
%{
#include <stdio.h>
%}
%token NUMBER ID;
%left '+''-'
%left '*''/'
%%
E:T{
printf("result=%d\n",$$);
return 0;
}
T:
T'+'T {$$=$1+$3;}
|T'-'T {$$=$1-$3;}
|T'*'T {$$=$1*$3;}
|T'/'T {$$=$1/$3;}
|'-'NUMBER {$$=-$2;}
|'-'ID {$$=-$2;}
|'('T')' {$$=$2;}
|ID {$$=$1;}
|NUMBER {$$=$1;};
%%
int main()
{
printf("\nEnter the expression:\n");
yyparse();
}
int yyerror(char *s)
{
printf("\nIt is not an identifier\n");
return 0;
}
