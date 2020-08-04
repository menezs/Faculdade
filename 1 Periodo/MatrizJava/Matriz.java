import java.util.Scanner;
import java.util.Random;


class Matriz{
	private int mat[][]; 
	private int numI, numJ;
	
	Matriz(){
		this.setNumI(5);
		this.setNumI(5);
		mat=new int[this.getNumI()][this.getNumJ()];
	}
	Matriz(int novoI, int novoJ){
		this.setNumI(novoI);
		this.setNumJ(novoJ);
		mat= new int[this.getNumI()][this.getNumJ()];
	}
	
	public int getElemento(int indiceI, int indiceJ){
		return 	this.mat[indiceI][indiceJ];
	}
	public void setElemento (int indiceI, int indiceJ, int novoValor){
		this.mat[indiceI][indiceJ]=novoValor;
	}
	
	public int getNumI(){
		return this.numI;
	}
	private void setNumI(int novoI){
		this.numI=novoI;
	}
	public int getNumJ(){
		return this.numJ;
	}
	private void setNumJ(int novoJ){
		this.numJ=novoJ;
	}
	
	public void imprime(){
		int i, j;
		
		for (i=0; i<this.getNumI(); i++){
			for(j=0; j<this.getNumJ(); j++){
				System.out.print(" "+this.getElemento(i, j));
			}
			System.out.println(" ");
		}
		System.out.println(" ");
		System.out.println(" ");
		
	}

	public void inicializaManual(int valor){
		int i, j;
		
		for (i=0; i<this.getNumI(); i++){
			for(j=0; j<this.getNumJ(); j++){
				this.setElemento(i, j, valor);
			}
		}
	}

	public void inicializaManualUmporUm(){
		Scanner ler=new Scanner(System.in);		
		int i, j, x;
		
		for (i=0; i<this.getNumI(); i++){
			for(j=0; j<this.getNumJ(); j++){
				x=ler.nextInt();
				this.setElemento(i, j, x);
			}
		}
	}
	
	public void inicializaRandom(){
		Random num=new Random();
		int i, j, max;
		max=this.getNumI()*this.getNumJ();
		for (i=0; i<this.getNumI(); i++){
			for(j=0; j<this.getNumJ(); j++){
				this.setElemento(i, j, num.nextInt(max));
			}
			System.out.println();	
		}
	}

	public void inicializaOrdenado(){
		int i, j, valor;
		valor=0;
		for (i=0; i<this.getNumI(); i++){
			for(j=0; j<this.getNumJ(); j++){
				this.setElemento(i, j, valor);
				valor++;
			}		
		}
	}

}











