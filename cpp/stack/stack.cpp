#include <stdbool.h>
#include <iostream>

typedef struct Stack {
	int data;
	Stack* next;
} Stack;

Stack* top = NULL;

void chooseOpt(int* opt) {
	std::cout << "\n===MENU===\n" << std::endl;
	std::cout << "1 - Adicionar" << std::endl;
	std::cout << "2 - Consultar" << std::endl;
	std::cout << "3 - Remover" << std::endl;
	std::cout << "4 - Limpar" << std::endl;
	std::cout << "5 - Sair" << std::endl;
	std::cout << "$> ";
	std::cin >> *opt;
}

void add() {
	Stack* novo = new Stack();
	std::cout << "Type the Value: ";
	std::cin >> novo->data;
	novo->next = top;
	top = novo;
	std::cout << "[*] Number added\n";
}

bool isEmpty(Stack* s) {
	if(s == NULL) {
		std::cout << "[!] Empty\n";
		return true;
	}
	return false;
}

void printList() {
	if(!isEmpty(top))
	{
		Stack* aux = top;
		while(aux != NULL) {
			std::cout << aux->data << std::endl;
			aux = aux->next;
		}
	}
}

void remove() {
	if(!isEmpty(top))
	{
		top = top->next;
		std::cout << "[*] Deleted\n";
	}
}

void clear() {
	if(!isEmpty(top))
	{
		Stack* aux = top;
		while(aux != NULL) {
			top = top->next;
			delete(aux);
			aux = top;
		}
		std::cout << "[*] Cleaned\n";
	}
}
void toggleOpt(int opt) {
	if(opt < 1 || opt > 5)
		std::cout << "\n[!] Invalid option\n";
	else if(opt == 1)
		add();
	else if(opt == 2)
		printList();
	else if(opt == 3)
		remove();
	else if(opt == 4)
		clear();
}

int main() {
	int opt;
	do {
		chooseOpt(&opt);
		toggleOpt(opt);
	} while(opt != 5);
	return 0;
}
