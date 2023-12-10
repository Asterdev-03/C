%{
#include<stdio.h>
#include<stdlib.h>
char p='A';
%}

%union {char dval;}
%token NUM
%left '+''-'
%left '*''/'
%type <dval> S
%type <dval> E
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
printf("Expression is valid\n");
return 0;
}
int yyerror()
{
printf("Expression is invalid \n");
exit(0);
}
