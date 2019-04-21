#include "lista.h"
#include <stdlib.h>

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
