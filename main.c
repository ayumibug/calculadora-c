
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void mostrarMenu();
double somar(double num1, double num2);
double subtrair(double num1, double num2);
double multiplicar(double num1, double num2);
double dividir(double num1, double num2);

int main() {
    int opcao;
    int continuar = 1;
    int caractere;
    int respostaValida;
    char resposta;
    char entrada[100];
    char *fim;
    long valor;
    double num1, num2, resultado;

    do {
        mostrarMenu();

        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            break;
        }

        valor = strtol(entrada, &fim, 10);

        while (isspace((unsigned char)*fim)) {
            fim++;
        }

        if (fim == entrada || *fim != '\0' || valor < 1 || valor > 5) {
            printf("Opção inválida! Tente novamente.\n");
            continue;
        }

        opcao = (int)valor;

        switch (opcao) {

            case 1:
                printf("Digite o primeiro número: ");
                scanf("%lf", &num1);

                printf("Digite o segundo número: ");
                scanf("%lf", &num2);

                resultado = somar(num1, num2);

                printf("Resultado: %g + %g = %g\n", num1, num2, resultado);
                break;

            case 2:
                printf("Digite o primeiro número: ");
                scanf("%lf", &num1);

                printf("Digite o segundo número: ");
                scanf("%lf", &num2);

                resultado = subtrair(num1, num2);

                printf("Resultado: %g - %g = %g\n", num1, num2, resultado);
                break;

            case 3:
                printf("Digite o primeiro número: ");
                scanf("%lf", &num1);

                printf("Digite o segundo número: ");
                scanf("%lf", &num2);

                resultado = multiplicar(num1, num2);

                printf("Resultado: %g * %g = %g\n", num1, num2, resultado);
                break;

            case 4:
                printf("Digite o primeiro número: ");
                scanf("%lf", &num1);

                printf("Digite o segundo número: ");
                scanf("%lf", &num2);

                if (num2 == 0) {
                    dividir(num1, num2);
                } else {
                    resultado = dividir(num1, num2);

                    printf("Resultado: %g / %g = %g\n", num1, num2, resultado);
                }
                break;

            case 5:
                continuar = 0;
                break;
        }

        if (opcao != 5) {

            while ((caractere = getchar()) != '\n' && caractere != EOF);

            respostaValida = 0;

            do {
                printf("Deseja realizar outra operação? (s/n): ");

                if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
                    continuar = 0;
                    break;
                }

                fim = entrada;

                while (isspace((unsigned char)*fim)) {
                    fim++;
                }

                resposta = *fim;
                fim++;

                while (isspace((unsigned char)*fim)) {
                    fim++;
                }

                if ((resposta == 's' || resposta == 'S' ||
                     resposta == 'n' || resposta == 'N') && *fim == '\0') {

                    respostaValida = 1;

                    if (resposta == 's' || resposta == 'S') {
                        continuar = 1;
                    } else {
                        continuar = 0;
                    }

                } else {
                    printf("Resposta inválida! Digite s ou n.\n");
                }

            } while (respostaValida == 0);
        }

    } while (continuar == 1);

    printf("Obrigado por usar a calculadora! Até a próxima.\n");

    return 0;
}

void mostrarMenu() {
    printf("===============================\n");
    printf("   Calculadora Simples\n");
    printf("===============================\n");
    printf("Selecione uma operação:\n");
    printf("1. Adição\n");
    printf("2. Subtração\n");
    printf("3. Multiplicação\n");
    printf("4. Divisão\n");
    printf("5. Sair\n");
    printf("Opção: ");
}

double somar(double num1, double num2) {
    return num1 + num2;
}

double subtrair(double num1, double num2) {
    return num1 - num2;
}

double multiplicar(double num1, double num2) {
    return num1 * num2;
}

double dividir(double num1, double num2) {
    if (num2 == 0) {
        printf("Erro: Divisão por zero não é permitida.\n");
        return 0;
    }

    return num1 / num2;
}
