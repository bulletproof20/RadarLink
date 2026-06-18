/**
 * @file    process_geral.c
 * @brief   Funções auxiliares gerais para manipulação de dados e estruturas no projeto.
 * 
 * @details Este ficheiro contém implementações de funções auxiliares gerais, utilizadas para realizar 
 *          operações comuns no projeto, como a manipulação de memória, manipulação de pilhas e filas, 
 *          remoção de nós de listas, entre outras funções de apoio.
 * 
 *          Estas funções não são específicas de nenhum módulo ou componente, sendo aplicáveis em várias 
 *          partes do sistema para facilitar a manipulação e gestão de dados e estruturas.
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




#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"
#include "interface.h"
#include "process_geral.h"
#include "process_ficheiro.h"
#include "process_esp.h"



 
  



// > LIBERTAR MEMÓRIA

/**
 * @brief Liberta a memória de uma lista de arestas.
 * 
 * @param coord Ponteiro para a lista de arestas a ser liberada.
 * @return NULL Sempre retorna NULL após liberar toda a memória da lista.
 */
LL_aresta LibertarAresta(LL_aresta coord) {
    LL_aresta temp; // Ponteiro temporário para armazenar o elemento a ser liberado
    while (coord != NULL) {  // Enquanto a lista não estiver vazia
        temp = coord; // Salva o nó atual em 'temp'
        coord = coord->seguinte; // Avança para o próximo nó da lista
        free(temp); // Libera a memória do nó atual
    }
    return NULL; // Retorna NULL, pois a lista foi completamente liberada
}

/**
 * @brief Liberta a memória de uma lista de vértices, incluindo as arestas associadas.
 * 
 * @param coord Ponteiro para a lista de vértices a ser liberada.
 * @return NULL Sempre retorna NULL após liberar toda a memória da lista.
 */
LL_vertice LibertarVertice(LL_vertice coord) {
    LL_vertice temp; // Ponteiro temporário para armazenar o vértice a ser liberado
    while (coord != NULL) {  // Enquanto a lista de vértices não estiver vazia
        // Se o vértice tiver uma lista de arestas, libera-a antes
        if (coord->lista_aresta != NULL) {
            coord->lista_aresta = LibertarAresta(coord->lista_aresta); // Libera as arestas associadas
        }
        temp = coord; // Salva o nó atual (vértice) em 'temp'
        coord = coord->seguinte; // Avança para o próximo vértice na lista
        free(temp); // Libera a memória do vértice atual
    }
    return NULL; // Retorna NULL, pois a lista foi completamente liberada
}

/**
 * @brief Liberta a memória de uma lista de subgrafos, incluindo os vértices e as arestas associadas.
 * 
 * @param subgrafos Ponteiro para a lista de subgrafos a ser liberada.
 * @return NULL Sempre retorna NULL após liberar toda a memória da lista.
 */
LL_subgrafos LibertarSubgrafos(LL_subgrafos subgrafos) {
    LL_subgrafos temp; // Ponteiro temporário para armazenar o subgrafo a ser liberado
    while (subgrafos != NULL) {  // Enquanto a lista de subgrafos não estiver vazia
        // Se o subgrafo tiver uma lista de vértices, libera-a antes
        if (subgrafos->lista_vertice != NULL) {
            subgrafos->lista_vertice = LibertarVertice(subgrafos->lista_vertice); // Libera os vértices e suas arestas
        }
        temp = subgrafos; // Salva o subgrafo atual em 'temp'
        subgrafos = subgrafos->seguinte; // Avança para o próximo subgrafo
        free(temp); // Libera a memória do subgrafo atual
    }
    return NULL; // Retorna NULL, pois a lista foi completamente liberada
}

/**
 * @brief Liberta a memória de uma lista de antenas.
 * 
 * @param antena Ponteiro para a lista de antenas a ser liberada.
 * @return NULL Sempre retorna NULL após liberar toda a memória da lista.
 */
LL_antena LibertarAntenas(LL_antena antena) {
    LL_antena temp; // Ponteiro temporário para armazenar a antena a ser liberada
    while (antena != NULL) {  // Enquanto a lista de antenas não estiver vazia
        temp = antena; // Salva a antena atual em 'temp'
        antena = antena->seguinte; // Avança para a próxima antena
        free(temp); // Libera a memória da antena atual
    }
    return NULL; // Retorna NULL, pois a lista foi completamente liberada
}

/**
 * @brief Liberta a memória de uma lista de letras.
 * 
 * @param letra Ponteiro para a lista de letras a ser liberada.
 * @return NULL Sempre retorna NULL após liberar toda a memória da lista.
 */
LL_letras LibertarLetras(LL_letras letra) {
    LL_letras temp; // Ponteiro temporário para armazenar a letra a ser liberada
    while (letra != NULL) {  // Enquanto a lista de letras não estiver vazia
        temp = letra; // Salva a letra atual em 'temp'
        letra = letra->seguinte; // Avança para a próxima letra
        free(temp); // Libera a memória da letra atual
    }
    return NULL; // Retorna NULL, pois a lista foi completamente liberada
}

/**
 * @brief Limpa a pilha até que ela seja vazia (NULL).
 * 
 * @param caminho Ponteiro para a pilha a ser limpa.
 */
void limparPilha(PILHA caminho) {
    int lixo;
    
    // Enquanto a pilha não for NULL, continua a desempilhar
    while (caminho != NULL) {
        caminho = Pop(caminho, &lixo);  // Remove o topo da pilha
    }
}

/**
 * @brief Liberta a memória de uma lista de segmentos.
 * 
 * @param seg Ponteiro para a lista de segmentos a ser liberada.
 * @return NULL Sempre retorna NULL após liberar toda a memória da lista.
 */
LL_segmento LibertarSegmentos(LL_segmento seg) {
    LL_segmento temp; // Ponteiro temporário para armazenar o segmento a ser liberado
    while (seg != NULL) {  // Enquanto a lista de segmentos não estiver vazia
        temp = seg; // Salva o segmento atual em 'temp'
        seg = seg->seguinte; // Avança para o próximo segmento
        free(temp); // Libera a memória do segmento atual
    }
    return NULL; // Retorna NULL, pois a lista foi completamente liberada
}

/**
 * @brief Liberta a memória de uma lista de interseções.
 * 
 * @param intercessao Ponteiro para a lista de interseções a ser liberada.
 * @return NULL Sempre retorna NULL após liberar toda a memória da lista.
 */
LL_Intercessoes LibertarIntercessao(LL_Intercessoes intercessao) {
    LL_Intercessoes temp; // Ponteiro temporário para armazenar o elemento a ser liberado
    while (intercessao != NULL) {  // Enquanto a lista não estiver vazia
        temp = intercessao; // Salva o nó atual em 'temp'
        intercessao = intercessao->seguinte; // Avança para o próximo nó da lista
        free(temp); // Libera a memória do nó atual
    }
    return NULL; // Retorna NULL, pois a lista foi completamente liberada
}

 


// > MANIPULAÇÃO DE PILHA (LL FILO)

/**
 * @brief Adiciona um novo elemento no topo da pilha.
 * 
 * @param topo Ponteiro para o topo atual da pilha.
 * @param id Valor inteiro a ser inserido no novo elemento da pilha.
 * @return PILHA Novo topo da pilha (elemento recém-inserido), ou o topo original em caso de falha na alocação.
 */
PILHA Push(PILHA topo, int id) {
    PILHA novo = malloc(sizeof(struct DadoP)); // Aloca memória para um novo elemento da pilha
    if (!novo) return topo; // Se a alocação falhar, retorna a pilha original (sem alteração)
    novo->id = id; // Atribui o valor ao novo elemento
    novo->seguinte = topo; // O próximo elemento do novo nó será o topo atual
    return novo; // Retorna o novo topo da pilha (novo elemento adicionado)
}

/**
 * @brief Remove o elemento do topo da pilha.
 * 
 * @param topo Ponteiro para o topo atual da pilha.
 * @param id Ponteiro para armazenar o valor do elemento removido.
 * @return PILHA Novo topo da pilha após a remoção, ou NULL se a pilha estiver vazia.
 */
PILHA Pop(PILHA topo, int* id) {
    if (!topo) return NULL; // Se a pilha estiver vazia, não há nada a remover, retorna NULL
    *id = topo->id; // Armazena o valor do topo na variável fornecida por referência
    PILHA temp = topo; // Salva o topo atual em uma variável temporária para liberar memória depois
    topo = topo->seguinte; // Avança para o próximo elemento da pilha (o novo topo)
    free(temp); // Libera a memória do antigo topo (nó removido)
    return topo; // Retorna o novo topo da pilha
}




// > MANIPULAÇÃO DE FILA (LL FIFO)

/**
 * @brief Adiciona um novo elemento no final da fila.
 * 
 * @param fila Ponteiro para o início da fila.
 * @param id Valor inteiro a ser inserido no novo elemento da fila.
 * @return FILA Ponteiro para o início da fila (inalterado), ou o novo elemento se a fila estiver vazia.
 */
FILA Enqueue(FILA fila, int id) {
    FILA novo = malloc(sizeof(struct DadoF)); // Aloca memória para o novo elemento da fila
    if (!novo) return fila; // Se a alocação falhar, retorna a fila original (sem alteração)
    novo->id = id; // Atribui o valor fornecido ao novo elemento
    novo->seguinte = NULL; // O novo elemento será o último da fila, então não há elemento seguinte

    // Se a fila estiver vazia, o novo elemento se torna a cabeça da fila
    if (!fila) return novo; 

    // Caso contrário, percorre a fila até o último elemento e o adiciona no final
    FILA aux = fila; 
    while (aux->seguinte) aux = aux->seguinte; // Vai até o último elemento da fila
    aux->seguinte = novo; // O último elemento agora aponta para o novo elemento, adicionando-o no final
    return fila; // Retorna a fila original (não alterada)
}

/**
 * @brief Remove o primeiro elemento da fila.
 * 
 * @param fila Ponteiro para o início da fila.
 * @param id Ponteiro para armazenar o valor do elemento removido.
 * @return FILA Ponteiro para o novo início da fila após a remoção, ou NULL se a fila estiver vazia.
 */
FILA Dequeue(FILA fila, int* id) {
    if (!fila) return NULL; // Se a fila estiver vazia, retorna NULL (não há elementos para remover)
    *id = fila->id; // Armazena o valor do primeiro elemento da fila na variável fornecida por referência
    FILA temp = fila; // Salva o primeiro elemento da fila em uma variável temporária
    fila = fila->seguinte; // Avança para o próximo elemento da fila, que se torna a nova cabeça
    free(temp); // Libera a memória do antigo primeiro elemento (nó removido)
    return fila; // Retorna a nova cabeça da fila (o próximo elemento)
}





// > MANIPULAÇÃO DE LL_INTERCEÇÕES

/**
 * @brief Remove o nó atual de uma lista ligada de interceções.
 *
 * Esta função remove um nó específico da lista ligada, atualizando os apontadores adequadamente.
 * Se o nó a remover for o primeiro da lista, o ponteiro do início da lista será ajustado.
 * A memória do nó removido é libertada.
 *
 * @param listaInicio Ponteiro para o ponteiro que representa o início da lista.
 * @param anterior Ponteiro para o nó anterior ao nó atual (ou NULL se o atual for o primeiro nó).
 * @param atual Ponteiro para o nó que se pretende remover.
 * @return LL_Intercessoes Ponteiro para o próximo nó a ser processado após a remoção.
 *                         Se o nó anterior for válido, devolve `anterior->seguinte`;
 *                         caso contrário, devolve o novo início da lista.
 */
LL_Intercessoes RemoverNoAtual(LL_Intercessoes* listaInicio, LL_Intercessoes anterior, LL_Intercessoes atual) {
    // Verifica se o nó atual existe; se não existir, retorna NULL (nada a remover)
    if (!atual) return NULL;

    // Caso o anterior seja NULL, então o nó atual é o primeiro da lista
    if (!anterior) {
        // Atualiza o início da lista para apontar para o próximo nó
        *listaInicio = atual->seguinte;
    } else {
        // Liga o nó anterior ao seguinte do atual, saltando o atual
        anterior->seguinte = atual->seguinte;
    }

    // Liberta a memória do nó que foi removido
    free(atual);

    // Retorna o próximo nó a ser processado após a remoção
    // Se anterior for válido, retorna o nó seguinte dele
    // Caso contrário, retorna o novo início da lista
    return (anterior) ? anterior->seguinte : *listaInicio;
}




// > FUNÇÕES DE RESET E VALIDAÇÃO

// Função responsável por dar reset nos vistos em vértices e arestas
void ResetVistos(const LL_subgrafos inicioS){
    LL_subgrafos atual = inicioS;  // Inicia o subgrafo atual com o primeiro subgrafo
    while (atual != NULL)  // Continua até não haver mais subgrafos
    {
        LL_vertice vertice = atual->lista_vertice;  // Inicia no primeiro vértice do subgrafo
        while (vertice != NULL)  // Continua até não haver mais vértices no subgrafo
        {
            vertice->visto = 0;  // Reseta o estado 'visto' do vértice para 0
            LL_aresta aresta = vertice->lista_aresta;  // Inicia na lista de arestas do vértice
            if (aresta != NULL)  // Verifica se o vértice tem arestas associadas
            {
                while (aresta != NULL)  // Continua até não haver mais arestas no vértice
                {
                    aresta->visto = 0;  // Reseta o estado 'visto' da aresta para 0
                    aresta = aresta->seguinte;  // Avança para a próxima aresta
                } 
            }
            vertice = vertice->seguinte;  // Avança para o próximo vértice
        }
        atual = atual->seguinte;  // Avança para o próximo subgrafo
    }
}

// Função responsável por validar a existência de um vértice num subgrafo
LL_subgrafos VerificarVertice(const LL_subgrafos inicioS, char frequencia, int v){
    LL_subgrafos atual = inicioS;  // Inicia o subgrafo atual com o primeiro subgrafo
    while (atual != NULL)  // Continua até não haver mais subgrafos
    {
        if(atual->f == frequencia)  // Verifica se o subgrafo possui a frequência desejada
        {
            LL_vertice vertice = atual->lista_vertice;  // Inicia no primeiro vértice do subgrafo
            while (vertice != NULL)  // Continua até não haver mais vértices no subgrafo
            {
                if(vertice->id == v)  // Verifica se o vértice com o id procurado existe
                {
                    return inicioS;  // Se o vértice for encontrado, retorna o subgrafo
                }
                vertice = vertice->seguinte;  // Avança para o próximo vértice
            } 
        }
        atual = atual->seguinte;  // Avança para o próximo subgrafo
    }
    return NULL;  // Se o vértice não for encontrado, retorna NULL
}




// > FUNÇÕES DE BUSCA

/**
 * @brief Procura um vértice com um determinado ID dentro de um subgrafo específico.
 *
 * Esta função percorre a lista de subgrafos até encontrar aquele com a frequência indicada.
 * Em seguida, percorre a lista de vértices desse subgrafo à procura de um vértice com o ID fornecido.
 *
 * @param inicioS Ponteiro para o início da lista de subgrafos.
 * @param freq Frequência associada ao subgrafo onde se pretende procurar.
 * @param id ID do vértice a ser procurado.
 * @return LL_vertice Ponteiro para o vértice encontrado ou NULL caso não exista.
 */
LL_vertice BuscarVerticePorId(LL_subgrafos inicioS, char freq, int id) {
    LL_subgrafos sub = inicioS;

    // Percorre todos os subgrafos até encontrar o que tem a frequência indicada
    while (sub) {
        if (sub->f == freq) {
            // Dentro do subgrafo correto, percorre a lista de vértices
            LL_vertice verticeAtual = sub->lista_vertice;
            while (verticeAtual != NULL) {
                // Compara o ID do vértice atual com o procurado
                if (verticeAtual->id == id) {
                    return verticeAtual; // Retorna o vértice encontrado
                }
                verticeAtual = verticeAtual->seguinte;
            }
        }
        sub = sub->seguinte; // Vai para o próximo subgrafo
    }

    // Se não encontrou o vértice, retorna NULL
    return NULL;
}

/**
 * @brief Procura um segmento com um determinado ID numa lista de segmentos.
 *
 * Esta função percorre a lista ligada de segmentos à procura de um segmento com o ID correspondente.
 *
 * @param inicio Ponteiro para o início da lista de segmentos.
 * @param id ID do segmento a ser procurado.
 * @return LL_segmento Ponteiro para o segmento encontrado ou NULL caso não exista.
 */
LL_segmento BuscarSegmentoPorID(LL_segmento inicio, int id) {
    // Percorre a lista de segmentos
    while (inicio != NULL) {
        // Verifica se o ID do segmento atual corresponde ao procurado
        if (inicio->id == id) return inicio;
        inicio = inicio->seguinte; // Avança para o próximo segmento
    }

    // Se não encontrou o segmento, retorna NULL
    return NULL;
}







