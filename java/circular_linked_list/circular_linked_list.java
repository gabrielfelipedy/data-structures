import java.util.Scanner;
import java.util.InputMismatchException;

public class circular_linked_list
{
	private static class Lista
	{
		public int data;
		public Lista next;
	}

	public static Scanner s = new Scanner(System.in);
	public static Lista head = null;
	public static Lista tail = null;
	public static int opt;

	public static void chooseOpt()
	{
			System.out.println("\n===MENU===\n");
                        System.out.println("1 - Inserir no head da lista;");
                        System.out.println("2 - Inserir no fim da lista;");
                        System.out.println("3 - Consultar toda a lista;");
                        System.out.println("4 - Remover da lista;");
                        System.out.println("5 - Esvaziar a lista;");
                        System.out.println("6 - Sair.");
                        System.out.print("\n$> ");
	                opt = s.nextInt();
	}

	public static void toggleOpt()
	{
		if(opt < 1 || opt > 6)
			System.out.println("\nInvalid");
		else if(opt == 1)
			addStart();
		else if(opt == 2)
			addEnd();
		else if(opt == 3)
			printList();
		else if(opt == 4)
			deleteE();
		else if(opt == 5)
			clearL();
	}

	public static boolean isEmptyList(Lista novo)
	{
		if(head == null) 
		{
			head = novo;
			tail = novo;
			tail.next = novo;
			return true;
		}
		return false;
	}

	public static void addStart()
	{
		System.out.println("\nType the number: ");
		Lista novo = new Lista();
		novo.data = s.nextInt(); 
		if(!isEmptyList(novo))
		{
			novo.next = head;
			head = novo;
			tail.next = head;
		}
		System.out.println("\nNumber Inserted");
	}

	public static void addEnd()
	{
		System.out.println("\nType the number: ");
		Lista novo = new Lista();
		novo.data = s.nextInt();
		if(!isEmptyList(novo))
		{
			tail.next = novo;
			tail = novo;
			tail.next = head;
		}
		System.out.println("\nNumber inserted");
	}

	public static void printList()
	{
		if(head == null)
			System.out.println("\nEmpty");
		else
		{
			Lista aux = head;
			do {
				System.out.print(aux.data+" ");
				aux = aux.next;
			} while(aux != head);
		}
	}

	public static void deleteE()
	{
		if(head == null)
			System.out.println("\nEmpty List");
		else
		{
			System.out.print("Type the number: ");
			int numero = s.nextInt();
			boolean achou = false;
			Lista aux = head;
			Lista anterior = null;
			do
			{
				if(aux.data == numero)
				{
					achou = true;
					if(head == tail && head.data == numero) {
						head = null;
						return;
					}
					else if(aux == head)
					{
						head = aux.next;
						tail.next = head;
						aux = head;
					}
					else if(aux == tail)
					{
						tail = anterior;
						tail.next = head;
						aux = aux.next;
					}
					else 
					{
						anterior.next = aux.next;
						aux = aux.next;
					}
				}
				else
				{
					anterior = aux;
					aux = aux.next;
				}
			} while(aux != head);
			if(achou)
				System.out.println("\nDeleted");
			else
				System.out.println("\n404");
		}
	}

	public static void clearL()
	{
		if(head == null)
			System.out.println("Empty");
		else
		{
			head = null;
			System.out.println("Cleaned");
		}
	}

	public static void main(String[] args) {
		do
		{
			try
			{
				chooseOpt();
				toggleOpt();
			} 
			catch(InputMismatchException e)
			{
				System.out.println("Error. Invalid input");
				return;
			}
		}
		while(opt != 6);
	}
}
