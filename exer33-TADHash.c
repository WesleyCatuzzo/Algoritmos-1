
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int tamanho;
    int *buckets;
} HashT;

HashT *criar(unsigned int tam){
    HashT *t = malloc(sizeof(HashT));
    int i;

    t->tamanho = tam;
    t->buckets = malloc(tam * sizeof(int));

    for (i = 0; i < tam; i++)
        t->buckets[i] = -1;

    return t;
}


// Função hash, onde k é a chave e B é o tamanho da tabela
static int hashingF(int k, int B){
    return k % B;
}


// Implementação de uma função rehash por overflow progressinvo
// hashC: resultado de uma função hash
// tentativa: é o número da tentativa para localizar ou posicionar uma chave
static int overflow_prog(int hashC, int B, int tentativa){
    return (hashC + tentativa) % B;
}

//Antes
/*int buscar(int chave, HashT *t){
    int x = hashingF(chave, t->tam);

    if (t->buckets[x] == chave)
        return x;

    return -1;
}*/


//Depois
int buscar(int chave, HashT *t){
    int x = hashingF(chave, t->tamanho); // Posição ou código hash (primeira tentativa) para chave chave
    int i, rh;

    if (t->buckets[x] == chave) // se chave foi encontrada na primeira tentativa, retornar a posição definida pela função hash
        return x;
    else if (t->buckets[x] >= 0){ // Se a chave localizada na tabela hash for diferente da procurada, verificar se o bucket da posição x não está vazia (ou seja, não tenha o valor -1)
        i = 1; // tentativa
        rh = x; // rehash

        /* Loop para continuar a busca da chave através de rehash
        Critérios de parada:
        1: as tentativas foram esgotadas (i == t->tam)
        2: a chave foi encontrada (t->buckets[rh] == chave)
        3: uma posição vazia é encontrada (t->buckets[rh] == -1)
        */
        while ((i < t->tamanho) && (t->buckets[rh] != chave) && (t->buckets[rh] >= 0)){
            rh = overflow_prog(x, t->tamanho, i); // aplicar a função rehash

            i++; // atualizar a tentativa
        }

        // Verificar se a chave foi encontrada, ou seja, não foram esgotadas as tentativas
        // e o bucket na posição rh não  vazio (chave maior que -1)
        if ((i < t->tamanho) && (t->buckets[rh] == chave))
            return rh;
    }else
        return -1;
}

//Antes
/*int inserir(int chave, HashT *t){
    int x;

    if (t != NULL){
        x = hashingF(chave, t->tam);

        if (t->buckets[x] < 0){
            t->buckets[x] = chave;

            return 1;
        }
    }

    return 0;
}*/


// Depois
int inserir(int chave, HashT *t){
    int x;
    int i, rh;

    // verificar se a tabela não é nula e se a chave a ser inserida é válida
    if ((t != NULL) && (chave > 0)){
        x = hashingF(chave, t->tamanho); // Aplicação de função hash na chave chave

        // Caso o bucket na posição x seja vazio (valor negativo) ou represente uma
        // remoção (igual a zero), basta incluir a chave chave
        if (t->buckets[x] <= 0){
            t->buckets[x] = chave;

            return 1;
        }else{ // Se a posição x não for vazia, tentar encontrar um bucket vazio
            i = 1; // tentativa
            rh = x; // rehash

            /*
            Loop para procurar um bucket vazio
            Critérios de parada:
            1: as tentativas foram esgotadas (i == t->tam), ou seja, a tabela está cheia
            2: a chave foi encontrada (t->buckets[rh] == chave): como a chave já existe, então não é feita a inserção
            3: uma posição vazia é encontrada (t->buckets[rh] == -1)
            */
            while ((i < t->tamanho) && (t->buckets[rh] != chave) && (t->buckets[rh] > 0)){
                rh = overflow_prog(x, t->tamanho, i); // aplicar a função rehash

                i++; // atualizar a tentativa
                printf("tam:%d",t->tamanho);
            }

            // Se as tentativas não foram esgotadas e um bucket apropriado (vazio ou com sinal de que a chave foi removida) foi encontrado, incluir a chave na posição rh
            if ((i < t->tamanho) && (t->buckets[rh] <= 0)){
                t->buckets[rh] = chave;

                return 1;
            }
        }
    }

    return 0;
}


// Antes
/*int remover(int chave, HashT *t){
    int x;

    if (t != NULL){
        x = hashingF(chave, t->tam);

        if (t->buckets[x] == chave){
            t->buckets[x] = -1;

            return 1;
        }
    }

    return 0;
}*/


// Depois
int remover(int chave, HashT *t){
    int x;

    if (t != NULL){
        x = buscar(chave, t->tamanho); // procurar a chave

        // Se a chave existir, basta atribuir valor 0 para sinalizar a remoção da chave chave na posição x
        if (t->buckets[x] == chave){
            t->buckets[x] = 0;

            return 1;
        }
    }

    return 0;
}


void imprimir(HashT *t){
    int i;
    if (t != NULL){
        for (i = 0; i < t->tamanho; i++){
            if (t->buckets[i] >= 0)
                printf("%d\n", t->buckets[i]);
        }
    }
}

int liberar(HashT *t){
    if (t != NULL){
        free(t->buckets);

        free(t);

        return 1;
    }

    return 0;
}

int hashmult(int chave, float c, int tamanho){
        float a;
        a = chave * c;
        printf("%f\t", a);
        a = a - (int)a;
        printf("%f\t", a);
        //printf("%d",tamanho*a);
        return (int)(tamanho * a);
}

int main(void){
         float c;
        int n, qtd, i, chave, x;
        HashT *tb, t;
        printf("t:%d",t.tamanho);
        scanf("%f", &c);
        //if (c < 1 && c > 0){
            scanf("%d", &t.tamanho);
printf("t:%d",t.tamanho);
        
            scanf("%d", &qtd);
            tb = criar(n);
            for (i = 0; i < qtd; i++)
            {
                scanf("%d", &chave);
                chave = hashmult(chave, c, n);
                printf("chave:%d\n", &chave);
                x = inserir(chave, tb);
            }
            
        imprimir(tb);
        return 0;
}
    
