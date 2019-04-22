typedef struct celula2* apontador2;
typedef struct celula2{
    int iddoc;
    int contatotal;
    apontador2 prox;
}celula2;

typedef struct lista2{
    apontador2 ultimo,primeiro;
}lista2;

void inicizalizaLista2(lista2* list);

void criacelula2(lista2* list,int id);

void imprimeLista2(lista2* list);

