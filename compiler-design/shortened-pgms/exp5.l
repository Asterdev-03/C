%{
%}
identifier [a-zA-Z][a-zA-Z0-9]*
%%

#.* {printf("\n%s is a preprocessor directive", yytext);}
int|float|char|double|while|for|if|break|continue|void|return|else {printf("\n%s is a keyword", yytext);}

{identifier}\( {printf("\nFunction %s", yytext);}
"{" {printf("BLOCK BEGINS");}
"}" {printf("BLOCK ENDS ");}

{identifier}(\[[0-9]*\])? {printf("\n%s is an IDENTIFIER", yytext);}
\".*\" {printf("\n%s is a STRING", yytext);}
[0-9]+ {printf("\n%s is a CONSTANT", yytext);}

"/"|"+"|"-"|"*" {printf("\n%s is an ARITHMETIC OPERATOR", yytext);}
"=" {printf("\n%s is an ASSIGNMENT OPERATOR",yytext);}
"<="|">="|"<"|"=="|">" {printf("\n%s is a RELATIONAL OPERATOR",yytext);}

%%

int main(){
yyin=fopen("program.txt","r");
yylex();
}
