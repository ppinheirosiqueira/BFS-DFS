#ifndef PILHA_H 
#define PILHA_H

#include"estruturas.h"

typedef struct Pilha Pilha;

struct Pilha{
	Block *base;
	Block *top;
};

void FPVazia(Pilha *p);
void Push(Pilha *p, Item d);
void Pop(Pilha *p, Item *d);
void PImprime(Pilha *p);

bool PAndarBaixo(int **matriz, Pilha *p, int n);
bool PAndarCima(int **matriz, Pilha *p);
bool PAndarDireita(int **matriz, Pilha *p, int n);
bool PAndarEsquerda(int **matriz, Pilha *p);


#endif
