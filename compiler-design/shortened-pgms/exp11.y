%{
#include<stdio.h>
char p='A';
%}

%token NUM
%left '+''-'
%left '*''/'
%%

S:E {printf("X=%c\n",$$);}
E:NUM {}
|E'+'E {printf("%c=%c+%c\n",p,$1,$3);$$=p;p++;}
|E'-'E {printf("%c=%c-%c\n",p,$1,$3);$$=p;p++;} 
|E'*'E {printf("%c=%c*%c\n",p,$1,$3);$$=p;p++;} 
|E'/'E {printf("%c=%c/%c\n",p,$1,$3);$$=p;p++;}

%%
int main()
{
printf("Enter the expression : ");
yyparse();
}
int yyerror()
{
printf("Expression is invalid \n");
}
