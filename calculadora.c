#include<stdio.h>

double soma(double a, double b), subtracao(double a, double b), multiplicacao(double a, double b), divisao(double a, double b), modulo(double a), fatorial(double a), seno(double a);

double soma(double a, double b) {
    scanf("%lf %lf", &a, &b);
    return a + b;
}

double subtracao(double a, double b) {
    scanf("%lf %lf", &a, &b);
    return a - b;
}

double multiplicacao(double a, double b) {
    scanf("%lf %lf", &a, &b);
    return a * b;
}

double divisao(double a, double b) {
    scanf("%lf %lf", &a, &b);
    return a / b;
}

double modulo(double a) {
    scanf("%lf", &a);
    if (a < 0) {
        return -a;
    } else {
        return a;
    }
}

double fatorial(double a) {
    scanf("%lf", &a);
    int fat = 1;
    for(int i = a; i > 0; i--) {
        fat *= i;
    }
    return fat;
}

double exponencial(double a, double b) {
    scanf("%lf %lf", &a, &b);
    double exp = 1;
    if (b != 0) {
        for(int i = 0; i < b; i++) {
            exp *= a;
        }
    } 
    return exp;
}

int main() {

    double x, y, resultado;
    char operacao;

    scanf("%c", &operacao);

    switch (operacao) {
        case '+': 
                resultado = soma(x, y);
                break;
        case '-':
                resultado = subtracao(x, y);
                break;
        case '*':
                resultado = multiplicacao(x, y);
                break;
        case '/':
                resultado = divisao(x, y);
                break;
        case 'm':
                resultado = modulo(x);
                break;
        case 'f':
                resultado = fatorial(x);
                break;
        case 'e':
                resultado = exponencial(x, y);
                break;
        default:
                break;
    }

    printf("%.2f", resultado);
    return 0;
}