typedef struct celula* apontador;
typedef struct celula{
    int iddoc;
    int cont;
    apontador prox;
}celula;

typedef struct lista{
    apontador ultimo,primeiro;
}lista;

void inicizalizaLista(lista* list);

void criacelula(lista* list,int id);

void imprimeLista(lista* list);
