#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entrada.h"
#include "saida.h"
#include "processamento.h"

// Função responsável por contar quais letras estão sendo usadas na transação e colocar na posição corresponde do alfabeto
void contador(struct trans transacao, int alfabeto[], int *caracter)
{
    // Pega o tamanho de cada uma das linhas do arquivo
    int tamA = strlen(transacao.lin_A), tamB = strlen(transacao.lin_B), tamC = strlen(transacao.lin_C);

    // Laço que percorre a palavra A para descobrir quais as letras estão sendo usadas
    for (int i = 0; i < tamA; i++)
    {
        alfabeto[transacao.lin_A[i] - 65] = 1; //'65' é o valor correspondente ao 'A' na tabela ASCII
    }

    // Laço que percorre a palavra B para descobrir quais as letras estão sendo usadas
    for (int i = 0; i < tamB; i++)
    {
        alfabeto[transacao.lin_B[i] - 65] = 1; //'65' é o valor correspondente ao 'A' na tabela ASCII
    }

    // Laço que percorre a palavra C para descobrir quais as letras estão sendo usadas
    for (int i = 0; i < tamC; i++)
    {
        alfabeto[transacao.lin_C[i] - 65] = 1; //'65' é o valor correspondente ao 'A' na tabela ASCII
    }

    cont_letras(caracter, alfabeto);
}

// Função responsável por contar quantas letras estão sendo usadas
void cont_letras(int *caracter, int alfabeto[])
{
    int count = 0;

    // Laço que percorre o alfabeto e identifica quando uma posição/letra do alfabeto tem 1
    for (int i = 0; i < 26; i++)
    {
        if (alfabeto[i] == 1)
        {
            count++;
        }
    }
    (*caracter) = count;
}

// Função responsável por organizar as letras e agregar o valor '9' para cada uma das letras
void organiza(int caracter, struct trans transacao, int organizador[], int alfabeto[], struct aux *copia)
{
    // Laço que vai percorrer o organizador pela quantidade de letras encontrada
    for (int i = 0; i < caracter; i++)
    {
        // Laço que vai percorrer o alfabeto para saber qual posição é igual à 1
        for (int k = 0; k < 26; k++)
        {
            if (alfabeto[k] == 1)
            {
                // Volta o valor da posição encontrada para 0
                alfabeto[k] = 0;

                // Soma a posição do alfabeto com 65 para saber qual é a letra esté sendo guardada no organizador
                organizador[i] = k + 65;

                // Agrega valor 9 na posição dobrada da letra para corresponder a letra da metade da posição
                organizador[caracter + i] = '9';
                break;
            }
        }
    }
    auxiliar(transacao, copia, organizador, caracter);
}

// Função responsável por construir a struct auxiliar, invés de letras vai ter o 9, para ser feito a decifração
void auxiliar(struct trans transacao, struct aux *copia, int organizador[], int caracter)
{
    // Pega o tamanho de cada palavra
    int tamA = strlen(transacao.lin_A), tamB = strlen(transacao.lin_B), tamC = strlen(transacao.lin_C);

    // Laço que percorre cada caracter da primeira palavra pelo seu próprio tamanho
    for (int i = 0; i < tamA; i++)
    {
        // Laço que percorre o organizador pela quantidade de caracteres encontrados
        for (int k = 0; k < caracter; k++)
        {
            // Condição para saber se a letra da palavra é a mesma do organizador para ser guardado em uma struct auxiliar
            if (transacao.lin_A[i] == organizador[k])
            {
                copia->copA[i] = organizador[caracter + k];
            }
        }

        // Coloca a terminação nula na palavra da nova struct
        copia->copA[tamA] = '\0';
    }

    // Laço que percorre cada caracter da primeira palavra pelo seu próprio tamanho
    for (int i = 0; i < tamB; i++)
    {
        // Laço que percorre o organizador pela quantidade de caracteres encontrados
        for (int k = 0; k < caracter; k++)
        {
            // Condição para saber se a letra da palavra é a mesma do organizador para ser guardado em uma struct auxiliar
            if (transacao.lin_B[i] == organizador[k])
            {
                copia->copB[i] = organizador[caracter + k];
            }
        }

        // Coloca a terminação nula na palavra da nova struct
        copia->copB[tamB] = '\0';
    }

    // Laço que percorre cada caracter da primeira palavra pelo seu próprio tamanho
    for (int i = 0; i < tamC; i++)
    {
        // Laço que percorre o organizador pela quantidade de caracteres encontrados
        for (int k = 0; k < caracter; k++)
        {
            // Condição para saber se a letra da palavra é a mesma do organizador para ser guardado em uma struct auxiliar
            if (transacao.lin_C[i] == organizador[k])
            {
                copia->copC[i] = organizador[caracter + k];
            }
        }

        // Coloca a terminação nula na palavra da nova struct
        copia->copC[tamC] = '\0';
    }
}

// Função responsável pelo teste da soma dos algarismos para serem testados
int somaAB(struct aux copia)
{
    // Transforma as palavras da struct auxiliar em inteiro, essas palavras são números 9
    int A = atoi(copia.copA), B = atoi(copia.copB), C = atoi(copia.copC);

    // Condição para saber se a soma vai dar a terceira palavra e retornar 1 caso seja verdadeira, se falsa, retorna 0
    if ((A + B) == C)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Função responsável por decifrar o valor da transação
void decifrador(struct aux *copia, struct trans transacao, int organizador[], int caracter, char *argv[])
{
    int bandeira = 1;
    aux copia2;

    // Inicialização do copia2
    copia2.copC[0] = '0', copia2.copC[1] = '\0';

    // Organizador auxiliar de mesmo tamanho do Organizador usado anteriormente
    int orgAux[caracter * 2];

    // Array com tamanho de letras encontradas +1 para a terminação nula
    char numeros[caracter + 1];

    // Laço responsável por decrementar o valor para testar a soma e descobrir o maior valor
    while (bandeira > 0)
    {
        // Percorre numeros e o organizador pela quantidade de letras e depois guarda o numero correpsonde do organizador em numeros
        for (int i = 0; i < caracter; i++)
        {
            numeros[i] = organizador[caracter + i];
        }

        // Acrescenta terminação nula
        numeros[caracter] = '\0';

        // Transforma o array numeros em inteiro para ser feito a decrementação
        int algarismo = atoi(numeros);

        // Decrementa 1 do valor de algarismo
        algarismo = algarismo - 1;

        // Testa se a subtração anterior é menor que zero para interromper a decrementação
        if (algarismo < 0)
        {
            break;
        }

        // Inicializa todos os caracteres de numeros para 0
        memset(numeros, '0', sizeof(numeros));

        // Adiciona o número por trás
        sprintf(numeros + caracter - snprintf(NULL, 0, "%d", algarismo), "%d", algarismo);

        // Faz o caminho inverso do primeiro for
        for (int i = caracter - 1; i >= 0; i--)
        {
            organizador[caracter + i] = numeros[i];
        }

        // Chama a função para passar os valores para a struct auxiliar
        auxiliar(transacao, copia, organizador, caracter);

        // Condição para saber se a posição a mais esquerda é igual a zero
        if ((strlen((*copia).copA) > 1 && (*copia).copA[0] == '0'))
        {
            continue;
        }

        // Condição para saber se a posição a mais esquerda é igual a zero
        if ((strlen((*copia).copB) > 1 && (*copia).copB[0] == '0'))
        {
            continue;
        }

        // Condição para saber se a posição a mais esquerda é igual a zero
        if ((strlen((*copia).copC) > 1 && (*copia).copC[0] == '0'))
        {
            continue;
        }

        // Condição que testa se a soma com os valores encontrados deu certo
        if (somaAB(*copia) == 1)
        {
            // Condição para ver se uma das somas encontradas é maior que o outra

            if (atoi(copia->copC) >= atoi(copia2.copC))
            {
                // Guarda a maior soma em outra nova struct para testar novamente caso tenhamos outro resultado
                strcpy(copia2.copA, copia->copA);
                strcpy(copia2.copB, copia->copB);
                strcpy(copia2.copC, copia->copC);

                // Percorre o Organizador para guardar os mesmos valores no Organizador auxiliar
                for (int i = 0; i < caracter * 2; i++)
                {
                    orgAux[i] = organizador[i];
                }
            }
            bandeira = 2;
        }
    }

    // Condição para saber se a soma foi encontrada ou não
    if (bandeira == 2)
    {

        // Printa os valores das 3 palavras
        saida_arq(argv, copia2, orgAux, caracter);
    }
    if (bandeira == 1)
    {

        // Printa -1 caso não seja possível a soma
        saida_erro(argv);
    }
}
