#include <stdlib.h>
#include <stdio.h>
#include "patricia.h"
#include <sys/time.h>
#include <string.h>

// nao precisa, ja esta definido em patricia.h
//#define D 50

//OBSERVACAO PARA LEMBRAR, MUDEI O K PARA UM VETOR...

short EExterno(TipoArvore p)
{ /* Verifica se p^ e nodo externo */
    return (p->nt == Externo);
}

TipoArvore CriaNoInt(unsigned int i, TipoArvore *Esq,  TipoArvore *Dir,unsigned char Letra)
{ TipoArvore p;
    p = (TipoArvore)malloc(sizeof(TipoPatNo));
    p->nt = Interno;
    p->NO.NInterno.Esq = *Esq;
    p->NO.NInterno.Dir = *Dir;
    p->NO.NInterno.Pos = (char)i;
    printf("\nO VALOR DE I AQUI É:  %d\n", p->NO.NInterno.Pos);
    p->NO.NInterno.Letra = Letra;
    return p;
}
// PASSOU POR TODA FUNÇÃO
TipoArvore CriaNoExt(TipoChave *k){
    TipoArvore p;
    int i = 0;
    p = (TipoArvore)malloc(sizeof(TipoPatNo));
    p->nt = Externo;
    while(*(k+i) != '\0') {
        p->NO.Chave[i] = *(k+i);
        i++;
    }
    return p;
}
//==============================

///MUDAR ESSA PESQUISA DISNEY AEE

/*
void Pesquisa(TipoChave k, TipoArvore t)
{ if (EExterno(t))
    { if (k == t->NO.Chave)
            printf("Elemento encontrado\n");
        else printf("Elemento nao encontrado\n");
        return;
    }
    if (Bit(t->NO.NInterno.Pos, k) == 0) //TEM Q TIRAR ESSE BIT, MAS TENHO Q VER COMO MUDAR A COMPARACAO DE INDEX
        Pesquisa(k, t->NO.NInterno.Esq);
    else Pesquisa(k, t->NO.NInterno.Dir);
}
 */

TipoArvore InsereEntre(TipoChave *k, TipoArvore *t,unsigned int i,unsigned char Letra) {
    TipoArvore p, aux;
    if (EExterno(*t) || i < (int)((*t)->NO.NInterno.Pos)) {
        printf("\nCHEGOU AQUI...\n");
        p = CriaNoExt(k);
        if(EExterno(*t)) {
            if ((*t)->NO.Chave[i] <= Letra) {//FIXED eu acho
                printf("\nDISNEY CHANELL\n");
                return (CriaNoInt(i, t, &p, (*t)->NO.Chave[i]));
            } // OLHAR AMANHA
            else return (CriaNoInt(i, &p, t, Letra));
        }
        else{
            unsigned char nC;
            nC = InsereEntreLetra(t,i,Letra);
            if( nC <= Letra) {
                return CriaNoInt(i, t, &p, nC);

            }
            else
                return CriaNoInt(i, &p, t, Letra);
        }
    }
    else {
        printf("\nTA CHEGANDO NO INSERE ISSO AQUI: %c\n", (*t)->NO.NInterno.Letra);
        if ((*(k+((int)((*t)->NO.NInterno.Pos))) <= (*t)->NO.NInterno.Letra))
            (*t)->NO.NInterno.Esq = InsereEntre(k,&(*t)->NO.NInterno.Esq,i, Letra);
        else
            (*t)->NO.NInterno.Dir = InsereEntre(k,&(*t)->NO.NInterno.Dir,i, Letra);
        return (*t);
    }
}

TipoArvore Insere(TipoChave *k, TipoArvore *t) { 
    
    TipoArvore *p;
    //printf("\nInserindo na arvore a palavra: %s\n", k); // Checkin
    unsigned int i;
    unsigned char letra;
    //printf("\nesta chegando aqui: %c\n", *(k+1));
    //printf("%d", strlen(k));       APENAS CHECAGEM
    if (*t == NULL) {
        //======= ATE AQUI CHEGOU ========
        return (CriaNoExt(k)); // return faz sair da função
    }
    //===================ATÉ AQUI CHEGOU================
    else {

        p = t;
        if(strlen(k) < ((int)(*p)->NO.NInterno.Pos))
            p = checagem(p);
        printf("Tamanho da string: %d", strlen(k));//chegou aqui ufa
        while (!EExterno(*p)) {
            //printf("++++++++++++++++++++++++++++++++");
            //printf("\nTamanho da string: %d\n", strlen(k));
            if (*(k+((int)(*p)->NO.NInterno.Pos)) <=    (*p)->NO.NInterno.Letra)
                p = &(*p)->NO.NInterno.Esq;
            else p = &(*p)->NO.NInterno.Dir ;
        }

        i = 0;
        letra = *(k+i);
        while (i <= D && (*(k+i) == (*p)->NO.Chave[i])){
                printf("%c", (*p)->NO.Chave[i]);
                printf(" ESPERADO\n");// essa linha aqui tem q tirar depois
                //O i SAI DAQUI COM A POSIÇÃO QUE DIFERE AS DUAS PALAVRAS
                i++;
                letra = *(k+i);
                if(i == strlen(k)+1){
                    break;
                }
                printf("\nLETRA ESTA ARMAZENANDO: %c\n", letra);
        }
        //ATE AQUI CHEGOU
        printf("chave = %s", k);
        printf("chave = %s", (*p)->NO.Chave);
        if (i >= strlen(k) && (*p)->NO.Chave[i] == '\0')//tem algum erro aqui
        { printf("Erro: chave ja esta na arvore\n");  return (*t); }
        else return (InsereEntre(k, t, i, letra)); //ACHO QUE O ERRO ESTA AQUI, PQ QUANDO EU RETORNO PRO MAIN O A PASSA A APONTAR PARA ESSE NO INTERNO E PERDE A POSIÇÃO DO OUTRO

    }
}

void insertWord(Tipovec* data){
    int mPalavra = 50;
    int i = 0;
    printf("\nDigite uma nova palavra:\n");
    *data = (Tipovec)malloc(sizeof(TipoChave)*mPalavra); // 50 caracteres = 1 palavra;
    scanf(" %s", &(**data));
}

void Inicializa(TipoArvore *a){
    *a = NULL;
}

void ImprimePat(TipoArvore t){//Imprime a árvore PATRICIA
    if(EExterno(t)){//Verifica se o nó é externo, significando que uma chave deve ser mostrada
        printf("\nPalavra -> %s ", t->NO.Chave);//Imprime a palavra
    }
    else{//Se o nó for interno, significa que a árvore ainda deve ser percorrida
        if(t->NO.NInterno.Esq != NULL){//Verifica se o nó a esquerda não é vazio
            ImprimePat(t->NO.NInterno.Esq);//Avança para a esquerda primeiro (Para garantir a ordem alfabética)
        }
        if(t->NO.NInterno.Dir != NULL){//Verifica se o nó a direita não é vazio
            ImprimePat(t->NO.NInterno.Dir);//Avança para a direita por último (Para garantir a ordem alfabética)
        }
    }
}

void Pesquisa(TipoArvore *t, TipoChave *k){
    TipoArvore p;
    p = *t;
    if(!(EExterno(p))){
        if(*(k+((int)p->NO.NInterno.Pos)) == p->NO.NInterno.Letra){
            Pesquisa(&(*t)->NO.NInterno.Esq, k);
        }
        else
            Pesquisa(&(*t)->NO.NInterno.Dir, k);
    }
    else {
        int i = 0;
        while (i <= D && (*(k + i) == p->NO.Chave[i])) {
            printf("%c", p->NO.Chave[i]);
            printf(" ESPERADO\n");// essa linha aqui tem q tirar depois
            //O i SAI DAQUI COM A POSIÇÃO QUE DIFERE AS DUAS PALAVRAS
            i++;
            if (*(k + i) == '\0') {
                break;
            }
        }
        if (i >= strlen(k) && p->NO.Chave[i] == '\0')
            printf("Chave encontrada\n");
        else
            printf("Chave não se encontra na arvore");

    }
}

unsigned char InsereEntreLetra(TipoArvore *t,unsigned int i, unsigned char letra) {
    TipoArvore p;
    p = *t;
    while (!(EExterno(p))) {
        if (letra <= (*t)->NO.NInterno.Letra) {
            p = p->NO.NInterno.Esq;
        } else {
            p = p->NO.NInterno.Dir;
        }
    }
    if(p->NO.Chave[i] <= letra){
        return p->NO.Chave[i];
    }
    else return letra;
}

TipoArvore *checagem(TipoArvore *p){
    //TipoArvore *p = NULL;
    //p = t;
    while(!(EExterno(*p))) {
        p = &(*p)->NO.NInterno.Esq;
    }
    return p;
}

