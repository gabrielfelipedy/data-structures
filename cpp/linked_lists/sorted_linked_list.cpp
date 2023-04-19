#include <iostream>
#include <stdbool.h>

typedef struct Lista {

	int data;
	Lista* next;

} Lista;

int main() {

	Lista* inicio = NULL;
	Lista* fim = NULL;
	Lista* aux;
	Lista* anterior;

	int opt, numero;
	bool achou;

	do {

		std::cout << "\n===MENU===\n";
                std::cout << "1 - Add on the list\n";
                std::cout << "2 - Print list\n";
                std::cout << "3 - Delete an element\n";
                std::cout << "4 - Clear the list\n";
                std::cout << "5 - Exit\n" << std::endl;
                std::cout << "$> ";
                std::cin >> opt;

                if(opt < 1 || opt > 6)
                        std::cout << "Invalid!" << std::endl;

		if(opt == 1) {

			std::cout << "Type the number: ";
			Lista* novo = new Lista();
			std::cin >> novo->data;

			if(inicio == NULL)
			{
				inicio = novo;
				fim = novo;
				fim->next = NULL;
			} else {

				anterior = NULL;
				aux = inicio;
				while(aux != NULL && novo->data > aux->data)
				{
					anterior = aux;
					aux = aux->next;
				}

				if(anterior == NULL) {

					novo->next = inicio;
					inicio = novo;
				} else if(aux == NULL) {

					fim->next = novo;
					fim = novo;
					fim->next = NULL;
				} else {

					anterior->next = novo;
					novo->next = aux;
				}

				std::cout << "Added" << std::endl;
			} 
		}
		if(opt == 2) {

			if(inicio == NULL)
				std::cout << "Empty" << std::endl;
			else {

				aux = inicio;
				while(aux != NULL) {

					std::cout << aux->data << " ";
					aux = aux->next;
				}
			}
		}

		if(opt == 3) {

			if(inicio == NULL)
				std::cout << "Empty" << std::endl;
			else {

				std::cout << "Type the number: ";
				std::cin >> numero;
				
				aux = inicio;
				anterior = NULL;
				achou = false;
				while(aux != NULL) {

					if(aux->data == numero) {

						achou = true;

						if(aux == inicio)
						{
							inicio = aux->next;
							delete(aux);
							aux = inicio;
								
						} else if(aux == fim)
						{
							
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
					std::cout << "Deleted" << std::endl;
				else
					std::cout << "404" << std::endl;
			}
		}

		if(opt == 4) {

			if(inicio == NULL)
				std::cout << "Empty" << std::endl;
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

	} while(opt != 5);

	return 0;
}
