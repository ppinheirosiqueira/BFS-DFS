#include "fila.h"

void FFVazia(Fila *f){
	f->first = (Block*) malloc (sizeof(Block));
	f->last  = f->first;
	f->first->prox = NULL;
}

void Enfileira(Fila *f, Item d, int *contagem){
	f->last->prox = (Block*) malloc (sizeof(Block));
	f->last = f->last->prox;
	f->last->data = d;
	f->last->prox = NULL;
	*contagem = *contagem + 1;
}

void Desenfileira(Fila *f, int *contagem){
	Block *aux;

	if(f->first == f->last || f == NULL || f->first->prox == NULL){
		printf("FILA VAZIA!\n");
		return;
	}
	
	aux = f->first->prox;
	f->first->prox = aux->prox;
	free(aux);
	*contagem = *contagem + 1;
}


void FImprime(Fila *f){
	Block *aux;

	aux = f->first->prox;
	while(aux != NULL){
		printf("Linha: %d Coluna: %d\n", aux->data.linha, aux->data.coluna);
		aux = aux->prox;
	}

}

void FAndarBaixo(int **matriz, Fila *f, int n, int *contagem){
	int aux;
	Item NovoItem;
	aux = f->first->prox->data.linha + 1;
	if(aux < n && matriz[aux][f->first->prox->data.coluna] == 0){
		matriz[aux][f->first->prox->data.coluna] = 1;
		NovoItem.linha = f->first->prox->data.linha + 1;
		NovoItem.coluna = f->first->prox->data.coluna;
		Enfileira(f, NovoItem, contagem);
	}
}

void FAndarCima(int **matriz, Fila *f, int *contagem){
	int aux;
	Item NovoItem;
	aux = f->first->prox->data.linha - 1;
	if(aux > 0 && matriz[aux][f->first->prox->data.coluna] == 0){
		matriz[aux][f->first->prox->data.coluna] = 1;
		NovoItem.linha = f->first->prox->data.linha -1;
		NovoItem.coluna = f->first->prox->data.coluna;
		Enfileira(f, NovoItem, contagem);
	}
}

void FAndarDireita(int **matriz, Fila *f, int n, int *contagem){
	int aux;
	Item NovoItem;
	aux = f->first->prox->data.coluna + 1;
	if(aux < n && matriz[f->first->prox->data.linha][aux] == 0){
		matriz[f->first->prox->data.linha][aux] = 1;
		NovoItem.linha = f->first->prox->data.linha;
		NovoItem.coluna = f->first->prox->data.coluna + 1;
		Enfileira(f, NovoItem, contagem);
	}
}

void FAndarEsquerda(int **matriz, Fila *f, int *contagem){
	int aux;
	Item NovoItem;
	aux = f->first->prox->data.coluna - 1;
	if(aux > 0 && matriz[f->first->prox->data.linha][aux] == 0){
		matriz[f->first->prox->data.linha][aux] = 1;
		NovoItem.linha = f->first->prox->data.linha;
		NovoItem.coluna = f->first->prox->data.coluna - 1;
		Enfileira(f, NovoItem, contagem);
	}
}