#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int multiplicacao_rec(int a, int b){
    if(a>0 && b >1){
        return a=a+multiplicacao_rec(a, b-1);
    }else if(b==0){
        return 0;
    }else
        return a;
}



int main() {

    int num1, num2;
    scanf("%d %d", &num1, &num2);
    printf("%d\n", multiplicacao_rec(num1, num2));
    return 0;
}
