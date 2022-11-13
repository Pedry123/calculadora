#include<stdio.h> // Biblioteca padrao de funcoes de entrada e saida.

double soma(double a, double b), subtracao(double a, double b), multiplicacao(double a, double b), divisao(double a, double b), modulo(double a), fatorial(double a), exponencial(double a, double b), seno(double a), cosseno(double a), tangente(double a), exponencialNatural(double a), logNatural(double a), logaritmo(double a, double b), raiz(double a, double b); // Declaracao das funcoes.


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
    for(int i = 1; i <= a; i++) {
        fat *= i;
    }
    return fat;
}

double exponencial(double a, double b) { // Operacao que eleva um numero a outro.
    double exp = 1.0;
    if (b != 0.0) { 

        for(int i = 0; i < b; i++) {
            exp *= a;
        }
    }
    return exp;
}

double seno(double a) { // As funcoes seno, cosseno e tangente estao em radianos.
    double serie = 0.0;
    for(int i = 0; i < 20; i++) {
        serie += (exponencial(-1.0, i) / fatorial(2.0 * i + 1.0)) * exponencial(a,  2.0 * i + 1.0);
    }

    return serie;
}

double cosseno(double a) { 
    double serie = 0.0;
    for(int i = 0; i < 20; i++) {
        serie += (exponencial(-1.0, i) / fatorial(2.0 * i)) * exponencial(a, 2.0 * i);
    }

    return serie;
}

double tangente(double a) { 
    return seno(a) / cosseno(a);
}

double exponencialNatural(double a) { // Operacao de exponencial, cuja base eh o numero de Euler.
    double serie = 0.0;

    for(int i = 0; i < 20; i++) {
        serie += exponencial(a, i) / fatorial(i);
    }

    return serie;
}

double logNatural(double a) { // Operacao de logaritmo natural, isto eh, cuja base eh Euler.
    double serie = 0.0;

    if (a > 0) {
        for(int i = 0; i < 20; i++) {
            serie += (1.0 / (2.0 * i + 1.0)) * exponencial(((a - 1.0) / (a + 1.0)), (2.0 * i + 1.0));
        }
    }

    return 2.0 * serie;
}

double logaritmo(double a, double b) { 
        return logNatural(a) / logNatural(b);
}

double raiz(double a, double b) { // Operacao da raiz enesima. O primeiro parametro eh o radicando, e o segundo eh o indice.
        return exponencialNatural((1.0 / b) * logNatural(a));
}

int main() { // Programa principal
    double x, y, resultado;
    char operacao;

    scanf("%c", &operacao);

    switch (operacao) { //De acordo com a leitura do caractere, sera feita a operacao desejada.
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
                if (x > 0) {
                    resultado = fatorial(x);
                    break;
                }
                return -1;
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
                break;
        case 'n':
                scanf("%lf", &x);
                resultado = exponencialNatural(x);
                break;
        case 'g':
                scanf("%lf", &x);
                if (x > 0.0) {
                    resultado = logNatural(x);
                    break;
                }
                return -1; // Encerramento do programa, quando as condicoes da operacao nao sao satisfeitas.
        case 'l':
                scanf("%lf %lf", &x, &y);
                if (x > 0.0 && y > 0.0) {
                    resultado = logaritmo(x, y);
                    break;
                }  
                return -1;
        case 'r':
                scanf("%lf %lf", &x, &y);
                if (x > 0.0 && y > 0.0) {
                    resultado = raiz(x, y);
                    break;
                }
                return -1;
        default:
                break;
    }

    printf("%.2f", resultado); // Print com precisao de duas casas decimais.
    return 0;
}