#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do Produto
typedef struct {
    int id;
    char nome[50];
    char descricao[200];
    float preco;
    int quantidade;
} Produto;

// Funções
void inserirProduto(Produto **produtos, int *total);
void comprarProduto(Produto *produtos, int total);
void listarProdutos(Produto *produtos, int total);
void bubbleSort(Produto *produtos, int total);
Produto* buscarProdutoPorId(Produto *produtos, int total, int id);

int main() {
    int opcao;
    Produto *produtos = NULL;
    int totalProdutos = 0;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir Produto\n");
        printf("2. Comprar Produto\n");
        printf("3. Listar Produtos\n");
        printf("4. Sair\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirProduto(&produtos, &totalProdutos);
                break;
            case 2:
                comprarProduto(produtos, totalProdutos);
                break;
            case 3:
                printf("\nProdutos Cadastrados:\n");
                listarProdutos(produtos, totalProdutos);
                break;
            case 4:
                printf("Saindo...\n");
                break;    
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao >! 4);

    free(produtos);
    return 0;
}

void inserirProduto(Produto **produtos, int *total) {
    *produtos = realloc(*produtos, (*total + 1) * sizeof(Produto));
    Produto *novoProduto = &(*produtos)[*total];

    printf("ID do produto: ");
    scanf("%d", &novoProduto->id);
    printf("Nome do produto: ");
    scanf(" %[^\n]", novoProduto->nome);
    printf("Descricao do produto: ");
    scanf(" %[^\n]", novoProduto->descricao);
    printf("Preco do produto: ");
    scanf("%f", &novoProduto->preco);
    printf("Quantidade em estoque: ");
    scanf("%d", &novoProduto->quantidade);

    (*total)++;
}

void comprarProduto(Produto *produtos, int total) {
    int id, quantidade;
    printf("ID do produto: ");
    scanf("%d", &id);
    Produto *produto = buscarProdutoPorId(produtos, total, id);

    if (produto) {
        printf("Quantidade desejada: ");
        scanf("%d", &quantidade);
        if (quantidade <= produto->quantidade) {
            produto->quantidade -= quantidade;
            printf("Compra realizada com sucesso!\n");
        } else {
            printf("Quantidade em estoque insuficiente!\n");
        }
    } else {
        printf("Produto inexistente!\n");
    }
}

void listarProdutos(Produto *produtos, int total) {
    bubbleSort(produtos, total);
    for (int i = 0; i < total; i++) {
        printf("ID: %d\n", produtos[i].id);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Descricao: %s\n", produtos[i].descricao);
        printf("Preco: %.2f\n", produtos[i].preco);
        printf("Quantidade: %d\n", produtos[i].quantidade);
        
    }
}

void bubbleSort(Produto *produtos, int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (strcmp(produtos[j].nome, produtos[j + 1].nome) > 0) {
                Produto temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }
}

Produto* buscarProdutoPorId(Produto *produtos, int total, int id) {
    for (int i = 0; i < total; i++) {
        if (produtos[i].id == id) {
            return &produtos[i];
        }
    }
    return NULL;
}
