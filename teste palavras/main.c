#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PALAVRAS 100
#define TAMANHO_MAX_PALAVRA 50

int lerPalavrasDoArquivo(const char *nomeArquivo, char palavras[MAX_PALAVRAS][TAMANHO_MAX_PALAVRA]);
void imprimePalavras(char palavras[][TAMANHO_MAX_PALAVRA], int numPalavras);

int main() {
    char palavras[MAX_PALAVRAS][TAMANHO_MAX_PALAVRA];
    int numPalavras = lerPalavrasDoArquivo("palavras.txt", palavras);

    if (numPalavras == -1) {
        return 1;
    }

    printf("Palavras carregadas com sucesso:\n");
    imprimePalavras(palavras, numPalavras);

    return 0;
}

int lerPalavrasDoArquivo(const char *nomeArquivo, char palavras[MAX_PALAVRAS][TAMANHO_MAX_PALAVRA]) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return -1;
    }

    int numPalavras = 0;
    while (fgets(palavras[numPalavras], TAMANHO_MAX_PALAVRA, arquivo) != NULL) {
        palavras[numPalavras][strcspn(palavras[numPalavras], "\n")] = '\0';
        numPalavras++;
        if (numPalavras >= MAX_PALAVRAS) {
            break;
        }
    }

    fclose(arquivo);
    return numPalavras;
}

void imprimePalavras(char palavras[][TAMANHO_MAX_PALAVRA], int numPalavras) {
    for (int i = 0; i < numPalavras; i++) {
        printf("%s\n", palavras[i]);
    }
}
