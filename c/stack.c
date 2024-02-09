#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int num;
    struct stack* next;
} stack;

void add(stack** head, int value) {
    stack* new = malloc(sizeof(stack));

    new->num = value;
    new->next = *head;
    *head = new;
}

void delete(stack** head) {
    if(*head == NULL) return;

    *head = (*head)->next;
}

void printStack(stack* pilha) {
    stack* aux = pilha;

    while(aux) {
        printf("%d ", aux->num);
        aux = aux->next;
    }
    putchar('\n');
}

int main() {
    stack* pilha = NULL;
    printStack(pilha);


    add(&pilha, 23);
    add(&pilha, 6);
    add(&pilha, 16);

    printStack(pilha);
}