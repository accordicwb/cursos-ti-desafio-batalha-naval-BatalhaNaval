#include <stdio.h>


// BATALHA NAVAL – NÍVEL NOVATO
// Representação do tabuleiro, posicionamento dos navios e exibição


int main() {

    // ------------------------------------
    // 1. REPRESENTAÇÃO DO TABULEIRO 10x10
    // ------------------------------------
    int tabuleiro[10][10];

    // Inicializando o tabuleiro com 0 (água)
    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // ------------------------------------
    // 2. DEFINIÇÃO DOS NAVIOS (TAMANHO 3)
    // ------------------------------------
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3]   = {3, 3, 3};

    // Coordenadas de início definidas no código
    int inicioHorLinha = 2;
    int inicioHorColuna = 4;

    int inicioVerLinha = 5;
    int inicioVerColuna = 1;

    // ------------------------------------
    // 3. VALIDAÇÃO BÁSICA DOS NAVIOS
    // ------------------------------------
    int validoHorizontal = (inicioHorColuna + 2 < 10);
    int validoVertical   = (inicioVerLinha + 2 < 10);

    int sobrepoe = 0; // flag de sobreposição (0 = não, 1 = sim)

    // Verifica se o navio vertical passará por cima do horizontal
    for (int i = 0; i < 3; i++) {
        if ( (inicioVerLinha + i == inicioHorLinha) &&
             (inicioVerColuna == inicioHorColuna ||
              inicioVerColuna == inicioHorColuna + 1 ||
              inicioVerColuna == inicioHorColuna + 2) ) {
            sobrepoe = 1;
        }
    }

    if (!validoHorizontal || !validoVertical || sobrepoe) {
        printf("\nErro ao posicionar os navios! Coordenadas inválidas ou sobreposição detectada.\n");
        return 1;
    }

    // ------------------------------------
    // 4. POSICIONAR NAVIO HORIZONTAL
    // ------------------------------------
    for (int i = 0; i < 3; i++) {
        tabuleiro[inicioHorLinha][inicioHorColuna + i] = navioHorizontal[i];
    }

    // ------------------------------------
    // 5. POSICIONAR NAVIO VERTICAL
    // ------------------------------------
    for (int i = 0; i < 3; i++) {
        tabuleiro[inicioVerLinha + i][inicioVerColuna] = navioVertical[i];
    }

    // ------------------------------------
    // 6. EXIBIR O TABULEIRO COMPLETO
    // ------------------------------------
    printf("\n=== TABULEIRO DE BATALHA NAVAL 10x10 ===\n\n");

    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    printf("\nLegenda: 0 = Água | 3 = Parte do Navio\n");

    return 0;
}