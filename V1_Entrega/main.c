/**
 * @file    main.c
 * @brief   Gestão e seleção de funções para manipulação de antenas.
 * 
 * @details Este ficheiro tem como objetivo chamar funções que realizam operações de pesquisa e manipulação de antenas, 
 *          de forma eficiente, permitindo as seguintes ações:
 * 
 *          a. Chamar a função para procurar em profundidade a partir de uma antena, listando na consola as coordenadas das antenas 
 *             alcançadas.
 *          b. Chamar a função para procurar em largura a partir de uma antena, listando na consola as coordenadas das antenas 
 *             alcançadas.
 *          c. Chamar a função para identificar todos os caminhos possíveis entre duas antenas específicas, listando na consola a 
 *             sequência de arestas interligando as antenas.
 *          d. Chamar a função para listar na consola todas as interseções de pares de antenas com frequências de ressonância A 
 *             e B, indicando as respetivas coordenadas.
 * 
 *          No programa, para o esclarecimento de dados existentes, o menu principal apresenta os seguintes comandos:
 * 
 *          - 601: Apresenta a estrutura em que os dados estão registados (subgrafo(vertice(aresta))).
 *          - 602: Apresenta todos os segmentos.
 *          - 603: Apresenta todos os pares de segmentos, com frequências diferentes, possíveis.
 *
 * @note    A pasta `src`, localizada na mesma pasta de `main.c`, contém as implementações de todas as funções 
 *          utilizadas neste programa.
 * 
 *          Ficheiros presentes em `src`:
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
 * @author  Ivo Filipe Carvalho de Sá, a22604
 * @date    12/05/2025
 */







#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"
#include "interface.h"
#include "process_geral.h"
#include "process_ficheiro.h"
#include "process_esp.h"

 





int main() {
    // Introdução e aviso inicial
    intro();
    AvisoAvancar();

    // Declaração de variáveis
    LL_antena inicioA = NULL;
    LL_subgrafos inicioS = NULL;
    LL_vertice inicioV = NULL;
    LL_aresta inicioAr = NULL;

    // Variáveis de controle de decisão
    int decisao = -1, linha, coluna, vertice;
    char frequencia;

    // Leitura e verificação da matriz da cidade
    while (decisao != 0) {
        // Limpa antenas anteriores e lê o novo ficheiro
        inicioA = LibertarAntenas(inicioA);
        inicioA = lerFicheiro(inicioA);

        // Guarda as dimensões da matriz após leitura
        int n_linhas = inicioA->m;
        int n_colunas = inicioA->n;

        // Remove antenas inválidas ou obsoletas
        inicioA = RemoverAntena(inicioA, n_linhas, n_colunas);

        // Limpa o terminal e exibe a cidade carregada
        limparTerminal();
        printf("\n> Cidade carregada.\n");
        inicioA = ApresentaMatriz(inicioA, n_linhas, n_colunas);

        // Pergunta ao utilizador se deseja manter ou carregar outro ficheiro
        printf("\n\n> Pretende:\n");
        printf("> \33[32m(0)\33[0m Manter a matriz;\n");
        printf("> \33[32m(1)\33[0m Selecionar outro documento. \33[0m");
        
        // Espera pela decisão do utilizador
        while (1) {
            decisao = LeInteiro();
            if (decisao < 0 || decisao > 1)
                printf("\33[31m> Introduza uma opção válida.\33[0m\n> ");
            else 
                break;
        }
    }

    // Preparar subgrafos e verificar a construção
    limparTerminal();
    inicioS = CriarGrafo(inicioA, inicioS);

    // Menu de seleção de ações
    while (decisao != 6) {
        LL_subgrafos aux = NULL;

        // Exibe o menu e aguarda a opção do utilizador
        while (1) {
            menu();
            decisao = LeInteiro();
            if (decisao >= 1 && (decisao <= 6 || (decisao >= 601 && decisao <= 603))) break;
                
            printf("\33[31m> Opção inválida.\33[0m\n");
            AvisoAvancar();
        }

        // Switch para as ações do menu
        switch (decisao) {
            case 1: 
                frequencia = ObterFrequencia(inicioS);
                vertice = ObterVertice(inicioS, frequencia);
                
                limparTerminal();
                printf("\n\n> Travessia em profundidade no subgrafo %c, com início no vértice %i\n\n", frequencia, vertice);
                inicioS = TravessiaProfundidade(inicioS, frequencia, vertice);
                AvisoAvancar();
                break;

            case 2: 
                frequencia = ObterFrequencia(inicioS);
                vertice = ObterVertice(inicioS, frequencia);
                
                limparTerminal();
                printf("\n\n> Travessia em largura no subgrafo %c, com início no vértice %i\n\n", frequencia, vertice);
                inicioS = TravessiaLargura(inicioS, frequencia, vertice);
                AvisoAvancar();
                break;

            case 3: 
                frequencia = ObterFrequencia(inicioS);
                int v1 = ObterVertice(inicioS, frequencia);
                int v2 = ObterVertice(inicioS, frequencia);
                
                limparTerminal();
                printf("\n\n> Caminhos possíveis entre vértices %i e %i, no subgrafo %c\n\n", v1, v2, frequencia);
                CaminhosEntreVertices(inicioS, frequencia, v1, v2);
                AvisoAvancar();
                break;

            case 4: 
                // Gerar segmentos e interseções
                LL_segmento inicioSg = NULL;
                LL_Intercessoes inicioI = NULL;

                inicioSg = GerarSegmentos(inicioS, inicioSg);
                inicioI = GerarIntersecoes(inicioSg);
                inicioI = MostrarPontosIntersecao(inicioI, inicioSg, inicioS);
                
                limparTerminal();
                MostrarIntersecoes(inicioI, inicioSg, inicioS);
                AvisoAvancar();
                break;

            case 5:
                while (decisao != 0) {
                    // Recarrega a cidade e suas antenas
                    inicioA = LibertarAntenas(inicioA);
                    inicioS = LibertarSubgrafos(inicioS);
                    inicioA = lerFicheiro(inicioA);
                    
                    int n_linhas = inicioA->m, n_colunas = inicioA->n;
                    inicioA = RemoverAntena(inicioA, n_linhas, n_colunas);
                    
                    limparTerminal();
                    printf("\n> Cidade carregada.");
                    inicioA = ApresentaMatriz(inicioA, n_linhas, n_colunas);

                    // Pergunta se deseja manter ou carregar outro ficheiro
                    printf("\n\n> Pretende: \n> \33[32m(0)\33[0m Manter a matriz; \n> \33[32m(1)\33[0m Selecionar outro documento.\n> ");
                    while ((scanf("%d", &decisao) != 1) || (decisao < 0 || decisao > 1)) {
                        printf("\33[31m> Introduza uma opção válida.\33[0m\n> ");
                        while (getchar() != '\n');
                    }
                }

                limparTerminal();
                // Recria subgrafos
                inicioS = CriarSubgrafos(inicioA, inicioS);
                inicioS = CriarArestasSubgrafosCompleto(inicioS);
                break;

            case 601: // Mostrar grafo completo da cidade
                limparTerminal();
                ImprimirGrafo(inicioS);
                AvisoAvancar();
                break;

            case 602: // Mostrar segmentos possíveis do grafo
                limparTerminal();
                inicioSg = NULL;
                inicioSg = GerarSegmentos(inicioS, inicioSg);
                ImprimirSegmentos(inicioSg);
                inicioSg = LibertarSegmentos(inicioSg);
                AvisoAvancar();
                break;

            case 603: // Mostrar todos os pares de segmentos possíveis de diferentes frequências
                limparTerminal();
                inicioSg = NULL;
                inicioI = NULL;
                inicioSg = GerarSegmentos(inicioS, inicioSg);
                inicioI = GerarIntersecoes(inicioSg);
                ImprimirIntersecoes(inicioI);
                inicioSg = LibertarSegmentos(inicioSg);
                inicioI = LibertarIntercessao(inicioI);
                AvisoAvancar();
                break;

            default:
                inicioA = LibertarAntenas(inicioA);
                inicioS = LibertarSubgrafos(inicioS);
                printf("\n\n\n> A terminar programa...");
                exit(EXIT_SUCCESS); 
                break;
        }
        
        decisao = -1;
    }
}








