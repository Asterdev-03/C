%{
#include<stdio.h>
%}
%%
[ \n\t] {printf("");}
%%
void main()
{
yyin=fopen("input.txt","r")
yylex();
}
