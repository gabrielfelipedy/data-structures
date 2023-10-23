import java.util.Scanner;

public class LinkedList {

	private static class Lista {

		public int num;
		public Lista next;
	}
		
	public static void main(String[] args) {

		Scanner s = new Scanner(System.in);

		Lista inicio = null;
		Lista fim = null;

		Lista aux, anterior;

		int opt, numero;
		do {

			System.out.println("\n===MENU===\n");
			System.out.println("1 - Inserir no inicio da lista;");	
			System.out.println("2 - Inserir no fim da lista;");	
			System.out.println("3 - Consultar toda a lista;");	
			System.out.println("4 - Remover da lista;");	
			System.out.println("5 - Esvaziar a lista;");
			System.out.println("6 - Sair.");
			System.out.print("\n$> ");
			opt = s.nextInt();

			if(opt < 1 || opt > 6)
				System.out.println("Invalid!");

			if(opt == 1) {

				System.out.print("Type the number: ");
				Lista novo = new Lista();
				novo.num = s.nextInt();

				if(inicio == null)
				{
					inicio = novo;
					fim = novo;
					novo.next = null;
				} else {

					novo.next = inicio;
					inicio = novo;
				}

				System.out.println("Inserted!");
			}

			if(opt == 2) {

				System.out.print("Type the number: ");
				Lista novo = new Lista();
				novo.num = s.nextInt();

				if(inicio == null)
				{
					inicio = novo;
					fim = novo;
					novo.next = null;
				} else {

					fim.next = novo;
					fim = novo;
					fim.next = null;
				}
			}

			if(opt == 3) {

				if(inicio == null)		
					System.out.println("Empty list!");
				else {

					System.out.println("\n===PRINT===\n\n");
					aux = inicio;
					while(aux != null) {
						System.out.println(aux.num);
						aux = aux.next;
					}
				}
			}

			if(opt == 4) {

				if(inicio == null) 
					System.out.println("Empty list");
				else {

					System.out.print("Type the number: ");
					numero = s.nextInt();
					aux = inicio;
					anterior = null; 
					boolean achou = false;
					while(aux != null) {

						if(aux.num == numero) {
							achou = true;
							if(aux == inicio) {
								inicio = aux.next;
								aux = inicio;
							} else if(aux == fim) {

								anterior.next = null;
								fim = anterior;
								aux = null;
							} else {
	
								anterior.next = aux.next;
								aux = aux.next;
							}
						} else {

							anterior = aux;
							aux = aux.next;
						}
					}

					if(achou) {
						System.out.println("Removed");
					} else {
						System.out.println("404");
					}
				}

			}

			if(opt == 5) {

				if(inicio == null)
					System.out.println("Empty list");
				else {
					inicio = null;
					System.out.println("Unfilled");
				}
			}
		} while(opt != 6);
	}
}
