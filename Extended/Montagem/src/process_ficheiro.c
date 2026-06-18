/**
 * @file    process_ficheiro.c
 * @brief   Módulo responsável pela receção, validação e manipulação inicial dos dados lidos de ficheiros.
 * 
 * @details Este módulo tem como objetivo gerir os dados extraídos de ficheiros de texto no contexto da gestão de antenas
 *          numa matriz bidimensional. Ele abrange as funcionalidades principais:
 *          - Inserção ordenada de antenas numa lista ligada (por linha e coluna), evitando duplicados.
 *          - Remoção de antenas com base na sua localização (usada apenas para remover nó fictício).
 *          - Verificação da validade estrutural da matriz extraída do ficheiro (mínimo 2x2).
 *          - Tratamento de erros de leitura de ficheiros, permitindo nova tentativa ou término do programa.
 *          - Criação de um nó provisório com as dimensões da matriz.
 *          - Conversão de uma linha de ficheiro para uma lista ligada de caracteres.
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




#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"
#include "interface.h"
#include "process_geral.h"
#include "process_ficheiro.h"
#include "process_esp.h"
#include "process_nef.h"
 


// > RECEÇÃO E MANIPULAÇÃO INICIAL DE DADOS DO FICHEIRO





/**
 * @brief Verifica a validade do ficheiro de entrada, garantindo que tem pelo menos 2 linhas e 2 colunas.
 * 
 * Esta função valida as dimensões do ficheiro lido, verificando se ele possui pelo menos 2 linhas e 2 colunas.
 *
 * @param linha Número de linhas do ficheiro.
 * @param max_coluna Número máximo de colunas no ficheiro.
 * 
 * @return 1 se o ficheiro for válido, 0 caso contrário.
 */
int verificarValidade(int linha, int max_coluna) {

    // Verificar se a matriz tem pelo menos 2 linhas e 2 colunas
    if (linha < 2 || max_coluna < 2) {
        // Exibir mensagem de erro caso as dimensões sejam inválidas
        printf("\n\n\33[31m> Matriz inválida.\33[0m");
        return 0; // Ficheiro inválido
    }

    // Se as dimensões forem válidas, retornar sucesso
    return 1; // Ficheiro válido
}


/**
 * @brief Trata erro ao ler o ficheiro e oferece opções ao utilizador.
 * 
 * Esta função exibe uma mensagem de erro e oferece ao utilizador a opção de inserir um novo caminho para o ficheiro
 * ou de terminar o programa.
 *
 * @param sair Variável para armazenar a decisão do utilizador (0 para novo caminho, 1 para terminar).
 * @param caminho Caminho do ficheiro que causou o erro.
 * 
 * @return A decisão do utilizador (0 ou 1).
 */
int ErroFicheiro(int sair, const char caminho[256]) {

    // Exibir a mensagem de erro com o caminho do ficheiro
    printf("\33[31m\n> Erro: %s\n\33[0m", caminho);

    // Exibir as opções para o utilizador
    printf("\n\n> \33[32m(0)\33[0m Inserir novo caminho;\n> \33[32m(1)\33[0m Terminar programa.\n> \33[32m");

    // Validar a entrada do utilizador
    while ((scanf("%i", &sair) != 1) || (sair < 0 || sair > 1)) {
        // Se a opção não for válida, pedir ao utilizador para inserir uma nova opção
        printf("\33[31m> Introduza uma opção válida.\33[0m\n> ");
        
        // Limpar o buffer de entrada
        while (getchar() != '\n');
        printf("\33[0m");
    }
    
    return sair; // Retornar a decisão do utilizador
}


/**
 * @brief Cria um nó provisório caso não existam antenas na lista ligada.
 * 
 * Caso a lista esteja vazia, esta função cria um nó provisório, definindo a linha e a coluna como valores iniciais,
 * e o adiciona ao início da lista.
 *
 * @param inicioA Ponteiro para o início da lista ligada de antenas.
 * @param linha Número da linha do nó provisório.
 * @param max_coluna Número máximo de colunas encontrado no ficheiro.
 * 
 * @return Ponteiro para o início da lista ligada com o nó provisório.
 */
LL_antena criarNoProvisorio(LL_antena inicioA, int linha, int max_coluna) {

    // Alocar memória para o novo nó
    LL_antena NoProvisorio = malloc(sizeof(struct antena));
    
    // Verificar se a alocação falhou
    if (NoProvisorio == NULL) {
        // Chama a função FalhaMalloc caso a alocação de memória falhe
        FalhaMalloc(inicioA, NULL); 
    }

    // Definir os valores do novo nó
    NoProvisorio->seguinte = inicioA;
    NoProvisorio->m = linha;
    NoProvisorio->n = max_coluna;

    // Retornar o novo nó, agora no início da lista
    return NoProvisorio;
}


/**
 * @brief Lê uma linha do ficheiro e cria uma lista ligada de letras.
 * 
 * Esta função lê os caracteres de uma linha do ficheiro até encontrar uma nova linha ('\n') ou o fim do ficheiro (EOF).
 * Cada caractere lido é armazenado em um nó de uma lista ligada de letras.
 *
 * @param ficheiro Ponteiro para o ficheiro a ser lido.
 * 
 * @return Ponteiro para o início da lista ligada com os caracteres lidos.
 */
LL_letras LerLinhaParaFila(FILE* ficheiro) {
    LL_letras inicioL = NULL, fim = NULL;  // Ponteiros para o início e fim da lista ligada de letras
    char ch;

    // Lê os caracteres do ficheiro até encontrar o fim de linha ou o fim do ficheiro
    while ((ch = fgetc(ficheiro)) != EOF && ch != '\n') {
        LL_letras novaLetra = malloc(sizeof(struct Letra));  // Aloca memória para um novo nó
        if (novaLetra == NULL) return NULL;  // Se falhar a alocação de memória, retorna NULL

        novaLetra->caracter = ch;  // Atribui o caractere lido ao nó
        novaLetra->seguinte = NULL;  // O próximo nó é inicialmente NULL

        // Se a lista estiver vazia, o novo nó é o primeiro e o único da lista
        if (inicioL == NULL)
            inicioL = fim = novaLetra;
        else {
            // Se a lista já tiver elementos, adiciona o novo nó no final
            fim->seguinte = novaLetra;
            fim = novaLetra;  // Atualiza o ponteiro do fim para o novo nó
        }
    }

    return inicioL;  // Retorna a lista ligada com as letras lidas
}


/**
 * @brief Processa o ficheiro e cria uma lista ligada de antenas a partir dos dados lidos.
 * 
 * Esta função lê as linhas do ficheiro e, para cada caractere diferente de '.' ou espaço, insere uma antena na lista.
 * O número de linhas e colunas é monitorizado para garantir que o ficheiro tenha dimensões válidas.
 *
 * @param ficheiro Ponteiro para o ficheiro a ser lido.
 * @param inicioA Ponteiro para o início da lista ligada de antenas.
 * 
 * @return Ponteiro para o início da lista ligada com as antenas inseridas.
 */
LL_antena processarFicheiro(FILE* ficheiro, LL_antena inicioA) {
    int linha = 0;  // Contador de linhas do ficheiro
    int max_coluna = 0;  // Armazena o número máximo de colunas encontradas

    while (1) {
        // Lê uma linha do ficheiro e converte-a em uma lista ligada de letras
        LL_letras fila = LerLinhaParaFila(ficheiro);
        if (fila == NULL) break;  // Se não houver mais linhas, termina o loop

        LL_letras atual = fila;  // Ponteiro para percorrer a lista de letras
        int coluna = 0;  // Contador de colunas da linha atual

        // Percorre a lista de letras da linha atual
        while (atual != NULL) {
            // Se o caractere não for '.' nem espaço, insere uma antena
            if (atual->caracter != '.' && atual->caracter != ' ') 
                inicioA = InserirAntena(inicioA, linha + 1, coluna + 1, atual->caracter);

            coluna++;  // Incrementa a contagem de colunas
            atual = atual->seguinte;  // Move para o próximo caractere na lista
        }

        // Liberta a memória da lista de letras lida
        fila = LibertarLetras(fila);

        // Atualiza o número máximo de colunas se necessário
        if (coluna > max_coluna) max_coluna = coluna;
        linha++;  // Incrementa a contagem de linhas
    }

    // Verifica a validade do ficheiro com base no número de linhas e colunas
    if (!verificarValidade(linha, max_coluna))
        inicioA = LibertarAntenas(inicioA);  // Se inválido, liberta as antenas
    else if (inicioA != NULL)
        inicioA = criarNoProvisorio(inicioA, linha, max_coluna);  // Cria um nó provisório caso válido

    return inicioA;  // Retorna a lista ligada de antenas processadas
}


/**
 * @brief Função responsável por ler e processar um ficheiro fornecido pelo utilizador.
 * 
 * Esta função solicita o caminho de um ficheiro e, se o caminho for válido, processa o ficheiro 
 * para extrair informações e armazená-las numa lista ligada. A função repetidamente pede ao utilizador
 * para fornecer o caminho do ficheiro até que um ficheiro válido seja processado com sucesso.
 * 
 * @param[in] inicioA A lista ligada inicial de antenas a ser preenchida.
 * 
 * @return A lista ligada de antenas após o processamento do ficheiro. 
 *         Retorna a lista ligada atualizada com os dados extraídos do ficheiro fornecido.
 */
LL_antena lerFicheiro(LL_antena inicioA) {
    char caminho[256];  // Variável para armazenar o caminho do ficheiro
    int sair = -1;

    while (1) {
        sair = -1;  // Inicializa o estado de saída
        printf("\33[0m");
        instrucoesFile();  // Mostra as instruções para o utilizador
        obterCaminhoFicheiro(caminho);  // Obtém o caminho do ficheiro a ser lido

        FILE *ficheiro = fopen(caminho, "r");  // Abre o ficheiro no modo de leitura

        if (ficheiro == NULL) 
            sair = ErroFicheiro(sair, caminho);  // Se o ficheiro não puder ser aberto, trata o erro

        if (sair == 1) 
            SaidaSucesso();  // Se o ficheiro foi processado com sucesso, sai
        else if (sair == 0) continue;  // Se houver erro, pede para o utilizador tentar novamente

        // Processa o ficheiro e armazena as antenas na lista ligada
        inicioA = processarFicheiro(ficheiro, inicioA);
        fclose(ficheiro);  // Fecha o ficheiro após o processamento

        if (inicioA == NULL) {
            sair = ErroFicheiro(sair, caminho);  // Se não houve antenas processadas, trata o erro
            if (sair == 1) 
                SaidaSucesso();  // Se o ficheiro for válido, encerra com sucesso
        } else break;  // Se o ficheiro foi processado com sucesso, sai do loop
        
    }

    printf("\n\n >\33[0m ");
    return inicioA;  // Retorna a lista de antenas processadas
}




// > REORGANIZAÇÃO DOS DADOS DO FICHEIRO EM GRAFO

/**
 * @brief Função principal para criar o grafo completo agrupando as antenas por frequência.
 * 
 * Esta função cria subgrafos a partir da lista de antenas e, em seguida, cria arestas entre
 * os vértices dentro de cada subgrafo, formando um grafo completo.
 *
 * @param inicioA Ponteiro para a lista de antenas.
 * @param inicioS Ponteiro para a lista de subgrafos.
 * 
 * @return Ponteiro para a lista de subgrafos com as antenas agrupadas e as arestas formadas.
 */
LL_subgrafos CriarGrafo(LL_antena inicioA, LL_subgrafos inicioS) {
    // Passo 1: Criar subgrafos a partir das antenas, agrupando-as por frequência
    inicioS = CriarSubgrafos(inicioA, inicioS);

    // Passo 2: Criar arestas entre os vértices dentro de cada subgrafo, completando o grafo
    inicioS = CriarArestasSubgrafosCompleto(inicioS);

    // Retornar o início da lista de subgrafos, agora com as antenas agrupadas e com as arestas formadas
    return inicioS;
}


/**
 * @brief Função responsável por criar subgrafos a partir das antenas.
 * 
 * Esta função percorre a lista de antenas e cria ou encontra um subgrafo para cada antena,
 * agrupando as antenas por frequência. Também cria vértices para cada antena e os associa aos
 * subgrafos correspondentes.
 *
 * @param inicioA Ponteiro para a lista de antenas.
 * @param inicioS Ponteiro para a lista de subgrafos.
 * 
 * @return Ponteiro para a lista de subgrafos com os vértices associados às antenas.
 */
LL_subgrafos CriarSubgrafos(LL_antena inicioA, LL_subgrafos inicioS) {
    LL_antena actual = inicioA;

    while (actual != NULL) {
        // Passo 1: Encontrar ou criar um subgrafo com a mesma frequência da antena atual
        inicioS = CriarOuEncontrarSubgrafo(inicioS, actual->f);

        // Passo 2: Criar um vértice e associá-lo ao subgrafo encontrado/criado
        inicioS = CriarVerticeNoSubgrafo(inicioS, actual);

        // Avançar para a próxima antena na lista
        actual = actual->seguinte;
    }
    actual = inicioA;
    while (actual != NULL){
        // Atribui id a todos os vertices
        inicioS = AtribuirIdsVertice(inicioS);
        // Avançar para a próxima antena na lista
        actual = actual->seguinte;
    }
    

    // Retornar o início da lista de subgrafos agora com os vértices associados às antenas
    return inicioS;
}


/**
 * @brief Função responsável por criar ou encontrar um subgrafo baseado na frequência da antena.
 * 
 * A função verifica se já existe um subgrafo com a mesma frequência. Se não existir, cria
 * um novo subgrafo com essa frequência e o adiciona à lista de subgrafos.
 *
 * @param inicioS Ponteiro para a lista de subgrafos.
 * @param frequencia Frequência da antena.
 * 
 * @return Ponteiro para a lista de subgrafos, com o novo ou existente subgrafo.
 */
LL_subgrafos CriarOuEncontrarSubgrafo(LL_subgrafos inicioS, char frequencia) {
    LL_subgrafos subgrafo_atual = inicioS, subgrafo_anterior = NULL;

    // Passo 1: Procurar por um subgrafo com a mesma frequência
    while (subgrafo_atual != NULL && subgrafo_atual->f != frequencia) {
        subgrafo_anterior = subgrafo_atual;
        subgrafo_atual = subgrafo_atual->seguinte;
    }

    // Passo 2: Se não encontrar um subgrafo com essa frequência, criar um novo subgrafo
    if (subgrafo_atual == NULL) {
        // Alocar memória para o novo subgrafo
        subgrafo_atual = malloc(sizeof(struct subgrafos));
        if (subgrafo_atual == NULL) FalhaMalloc(NULL, inicioS); // Verificação de falha de alocação

        // Inicializar o subgrafo com a frequência e outros parâmetros
        subgrafo_atual->f = frequencia;
        subgrafo_atual->lista_vertice = NULL; // Não há vértices associados inicialmente
        subgrafo_atual->seguinte = NULL; // Será o último na lista por enquanto

        // Adicionar o novo subgrafo à lista
        if (inicioS == NULL) {
            inicioS = subgrafo_atual; // Se não houver subgrafos, o novo será o primeiro
        } else {
            subgrafo_anterior->seguinte = subgrafo_atual; // Se houver, adiciona no final da lista
        }
    }

    // Retornar a lista de subgrafos, com o novo ou existente subgrafo
    return inicioS;
}


/**
 * @brief Função responsável por criar um vértice e associá-lo ao subgrafo correto.
 * 
 * A função encontra o subgrafo correspondente à antena e cria um vértice associado à antena.
 * O vértice é inserido na lista de vértices do subgrafo de forma ordenada.
 *
 * @param inicioS Ponteiro para a lista de subgrafos.
 * @param antena Ponteiro para a antena atual.
 * 
 * @return Ponteiro para a lista de subgrafos com o novo vértice inserido.
 */
LL_subgrafos CriarVerticeNoSubgrafo(LL_subgrafos inicioS, LL_antena antena) {
    LL_subgrafos subgrafo_atual = inicioS;

    // Passo 1: Encontrar o subgrafo correspondente à frequência da antena
    while (subgrafo_atual != NULL && subgrafo_atual->f != antena->f) {
        subgrafo_atual = subgrafo_atual->seguinte;
    }

    // Passo 2: Se o subgrafo não for encontrado, retorna a lista de subgrafos (isso não deveria acontecer, pois os subgrafos são criados na função anterior)
    if (subgrafo_atual == NULL) return inicioS;

    // Passo 3: Criar novo vértice
    LL_vertice novo_vertice = malloc(sizeof(struct vertice));
    if (novo_vertice == NULL) FalhaMalloc(NULL, inicioS); // Verifica falha na alocação de memória

    // Inicializar os atributos do novo vértice com os dados da antena
    novo_vertice->id = 1;  // O ID será atribuído mais tarde, após o contador
    novo_vertice->m = antena->m;
    novo_vertice->n = antena->n;
    novo_vertice->visto = 0;  // Inicialmente não foi visitado
    novo_vertice->lista_aresta = NULL; // Não há arestas inicialmente
    novo_vertice->seguinte = NULL; // Último vértice na lista por enquanto

    // Passo 4: Inserir o vértice de forma ordenada na lista de vértices do subgrafo
    subgrafo_atual->lista_vertice = InserirVerticeOrdenado(subgrafo_atual->lista_vertice, novo_vertice);

    // Retornar a lista de subgrafos (agora com o vértice inserido)
    return inicioS;
}


/**
 * @brief Função auxiliar para inserir vértices de forma ordenada na lista de vértices.
 * 
 * Os vértices são ordenados primeiro pelo valor de 'm' e, se iguais, pelo valor de 'n'.
 *
 * @param lista_vertice Ponteiro para a lista de vértices do subgrafo.
 * @param novo_vertice Vértice a ser inserido.
 * 
 * @return Ponteiro para a lista de vértices com o novo vértice inserido.
 */
LL_vertice InserirVerticeOrdenado(LL_vertice lista_vertice, LL_vertice novo_vertice) {
    LL_vertice vertice_atual = lista_vertice, vertice_anterior = NULL;

    // Passo 1: Encontrar a posição correta para inserir o novo vértice
    // O critério de ordenação é:
    // 1. 'm' em ordem crescente.
    // 2. Caso 'm' seja igual, ordena por 'n' em ordem crescente.
    while (vertice_atual != NULL && (vertice_atual->m < novo_vertice->m ||
              (vertice_atual->m == novo_vertice->m && vertice_atual->n < novo_vertice->n))) {
        vertice_anterior = vertice_atual;
        vertice_atual = vertice_atual->seguinte;
    }

    // Passo 2: Inserir o novo vértice na posição correta
    if (vertice_anterior == NULL) {
        // Inserção no início da lista
        novo_vertice->seguinte = lista_vertice;
        lista_vertice = novo_vertice;
    } else {
        // Inserção no meio ou fim da lista
        novo_vertice->seguinte = vertice_atual;
        vertice_anterior->seguinte = novo_vertice;
    }

    // Retornar a lista de vértices (com o novo vértice inserido na ordem correta)
    return lista_vertice;
}


/**
 * @brief Função para atribuir IDs sequenciais aos vértices de cada subgrafo.
 * 
 * Esta função percorre todos os subgrafos e atribui IDs sequenciais aos vértices dentro de cada
 * subgrafo.
 *
 * @param inicioS Ponteiro para a lista de subgrafos.
 * 
 * @return Ponteiro para a lista de subgrafos com os vértices atribuídos com IDs.
 */
LL_subgrafos AtribuirIdsVertice(LL_subgrafos inicioS) {
    LL_subgrafos subgrafo_atual = inicioS;

    // Percorrer todos os subgrafos existentes na lista
    while (subgrafo_atual != NULL) {
        LL_vertice vertice_atual = subgrafo_atual->lista_vertice;
        int id = 1;  // Iniciar a contagem dos IDs a partir de 1

        // Percorrer todos os vértices do subgrafo atual
        while (vertice_atual != NULL) {
            vertice_atual->id = id++;  // Atribuir o ID atual e depois incrementá-lo
            vertice_atual = vertice_atual->seguinte;  // Passar para o próximo vértice
        }

        // Avançar para o próximo subgrafo da lista
        subgrafo_atual = subgrafo_atual->seguinte;
    }

    // Retornar o ponteiro para o início da lista de subgrafos (útil para manter continuidade no programa)
    return inicioS;
}


/**
 * @brief Função que liga todos os vértices entre si dentro de cada subgrafo, criando um grafo completo.
 * 
 * Esta função percorre cada subgrafo e, para cada vértice dentro do subgrafo, cria arestas ligando-o a todos os outros vértices (exceto a si mesmo). 
 * As arestas são adicionadas às listas de arestas dos vértices, de forma a manter a ordem de inserção.
 * 
 * @param inicioS Ponteiro para a lista ligada de subgrafos.
 * 
 * @return Ponteiro para a lista ligada de subgrafos com as arestas completas.
 */
LL_subgrafos CriarArestasSubgrafosCompleto(LL_subgrafos inicioS) {
    LL_subgrafos atualS = inicioS;

    // Percorre todos os subgrafos
    while (atualS != NULL) {
        LL_vertice origem = atualS->lista_vertice;

        // Para cada vértice 'origem'
        while (origem != NULL) {
            LL_vertice destino = atualS->lista_vertice;

            // Compara com todos os outros vértices (evita ligar a ele próprio)
            while (destino != NULL) {
                if (origem != destino) {
                    // Aloca espaço para nova aresta
                    LL_aresta novaAresta = malloc(sizeof(struct aresta));
                    if (novaAresta == NULL) FalhaMalloc(NULL, inicioS); // erro se não conseguir alocar

                    // Inicializa os dados da nova ligação
                    novaAresta->id = destino->id;
                    novaAresta->m = destino->m;
                    novaAresta->n = destino->n;
                    novaAresta->visto = 0;
                    novaAresta->seguinte = NULL;  // Sem isto, ficas com lixo e bugs bizarros

                    // Adiciona a aresta no fim da lista da origem (mantém ordem de inserção)
                    if (origem->lista_aresta == NULL) {
                        origem->lista_aresta = novaAresta;
                    } else {
                        LL_aresta temp = origem->lista_aresta;
                        while (temp->seguinte != NULL) temp = temp->seguinte;
                        temp->seguinte = novaAresta;
                    }
                }

                destino = destino->seguinte; // Avança para o próximo vértice destino
            }

            origem = origem->seguinte; // Avança para o próximo vértice origem
        }

        atualS = atualS->seguinte; // Avança para o próximo subgrafo
    }

    return inicioS; // Tudo feito, devolve os subgrafos com arestas completas
}





