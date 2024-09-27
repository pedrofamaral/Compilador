#include "analex-2.h"
#include "pilha.h"

#define ID 257

int token;
int resultado;

void E();
void E_linha();
void T();
void T_linha();
void F();
void erro_sint(){
    printf("ERRO SINTATICO!!\n");
    exit(1);
}

void consome(int t){
    if (token == t)
        token = analex();
    else
        erro_sint();
}

void E(){
    T();
    E_linha();
}

void E_linha(){
    int a, b;
    switch(token){
        case '+':
            consome('+');
            T();
            b = pop();
            a = pop();
            push(a + b);
            printf("+ ");
            E_linha();
            break;
        case '-':
            consome('-');
            T();
            b = pop();
            a = pop();
            push(a - b);
            printf("- ");
            E_linha();
            break;
    }
}

void T(){
    F();
    T_linha();
}

void T_linha(){
    int a, b;
    switch(token){
        case '*':
            consome('*');
            F();
            b = pop();
            a = pop();
            push(a * b);
            printf("* ");
            T_linha();
            break;
        case '/':
            consome('/');
            F();
            b = pop();
            a = pop();
            push(a / b);
            printf("/ ");
            T_linha();
            break;
    }
}

void F(){
    switch(token){
        case '(':
            consome('(');
            E();
            consome(')');
            break;
        case NUM:
            printf("%d ", tokenval);
            push(tokenval);
            consome(NUM);
            break;
        case ID:
            printf("%d ", tokenval);
            push(tokenval);
            consome(ID);
            break;
        default:
            erro_sint();
    }
}

int main(){
    token = analex();
    E();

    if(token == ';') {
        resultado = pop();
        printf("\nResultado: %d\n", resultado);
        printf("NAO TEM ERROS SINTATICOS!!\n");
    } else
        erro_sint();

    return 0;
}
