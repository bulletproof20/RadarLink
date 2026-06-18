/**
 * @file    estruturas.h
 * @brief   Definição de estruturas de dados para manipulação de antenas, arestas e outros componentes gráficos.
 *
 * @details Este ficheiro contém as definições das estruturas de dados utilizadas no processamento e manipulação
 *          das antenas, arestas, vértices, segmentos e interseções, de forma eficiente.
 *
 * @note    Ficheiros presentes na mesma pasta:
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
 *          Estes ficheiros, em conjunto, constituem os principais módulos do programa.
 *
 * @version 9
 * @author  Ivo Sá, nº 22604
 * @date    12/05/2025
 */



#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H


/**
 * @struct antena
 * @brief Representa uma antena localizada numa matriz.
 * 
 * @var antena::m
 *      Linha da matriz onde a antena está posicionada.
 * @var antena::n
 *      Coluna da matriz onde a antena está posicionada.
 * @var antena::f
 *      Frequência da antena (ex: 'A', 'B', ...).
 * @var antena::seguinte
 *      Apontador para a próxima antena na lista ligada.
 */
typedef struct antena {
    int m;
    int n;
    char f;
    struct antena* seguinte;
} *LL_antena;

/**
 * @struct Letra
 * @brief Representa um nó de uma lista ligada de caracteres (FIFO), usada para armazenar texto.
 * 
 * @var Letra::caracter
 *      Carácter armazenado no nó.
 * @var Letra::seguinte
 *      Apontador para o próximo nó da lista.
 */
typedef struct Letra {
    char caracter;
    struct Letra* seguinte;
} *LL_letras;



/**
 * @struct aresta
 * @brief Representa uma aresta entre vértices, com identificação e coordenadas.
 * 
 * @var aresta::id
 *      Identificador único da aresta.
 * @var aresta::m
 *      Linha da matriz onde a aresta se encontra.
 * @var aresta::n
 *      Coluna da matriz onde a aresta se encontra.
 * @var aresta::visto
 *      Indica se a aresta foi visitada (0: não, !=0: sim).
 * @var aresta::seguinte
 *      Apontador para a próxima aresta na lista ligada.
 */
typedef struct aresta {
    int id;
    int m;
    int n;
    int visto;
    struct aresta* seguinte;
} *LL_aresta;

/**
 * @struct vertice
 * @brief Representa um vértice do grafo, contendo uma lista de arestas.
 * 
 * @var vertice::id
 *      Identificador único do vértice.
 * @var vertice::m
 *      Linha da matriz onde o vértice se encontra.
 * @var vertice::n
 *      Coluna da matriz onde o vértice se encontra.
 * @var vertice::visto
 *      Indica se o vértice foi visitado (0: não, !=0: sim).
 * @var vertice::lista_aresta
 *      Lista ligada de arestas associadas a este vértice.
 * @var vertice::seguinte
 *      Apontador para o próximo vértice na lista ligada.
 */
typedef struct vertice {
    int id;
    int m;
    int n;
    int visto;
    LL_aresta lista_aresta;
    struct vertice* seguinte;
} *LL_vertice;

/**
 * @struct subgrafos
 * @brief Representa um subgrafo associado a uma determinada frequência.
 * 
 * @var subgrafos::f
 *      Frequência associada ao subgrafo.
 * @var subgrafos::lista_vertice
 *      Lista ligada de vértices pertencentes ao subgrafo.
 * @var subgrafos::seguinte
 *      Apontador para o próximo subgrafo.
 */
typedef struct subgrafos {
    char f;
    LL_vertice lista_vertice;
    struct subgrafos* seguinte;
} *LL_subgrafos;

 
/**
 * @struct DadoP
 * @brief Estrutura de nó para uma pilha (FILO), usada na pesquisa em profundidade.
 * 
 * @var DadoP::id
 *      Identificador do elemento.
 * @var DadoP::seguinte
 *      Apontador para o próximo nó da pilha.
 */
typedef struct DadoP {
    int id;
    struct DadoP* seguinte;
} *PILHA;

/**
 * @struct DadoF
 * @brief Estrutura de nó para uma fila (FIFO), usada na pesquisa em largura.
 * 
 * @var DadoF::id
 *      Identificador do elemento.
 * @var DadoF::seguinte
 *      Apontador para o próximo nó da fila.
 */
typedef struct DadoF {
    int id;
    struct DadoF* seguinte;
} *FILA;

/**
 * @struct SegmentoReta
 * @brief Representa um segmento de reta entre dois vértices com uma frequência associada.
 * 
 * @var SegmentoReta::id
 *      Identificador do segmento.
 * @var SegmentoReta::freq
 *      Frequência associada ao segmento.
 * @var SegmentoReta::V1
 *      Identificador do primeiro vértice.
 * @var SegmentoReta::V2
 *      Identificador do segundo vértice.
 * @var SegmentoReta::seguinte
 *      Apontador para o próximo segmento na lista ligada.
 */
typedef struct SegmentoReta {
    int id;
    char freq;
    int V1, V2;
    struct SegmentoReta* seguinte;
} *LL_segmento;

/**
 * @struct Intercessao
 * @brief Representa uma interseção entre dois segmentos de reta.
 * 
 * @var Intercessao::s1
 *      Identificador do primeiro segmento.
 * @var Intercessao::s2
 *      Identificador do segundo segmento.
 * @var Intercessao::seguinte
 *      Apontador para a próxima interseção na lista ligada.
 */
typedef struct Intercessao {
    int s1, s2;
    struct Intercessao* seguinte;
} *LL_Intercessoes;

/**
 * @struct EquacaoReta
 * @brief Representa os coeficientes de uma equação de reta no plano.
 * 
 * @var EquacaoReta::m
 *      Declive (coeficiente angular) da reta.
 * @var EquacaoReta::b
 *      Ordenada na origem.
 * @var EquacaoReta::indefinida
 *      Flag que indica se a reta é vertical (1 se sim).
 * @var EquacaoReta::x_const
 *      Valor constante de x caso a reta seja vertical.
 */
typedef struct EquacaoReta {
    float m;
    float b;
    int indefinida;
    int x_const;
} *LL_EquacaoReta;

#endif
