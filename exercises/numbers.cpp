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
		l->tail->next = n;
		l->tail = n;
		l->tail->next = NULL;
	}
}

void printList(Lista l) {
	Numero* aux = l.head;
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

Numero* DNumToNum(DNumero* d) {
	Numero* novo = new Numero();
	novo->data = d->data;
	novo->next = NULL;
	return novo;
}

DNumero* NumToDNum(Numero* d) {
	DNumero* novo = new DNumero();
	novo->data = d->data;
	novo->next = NULL;
	novo->prev = NULL;
	return novo;
}

void copyNumbers(Lista lista) {
	ListaGeral auxG = lg;
	Numero* ap = lista.head;
	DNumero* ag = auxG.head;
	while(ap != NULL) {
		if(ag == NULL) {
			DNumero* aux = NumToDNum(ap);
			auxG.head = aux;
			auxG.tail = aux;
			aux->next = NULL;
			aux->prev = NULL;
		}
		else {
			while(ag != NULL && ap->data > ag->data) {
				ag = ag->next;
			}
			if(ag == auxG.head) {
				DNumero* aux = NumToDNum(ap);
				aux->next = ag;
				aux->prev = NULL;
				ag->prev = aux;
				ag = aux;
			} else if(ag == NULL) {
				DNumero* aux = NumToDNum(ap);
				auxG.tail->next = aux;
				aux->prev = auxG.tail;
				auxG.tail = aux;
				auxG.tail->next = NULL;
			} else {
				DNumero* aux = NumToDNum(ap);
				aux->next = ag;
				ag->prev->next = aux;
				aux->prev = ag->prev;
				ag->prev = aux;
			}
		}
		ap = ap->next;
	}
	lg = auxG;
}

void printGeral() {
	if(lg.head == NULL)
		std::cout << "\n[!] Empty\n";
	else {
		DNumero* aux = lg.head;
		while(aux != NULL) {
			std::cout << aux->data << " ";
			aux = aux->next;
		}
	}
}

int main() {
	init();
	for(int i = 0; i < 5; i++) {
		addNumber();
	}
	printList(lp);
	printList(li);
	copyNumbers(lp);
	copyNumbers(li);
	printGeral();
	return 0;
}
