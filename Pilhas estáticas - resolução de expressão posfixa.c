#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define TAM_MAX 100


typedef struct{
    float topo;
    int *item;
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


Pilha* empilhar(Pilha *p, float item){

    Pilha *aux = criar_pilha();

    if(aux){
        aux->topo = item;
        aux->item = p;
        return aux;
    }
    else
        return 0;
}

Pilha* desempilhar(Pilha **p){
    Pilha *remover = NULL;

    if(*p){
        remover = *p;
        *p = remover->item;
    }
    else
        printf("\tPilha vazia\n");
    return remover;
}


float resolvePosFixo(char *s){

    Pilha *p1, *p2;
    Pilha *p3 = NULL;
    float num;
    char *aux;



    aux = strtok(s, " ");
    while(aux){
        if(aux[0] == '*' || aux[0] == '/' || aux[0] == '+' || aux[0] == '-'){
            p1 = desempilhar(&p3);
            p2 = desempilhar(&p3);
            if(aux[0] == '*'){

                num = p2->topo * p1->topo;

            }else if(aux[0] == '/'){

                num = p2->topo / p1->topo;

            }else if(aux[0] == '+'){

                num = p2->topo + p1->topo;

            }else if(aux[0] == '-'){

                num = p2->topo - p1->topo;
            }

            p3 = empilhar(p3, num);
        }
        else{
            num = strtol(aux, NULL, 20);
            p3 = empilhar(p3, num);
        }
        aux = strtok(NULL, " ");
    }
    p1 = desempilhar(&p3);
    num = p1->topo;


    return num;
}

int main(){
    char *s =(char*) malloc(50*sizeof(char));
    strcpy(s, "7 6 2 + 4 / - 3 +");

    printf("%.0f\n", resolvePosFixo(s));
}
