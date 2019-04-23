#include <stdio.h>
#include "Arquivo.h"
int main() {
    TipoArvore t;
    TipoApontador no;
    lista2 total_pal;
    int a=0; int b; int contaDoc=0;
    char prefixo[50];
    Inicializa(&t);//inicializa patricia
    inicializaTST(&no);
    inicizalizaLista2(&total_pal);
    while(a==0){
        printf("Digite 1 para inserir um novo arquivo, 2 para imprimir o indice invertido, 3 para buscar uma palavra, 4 para sugestoes de palavra pelo prefixo");
        scanf("%d", &b);
        if(b==1){
            contaDoc++;
            criacelula2(&total_pal, contaDoc);
            LeArquivo(&t, &no, &total_pal, contaDoc);
        }
        else if(b==2){
            ImprimeIndice(t);
        }
        else if(b==3){

        }
        else if(b==4){
            printf("Digite o prefixo");
            scanf("%s", prefixo);
            PrintPalavrasPrefixo(prefixo, no);
        }
        else
            printf("Numero invalido");
        printf("Digite 0 para continuar ou 1 para sair");
        scanf("%d", &a);
    }
}
