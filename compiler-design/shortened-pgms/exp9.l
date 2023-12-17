%{
%}
%%

[a-z] printf("%c",toupper(yytext[0]));
. printf("%c",yytext[0]);
%%

int main()
{
yyin=fopen("input.txt","r");
yylex();
}
