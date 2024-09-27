#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUM 256
#define ID 257
int tokenval;
int token;


int analex(){
    char ch;


    ch = getchar();


    while (isspace(ch)) {
        ch = getchar();
    }


    if(ch == '+')
        return '+';

    if(ch == '-')
        return '-';

    if(ch == '*')
        return '*';

    if(ch == '/')
        return '/';

    if(ch == ';')
        return ';';

    if(ch == '(')
        return '(';

    if(ch == ')')
        return ')';

    if(isdigit(ch)){
        tokenval = 0;
        do {
            tokenval = tokenval * 10 + (ch - '0');
            ch = getchar();
        } while(isdigit(ch));
        ungetc(ch, stdin);
        return NUM;
    }

    printf("ERRO LÉXICO !!!\n");
    exit(1);
}
