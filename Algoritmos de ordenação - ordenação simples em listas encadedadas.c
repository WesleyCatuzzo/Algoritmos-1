#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct Cell {
    int item;
    struct Cell *next;
};

typedef struct Cell Cell;

typedef struct{
    Cell *head;
} ListaE;


Cell *inserir_ultimo(Cell *l, int key) {
    Cell * c;
    c = (Cell*)malloc(sizeof(Cell));
    c->item = key;
    c->next = l->next;
    l->next = c;
    return l;
}

void imprimir(Cell *l) {
    Cell *p = l->next;
    while (p->next != NULL){
        printf("%d ", p->item);
        p = p->next;
    }
}

void selection_sort(Cell *l) {
    Cell *j, *p;
    Cell *aux = l->next;
    int aux2;


    while(aux->next->next != NULL) {
        p = aux;
        j = aux->next;
        while(j->next != NULL){
            if(j->item < p->item)
                p = j;
            j = j->next;
        }
        aux2 = aux->item;
        aux->item = p->item;
        p->item = aux2;
        aux = aux->next;
    }
}

int main() {
    Cell *l, *fim, *l2;
    Cell c, r;
    l = &c;
    fim = &r;
    l->next = fim;
    l2 = l;

    int num;


    while(num != -1)
    {
        scanf("%d", &num);
        if(num!= -1){
            l2 = inserir_ultimo(l2, num);
        }
    }


    selection_sort(l);
    imprimir(l);



    return 0;
}


