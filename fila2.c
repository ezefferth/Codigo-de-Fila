#include <stdio.h>
#include <stdlib.h>

typedef struct Noh_T{

    int item;
    struct Noh_T *Prox;

} Noh;

typedef struct {

    Noh *inicio;
    Noh *fim;

} fila;

void cria_fila (fila *F){

    F->inicio = malloc(sizeof(Noh));

    F->fim = F->inicio;
    F->inicio->Prox = NULL;

}

int fila_vazia (fila *F){

    return F->inicio == F->fim;

}

void enfileira (fila *F, int *x){

    Noh *aux;

    aux=malloc(sizeof(Noh));

    F->fim->Prox = aux;
    F->fim = aux;

    aux->Prox = NULL;
    aux->item = *x;

}

void desenfileira (fila *F, int *x){

    Noh *aux;

    if (fila_vazia(F)){
        printf("FILA VAZIA");
        return;

    }

   aux = F->inicio;
   F->inicio = F->inicio->Prox;
   *x = F->inicio->item;
   aux->Prox = NULL;

   free(aux);


}

void apaga_fila (fila *F){

    int x;

    while(!(fila_vazia(F))){

        desenfileira(F,&x);
    }

    free(F->inicio);
}



int main(){

    int i,x;

    fila *F=malloc(sizeof(fila));

    cria_fila(F);

    for (i=0;i<30;i++){
        enfileira(F,&i);
    }

    for (i=0;i<30;i++){
        desenfileira(F,&x);
        printf("%d\n",x);
    }

    apaga_fila(F);

    free(F);

}
