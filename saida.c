#include <stdio.h>
#include <stdlib.h>
#include "entrada.h"
#include "tratamento.h"

// Função que abre e escreve no arquivo o que foi pedido
void saida_arq(char *argv[], struct aux copia, int organizador[], int caracter)
{
    FILE *dataFileExit = NULL;
    dataFileExit = fopen(argv[2], "w");
    erro_abertura(dataFileExit);
    int result = atoi(copia.copC);
    fprintf(dataFileExit, "%d\n", result);
    for (int i = 0; i < caracter; i++)
    {
        fprintf(dataFileExit, "%c:%c\n", organizador[i], organizador[caracter + i]);
    }
    fclose(dataFileExit);
    exit(0);
}

// Função que abre e escreve '-1'
void saida_erro(char *argv[])
{
    FILE *dataFileExit = NULL;
    dataFileExit = fopen(argv[2], "w");
    erro_abertura(dataFileExit);
    fprintf(dataFileExit, "%d", -1);
    fclose(dataFileExit);
    exit(0);
}
