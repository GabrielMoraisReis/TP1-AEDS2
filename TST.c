#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TST.h"

void inicializaTST(TipoApontador* no){
    *no=NULL;
}


void InsereNo (char* string, TipoApontador *no)
{
    if(*no==NULL){
        *no= (TipoApontador)malloc(sizeof(TipoNoTST));
        (*no)->palavra=string[0];
        (*no)->fdir=NULL;
        (*no)->fmid=NULL;
        (*no)->fesq=NULL;
        (*no)->type=NO;
    }
    if(string[0] < (*no)->palavra)
        InsereNo(string, &(*no)->fesq);

    else if(string[0] > (*no)->palavra)
        InsereNo(string, &(*no)->fdir);

    else {
        if(*(string+1)=='\0') { //verifica se é a ultima letra da string sendo inserida, se for, o marcador de fim de string passa a ser true
            (*no)->type = YES;
            return;
        } else
            InsereNo(++string,&(*no)->fmid);//"++string" avança a posição do vetor, meio que deleta a posição 0 e a antiga
        //posição 1 vira a nova posição 0
    }
}


//procura a palavra na arvore, é diferente do checa pre porque mesmo que a palavra esteja na arvore, se ela não
//tiver um marcador irá mostrar que não tem. Ex: inseriu casado, mas não inseriu casa e procurou casa, retorna falso
void busca(char* string, TipoApontador no){
    if (no==NULL) {
        printf("Nao encontrado\n");
        return;
    }
    if (*string< no->palavra)
        busca(string, no->fesq);
    else if(*string>no->palavra)
        busca(string, no->fdir);
    else{
        if (*(string+1)=='\0' && no->type==YES){
            printf("Encontrado\n");
            return;}
        else
            busca(++string, no->fmid);
    }

}

//Verifica se existe o prefixo na arvore
TipoApontador ChecaPre(char* string, TipoApontador no){
    if (no==NULL)
        return NULL;
    if (*string< no->palavra)
        ChecaPre(string, no->fesq);
    else if(*string>no->palavra)
        ChecaPre(string, no->fdir);
    else{
        if (*(string+1)=='\0'){
            return no;}
        else
            ChecaPre(++string, no->fmid);
    }
}

//Função que irá percorrer a arvore a partir do final do prefixo e printar todas as palvras que tem esse prefixo
void BuscaPalavraPre(char* prefixo, TipoApontador inicio){
    if(inicio->type != NO)
        printf("Encontrada:%s%c\n",prefixo,inicio->palavra);

    if(inicio->fesq != NULL)
        BuscaPalavraPre(prefixo, inicio->fesq);

    if(inicio->fdir != NULL)
        BuscaPalavraPre(prefixo, inicio->fdir);

    if(inicio->fmid != NULL) {
        char *_prefixo = (char *)malloc(strlen(prefixo) + 2);
        sprintf(_prefixo,"%s%c",prefixo,inicio->palavra);
        BuscaPalavraPre(_prefixo,inicio->fmid);
    }
}

//Função que chama ChecaPre pra ver se tem prefixo, se tiver manda a posição da ultima letra desse prefixo pra BuscaPalavraPre
//e se não tiver informar o usuário
void PrintPalavrasPrefixo (char* prefixo, TipoApontador no){
    TipoApontador atual = ChecaPre(prefixo, no);
    if(NULL == atual)
        printf("Sem palavras com o prefixo %s\n",prefixo);
    else {
        BuscaPalavraPre(prefixo,atual->fmid);
    }
}
