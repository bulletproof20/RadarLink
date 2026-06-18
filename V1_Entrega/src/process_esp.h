/**
 * @file    process_esp.h
 * @brief   Declarações das funções responsáveis pela lógica específica do sistema.
 *
 * @details Este ficheiro contém os protótipos das funções que:
 *          - Realizam travessias em profundidade (DFS) e em largura (BFS);
 *          - Verificam todos os segmentos existentes (apenas válidos entre dois vértices da mesma frequência);
 *          - Determinam todas as interseções de arestas entre frequências diferentes;
 *          - Verificam e limpam interseções inválidas, removendo nós da lista de interseções onde os segmentos não se cruzam de fato no ponto calculado.
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
 * @version 3
 * @author  Ivo Sá, nº 22604
 * @date    12/05/2025
*/




#ifndef PROCESS_ESP_H
#define PROCESS_ESP_H

// > FUNÇÕES PARA TRAVESSIAS

/**
 * @brief Função de travessia em largura (BFS).
 *
 * @param[in] inicioS Lista ligada de subgrafos, que representa a estrutura do grafo.
 * @param[in] frequencia Caracter que define a frequência dos segmentos a considerar na travessia.
 * @param[in] id_inicial ID do vértice inicial para a travessia.
 * 
 * @return Lista ligada de subgrafos com os vértices visitados durante a travessia.
 */
LL_subgrafos TravessiaLargura(const LL_subgrafos inicioS, char frequencia, int id_inicial);

/**
 * @brief Função de travessia em profundidade (DFS).
 *
 * @param[in] inicioS Lista ligada de subgrafos, que representa a estrutura do grafo.
 * @param[in] frequencia Caracter que define a frequência dos segmentos a considerar na travessia.
 * @param[in] id_inicial ID do vértice inicial para a travessia.
 * 
 * @return Lista ligada de subgrafos com os vértices visitados durante a travessia.
 */
LL_subgrafos TravessiaProfundidade(const LL_subgrafos inicioS, char frequencia, int id_inicial);


// > FUNÇÕES PARA DETERMINAR CAMINHOS POSSÍVEIS ENTRE 2 VÉRTICES

/**
 * @brief Função de busca DFS para determinar todos os caminhos entre dois vértices.
 *
 * @param[in] sub Lista ligada de subgrafos.
 * @param[in] atual Vértice atual na busca.
 * @param[in] destino ID do vértice destino.
 * @param[in] caminho Pilha que armazena o caminho durante a busca.
 */
void DFS_Caminhos(LL_subgrafos sub, LL_vertice atual, int destino, PILHA caminho);

/**
 * @brief Função para calcular todos os caminhos entre dois vértices.
 *
 * @param[in] inicioS Lista ligada de subgrafos.
 * @param[in] frequencia Frequência dos segmentos a considerar.
 * @param[in] origem ID do vértice de origem.
 * @param[in] destino ID do vértice destino.
 */
void CaminhosEntreVertices(LL_subgrafos inicioS, char frequencia, int origem, int destino);


// > FUNÇÕES PARA VERIFICAR QUE SEGMENTOS DE DIFERENTES FREQUENCIAS SE CRUZAM

// -> CRIAR TODOS OS SEGMENTOS DO GRAFO

/**
 * @brief Função para gerar todos os segmentos do grafo.
 *
 * @param[in] inicioS Lista de subgrafos.
 * @param[in] inicioSegmentos Lista de segmentos já existentes.
 * 
 * @return Lista de segmentos gerados.
 */
LL_segmento GerarSegmentos(LL_subgrafos inicioS, LL_segmento inicioSegmentos);

/**
 * @brief Função para criar um segmento entre dois vértices.
 *
 * @param[in] sub Lista de subgrafos.
 * @param[in] frequencia Frequência dos segmentos a considerar.
 * @param[in] v1 ID do primeiro vértice.
 * @param[in] v2 ID do segundo vértice.
 * @param[in] id ID do segmento.
 * 
 * @return Segmento criado.
 */
LL_segmento CriarSegmento(LL_subgrafos sub, char frequencia, int v1, int v2, int id);


// -> CRIAR TODOS PARES DE SEGMENTOS DO GRAFO

/**
 * @brief Função para verificar se um par de interseções já existe.
 *
 * @param[in] inicio Lista ligada de interseções.
 * @param[in] id1 ID do primeiro segmento.
 * @param[in] id2 ID do segundo segmento.
 * 
 * @return 1 se o par de interseções existe, 0 caso contrário.
 */
int ParExiste(LL_Intercessoes inicio, int id1, int id2);

/**
 * @brief Função para adicionar uma interseção entre dois segmentos.
 *
 * @param[in] inicio Lista ligada de interseções.
 * @param[in] id1 ID do primeiro segmento.
 * @param[in] id2 ID do segundo segmento.
 * 
 * @return Lista de interseções com a nova interseção adicionada.
 */
LL_Intercessoes AdicionarIntersecao(LL_Intercessoes inicio, int id1, int id2);

/**
 * @brief Função para gerar todas as interseções entre segmentos.
 *
 * @param[in] segmentos Lista de segmentos.
 * 
 * @return Lista de interseções geradas entre os segmentos.
 */
LL_Intercessoes GerarIntersecoes(LL_segmento segmentos);


// -> DETERMINA PONTO DE INTERCESSÃO DA RETA

/**
 * @brief Função para calcular a equação da reta associada a um segmento.
 *
 * @param[in] inicioS Lista de subgrafos.
 * @param[in] seg Segmento para o qual a equação da reta será calculada.
 * 
 * @return Equação da reta associada ao segmento.
 */
LL_EquacaoReta CalcularEquacaoReta(LL_subgrafos inicioS, LL_segmento seg);

/**
 * @brief Função para determinar a interseção entre duas retas.
 *
 * @param[in] r1 Equação da primeira reta.
 * @param[in] r2 Equação da segunda reta.
 * 
 * @return Ponto de interseção entre as duas retas.
 */
LL_segmento DeterminarIntersecao(LL_EquacaoReta r1, LL_EquacaoReta r2);


// -> VERIFICAÇÃO DE INTERSEÇÃO ENTRE SEGMENTOS

/**
 * @brief Função para verificar se um ponto está dentro de um intervalo definido por dois vértices.
 *
 * @param[in] v1 Primeiro vértice.
 * @param[in] v2 Segundo vértice.
 * @param[in] linha Linha do ponto a verificar.
 * @param[in] coluna Coluna do ponto a verificar.
 * 
 * @return 1 se o ponto está dentro do intervalo, 0 caso contrário.
 */
int PontoDentroDoSegmento(LL_vertice v1, LL_vertice v2, int linha, int coluna);

/**
 * @brief Função que verifica se dois intervalos (definidos por valores mínimo e máximo) se sobrepõem.
 *
 * @param[in] min1 Valor mínimo do primeiro intervalo.
 * @param[in] max1 Valor máximo do primeiro intervalo.
 * @param[in] min2 Valor mínimo do segundo intervalo.
 * @param[in] max2 Valor máximo do segundo intervalo.
 * 
 * @return 1 se os intervalos se sobrepõem, 0 caso contrário.
 */
int IntervalosSobrepostos(int min1, int max1, int min2, int max2);

/**
 * @brief Função para verificar interseção entre dois segmentos.
 *
 * @param[in] inicioS Lista de subgrafos.
 * @param[in] inicioSg Lista de segmentos.
 * @param[in] id1 ID do primeiro segmento.
 * @param[in] id2 ID do segundo segmento.
 * @param[in] linhaInt Linha do ponto de interseção.
 * @param[in] colunaInt Coluna do ponto de interseção.
 * 
 * @return Segmento resultante da interseção verificada.
 */
LL_segmento VerificarIntersecao(LL_subgrafos inicioS, LL_segmento inicioSg, int id1, int id2, int linhaInt, int colunaInt);


// -> VERIFICAÇÃO E LIMPEZA DE INTERSEÇÕES INVÁLIDAS

/**
 * @brief Função para verificar e limpar interseções inválidas.
 *
 * @param[in] listaInter Lista de interseções detectadas.
 * @param[in] inicioSg Lista de segmentos.
 * @param[in] inicioS Lista de subgrafos.
 * 
 * @return Lista de interseções atualizada com apenas interseções válidas.
 */
LL_Intercessoes MostrarPontosIntersecao(LL_Intercessoes listaInter, LL_segmento inicioSg, LL_subgrafos inicioS);

#endif
