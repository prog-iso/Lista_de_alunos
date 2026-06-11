#ifndef __FUNC_H_
#define __FUNC_H_

typedef struct
{
    char nome[30];
    int RA; 
    float nota[3];
    int freq;        
} Aluno;

void imprime_menu();
int busca_aluno(Aluno* turma, int RA);
void adiciona_aluno(Aluno* turma, int RA);
void remove_aluno(Aluno* turma, int RA);
void imprime_turma(Aluno* turma);

#endif