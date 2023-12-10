%{
FILE *fp;
%}
%%

[a-z] fprintf(fp,"%c",toupper(yytext[0]));
. fprintf(fp,"%c",yytext[0]);
%%

int main()
{
fp=fopen("b.txt","w");
yyin=fopen("a.txt","r");
yylex();
}
