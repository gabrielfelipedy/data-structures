import java.util.Scanner;

public class DoubleLinkedList {

	private static class Lista {

		public int data;
		public Lista next;
		public Lista prev;
	}

	public static void main(String[] args) {

		Scanner s = new Scanner(System.in);

		Lista head = null;
		Lista tail = null;

		Lista aux;
		
		int opt, numero;
		boolean achou;

		do {
			System.out.println("\n===MENU===\n");
                        System.out.println("1 - Inserir no inicio da lista;");
                        System.out.println("2 - Inserir no fim da lista;");
                        System.out.println("3 - Consultar StE;");
			System.out.println("4 - Consultar EtS;");
                        System.out.println("5 - Remover da lista;");
                        System.out.println("6 - Esvaziar a lista;");
                        System.out.println("7 - Sair.");
                        System.out.print("\n$> ");
                        opt = s.nextInt();

                        if(opt < 1 || opt > 7)
                                System.out.println("Invalid!");

			if(opt == 1) {

				System.out.println("Type the number: ");
				Lista novo = new Lista();
				novo.data = s.nextInt();

				if(head == null) {

					head = novo;
					tail = novo;
					novo.next = null;
					novo.prev = null;
				} else {

					novo.next = head;
					head.prev = novo;
					novo.prev = null;
					head = novo;
				}

				System.out.println("\nAdd");
			}

			if(opt == 2) {

				System.out.println("Type the number: ");
				Lista novo = new Lista();
				novo.data = s.nextInt();

				if(head == null) {

					head = novo;
					tail = novo;
					novo.next = null;
					novo.prev = null;
				} else {

					tail.next = novo;
					novo.prev = tail;
					tail = novo;
					tail.next = null;
				}

				System.out.println("\nAdd");
			}

			if(opt == 3) {

				if(head == null)
					System.out.println("\nEmpty");
				else {

					aux = head;
					while(aux != null) {

						System.out.print(aux.data + " ");
						aux = aux.next;
					}
				}
			}

			if(opt == 4) {

				aux = tail;
				while(aux != null) {

					System.out.print(aux.data + " ");
					aux = aux.prev;
				}
			}

			if(opt == 5) {

				if(head == null)
					System.out.println("\nEmpty");
				else {

					System.out.println("Type the number: ");
					numero = s.nextInt();

					achou = false;
					aux = head;
					while(aux != null) {

						if(aux.data == numero)
						{

							achou = true;

							if(aux == head)
							{
								head = aux.next;
								if(head != null)
									head.prev = null;
								aux = head;
							}
							else if(aux == tail) {

								tail = tail.prev;
								tail.next = null;
								aux = null;

							} else {

								aux.prev.next = aux.next;
								aux.next.prev = aux.prev;
								aux = aux.next;
							}
						}
						else
						{

							aux = aux.next;
						}
					}

					if(achou)
						System.out.println("\nDeleted");
					else
						System.out.println("\n404");
				}
			}

			if(opt == 6) {

				if(head == null)
					System.out.println("\nEmpty");
				else {

					head = null;
					System.out.println("\nCleaned");
				}
			}

		} while(opt != 7);
	}
}
