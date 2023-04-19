#include <iostream>
#include <stdbool.h>

typedef struct Funcionario {
	char nome[20];
	double salario;
	Funcionario* next;
	Funcionario* prev;
} Funcionario;

typedef struct Lista {
	Funcionario* head;
	Funcionario* tail;
} Lista;

Lista lista;

void init() {
	lista.head = NULL;
	lista.tail = NULL;
}

void addFuncionario() {
	Funcionario* novo = new Funcionario();
	std::cout << "\nType the name: ";
	std::cin >> novo->nome;
	std::cout << "Type the salary: ";
	std::cin >> novo->salario;

	if(lista.head == NULL) {
		lista.head = novo;
		lista.tail = novo;
		novo->next = NULL;
		novo->prev = NULL;
	}
	else {
		Funcionario* anterior = NULL;
		Funcionario* aux = lista.head;
		while(aux != NULL && novo->salario > aux->salario) {
			anterior = aux;
			aux = aux->next;
		}
		if(anterior == NULL) {
			novo->next = lista.head;
			lista.head->prev = novo;
			novo->prev = NULL;
			lista.head = novo;
		}
		else if(aux == NULL) {
			lista.tail->next = novo;
			novo->prev = lista.tail;
			novo->next = NULL;
			lista.tail = novo;
		}
		else {
			anterior->next = novo;
			novo->prev = anterior;
			novo->next = aux;
			aux->prev = novo;
		}
	}
	std::cout << "\n[*] Funcionario adicionado\n";
}

double getValorImposto(Funcionario* f) {
	if(f->salario <= 850)
		return 0.0;
	else if(f->salario > 850 && f->salario <= 1200)
		return f->salario * 0.10;

	return f->salario * 0.20;
}

void printFuncionario(Funcionario* f) {
	double imposto = getValorImposto(f);
	std::cout << "\nNome: " << f->nome <<std::endl;
	std::cout << "Valor do imposto: R$ " << imposto << std::endl;
	std::cout << "Valor a receber: R$ " << f->salario - imposto << std::endl;
}

void printRelatory() {
	Funcionario* aux = lista.head;
	std::cout << "\n===BILLS RELATORY==\n";
	while(aux != NULL) {
		printFuncionario(aux);
		aux = aux->next;
	} 
}

void printLetter() {
	char c;
	std::cout << "\nType a char: ";
	std::cin >> c;
	c = tolower(c);
	bool achou = false;
	Funcionario* aux = lista.head;
	std::cout << "\n===PLAYER WHO STARTS WITH " << (char)toupper(c) << "===\n";
	while(aux != NULL) {
		char firstLetter = tolower(aux->nome[0]);
		if(c == firstLetter) {
			achou = true;
			printFuncionario(aux);
		}
		aux = aux->next;
	}
	if(!achou)
		std::cout << "\n[!] 404 not found\n";
}

void printL() {
	if(lista.head == NULL)
		std::cout << "\n[!] The list is empty\n";
	else {
		Funcionario* aux = lista.head;
		std::cout << "\n===ORDEM CRESCENTE===\n";
		while(aux != NULL) {
			std::cout << "\nNome: " << aux->nome;
			std::cout << "\nSalario: "<<aux->salario;
			aux = aux->next;
		}
	}
}

void printRL() {
	if(lista.head == NULL)
		std::cout << "\n[!] The list is empty\n";
	else {
		Funcionario* aux = lista.tail;
		std::cout << "\n===ORDEM DECRESCENTE===\n";
		while(aux != NULL) {
			std::cout << "\nNome: " << aux->nome;
			std::cout << "\nSalario: "<<aux->salario;
			aux = aux->prev;
		}
	}
}

int main() {
	init();
	for(int i=0; i < 3; i++)
		addFuncionario();
	printRelatory();
	printLetter();
	printL();
	printRL();
	return 0;
}
