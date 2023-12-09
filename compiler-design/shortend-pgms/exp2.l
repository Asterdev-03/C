%{
#include <stdio.h>
int v=0,c=0;
%}

%%

[aeiouAEIOU] {v++;}
[a-zA-Z] {c++;}
. {}

%%

int main(){
yyin=fopen("input.txt","r");
yylex();
printf("vowel=%d",v);
}
