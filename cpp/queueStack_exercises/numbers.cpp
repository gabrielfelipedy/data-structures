#include <iostream>

typedef struct Numero {
	int data;
	Numero* next;
} Numero;

typedef struct Pilha {
	Numero* top;
} Pilha;

typedef struct Fila {
	Numero* head;
	Numero* tail;
} Fila;

Pilha pilha;
Fila fila;

void init() {
	pilha.top = NULL;
	fila.head = NULL;
	fila.tail = NULL;
}

void addStack() {
	Numero* novo = new Numero();
	std::cout << "Type the number: ";
	std::cin >> novo->data;
	novo->next = pilha.top;
	pilha.top = novo;
}

void addQueue() {
	Numero* novo = new Numero();
	std::cout << "Type the number: ";
	std::cin >> novo->data;
	if(fila.head == NULL) {
		fila.head = novo;
		fila.tail = novo;
	}
	else
	{
		fila.tail->next = novo;
		fila.tail = novo;
	}
}

void printLista(Numero* n) {
	Numero* aux = n;
	while(aux != NULL) {
		std::cout << aux->data << " ";
		aux = aux->next;
	}
}

void printRelatory() {
	std::cout << "\n===FULL RELATORY===\n";
	printLista(pilha.top);
	printLista(fila.head);

	std::cout << "\n===FILA RELATORY===\n";
	printLista(fila.head);

	std::cout << "\n===PILHA RELATORY===\n";
	printLista(pilha.top);
}

int main() {
	init();
	int i;
	for(i = 0; i < 5; i++){
		addStack();
	}
	for(i = 0; i < 5; i++) {
		addQueue();
	}
	printRelatory();
	return 0;
}
