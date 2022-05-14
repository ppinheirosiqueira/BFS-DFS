#include "pilha.h"
#include "fila.h"
#include "matriz.h"

int main(){
	int **matriz;
	int n, numItePil, numIteFil;
	bool possivel = true, pAndou = false;
	Fila f;
	Pilha p;
	Item iAux;

	matriz = geraMatriz(&n);

	FFVazia(&f);
	FPVazia(&p);

	iAux.linha = 0;
	iAux.coluna = 0;
	Enfileira(&f, iAux);
	matriz[0][0] = 1;

	printf("Essa é a matriz inicialmente: \n");
	imprimeMatriz(matriz, n);
	printf("\n\n");
	printf("------------------------------------------------------------------------------------------\n\n");

	// BFS
	numIteFil = 0;
	
	while(matriz[n-1][n-1] != 1){
		FAndarBaixo(matriz, &f, n);
		FAndarDireita(matriz,&f, n);
		FAndarCima(matriz,&f);
		FAndarEsquerda(matriz,&f);
		Desenfileira(&f);

		if(f.first == f.last || f.first->prox == NULL){
			possivel = false;
			break;
		}
		numIteFil++;
	}

	printf("Essa é a matriz final do BFS: \n");
	imprimeMatriz(matriz, n);

	if(possivel)
		printf("O número de iterações feitas pela fila até encontrar N,N foi igual a: %d\n\n", numIteFil);
	else
		printf("Impossível chegar onde você quer!\n\n");
	printf("------------------------------------------------------------------------------------------\n\n");

	//------------------------------------------------------------------------------------------------------------

	// DFS
	numItePil = 0;
	possivel = true;
	Push(&p, iAux);

	limpaMatriz(matriz,n);

	matriz[0][0] = 1;

	while(matriz[n-1][n-1] != 1){
		pAndou = PAndarBaixo(matriz, &p, n);
		if (!pAndou)
			pAndou = PAndarDireita(matriz, &p, n);
		if (!pAndou)
			pAndou = PAndarCima(matriz, &p);
		if (!pAndou)
			pAndou = PAndarEsquerda(matriz, &p);
		if (!pAndou){
			Pop(&p, &iAux);
			matriz[iAux.linha][iAux.coluna] = 2;
		}
		if(p.base == p.top){
			possivel = false;
			break;
		}
		numItePil++;
	}

	printf("Essa é a matriz final do DFS: \n");
	imprimeMatriz(matriz, n);
	if(possivel)
		printf("O número de iterações feitas pela pilha até encontrar N,N foi igual a: %d\n\n", numItePil);
	else
		printf("Impossível chegar onde você quer!\n\n");

	printf("------------------------------------------------------------------------------------------\n\n");

	if(numIteFil > numItePil)
		printf("O número de iterações feitas pelo BFS foi maior que o do DFS\n");
	else if(numIteFil == numItePil)
		printf("O número de iterações feitas pelos dois métodos foi igual\n");
	else
		printf("O número de iterações feitas pelo DFS foi maior que o do BFS\n");

	return 0;
}