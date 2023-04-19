#include <iostream>
#include <stdbool.h>

typedef struct Numero {
	int data;
	Numero* next;
} Numero;

typedef struct DNumero {
	int data;
	DNumero* next;
	DNumero* prev;
} DNumero;

typedef struct Lista {
	Numero* head;
	Numero* tail;
} Lista;

typedef struct ListaGeral {
	DNumero* head;
	DNumero* tail;
} ListaGeral;

Lista lp;
Lista li;
ListaGeral lg;

void init() {
	lp.head = NULL;
	lp.tail = NULL;
	li.head = NULL;
	li.tail = NULL;
	lg.head = NULL;
	lg.tail = NULL;
}

void addList(Lista* l, Numero* n) {
	if(l->head == NULL) {
		l->head = n;
		l->tail = n;
		l->tail->next = NULL;
	}
	else {
		n->next = l->head;
		l->head = n;
	}
}

void printList(Lista l) {
	Numero* aux = l.head;
	std::cout << "\n===PRINT===\n";
	while(aux != NULL) {
		std::cout << aux->data << " " << std::endl;
		aux = aux->next;
	}
}

void addNumber() {
	Numero* novo = new Numero();
	std::cout << "\nType a number: ";
	std::cin >> novo->data;
	if(novo->data % 2 == 0)
		addList(&lp, novo);
	else
		addList(&li, novo);
}

DNumero* NumToDNum(Numero* d) {
	DNumero* novo = new DNumero();
	novo->data = d->data;
	return novo;
}

void copyNumbers(ListaGeral* lg, Lista l) {	
	Numero* a = l.head;
	while(a != NULL) {
		DNumero* novo = NumToDNum(a);
		if(lg->head != NULL) {
			DNumero* aux = lg->head;
			while(aux != NULL && novo->data > aux->data) {
				aux = aux->next;
			}
			
			if(aux == lg->head) {
				novo->next = lg->head;
				novo->prev = NULL;
				lg->head->prev = novo;
				lg->head = novo;
			} else if(aux == NULL) {
				lg->tail->next = novo;
				novo->prev = lg->tail;
				novo->next = NULL;
				lg->tail = novo;
			} else {
				aux->prev->next = novo;
				novo->next = aux;
				novo->prev = aux->prev;
				aux->prev = novo;
			}
		} else {
			lg->head = novo;
			lg->tail = novo;
			novo->next = NULL;
			novo->prev = NULL;
		}
		std::cout << "\n[*] Number " << novo->data << " added" << std::endl;
		a = a->next;
	}
}

void printGeral() {
	if(lg.head == NULL)
		std::cout << "\n[!] Empty\n";
	else {
		DNumero* aux = lg.head;
		std::cout << "\n===PRINT ALL===\n";
		while(aux != NULL) {
			std::cout << aux->data << std::endl;
			aux = aux->next;
		}
	}
}

int main() {
	init();
	for(int i = 0; i < 20; i++) {
		addNumber();
	}
	printList(lp);
	printList(li);
	copyNumbers(&lg, lp);
	copyNumbers(&lg, li);
	printGeral();
	return 0;
}
