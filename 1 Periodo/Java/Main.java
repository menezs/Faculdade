import java.util.Scanner;

class main{
	public static void main (String[] args){
		Scanner ler = new Scanner(System.in);
		int lin, col, valor;
		int i, j;

		System.out.printf("Hello, word!\n");
		lin=ler.nextInt();
		col=ler.nextInt();
		Matriz mat = new Matriz(lin, col);

		for(i=0; i<lin; i++){
			for(j=0; j<col; j++){
				valor=ler.nextInt();
				mat.setValor(i, j, valor);
			}
		}

		mat.imprimeMatriz();

	}
}