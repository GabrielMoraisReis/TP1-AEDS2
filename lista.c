#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

void inicizalizaLista(lista* list){
    list->primeiro=(apontador)malloc(sizeof(celula));
    list->ultimo=list->primeiro;
    list->primeiro->prox=NULL;
    list->ultimo->cont=1;
}

void criacelula(lista* list,int id){
    list->ultimo->prox=(apontador)malloc(sizeof(celula));
    list->ultimo=list->ultimo->prox;
    list->ultimo->prox=NULL;
    list->ultimo->iddoc=id;
    list->ultimo->cont=0;
}

void imprimeLista(lista* list){
    apontador pAux;
    pAux=list->primeiro;
    while(pAux!=NULL){
        printf("<%d, %d> ", pAux->cont, pAux->iddoc);
        pAux= pAux->prox;
    }
}
