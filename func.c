#include "func.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void imprime_menu()
{
    #if defined _WIN32 || defined _WIN64
        system("cls");
    #else
        system("clear");
    #endif

    printf("Menu:");
    printf("\n1.\tInderir aluno");
    printf("\n2.\tRemover aluno");
    printf("\n3.\tBuscar aluno por RA");
    printf("\n4.\tImprimir turma");
    printf("\n5.\tEncerrar programa");
}