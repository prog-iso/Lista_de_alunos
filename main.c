#include "func.h"

#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"pt_BR.UTF-8");
    setlocale(LC_NUMERIC,"C");

    int escolha = 0;
    while (escolha!=5)
    {
        imprime_menu();
        printf("\n\nDigite sua escolha: ");
        scanf("%d", &escolha);
    }
    
}