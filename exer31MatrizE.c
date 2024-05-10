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

void confere (matrizEsp *m){ 

    Cell *aux;
    int i;

    for(i = 0; i < m->n_lin; i++){ 
        aux = m->lin[i]->head;
        printf("%d:", i);
        if(aux == NULL){
            printf(" ->");
        }
        while(aux != NULL){ 
            printf(" -> %d,%d", aux->col, aux->item);
            aux = aux->next;
        }
        printf("\n");
    }
}
int main() {
    int l, c, i, j, chave;
    matrizEsp *matriz;
    scanf("%d %d", &l, &c);
    matriz = criar(l, c);
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            scanf("%d", &chave);
            if(chave > 0)
                inserir(chave, i, j, matriz);
        }
    }
    confere(matriz);
    return 0;
}
