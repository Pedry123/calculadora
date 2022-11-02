#include<stdio.h>

void leituraDoisValores();
double soma(double a, double b), subtracao(double a, double b), multiplicacao(double a, double b), divisao();


void leituraDoisValores(double a, double b) {
    scanf("%lf %lf", &a, &b);
}
double soma(double a, double b) {
    
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
                //multiplicacao();
                break;
        case '/':
                //divisao();  
                break;
        default:
                break;
    }

    printf("%.2f", resultado);
    return 0;
}