#include <stdio.h>
#include <stdlib.h>



typedef struct
{
    int item;
    struct Cell *next;
} Cell;



typedef struct
{
    Cell *head;
} ListaE;



Cell* criar_celula(int key)
{
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}


ListaE* criar_listaE()
{
    ListaE* l = (ListaE*) malloc(sizeof(ListaE));

    l->head = NULL;

    return l;
}


int listaE_vazia(ListaE *l)
{
    return (l == NULL) || (l->head == NULL);
}



int procurar(int key, ListaE *l)
{
    Cell *aux;

    if (l != NULL)
    {
        aux = l->head;


        while (aux != NULL)
        {
            if (aux->item == key)
                return 1;

            aux = aux->next;
        }
    }

    return 0;
}



void inserir_primeiro(int key, ListaE *l)
{
    Cell *aux;

    if (l == NULL)
        l = criar_listaE();


    aux = criar_celula(key);



    aux->next = l->head;

    l->head = aux;
}



void inserir_ultimo(int key, ListaE *l)
{
    Cell *aux, *novo;

    if (l == NULL)
        l = criar_listaE();

    if (listaE_vazia(l))
        inserir_primeiro(key, l);
    else
    {
        aux = l->head;


        while(aux->next != NULL)
            aux = aux->next;

        novo = criar_celula(key);

        aux->next = novo;
    }
}






void imprimir(ListaE *l)
{
    Cell *aux;

    if (!listaE_vazia(l))
    {
        aux = l->head;

        while (aux != NULL)
        {
            printf("%d ", aux->item);

            aux = aux->next;
        }

        printf("\n");
    }
}


int liberar_LE(ListaE *l)
{
    Cell *aux = NULL;

    if (l != NULL)
    {
        while(l->head != NULL)
        {
            aux = l->head;

            l->head = aux->next;

            free(aux);
        }

        free(l);

        return 1;
    }

    return 0;
}


int tamanho_LE(ListaE *l)
{
    Cell *aux;
    int tam = 0;

    if (!listaE_vazia(l))
    {
        aux = l->head;

        while(aux != NULL)
        {
            aux = aux->next;

            tam++;
        }
    }

    return tam;
}




void recuperacao_por_transposicao(ListaE *l, int vet[], int tam)
{

    Cell *auxA = l->head;
    Cell *auxP = NULL;
    int i, troca;

    for(i=0; i<tam; i++)
    {

        if (!listaE_vazia(l))
        {

            if(auxA->item == vet[i])
            {

                l->head = l->head->next;

            }
            else
            {
                auxP = auxA;

                while((auxA != NULL) && (auxA->item != vet[i]))
                {

                    auxP = auxA;

                    auxA = auxA->next;
                }
            }

            if (auxA != NULL)
            {

                if (auxP != NULL)
                {
                    troca = auxP->item;
                    auxP->item = auxA->item;
                    auxA->item = troca;
                }


            }

        }
    }



    imprimir(l);


}




int main()
{

    ListaE *l1 = criar_listaE();
    int num, qtdchave, i;

    while(num != -1)
    {
        scanf("%d", &num);
        if(num != -1)
        {

            inserir_ultimo(num, l1);
        }

    }

    scanf("%d", &qtdchave);
    int vetChaves[qtdchave];

    for(i=0; i<qtdchave; i++)
    {
        scanf("%d", &vetChaves[i]);
    }


    recuperacao_por_transposicao(l1, vetChaves, qtdchave);






    return 0;
}


