#include<stdio.h>

double soma(double a, double b), subtracao(double a, double b), multiplicacao(double a, double b), divisao(double a, double b), modulo(double a), fatorial(double a), exponencial(double a, double b), seno(double a);

double soma(double a, double b) {
    return a + b;
}

double subtracao(double a, double b) {
    return a - b;
}

double multiplicacao(double a, double b) {
    return a * b;
}

double divisao(double a, double b) {
    return a / b;
}

double modulo(double a) {
    if (a < 0) {
        return -a;
    } else {
        return a;
    }
}

double fatorial(double a) {
    int fat = 1;
    for(int i = a; i > 0; i--) {
        fat *= i;
    }
    return fat;
}

double exponencial(double a, double b) {
    double exp = 1;
    if (b != 0) {

        for(int i = 0; i < b; i++) {
            exp *= a;
        }

    } 
    return exp;
}

double seno(double a) {
    int soma = 0;

    for(int j = 0; j < 20; j++) {
        double i = (double) j;
        soma += exponencial(-1.0, i) * exponencial(a,  2.0 * i + 1) / fatorial(2.0 * i + 1);
    }

    return soma;
}

int main() {

    double x, y, resultado;
    char operacao;

    scanf("%c", &operacao);

    switch (operacao) {
        case '+':
                scanf("%lf %lf", &x, &y); 
                resultado = soma(x, y);
                break;
        case '-':
                scanf("%lf %lf", &x, &y);
                resultado = subtracao(x, y);
                break;
        case '*':
                scanf("%lf %lf", &x, &y);
                resultado = multiplicacao(x, y);
                break;
        case '/':
                scanf("%lf %lf", &x, &y);
                resultado = divisao(x, y);
                break;
        case 'm':
                scanf("%lf", &x);
                resultado = modulo(x);
                break;
        case 'f':
                scanf("%lf", &x);
                resultado = fatorial(x);
                break;
        case 'e':
                scanf("%lf %lf", &x, &y);
                resultado = exponencial(x, y);
                break;
        case 's':
                scanf("%lf", &x);
                resultado = seno(x);
                break;
        default:
                break;
    }

    printf("%.2f", resultado);
    return 0;
}