#include <stdlib.h>
#include <stdio.h>
#include "ram.h"

struct BlocoMemoria {
    int id;
    void *endereco;
    size_t tamanho;
    int ocupado;
};

int quantidade = 0; 

PBlocoMemoria criaBlocaDeMemoria(PBlocoMemoria Bloco){
    int tamanho;
    printf("\nInforme o tamanho do bloco em bytes: ");
    if (scanf("%i", &tamanho) != 1 || tamanho <= 0) {
        while (getchar() != '\n');
        printf("valor invalido, tente com valores acima de 0\n");
        return NULL;
    }
    if(quantidade == 0){
        PBlocoMemoria B = (PBlocoMemoria)malloc(sizeof(TBlocoMemoria));
        if(B == NULL){
            printf("Erro na alocação inicial!\n");
            return NULL;
        }
        quantidade ++;
        B->id = quantidade;
        B->endereco = malloc(tamanho);
        if(B->endereco == NULL){
            quantidade --;
            printf("Erro na alocação!\n");
            free(B);
            return NULL;
        }
        B->tamanho = tamanho;
        B->ocupado = 1;
        printf("\nBloco alocado com sucesso!\n");
        printf("Identificador: %d\n", quantidade);
        printf("Endereço: %p\n",  B->endereco);
        printf("Tamanho: %d bytes\n", B->tamanho);
        if(B->ocupado == 0){
                printf("Estado: LIVRE\n");
            }else{
                printf("Estado: OCUPADO\n");
            }
        return B;
    }else{
        PBlocoMemoria M = (PBlocoMemoria) realloc(Bloco, (quantidade + 1) * sizeof(TBlocoMemoria)); 
        if(M == NULL){
            printf("Erro na alocação!\n");
            return NULL;
        }
        quantidade ++;
        M[quantidade - 1].id = quantidade;
        M[quantidade - 1].endereco = malloc(tamanho);
        if(M[quantidade - 1].endereco == NULL){
            quantidade --;
            printf("Erro na alocação!\n");
            return M;
        }
        M[quantidade - 1].tamanho = tamanho;
        M[quantidade - 1].ocupado = 1;
        printf("\nBloco alocado com sucesso!\n");
        printf("Identificador: %d\n", quantidade);
        printf("Endereço: %p\n",  M[quantidade - 1].endereco);
        printf("Tamanho: %d bytes\n", M[quantidade - 1].tamanho);
        if(M[quantidade - 1].ocupado == 0){
                printf("Estado: LIVRE\n");
            }else{
                printf("Estado: OCUPADO\n");
            }
        return M;
    }
}

void liberaBloco(PBlocoMemoria Bloco){
    if(Bloco == NULL){
        printf("Não existe blocos de memorias alocadas, realize o cadastro\n");
    }else{
        int valor;
        printf("Informe o identificador do bloco: ");
        if (scanf("%i", &valor) != 1 || valor <= 0) {
            while (getchar() != '\n');
            printf("valor invalido, tente com valores acima de 0\n");
            return;
        }
        if(valor > quantidade || valor <= 0){
            printf("Digite um valor valido, temos o valor até o id: %d\n", quantidade);
        }else{
            int idValor = valor - 1;
            if(Bloco[idValor].ocupado == 0){
                printf("A memoria do bloco já foi liberado, utilize outro ID\n");
            }else{
                free(Bloco[idValor].endereco);
                Bloco[idValor].ocupado = 0;
                printf("\nBloco %d liberado com sucesso.\n", Bloco[idValor].id );
            }
        }
    }
}

void exibirBloco(PBlocoMemoria Bloco){
    if(Bloco == NULL){
        printf("Não existe blocos de memorias alocadas, realize o cadastro\n");
    }else{
        printf("\nID  ENDEREÇO          TAMANHO  ESTADO\n");
        for(int i = 0; i < quantidade; i++){
            if(Bloco[i].ocupado == 0)
                printf("%d  (liberado)          %d       LIVRE\n",Bloco[i].id, Bloco[i].tamanho);
            else
                printf("%d  %p      %d      OCUPADO\n",Bloco[i].id, Bloco[i].endereco, Bloco[i].tamanho);
        }
    }
}

void resumoDeMemoria(PBlocoMemoria Bloco){
    if(Bloco == NULL){
        printf("Não existe blocos de memorias alocadas, realize o cadastro\n");
    }else{
        int blocosOcupados = 0;
        int blocosLivres = 0 ;
        int bytesTotal = 0;
        printf("Total de registros: %d\n", quantidade);
        for(int i = 0; i < quantidade; i++){
            if(Bloco[i].ocupado == 0){
                blocosLivres ++; 
            }
            if(Bloco[i].ocupado == 1){
                blocosOcupados ++; 
                bytesTotal = bytesTotal + Bloco[i].tamanho;
            }
        }
        printf("Blocos ocupados: %d\n", blocosOcupados);
        printf("Blocos livres: %d\n", blocosLivres);
        printf("Bytes atualmente alocados: %d\n", bytesTotal);
    }
}

void excluirBlocos(PBlocoMemoria Bloco){
    printf("Liberando blocos restantes...\n");
    if(Bloco == NULL){
        printf("Não existe blocos de memorias alocadas, realize o cadastro\n");
    }else{
        for(int i = 0; i < quantidade; i++){
            if(Bloco[i].ocupado == 1){
                free(Bloco[i].endereco);
                Bloco[i].ocupado = 0;
            }
        }
        free(Bloco);
    }
    printf("Todos os recursos foram liberados.\n");
}