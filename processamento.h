#ifndef PROCESSAMENTO_H
#define PROCESSAMENTO_H

void contador(struct trans transacao, int alfabeto[], int *caracter);
void cont_letras(int *caracter, int alfabeto[]);
void organiza(int caracter, struct trans transacao, int organizador[], int alfabeto[], struct aux *copia);
void auxiliar(struct trans transacao, struct aux *copia, int organizador[], int caracter);
void decifrador(struct aux *copia, struct trans transacao, int organizador[], int caracter, char *argv[]);

#endif // PROCESSAMENTO_