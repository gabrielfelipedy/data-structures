#include <stdio.h>

typedef struct stack {
    int num;
    struct stack* next;
} stack;

void add(stack** head, int num) {
    stack* new = (stack*)malloc(sizeof(stack));

    new->num = num;
    new->next = *head;
    *head = new;
}

void remove(stack** head) {
    if(*head == NULL) return;

    *head = (*head)->next;
}