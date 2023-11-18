%{

#include"y.tab.h"

%}

%%

[0-9]+ {yylval.dval=(*yytext);return NUM;}

\n return 0;

. return yytext[0];

%%
