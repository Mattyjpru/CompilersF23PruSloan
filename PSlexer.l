%{
#include <stdio.h>
#include "yourmain.h"
%}

%%
[0-9]*                      |
[0-9]*\.[0-9]*              |
[A-Z|a-z]*                  |




%%
int main(int argc, char *argv){
    int val;
    while (val==yylex())
        printf("Value is %d\n", val)
    return 0;
}