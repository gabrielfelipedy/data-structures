#include <iostream>
#include <stdbool.h>

typedef struct Funcionario {
	char nome[20];
	double salario;
	Funcionario* next;
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
	std::cout << "\nDigite o nome do funcionario: ";
	std::cin >> novo->nome;
	std::cout << "Digite o salário do funcionario: R$ ";
	std::cin >> novo->salario;
	if(lista.head == NULL) {
		lista.head = novo;
		lista.tail = novo;
		lista.tail->next = NULL;
	} else {
		Funcionario* aux = lista.head;
		Funcionario* anterior = NULL;
		while(aux != NULL && aux->salario > novo->salario) {
			anterior = aux;
			aux = aux->next;
		}
		if(anterior == NULL) {
			novo->next = lista.head;
			lista.head = novo;
		} else if(aux == NULL) {
			lista.tail->next = novo;
			lista.tail = novo;
			lista.tail->next = NULL;
		} else {
			anterior->next = novo;
			novo->next = aux;
		}
	}
	std::cout << "\n[!] Funcionario adicionado\n";
}

void printFuncionario(Funcionario* f) {
	std::cout << "\nNome: " << f->nome;
	std::cout << "\nSalario: R$ " << f->salario << std::endl;
}

void mediaDeSalario() {
	double total = 0.0;
	int cont = 0;
	Funcionario* aux = lista.head;
	while(aux != NULL) {
		total += aux->salario;
		cont++;
		aux = aux->next;
	}

	double media = total / cont;
	std::cout << "\nMedia de salario: R$ " << media << std::endl;
}

void showRelatory() {
	Funcionario* maior = lista.head;
	Funcionario* aux = lista.head;
	std::cout << "\n===RELATORY===\n";
	while(aux->salario >= maior->salario && aux != NULL) {
		printFuncionario(aux);
		aux = aux->next;
	}
	mediaDeSalario();
}

void showQtd() {
	double limite;
	std::cout << "\nType the salary: R$ ";
	std::cin >> limite;
	Funcionario* aux = lista.head;
	bool achou = false;
	int qtd = 0;
	while(aux != NULL) {
		if(aux->salario <= limite) break;
		achou = true;
		qtd++;
		aux = aux->next;
	}
	if(achou)
		std::cout << qtd << " Funcionarios ganham mais de R$ " << limite << std::endl;
	else 
		std::cout << "\n[!] 404 not found\n";
}

int main() {
	init();
	for(int i = 0; i < 5; i++) {
		addFuncionario();
	}
	showRelatory();
	showQtd();
	return 0;
}
