#include <stdio.h>
#include <stdlib.h>

typedef struct data {
	int data;
	struct data* next;
} data;

typedef struct Queue {
	data* head;
	data* tail;
} Queue;

void add(Queue** queue, int value) {
    data* new = malloc(sizeof(data));
	new->data = value;
	new->next = NULL;

	if((*queue)->head == NULL) {
		(*queue)->head = new;
		(*queue)->tail = new;
	}
	else {
		(*queue)->tail->next = new;
		(*queue)->tail = new;
	}
}

void printQueue(Queue* queue) {
    data* aux = queue->head;
    while(aux) {
        printf("%d ", aux->data);
        aux = aux->next;
    }
    putchar('\n');
}

Queue* createQueue() {
    Queue* new = malloc(sizeof(Queue));
    new->head = NULL;
    new->tail = NULL;

    return new;
}

int main() {
    Queue* fila = createQueue();

    printQueue(fila);

    add(&fila, 16);
    add(&fila, 6);
    add(&fila, 23);

    printQueue(fila);

    return 0;
}