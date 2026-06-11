#include "func.h"

#include <stdio.h>
#include <locale.h>

#define MAX_ALUNOS 50

int main()
{
    setlocale(LC_ALL,"pt_BR.UTF-8");
    setlocale(LC_NUMERIC,"C");

    int quant_alunos = 0;
    Aluno turma[MAX_ALUNOS];

    int escolha = 0;
    while (escolha!=5)
    {
        imprime_menu();
        printf("\n\nDigite sua escolha: ");
        scanf("%d", &escolha);
        getchar();

        limpa_tela();

        switch (escolha)
        {
        case 1:
            if(quant_alunos==MAX_ALUNOS)
            {
                printf("Desculpa, a turma está lodata.\nSe quiser, pode voltar depois para ver se alguém desistiu.");
                printf("\n\\Para voltar ao menu, digite enter.");
                getchar();
            }
            else
            {
                int RA;
                printf("Primeiro, digite o RA,\npara sabermos se esse(a) aluno(a) já está matriculado(a)");
                printf("\nRA: ");
                scanf("%d", &RA);
                printf("\n");

                int pos = busca_aluno(turma, MAX_ALUNOS, RA);
                
                if(pos != -1)
                {
                    printf("Olha só, ele(a) já está matriculado(a) nessa turma.");
                    printf("\n\nPara voltar ao menu, aperte enter.");
                    getchar();
                }
                else
                {
                    adiciona_aluno(turma, quant_alunos, RA);
                }
            }
            
            break;
        
        case 2:
                int RA;
                printf("Primeiro, digite o RA,\npara sabermos se esse(a) aluno(a) já está matriculado(a)");
                printf("\nRA: ");
                scanf("%d", &RA);
                getchar();
                printf("\n");

                int pos = busca_aluno(turma, MAX_ALUNOS, RA);

            if(pos == -1)
            {
                printf("Desculpe, ele(a) não estava matriculado(a) nessa turma.\nPor isso, nem pude removê-lo(a).")
                printf("\n\nPara voltar ao menu, aperte enter.");
                getchar();
            }
            else
                remove_aluno(turma, pos);
            
            break;

        case 3:
            int RA;
                printf("Primeiro, digite o RA,\npara sabermos se esse(a) aluno(a) já está matriculado(a)");
                printf("\nRA: ");
                scanf("%d", &RA);
                getchar();
                printf("\n");

                int pos = busca_aluno(turma, MAX_ALUNOS, RA);

            if(pos == -1)
            {
                printf("Desculpe, ele(a) não estava matriculado(a) nessa turma.")
            }
            else
            {
                
                printf("\nDados do(a) %dº aluno(a):");
                printf("\n\tNome: %s", turma[pos].nome);
                printf("\n\tRA: %d", turma[pos].RA);
                printf("\n\tNotas:");
                for(int j=0; j<3; j++)
                {
                    printf(" %.2f,", turma[pos].nota[j]);
                }
                printf("\b ");
                printf("\n\tFrequência: %d\n", turma[pos].freq);
            } 

                printf("\n\nPara voltar ao menu, aperte enter.");
                getchar();
            break;

        case 4:
            imprime_turma(turma, quant_alunos);
            break;
        default:
            printf("Desculpa, essa opção não é válida.\n\nPara voltar ao menu, digite enter.");
            getchar();  
            break;
        }
    }
    
}