enum ntype {NO,YES};

typedef struct Node* TipoApontador;

typedef struct Node {
    char palavra;
    TipoApontador fesq, fdir, fmid;
    enum ntype type;
}TipoNo;

void inicializa(TipoApontador *no);
void InsereNo( char* string, TipoApontador* node);
void busca(char* string, TipoApontador No);

void PrintPalavrasPrefixo(char* prefixo, TipoApontador No);
TipoApontador CriaNo(char w, enum ntype t);