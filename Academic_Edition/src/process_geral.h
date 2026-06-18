/**
 * @file    process_geral.h
 * @brief   Declarações das funções auxiliares gerais para manipulação de dados e estruturas no projeto.
 * 
 * @details Este ficheiro contém as declarações das funções auxiliares gerais utilizadas para realizar 
 *          operações comuns no projeto, como libertação de memória, manipulação de pilhas e filas, 
 *          remoção de nós de listas, entre outras funções de apoio.
 * 
 *          Estas funções não são específicas de nenhum módulo ou componente, sendo aplicáveis em várias 
 *          partes do sistema, com o objetivo de facilitar a manipulação e gestão de dados e estruturas.
 * 
 * @note    Ficheiros relacionados no mesmo diretório:
 *          - `estruturas.h`
 *          - `interface.c`
 *          - `interface.h`
 *          - `process_esp.c`
 *          - `process_esp.h`
 *          - `process_ficheiro.c`
 *          - `process_ficheiro.h`
 *          - `process_geral.c`
 *          - `process_geral.h`
 *
 *          Estes ficheiros constituem, em conjunto, os principais módulos do sistema.
 * 
 * @version 9
 * @author  Ivo Sá, nº 22604
 * @date    12/05/2025
*/





#ifndef PROCESS_GERAL_H
#define PROCESS_GERAL_H

#include "estruturas.h"
#include "interface.h"
#include "process_geral.h"
#include "process_ficheiro.h"
#include "process_esp.h"



// > LIBERTAR MEMÓRIA

/**
 * @brief Liberta a memória ocupada por uma lista de arestas.
 * @param coord Ponteiro para o início da lista de arestas.
 * @return NULL, após libertar toda a lista.
 */
LL_aresta LibertarAresta(LL_aresta coord);

/**
 * @brief Liberta a memória de uma lista de vértices e as suas respetivas arestas.
 * @param coord Ponteiro para o início da lista de vértices.
 * @return NULL, após libertar todos os vértices e arestas.
 */
LL_vertice LibertarVertice(LL_vertice coord);

/**
 * @brief Liberta a memória de uma lista de subgrafos, incluindo todos os vértices e arestas.
 * @param subgrafos Ponteiro para o início da lista de subgrafos.
 * @return NULL, após libertar toda a estrutura.
 */
LL_subgrafos LibertarSubgrafos(LL_subgrafos subgrafos);

/**
 * @brief Liberta a memória de uma lista de antenas.
 * @param antena Ponteiro para o início da lista de antenas.
 * @return NULL, após libertar toda a lista.
 */
LL_antena LibertarAntenas(LL_antena antena);

/**
 * @brief Liberta a memória de uma lista de segmentos.
 * @param seg Ponteiro para o início da lista de segmentos.
 * @return NULL, após libertar toda a lista.
 */
LL_segmento LibertarSegmentos(LL_segmento seg);

/**
 * @brief Liberta a memória de uma lista de letras.
 * @param letra Ponteiro para o início da lista de letras.
 * @return NULL, após libertar toda a lista.
 */
LL_letras LibertarLetras(LL_letras letra);

/**
 * @brief Liberta a memória de uma lista de interceções.
 * @param intercessao Ponteiro para o início da lista de interceções.
 * @return NULL, após libertar toda a lista.
 */
LL_Intercessoes LibertarIntercessao(LL_Intercessoes intercessao);

/**
 * @brief Liberta a memória associada à pilha.
 * @param caminho Estrutura PILHA a ser libertada.
 */
void limparPilha(PILHA caminho);



// > MANIPULAÇÃO DE PILHA (LL FILO)

/**
 * @brief Adiciona um novo elemento ao topo da pilha.
 * @param topo Ponteiro para o topo atual da pilha.
 * @param id Valor a ser inserido.
 * @return Novo topo da pilha.
 */
PILHA Push(PILHA topo, int id);

/**
 * @brief Remove o elemento do topo da pilha.
 * @param topo Ponteiro para o topo atual da pilha.
 * @param id Ponteiro onde será guardado o valor removido.
 * @return Novo topo da pilha.
 */
PILHA Pop(PILHA topo, int *id);



// > MANIPULAÇÃO DE FILA (LL FIFO)

/**
 * @brief Adiciona um novo elemento ao final da fila.
 * @param fila Ponteiro para a fila atual.
 * @param id Valor a ser inserido.
 * @return Ponteiro atualizado da fila.
 */
FILA Enqueue(FILA fila, int id);

/**
 * @brief Remove o elemento no início da fila.
 * @param fila Ponteiro para a fila atual.
 * @param id Ponteiro onde será guardado o valor removido.
 * @return Ponteiro atualizado da fila.
 */
FILA Dequeue(FILA fila, int* id);



// > MANIPULAÇÃO DE LL_INTERCEÇÕES

/**
 * @brief Dá reset ao estado "visto" de todos os vértices e arestas nos subgrafos.
 * @param inicioS Ponteiro para o início da lista de subgrafos.
 */
void ResetVistos(const LL_subgrafos inicioS);

/**
 * @brief Remove o nó atual da lista ligada de interceções.
 * @param listaInicio Ponteiro para o ponteiro do início da lista.
 * @param anterior Nó anterior ao atual.
 * @param atual Nó atual a ser removido.
 * @return Ponteiro para o próximo nó após a remoção.
 */
LL_Intercessoes RemoverNoAtual(LL_Intercessoes* listaInicio, LL_Intercessoes anterior, LL_Intercessoes atual);



// > FUNÇÕES DE RESET E VALIDAÇÃO

/**
 * @brief Dá reset ao estado "visto" de todos os vértices e arestas nos subgrafos.
 * @param inicioS Ponteiro para o início da lista de subgrafos.
 */
void ResetVistos(const LL_subgrafos inicioS);

/**
 * @brief Verifica se um vértice com determinado ID existe num subgrafo de uma dada frequência.
 * @param inicioS Ponteiro para o início da lista de subgrafos.
 * @param frequencia Frequência do subgrafo a ser pesquisado.
 * @param v ID do vértice a verificar.
 * @return Ponteiro para o subgrafo onde o vértice foi encontrado ou NULL.
 */
LL_subgrafos VerificarVertice(const LL_subgrafos inicioS, char frequencia, int v);



// > FUNÇÕES DE BUSCA

/**
 * @brief Procura um vértice por ID dentro de um subgrafo de frequência específica.
 * @param inicioS Ponteiro para o início da lista de subgrafos.
 * @param freq Frequência do subgrafo.
 * @param id ID do vértice a procurar.
 * @return Ponteiro para o vértice encontrado ou NULL.
 */
LL_vertice BuscarVerticePorId(LL_subgrafos inicioS, char freq, int id);

/**
 * @brief Procura um segmento por ID.
 * @param inicio Ponteiro para o início da lista de segmentos.
 * @param id ID do segmento a procurar.
 * @return Ponteiro para o segmento encontrado ou NULL.
 */
LL_segmento BuscarSegmentoPorID(LL_segmento inicio, int id);





#endif 


