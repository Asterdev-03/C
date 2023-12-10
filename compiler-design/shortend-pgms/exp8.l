%{
#include "y.tab.h"
int yylval;
%}
%%
[0-9]+ {
yylval=atoi(yytext);
return NUMBER;
}
[a-zA-Z]+ return ID;
\n return 0;
. return yytext[0];
%%

