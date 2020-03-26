#include <stdio.h>
#include <stdlib.h>


typedef struct registro_paciente
{
    char cod_p;
    char nome;
    struct registro_paciente *Prox;
}reg_1;



typedef struct
{
    reg_1 *inicio;
    reg_1 *fim;
}fila;

void cria_fila(fila * F)
{
    F->inicio = malloc(sizeof(reg_1));
    F->fim = F->inicio;
    F->inicio->Prox = NULL;
}

void fila_vazia(fila *F)
{
    return F->inicio == F->fim;
}

void enfileira_reg_1(fila *F,char *cod, char *name)
{
    reg_1 *aux = malloc(sizeof(reg_1));
    F->fim->Prox = aux;
    F->fim = aux;
    aux->Prox = NULL;
    aux->cod_p = *cod;
    aux->nome = *name;
}
/*
void desenfilera(fila *F,char *cod, char *name)
{
    if((fila_vazia(F)))
    {
        printf("FILA VAZIA\n");
        //return;
    }

    reg_1 *aux = F->inicio->Prox;
    *cod = F->inicio->cod_p;
    *name = F->inicio->nome;
    free(aux);

}

void apaga_fila(fila *F)
{

}
*/
void imprime_fila(fila *F)
{/*
    if((fila_vazia(F)))
    {
        printf("FILA VAZIA\n");
        return;
    }*/
    reg_1 *aux = F->Prox;
    printf("Fila:");
    while(aux != NULL)
    {
        printf("Nome: %s,Cod: %s /",aux->nome,aux->cod_p);
        aux= aux->Prox;
    }

}

int main()
{
    int i=0;
    fila * F = malloc(sizeof(fila));
    cria_fila(F);
    for(i=0;i<4;i++)
    {
        char nome[25];
        char cod[11];
        scanf(" %[^\n]s",nome);
        scanf(" %[^\n]s",cod);
        enfileira_reg_1(F,&nome,&cod);
    }




    return 0;
}












