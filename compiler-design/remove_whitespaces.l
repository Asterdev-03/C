%{
#include<stdio.h>
%}
%%
[ \n\t] {printf("");}
%%
void main(int argc,char*argv[])
{
yyin=fopen(argv[1],"r")
yylex();}
