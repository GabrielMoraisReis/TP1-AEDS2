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
    int b = 0;
    Inicializa(&a);
    while(b != 10) {
        insertWord(&k);
        printf("%s", k);
        a = Insere(k, &a);
        printf("\nCHECAGEM: %c", (*a).NO.NInterno.Letra); // tem algum erro porque a primeira palavra nao deveria ter uma letra...
        b++;
        //printf("\n%d\n",strlen(k));
    }
}
