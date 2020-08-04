

typedef struct pilha Pilha;

Pilha* pilha_cria();
void pilha_push(Pilha* p, char v);
char pilha_pop(Pilha* p);
int pilha_vazia(Pilha* p);
void pilha_libera(Pilha* p);
void imprimir(Pilha* p);
void concatena_pilhas(Pilha* p1, Pilha* p2);
char confere(Pilha* p);