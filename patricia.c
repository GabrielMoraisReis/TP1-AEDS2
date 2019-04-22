#include <stdlib.h>
#include <stdio.h>
#include "patricia.h"
#include <sys/time.h>
#include <string.h>
#include <math.h>


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
    //printf("\nO VALOR DE I AQUI É:  %d\n", p->NO.NInterno.Pos);
    p->NO.NInterno.Letra = Letra;
    return p;
}
// PASSOU POR TODA FUNÇÃO
TipoArvore CriaNoExt(TipoChave *k,int docatual, lista2* total_pal){
    TipoArvore p;
    int i = 0;
    p = (TipoArvore)malloc(sizeof(TipoPatNo));
    p->nt = Externo;
    inicizalizaLista(&(p->list));
    p->list.ultimo->iddoc=docatual;
    total_pal->ultimo->contatotal=total_pal->ultimo->contatotal+1;
    while(*(k+i) != '\0') {
        p->NO.Chave[i] = *(k+i);
        i++;
    }
    return p;
}

TipoArvore InsereEntre(TipoChave *k, TipoArvore *t,unsigned int i,unsigned char Letra,int docatual, lista2* total_pal) {
    TipoArvore p;
    if (EExterno(*t)) {
        //printf("\nCHEGOU AQUI...\n");
        p = CriaNoExt(k,docatual, total_pal);
        if ( (*t)->NO.Chave[i] != Letra){//FIXED eu acho
            //printf("\nDISNEY CHANELL\n");
            return (CriaNoInt(i, &p, t, Letra));} // OLHAR AMANHA
        else return (CriaNoInt(i, t, &p, Letra));
    }
    else {
        //printf("\nTA CHEGANDO NO INSERE ISSO AQUI: %c\n", (*t)->NO.NInterno.Letra);
        if (*(k+((int)((*t)->NO.NInterno.Pos))) == (*t)->NO.NInterno.Letra)
            (*t)->NO.NInterno.Esq = InsereEntre(k,&(*t)->NO.NInterno.Esq,i, Letra,docatual, total_pal);
        else
            (*t)->NO.NInterno.Dir = InsereEntre(k,&(*t)->NO.NInterno.Dir,i, Letra,docatual, total_pal);
        return (*t);
    }
}

TipoArvore Insere(TipoChave *k, TipoArvore *t,int docatual, lista2* total_pal) {

    TipoArvore p;
    //printf("\nInserindo na arvore a palavra: %s\n", k); // Checkin
    unsigned int i;
    unsigned char letra;
    //printf("\nesta chegando aqui: %c\n", *(k+1));
    //printf("%d", strlen(k));       APENAS CHECAGEM
    if (*t == NULL) {
        //======= ATE AQUI CHEGOU ========
        return (CriaNoExt(k,docatual, total_pal)); // return faz sair da função
    }
        //===================ATÉ AQUI CHEGOU================
    else {
        p = *t;
        //printf("Tamanho da string: %d", strlen(k));//chegou aqui ufa
        while (!EExterno(p)) {
            //printf("++++++++++++++++++++++++++++++++");
            //printf("\nTamanho da string: %d\n", strlen(k));
            if (*(k+((int)p->NO.NInterno.Pos)) ==    p->NO.NInterno.Letra)
                p = p->NO.NInterno.Esq;
            else p = p->NO.NInterno.Dir ;
        }


        i = 0;
        letra = *(k+i);
        while (i <= D && (*(k+i) == p->NO.Chave[i])){
            //printf("%c", p->NO.Chave[i]);
            //printf(" ESPERADO\n");// essa linha aqui tem q tirar depois
            //O i SAI DAQUI COM A POSIÇÃO QUE DIFERE AS DUAS PALAVRAS
            i++;
            letra = *(k+i);
            if(i == strlen(k)+1){
                break;
            }
            //printf("\nO VALOR DE I É: %d", i);
            //printf("\nLETRA ESTA ARMAZENANDO: %c\n", letra);
        }
        //ATE AQUI CHEGOU
        if (i >= strlen(k) && p->NO.Chave[i] == '\0')//tem algum erro aqui
        {
            if(p->list.ultimo->iddoc!=docatual) {
                criacelula(&(p->list),docatual);
                p->list.ultimo->cont = p->list.ultimo->cont + 1;
                printf("Erro: chave ja esta na arvore %d\n", p->list.ultimo->cont);
                total_pal->ultimo->contatotal=total_pal->ultimo->contatotal+1;
                return (*t);
            }
            else{
                p->list.ultimo->cont = p->list.ultimo->cont + 1;
                printf("Erro: chave ja esta na arvore cont:%d id:%d\n", p->list.ultimo->cont,p->list.ultimo->iddoc);
                return (*t);
            }
        }
        else return (InsereEntre(k, t, i, letra,docatual, total_pal)); //ACHO QUE O ERRO ESTA AQUI, PQ QUANDO EU RETORNO PRO MAIN O A PASSA A APONTAR PARA ESSE NO INTERNO E PERDE A POSIÇÃO DO OUTRO

    }
}

void insertWord(Tipovec* data){
    int mPalavra = 50;
    int i = 0;
    printf("\nDigite uma nova palavra:\n");
    *data = (Tipovec)malloc(sizeof(TipoChave)*mPalavra); // 50 caracteres = 1 palavra;
    scanf(" %s", &(**data));
    //printf("TAMANHO DA STRING: %d\n", strlen(data));
    //printf("%s", *data);
}

void Inicializa(TipoArvore *a){
    *a = NULL;
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
            //printf("%c", p->NO.Chave[i]);
            //printf(" ESPERADO\n");// essa linha aqui tem q tirar depois
            //O i SAI DAQUI COM A POSIÇÃO QUE DIFERE AS DUAS PALAVRAS
            i++;
            if (*(k + i) == '\0') {
                break;
            }
        }
        if (i >= strlen(k) && p->NO.Chave[i] == '\0'){
            imprimeLista(&(*t)->list);
        }
        else
            printf("Chave não se encontra na arvore\n");

    }
}

void buscaindice(TipoArvore *t,int docatual,lista3* pesos,lista2* total_pal){
    int m=0,p=0,cont,r,n,u=0; unsigned char a[50]; relevarranjo arranjo;
    printf("Insira o valor de m: ");
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        printf("Insira a palavra: ");
        scanf("%s",a);
        BUSCA(t,a,docatual,pesos);
    }
    apontador3 aux3=pesos->primeiro;
    apontador2 aux2=total_pal->primeiro;
    for(int j=0;j<docatual;j++){
        cont=0;
        while(aux3!=NULL){
            if(aux3->iddoc==j){
                p=p+aux3->peso;
                cont++;
            }
            aux3=aux3->prox;
        }
        if (cont!=0){
            for(int o=0;o<j;j++){
                aux2=aux2->prox;
            }
            n=aux2->contatotal;
            r=(1/n)*p;
            arranjo[u].iddoc=aux2->iddoc;
            arranjo[u].r=r;
            u++;
        }
    }
    for(n=0; n<u;n++)
        printf("%d, %d",arranjo[n].r,arranjo[n].iddoc );
}

void BUSCA(TipoArvore *t, TipoChave *k,int docatual,lista3* pesos){
    TipoArvore p;
    p = *t;
    if(!(EExterno(p))){
        if(*(k+((int)p->NO.NInterno.Pos)) == p->NO.NInterno.Letra){
            BUSCA(&(*t)->NO.NInterno.Esq, k,docatual,pesos);
        }
        else
            BUSCA(&(*t)->NO.NInterno.Dir, k,docatual, pesos);
    }
    else {
        int i = 0;
        while (i <= D && (*(k + i) == p->NO.Chave[i])) {
            //printf("%c", p->NO.Chave[i]);
            //printf(" ESPERADO\n");// essa linha aqui tem q tirar depois
            //O i SAI DAQUI COM A POSIÇÃO QUE DIFERE AS DUAS PALAVRAS
            i++;
            if (*(k + i) == '\0') {
                break;
            }
        }
        if (i >= strlen(k) && p->NO.Chave[i] == '\0'){ //achou a palavara
            int w,dj,N=docatual,f;  apontador h=p->list.primeiro;
            dj=p->list.dj;
            for(int g=0;g<dj;g++){
                if(g==0)
                    f=p->list.primeiro->cont; //criacelula3(lista3* list,int id,int num)
                else{
                    h=h->prox;
                    f=h->cont;
                }
                w=f*log2(N)/dj;
                criacelula3(pesos,h->iddoc,w);
            }
        }
        else
            printf("Chave não se encontra na arvore\n");

    }
}
