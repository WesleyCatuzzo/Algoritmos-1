#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TAM_MAX 100

typedef struct{
    int item[TAM_MAX];
    int ini;
    int fim;
    int tam;
}Fila;


Fila* criar_fila(){
    Fila *f = (Fila *) malloc(sizeof(Fila));

    f->ini = -1;
    f->fim = -1;
    f->tam = 0;

    return f;
}


int fila_cheia(Fila *f){

    if (f == NULL)
        return -1;
    else if (f->tam < TAM_MAX)
        return 0;
    else
        return 1;
}


int fila_vazia(Fila *f){
    if (f == NULL)
        return -1;
    else if (f->tam > 0)
        return 0;
    else
        return 1;
}


int enfileirar(Fila *f, int chave){

    if (f == NULL)
        f = criar_fila();


    if (!fila_cheia(f)){

        if (f->ini < 0)
            f->ini = 0;


        if (f->fim < TAM_MAX - 1)
            f->fim++;
        else
            f->fim = 0;


        f->item[f->fim] = chave;


        f->tam++;

        return 1;
    }

    return 0;
}


int desenfileirar(Fila *f){
    int item = INT_MIN;


    if (!fila_vazia(f)){
        item = f->item[f->ini];


        if (f->ini < TAM_MAX - 1)
            f->ini++;
        else
            f->ini = 0;

        f->tam--;

        if (f->tam == 0){
            f->ini = -1;
            f->fim = -1;
        }
    }

    return item;
}


void imprimir_fila(Fila *f){

    Fila aux = *f;
    int item;

    while (!fila_vazia(&aux)){
        item = desenfileirar(&aux);

        printf("%d ", item);
    }

    printf("\n");
}


void liberar_fila(Fila *f){
    if (f != NULL)
        free(f);
}

void intercala_fila(Fila *f1, Fila *f2)
{

    Fila *f3 = criar_fila();
    int item=0, item2=0;


   while(!fila_vazia(f1))
{
    while(!fila_vazia(f2)){
        item = desenfileirar (f1);
        item2 = desenfileirar (f2);

        if(item!=-1 && item2!=-1){
            if(item>item2){
                enfileirar(f3,item);
                enfileirar(f3,item2);
            }else{
                enfileirar(f3,item2);
                enfileirar(f3,item);
            }
        }else if(item2!=-1 && !fila_vazia(f2))
            enfileirar(f3,item2);
    }

    if(item!=-1 && !fila_vazia(f1))
        enfileirar(f3,item);
    item = desenfileirar (f1);

}


    imprimir_fila(f3);





}


int main() {

    Fila *f1 = criar_fila();
    Fila *f2 = criar_fila();
    Fila *f3 = criar_fila();
    int num, num2;

    do{
        scanf("%d", &num);
        enfileirar(f1, num);

    }while(num != -1);


    do{
        scanf("%d", &num2);
        enfileirar(f2, num2);

    }while(num2 != -1);


    intercala_fila(f1, f2);




    return 0;
}
