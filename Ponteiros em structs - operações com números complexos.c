#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


typedef struct{

    float real, img, mod;

}complexo;


void atualizar_complexo(complexo *c, float real, float img){


    c->real = real;
    c->img = img;
    c->mod = sqrt(real * real + img * img);

    if(img < 0){
        printf("%.1f%.1fi", c->real, c->img);

    }else
        printf("%.1f+%.1fi", c->real, c->img);

        printf("\n%.1f", c->mod);

}





int main() {

     complexo *pc = (complexo*)malloc(sizeof(complexo));
     float num1, num2;


    scanf("%f %f", &num1, &num2);


    atualizar_complexo(pc, num1, num2);



    return 0;
}
