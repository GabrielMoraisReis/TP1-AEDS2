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
    int docatual=1;
    int b = 0,c=0;
    Inicializa(&a);
    while(b != 5) {
        insertWord(&k);
        printf("%s", k);
        a = Insere(k, &a,docatual);
        printf("\nCHECAGEM: %c", (*a).NO.NInterno.Letra); // tem algum erro porque a primeira palavra nao deveria ter uma letra...
        b++;
        //printf("\n%d\n",strlen(k));
    }
    docatual=2;
    while(c != 5) {
        insertWord(&k);
        printf("%s", k);
        a = Insere(k, &a,docatual);
        printf("\nCHECAGEM: %c", (*a).NO.NInterno.Letra); // tem algum erro porque a primeira palavra nao deveria ter uma letra...
        c++;
        //printf("\n%d\n",strlen(k));
    }
}
