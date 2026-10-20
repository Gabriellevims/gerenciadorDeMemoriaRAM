#include <stdio.h>
#include <stdlib.h>
#include "ram.h"

int main() {
    
    PBlocoMemoria meusBlocos = NULL;
    int opcao;
    
    do {
        printf("\n========== GERENCIADOR DE MEMORIA ==========\n");
        printf("1 - Alocar bloco de memoria\n");
        printf("2 - Liberar bloco de memoria\n");
        printf("3 - Exibir estado da memoria\n");
        printf("4 - Exibir resumo da memoria\n");
        printf("0 - Encerrar\n");
        printf("Escolha uma opcao: ");
        if (scanf("%i", &opcao) != 1){
            while (getchar() != '\n'); 
            opcao = 6; 
        }
        switch(opcao) {
            case 1:
                meusBlocos = criaBlocaDeMemoria(meusBlocos);
                break;
            case 2:
                liberaBloco(meusBlocos);
                break;
            case 3:
                exibirBloco(meusBlocos);
                break;
            case 4:
                resumoDeMemoria(meusBlocos);
                break;
            case 0:
                excluirBlocos(meusBlocos);
                printf("Programa encerrado.");
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }
    } while(opcao != 0);

    return 0;
}