#include <stdio.h>
#include <stdlib.h>
#include "entrada.h"
#include "processamento.h"
#include "tratamento.h"
#include "saida.h"

int main(int argc, char *argv[])
{
    erro_inicia(argc);
    int alfabeto[26] = {0}, caracter = 0;
    trans transacao;
    aux copia;
    leitura_arq(argv, &transacao);
    contador(transacao, alfabeto, &caracter);
    int organizador[caracter * 2];
    organiza(caracter, transacao, organizador, alfabeto, &copia);
    auxiliar(transacao, &copia, organizador, caracter);
    decifrador(&copia, transacao, organizador, caracter, argv);
    return 0;
}
