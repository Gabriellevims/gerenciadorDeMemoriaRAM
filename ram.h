#ifndef RAM_H
#define RAM_H


typedef struct BlocoMemoria TBlocoMemoria;
typedef TBlocoMemoria *PBlocoMemoria;

PBlocoMemoria criaBlocaDeMemoria(PBlocoMemoria Bloco);
void liberaBloco(PBlocoMemoria Bloco);
void exibirBloco(PBlocoMemoria Bloco);
void resumoDeMemoria(PBlocoMemoria Bloco);
void excluirBlocos(PBlocoMemoria Bloco);

#endif


