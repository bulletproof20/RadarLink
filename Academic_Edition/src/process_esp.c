/**
 * @file    process_esp.c
 * @brief   Responsável pela lógica específica para determinados objetivos do sistema.
 *
 * @details Este ficheiro contém funções lógicas que:
 *          - Realizam travessias em profundidade (DFS) e em largura (BFS);
 *          - Verificam todos os segmentos existentes (apenas válidos entre dois vértices da mesma frequência);
 *          - Determinam todas as interseções de arestas entre frequências diferentes.
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


#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"
#include "interface.h"
#include "process_geral.h"
#include "process_ficheiro.h"
#include "process_esp.h"





// > FUNÇÕES PARA TRAVESSIAS

/**
 * @brief   Realiza uma travessia em profundidade (DFS) num subgrafo com determinada frequência, a partir de um id de vertice.
 *
 * @details A função percorre o subgrafo correspondente à frequência indicada, a partir de um vértice inicial pré-selecionado pelo user,
 *          imprimindo cada caminho seguido até ao seu fim. Apenas é seguido um caminho de cada vez, simulando
 *          a lógica de uma pilha (LIFO).
 *
 * @param[in]  inicioS     Lista ligada de subgrafos existentes.
 * @param[in]  frequencia  Frequência associada ao subgrafo a ser percorrido.
 * @param[in]  id_inicial  ID do vértice por onde começa a travessia.
 *
 * @return Ponteiro para o início da lista de subgrafos (inalterado), ou NULL caso o subgrafo ou vértice inicial não exista.
 */
LL_subgrafos TravessiaProfundidade(const LL_subgrafos inicioS, char frequencia, int id_inicial) {
    ResetVistos(inicioS);  // Reseta os vértices e arestas para 'não visitados'
    LL_subgrafos sub = inicioS;

    // Encontra o subgrafo com a frequência desejada
    while (sub && sub->f != frequencia) sub = sub->seguinte;
    if (!sub) return NULL;  // Se não encontrar o subgrafo, retorna NULL

    LL_vertice inicial = sub->lista_vertice;
    // Encontra o vértice inicial pelo id
    while (inicial && inicial->id != id_inicial) inicial = inicial->seguinte;
    if (!inicial) return NULL;  // Se não encontrar o vértice inicial, retorna NULL

    PILHA pilha = NULL;
    pilha = Push(pilha, inicial->id);  // Coloca o vértice inicial na pilha
    inicial->visto = 1;  // Marca o vértice como visitado

    // Percorre o grafo em profundidade (DFS)
    while (pilha) {
        int id_atual;
        pilha = Pop(pilha, &id_atual);  // Retira o topo da pilha

        LL_vertice atual = sub->lista_vertice;
        // Encontra o vértice atual pelo id
        while (atual && atual->id != id_atual) atual = atual->seguinte;
        if (!atual) continue;  // Se o vértice não for encontrado, continua para o próximo

        int encontrou_novo = 0;
        LL_aresta a = atual->lista_aresta;

        // Percorre as arestas do vértice atual
        while (a) {
            LL_vertice destino = sub->lista_vertice;
            // Encontra o vértice destino pela aresta
            while (destino && destino->id != a->id) destino = destino->seguinte;

            if (destino && !destino->visto) {  // Se o destino não foi visitado
                destino->visto = 1;  // Marca o destino como visitado
                printf("%d->%d\n", atual->id, destino->id);  // Imprime a aresta

                pilha = Push(pilha, atual->id);  // Coloca o vértice atual na pilha (ponto de retorno)
                pilha = Push(pilha, destino->id);  // Coloca o vértice destino na pilha (próximo a explorar)
                encontrou_novo = 1;  // Marca que encontrou um novo vértice
                break;  // Importante: só seguimos um caminho por vez
            }

            a = a->seguinte;  // Avança para a próxima aresta
        }

        // Se não encontrou um novo vértice, imprime "NULL" (fim de um caminho)
        if (!encontrou_novo) {
            printf("%d->NULL\n", atual->id);
        }
    }

    return inicioS;  // Retorna o subgrafo original
}


/**
 * @brief   Realiza uma travessia em largura (BFS) num subgrafo com determinada frequência, a partir de um id de vertice.
 *
 * @details A função percorre o subgrafo correspondente à frequência indicada, a partir de um vértice inicialpré-selecionado pelo user,
 *          imprimindo todos os vértices adjacentes em cada nível antes de avançar para os seguintes.
 *          Utiliza uma fila (FIFO) para gerir os vértices por visitar.
 *
 * @param[in]  inicioS     Lista ligada de subgrafos existentes.
 * @param[in]  frequencia  Frequência associada ao subgrafo a ser percorrido.
 * @param[in]  id_inicial  ID do vértice por onde começa a travessia.
 *
 * @return Ponteiro para o início da lista de subgrafos (inalterado), ou NULL caso o subgrafo ou vértice inicial não exista.
 */
LL_subgrafos TravessiaLargura(const LL_subgrafos inicioS, char frequencia, int id_inicial) {
    ResetVistos(inicioS);  // Reseta os vértices e arestas para 'não visitados'
    LL_subgrafos sub = inicioS;

    // Encontra o subgrafo com a frequência desejada
    while (sub && sub->f != frequencia) sub = sub->seguinte;
    if (!sub) return NULL;  // Se não encontrar o subgrafo, retorna NULL

    LL_vertice v = sub->lista_vertice;
    // Encontra o vértice inicial pelo id
    while (v && v->id != id_inicial) v = v->seguinte;
    if (!v) return NULL;  // Se não encontrar o vértice inicial, retorna NULL

    FILA fila = NULL;
    fila = Enqueue(fila, v->id);  // Coloca o vértice inicial na fila
    v->visto = 1;  // Marca o vértice como visitado
 
    // Percorre o grafo em largura (BFS)
    while (fila) {
        int atual_id;
        fila = Dequeue(fila, &atual_id);  // Retira o primeiro vértice da fila

        // Encontra o vértice atual pelo id
        LL_vertice atual = sub->lista_vertice;
        while (atual && atual->id != atual_id) atual = atual->seguinte;
        if (!atual) continue;  // Se o vértice não for encontrado, continua para o próximo

        // Imprime o caminho para cada vértice
        printf("%d ->", atual->id);

        LL_aresta a = atual->lista_aresta;
        int primeiro = 1;

        // Percorre as arestas do vértice atual
        while (a) {
            LL_vertice destino = sub->lista_vertice;
            // Encontra o vértice destino pela aresta
            while (destino && destino->id != a->id) destino = destino->seguinte;

            if (destino && !destino->visto) {  // Se o destino não foi visitado
                if (primeiro) {
                    printf(" %d", destino->id);  // Imprime o primeiro destino
                    primeiro = 0;  // Marca que já imprimiu o primeiro
                } else {
                    printf(" -> %d", destino->id);  // Imprime os demais destinos
                }
                destino->visto = 1;  // Marca o destino como visitado
                fila = Enqueue(fila, destino->id);  // Coloca o destino na fila
            }

            a = a->seguinte;  // Avança para a próxima aresta
        }

        // Se não houver adjacentes, adiciona o "NULL" ao caminho
        if (primeiro) {
            printf(" NULL");
        }
        
        printf("\n");  // Quebra de linha para o próximo vértice
    }

    return inicioS;  // Retorna o subgrafo original
}




// > FUNÇÕES PARA DETERMINAR CAMINHOS POSSÍVEIS ENTRE 2 VÉRTICES

/**
 * @brief Realiza uma busca em profundidade (DFS) com backtracking para encontrar todos os caminhos possíveis entre dois vértices.
 *
 * Esta função marca os vértices visitados e utiliza uma pilha para armazenar o caminho atual. 
 * Quando o destino é atingido, o caminho é listado. A função é recursiva e explora todos os vizinhos ainda não visitados.
 * 
 * @param sub Ponteiro para a lista de subgrafos, onde se encontra o grafo atual.
 * @param atual Ponteiro para o vértice atual em análise.
 * @param destino Identificador do vértice de destino.
 * @param caminho Pilha com os identificadores dos vértices visitados até ao momento.
 */
void DFS_Caminhos(LL_subgrafos sub, LL_vertice atual, int destino, PILHA caminho) {
    // Marcar o vértice atual como visitado e adicioná-lo à pilha de caminho
    atual->visto = 1;  // O vértice atual foi visitado
    caminho = Push(caminho, atual->id);  // Adiciona o vértice atual à pilha de caminho

    // Verificar se o vértice atual é o destino
    if (atual->id == destino) {
        listarPilha(caminho);  // Se chegou ao destino, listar o caminho encontrado
        printf("\b\b\b  \n"); // Esconde os últimos 3 caracteres para não alterar o formato da lista
    } else {
        // Explorar os vizinhos do vértice atual
        LL_aresta a = atual->lista_aresta;  // Lista de arestas conectadas ao vértice atual
        while (a) {
            // Percorre a lista de arestas para encontrar os vizinhos
            LL_vertice vizinho = sub->lista_vertice;
            while (vizinho && vizinho->id != a->id) vizinho = vizinho->seguinte;  // Encontrar o vértice vizinho pela aresta

            // Se o vizinho existe e ainda não foi visitado, continuar a busca DFS
            if (vizinho && !vizinho->visto) {
                DFS_Caminhos(sub, vizinho, destino, caminho);  // Chamada recursiva para explorar o vizinho
            }
            
            a = a->seguinte;  // Passar para a próxima aresta
        }
    }

    // "Backtrack": Desmarcar o vértice atual como não visitado e removê-lo da pilha
    atual->visto = 0;  // Desmarca o vértice como visitado
    int lixo;  // Variável temporária. isto é só para não apresentar NULL, pq n preciso do id
    caminho = Pop(caminho, &lixo);  // Remove o vértice atual da pilha
}


/**
 * @brief Inicia o processo de procura de todos os caminhos entre dois vértices num subgrafo com uma dada frequência.
 *
 * Esta função prepara o ambiente de execução, realizando o reset dos vértices visitados, 
 * selecionando o subgrafo correto com base na frequência e identificando o vértice de origem.
 * Depois, inicia a DFS para determinar todos os caminhos entre os dois vértices.
 * 
 * @param inicioS Ponteiro para o início da lista de subgrafos.
 * @param frequencia Carácter que representa a frequência do subgrafo onde será feita a busca.
 * @param origem Identificador do vértice de origem.
 * @param destino Identificador do vértice de destino.
 */
void CaminhosEntreVertices(LL_subgrafos inicioS, char frequencia, int origem, int destino) {
    // Resetar os vistos de todos os vértices antes de iniciar a busca
    ResetVistos(inicioS);

    // Procurar o subgrafo que possui a frequência correta
    LL_subgrafos sub = inicioS;
    while (sub && sub->f != frequencia) sub = sub->seguinte;  // Encontra o subgrafo pela frequência
    if (!sub) return;  // Se não encontrar o subgrafo, retorna sem fazer nada

    // Procurar o vértice de origem
    LL_vertice v_origem = sub->lista_vertice;
    while (v_origem && v_origem->id != origem) v_origem = v_origem->seguinte;  // Encontra o vértice de origem
    if (!v_origem) return;  // Se o vértice de origem não existir, retorna sem fazer nada

    // PILHA para armazenar o caminho atual durante a busca
    PILHA caminho = NULL;

    // Chama a função recursiva para encontrar os caminhos entre a origem e o destino
    DFS_Caminhos(sub, v_origem, destino, caminho);
    limparPilha(caminho);
}





// > FUNÇÕES PARA VERIFICAR QUE SEGMENTOS DE DIFERENTES FREQUENCIAS SE CRUZAM

// >> CRIAR TODOS OS SEGMENTOS DO GRAFO

/**
 * @brief Cria um novo segmento com os dados fornecidos: ID, frequência e vértices associados.
 *
 * Esta função aloca memória para um novo segmento, atribui a frequência, vértices (V1 e V2), 
 * e ID fornecidos. O segmento é inicializado e retornado ao chamador.
 * 
 * @param sub Ponteiro para o subgrafo onde o segmento será criado.
 * @param frequencia Frequência associada ao segmento.
 * @param v1 Identificador do primeiro vértice do segmento.
 * @param v2 Identificador do segundo vértice do segmento.
 * @param id ID único para o segmento.
 * 
 * @return LL_segmento Ponteiro para o novo segmento criado.
 */
LL_segmento CriarSegmento(LL_subgrafos sub, char frequencia, int v1, int v2, int id) {
    // Aloca memória para um novo segmento
    LL_segmento novo_segmento = malloc(sizeof(struct SegmentoReta));
    
    // Verifica se a alocação foi bem-sucedida
    if (!novo_segmento) FalhaMalloc(NULL, sub);

    // Define o ID, frequência e vértices do novo segmento
    novo_segmento->id = id;
    novo_segmento->freq = frequencia;
    novo_segmento->V1 = v1;
    novo_segmento->V2 = v2;

    // O próximo segmento é NULL (não há mais segmentos após este)
    novo_segmento->seguinte = NULL;

    // Retorna o novo segmento criado
    return novo_segmento;
}

/**
 * @brief Gera segmentos de todos os subgrafos e os adiciona a uma lista.
 *
 * Esta função percorre todos os subgrafos, seus vértices e arestas para criar segmentos entre 
 * os vértices conectados. Cada segmento é atribuído um ID único. Os segmentos são gerados 
 * somente para arestas onde o vértice de origem (V1) tem um ID menor que o vértice de destino (V2),
 * para evitar a criação de segmentos duplicados.
 * 
 * @param inicioS Ponteiro para o primeiro subgrafo na lista.
 * @param inicioSegmentos Ponteiro para a lista de segmentos, que será preenchida.
 * 
 * @return LL_segmento Ponteiro para a lista de segmentos gerados.
 */
LL_segmento GerarSegmentos(LL_subgrafos inicioS, LL_segmento inicioSegmentos) {
    LL_subgrafos sub = inicioS;
    int id_counter = 1; // Contador de IDs, começa em 1 (pode ser alterado para 0 se preferir)

    // Percorrer todos os subgrafos
    while (sub != NULL) {
        LL_vertice v = sub->lista_vertice;

        // Percorrer todos os vértices do subgrafo
        while (v != NULL) {
            LL_aresta a = v->lista_aresta;

            // Percorrer todas as arestas do vértice
            while (a != NULL) {
                // Adiciona segmento somente se V1 < V2 para evitar duplicados (V2<->V1)
                if (v->id < a->id) {
                    // Cria um novo segmento
                    LL_segmento novo = CriarSegmento(sub, sub->f, v->id, a->id, id_counter++);

                    // Se não houver segmentos, inicializa o primeiro
                    if (inicioSegmentos == NULL) {
                        inicioSegmentos = novo;
                    } else {
                        // Caso contrário, adiciona o novo segmento ao final da lista
                        LL_segmento temp = inicioSegmentos;
                        while (temp->seguinte != NULL) temp = temp->seguinte;
                        temp->seguinte = novo;
                    }
                }
                a = a->seguinte;
            }

            v = v->seguinte;
        }

        sub = sub->seguinte;
    }

    // Retorna a lista de segmentos gerados
    return inicioSegmentos;
}



// >> CRIAR TODOS PARES DE SEGMENTOS DO GRAFO

/**
 * @brief Verifica se um par de segmentos (id1, id2) ou (id2, id1) já existe na lista de interseções.
 *
 * Esta função percorre a lista de interseções e verifica se algum par de segmentos (id1, id2) 
 * ou (id2, id1) já foi registrado. Se o par existir, retorna 1, caso contrário, retorna 0.
 * 
 * @param inicio Ponteiro para o primeiro nó da lista de interseções.
 * @param id1 ID do primeiro segmento.
 * @param id2 ID do segundo segmento.
 * 
 * @return int Retorna 1 se o par de segmentos já existe, ou 0 caso contrário.
 */
int ParExiste(LL_Intercessoes inicio, int id1, int id2) {
    LL_Intercessoes atual = inicio;

    // Percorrer a lista de interseções
    while (atual != NULL) {
        // Verifica se o par (id1, id2) ou (id2, id1) já existe
        if ((atual->s1 == id1 && atual->s2 == id2) || (atual->s1 == id2 && atual->s2 == id1)) {
            return 1; // Já existe
        }
        atual = atual->seguinte;
    }

    // Se não encontrar, retorna 0 (não existe)
    return 0;
}

/**
 * @brief Cria e adiciona uma nova interseção à lista de interseções.
 *
 * Esta função aloca memória para uma nova interseção, atribui os IDs dos segmentos que 
 * estão se cruzando e adiciona o nó na lista de interseções. Se a lista estiver vazia, 
 * o novo nó é retornado como a cabeça da lista. Caso contrário, o nó é adicionado ao 
 * final da lista.
 * 
 * @param inicio Ponteiro para o primeiro nó da lista de interseções.
 * @param id1 ID do primeiro segmento da interseção.
 * @param id2 ID do segundo segmento da interseção.
 * 
 * @return LL_Intercessoes Ponteiro para a lista de interseções atualizada.
 */
LL_Intercessoes AdicionarIntersecao(LL_Intercessoes inicio, int id1, int id2) {
    // Aloca memória para uma nova interseção
    LL_Intercessoes novo = malloc(sizeof(struct Intercessao));
    if (!novo) {
        printf("Erro: Falha de memória ao criar interseção.\n");
        exit(EXIT_FAILURE); // Se falhar, encerra o programa
    }

    // Atribui os IDs aos segmentos da interseção
    novo->s1 = id1;
    novo->s2 = id2;
    novo->seguinte = NULL;

    // Se a lista estiver vazia, retorna o novo nó
    if (inicio == NULL) return novo;

    // Caso contrário, percorre até o fim da lista e adiciona o novo nó
    LL_Intercessoes temp = inicio;
    while (temp->seguinte != NULL) temp = temp->seguinte;
    temp->seguinte = novo;

    return inicio;
}

/**
 * @brief Gera todos os pares únicos de segmentos com frequências diferentes.
 *
 * Esta função percorre todos os segmentos e compara cada par de segmentos subsequentes. 
 * Se os segmentos tiverem frequências diferentes e o par ainda não tiver sido registrado 
 * nas interseções, a interseção é adicionada à lista. A lista final de interseções 
 * com pares únicos de segmentos é retornada.
 * 
 * @param segmentos Ponteiro para a lista de segmentos do grafo.
 * 
 * @return LL_Intercessoes Ponteiro para a lista de interseções geradas.
 */
LL_Intercessoes GerarIntersecoes(LL_segmento segmentos) {
    LL_Intercessoes listaInter = NULL;
    LL_segmento s1 = segmentos;

    // Percorrer todos os segmentos
    while (s1 != NULL) {
        LL_segmento s2 = s1->seguinte;

        // Comparar cada segmento com os seguintes
        while (s2 != NULL) {
            // Se os segmentos tiverem frequências diferentes e o par ainda não existir
            if (s1->freq != s2->freq && !ParExiste(listaInter, s1->id, s2->id)) {
                // Adiciona a interseção à lista de interseções
                listaInter = AdicionarIntersecao(listaInter, s1->id, s2->id);
            }
            s2 = s2->seguinte;
        }
        s1 = s1->seguinte;
    }

    // Retorna a lista de interseções geradas
    return listaInter;
}



// >> DETERMINA PONTO DE INTERCESSÃO DA RETA

/**
 * @brief Calcula a equação da reta entre dois vértices de um subgrafo.
 *
 * Esta função encontra os vértices correspondentes ao segmento de reta e calcula
 * a equação da reta entre eles, levando em consideração se a reta é vertical
 * ou não. Se a reta for vertical, a equação será indefinida.
 *
 * @param inicioS Lista de subgrafos que contém os vértices e suas respectivas frequências.
 * @param seg Segmento de reta para o qual a equação será calculada.
 * @return A equação da reta entre os dois vértices, ou uma equação indefinida.
 */
LL_EquacaoReta CalcularEquacaoReta(LL_subgrafos inicioS, LL_segmento seg) {
    // Aloca memória para a estrutura que vai representar a equação da reta
    LL_EquacaoReta eq = (LL_EquacaoReta)malloc(sizeof(struct EquacaoReta));
    eq->indefinida = 0; // Inicializa como reta definida (não vertical)
 
    // Procura o subgrafo com a frequência que corresponde ao segmento
    LL_subgrafos sub = inicioS;
    while (sub && sub->f != seg->freq)
        sub = sub->seguinte;

    // Se o subgrafo não for encontrado, retorna a equação indefinida
    if (!sub) return eq;

    // Procura os vértices V1 e V2 correspondentes ao segmento
    LL_vertice v1 = sub->lista_vertice;
    while (v1 && v1->id != seg->V1)
        v1 = v1->seguinte;

    LL_vertice v2 = sub->lista_vertice;
    while (v2 && v2->id != seg->V2)
        v2 = v2->seguinte;

    // Se algum dos vértices não for encontrado, retorna a equação indefinida
    if (!v1 || !v2) return eq;

    // Verifica se a reta é vertical (declive indefinido)
    if (v1->m == v2->m) {
        eq->indefinida = 1; // Marca a equação como indefinida (reta vertical)
        eq->x_const = v1->m; // Atribui o valor de x para a reta vertical
        return eq;
    }

    // Caso a reta não seja vertical, calcula o declive m e a ordenada na origem b
    eq->m = (float)(v2->n - v1->n) / (v2->m - v1->m); // Declive m
    eq->b = v1->n - eq->m * v1->m; // Ordenada na origem b

    // Retorna a equação calculada
    return eq;
}

/**
 * @brief Determina a interseção entre duas retas.
 *
 * A função determina o ponto de interseção entre duas retas, levando em consideração
 * diferentes casos, como retas paralelas, verticais ou com declives diferentes.
 * Caso as retas não se cruzem, a função retorna NULL.
 *
 * @param r1 Equação da primeira reta.
 * @param r2 Equação da segunda reta.
 * @return Um segmento representando o ponto de interseção entre as retas,
 *         ou NULL caso as retas não se cruzem.
 */
LL_segmento DeterminarIntersecao(LL_EquacaoReta r1, LL_EquacaoReta r2) {
    float y, x;

    // Caso: ambas as retas são verticais
    if (r1->indefinida && r2->indefinida) {
        // Verifica se as retas coincidem ou são paralelas
        if (r1->x_const == r2->x_const)
            printf("\n\n> As arestas estão sobrepostas.\n"); // Retas coincidentes
        else
            printf("\n\n> As arestas não se cruzam.\n"); // Retas paralelas, sem interseção
        return NULL;
    }

    // Caso: as retas são paralelas (mesmo declive)
    else if (r1->m == r2->m) {
        // Verifica se as retas coincidem ou são paralelas
        if (r1->b == r2->b)
            printf("\n\n> As arestas estão sobrepostas.\n"); // Retas coincidentes
        else {
            printf("\n\n> As arestas não se cruzam.\n"); // Retas paralelas, sem interseção
            return NULL;
        }
    }

    // Caso: uma das retas é vertical
    else if (r1->indefinida) {
        x = r1->x_const; // Se a reta 1 for vertical, usa o valor de x constante
        y = r2->m * x + r2->b; // Calcula o valor de y com a equação da reta 2
    }
    else if (r2->indefinida) {
        x = r2->x_const; // Se a reta 2 for vertical, usa o valor de x constante
        y = r1->m * x + r1->b; // Calcula o valor de y com a equação da reta 1
    }

    // Caso geral: as retas não são paralelas nem verticais
    else {
        x = (r2->b - r1->b) / (r1->m - r2->m); // Calcula o valor de x da interseção
        y = r1->m * x + r1->b; // Calcula o valor de y da interseção
    }

    // Cria um novo segmento representando o ponto de interseção
    LL_segmento pontoInter = (LL_segmento)malloc(sizeof(struct SegmentoReta));
    pontoInter->V1 = x; // Atribui o valor de x
    pontoInter->V2 = y; // Atribui o valor de y
    pontoInter->seguinte = NULL;

    // Retorna o segmento que representa o ponto de interseção
    return pontoInter;
}



// > VERIFICAÇÃO DE INTERSEÇÃO ENTRE SEGMENTOS

/** 
 * @brief Verifica se um ponto (linha, coluna) está dentro dos limites de um segmento definido por dois vértices.
 * 
 * Esta função determina se as coordenadas fornecidas (linha, coluna) estão dentro do intervalo do segmento definido 
 * pelos vértices v1 e v2. O segmento é considerado como o intervalo entre os dois vértices no plano 2D.
 * 
 * @param v1 Vértice 1 do segmento.
 * @param v2 Vértice 2 do segmento.
 * @param linha Linha do ponto a ser verificado.
 * @param coluna Coluna do ponto a ser verificado.
 * 
 * @return 1 se o ponto (linha, coluna) está dentro do segmento, caso contrário, retorna 0.
 */
int PontoDentroDoSegmento(LL_vertice v1, LL_vertice v2, int linha, int coluna) {
    int linhaMin = (v1->m < v2->m) ? v1->m : v2->m;
    int linhaMax = (v1->m > v2->m) ? v1->m : v2->m;
    int colunaMin = (v1->n < v2->n) ? v1->n : v2->n;
    int colunaMax = (v1->n > v2->n) ? v1->n : v2->n;

    return (linhaMin <= linha && linhaMax >= linha &&
            colunaMin <= coluna && colunaMax >= coluna);
}

/** 
 * @brief Verifica se dois intervalos [min1, max1] e [min2, max2] estão sobrepostos.
 * 
 * Esta função verifica se dois intervalos no eixo 1D estão sobrepostos. Um intervalo é definido por seus limites 
 * [min, max], e a função retorna 1 se houver sobreposição entre os dois intervalos, e 0 caso contrário.
 * 
 * @param min1 Limite inferior do primeiro intervalo.
 * @param max1 Limite superior do primeiro intervalo.
 * @param min2 Limite inferior do segundo intervalo.
 * @param max2 Limite superior do segundo intervalo.
 * 
 * @return 1 se os intervalos se sobrepõem, caso contrário, retorna 0.
 */
int IntervalosSobrepostos(int min1, int max1, int min2, int max2) {
    return !(max1 < min2 || max2 < min1); // Retorna 1 se houver sobreposição
}

/** 
 * @brief Verifica a interseção entre dois segmentos no ponto fornecido.
 * 
 * Esta função verifica se dois segmentos, definidos por seus identificadores (id1 e id2), se interceptam no ponto 
 * especificado pelas coordenadas (linhaInt, colunaInt). Se houver interseção, retorna o ponteiro para o primeiro segmento. 
 * Caso contrário, retorna NULL.
 * 
 * @param inicioS Ponteiro para o início da lista de subgrafos.
 * @param inicioSg Ponteiro para o início da lista de segmentos.
 * @param id1 ID do primeiro segmento.
 * @param id2 ID do segundo segmento.
 * @param linhaInt Linha do ponto de interseção.
 * @param colunaInt Coluna do ponto de interseção.
 * 
 * @return Ponteiro para o primeiro segmento se houver interseção, caso contrário retorna NULL.
 */
LL_segmento VerificarIntersecao(LL_subgrafos inicioS, LL_segmento inicioSg, int id1, int id2, int linhaInt, int colunaInt) {
    LL_segmento segmento1 = BuscarSegmentoPorID(inicioSg, id1);
    LL_segmento segmento2 = BuscarSegmentoPorID(inicioSg, id2);

    if (!segmento1 || !segmento2) {
        printf("Um dos segmentos não foi encontrado.\n");
        return NULL;
    }

    LL_vertice v1_1 = BuscarVerticePorId(inicioS, segmento1->freq, segmento1->V1);
    LL_vertice v2_1 = BuscarVerticePorId(inicioS, segmento1->freq, segmento1->V2);
    LL_vertice v1_2 = BuscarVerticePorId(inicioS, segmento2->freq, segmento2->V1);
    LL_vertice v2_2 = BuscarVerticePorId(inicioS, segmento2->freq, segmento2->V2);

    if (!v1_1 || !v2_1 || !v1_2 || !v2_2) {
        printf("Um ou mais vértices não foram encontrados.\n");
        return NULL;
    }

    ImprimirInfoSegmento(segmento1, v1_1, v2_1);
    ImprimirInfoSegmento(segmento2, v1_2, v2_2);
    printf("Ponto de interseção (%d, %d)\n\n", linhaInt, colunaInt);

    int dentro1 = PontoDentroDoSegmento(v1_1, v2_1, linhaInt, colunaInt);
    int dentro2 = PontoDentroDoSegmento(v1_2, v2_2, linhaInt, colunaInt);

    // Verificação para segmentos horizontais
    if (v1_1->m == v2_1->m && v1_2->m == v2_2->m && v1_1->m == v1_2->m) {
        int colMin1 = (v1_1->n < v2_1->n) ? v1_1->n : v2_1->n;
        int colMax1 = (v1_1->n > v2_1->n) ? v1_1->n : v2_1->n;
        int colMin2 = (v1_2->n < v2_2->n) ? v1_2->n : v2_2->n;
        int colMax2 = (v1_2->n > v2_2->n) ? v1_2->n : v2_2->n;

        if (IntervalosSobrepostos(colMin1, colMax1, colMin2, colMax2) && dentro1 && dentro2)
            return segmento1;
    }

    // Verificação para segmentos verticais
    else if (v1_1->n == v2_1->n && v1_2->n == v2_2->n && v1_1->n == v1_2->n) {
        int linMin1 = (v1_1->m < v2_1->m) ? v1_1->m : v2_1->m;
        int linMax1 = (v1_1->m > v2_1->m) ? v1_1->m : v2_1->m;
        int linMin2 = (v1_2->m < v2_2->m) ? v1_2->m : v2_2->m;
        int linMax2 = (v1_2->m > v2_2->m) ? v1_2->m : v2_2->m;

        if (IntervalosSobrepostos(linMin1, linMax1, linMin2, linMax2) && dentro1 && dentro2)
            return segmento1;
    }

    // Verificação para segmentos cruzados (um vertical e outro horizontal)
    else if (dentro1 && dentro2) return segmento1;

    return NULL;
}




// > VERIFICAÇÃO E LIMPEZA DE INTERSEÇÕES INVÁLIDAS

/**
 * @brief Função que percorre a lista de interseções detetadas e verifica se cada interseção é válida,
 *        com base na intersecção real dos segmentos correspondentes. 
 *        Se uma interseção for inválida (segmentos não se cruzam de facto no ponto calculado), o nó é removido da lista.
 * 
 * @param listaInter A lista de interseções a ser verificada.
 * @param inicioSg A lista de segmentos que contém os dados dos segmentos.
 * @param inicioS A lista de subgrafos utilizada para buscar as equações das retas.
 * 
 * @return LL_Intercessoes A lista de interseções atualizada com apenas interseções válidas.
 */
LL_Intercessoes MostrarPontosIntersecao(LL_Intercessoes listaInter, LL_segmento inicioSg, LL_subgrafos inicioS) {
    LL_Intercessoes anterior = NULL, atual = listaInter;

    // Percorre cada nó da lista de interseções
    while (atual) {
        // Obtém os segmentos associados à interseção
        LL_segmento s1 = BuscarSegmentoPorID(inicioSg, atual->s1);
        LL_segmento s2 = BuscarSegmentoPorID(inicioSg, atual->s2);

        // Se algum dos segmentos não for encontrado, remove a interseção da lista
        if (!s1 || !s2) {
            atual = RemoverNoAtual(&listaInter, anterior, atual);
            continue;
        }

        // Calcula as equações das retas associadas aos segmentos
        LL_EquacaoReta eq1 = CalcularEquacaoReta(inicioS, s1);
        LL_EquacaoReta eq2 = CalcularEquacaoReta(inicioS, s2);

        // Determina o ponto de interseção entre as duas retas
        LL_segmento pontoInter = DeterminarIntersecao(eq1, eq2);

        void* aux = NULL;
        if (pontoInter) {
            // Extrai as coordenadas (x, y) do ponto de interseção calculado
            float x = pontoInter->V1;
            float y = pontoInter->V2;

            // Verifica se este ponto de interseção está efetivamente dentro de ambos os segmentos
            aux = VerificarIntersecao(inicioS, inicioSg, s1->id, s2->id, x, y);

            free(pontoInter); // Liberta a estrutura temporária usada para armazenar o ponto
        }

        // Se a interseção é válida (o ponto está dentro dos dois segmentos), passa ao próximo nó
        if (aux) {
            anterior = atual;
            atual = atual->seguinte;
        } else {
            // Caso contrário, remove a interseção inválida da lista
            atual = RemoverNoAtual(&listaInter, anterior, atual);
        }
    }

    // Retorna a lista filtrada com apenas interseções válidas
    return listaInter;
}
















