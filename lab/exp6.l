%{
#include "y.tab.h"
%}
%%
[a-zA-z_][a-zA-Z_0-9]* return id;
[0-9]+(\.[0-9]*)? return num;
[+/*] return op;
. return yytext[0];
%%
