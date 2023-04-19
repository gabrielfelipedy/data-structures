#include <iostream>
#include <stdbool.h>

int main() {

	typedef struct lista {

		int num;
		lista* next;

	} lista;

	lista* inicio = NULL;
	lista* fim = NULL;

	lista* aux;
	lista* anterior;

	int opt, numero;
	bool achou;
	do {

		std::cout << "\n===MENU===\n";
		std::cout << "1 - Add on the start\n";
		std::cout << "2 - Add on the end\n";
		std::cout << "3 - Print list\n";
		std::cout << "4 - Delete an element\n";
		std::cout << "5 - Clear the list\n";
		std::cout << "6 - Exit\n" << std::endl;
		std::cout << "$> ";
		std::cin >> opt;

		if(opt < 1 || opt > 6)
			std::cout << "Invalid!" << std::endl;

		if(opt == 1) {
			std::cout << "Type the number: ";
			lista* novo = new lista();
			std::cin >> novo->num;

			if(inicio == NULL)
			{
				inicio = novo;
				fim = novo;
				fim->next = NULL;
			} else {

				novo->next = inicio;
				inicio = novo;
			}

			std::cout << "Added!" << std::endl;
		}

		if(opt == 2) {

			std::cout << "Type the number: ";
			lista* novo = new lista();
			std::cin >> novo->num;

			if(inicio == NULL)
			{
				inicio = novo;
				fim = novo;
				fim->next = NULL;
			} else {

				fim->next = novo;
				fim = novo;
				fim->next = NULL;
			}

			std::cout << "Added!" << std::endl;
		}
		if(opt == 3) {
			if(inicio == NULL)
				std::cout << "Empty\n";
			else {
				std::cout << "\n===PRINT===\n" << std::endl;
				aux = inicio;
				while(aux != NULL)
				{
					std::cout << aux->num << "  ";
					aux = aux->next;
				}
			}
		}
		if(opt == 4) {
			if(inicio == NULL)
				std::cout << "Empty" << std::endl;
			else {
				std::cout << "Type the number: ";
				std::cin >> numero;
				achou = false;
				aux = inicio;
				anterior = NULL;

				while(aux != NULL)
				{
					if(aux->num == numero)
					{
						achou = true;
						if(aux == inicio) {
							inicio = aux->next;
							delete(aux);
							aux = inicio;
						} else if(aux == fim) {

							anterior->next = NULL;
							fim = anterior;
							delete(aux);
							aux = NULL;
						} else {

							anterior->next = aux->next;
							delete(aux);
							aux = anterior->next;
						}
					} else {

						anterior = aux;
						aux = aux->next;
					}

				}

				if(achou)
					std::cout << "Number deleted\n";
				else
					std::cout << "404" << std::endl;
				}
			}
			if(opt == 5) {

				if(inicio == NULL)
					std::cout << "Empty\n";
				else {
					aux = inicio;
					while(aux != NULL) {

						inicio = inicio->next;
						delete(aux);
						aux = inicio;
					}
					std::cout << "Cleaned" << std::endl;
				}
			}

	} while(opt != 6);

	return 0;
}
