class Matriz{
    private int lin;
    private int col;
    private int[][] matriz;

    Matriz(int lin, int col){
        this.setLinha(lin);
        this.setColuna(col);
        matriz = new int[this.getLinha()][this.getColuna()];
    }

    public void setLinha(int l){
        this.lin = l;
    }
    public int getLinha(){
        return this.lin;
    }

    public void setColuna(int c){
        this.col = c;
    }
    public int getColuna(){
        return this.col;
    }

    public void setValor(int i, int j, int v){
        this.matriz[i][j] = v;
    }
    public int getValor(int i, int j){
        return this.matriz[i][j];
    }

    public void imprimeMatriz(){
        int i, j;
        for(i=0; i<this.getLinha(); i++){
            for(j=0; j<this.getColuna(); j++){
                System.out.printf(this.matriz[i][j]+" ");
            }
            System.out.println();
        }
    }
}