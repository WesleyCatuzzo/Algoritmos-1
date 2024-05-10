#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char* decodificador(char *s, int *v, int n )
{
    char aux[20];
    int i, item=0;

    for (i=1; i<n; i++)
    {
        if(v[i]!=-1){
            item=v[i];
            aux[i] = s[item-1];
        }

    }
    return (aux);

}


int main()
{
    char s[20];
    //s = (char*) malloc(20*sizeof(char));

    scanf("%s", &s);
    /*for(int j=0;j<20;j++)
    {
        scanf("%c", &s[j]);
    }*/


    //scanf("%s", &s);

    int num, i=0, cont=0;
    int *vet = (int*) malloc(sizeof(int));




    do
    {
        i++;
        scanf("%d", &vet[i]);

    }while(vet[i]!=-1);



     char retorno[20];

    retorno = decodificador(&s,vet, i);
    printf("%s", retorno);


    return 0;
}
