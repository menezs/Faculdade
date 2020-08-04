typedef struct matriz Matriz;
struct matriz{
  int lin;
  int col;
  float* v;
};

Matriz* mat_cria(int m, int n);
void mat_libera(Matriz* mat);
float mat_acessa(Matriz* mat, int i, int j);
void mat_atribui(Matriz* mat, int i, int j, float v);
int mat_linhas(Matriz* mat);
int mat_colunas(Matriz* mat);
Matriz* transposta(Matriz* mat);
Matriz* mat_mult(Matriz* a, Matriz* b);