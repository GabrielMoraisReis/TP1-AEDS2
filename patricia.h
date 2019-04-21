#include<stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include "lista.h"
#define D 50   /* depende de TipoChave */

typedef unsigned char TipoChave; /* a definir, dependendo da aplicacao */
typedef unsigned char TipoIndexAmp;

// desabilitei pois nao esta usando o Bit mais
//typedef unsigned char TipoDib;



typedef TipoChave* Tipovec;
typedef enum {
    Interno, Externo
} TipoNo;
typedef struct TipoPatNo* TipoArvore;
typedef struct TipoPatNo {
    TipoNo nt;
    union {
        struct {
            TipoIndexAmp Pos,Letra;
            TipoArvore Esq, Dir;
        } NInterno ;
        TipoChave Chave[50];
    } NO;
    lista list;
} TipoPatNo;

// desabilitei pois nao esta usando o Bit mais
//TipoDib Bit(TipoIndexAmp i, TipoChave k);

short EExterno(TipoArvore p);
TipoArvore CriaNoInt(unsigned int i, TipoArvore *Esq,  TipoArvore *Dir,unsigned char Letra);
TipoArvore CriaNoExt(TipoChave *k,int docatual);
void Pesquisa(TipoChave k, TipoArvore t);
TipoArvore InsereEntre(TipoChave *k, TipoArvore *t,unsigned int i,unsigned char Letra,int docatual);
TipoArvore Insere(TipoChave *k, TipoArvore *t,int docatual);
void Inicializa(TipoArvore *a);
void insertWord(Tipovec* data);
