#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void insert(node** head, int value) {
    node* new = malloc(sizeof(node));
    if(new == NULL) {
        printf("Error");
        return;
    }

    new->data = value;
    new->next = *head;
    *head = new;
}

void printList(node* head) {
    node* aux = head;
    while(aux) {
        printf("%d ", aux->data);
        aux = aux->next;
    }
    putchar('\n');
}

int main() {
    node* lista = NULL;
    printList(lista);


    insert(&lista, 23);
    insert(&lista, 6);
    insert(&lista, 16);

    printList(lista);
}