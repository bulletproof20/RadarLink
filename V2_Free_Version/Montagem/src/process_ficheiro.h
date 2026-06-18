/**
 * @file    process_ficheiro.h
 * @brief   Declarações das funções e estruturas utilizadas para processar e validar ficheiros de texto 
 *          relacionados com a gestão de antenas numa matriz bidimensional.
 * 
 * @details Este ficheiro contém as declarações das funções responsáveis pela leitura, validação e manipulação 
 *          de dados extraídos de ficheiros de texto. O foco principal é a gestão de antenas representadas numa 
 *          matriz bidimensional, incluindo a inserção, remoção e validação de dados.
 * 
 *          Além disso, este ficheiro também inclui as funções necessárias para a conversão da lista ligada de 
 *          antenas para um grafo, com a criação de subgrafos, vértices e arestas, permitindo uma análise e 
 *          manipulação estruturada dos dados.
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
 * @version 7
 * @author  Ivo Sá, nº 22604
 * @date    12/05/2025
 */


#ifndef PROCESS_FICHEIRO_H
#define PROCESS_FICHEIRO_H

#include <stdio.h> 
#include "estruturas.h" 
#include "interface.h" 
#include "process_geral.h"  
#include "process_ficheiro.h"  

// > MANIPULAÇÃO DE DADOS DO FICHEIRO

/**
 * @brief Inserir uma antena na lista de antenas.
 * 
 * @param inicio A lista de antenas onde a nova antena será inserida.
 * @param linha A linha onde a antena está localizada na matriz.
 * @param coluna A coluna onde a antena está localizada na matriz.
 * @param frequencia A frequência associada à antena.
 * @return LL_antena A nova lista com a antena inserida.
 */
LL_antena InserirAntena(LL_antena inicio, int linha, int coluna, char frequencia);  

/**
 * @brief Remover uma antena da lista de antenas.
 * 
 * @param inicio A lista de antenas onde a antena será removida.
 * @param linha A linha onde a antena a ser removida está localizada.
 * @param coluna A coluna onde a antena a ser removida está localizada.
 * @return LL_antena A nova lista de antenas após a remoção.
 */
LL_antena RemoverAntena(LL_antena inicio, int linha, int coluna);  

/**
 * @brief Verificar se o número de linhas e colunas no ficheiro é válido.
 * 
 * @param linha O número de linhas do ficheiro.
 * @param max_coluna O número máximo de colunas permitidas no ficheiro.
 * @return 1 se a matriz for válida, 0 caso contrário.
 */
int verificarValidade(int linha, int max_coluna);  

/**
 * @brief Processar erro no ficheiro e decidir se o programa deve sair ou tentar novamente.
 * 
 * @param sair Indicador de se o programa deve sair (1) ou não (0).
 * @param caminho O caminho do ficheiro onde ocorreu o erro.
 * @return Código de erro ou sucesso conforme o tratamento.
 */
int ErroFicheiro(int sair, const char caminho[256]);  

/**
 * @brief Criar um nó temporário para armazenar o tamanho da matriz de antenas.
 * 
 * @param inicioA Lista de antenas.
 * @param linha O número de linhas da matriz.
 * @param max_coluna O número máximo de colunas.
 * @return LL_antena O nó provisório criado.
 */
LL_antena criarNoProvisorio(LL_antena inicioA, int linha, int max_coluna);  

/**
 * @brief Ler uma linha do ficheiro e armazenar os caracteres numa fila.
 * 
 * @param ficheiro Ponteiro para o ficheiro a ser lido.
 * @return LL_letras Lista ligada de caracteres representando a linha lida.
 */
LL_letras LerLinhaParaFila(FILE* ficheiro);  

/**
 * @brief Processar o ficheiro de texto, identificar antenas e validar dados.
 * 
 * @param ficheiro Ponteiro para o ficheiro a ser processado.
 * @param inicioA A lista de antenas onde os dados serão inseridos.
 * @return LL_antena Lista de antenas processada.
 */
LL_antena processarFicheiro(FILE* ficheiro, LL_antena inicioA);  

/**
 * @brief Função principal para abrir e processar o ficheiro, identificando antenas.
 * 
 * @param inicioA Lista de antenas onde os dados do ficheiro serão inseridos.
 * @return LL_antena Lista de antenas após o processamento.
 */
LL_antena lerFicheiro(LL_antena inicioA);  

// > CONVERSÃO DA LLG DE ANTENAS PARA UM GRAFO

/**
 * @brief Criar um grafo a partir das antenas.
 * 
 * @param inicioA Lista de antenas.
 * @param inicioS Lista de subgrafos onde o grafo será criado.
 * @return LL_subgrafos Lista de subgrafos com o grafo criado.
 */
LL_subgrafos CriarGrafo(LL_antena inicioA, LL_subgrafos inicioS);  

/**
 * @brief Criar subgrafos a partir das antenas.
 * 
 * @param inicioA Lista de antenas.
 * @param inicioS Lista de subgrafos onde os subgrafos serão criados.
 * @return LL_subgrafos Lista de subgrafos com os subgrafos criados.
 */
LL_subgrafos CriarSubgrafos(LL_antena inicioA, LL_subgrafos inicioS);  

/**
 * @brief Criar ou encontrar um subgrafo com uma determinada frequência.
 * 
 * @param inicioS Lista de subgrafos.
 * @param frequencia Frequência do subgrafo a ser criado ou encontrado.
 * @return LL_subgrafos O subgrafo encontrado ou criado.
 */
LL_subgrafos CriarOuEncontrarSubgrafo(LL_subgrafos inicioS, char frequencia);  

/**
 * @brief Criar um vértice dentro de um subgrafo.
 * 
 * @param inicioS Lista de subgrafos.
 * @param antena A antena que será associada ao vértice.
 * @return LL_subgrafos Lista de subgrafos com o novo vértice.
 */
LL_subgrafos CriarVerticeNoSubgrafo(LL_subgrafos inicioS, LL_antena antena);  

/**
 * @brief Inserir um vértice de forma ordenada na lista de vértices de um subgrafo.
 * 
 * @param lista_vertice Lista de vértices onde o novo vértice será inserido.
 * @param novo_vertice O vértice a ser inserido.
 * @return LL_vertice A lista de vértices com o novo vértice inserido.
 */
LL_vertice InserirVerticeOrdenado(LL_vertice lista_vertice, LL_vertice novo_vertice);  

/**
 * @brief Atribuir IDs aos vértices dos subgrafos conforme a ordem em que foram inseridos.
 * 
 * @param inicioS Lista de subgrafos.
 * @return LL_subgrafos Lista de subgrafos com IDs atribuídos aos vértices.
 */
LL_subgrafos AtribuirIdsVertice(LL_subgrafos inicioS);  

/**
 * @brief Criar arestas completas entre todos os vértices de cada subgrafo.
 * 
 * @param inicioS Lista de subgrafos.
 * @return LL_subgrafos Lista de subgrafos com as arestas criadas.
 */
LL_subgrafos CriarArestasSubgrafosCompleto(LL_subgrafos inicioS);  

#endif // PROCESS_FICHEIRO_H
