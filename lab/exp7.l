%{
#include "y.tab.h"
%}
%%
[a-zA-Z_] return letter;
[0-9] return digit;
.	return yytext[0];
%%
