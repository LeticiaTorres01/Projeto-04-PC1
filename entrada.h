#ifndef ENTRADA_H
#define ENTRADA_H

typedef struct trans
{
    char lin_A[9];
    char lin_B[9];
    char lin_C[9];
} trans;

typedef struct aux
{
    char copA[9];
    char copB[9];
    char copC[9];
} aux;

// void count_struct(char *argv[]);
void leitura_arq(char *argv[], struct trans *transacao);

#endif // ENTRADA_H