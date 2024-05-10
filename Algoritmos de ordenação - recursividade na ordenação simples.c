#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


void selectsort2(int v[], int n, int i){
	int  j, p, aux;

		p = i;

		for (j = i + 1; j < n; j++)
			if (v[j] < v[p])
				p = j;

		if (p != i){
			aux = v[i];
			v[i] = v[p];
			v[p] = aux;
		}

		if(i+1 < n){
            selectsort2(v,n, i+1);
		}
}


int main() {

    int tam, i;
    scanf("%d", &tam);

    int vet[tam];

    for(i=0; i<tam; i++){
        scanf("%d", &vet[i]);
    }


    selectsort2(vet, tam, 0);

    for(i=0; i<tam; i++){
        printf("%d ", vet[i]);
    }

    return 0;
}
