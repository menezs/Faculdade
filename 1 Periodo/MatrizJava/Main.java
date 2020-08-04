
class Main{
	public static void main(String[] args){

		System.out.print(":::::::::::MATRIZ::::::::::::");
		Matriz mat= new Matriz(3,3);
		mat.inicializaRandom();
		mat.imprime();
		mat.inicializaOrdenado();
		mat.imprime();

		mat.inicializaManual(5);
		mat.imprime();
		mat.inicializaManualUmporUm();
		mat.imprime();

		mat.imprime();
		
	}

}
