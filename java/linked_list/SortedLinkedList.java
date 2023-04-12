import java.util.Scanner;

public class SortedLinkedList{

	private static class Lista
	{
		public int data;
		public Lista next;
	}

	public static void main(String[] args) {

		Scanner s = new Scanner(System.in);

		Lista inicio = null;
		Lista fim = null;
		Lista aux;
		Lista anterior;

		int opt, numero;
		boolean achou;
		do {

			System.out.println("\n===MENU===\n");
                        System.out.println("1 - Inserir na lista;");
                        System.out.println("2 - Consultar toda a lista;");
                        System.out.println("3 - Remover da lista;");
                        System.out.println("4 - Esvaziar a lista;");
                        System.out.println("5 - Sair.");
                        System.out.print("\n$> ");
                        opt = s.nextInt();

                        if(opt < 1 || opt > 6)
                                System.out.println("Invalid!");

			if(opt == 1) {

				System.out.print("Type the number: ");
				Lista novo = new Lista();
				novo.data = s.nextInt();

				if(inicio == null) {
					inicio = novo;
					fim = novo;
					fim.next = null;
				} else {

					anterior = null;
					aux = inicio;
					while(aux != null && novo.data > aux.data) {

						anterior = aux;
						aux = aux.next;
					}

					if(anterior == null)
					{
						novo.next = inicio;
						inicio = novo;
					} else if(aux == null) {

						fim.next = novo;
						fim = novo;
						fim.next = null;

					} else {

						anterior.next = novo;
						novo.next = aux;
					}

					System.out.println("Inserted");
				}
			}

			if(opt == 2) {

				if(inicio == null)
					System.out.println("Empty");
				else {

					aux = inicio;
					while(aux != null) {

						System.out.print(aux.data + " ");
						aux = aux.next;
					}
				}
			}

			if(opt == 3) {

				if(inicio == null)
					System.out.println("Empty");

				else {

					System.out.print("Type the number: ");
					numero = s.nextInt();

					aux = inicio;
					anterior = null;
					achou = false;
					while(aux != null) {

						if(aux.data == numero) {

							achou = true;

							if(aux == inicio) {
								
								inicio = aux.next;
								aux = inicio;
							} else if(aux == fim)
							{
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

					if(achou)
						System.out.println("Deleted");
					else
						System.out.println("404");
				}
			}

			if(opt == 4) {

				if(inicio == null)
					System.out.println("Empty");
				else {

					inicio = null;
					System.out.println("Cleaned");
				}
			}

		} while(opt != 5);
	}
}
