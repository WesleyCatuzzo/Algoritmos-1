#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


void operacoes(int *a, int *b , int *c){

    *c = abs(a - b);
    *a = *a + *c;
    *b = *b - *c;


}


int main(){

    int num1, num2, diferenca;
    scanf("%d %d", &num1, &num2);

    operacoes(&num1, &num2, &diferenca);


    printf("A=%d B=%d C=%d", num1, num2, diferenca);

    return 0;
}
