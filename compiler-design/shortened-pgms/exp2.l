%{
#include <stdio.h>
int vowels=0,consonants=0;
%}

%%

[aeiouAEIOU] {vowels++;}
[a-zA-Z] {consonants++;}
. {}

%%

int main(){
yyin=fopen("input.txt","r");
yylex();
printf("vowels=%d",vowels);
printf("consonants=%d",consonants);
}
