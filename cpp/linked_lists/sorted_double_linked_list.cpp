#include <stdbool.h>
#include <iostream>

typedef struct Lista
{
	int data;
	Lista* next;
	Lista* prev;
} Lista;
Lista* head = NULL;
Lista* tail = NULL;

void chooseOption(int* opt)
{
	std::cout << "\n===MENU===\n";
        std::cout << "1 - Add on the List\n";
        std::cout << "2 - Print list StE\n";
        std::cout << "3 - Print list EtS\n";
        std::cout << "4 - Delete an element\n";
        std::cout << "5 - Clear the list\n";
        std::cout << "6 - Exit\n" << std::endl;
        std::cout << "$> ";
        std::cin >> *opt;
}

void add()
{
	std::cout << "\nType the number: ";
	Lista* novo = new Lista();
	std::cin >> novo->data;

	if(head == NULL)
	{
		novo->next = NULL;
		novo->prev = NULL;
		head = novo;
		tail = novo;
	} else
	{
		Lista* aux = head;
		while(aux != NULL && novo->data > aux->data)
			aux = aux->next;
		if(aux == head)
		{
			novo->next = head;
			head->prev = novo;
			novo->prev = NULL;
			head = novo;
		}
		else if(aux == NULL)
		{
			tail->next = novo;
			novo->next = NULL;
			novo->prev = tail;
			tail = novo;
		} else
		{
			novo->next = aux;
			aux->prev->next = novo;
			novo->prev = aux->prev;
			aux->prev = novo;
		}
	}
	std::cout << "\nAdd" << std::endl;
}

void printL()
{
	if(head == NULL)
		std::cout << "Empty" << std::endl;
	else
	{
		Lista* aux = head;
		while(aux != NULL)
		{
			std::cout << aux->data << " ";
			aux = aux->next;
		}
	}
}

void printRL()
{
	if(head == NULL)
		std::cout << "Empty" << std::endl;
	else
	{
		Lista* aux = tail;
		while(aux != NULL)
		{
			std::cout << aux->data << " ";
			aux = aux->prev;
		}
	}
}

void deleteE()
{
	if(head == NULL)
		std::cout << "Empty" << std::endl;
	else
	{
		int numero;
		std::cout << "\nType the number: ";
		std::cin >> numero;

		Lista* aux = head;
		bool achou = false;
		while(aux != NULL)
		{
			if(aux->data == numero)
			{
				achou = true;
				if(aux == head)
				{
					head = aux->next;
					if(head != NULL)
						head->prev = NULL;
					delete(aux);
					aux = head;
				}
				else if(aux == tail)
				{
					tail = aux->prev;
					tail->next = NULL;
					delete(aux);
					aux = NULL;
				}
				else
				{
					delete(aux);
					aux = aux->next;
				}
			} 
			else
			{
				aux = aux->next;
			}
		}
		if(achou)
			std::cout << "Deleted" << std::endl;
		else
			std::cout << "404" << std::endl;
	}
}

void clearL()
{
	if(head == NULL)
		std::cout << "Empty\n";
	else
	{
		Lista* aux = head;
		while(aux != NULL) {
			head = head->next;
			delete(aux);
			aux = head;
		}
		std::cout << "Cleaned" << std::endl;
	}
}

int main() 
{
	int opt;
	do 
	{
		chooseOption(&opt);
		if(opt == 1) add();
		if(opt == 2) printL();
		if(opt == 3) printRL();
		if(opt == 4) deleteE();
		if(opt == 5) clearL();
	} while(opt != 6);
	return 0;
}
