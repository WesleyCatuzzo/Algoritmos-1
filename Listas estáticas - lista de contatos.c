#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct{
    char nome[MAX_SIZE];
}Item;

 typedef struct {
    Item item[MAX_SIZE];
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


void procura_string(char nome[], int num){
    Lista *l = criar_lista(l);
    l->tam = num;
    int i=0;

    while(i<num){
        scanf("%s", &l->item[i].nome);
        i++;
    }
    i=0;
    while(i<num){
        if(strstr(l->item[i].nome, nome)!= NULL){
                printf("%s", l->item[i].nome);
                printf("\n");
        }
        i++;
    }

}

int main(){
    char nome[MAX_SIZE];
    gets(nome);

    int num;
    scanf("%d", &num);
    procura_string(nome, num);

}

