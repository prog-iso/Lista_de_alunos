#include "func.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void limpa_tela()
{
    #if defined _WIN32 || defined _WIN64
        system("cls");
    #else
        system("clear");
    #endif
}

void imprime_menu()
{
    limpa_tela();

    printf("Menu:");
    printf("\n1.\tInserir aluno");
    printf("\n2.\tRemover aluno");
    printf("\n3.\tBuscar aluno por RA");
    printf("\n4.\tImprimir turma");
    printf("\n5.\tEncerrar programa");
}

int busca_aluno(Aluno* turma, int tam_turma, int RA)
{
    for(int i=0; i<tam_turma; i++) if(turma[i].RA==RA) return i;
    return -1;
}

void adiciona_aluno(Aluno* turma, int quant_alunos, int RA)
{
    printf("Os dados desse aluno(a) são:\n");
    turma[quant_alunos].RA = RA;
    printf("\n\tJá sabemos que o RA é: %d", turma[quant_alunos].RA);
    printf("\n\tQual o nome desse(a) aluno(a)? ");
    fgets(turma[quant_alunos].nome, sizeof(turma[quant_alunos].nome), stdin);
    turma[quant_alunos].nome[strlen[turma[quant_alunos].nome]-1] = '\0';
    
    printf("\tQuais as notas das provas desse(a) aluno(a)?\n");
    for(int i=0; i<3; i++)
    {
        printf("\t\tNota da %dº prova: ", i+1);
        scanf("%f", &turma[quant_alunos].nota[i]);
    }
    printf("\tPor fim, qual a frequência desse(a) aluno(a)? ");
    scanf("%d", &turma[quant_alunos].freq);
    printf("\n\nPara voltar ao menu, aperte enter.");
    getchar();
    getchar();
}

void remove_aluno(Aluno* turma, int pos)
{
    printf("O aluno %s foi removido.", turma[pos].nome);
    turma[pos] = turma[pos-1];
    printf("\n\nPara voltar ao menu, aperte enter.");
    getchar();
}

void imprime_turma(Aluno* turma, int quant_alunos)
{
    printf("Os alunos da turma são:\n");
    for(inti=0; i<quant_alunos; i++)
    {
        printf("\nDados do(a) %dº aluno(a):");
        printf("\n\tNome: %s", turma[i].nome);
        printf("\n\tRA: %d", turma[i].RA);
        printf("\n\tNotas:");
        for(int j=0; j<3; j++)
        {
            printf(" %.2f,", turma[i].nota[j]);
        }
        printf("\b ");
        printf("\n\tFrequência: %d\n", turma[i].freq);
    }
    getchar();
}
