
#include <stdio.h>
#include <stdlib.h>
#include "TST.h"
#include <sys/time.h>
#include <string.h>

// nao precisa, ja esta definido em patricia.h
//#define D 8


int main(int argc, char *argv[]) {
    TipoApontador no;
    inicializa(&no);
    InsereNo("casamento", &no);
    InsereNo("casada", &no);
    InsereNo("calada", &no);
    InsereNo("dado",&no);
    InsereNo("deidade",&no);
    InsereNo("baleia",&no);
    InsereNo("girafa",&no);
    busca("casa", no);
    busca("casada", no);
    busca("dado", no);
    busca("baleia", no);
    busca("armadilha", no);
    PrintPalavrasPrefixo("ca",no);
    PrintPalavrasPrefixo("d",no);
    PrintPalavrasPrefixo("al",no);
    PrintPalavrasPrefixo("cas",no);
}
