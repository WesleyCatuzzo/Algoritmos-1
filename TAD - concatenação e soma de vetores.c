#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int *v;
    int n;
    int q;
} Vetor;

Vetor * iniciar(int n)
{
    Vetor *aux = malloc(sizeof(Vetor));

    aux->v = (int*)malloc(n * sizeof(int));
    aux->n = n;
    aux->q = 0;

    return aux;
}

int inserir(Vetor *v, int x)
{
    if(v->q < v->n)
    {
        v->v[v->q] = x;
        v->q++;

        return 1;
    }else
        return -1;
}

Vetor * concatenar(Vetor *v1, Vetor *v2)
{
    Vetor *aux;
    int i=0, j=0;


    aux = iniciar(v1->n+v2->n);

    while (i<v1->n)
    {
        aux->v[i]=v1->v[i];
        aux->q++;
        i++;
    }

    while (i<v1->n+v2->n)
    {
        aux->v[i]=v2->v[j];

        i++;
        j++;
    }

    return aux;
}

Vetor *soma(Vetor *v1, Vetor *v2)
{
    Vetor *v3;
    int i=0;
    if(v1->n >= v2->n)
    {
        v3 = iniciar(v1->n);
    }
    else
        v3 = iniciar(v2->n);

    while(i<v3->n)
    {

        if(i < v1->n && i<v2->n)
        {
            v3->v[i]= v1->v[i] + v2->v[i];
        }
        else if(i < v1->n && i>=v2->n)
        {
            v3->v[i]= v1->v[i];
        }
        else
        {
            v3->v[i] = v2->v[i];
        }
        i++;
    }
    return v3;
}


int main()
{
    Vetor *vetor1, *vetor2, *vetor3, *vetor4;
    int aux;
    int i = 0;
    scanf("%d",&aux);

    vetor1 = iniciar(aux);

    for(i=0; i<vetor1->n; i++){
        scanf("%d", &aux);

        inserir(vetor1, aux);
    }


    scanf("%d",&aux);

    vetor2 = iniciar(aux);


    for(i=0; i<vetor2->n; i++){

        scanf("%d", &aux);

        inserir(vetor2, aux);

    }

    vetor3 = concatenar(vetor1, vetor2);


    for(i=0; i < vetor2->n+vetor1->n; i++)
    {
        printf("%d ", vetor3->v[i]);
    }
    printf("\n");


    vetor4 = soma(vetor1, vetor2);
    for(i=0; i<vetor4->n; i++)
    {
        printf("%d ", vetor4->v[i]);
    }

    printf("\n");


    return 0;
}
