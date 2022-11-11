#include<stdio.h>

double serie = 0;
double soma(double a, double b), subtracao(double a, double b), multiplicacao(double a, double b), divisao(double a, double b), modulo(double a), fatorial(double a), exponencial(double a, double b), seno(double a), cosseno(double a), tangente(double a), exponencialNatural(double a), logNatural(double a), log(double a, double b), raiz(double a, double b);

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
    double fat = 1.0;
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

    for(int i = 0; i < 20; i++) {
        serie += (exponencial(-1.0, i) / fatorial(2.0 * i + 1)) * exponencial(a,  2.0 * i + 1) ;
    }

    return serie;
}

double cosseno(double a) {

    for(int i = 0; i < 20; i++) {
        serie += (exponencial(-1, i) / fatorial(2 * i)) * exponencial(a, 2 * i);
    }

    return serie;
}

double tangente(double a) {
    return seno(a) / cosseno(a);
}

double exponencialNatural(double a) {

        for(int i = 0; i < 20; i++) {
            serie += exponencial(a, i) / fatorial(i);
        }

    return serie;
}

double logNatural(double a) {
    if (a > 0) {
        for(int i = 0; i < 20; i++) {
            serie += (1.0 / (2 * i + 1.0)) * exponencial(((a - 1.0) / (a + 1.0)), (2.0 * i + 1.0));
        }
    }

    return 2 * serie;
}

double log(double a, double b) {
    return logNatural(a) / logNatural(b);
}

double raiz(double a, double b) {
    return exponencialNatural((1.0 / b) * logNatural(a));
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
        case 'c':
                scanf("%lf", &x);
                resultado = cosseno(x);
                break;
        case 't':
                scanf("%lf", &x);
                resultado = tangente(x);
        case 'n':
                scanf("%lf", &x);
                resultado = exponencialNatural(x);
        case 'g':
                scanf("%lf", &x);
                resultado = logNatural(x);
                break;
        case 'l':
                scanf("%lf %lf", &x, &y);
                resultado = log(x, y);
        case 'r':
                scanf("%lf %lf", &x, &y);
                resultado = raiz(x, y);
        default:
                break;
    }

    printf("%.2f", resultado);
    return 0;
}