%{
#include <stdio.h>
int word=0;
int line=0,ch=0;
%}

%%
[a-zA-Z0-9] {ch++;}
" " {word++;}
"\n" {line++; word++;}
. {}
%%
int main(){
yyin=fopen("input.txt","r");
yylex();
printf("line count:%d\n",line);
printf("word count:%d\n",word);
}
