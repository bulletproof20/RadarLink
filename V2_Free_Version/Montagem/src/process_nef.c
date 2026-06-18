

#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"
#include "interface.h"
#include "process_geral.h"
#include "process_ficheiro.h"
#include "process_esp.h"
#include "process_nef.h"


/**
 * @brief Identifica pontos nefastos na cidade com base na distância entre antenas.
 *
 * Esta função percorre os subgrafos de antenas com a mesma frequência e identifica 
 * locais onde possam ocorrer interferências, inserindo antenas de marcação ('#').
 *
 * @param inicioA Lista ligada de antenas já existentes na cidade.
 * @param inicioG Lista ligada de subgrafos de antenas com a mesma frequência.
 * @param n_linhas Número total de linhas da matriz da cidade.
 * @param n_colunas Número total de colunas da matriz da cidade.
 * @return LL_antena Lista ligada atualizada com os pontos nefastos identificados.
 */
LL_antena IdentificarNefastos(LL_antena inicioA, LL_subgrafos inicioG, int n_linhas, int n_colunas)
{
    if (inicioG == NULL)
    {
        printf("\n\n> ERROR 0 : Não existem antenas na cidade.");
        return NULL;
    }

    LL_subgrafos aux = inicioG;  // Percorrer cada grupo (mesma frequência)
    while (aux != NULL)
    {
        LL_vertice noA = aux->lista_vertice;  // Lista de vertice do grupo
        while (noA != NULL && noA->seguinte != NULL)
        {
            LL_vertice noB = noA->seguinte;  // Próxima antena para comparação

            while (noB != NULL)
            {
                int mDist = abs(noB->m - noA->m);
                int nDist = abs(noB->n - noA->n);
                printf("\n> Grupo %c,", aux->f);
                printf("\n> Antena A (%d, %d),", noA->m, noA->n);
                printf("\n> Antena B (%d, %d),", noB->m, noB->n);

                // Diagonal (cima-esquerda para baixo-direita)
                if ((noA->n < noB->n) && (noA->m < noB->m)) 
                {
                    printf("Direção: Diagonal (cima-esquerda para baixo-direita)\n");
                    int mNef = noB->m + mDist;
                    int nNef = noB->n + nDist;
                    if (mNef <= n_linhas && mNef > 0 && nNef <= n_colunas && nNef > 0 && (nDist != 0 && mDist != 0))
                    {
                        inicioA = InserirAntena(inicioA, mNef, nNef, '#');
                        printf("Ponto nefasto no canto inferior direito (%d, %d)\n", mNef, nNef);
                    }
                    mNef = noA->m - mDist;
                    nNef = noA->n - nDist;
                    if (mNef <= n_linhas && mNef > 0 && nNef <= n_colunas && nNef > 0 && (nDist != 0 && mDist != 0))
                    {
                        inicioA = InserirAntena(inicioA, mNef, nNef, '#');
                        printf("Ponto nefasto no canto superior esquerdo (%d, %d)\n", mNef, nNef);
                    }
                }
                // Diagonal (cima-direita para baixo-esquerda)
                else if ((noA->n > noB->n) && (noA->m != noB->m))
                {
                    printf("Direção: Diagonal (cima-direita para baixo-esquerda)\n");
                    int mNef = noB->m + mDist;
                    int nNef = noB->n - nDist;
                    if (mNef <= n_linhas && mNef > 0 && nNef <= n_colunas && nNef > 0 && (nDist != 0 && mDist != 0))
                    {
                        inicioA = InserirAntena(inicioA, mNef, nNef, '#');
                        printf("Ponto nefasto no canto inferior esquerdo (%d, %d)\n", mNef, nNef);
                    }
                    mNef = noA->m - mDist;
                    nNef = noA->n + nDist;
                    if (mNef <= n_linhas && mNef > 0 && nNef <= n_colunas && nNef > 0 && (nDist != 0 && mDist != 0))
                    {
                        inicioA = InserirAntena(inicioA, mNef, nNef, '#');
                        printf("Ponto nefasto no canto superior direito (%d, %d)\n", mNef, nNef);
                    }
                }
                // Mesma coluna
                else if (noA->n == noB->n)
                {
                    printf("Direção: Mesma coluna\n");
                    int mNef = noB->m + mDist;
                    int nNef = noA->n;
                    if (mNef <= n_linhas && mNef > 0 && mDist > 0)
                    {
                        inicioA = InserirAntena(inicioA, mNef, nNef, '#');
                        printf("Ponto nefasto abaixo (%d, %d)\n", mNef, nNef);
                    }
                    mNef = noA->m - mDist;
                    if (mNef <= n_linhas && mNef > 0 && mDist > 0)
                    {
                        inicioA = InserirAntena(inicioA, mNef, nNef, '#');
                        printf("Ponto nefasto acima (%d, %d)\n", mNef, nNef);
                    }
                }
                // Mesma linha
                else if (noA->m == noB->m)
                {
                    printf("Direção: Mesma linha\n");
                    int nNef = noB->n + nDist;
                    int mNef = noA->m;
                    if (nNef <= n_colunas && nNef > 0 && nDist > 0)
                    {
                        inicioA = InserirAntena(inicioA, mNef, nNef, '#');
                        printf("Ponto nefasto à direita (%d, %d)\n", mNef, nNef);
                    }
                    nNef = noA->n - nDist;
                    if (nNef <= n_colunas && nNef > 0 && nDist > 0)
                    {
                        inicioA = InserirAntena(inicioA, mNef, nNef, '#');
                        printf("Ponto nefasto à esquerda (%d, %d)\n", mNef, nNef);
                    }
                }
                noB = noB->seguinte;
            }
            noA = noA->seguinte;
        }
        aux = aux->seguinte;
    }
    return inicioA;
}

/**
 * @brief Remove todos os efeitos nefastos ('#') da lista de antenas.
 * 
 * Esta função percorre a lista de antenas e remove todas as ocorrências do 
 * caractere '#' que representam pontos nefastos. Atualiza os apontadores 
 * conforme necessário para manter a integridade da lista.
 * 
 * @param inicio Ponteiro para o início da lista de antenas.
 * @return Retorna a lista de antenas atualizada, sem os pontos nefastos.
 */
LL_antena RemoverNefasto(LL_antena inicio)
{
    LL_antena act = inicio, ant = NULL;

    // Verifica se a lista está vazia
    if (act == NULL) 
    {
        printf("\n> ERROR 12 : Não existem efeitos nefastos para remover");
        return inicio;
    }

    // Caso especial: remover nós no início da lista
    while (act != NULL && act->f == '#') 
    {
        LL_antena temp = act;
        act = act->seguinte; // Avança para o próximo nó antes de libertar
        free(temp);
    }
    
    inicio = act; // Atualiza o início da lista caso o primeiro nó tenha sido removido

    // Remover nós no meio ou no final da lista
    while (act != NULL) 
    {
        if (act->f == '#') 
        {
            LL_antena temp = act;
            ant->seguinte = act->seguinte; // Liga o nó anterior ao próximo nó
            act = act->seguinte; // Avança antes de libertar
            free(temp);
        } 
        else 
        {
            ant = act;  // Atualiza o ponteiro do nó anterior
            act = act->seguinte; // Avança para o próximo nó
        }
    }

    return inicio; // Retorna a lista atualizada sem os pontos nefastos
}
