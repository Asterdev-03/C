%{
#include <stdio.h>
int word=0,line=0,ch=0;
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
printf("character count:%d\n",ch);
printf("word count:%d\n",word);
printf("line count:%d\n",line);
}
