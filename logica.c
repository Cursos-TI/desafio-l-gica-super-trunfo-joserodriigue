#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> // Para usar tolower

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

void comparar_cartas(Carta carta1, Carta carta2) {
    int escolha;

    printf("\n--- Menu de Comparação ---\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite o número da sua escolha: ");
    scanf("%d", &escolha);
    getchar(); // Consumir o newline

    printf("\nComparação: %s (%s) vs %s (%s)\n", carta1.nome_cidade, carta1.estado, carta2.nome_cidade, carta2.estado);

    switch (escolha) {
        case 1:
            printf("Atributo: População\n");
            printf("  %s: %d\n", carta1.nome_cidade, carta1.populacao);
            printf("  %s: %d\n", carta2.nome_cidade, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("  Vencedor: %s\n", carta1.nome_cidade);
            } else if (carta2.populacao > carta1.populacao) {
                printf("  Vencedor: %s\n", carta2.nome_cidade);
            } else {
                printf("  Empate!\n");
            }
            break;
        case 2:
            printf("Atributo: Área\n");
            printf("  %s: %.2f km²\n", carta1.nome_cidade, carta1.area);
            printf("  %s: %.2f km²\n", carta2.nome_cidade, carta2.area);
            if (carta1.area > carta2.area) {
                printf("  Vencedor: %s\n", carta1.nome_cidade);
            } else if (carta2.area > carta1.area) {
                printf("  Vencedor: %s\n", carta2.nome_cidade);
            } else {
                printf("  Empate!\n");
            }
            break;
        case 3:
            printf("Atributo: PIB\n");
            printf("  %s: R$ %.2f\n", carta1.nome_cidade, carta1.pib);
            printf("  %s: R$ %.2f\n", carta2.nome_cidade, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("  Vencedor: %s\n", carta1.nome_cidade);
            } else if (carta2.pib > carta1.pib) {
                printf("  Vencedor: %s\n", carta2.nome_cidade);
            } else {
                printf("  Empate!\n");
            }
            break;
        case 4:
            printf("Atributo: Número de Pontos Turísticos\n");
            printf("  %s: %d\n", carta1.nome_cidade, carta1.num_pontos_turisticos);
            printf("  %s: %d\n", carta2.nome_cidade, carta2.num_pontos_turisticos);
            if (carta1.num_pontos_turisticos > carta2.num_pontos_turisticos) {
                printf("  Vencedor: %s\n", carta1.nome_cidade);
            } else if (carta2.num_pontos_turisticos > carta1.num_pontos_turisticos) {
                printf("  Vencedor: %s\n", carta2.nome_cidade);
            } else {
                printf("  Empate!\n");
            }
            break;
        case 5:
            printf("Atributo: Densidade Demográfica\n");
            printf("  %s: %.2f hab/km²\n", carta1.nome_cidade, carta1.densidade_populacional);
            printf("  %s: %.2f hab/km²\n", carta2.nome_cidade, carta2.densidade_populacional);
            if (carta1.densidade_populacional < carta2.densidade_populacional) {
                printf("  Vencedor: %s\n", carta1.nome_cidade);
            } else if (carta2.densidade_populacional < carta1.densidade_populacional) {
                printf("  Vencedor: %s\n", carta2.nome_cidade);
            } else {
                printf("  Empate!\n");
            }
            break;
        default:
            printf("Opção inválida! Por favor, escolha uma opção do menu.\n");
    }
}

int main() {
    Carta carta1, carta2;

    printf("Cadastro da Primeira Carta:\n");
    cadastrar_carta(&carta1);

    printf("\nCadastro da Segunda Carta:\n");
    cadastrar_carta(&carta2);

    printf("\n--- Cartas Cadastradas ---\n");

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

    comparar_cartas(carta1, carta2);

    return 0;
}