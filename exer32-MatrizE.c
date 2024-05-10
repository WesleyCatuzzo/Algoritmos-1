#include <stdio.h>
#include <stdlib.h>
typedef struct cell{
        int item, lin, col;
        struct cell *next;
}Cell;


typedef struct {
        Cell *head;
}ListaE;


typedef struct {
       int n_lin;
       int n_col;
       ListaE **lin;
      
}matrizEsp;


matrizEsp* criar(int l, int c){
        matrizEsp* mat = (matrizEsp*) malloc(sizeof(matrizEsp));
        int i;

        mat->n_col = c;
        mat->n_lin = l;
        mat->lin = (ListaE**) malloc(sizeof(ListaE*) * l);
       
        for (i = 0; i < l; i++){
                mat->lin[i] = (ListaE*) malloc(sizeof(ListaE));
                mat->lin[i]->head = NULL;
        }

        return mat;
}


Cell* criar_celula(int item, int l, int c){
    Cell *nova = NULL;

    if (item > 0){
        nova = (Cell*) malloc(sizeof(Cell));
        nova->item = item;
        nova->lin = l;
        nova->col = c;
        nova->next = NULL;
    }

    return nova;
}



void inserir(int chave, int l, int c, matrizEsp *m){
    Cell *nova = criar_celula(chave, l, c);
    Cell *aux;

    if(m->lin[l]->head == NULL){
        m->lin[l]->head = nova;
    }
    else if (m->lin[l]->head->col > c){
        
        nova->next = m->lin[l]->head;
        m->lin[l]->head = nova;
        
    }
    else {
        aux = m->lin[l]->head;
        while (aux->next != NULL && aux->next->col < c){
            aux = aux->next;
        }
        
        nova->next = aux->next;
        aux->next = nova;
    }
}  

    
int confere(matrizEsp *m){ 

    Cell *aux;
    int i, j=0;
    
    for(i = 0; i < m->n_lin; i++){
        aux = m->lin[i]->head;
        
        while(aux != NULL){
            if(aux->col != aux->lin){
                j= 1;
            }
            aux = aux->next;
        }
    }
    
    return j;
}

int main(void) {
    int l, i, j, chave, aux;
    matrizEsp *matriz;
    scanf("%d", &l);
    matriz = criar(l,l);
    for(i = 0; i < l; i++){
        for(j = 0; j < l; j++){
            scanf("%d", &chave);
            if(chave > 0)
                inserir(chave, i, j, matriz);
        }
    }
    aux = confere(matriz);

    if(aux == 1){
        printf("nao diagonal");
    }
    else
    {
        printf("diagonal");
    }
    return 0;
}