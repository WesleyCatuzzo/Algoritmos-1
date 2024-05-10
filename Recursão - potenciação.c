#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int potenciacao_rec(int a, int b){
    if(b == 0){
        return 1;
    }else
        return a * potenciacao_rec(a, b-1);
}



int main() {

    int num1, num2;
    scanf("%d %d", &num1, &num2);
    printf("%d\n", potenciacao_rec(num1, num2));
    return 0;
}
