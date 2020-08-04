

typedef struct no No;
typedef struct lista Lista;

Lista* criar_lista();
void destruir_lista(Lista* lis);
void inserir_fim(Lista* lis, int elem);
void imprimir_lista(Lista* lis);
void remover_no(Lista* lis, No* no);
No* buscar_elem(Lista* lis, int elem);
int confere_tripla_nada(Lista* lis);
void remover_all_elem(Lista* lis, int elem);