%{
#include <stdio.h>
#include "tokens.h"
%}

%%
[0-9]*                      |
[0-9]*\.[0-9]*              {return 1;}
[A-Z|a-z]*                  {return 2;}

%%
int main(int argc, char **argv){
    int val;
    while (val==yylex())
        printf("Value is %d\n", val);
    return 0;
}