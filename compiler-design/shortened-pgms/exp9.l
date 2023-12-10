%{
FILE *fp;
%}
%%

[a-z] fprintf(fp,"%c",toupper(yytext[0]));
. fprintf(fp,"%c",yytext[0]);
%%

int main()
{
fp=fopen("output.txt","w");
yyin=fopen("input.txt","r");
yylex();
}
