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

// Função para cadastrar os dados de uma carta (mantida do desafio anterior)
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

// Função para exibir o menu de escolha de atributo
int escolher_atributo(int atributo_escolhido1) {
    int escolha;

    printf("\n--- Escolha o Atributo para Comparação ---\n");
    printf("Escolha um atributo:\n");
    if (atributo_escolhido1 != 1) printf("1 - População\n");
    if (atributo_escolhido1 != 2) printf("2 - Área\n");
    if (atributo_escolhido1 != 3) printf("3 - PIB\n");
    if (atributo_escolhido1 != 4) printf("4 - Número de Pontos Turísticos\n");
    if (atributo_escolhido1 != 5) printf("5 - Densidade Demográfica\n");
    printf("Digite o número da sua escolha: ");
    scanf("%d", &escolha);
    getchar(); // Consumir o newline

    return escolha;
}

void comparar_cartas(Carta carta1, Carta carta2) {
    int atributo1, atributo2;
    float valor1_atributo1 = 0, valor2_atributo1 = 0;
    float valor1_atributo2 = 0, valor2_atributo2 = 0;
    char nome_atributo1[50] = "", nome_atributo2[50] = "";
    int pontos1 = 0, pontos2 = 0;

    // Escolha do primeiro atributo
    atributo1 = escolher_atributo(0);
    while (atributo1 < 1 || atributo1 > 5) {
        printf("Opção inválida. Por favor, escolha um atributo da lista.\n");
        atributo1 = escolher_atributo(0);
    }

    // Escolha do segundo atributo (garantindo que seja diferente do primeiro)
    atributo2 = escolher_atributo(atributo1);
    while (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
        printf("Opção inválida ou atributo já escolhido. Por favor, escolha um atributo diferente da lista.\n");
        atributo2 = escolher_atributo(atributo1);
    }

    printf("\n--- Comparação: %s (%s) vs %s (%s) ---\n", carta1.nome_cidade, carta1.estado, carta2.nome_cidade, carta2.estado);

    // Comparação do primeiro atributo
    switch (atributo1) {
        case 1:
            strcpy(nome_atributo1, "População");
            valor1_atributo1 = carta1.populacao;
            valor2_atributo1 = carta2.populacao;
            if (carta1.populacao > carta2.populacao) pontos1++;
            else if (carta2.populacao > carta1.populacao) pontos2++;
            break;
        case 2:
            strcpy(nome_atributo1, "Área");
            valor1_atributo1 = carta1.area;
            valor2_atributo1 = carta2.area;
            if (carta1.area > carta2.area) pontos1++;
            else if (carta2.area > carta1.area) pontos2++;
            break;
        case 3:
            strcpy(nome_atributo1, "PIB");
            valor1_atributo1 = carta1.pib;
            valor2_atributo1 = carta2.pib;
            if (carta1.pib > carta2.pib) pontos1++;
            else if (carta2.pib > carta1.pib) pontos2++;
            break;
        case 4:
            strcpy(nome_atributo1, "Número de Pontos Turísticos");
            valor1_atributo1 = carta1.num_pontos_turisticos;
            valor2_atributo1 = carta2.num_pontos_turisticos;
            if (carta1.num_pontos_turisticos > carta2.num_pontos_turisticos) pontos1++;
            else if (carta2.num_pontos_turisticos > carta1.num_pontos_turisticos) pontos2++;
            break;
        case 5:
            strcpy(nome_atributo1, "Densidade Demográfica");
            valor1_atributo1 = carta1.densidade_populacional;
            valor2_atributo1 = carta2.densidade_populacional;
            if (carta1.densidade_populacional < carta2.densidade_populacional) pontos1++;
            else if (carta2.densidade_populacional < carta1.densidade_populacional) pontos2++;
            break;
    }

    // Comparação do segundo atributo
    switch (atributo2) {
        case 1:
            strcpy(nome_atributo2, "População");
            valor1_atributo2 = carta1.populacao;
            valor2_atributo2 = carta2.populacao;
            if (carta1.populacao > carta2.populacao) pontos1++;
            else if (carta2.populacao > carta1.populacao) pontos2++;
            break;
        case 2:
            strcpy(nome_atributo2, "Área");
            valor1_atributo2 = carta1.area;
            valor2_atributo2 = carta2.area;
            if (carta1.area > carta2.area) pontos1++;
            else if (carta2.area > carta1.area) pontos2++;
            break;
        case 3:
            strcpy(nome_atributo2, "PIB");
            valor1_atributo2 = carta1.pib;
            valor2_atributo2 = carta2.pib;
            if (carta1.pib > carta2.pib) pontos1++;
            else if (carta2.pib > carta1.pib) pontos2++;
            break;
        case 4:
            strcpy(nome_atributo2, "Número de Pontos Turísticos");
            valor1_atributo2 = carta1.num_pontos_turisticos;
            valor2_atributo2 = carta2.num_pontos_turisticos;
            if (carta1.num_pontos_turisticos > carta2.num_pontos_turisticos) pontos1++;
            else if (carta2.num_pontos_turisticos > carta1.num_pontos_turisticos) pontos2++;
            break;
        case 5:
            strcpy(nome_atributo2, "Densidade Demográfica");
            valor1_atributo2 = carta1.densidade_populacional;
            valor2_atributo2 = carta2.densidade_populacional;
            if (carta1.densidade_populacional < carta2.densidade_populacional) pontos1++;
            else if (carta2.densidade_populacional < carta1.densidade_populacional) pontos2++;
            break;
    }

    printf("Atributo 1: %s\n", nome_atributo1);
    printf("  %s: %.2f\n", carta1.nome_cidade, valor1_atributo1);
    printf("  %s: %.2f\n", carta2.nome_cidade, valor2_atributo1);

    printf("Atributo 2: %s\n", nome_atributo2);
    printf("  %s: %.2f\n", carta1.nome_cidade, valor1_atributo2);
    printf("  %s: %.2f\n", carta2.nome_cidade, valor2_atributo2);

    printf("\n--- Resultado da Rodada ---\n");
    printf("Pontuação %s: %d\n", carta1.nome_cidade, pontos1);
    printf("Pontuação %s: %d\n", carta2.nome_cidade, pontos2);

    if (pontos1 > pontos2) {
        printf("Vencedor da rodada: %s\n", carta1.nome_cidade);
    } else if (pontos2 > pontos1) {
        printf("Vencedor da rodada: %s\n", carta2.nome_cidade);
    } else {
        printf("Empate na rodada!\n");
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