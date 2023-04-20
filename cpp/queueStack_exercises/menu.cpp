#include <iostream>
#include <stdbool.h>

typedef struct Numero {
	int data;
	Numero* next;
} Numero;

typedef struct Pilha {
	Numero* top;
} Pilha;

Pilha pilha;

void init() {
	pilha.top = NULL;
}

void showMenu(int* opt)
{
	std::cout << "\n===MENU===\n";
	std::cout << "1 - Cadastrar número\n";
	std::cout << "2 - Mostrar números pares entre o primeiro e ultimo numero cadastrados\n";
	std::cout << "3 - Excluir números\n";
	std::cout << "4 - Sair\n";
	std::cout << "\n$> ";
	std::cin >> *opt;
}

void add() {
	Numero* novo = new Numero();
	std::cout << "Type the number: ";
	std::cin >> novo->data;
	novo->next = pilha.top;
	pilha.top = novo;
	std::cout << "[*] Added\n";
}

void showPairs() {

	if(pilha.top == NULL) {
		std::cout << "[!] Empty\n";
		return;
	}

	Numero* aux = pilha.top;
	int ultimo = aux->data;
	while(aux->next != NULL)
		aux = aux->next;
	int primeiro = aux->data;
	
	int maior = (ultimo > primeiro) ? ultimo : primeiro;
	int menor = (ultimo < primeiro) ? ultimo : primeiro;

	std::cout << "\n===PARES ENTRE " << menor << " e " << maior << "===\n";
	for(int i = menor; i <= maior; i++) {
		if(i % 2 == 0) {
			std::cout << i << " ";
		}
	}
}

void del() {
	if(pilha.top == NULL)
		std::cout << "[!] Empty\n";
	else {
		pilha.top = pilha.top->next;
		std::cout << "[*] Deleted\n";
	}
}

void toggleMenu(int opt)
{
	if(opt < 1 || opt > 4)
		std::cout << "\nInvalid";
	else if(opt == 1)
		add();
	else if(opt == 2)
		showPairs();
	else if(opt == 3)
		del();
}

int main() {
	init();
	int opt;
	do {
		showMenu(&opt);
		toggleMenu(opt);
	} while(opt != 4);
	return 0;
}
