#include <stdlib.h>
#include <stdio.h>
#include "lista2.h"

void inicizalizaLista2(lista2* list){
    list->primeiro=NULL;
    list->ultimo=NULL;
}


void criacelula2(lista2* list,int id){
    if (list->ultimo == NULL)
    { list->ultimo = (apontador2) malloc(sizeof(celula2));
        list->primeiro = list->ultimo; }
    else
    { list->ultimo->prox = (apontador2) malloc(sizeof(celula2));
        list->ultimo = list->ultimo->prox;
    }
    list->ultimo->iddoc = id;
    list->ultimo->contatotal=0;
    list->ultimo->prox = NULL;
}

void imprimeLista2(lista2* list){
    apontador2 pAux;
    pAux=list->primeiro;
    while(pAux!=NULL){
        printf("<%d, %d> ", pAux->contatotal, pAux->iddoc);
        pAux= pAux->prox;
    }
}
