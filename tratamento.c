#include <stdio.h>
#include <stdlib.h>
#include "tratamento.h"

// Função para retornar se houve erro na abertura de arquivo
void erro_abertura(FILE *dataFileExit)
{
    if (dataFileExit == NULL)
    {
        printf("Erro de abertura\n");
    }
}

// Função para retornar se a inicialização não corresponde com o padrão necessário
void erro_inicia(int argc)
{
    if (argc != 3)
    {
        printf("Erro na inicialização, uso: ./main arquivo_entrada arquivo_saida\n");
        exit(0);
    }
}