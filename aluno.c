#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ALUNOS 50
#define TAM_NOME 51 


typedef struct {
    char nome[TAM_NOME];
    double nota;
} Aluno;


void incluirAluno(Aluno alunos[], int *qtdAlunos);
void listarAlunos(Aluno alunos[], int qtdAlunos);

int main() {
    Aluno alunos[MAX_ALUNOS];
    int qtdAlunos = 0;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Incluir aluno\n");
        printf("2. Listar alunos\n");
        printf("3. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        
        while(getchar() != '\n');

        switch (opcao) {
            case 1:
                if (qtdAlunos < MAX_ALUNOS) {
                    incluirAluno(alunos, &qtdAlunos);
                } else {
                    printf("Limite de alunos alcançado.\n");
                }
                break;
            case 2:
                listarAlunos(alunos, qtdAlunos);
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 3);

    return 0;
}

// Função novo aluno
void incluirAluno(Aluno alunos[], int *qtdAlunos) {
    char nome[TAM_NOME];
    double nota;
    printf("Informe o nome do aluno: ");
    scanf(" %[^\n]s", nome);

    printf("Informe a nota final do aluno: ");
    scanf("%lf", &nota);

    strcpy(alunos[*qtdAlunos].nome, nome);
    alunos[*qtdAlunos].nota = nota;

    (*qtdAlunos)++;
}

// Função listar os alunos
void listarAlunos(Aluno alunos[], int qtdAlunos) {
    if (qtdAlunos == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    printf("\nAlunos cadastrados:\n");
    for (int i = 0; i < qtdAlunos; i++) {
        printf("Nome: %s\n", alunos[i].nome);
        printf("Nota: %.2f\n", alunos[i].nota);
        if (alunos[i].nota >= 5.75) {
            printf("Situação: Aprovado\n");
        } else {
            printf("Situação: Reprovado\n");
        }
        printf("\n");
    }
}
