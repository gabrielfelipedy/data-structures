#include <iostream>
#include <stdbool.h>

typedef struct Lista
{
	int data;
	Lista* next;
	Lista* prev;
} Lista;

Lista* head = NULL;
Lista* tail = NULL;
int opt;
void chooseOpt(int* opt)
{
	std::cout << "\n===MENU===\n";
        std::cout << "1 - Add on the start\n";
        std::cout << "2 - Add on the end\n";
        std::cout << "3 - Print list StE\n";
        std::cout << "4 - Print list EtS\n";
        std::cout << "5 - Delete an element\n";
        std::cout << "6 - Clear the list\n";
        std::cout << "7 - Exit\n" << std::endl;
        std::cout << "$> ";
        std::cin >> *opt;
}

bool isEmpty()
{
	if(head == NULL && opt < 3)
		return true;
	else if(head == NULL && opt >= 3)
	{
		std::cout << "\nEmpty\n";
		return false;
	}
	return false;
}

void addStart()
{
	std::cout << "\nType the number: ";
	Lista* novo = new Lista();
	std::cin >> novo->data;
	if(!isEmpty())
	{
		novo->next = head;
		head->prev = novo;
		novo->prev = tail;
		tail->next = novo;
		head = novo;
	} 
	else {
		head = novo;
		tail = novo;
		tail->next = head;
		head->prev = tail;
	}
	std::cout << "Added\n";
}

void addEnd()
{
	std::cout << "\nType the number: ";
	Lista* novo = new Lista();
	std::cin >> novo->data;
	if(!isEmpty())
	{
		tail->next = novo;
		novo->prev = tail;
		tail = novo;
		tail->next = head;
		head->prev = tail;
	}
	else
	{
		head = novo;
		tail = novo;
		tail->next = head;
		head->prev = tail;
	}
	std::cout << "Added\n";
}

void printL()
{
	if(!isEmpty())
	{
		Lista* aux = head;
		do
		{
			std::cout << aux->data << " ";
			aux = aux->next;
		} 
		while(aux != head);
	}
}

void printRL()
{
	if(!isEmpty())
	{
		Lista* aux = tail;
		do
		{
			std::cout << aux->data << " ";
			aux = aux->prev;
		} 
		while(aux != tail);
	}
}

void deleteE()
{
	if(!isEmpty())
	{
		std::cout << "\nType the number: ";
		int numero;
		std::cin >> numero;

		bool achou = false;
		Lista* aux = head;
		int qtd = 0;
		do
		{
			qtd++;
			aux = aux->next;
		} while(aux != head);
		int i;
		do
		{
			if(head == tail && head->data == numero)
			{
				head = NULL;
				delete(head);
				achou = true;
			}
			else
			{
				if(aux->data == numero)
				{
					achou = true;
					if(aux == head)
					{
						head = aux->next;
						head->prev = tail;
						tail->next = head;
						delete(aux);
						aux = head;
					}
					else if(aux == tail)
					{
						tail = aux->prev;
						tail->next = head;
						head->prev = tail;
						delete(aux);
						aux = NULL;
					}
					else
					{
						aux->prev->next = aux->next;
						aux->next->prev = aux->prev;
						Lista* aux2 = aux;
						aux = aux->next;
						delete(aux2);
					}
				}
				else 
				{
					aux = aux->next;
				}
			}
			i++;
		} while(i <= qtd);
		if(achou)
			std::cout << "\nDeleted\n";
		else
			std::cout << "\n404\n";
	}
}

void clearL()
{
	if(!isEmpty())
	{
		Lista* aux = head;
		{
			head = head->next;
			delete(aux);
			aux = head;
		}
		while(aux != tail);
		delete(tail);
		head = NULL;
		std::cout << "\nCleaned\n";
	}
}

void toggleOpt(int opt)
{
	if(opt < 1 || opt > 7)
		std::cout << "\nInvalid\n";
	else if(opt == 1)
		addStart();
	else if(opt == 2)
		addEnd();
	else if(opt == 3)
		printL();
	else if(opt == 4)
		printRL();
	else if(opt == 5)
		deleteE();
	else if(opt == 6)
		clearL();
}

int main() {
	do
	{
		chooseOpt(&opt);
		toggleOpt(opt);
	} while(opt != 7);

	return 0;
}
