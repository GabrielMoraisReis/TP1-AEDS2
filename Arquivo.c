#include "Arquivo.h"
#include <string.h>
#include <ctype.h>

void LeArquivo(TipoArvore *t, TipoApontador *no, lista2* total_pal, int contaDoc){
    FILE *file;
    char  nomeArq[100];
    char string[50];
    int c=0;
    printf("Digite o endereco do arquivo");
    scanf("%s", nomeArq);
    file=fopen(nomeArq, "r");
    while(!feof(file)){
        fscanf(file, "%s", string);
        strlwr(string);
        c = strlen(string);
        for(int i=0;i<c;i++){
            if(ispunct(string[i]))
                string[i]=NULL;
        }
        *t=Insere(string, t, contaDoc, total_pal);
        InsereNo(string, no);
    }

    fclose(file);
}

