/**
 * @file    interface.h
 * @brief   Declarações das funções de apresentação, recolha de informação e manipulação do terminal.
 *
 * @details Este ficheiro contém os protótipos das funções definidas em `interface.c`, responsáveis
 *          pela interação com o utilizador: apresentação de dados, recolha de decisões e verificação
 *          de requisitos mínimos.
 *
 * @note    Ficheiros relacionados (presentes na mesma pasta):
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
 *          Estes ficheiros constituem os principais módulos do programa.
 *
 * @version 1
 * @author  Ivo Sá, nº 22604
 * @date    12/05/2025
*/





#ifndef INTERFACE_H
#define INTERFACE_H

#include "estruturas.h"  ///< Definições de estruturas utilizadas no módulo



// > MANIPULAÇÃO DO TERMINAL

/**
 * @brief Limpa o terminal.
 */
void limparTerminal();



// > APRESENTAÇÃO DE DADOS (FIXOS)

/**
 * @brief Apresenta o ecrã de introdução do programa.
 */
void intro();

/**
 * @brief Apresenta o menu principal.
 */
void menu();

/**
 * @brief Mostra instruções para carregamento de ficheiros.
 */
void instrucoesFile();

/**
 * @brief Apresenta aviso de continuação ao utilizador.
 */
void AvisoAvancar();



// > APRESENTAÇÃO DE DADOS (VARIÁVEIS)

/**
 * @brief Apresenta as antenas sob a forma de matriz.
 * @param inicio Lista ligada de antenas.
 * @param n_linhas Número de linhas da matriz.
 * @param n_colunas Número de colunas da matriz.
 * @return Lista de antenas após apresentação.
 */
LL_antena ApresentaMatriz(LL_antena inicio, int n_linhas, int n_colunas);

/**
 * @brief Imprime todos os subgrafos e respetivas ligações.
 * @param inicioS Lista ligada de subgrafos.
 */
void ImprimirGrafo(const LL_subgrafos inicioS);

/**
 * @brief Imprime todos os subgrafos existentes.
 * @param inicioS Lista ligada de subgrafos.
 * @return Lista ligada de subgrafos (inalterada).
 */
LL_subgrafos ImprimirSubgrafos(const LL_subgrafos inicioS);

/**
 * @brief Imprime os vértices de um subgrafo correspondente à frequência fornecida.
 * @param inicioS Lista ligada de subgrafos.
 * @param frequencia Frequência do subgrafo a imprimir.
 * @return Lista ligada de subgrafos (inalterada).
 */
LL_subgrafos ImprimirVerticeSubgrafo(const LL_subgrafos inicioS, char frequencia);

/**
 * @brief Lista os elementos de uma pilha, de forma recursiva.
 * @param pilha Estrutura de pilha.
 */
void listarPilha(PILHA pilha);

/**
 * @brief Imprime todos os segmentos registados no sistema.
 * @param inicio Lista ligada de segmentos.
 */
void ImprimirSegmentos(LL_segmento inicio);

/**
 * @brief Imprime todas as interseções detetadas.
 * @param inicio Lista ligada de interseções.
 */
void ImprimirIntersecoes(LL_Intercessoes inicio);

/**
 * @brief Imprime informação detalhada de um segmento entre dois vértices.
 * @param seg Segmento a analisar.
 * @param v1 Primeiro vértice.
 * @param v2 Segundo vértice.
 */
void ImprimirInfoSegmento(LL_segmento seg, LL_vertice v1, LL_vertice v2);



/**
 * @brief Mostra as interseções entre segmentos de diferentes frequências.
 * @param[in] inicioI Ponteiro para o início da lista de interseções.
 * @param[in] inicioSg Ponteiro para o início da lista de segmentos.
 * @param[in] inicioS Ponteiro para o início da lista de subgrafos (estrutura onde os vértices estão organizados por frequência).
 */
void MostrarIntersecoes(LL_Intercessoes inicioI, LL_segmento inicioSg, LL_subgrafos inicioS);



// > FUNÇÕES DE RECEÇÃO DE INFORMAÇÃO

/**
 * @brief Lê um número inteiro do terminal.
 * @return Valor inteiro lido.
 */
int LeInteiro();

/**
 * @brief Lê um único carácter do terminal.
 * @return Carácter lido.
 */
char LeCaracter();

/**
 * @brief Solicita uma frequência válida ao utilizador.
 * @param inicioS Lista ligada de subgrafos.
 * @return Frequência escolhida.
 */
char ObterFrequencia(LL_subgrafos inicioS);

/**
 * @brief Solicita um vértice válido ao utilizador.
 * @param inicioS Lista ligada de subgrafos.
 * @param frequencia Frequência associada ao vértice.
 * @return Índice do vértice escolhido.
 */
int ObterVertice(LL_subgrafos inicioS, char frequencia);

/**
 * @brief Solicita ao utilizador o caminho para o ficheiro de entrada.
 * @param caminho Array onde será armazenado o caminho.
 */
void obterCaminhoFicheiro(char* caminho);



// > SAÍDAS DO SISTEMA

/**
 * @brief Informa falha crítica de alocação e termina o programa, libertando memória.
 * @param inicioA Lista ligada de antenas.
 * @param inicioS Lista ligada de subgrafos.
 */
void FalhaMalloc(LL_antena inicioA, LL_subgrafos inicioS);

/**
 * @brief Informa que o programa terminou com sucesso.
 */
void SaidaSucesso();

#endif 
