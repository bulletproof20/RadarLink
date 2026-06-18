/**
 * @file    interface.c
 * @brief   Apresentação e recolha de informação, manipulação do terminal.
 *
 * @details Este ficheiro contém as funções responsáveis pela interação com o utilizador,
 *          incluindo apresentação no terminal, recolha de dados e comandos básicos.
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
 * @version 1
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
#include "process_nef.h"

 


// > MANIPULAÇÃO DE DADOS NO TERMINAL
/**
 * @brief Limpa o terminal consoante o sistema operativo.
 */
void limparTerminal() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}


// > APRESENTAÇÃO DE DADOS (FIXOS)
/**
 * @brief Apresenta o cabeçalho introdutório do programa.
 */
void intro (){
    limparTerminal();
    //Introduz o programa
    printf("==============================================================\n");
    printf("               GESTÃO DE ANTENAS E FREQUÊNCIAS                \n");
    printf("==============================================================\n");
    printf("                          MANIPULAÇÃO                         \n");
    printf("--------------------------------------------------------------\n");
    printf("-> Lê e armazena antenas numa matriz representando a cidade.\n");
    printf("-> Carrega dados a partir de ficheiros de texto.\n");
    printf("-> Permite selecionar e carregar novos ficheiros.\n");
    printf("-> Permite adicionar e remover antenas manualmente.\n");
    printf("-> Cada antena tem uma frequência e uma posição definida.\n");
    printf("--------------------------------------------------------------\n");
    printf("                            ANÁLISE                           \n");
    printf("--------------------------------------------------------------\n");
    printf("-> Deteta efeitos nefastos causados por alinhamentos (#).\n");
    printf("-> Apenas há ligação entre antenas com a mesma frequência.\n");
    printf("-> Percorre a matriz como grafo (DFS e BFS).\n");
    printf("-> Analisa caminhos possíveis entre duas antenas.\n");
    printf("-> Verifica interceções entre pares de diferentes frequências.\n");
    printf("==============================================================\n");

}


/**
 * @brief Apresenta o menu principal de opções ao utilizador.
 */
void menu(int men){
    limparTerminal();
    if(men == 1){
        printf("\n> Descomprimir Menu \33[32m(10)\33[0m\n");
        printf("\n> Qual o procedimento que pretende executar?\n");
        printf("   > \33[32m(1)\33[0mManipular matriz.\n");
        printf("   > \33[32m(2)\33[0mAnalisar antenas da matriz.\n");
        printf("   > \33[32m(3)\33[0mVisualizar matriz.\n");
        printf("   > \33[32m(4)\33[0mEstruturas criadas.\n");
        printf("   > \33[32m(5)\33[0mCarregar novo ficheiro.\n");
        printf("   > \33[32m(6)\33[0mTerminar programa.\n");

    }else{
        printf("\n> Comprimir Menu \33[32m(10)\33[0m\n");
        printf("\n> Qual o procedimento que pretende executar?\n");
        printf("   > \33[32m(1)\33[0mManipular matriz.\n");
        printf("             > Adicionar uma antena.\n");
        printf("             > Remover uma antena.\n\n");

        printf("   > \33[32m(2)\33[0mAnalisar antenas da matriz.\n");
        printf("             > Identificar todos caminhos possíveis entre duas antenas.\n");
        printf("             > Procura em profundidade a partir de uma antena.\n");
        printf("             > Procura em largura a partir de uma antena.\n");
        printf("             > Identificar intercessões entre frequências.\n\n");

        printf("   > \33[32m(3)\33[0mVisualizar matriz.\n");
        printf("             > Matriz atual.\n");
        printf("             > Matriz com efeitos nefastos.\n");
        printf("             > Matriz apenas com as antenas que geram intercessões de sinal.\n\n");

        printf("   > \33[32m(4)\33[0mEstruturas criadas.\n");
        printf("             > Estrura de grafo cidade.\n");
        printf("             > Segmentos possiveis da mesma frequencia.\n");
        printf("             > Pares possiveis de segmentos.\n\n");

        printf("   > \33[32m(5)\33[0mCarregar novo ficheiro.\n\n");
        printf("   > \33[32m(6)\33[0mTerminar programa.\n");
    }
    
}
 


/**
 * @brief Apresenta o menu de manipular ficheiro.
 */
void menu1(){
    limparTerminal();
    printf("\n> Qual o procedimento que pretende executar?\n");
    printf("   > \33[32m(1)\33[0mAdicionar uma antena.\n");
    printf("   > \33[32m(2)\33[0mRemover uma antena.\n");
    printf("   > \33[32m(3)\33[0mPagina anterior.\n");
}


/**
 * @brief Apresenta o menu de analise de dados.
 */
void menu2(){
    limparTerminal();
    printf("\n> Qual o procedimento que pretende executar?\n");
    printf("   > \33[32m(1)\33[0mIdentificar todos caminhos possíveis entre duas antenas.\n");
    printf("   > \33[32m(2)\33[0mProcura em profundidade a partir de uma antena.\n");
    printf("   > \33[32m(3)\33[0mProcura em largura a partir de uma antena.\n");
    printf("   > \33[32m(4)\33[0mIdentificar intercessões entre frequências.\n");
    printf("   > \33[32m(5)\33[0mPagina anterior.\n");
}


/**
 * @brief Apresenta o menu de analise de ficheiro.
 */
void menu3(){
    limparTerminal();
    printf("\n> Qual o procedimento que pretende executar?\n");
    printf("   > \33[32m(1)\33[0mMatriz atual.\n");
    printf("   > \33[32m(2)\33[0mMatriz com efeitos nefastos.\n");
    printf("   > \33[32m(3)\33[0mMatriz com identificador nos vertices que geram intercessão.\n");
    printf("   > \33[32m(4)\33[0mPagina anterior.\n");
}


/**
 * @brief Apresenta o menu de estrutura de dados.
 */
void menu4(){
    limparTerminal();
    printf("\n> Qual o procedimento que pretende executar?\n");
    printf("   > \33[32m(1)\33[0mEstrura de grafo cidade.\n");
    printf("   > \33[32m(2)\33[0mSegmentos possiveis da mesma frequencia.\n");
    printf("   > \33[32m(3)\33[0mPares possiveis de segmentos.\n");
    printf("   > \33[32m(4)\33[0mPagina anterior.\n");
}




/**
 * @brief Apresenta instruções para o carregamento de ficheiros.
 */
void instrucoesFile(){
    limparTerminal();
    printf("====================================================\n");
    printf("       INSTRUÇÕES  DE CARREGAMENTO DE FICHEIRO       \n");
    printf("====================================================\n");
    printf("-> Só é possivel carregar ficheiros do tipo '.txt'.\n");
    printf("-> A configuração do mesmo deve seguir o seguinte\n");
    printf(" padrão:\n");
    printf(" \n");
    printf("-> ........A.\n");
    printf("   ..........\n");
    printf("   ...Y......\n");
    printf("   I......A..\n");
    printf("   ..........\n");
    printf(" \n");
    printf("-> As antenas devem ser representadas por qualquer\n");
    printf(" caracter não reservado.\n");
    printf("-> A presença de antenas é facultativa.\n");
    printf("-> Os espaços sem antena pertencentes á 'cidade',\n");
    printf(" são representados por '.' .\n");
    printf("-> Os caracters reservados são '#',' '.\n");
    printf("-> Se o ficheiro texto contiver algum caracter \n");
    printf(" reservado, este será considerado '.'.\n");
    printf("-> Se a matriz estiver irregular, com colunas ou\n");
    printf(" linhas de diferente tamanho, serão regularizadas\n");
    printf(" pelo maior valor.\n");
    printf("====================================================\n\n");
}


/**
 * @brief Aguarda a interação do utilizador para prosseguir.
 */
void AvisoAvancar(){
    printf("\n\n\33[33m> Click em 'enter' para avançar.\33[0m\n\n");
    while (getchar() != '\n');
    getchar(); 
}




// > APRESENTAÇÃO DE DADOS (VARIAVEIS)
/**
 * @brief Apresenta a matriz de antenas representada por uma lista ligada.
 * @param inicio Ponteiro para o início da lista de antenas.
 * @param n_linhas Número total de linhas da matriz.
 * @param n_colunas Número total de colunas da matriz.
 * @return Ponteiro para o início da lista inalterado.
 */
LL_antena ApresentaMatriz(LL_antena inicio, int n_linhas, int n_colunas) {
    LL_antena aux = inicio;
    limparTerminal();

    printf("\n> Matriz de dimensão %d*%d\n\n\n", n_linhas, n_colunas);

    // Percorre todas as linhas da matriz
    for (int linha = 0; linha < n_linhas; linha++) {
        // Percorre todas as colunas da matriz
        for (int coluna = 0; coluna < n_colunas; coluna++) {
            // Verifica se a posição atual corresponde a uma antena
            if (aux != NULL && aux->m-1  == linha && aux->n-1  == coluna) 
            {
                if(aux->marc!=0) printf("\33[33m%c\33[0m", aux->f);
                //else if(aux->marc==2) printf("\33[32m%c\33[0m", aux->f);
                //else if(aux->marc==3) printf("\33[33m%c\33[0m", aux->f);
                else printf("%c", aux->f);
                // Avança para a próxima antena na lista
                aux = aux->seguinte;  
            } else {
                // Imprime um ponto ('.') se não houver antena na posição
                printf(".");
            }
        }
        // Nova linha após a impressão de uma linha da matriz
        printf("\n");
    }

    // Retorna a lista inalterada
    return inicio;
}


/**
 * @brief Imprime todos os subgrafos e os seus vértices com ligações.
 * @param inicioS Ponteiro para o início da lista de subgrafos.
 */
void ImprimirGrafo(const LL_subgrafos inicioS){
    const LL_subgrafos subgrafos = inicioS;
    printf("> Dados obtidos e armazenados.\n");

    LL_subgrafos atual = subgrafos;
    while (atual != NULL)
    {
        printf("\nSubgrafo '%c':\n", atual->f);

        LL_vertice vertice = atual->lista_vertice;
        while (vertice != NULL)
        {
            // Imprime o ID e a posição do vértice
            printf("   > V%i (%i, %i)", vertice->id, vertice->m, vertice->n);

            // Imprime as arestas do vértice
            LL_aresta aresta = vertice->lista_aresta;
            if (aresta != NULL)
            {
                
                while (aresta != NULL)
                {
                    printf("\n             -> v%i (%i, %i)", aresta->id, aresta->m, aresta->n);
                    aresta = aresta->seguinte;
                } 
            }

            printf("\n");
            vertice = vertice->seguinte;
        }

        atual = atual->seguinte;
    }
}


/**
 * @brief Imprime os identificadores de todas as frequências registadas.
 * @param inicioS Ponteiro para o início da lista de subgrafos.
 * @return Ponteiro para o início da lista inalterado.
 */
LL_subgrafos ImprimirSubgrafos(const LL_subgrafos inicioS){
    const LL_subgrafos subgrafos = inicioS;
    printf("> Frequências registadas.\n");

    LL_subgrafos atual = subgrafos;
    while (atual != NULL)
    {
        printf("\n  -> \33[32m%c\33[0m", atual->f);

        atual = atual->seguinte;
    }
}


/**
 * @brief Imprime todos os vértices de um subgrafo específico.
 * @param inicioS Ponteiro para o início da lista de subgrafos.
 * @param frequencia Carácter que identifica a frequência do subgrafo.
 * @return Ponteiro para o início da lista inalterado.
 */
LL_subgrafos ImprimirVerticeSubgrafo(const LL_subgrafos inicioS, char frequencia){
    LL_subgrafos atual = inicioS;
    int existe = 0;

    while (atual != NULL) {
        if (atual->f == frequencia) {
            existe = 1;
            printf("\nSubgrafo '%c':\n", atual->f);

            LL_vertice vertice = atual->lista_vertice;
            while (vertice != NULL) {
                printf("   > V%i (%i, %i)\n", vertice->id, vertice->m, vertice->n);
                vertice = vertice->seguinte;
            }
            
            break; // Frequência encontrada, não vale a pena continuar
        }
        atual = atual->seguinte;
    }

    if (existe == 0) {
        return NULL;
    } else {
        return inicioS;
    }
}


/**
 * @brief Lista os elementos da pilha, do fundo até ao topo (forma recursiva).
 * 
 * @param pilha Ponteiro para o topo da pilha.
 */
void listarPilha(PILHA pilha)
{
    if (pilha != NULL) {  // Verifica se a pilha não está vazia
        listarPilha(pilha->seguinte); // Chamada recursiva para listar o próximo elemento (vai até o fundo)
        printf("%d -> ", pilha->id); // Imprime o valor do topo atual da pilha
    }
}


/**
 * @brief Imprime todos os segmentos registados na lista ligada.
 * 
 * @param inicio Ponteiro para o primeiro nó da lista de segmentos.
 */
void ImprimirSegmentos(LL_segmento inicio) {
    LL_segmento atual = inicio;

    if (!atual) {  // Verifica se a lista está vazia
        printf("Lista de segmentos está vazia.\n"); // Mensagem caso a lista esteja vazia
        return;
    }

    printf("Segmentos registados:\n");

    // Percorre e imprime cada segmento presente na lista
    while (atual) {
        printf("  [%d] Freq: %c | V%d <-> V%d\n", atual->id, atual->freq, atual->V1, atual->V2); 
        // Exibe informações sobre o segmento (id, frequência e vértices)
        atual = atual->seguinte;  // Avança para o próximo segmento
    }
}


/**
 * @brief Imprime os pares de segmentos que se cruzam e têm frequências diferentes.
 * 
 * @param inicio Ponteiro para o início da lista de interseções.
 */
void ImprimirIntersecoes(LL_Intercessoes inicio) {
    if (!inicio) {  // Verifica se a lista de interseções está vazia
        printf("Sem interseções encontradas.\n");  // Mensagem caso não haja interseções
        return;
    }

    printf("Pares de segmentos com frequências diferentes:\n");

    LL_Intercessoes atual = inicio;
    // Percorre e imprime as interseções encontradas
    while (atual != NULL) {
        printf("  Segmento %d <-> Segmento %d\n", atual->s1, atual->s2); 
        // Exibe os pares de segmentos que têm frequências diferentes
        atual = atual->seguinte;  // Avança para o próximo par de interseções
    }
}


/**
 * @brief Imprime as coordenadas dos dois vértices de um segmento e a respetiva frequência.
 * 
 * @param seg Ponteiro para o segmento.
 * @param v1 Ponteiro para o primeiro vértice do segmento.
 * @param v2 Ponteiro para o segundo vértice do segmento.
 */
void ImprimirInfoSegmento(LL_segmento seg, LL_vertice v1, LL_vertice v2) {
    printf("Coordenadas do vértice 1 do Segmento (ID: %d): (%d, %d)\n", v1->id, v1->m, v1->n);
    printf("Coordenadas do vértice 2 do Segmento (ID: %d): (%d, %d)\n", v2->id, v2->m, v2->n);
    printf("Frequência do Segmento: %c\n", seg->freq);
}


/**
 * @brief Mostra as interseções entre segmentos de diferentes frequências.
 * 
 * Para cada interseção existente, são identificados os dois segmentos envolvidos.
 * A função imprime os vértices associados a cada segmento, bem como as respetivas coordenadas,
 * assinalando visualmente a interseção.
 * 
 * Em caso de erro na procura de segmentos ou vértices, termina a execução através de FalhaMalloc().
 * 
 * @param[in] inicioI Ponteiro para o início da lista de interseções.
 * @param[in] inicioSg Ponteiro para o início da lista de segmentos.
 * @param[in] inicioS Ponteiro para o início da lista de subgrafos.
 */
LL_antena MostrarIntersecoes(LL_Intercessoes inicioI, LL_segmento inicioSg, LL_subgrafos inicioS, LL_antena inicioA) {
    LL_Intercessoes inter = inicioI; ///< Ponteiro auxiliar para percorrer a lista de interseções
    printf("\n> Interceções entre 2 segmentos com diferentes frequencias");

    while (inter) { ///< Itera sobre cada interseção da lista
        for (int i = 0; i < 2; i++) { ///< Itera duas vezes: uma para cada segmento da interseção
            LL_segmento seg = NULL;
            
            // Seleciona o segmento correspondente (s1 ou s2)
            if (i == 0)
                seg = BuscarSegmentoPorID(inicioSg, inter->s1);
            else
                seg = BuscarSegmentoPorID(inicioSg, inter->s2);

            // Se o segmento não for encontrado, termina o programa
            if (!seg)
                FalhaMalloc(NULL, inicioS);

            // Busca o primeiro vértice do segmento
            LL_vertice vert1 = BuscarVerticePorId(inicioS, seg->freq, seg->V1);
            if (!vert1)
                FalhaMalloc(NULL, inicioS);

            // Busca o segundo vértice do segmento
            LL_vertice vert2 = BuscarVerticePorId(inicioS, seg->freq, seg->V2);
            if (!vert2)
                FalhaMalloc(NULL, inicioS);

            // Impressão formatada dos segmentos e seus vértices
            if (i == 0) {
                printf("\n\n\33[32m>\33[0m Segmento %d, f: '%c' ((%d, %d)-(%d, %d))", 
                       inter->s1, seg->freq, vert1->m, vert1->n, vert2->m, vert2->n);
                inicioA = MarcaAntena(inicioA, vert1->m, vert1->n);
                inicioA = MarcaAntena(inicioA, vert2->m, vert2->n);
                       
                printf("\n\33[32m--- Interceta ---\33[0m\n");
            } else {
                printf("\33[32m>\33[0m Segmento %d, f: '%c' ((%d, %d)-(%d, %d))", 
                       inter->s2, seg->freq, vert1->m, vert1->n, vert2->m, vert2->n);
                inicioA = MarcaAntena(inicioA, vert1->m, vert1->n);
                inicioA = MarcaAntena(inicioA, vert2->m, vert2->n);
            }
        }

        inter = inter->seguinte; ///< Avança para a próxima interseção
    }
    return inicioA;
}




// > RECEÇÃO E VERIFICAÇÃO DE INFORMAÇÃO 

/**
 * @brief Função responsável por ler um número inteiro do utilizador.

 * Garante que o input é válido, ignorando letras e outros símbolos.
 * 
 * @return Um número inteiro válido introduzido pelo utilizador.
 */
int LeInteiro() {
    int inteiro = 0;

    printf("\n >\33[32m ");
    // Repete até o utilizador introduzir um inteiro válido
    while ((scanf("%i", &inteiro) != 1)) {
        // Mensagem de erro e limpeza do buffer
        printf("\33[31m> Introduza uma opção válida.\33[0m\n> ");
        while (getchar() != '\n');
    }
    printf("\33[0m");

    return inteiro;
}


/**
 * @brief Função responsável por ler um único caractere do utilizador.
 * 
 * Ignora espaços, enters ou múltiplos caracteres inseridos.
 * 
 * @return O caractere válido introduzido pelo utilizador.
 */
char LeCaracter() {
    char caracter;
    printf("\n >\33[32m ");

    // Espaço antes de %c garante que ignora espaços anteriores
    scanf(" %c", &caracter);

    // Limpa o buffer caso o utilizador escreva mais de um carácter
    while (getchar() != '\n');

    printf("\33[0m");

    return caracter;
}


/**ç
 * @brief Função que solicita uma frequência válida ao utilizador.
 * 
 * Mostra as frequências disponíveis e valida a escolha do utilizador.
 * 
 * @param inicioS Ponteiro para o início da lista de subgrafos.
 * 
 * @return A frequência válida introduzida pelo utilizador.
 */
char ObterFrequencia(LL_subgrafos inicioS) {
    void *aux = NULL;
    char frequencia;

    limparTerminal();
    ImprimirSubgrafos(inicioS); // Mostra as frequências disponíveis

    // Continua a pedir até o utilizador inserir uma frequência existente
    
    while (aux == NULL) {
        printf("\n\n> Introduza a frequência do vértice que pretende analisar: ");
        frequencia = LeCaracter();
        aux = ImprimirVerticeSubgrafo(inicioS, frequencia);

        // Se a frequência não for válida, repete o processo
        if (!aux) {
            printf("\33[31m> Frequência não encontrada!\n\33[0m\n\n");
            AvisoAvancar();
            limparTerminal();
            ImprimirSubgrafos(inicioS);
        }
    }

    return frequencia;
}


/**
 * @brief Função que solicita ao utilizador um ID de vértice válido.
 * 
 * Valida o ID dentro da frequência previamente escolhida pelo utilizador.
 * 
 * @param inicioS Ponteiro para o início da lista de subgrafos.
 * @param frequencia Frequência escolhida pelo utilizador.
 * 
 * @return O ID de vértice válido.
 */
int ObterVertice(LL_subgrafos inicioS, char frequencia) {
    void *aux = NULL;
    int vertice;

    limparTerminal();
    ImprimirVerticeSubgrafo(inicioS, frequencia); // Mostra os vértices disponíveis nessa frequência

    // Continua a pedir até o utilizador inserir um vértice válido
    while (aux == NULL) {
        printf("\n\n> Introduza o ID do vértice: ");
        vertice = LeInteiro();
        aux = VerificarVertice(inicioS, frequencia, vertice);

        // Se o vértice não for encontrado, mostra aviso e repete
        if (!aux) {
            printf("\33[31m> Vértice não encontrado!\n\33[0m\n\n");
            AvisoAvancar();
            limparTerminal();
            ImprimirVerticeSubgrafo(inicioS, frequencia);
        }
    }

    return vertice;
}


/**
 * @brief Função que pede ao utilizador o caminho do ficheiro a ser lido.
 * 
 * O caminho é guardado na string 'caminho' passada por referência.
 * 
 * @param caminho Ponteiro para a string onde o caminho será armazenado.
 */
void obterCaminhoFicheiro(char* caminho) {
    printf("\n\n\n> Adicione o caminho parcial do ficheiro que pretende ler.");
    printf("\n\n>\33[32m ");
    scanf("%255s", caminho); // Lê até 255 caracteres (limite definido para segurança)
    while (getchar() != '\n');  // Limpa o buffer para evitar interferência com próximas leituras
    printf("\33[0m");
}




// > SAÍDAS DO SISTEMA

/**
 * @brief Função responsável por tratar uma falha de alocação de memória (malloc).
 * 
 * Liberta toda a memória alocada antes de terminar o programa abruptamente.
 * 
 * @param inicioA Ponteiro para a lista de antenas.
 * @param inicioS Ponteiro para a lista de subgrafos.
 */
void FalhaMalloc(LL_antena inicioA, LL_subgrafos inicioS) {
    // Mensagem de erro visual destacada a vermelho
    printf("\33[31m> Alocação de memória falhou.");
    printf(" A forçar termino do programa...\33[0m");

    // Liberta a memória alocada para antenas e subgrafos
    inicioA = LibertarAntenas(inicioA);
    inicioS = LibertarSubgrafos(inicioS);

    // Termina imediatamente o programa com código de erro
    exit(EXIT_FAILURE);
}


/**
 * @brief Função chamada quando o programa termina com sucesso.
 */
void SaidaSucesso() {
    // Mensagem de saída visual destacada a verde
    printf("\n\n\n\33[32m> A terminar programa...\33[0m");

    // Termina o programa normalmente com código de sucesso
    exit(EXIT_SUCCESS);
}





