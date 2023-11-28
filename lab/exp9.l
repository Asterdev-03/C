%{
FILE *fp;
FILE *fp1;
%}
%%
[a-z] fprintf(fp1,"%c",toupper(yytext[0]));
. fprintf(fp1,"%C",yytext[0]);
%%
int main()
{
fp1=fopen("b.txt","w");
fp=fopen("a.txt","r");
yyin=fp;
yylex();
}
