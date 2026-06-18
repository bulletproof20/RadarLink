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
#include "process_nef.h"

 





int main() {
    // Introdução e aviso inicial
    intro();
    AvisoAvancar();

    // Declaração de variáveis
    LL_antena inicioA = NULL, aux=NULL;
    LL_subgrafos inicioS = NULL;
    LL_vertice inicioV = NULL;
    LL_aresta inicioAr = NULL;
    LL_segmento inicioSg = NULL;
    LL_Intercessoes inicioI = NULL;

    // Variáveis de controle de decisão
    int decisao = -1, linha, coluna, vertice;
    char frequencia;
    int n_linhas;
    int n_colunas;
    int men = 1;

    // Leitura e verificação da matriz da cidade
    while (decisao != 0) {
        // Limpa antenas anteriores e lê o novo ficheiro
        inicioA = LibertarAntenas(inicioA);
        inicioA = lerFicheiro(inicioA);

        // Guarda as dimensões da matriz após leitura
        n_linhas = inicioA->m;
        n_colunas = inicioA->n;

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
        

        // Exibe o menu e aguarda a opção do utilizador
        while (1) {
            menu(men);
            decisao = LeInteiro();
            if (decisao >= 1 && (decisao <= 6 || decisao==10)) break;
                
            printf("\33[31m> Opção inválida.\33[0m\n");
            AvisoAvancar();
        }

        // Switch para as ações do menu
        switch (decisao) {
            case 1:  // Manipular ficheiro(pronto)
                decisao=0;
                while (decisao!=3)
                {
                    while (1) {
                        menu1();
                        decisao = LeInteiro();
                        if (decisao >= 1 && decisao <= 3 ) break;
            
                        printf("\33[31m> Opção inválida.\33[0m\n");
                        AvisoAvancar();
                    }
                    char freq;
                    int lin, col;
                    if (decisao!=3){
                        if(decisao==1){
                            
                            inicioA = ApresentaMatriz(inicioA, n_linhas, n_colunas);
                            printf("\n\n> Defina a frequencia da nova antena.\n");
                            freq = LeCaracter();
                            limparTerminal();
                            inicioA = ApresentaMatriz(inicioA, n_linhas, n_colunas);
                            printf("\n\n> Defina a linha da nova antena.\n");
                            lin = LeInteiro();
                            limparTerminal();
                            inicioA = ApresentaMatriz(inicioA, n_linhas, n_colunas);
                            printf("\n\n> Defina a coluna da nova antena.\n");
                            col = LeInteiro();
                            limparTerminal();
                            if((lin>0 && lin<=n_linhas)&&(col>0 && col<=n_colunas)&&((freq!='#')&&(freq!='.'))){
                                inicioA = InserirAntena(inicioA, lin, col, freq);
                                AvisoAvancar();

                                
                                inicioS = LibertarSubgrafos(inicioS);
                                inicioS = CriarSubgrafos(inicioA, inicioS);
                                inicioS = CriarArestasSubgrafosCompleto(inicioS);

                            }else{
                                printf("\33[31m> Dados inválidos.\33[0m");
                                AvisoAvancar();
                            }

                        }else{
                            inicioA = ApresentaMatriz(inicioA, n_linhas, n_colunas);
                            printf("\n\n> Defina a linha da antena a remover.\n");
                            lin = LeInteiro();
                            limparTerminal();
                            inicioA = ApresentaMatriz(inicioA, n_linhas, n_colunas);
                            printf("\n\n> Defina a coluna da antena a remover.\n");
                            col = LeInteiro();
                            limparTerminal();
                            if((lin>0 && lin<=n_linhas)&&(col>0 && col<=n_colunas)){
                                aux = RemoverAntena(inicioA, lin, col);
                                if(aux){
                                    inicioA = aux;
                                    aux = NULL;
                                    inicioS = LibertarSubgrafos(inicioS);
                                    inicioS = CriarSubgrafos(inicioA, inicioS);
                                    inicioS = CriarArestasSubgrafosCompleto(inicioS);
                                }

                            }else printf("\33[31m> Dados inválidos.\33[0m");
                            AvisoAvancar();
                            
                        }
                    
                    }
                    
                }
                decisao=0;
                break;
                
                

            case 2: // Analise dos dados registados(pronta)
                decisao=0;
                while (decisao!=5)
                {
                    while (1) {
                        menu2();
                        decisao = LeInteiro();
                        if (decisao >= 1 && decisao <= 5 ) break;
            
                        printf("\33[31m> Opção inválida.\33[0m\n");
                        AvisoAvancar();
                    }
                    switch(decisao){
                        case 1:
                            frequencia = ObterFrequencia(inicioS);
                            int v1 = ObterVertice(inicioS, frequencia);
                            int v2 = ObterVertice(inicioS, frequencia);
                            
                            limparTerminal();
                            printf("\n\n> Caminhos possíveis entre vértices %i e %i, no subgrafo %c\n\n", v1, v2, frequencia);
                            CaminhosEntreVertices(inicioS, frequencia, v1, v2);
                            AvisoAvancar();
                            break;

                        case 2:

                            frequencia = ObterFrequencia(inicioS);
                            vertice = ObterVertice(inicioS, frequencia);
                            
                            limparTerminal();
                            printf("\n\n> Travessia em profundidade no subgrafo %c, com início no vértice %i\n\n", frequencia, vertice);
                            inicioS = TravessiaProfundidade(inicioS, frequencia, vertice);
                            AvisoAvancar();
                            break;

                        case 3:
                            frequencia = ObterFrequencia(inicioS);
                            vertice = ObterVertice(inicioS, frequencia);
                            
                            limparTerminal();
                            printf("\n\n> Travessia em largura no subgrafo %c, com início no vértice %i\n\n", frequencia, vertice);
                            inicioS = TravessiaLargura(inicioS, frequencia, vertice);
                            AvisoAvancar();
                            break;
                        
                        case 4:
                            inicioI = LibertarIntercessao(inicioI);
                            inicioSg = GerarSegmentos(inicioS, inicioSg);
                            inicioI = GerarIntersecoes(inicioSg);
                            inicioI = MostrarPontosIntersecao(inicioI, inicioSg, inicioS);
                            
                            limparTerminal();
                            MostrarIntersecoes(inicioI, inicioSg, inicioS, inicioA);
                            inicioA = ResetMarc(inicioA);
                            AvisoAvancar();

                    }  
                    
                }
                decisao=0;
                break;

            case 3: // Analisar ficheiro
                decisao=0;
                while (decisao!=4)
                {
                    while (1) {
                        menu3();
                        decisao = LeInteiro();
                        if (decisao >= 1 && decisao <= 4 ) break;
            
                        printf("\33[31m> Opção inválida.\33[0m\n");
                        AvisoAvancar();
                    }
                    switch(decisao){
                        case 1:
                            ApresentaMatriz(inicioA, n_linhas, n_colunas);
                            AvisoAvancar();
                            break;

                        case 2:

                            // gerar efeitos nefastos

                            limparTerminal();
                            inicioA=IdentificarNefastos(inicioA, inicioS, n_linhas, n_colunas);
                            inicioA=ApresentaMatriz(inicioA, n_linhas, n_colunas);
                            inicioA=RemoverNefasto(inicioA);
                            AvisoAvancar();
                            
                            break;

                        case 3:
                            inicioI = LibertarIntercessao(inicioI);
                            inicioSg = GerarSegmentos(inicioS, inicioSg);
                            inicioI = GerarIntersecoes(inicioSg);
                            inicioI = MostrarPontosIntersecao(inicioI, inicioSg, inicioS);
                            MostrarIntersecoes(inicioI, inicioSg, inicioS, inicioA);
                            limparTerminal();
                            inicioA=ApresentaMatriz(inicioA, n_linhas, n_colunas);
                            inicioA = ResetMarc(inicioA);
                            AvisoAvancar();

                            break;
                            
                    }  
                    
                }
                decisao=0;
                break;
                    

            case 4: // Estruturas de dados criadas (pronto)
                    decisao=0;
                    while (decisao!=4){
                        while (1) {
                            menu4();
                            decisao = LeInteiro();
                            if (decisao >= 1 && decisao <= 4 ) break;
                
                            printf("\33[31m> Opção inválida.\33[0m\n");
                            AvisoAvancar();
                        }
                        switch(decisao){
                            case 1: // Mostrar grafo completo da cidade (pronta)
                                limparTerminal();
                                ImprimirGrafo(inicioS);
                                AvisoAvancar();
                                break;

                            case 2: // Mostrar segmentos possíveis do grafo

                                limparTerminal();
                                inicioSg = NULL;
                                inicioSg = GerarSegmentos(inicioS, inicioSg);
                                ImprimirSegmentos(inicioSg);
                                inicioSg = LibertarSegmentos(inicioSg);
                                AvisoAvancar();
                                break;

                            case 3:  // Mostrar todos os pares de segmentos possíveis de diferentes frequências
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
                                
                        } 
                        
                    }
                    decisao=0;
                    break;

            case 5: // Novo ficheiro(pronta)
                while (decisao != 0) {
                    // Recarrega a cidade e suas antenas
                    inicioA = LibertarAntenas(inicioA);
                    inicioS = LibertarSubgrafos(inicioS);
                    inicioA = lerFicheiro(inicioA);
                    
                    n_linhas = inicioA->m;
                    n_colunas = inicioA->n;
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
            
            case 10:
                if(men == 1)men=0;
                else men = 1;
                break;

            default: // pronta
                inicioA = LibertarAntenas(inicioA);
                inicioS = LibertarSubgrafos(inicioS);
                inicioI = LibertarIntercessao(inicioI);
                printf("\n\n\n> A terminar programa...");
                exit(EXIT_SUCCESS); 
                break;
        }
        
        decisao = -1;
    }
}








