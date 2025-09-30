#define MAX 50

		struct itens {char nome[26]; float qtde; int comprado;};
typedef struct itens TItem;
typedef struct {TItem itens[MAX]; int qtdeItens, qtdeComprados;} TLista;

void iniciaLista (TLista *);
int IncluiItem (TLista *, char *, float);
void ImprimeLista (TLista *, char);
int AtualizaItem (TLista *, char *);
int ExcluiItem(TLista *, char *);
void EncerraPrograma(TLista *);
