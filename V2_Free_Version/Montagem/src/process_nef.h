/**
 * @file    process_nef.h
 * @brief   
 *
 * @details 
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



#ifndef PROCESS_NEF_H
#define PRECESS_NEF_H

#include "estruturas.h"

LL_antena IdentificarNefastos(LL_antena inicioA, LL_subgrafos inicioG, int n_linhas, int n_colunas);
LL_antena RemoverNefasto(LL_antena inicio);

#endif