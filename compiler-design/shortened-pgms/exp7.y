%{
#include <stdio.h>
%}
%token digit letter
%%

start : letter s
s: letter s| digit s|;
%%

int yyerror()
{
printf("\nIts not an identifier\n");
exit(0);
}
int main(){
printf("\nEnter a name to be tested for identifier\n");
yyparse();
printf("It is an identifier\n");
} 
	
