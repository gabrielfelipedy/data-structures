#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

	int data;
	struct Node* next;
	struct Node* prev;

} Node;

Node* list;

Node* getNewNode(int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

void append(int data) {

	Node* newNode = getNewNode(data);

	if(list == NULL) {
		list = newNode;
		return;
	}

	while(list->next != NULL)
		list = list->next;

	list->next = newNode;
	newNode->prev = list;
	list = newNode;
}

void prepend(int data) {

	Node* newNode = getNewNode(data);
	if(list == NULL) {
		list = newNode;
		return;
	}

	list->prev = newNode;
	newNode->next = list;
	list = newNode;
}

void print() {

	Node* temp = list;

	while(temp != NULL) {
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}

void reversePrint() {

	Node* temp = list;
	if(temp == NULL) return;

	while(temp->next != NULL)
		temp = temp->next;

	while(temp != NULL) {
		printf("%d\n", temp->data);
		temp = temp->prev;
	}
}

int main() {

	list = NULL;
	append(2);
	append(4);
	append(6);
	append(7);
	append(8);
	append(9);
	append(10);
	print();
	//reversePrint();
}
