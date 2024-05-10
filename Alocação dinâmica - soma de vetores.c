#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int* soma(int *v1, int n1, int *v2, int n2)
{

    int maior, menor, *vR, i;
    if(n1>n2)
    {
        maior= n1;
        menor= n2;
    }
    else
    {
        maior= n2;
        menor= n1;
    }
    vR = (int*) malloc(maior * sizeof(int));

    for(i=0; i<menor; i++)
    {
        vR[i]= v1[i]+v2[i];
    }
    for(i=n2; i<n1; i++)
    {
        vR[i]= v1[i];
    }
    for(i=n1; i<n2; i++)
    {
        vR[i]= v2[i];
    }

    return vR;
}



int main()
{

    int qtdElementosV1, qtdElementosV2, i;
    scanf("%d", &qtdElementosV1);

    int v1[qtdElementosV1];

    for(i=0; i<qtdElementosV1; i++)
    {
        scanf("%d", &v1[i]);
    }

    scanf("%d", &qtdElementosV2);
    int v2[qtdElementosV2];

    for(i=0; i<qtdElementosV2; i++)
    {
        scanf("%d", &v2[i]);
    }

    int *v3;
    v3 = soma(v1, qtdElementosV1, v2, qtdElementosV2);


    for(i=0; i<sizeof(v3)-3; i++){
        printf("%d ", v3[i]);
    }











    return 0;
}
