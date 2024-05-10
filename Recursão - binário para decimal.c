#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int convert(int vet[], int tam, int n, int result)
{
    if (n>tam-1){
        printf("%d", result);
    }
    else{

        result = result + (vet[n]*pow(2, n));
        return convert( vet, tam, n+1, result);
    }

    return 0;

}



int main()
{
    int tam;
    scanf("%d", &tam);

    int vet[tam] , i;
    for(i=tam-1; i>=0; i--){
        scanf("%d", &vet[i]);
    }



    convert(vet, tam, 0, 0);



    return 0;
}

