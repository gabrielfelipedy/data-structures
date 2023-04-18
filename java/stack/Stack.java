import java.util.Scanner;

public class Stack {

	private static class Pilha {
		public int data;
		public Pilha next;
	}

	public static Pilha top = null;
	public static Scanner s = new Scanner(System.in);
	public static int opt;

	public static void main(String[] args) {
		do
		{
			chooseOpt();
			toggleOpt();
		} while(opt != 5);
	}

	public static void chooseOpt() {
		System.out.println("\n===MENU===\n");
		System.out.println("1 --> Add");
		System.out.println("2 --> Print");
		System.out.println("3 --> Remove");
		System.out.println("4 --> Clear");
		System.out.println("5 --> Exit");
		System.out.print("$> ");
		opt = s.nextInt();
	}

	public static void toggleOpt() {
		if(opt < 1 || opt > 5)
			System.out.println("[!] Invalid");
		else {
			if(opt == 1)
				add();
			else if(opt == 2)
				printL();
			else if(opt == 3)
				remove();
			else if(opt == 4)
				clear();
		}
	}

	public static void add() {
		Pilha novo = new Pilha();
		System.out.print("Type the number: ");
		novo.data = s.nextInt();
		novo.next = top;
		top = novo;
		System.out.println("[*] Added");
	}

	public static void printL() {
		if(top == null)
			System.out.println("[!] Empty");
		else {
			Pilha aux = top;
			System.out.println("\n===PRINT===\n");
			while(aux != null) {
				System.out.print(aux.data + " ");
				aux = aux.next;
			}
		}
	}

	public static void remove() {
		if(top == null)
			System.out.println("[!] Empty");
		else {
			top = top.next;
			System.out.println("[*] Removed");
		}
	}

	public static void clear() {
		if(top == null)
			System.out.println("[!] Empty");
		else {
			top = null;
			System.out.println("[*] Cleaned");
		}
	}
}
