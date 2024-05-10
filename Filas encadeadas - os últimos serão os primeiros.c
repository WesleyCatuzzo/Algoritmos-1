#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#define TAM_MAX 100



typedef struct{
    int item[TAM_MAX];
    int topo;
}Pilha;


Pilha* criar_pilha(){
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));

    p->topo = -1;

    return p;
}


int pilha_cheia(Pilha *p){

    if (p == NULL)
        return -1;
    else if (p->topo == (TAM_MAX - 1))
        return 1;
    else
        return 0;
}


int pilha_vazia(Pilha *p){

    if (p == NULL)
        return -1;
    else if (p->topo == -1)
        return 1;
    else
        return 0;
}


int empilhar(Pilha *p, int item){

    if (p == NULL)
        p = criar_pilha();


    if (!pilha_cheia(p)){
        p->topo++;

        p->item[p->topo] = item;

        return 1;
    }

    return 0;
}


int desempilhar (Pilha *p){
    int item = INT_MIN;


    if (!pilha_vazia(p)){
        item = p->item[p->topo];

        p->topo--;
    }

    return item;
}


void imprimir_pilha(Pilha *p){

    Pilha aux = *p;
    int item;


    while (!pilha_vazia(&aux)){
        item = desempilhar(&aux);

        printf("%d\n", item);
    }
}


void liberar_pilha(Pilha *p){
    if (p != NULL)
        free(p);
}



int obter_posicao_topo(Pilha *p){
    if (!pilha_vazia(p))
        return p->topo;
    else
        return -1;
}





typedef struct{
    int item;
    struct Cell *next;
}Cell;


typedef struct {
    Cell *inicio;
    Cell *fim;
}FilaE;


Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}

FilaE* criar_filaE(){
    FilaE *f = (FilaE*) malloc(sizeof(FilaE));

    f->inicio = NULL;
    f->fim = NULL;

    return f;
}


int filaE_vazia(FilaE* f){
    return (f == NULL) || (f->inicio == NULL);
}


void enfileirar(int key, FilaE* f){
    Cell *aux;

    if (f == NULL)
        f = criar_filaE();


    aux = criar_celula(key);


    if (f->inicio == NULL)
        f->inicio = f->fim = aux;
    else{
        f->fim->next = aux;
        f->fim = f->fim->next;
    }

}

int desenfileirar(FilaE* f){
    Cell *aux;
    int item = -INT_MAX;

    if (!filaE_vazia(f)){
        aux = f->inicio;
        f->inicio = aux->next;
        item = aux->item;
        free(aux);
    }

    return item;
}



void imprimir_fila(FilaE* f){
    Cell *aux;

    if (!filaE_vazia(f)){
        aux = f->inicio;

        while (aux != NULL){
            printf("%d\n", aux->item);
            aux = aux->next;
        }
    }
}


int liberar_filaE(FilaE* f){
    if (!filaE_vazia(f)){
        while (f->inicio != NULL)
            desenfileirar(f);

        free(f);

        return 1;
    }

    return 0;
}



void pilha_para_filaE(Pilha *p){
    Pilha *aux;
    FilaE *f = criar_filaE();
    Cell *aux2 = f->inicio;
    int aux3;

    if(!pilha_vazia(p)){
        while(!pilha_vazia(p)){
            aux3 = desempilhar(p);
            if(!filaE_vazia(f)){
                while(aux2!=NULL){
                   enfileirar(aux3, f);
                   aux2= aux2->next;
                   imprimir_fila(f);
                }

            }

        }
    }






}


int main() {

    Pilha *p = criar_pilha();

    int num;

    while(num != -1){
        scanf("%d", &num);
        if(num!= -1)
        {
            empilhar(p, num);
        }
    }

    printf("\n");

    pilha_para_filaE(p);


    return 0;
}
