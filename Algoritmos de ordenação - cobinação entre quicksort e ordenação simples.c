#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


//ALGORITMOS DE ORDENAÇÃO DO PROFESSOR

void insertsort(int v[], int n){
	int i, j, x;

	for (i = 1; i < n; i++){
		x = v[i];

		for (j = i - 1; (j >= 0) && (x  < v[j]); j--)
			v[j + 1] = v[j];

		v[j + 1] = x;
	}
}


void quicksort(int x[], int esq, int dir){
	int i = esq, j = dir, pivo = x[(i + j) / 2], aux;

	do{
		while (x[i] < pivo)
			i++;

		while (x[j] > pivo)
			j--;

		if (i <= j){
			aux = x[i];
			x[i] = x[j];
			x[j] = aux;
			i++;
			j--;
		}
	}while (i <= j);

	if (j > esq)
		quicksort(x, esq, j);
	if (i < dir)
		quicksort(x, i, dir);
}




void quicksort_e_insert(int x[], int esq, int dir, int tam, int m){
	int i = esq, j = dir, pivo = x[(i + j) / 2], aux;

	if(dir-esq+1 > m){

        do{
		while (x[i] < pivo)
			i++;

		while (x[j] > pivo)
			j--;

		if (i <= j){
			aux = x[i];
			x[i] = x[j];
			x[j] = aux;
			i++;
			j--;
		}
	}while (i <= j);

	if (j > esq)
		quicksort_e_insert(x, esq, j, dir-esq, m);
	if (i < dir)
		quicksort_e_insert(x, i, dir, dir-esq, m);
	}else{

        for (i = 1; i < tam; i++)
        {
            aux = x[i];

            for (j = i - 1; (j >= 0) && (aux  < x[j]); j--)
                x[j + 1] = x[j];

            x[j + 1] = aux;
        }

	}

}


int main() {


    int i, tam, m;

    scanf("%d", &tam);

    int vet[tam];

    i=0;
    while(i<tam){
        scanf("%d", &vet[i]);
        i++;
    }

    scanf("%d", &m);

    quicksort_e_insert(vet, 0, tam-1, tam, m);


     i=0;
     while(i<tam){
        printf("%d ", vet[i]);
        i++;
    }







    return 0;
}
