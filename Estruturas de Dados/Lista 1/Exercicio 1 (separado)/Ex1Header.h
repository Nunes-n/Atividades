		struct itens {char nome[26]; float qtde; int comprado; struct itens *prox, *ant;};
typedef struct itens TItem;
typedef struct {TItem *inicio, *final; int qtdeItens, qtdeComprados;} TLista;

void iniciaLista (TLista *);
int IncluiItem (TLista *, char *, float);
void ImprimeLista (TLista *, char);
int AtualizaItem (TLista *, char *);
int ExcluiItem(TLista *, char *);