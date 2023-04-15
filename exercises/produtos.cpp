#include <iostream>
#include <stdbool.h>
#include <cctype>

typedef struct Product
{
	unsigned int code;
	double price;
	unsigned int qtd;
	Product* next;
} Product;

typedef struct ListOfProducts
{
	Product* head;
	Product* tail;
} ListOfProducts;

ListOfProducts list;

void init()
{
	list.head = NULL;
	list.tail = NULL;
}

/***
void chooseOpt(int *opt)
{
	std::cout << "\n===MENU===" << std::endl;
	std::cout << "1 - Add a product" << std::endl;
	std::cout << "2 - Print the list" << std::endl;
	std::cout << "3 - Delete an element" << std::endl;
	std::cout << "4 - Clear the list" << std::endl;
	std::cout << "5 - Quit" << std::endl;
	std::cout << "$> ";
	std::cin >> *opt;
}
***/

bool isEmpty()
{
	if(list.head == NULL)
		return true;
	return false;
}

void addProduct()
{
	Product* novo = new Product();
	std::cout << "\nType the code of the product: ";
	std::cin >> novo->code;
	std::cout << "Type the price of the product: ";
	std::cin >> novo->price;
	std::cout << "Type the qtd of the product: ";
	std::cin >> novo->qtd;

	if(isEmpty())
	{
		list.head = novo;
		list.tail = novo;
		list.tail->next = NULL;
	} 
	else
	{
		novo->next = list.head;
		list.head = novo;
	}
	std::cout << "\n[*] Product added\n";
}

void printProduct(Product* product)
{
	std::cout << "\nCode: " << product->code;
	std::cout << "\nPrice: R$ " << product->price;
	std::cout << "\nQtd: " << product->qtd << std::endl;
}

void printList()
{
	if(isEmpty())
		std::cout << "\n[!] The List is empty\n";
	else
	{
		std::cout << "\n===RELATORY OF PRODUCTS===\n";
		Product* aux = list.head;
		while(aux != NULL)
		{
			printProduct(aux);
			aux = aux->next;
		}
		std::cout << "\n===PRODUCTS ARE MORE THAN 500===\n";
		delete(aux);
		aux = list.head;
		bool achou = false;
		while(aux != NULL)
		{
			if(aux->qtd > 500)
			{
				achou = true;
				printProduct(aux);
			}
			aux = aux->next;
		}
		if(!achou)
			std::cout << "[!] No products more than 500\n";
	}
}

/***
void deleteProduct()
{
	if(isEmpty())
		std::cout << "\n[!] The list is empty\n";
	else
	{
		int codeLooked;
		std::cout << "\nType the code of the product: ";
		std::cin >> codeLooked;

		Product* aux = list.head;
		Product* anterior = NULL;
		bool achou = false;
		while(aux != NULL)
		{
			if(aux->code == codeLooked)
			{
				achou = true;
				if(aux == list.head)
				{
					list.head = aux->next;
					delete(aux);
					aux = list.head;
				}
				else if(aux == list.tail)
				{
					list.tail = anterior;
					list.tail->next = NULL;
					delete(aux);
					aux = NULL;
				}
				else
				{
					anterior->next = aux->next;
					delete(aux);
					aux = anterior->next;
				}
			}
			else
			{
				anterior = aux;
				aux = aux->next;
			}
		}

		if(achou)
			std::cout << "\n[*] Product deleted\n";
		else
			std::cout << "\n[!] Product found\n";
	}
}

void toggleOpt(int opt)
{
	if(opt < 1 || opt > 5 || isalpha(opt))
		std::cout << "\n[!] Invalid option\n";
	else if(opt == 1)
		addProduct();
	else if(opt == 2)
		printList();
	else if(opt == 3)
		deleteProduct();
}
***/

void setDiscount()
{
	double discount;
	std::cout << "\nType the discount, in %: ";
	std::cin >> discount;

	Product* aux = list.head;
	while(aux != NULL)
	{
		aux->price -= aux->price * (discount / 100.0);
		aux = aux->next;
	}
}

int main() {

	init();
	for(int i=0; i < 5; i++)
	{
		addProduct();
	}
	setDiscount();
	printList();
	/*** Code for menu
	int opt;
	do
	{
		chooseOpt(&opt);
		toggleOpt(opt);
	}
	while(opt != 5);
	***/
	return 0;
}
