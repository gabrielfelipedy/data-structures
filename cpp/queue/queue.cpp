#include <iostream>
#include <stdbool.h>

typedef struct Numero {
	int data;
	Numero* next;
} Numero;

typedef struct Queue {
	Numero* head;
	Numero* tail;
} Queue;

Queue queue;

void init() {
	queue.head = NULL;
	queue.tail = NULL;
}

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
	Numero* novo = new Numero();
	std::cout << "Type the number: ";
	std::cin >> novo->data;
	novo->next = NULL;
	if(queue.head == NULL) {
		queue.head = novo;
		queue.tail = novo;
	}
	else {
		queue.tail->next = novo;
		queue.tail = novo;
	}
	std::cout << "[!] Inserted\n";
}

bool isEmpty() {
	if(queue.head == NULL) {
		std::cout << "[!] Empty\n";
		return true;
	}
	return false;
}

void printList() {
	if(!isEmpty()) {
		Numero* aux = queue.head;
		while(aux != NULL) {
			std::cout << aux->data << " \n";
			aux = aux->next;
		}
	}
}

void remove() {
	if(!isEmpty()) {
		queue.head = queue.head->next;
		std::cout << "[*] Removed\n";
	}
}

void clear() {
	if(!isEmpty()) {
		Numero* aux = queue.head;
		while(aux != NULL) {
			queue.head = queue.head->next;
			delete(aux);
			aux = queue.head;
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
	init();
	int opt;
	do {
		chooseOpt(&opt);
		toggleOpt(opt);
	} while(opt != 5);
	return 0;
}
