%{

FILE *fp;

FILE *fp1;

%}

%%

[a-z] fprintf(fp1,"%c",toupper(yytext[0]));

. fprintf(fp1,"%C",yytext[0]);

%%

int main(int args,char **argv)

{

fp1=fopen("b.txt","w");

if(!fp1)

{

printf("file not exists\n");

return(0);

}

fp=fopen("a.txt","r");

if(!fp)

{

printf("file not exists\n");

return(0);

}

yyin=fp1;
yyin=fp;

yylex();

return(0);

}

