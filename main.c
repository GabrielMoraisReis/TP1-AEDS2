#include <stdio.h>
#include <stdlib.h>
#include "patricia.h"
#include <sys/time.h>
#include <string.h>


// nao precisa, ja esta definido em patricia.h
//#define D 8


int main(int argc, char *argv[]) {
    TipoArvore a;
    TipoChave *k;
    lista2 total_pal;
    int docatual=1;
    int b = 0,c=0;
    Inicializa(&a);
    inicizalizaLista2(&total_pal);
    criacelula2(&total_pal, docatual);
    while(b != 5) {
        insertWord(&k);
        printf("%s", k);
        a = Insere(k, &a,docatual, &total_pal);
        printf("\nCHECAGEM: %c", (*a).NO.NInterno.Letra); // tem algum erro porque a primeira palavra nao deveria ter uma letra...
        b++;
        //printf("\n%d\n",strlen(k));
    }
    docatual=2;
    criacelula2(&total_pal, docatual);
    while(c != 5) {
        insertWord(&k);
        printf("%s", k);
        a = Insere(k, &a,docatual, &total_pal);
        printf("\nCHECAGEM: %c", (*a).NO.NInterno.Letra); // tem algum erro porque a primeira palavra nao deveria ter uma letra...
        c++;
        //printf("\n%d\n",strlen(k));
    }
    char *palavra = "casa";
    Pesquisa(&a, "banana");
    Pesquisa(&a, "casada");
    Pesquisa(&a, "cacada");
    Pesquisa(&a, "cacador");
    Pesquisa(&a, "true");
    imprimeLista2(&total_pal);
}
