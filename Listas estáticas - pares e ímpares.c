#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 100



typedef struct{
    int item[MAX_SIZE];
    int tam;
}Lista;


Lista* criar_lista(){
    Lista *l = (Lista*) malloc(sizeof(Lista));


    l->tam = 0;

    return l;
}


int lista_vazia(Lista *l){
    return (l == NULL) || (l->tam == 0);
}


int lista_cheia(Lista *l){
    return (l != NULL) && (l->tam == MAX_SIZE);
}


int buscar(Lista *l, int chave){
    int i;

    if (!lista_vazia(l)){

        for (i = 0; i < l->tam; i++)
            if (l->item[i] == chave)
                return i;
    }


    return -1;
}


int inserir(Lista *l, int chave){
    if (!lista_cheia(l)){

        l->item[l->tam] = chave;


        l->tam++;


        return 1;
    }


    return 0;
}


int remover(Lista *l, int chave){
    int i, p = buscar(l, chave);


    if (p > -1){
        for (i = p; i < l->tam - 1; i++)

            l->item[i] = l->item[i + 1];


        l->tam--; //


        return 1;
    }

    return 0;
}


void imprimir_lista(Lista *l){
    int i;

    if (!lista_vazia(l)){
        for (i = 0; i < l->tam; i++)
            printf("%d ", l->item[i]);

        printf("\n");
    }
}

int liberar_lista(Lista *l){
    if (l != NULL){
        free(l);

        return 1;
    }

    return 0;
}


void ParesEImpares(Lista *l1, Lista *l2, Lista *l3){

    int i;
    for (i = 0; i < l1->tam; i++)
    {
        if (l1->item[i]%2==0)
        {
            inserir(l2, l1->item[i]);
        }
        else if(l1->item[i]== -1)
        {
            remover(l3, -1);
        }
        else
            inserir(l3, l1->item[i]);
    }
    if(l2->tam == 0){
        printf("par: -1\n");

    }else
        printf("par: ");
        imprimir_lista(l2);
    if(l3->tam == 0){
         printf("impar: -1");
    }else
        printf("impar: ");
        imprimir_lista(l3);




}

int main(){

    Lista *L1 = criar_lista(L1);
    Lista *L2 = criar_lista(L2);
    Lista *L3 = criar_lista(L3);

    int num;

    do{
       scanf("%d", &num);
       inserir(L1, num);

    }while(num != -1);

    ParesEImpares(L1, L2, L3);






    return 0;
}

