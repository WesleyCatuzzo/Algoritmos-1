#include <stdio.h>
#include <stdlib.h>



int somarDigitosRecursao(int num){
    if(num == 0){
        return 0;
    }else{
        return(num % 10) + somarDigitosRecursao(num / 10);
    }

}


int main(){
    int num, resultado;

    scanf("%d", &num);

    resultado = somarDigitosRecursao(num);
    printf("%d", resultado);

    return 0;
}
