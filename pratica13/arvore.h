# ifndef arvore_h
# define arvore_h

typedef char TChave[200];

typedef struct {
  //PREENCHER AQUI
  TChave chave;
  int cont;//contar se a palvra repetiu
} TItem;

typedef struct TNo {
//PREENCHER AQUI
  TItem item;
  struct TNo *esq;
  struct TNo *dir;
} TNo;

typedef  TNo *TArvore; //PREENCHER AQUI TArvore;

//Manter como especificado
void TArvoreInicia (TNo **pRaiz);

//Definir de acordo com o metodo escolhido para insercao na arvore
int TArvoreInsere (TNo **pRaiz, TItem x);

//Manter como especificado
TNo *TNoCria (TItem x);

//realizar o caminhamento adequado na arvore
//Manter como especificado
void caminhamento(TNo *p);

# endif
