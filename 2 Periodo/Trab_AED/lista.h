

typedef struct no No;
typedef struct lista Lista;

Lista* criar_lista();
void destruir_lista(Lista* lis);
void inserir_fim(Lista* lis);
void imprimir_lista(Lista* lis);
No* buscar_ano(Lista* lis, int x);
No* buscar_nome(Lista* lis, char* nome);
void emprestar(Lista* lis, int mat, char* nome);
void devolver(Lista* lis, int mat, char* nome);
