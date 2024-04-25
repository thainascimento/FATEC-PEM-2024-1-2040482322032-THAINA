#include <stdio.h>

// Define as operações matemáticas
#define SOMA '+'
#define SUBTRACAO '-'
#define MULTIPLICACAO '*'
#define DIVISAO '/'

// Protótipos das funções
float soma(float num1, float num2);
float subtracao(float num1, float num2);
float multiplicacao(float num1, float num2);
float divisao(float num1, float num2);
char obterOperacao();
float obterNumero();
void limparBuffer();

int main() {
    char operacao;
    float num1, num2, resultado;

    printf("Bem-vindo à Calculadora de 4 operações básicas!\n");

    do {
        operacao = obterOperacao();

        if (operacao == 'S') {
            printf("Encerrando a calculadora.\n");
            break;
        }

        num1 = obterNumero();
        num2 = obterNumero();

        switch (operacao) {
            case SOMA:
                resultado = soma(num1, num2);
                break;
            case SUBTRACAO:
                resultado = subtracao(num1, num2);
                break;
            case MULTIPLICACAO:
                resultado = multiplicacao(num1, num2);
                break;
            case DIVISAO:
                resultado = divisao(num1, num2);
                break;
            default:
                printf("Operação inválida.\n");
                continue; // Volta ao início do loop
        }

        printf("Resultado: %.2f\n", resultado);

    } while (operacao != 'S');

    return 0;
}

// Função para realizar a soma
float soma(float num1, float num2) {
    return num1 + num2;
}

// Função para realizar a subtração
float subtracao(float num1, float num2) {
    return num1 - num2;
}

// Função para realizar a multiplicação
float multiplicacao(float num1, float num2) {
    return num1 * num2;
}

// Função para realizar a divisão
float divisao(float num1, float num2) {
    if (num2 != 0) {
        return num1 / num2;
    } else {
        printf("Erro: Divisão por zero.\n");
        return 0;
    }
}

// Função para obter a operação desejada do usuário
char obterOperacao() {
    char operacao;

    printf("Digite a operação desejada (+, -, *, /) ou 'S' para sair: ");
    scanf(" %c", &operacao);

    return operacao;
}

// Função para obter um número do usuário
float obterNumero() {
    float num;

    printf("Digite um número: ");
    scanf("%f", &num);

    return num;
}

// Função para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
