#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
    int i;
    int f;
    float num;
} Real;

Real* criar(int i, int f){
    Real *aux = (Real*)malloc(sizeof(Real));

    aux->i = i;
    aux->num = aux->i + (float)f/100;


    return aux;

}

Real* soma(Real *r1, Real *r2){
    Real *aux = (Real*)malloc(sizeof(Real));
    aux->num = r1->num + r2->num;


    return aux;

}


Real* subtracao(Real *r1, Real *r2){
    Real *aux = (Real*)malloc(sizeof(Real));
    aux->num = r1->num - r2->num;


    return aux;
}


int arredondar(Real *r1){
    int arredonda;
    arredonda= lround(r1->num);


    return arredonda;

}


void imprimir(Real *r1){
    printf("%.2f", r1->num);
    printf("\n");

}

int main() {

   Real *numReal = (Real*)malloc(sizeof(Real));
   Real *numReal2 = (Real*)malloc(sizeof(Real));
   Real *somar = (Real*)malloc(sizeof(Real));
   Real *subtrair = (Real*)malloc(sizeof(Real));

   int num, num3;
   float num2,num4;

   scanf("%d %f", &num, &num2);
   numReal = criar(num, num2);

   scanf("%d %f", &num3, &num4);
   numReal2 = criar(num3, num4);

   somar = soma(numReal, numReal2);

   subtrair = subtracao(numReal, numReal2);

   num = arredondar(numReal);
   num3 = arredondar(numReal2);

   imprimir(numReal);
   imprimir(numReal2);
   imprimir(somar);
   imprimir(subtrair);
   printf("%d %d", num, num3);


    return 0;
}
