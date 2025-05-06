

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definição da estrutura da carta
typedef struct {
    char estado[50];
    char codigo[10];
    char nome_cidade[50];
    int populacao;
    float area;
    float pib;
    int num_pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

// Função para cadastrar os dados de uma carta
void cadastrar_carta(Carta *carta) {
    printf("Digite o Estado: ");
    fgets(carta->estado, sizeof(carta->estado), stdin);
    carta->estado[strcspn(carta->estado, "\n")] = 0; // Remover newline

    printf("Digite o Código da Carta: ");
    fgets(carta->codigo, sizeof(carta->codigo), stdin);
    carta->codigo[strcspn(carta->codigo, "\n")] = 0; // Remover newline

    printf("Digite o Nome da Cidade: ");
    fgets(carta->nome_cidade, sizeof(carta->nome_cidade), stdin);
    carta->nome_cidade[strcspn(carta->nome_cidade, "\n")] = 0; // Remover newline

    printf("Digite a População: ");
    scanf("%d", &carta->populacao);
    getchar(); // Consumir o newline deixado pelo scanf

    printf("Digite a Área (em km²): ");
    scanf("%f", &carta->area);
    getchar(); // Consumir o newline deixado pelo scanf

    printf("Digite o PIB (em R$): ");
    scanf("%f", &carta->pib);
    getchar(); // Consumir o newline deixado pelo scanf

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &carta->num_pontos_turisticos);
    getchar(); // Consumir o newline deixado pelo scanf

    // Calcular Densidade Populacional e PIB per capita
    if (carta->area > 0) {
        carta->densidade_populacional = (float)carta->populacao / carta->area;
    } else {
        carta->densidade_populacional = 0;
    }

    if (carta->populacao > 0) {
        carta->pib_per_capita = carta->pib / carta->populacao;
    } else {
        carta->pib_per_capita = 0;
    }
}

int main() {
    Carta carta1, carta2;

    printf("Cadastro da Primeira Carta:\n");
    cadastrar_carta(&carta1);

    printf("\nCadastro da Segunda Carta:\n");
    cadastrar_carta(&carta2);

    printf("\n--- Resultados ---\n");

    printf("\nPrimeira Carta (%s - %s):\n", carta1.estado, carta1.nome_cidade);
    printf("  População: %d\n", carta1.populacao);
    printf("  Área: %.2f km²\n", carta1.area);
    printf("  PIB: R$ %.2f\n", carta1.pib);
    printf("  Número de Pontos Turísticos: %d\n", carta1.num_pontos_turisticos);
    printf("  Densidade Populacional: %.2f hab/km²\n", carta1.densidade_populacional);
    printf("  PIB per capita: R$ %.2f\n", carta1.pib_per_capita);

    printf("\nSegunda Carta (%s - %s):\n", carta2.estado, carta2.nome_cidade);
    printf("  População: %d\n", carta2.populacao);
    printf("  Área: %.2f km²\n", carta2.area);
    printf("  PIB: R$ %.2f\n", carta2.pib);
    printf("  Número de Pontos Turísticos: %d\n", carta2.num_pontos_turisticos);
    printf("  Densidade Populacional: %.2f hab/km²\n", carta2.densidade_populacional);
    printf("  PIB per capita: R$ %.2f\n", carta2.pib_per_capita);

    // Escolha do atributo para comparação (altere aqui para outro atributo)
    char atributo_comparacao[] = "População";

    printf("\nComparação de cartas (Atributo: %s):\n", atributo_comparacao);

    if (strcmp(atributo_comparacao, "População") == 0) {
        printf("  %s: %d\n", carta1.nome_cidade, carta1.populacao);
        printf("  %s: %d\n", carta2.nome_cidade, carta2.populacao);
        if (carta1.populacao > carta2.populacao) {
            printf("  Vencedor: %s\n", carta1.nome_cidade);
        } else if (carta2.populacao > carta1.populacao) {
            printf("  Vencedor: %s\n", carta2.nome_cidade);
        } else {
            printf("  Empate!\n");
        }
    } else if (strcmp(atributo_comparacao, "Área") == 0) {
        printf("  %s: %.2f\n", carta1.nome_cidade, carta1.area);
        printf("  %s: %.2f\n", carta2.nome_cidade, carta2.area);
        if (carta1.area > carta2.area) {
            printf("  Vencedor: %s\n", carta1.nome_cidade);
        } else if (carta2.area > carta1.area) {
            printf("  Vencedor: %s\n", carta2.nome_cidade);
        } else {
            printf("  Empate!\n");
        }
    } else if (strcmp(atributo_comparacao, "PIB") == 0) {
        printf("  %s: %.2f\n", carta1.nome_cidade, carta1.pib);
        printf("  %s: %.2f\n", carta2.nome_cidade, carta2.pib);
        if (carta1.pib > carta2.pib) {
            printf("  Vencedor: %s\n", carta1.nome_cidade);
        } else if (carta2.pib > carta1.pib) {
            printf("  Vencedor: %s\n", carta2.nome_cidade);
        } else {
            printf("  Empate!\n");
        }
    } else if (strcmp(atributo_comparacao, "Densidade Populacional") == 0) {
        printf("  %s: %.2f\n", carta1.nome_cidade, carta1.densidade_populacional);
        printf("  %s: %.2f\n", carta2.nome_cidade, carta2.densidade_populacional);
        if (carta1.densidade_populacional < carta2.densidade_populacional) {
            printf("  Vencedor: %s\n", carta1.nome_cidade);
        } else if (carta2.densidade_populacional < carta1.densidade_populacional) {
            printf("  Vencedor: %s\n", carta2.nome_cidade);
        } else {
            printf("  Empate!\n");
        }
    } else if (strcmp(atributo_comparacao, "PIB per capita") == 0) {
        printf("  %s: %.2f\n", carta1.nome_cidade, carta1.pib_per_capita);
        printf("  %s: %.2f\n", carta2.nome_cidade, carta2.pib_per_capita);
        if (carta1.pib_per_capita > carta2.pib_per_capita) {
            printf("  Vencedor: %s\n", carta1.nome_cidade);
        } else if (carta2.pib_per_capita > carta1.pib_per_capita) {
            printf("  Vencedor: %s\n", carta2.nome_cidade);
        } else {
            printf("  Empate!\n");
        }
    } else {
        printf("  Atributo de comparação inválido!\n");
    }

    return 0;
}