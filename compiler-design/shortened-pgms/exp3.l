%{
#include <stdio.h>
%}

%%
[ \n\t] {printf("");}
. {printf("%s",yytext);}
%%

void main()
{
yyin=fopen("input.txt","r");
yylex();
}
