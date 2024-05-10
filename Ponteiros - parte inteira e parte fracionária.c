#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


void frac(float n, int * in, float * fr){

    *in = (int)n;
    *fr = n - *in;



}




int main() {

    float numero, ptFracionaria;
    int casosTeste, ptInteira;

    scanf("%d", &casosTeste);

    for(int i=0; i<casosTeste; i++){
        scanf("%f", &numero);
        frac(numero, &ptInteira, &ptFracionaria);
        printf("N=%.3f I=%d F=%.3f\n", numero, ptInteira, ptFracionaria);


    }




    return 0;
}
