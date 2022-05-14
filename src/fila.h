#ifndef FILA_H 
#define FILA_H

#include"estruturas.h"

typedef struct Fila Fila;

struct Fila{
	Block *first;
	Block *last;
};

void FFVazia(Fila *f);
void Enfileira(Fila *f, Item d);
void Desenfileira(Fila *f);
void FImprime(Fila *f);

void FAndarBaixo(int **matriz, Fila *f, int n);
void FAndarCima(int **matriz, Fila *f);
void FAndarDireita(int **matriz, Fila *f, int n);
void FAndarEsquerda(int **matriz, Fila *f);

#endif