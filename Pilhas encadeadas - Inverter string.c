#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>



typedef struct {
    char item;

    struct Cell *next;
}Cell;



typedef struct {
    Cell *topo;
}PilhaE;



Cell* criar_celula(char key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}


PilhaE* criar_pilhaE(){
    PilhaE* p = (PilhaE*) malloc(sizeof(PilhaE));

    p->topo = NULL;

    return p;
}


int pilhaE_vazia(PilhaE *p){
    return (p == NULL) || (p->topo == NULL);
}


void empilhar(char key, PilhaE *p){
    Cell *aux = (Cell*) malloc(sizeof(Cell)); ;
    aux->item = key;
    aux->next = p->topo;
    p->topo = aux;

}



char desempilhar(PilhaE *p){
    Cell *aux = p->topo;
    char c = aux->item;
    p->topo = aux->next;

    free(aux);


    return c;
}


void imprimir_pilha(PilhaE *p){
    Cell *aux;

    if (!pilhaE_vazia(p)){
        aux = p->topo;

        while (aux != NULL){
            printf("%c\n", aux->item);

            aux = aux->next;
        }
    }
}



int liberar_pilha(PilhaE *p){
    if (p != NULL){
        while (!pilhaE_vazia(p))
            desempilhar(p);

        free(p);

        return 1;
    }

    return 0;
}


void inverte_string(char frase[]){

    PilhaE *p = criar_pilhaE();
    char c;

    int i=0;
    while(frase[i] != '\0'){
        i=0;
        while(frase[i] != '\0' && frase[i] != ' ') {
            empilhar(frase[i], &p);
            i++;
        }
        while (p->topo != NULL) {
            c = desempilhar(&p);
            printf("%c", c);
        }
    i++;
    }

}



int main() {
    char frase[10];

    fgets(frase, 10, stdin);

    inverte_string(frase);




    return 0;
}
