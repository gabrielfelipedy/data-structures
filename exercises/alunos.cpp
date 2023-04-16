#include <iostream>
#include <stdbool.h>

typedef struct Aluno {
	char nome[20];
	double nota;
	Aluno* next;
	Aluno* prev;
} Aluno;

typedef struct Lista {
	Aluno* head;
	Aluno* tail;
} Lista;

Lista lista;

void init() {
	lista.head = NULL;
	lista.tail = NULL;

}

void addAluno() {
	Aluno* novo = new Aluno();
	std::cout << "\nDigite o nome do aluno: ";
	std::cin >> novo->nome;
	std::cout << "Digite a nota final do aluno: ";
	std::cin >> novo->nota;

	if(lista.head == NULL) {
		lista.head = novo;
		lista.tail = novo;
		novo->next = NULL;
		novo->prev = NULL;
	}
	else {
		lista.tail->next = novo;
		novo->prev = lista.tail;
		novo->next = NULL;
		lista.tail = novo;
	}
}

void printAluno(Aluno* a) {
	std::cout << "\nNome: " << a->nome;
	std::cout << "\nNota: " << a->nota;
}

void showAproved() {
	Aluno* aux = lista.head;
	double media = 7.0;
	std::cout << "\n===APROVED===\n";
	bool achou = false;
	while(aux != NULL) {
		if(aux->nota >= media) {
			achou = true;
			printAluno(aux);
		}
		aux = aux->next;
	}
	if(!achou) 
		std::cout << "\n[!] Nenhum aluno aprovado\n";
}
int main() {		
	init();
	for(int i=0; i<5; i++)
		addAluno();
	showAproved();
	return 0;
}
