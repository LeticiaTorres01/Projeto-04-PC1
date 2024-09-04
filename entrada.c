#include <stdio.h>
#include <stdlib.h>
#include "entrada.h"
#include "tratamento.h"

// Função para abertura e leitura do primeiro arquivo
void leitura_arq(char *argv[], struct trans *transacao)
{
    FILE *dataFileTrans = NULL;
    dataFileTrans = fopen(argv[1], "r");
    erro_abertura(dataFileTrans);
    fscanf(dataFileTrans, "%8[^\n]\n", transacao->lin_A);
    fscanf(dataFileTrans, "%8[^\n]\n", transacao->lin_B);
    fscanf(dataFileTrans, "%8[^\n]\n", transacao->lin_C);
    fclose(dataFileTrans);
}
