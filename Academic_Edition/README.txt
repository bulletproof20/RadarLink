Esta pasta deve conter:

- Pasta `cidades` com ficheiros de teste (cidades)
- Pasta `src` com todos os ficheiros secundários do código (headers `.h` e implementações `.c`)

  Ficheiros relacionados no mesmo diretório:
    - `estruturas.h`
    - `interface.c`
    - `interface.h`
    - `process_esp.c`
    - `process_esp.h`
    - `process_ficheiro.c`
    - `process_ficheiro.l`
    - `process_geral.c`
    - `process_geral.h`

    Estes ficheiros constituem, em conjunto, os principais módulos do sistema.

- Ficheiro `main.c` fora da pasta `src`
- Pasta com alguns dos esquemas feitos em `.draw.isto`
- Enunciado do trabalho




Em caso de necessidade de compilar o programa manualmente com o `gcc`, recomenda-se usar o seguinte comando no terminal:

    gcc -I src main.c src/*.c -o Programa

Desta forma:
- O compilador vai procurar os ficheiros `.h` dentro da pasta `src`  
- Vai compilar todos os ficheiros `.c` dessa mesma pasta  
- E no fim, vai gerar um executável chamado `Programa`


Para adicionar imagem
    windres recurso.rc -o recurso.o
    gcc -I src main.c src/*.c recurso.o -o Programa.exe


No programa, para esclarecimento de dados existentes, quando no menu principal existem os comandos:

- 601: Apresenta a estrutura em como os dados estão registados (subgrafo(vertice(aresta)));
- 602: Apresenta todos os segmentos;
- 603: Apresenta todos os pares de segmentos, com frequências diferentes, possíveis.

Cumps,  
Ivo Sá
