%{
#include <stdio.h>
int valid=1;
%}
%token digit letter
%%
start : letter s
s: letter s| digit s|;
%%
int yyerror()
{
	printf("\nIts not an identifier\n");
	valid=0;
	return 0;
}
int main(){
	printf("\nEnter a name to be tested for identifier\n");
	yyparse();
	if(valid) 
	{
		printf("It is an identifier\n");
	}
} 
	
