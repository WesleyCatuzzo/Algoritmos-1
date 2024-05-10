#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{

    int numerador;
    int denominador;

}numeros_racionais;


numeros_racionais divisao_racionais(numeros_racionais num_rac1 , numeros_racionais num_rac2, numeros_racionais resultado){

    resultado.numerador = num_rac1.numerador * num_rac2.denominador;
    resultado.denominador = num_rac2.numerador * num_rac1.denominador;



    return resultado;
}


int main(){


    numeros_racionais num_rac1, num_rac2, resultadoo;

    scanf("%d %d", &num_rac1.numerador, &num_rac1.denominador);

    scanf("%d %d", &num_rac2.numerador, &num_rac2.denominador);



    resultadoo = divisao_racionais(num_rac1, num_rac2, resultadoo);

    printf("%d %d", resultadoo.numerador, resultadoo.denominador);




    return 0;
}
