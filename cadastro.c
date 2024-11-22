#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    int cpf;
    char email[50]; 
    int pk;
} Cadastro;

void cadastro(Cadastro pessoa[], int *quantidade) {
    int qtd;
    printf("Insira a quantidade de pessoas que você deseja cadastrar:");
    scanf("%d", &qtd);

    for (int i = *quantidade; i < *quantidade + qtd; i++) {
        pessoa[i].pk = i + 1; 
        printf("Digite o seu nome: ");
        scanf(" %[^\n]s", pessoa[i].nome);
        printf("Digite a sua idade: ");
        scanf("%d", &pessoa[i].idade);
        printf("Digite o seu CPF: ");
        scanf("%d", &pessoa[i].cpf);
        printf("Digite o seu E-MAIL: ");
        scanf("%s", pessoa[i].email);
        printf("Cadastro concluído! PK: %d\n\n", pessoa[i].pk);
    }

    *quantidade += qtd; 
}

void exibirdados(Cadastro pessoa[], int quantidade) {
    if (quantidade == 0) {
        printf("Nenhuma pessoa cadastrada.\n");
        return;
    }

    printf("\n--- DADOS ---\n");
    for (int i = 0; i < quantidade; i++) {
        printf("PK: %d\n", pessoa[i].pk);
        printf("Nome: %s\n", pessoa[i].nome);
        printf("Idade: %d\n", pessoa[i].idade);
        printf("CPF: %d\n", pessoa[i].cpf);
        printf("E-MAIL: %s\n\n", pessoa[i].email);
    }
}

void pesquisar(Cadastro pessoa[], int quantidade) {
    int opcao, valor;
    printf("Pesquisar por:\n");
    printf("1. CPF\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        printf("Digite o CPF: ");
        scanf("%d", &valor);
        for (int i = 0; i < quantidade; i++) {
            if (pessoa[i].cpf == valor) {
                printf("\n--- ---\n");
                printf("PK: %d\n", pessoa[i].pk);
                printf("Nome: %s\n", pessoa[i].nome);
                printf("Idade: %d\n", pessoa[i].idade);
                printf("CPF: %d\n", pessoa[i].cpf);
                printf("E-MAIL: %s\n\n", pessoa[i].email);
                return;
            }
        }
        printf("CPF não encontrado.\n");
    }
}

int main() {
    Cadastro pessoa[999];
    int quantidade = 0; 
    int op;

    do {
        printf("\n--- MENU ----\n");
        printf("1. Cadastrar\n");
        printf("2. Exibir Pessoas\n");
        printf("3. Pesquisar\n");
        printf("4. Sair\n");
        printf(": ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                cadastro(pessoa, &quantidade);
                break;
            case 2:
                exibirdados(pessoa, quantidade);
                break;
            case 3:
                pesquisar(pessoa, quantidade);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (op != 4);

    return 0;
}
