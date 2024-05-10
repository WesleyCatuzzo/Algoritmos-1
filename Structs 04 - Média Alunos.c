#include <stdio.h>
#include <math.h>

typedef struct {
    int cod;
    char nome[255];
    float notas[3];
    float media;
} aluno_t;

void calculaMedia(aluno_t aluno[], int n){
    int i, j;
    float media=0;
    for(i=0; i<n; i++){
        media=0;
        for(j=0; j<=3; j++){
            media=media+aluno[i].notas[j];
        }
    aluno[i].media = media/3;
    //printf("%.1f", aluno[i].media);
    }



}


int encontraMaiorMedia(aluno_t aluno[], int n)
{
    int i;
    float aux=0;
    float maiorMedia = -1;
    for (i = 0; i < n; i++)
    {
        if(aluno[i].media > maiorMedia)
        {
            maiorMedia = aluno[i].media;
            aux = i;
        }


    }
    return aux;
}

int encontraMenorMedia(aluno_t aluno[], int n){

    int i;
    float aux=0;
    float menorMedia = 999;
    for (i = 0; i < n; i++)
    {
        if(aluno[i].media < menorMedia)
        {
            menorMedia = aluno[i].media;
            aux = i;
        }


    }
    return aux;
}

int encontraMaiorP1(aluno_t aluno[], int n){
    int i;
    float aux=0;
    float maiorP1 = -1;

    for(i=0; i<n; i++){

       if(aluno[i].notas[0] > maiorP1){

            maiorP1= aluno[i].notas[0];
            aux = i;
       }
    }
    return aux;
}


int main(){

    int nAlunos, i, j, maiorMedia, menorMedia, maiorP1;


    scanf("%d", &nAlunos);

    aluno_t aluno[nAlunos];

    for (i = 0; i < nAlunos; i++){
        scanf("%d", &aluno[i].cod);
        scanf("%s", &aluno[i].nome);
        for(j=0; j<2; j++){
            scanf("%f", &aluno[i].notas[j]);
        }
        scanf("%f", &aluno[i].media);
    }
    /*for (i = 0; i < nAlunos; i++){
        printf("%d\n", aluno[i].cod);
        printf("%s\n", aluno[i].nome);
        for(j=0; j<2; j++){
            printf("%.1f\n", aluno[i].notas[j]);
        }
        printf("%.1f\n", aluno[i].media);
    }*/

    calculaMedia(aluno, nAlunos);
    for (i = 0; i < nAlunos; i++){
        if(aluno[i].media < 6){
            printf("Reprovado!");
        }else
            printf("Aprovado!");
        printf("\n");
    }


    maiorMedia = encontraMaiorMedia(aluno, nAlunos);
    printf("O aluno com maior media e: %d %s %.1f", aluno[maiorMedia].cod, aluno[maiorMedia].nome, aluno[maiorMedia].media);


    menorMedia = encontraMenorMedia(aluno, nAlunos);
    printf("\nO aluno com menor media e: %d %s %.1f", aluno[menorMedia].cod, aluno[menorMedia].nome, aluno[menorMedia].media);


    maiorP1= encontraMaiorP1(aluno, nAlunos);
    printf("\nO aluno com maior P1 e: %d %s %.1f", aluno[maiorP1].cod, aluno[maiorP1].nome, aluno[maiorP1].notas[0]);



    return 0;

}
