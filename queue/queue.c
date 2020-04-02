#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

typedef struct Queue {
    unsigned int length;
    unsigned int capacity;
    int *storage;
} Queue;

/*
    Creates a queue by allocating the appropriate amount of memory for an
    instance of the Queue struct, and initializes all of the fields of the
    struct. Also allocates memory for the queue's storage structure.
*/
Queue *createQueue(unsigned capacity)
{
    Queue *newQueue = malloc(sizeof(Queue));
    newQueue->storage = malloc(capacity * sizeof(unsigned int));
    newQueue->length = 0;
    newQueue->capacity = capacity;
    return newQueue;
};

/*
    Adds the given item to the end of the queue. If the queue does
    not have room, expand the queue's available storage so that it
    does have room for the additional item.
*/

void enqueue(Queue *q, int item)
{
    if (q->length == q->capacity) {
        printf("Resizing from %d to %d\n", q->capacity, q->capacity * 2);
    };
    *(q->storage + q->length) = item;
    printf("Adding %d to the Queue\n", *(q->storage + q->length));
    unsigned int k = 0;
    for (k = 0; k <= q->length; k++) {
        printf("Value %d: %d\n", k, *(q->storage + k));
    };
    q->length ++;
};

/*
    Removes the item at the front of the queue and returns it.
    If the queue is empty, this function should return -1.
*/
int dequeue(Queue *q)
{
    unsigned int k = 0;
    for (k = 0; k <= q->length; k++) {
        printf("Value %d: %d\n", k, *(q->storage + k));
    };
    printf("Queue length: %d\n", q->length);
    if (q->length != 0) {
        unsigned int i = 0;
        int return_value = *q->storage;
        for (i = 0; i <= q->length; i++) {
            *(q->storage + i) = *(q->storage + i + 1);
        }
        q->length --;
        return return_value;
      } else {
        return 0;
      }
};

/*
    Frees the memory used to hold the queue instance and its
    associated storage.
*/
void destroyQueue(Queue *q)
{
    free(q->storage);
    free(q);
}


#ifndef TESTING
int main(void)
{
    Queue *q = createQueue(4);

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);

    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));

    destroyQueue(q);

    return 0;
}
#endif
