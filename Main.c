#include <stdio.h>
#include <stdlib.h>
#include "TST.h"

int main(){
    TipoApontador no;
    inicializa(&no);
    InsereNo("casa", &no);
    InsereNo("cadeia", &no);
    InsereNo("catuaba", &no);
    InsereNo("deidade", &no);
    InsereNo("dados", &no);
    busca("casa", no);
    busca("deidade", no);
    busca("dados", no);
    busca("cadeia", no);
    busca("carambola", no);
    PrintPalavrasPrefixo("ca", no);
    PrintPalavrasPrefixo("da", no);
    PrintPalavrasPrefixo("dm", no);
}
