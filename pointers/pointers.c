#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Given a character pointer x (that points to an array of chars), and a
    character pointer y, copies the character contents of y over to x. Pointer
    arithmetic is necessary here. Also, make sure x points to a null terminator
    at its end to terminate it properly.

    Example call:

    char buffer[1024];

    string_copy(buffer, "Hello!");
    printf("%s", buffer); // Prints "Hello!"
*/
void string_copy(char *x, char *y)
{
    char current = *y;
    int i = 0;
    while (current != '\0') {
        //printf("Current: %c\n", current);
        //printf("Changing: %c to %c\n", *(x + i), *(y + i));
        *(x + i) = current;
        i++;
        current = *(y + i);
    };
    *(x + i + 1) = '\n';
}

/*
    Searches the input string `str` for the first instance of the
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, char c)
{
    char current = *str;
    int i = 0;
    while(current != c && *(str + i) != '\0') {
        //printf("Current: %c does not equal %c\n", current, c);
        i++;
        current = *(str + i);
    };
    if (*(str + i) == c) {
        return (str + i);
    } else {
        return NULL;
    };
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`.

    Do not use the `strstr` function from the standard library.
*/

int string_length(char *s)
{
    int i = 0;
    char current = *(s + i);
    int counter = 0;

    while (current != '\0') {
        i ++;
        current = *(s + i);
        counter ++;
    };

    return counter;
}


typedef struct Queue {
      char *storage;
      int length;
      int capacity;
} Queue;


Queue *createQueue(int capacity)
{
    Queue *newQueue = malloc(sizeof(Queue));
    newQueue->storage = malloc(capacity * sizeof(char));
    newQueue->length = 0;
    newQueue->capacity = capacity;
    return newQueue;
}


void destroyQueue(Queue *queue)
{
    free(queue->storage);
    free(queue);
}


void pushQueue(Queue *queue, char value)
{
    *(queue->storage + queue->length) = value;
    queue->length ++;
}


char popQueue(Queue *queue)
{
    int i = 0;
    char return_value = *queue->storage;
    for (i = 0; i <= queue->length; i++) {
        *(queue->storage + i) = *(queue->storage + i + 1);
    };
    queue->length --;
    return return_value;
}


void printQueue(Queue *queue)
{
    int i = 0;
    for (i = 0; i <= queue->length; i++) {
        printf("Value %d: %c\n", i, *(queue->storage + i));
    };
}

char *find_string(char *haystack, char *needle)
{
    printf("Looking for: %s\n", needle);
    int len = string_length(needle); // Length of needle
    char current = *haystack; // pointer to the first char of haystack
    Queue Q = *createQueue(len); // storage queue

    // While queue isnt full
    int k = 1;
    while (Q.length < Q.capacity) {
        // push
        pushQueue(&Q, current);
        // Increment haystack pointer
        current = *(haystack + k);
        k++;
    };

    // While queue != needle
    while (strcmp(Q.storage, needle) != 0 || *(haystack + k) != '\0') {
        // Pop from queue
        popQueue(&Q);
        current = *(haystack + k);
        // Push next char in haystack to queue
        pushQueue(&Q, current);
        k++;
    };
    /*
    if (strcmp(Q.storage, needle) != 0) {
        return NULL;
    };
    */
    printf("Found it %d, %s\n", strcmp(Q.storage, needle), Q.storage);
    int i = 0;
    // While haystack + k - i != first Char of needle
    while (*(haystack + k - i) != *(Q.storage + 0)) {
        // Go backwards
        i++;
    }
    printf("Returning: %c\n", *(haystack + k - i));
    return haystack + k - i;
}

#ifndef TESTING
int main(void)
{
    char *found_char = find_char("hello", 'e');
    char *found_string = find_string("world", "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
