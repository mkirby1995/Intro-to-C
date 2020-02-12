#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s (as a pointer), return the number of
    characters in the string.

    Do not just use the `strlen` function from the standard libary.
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

/*
    Write a function that reverses the order of string s and outputs
    the reversed string to the input array rv. The rv array will have
    enough space for the reversed string. Don't forget to terminate
    the reversed string with a null character. Return the rv array.
*/

typedef struct Stack {
      char *storage;
      int length;
      int capacity;
} Stack;


Stack *createStack(int capacity)
{
    Stack *newStack = malloc(sizeof(Stack));
    newStack->storage = malloc(capacity * sizeof(char));
    newStack->length = 0;
    newStack->capacity = capacity;
    return newStack;
}


void destroyStack(Stack *stack)
{
    free(stack->storage);
    free(stack);
}


void pushStack(Stack *stack, char value)
{
    *(stack->storage + stack->length) = value;
    stack->length ++;
}


char popStack(Stack *stack)
{
    char return_value = *(stack->storage + stack->length - 1);
    *(stack->storage + stack->length - 1) = 0;
    stack->length --;
    return return_value;
}


void printStack(Stack *stack)
{
    int i = 0;
    for (i = 0; i <= stack->length; i++) {
        printf("Value %d: %c\n", i, *(stack->storage + i));
    };
}


char *reverse_string(char *rv, char *s)
{
    // create a Stack with capacity string_length(*s)
    int len = string_length(s);
    Stack S = *createStack(len);

    int i = 0;
    // For each char in range len
    for (i = 0; i <= len; i++) {
        // Push char to stack
        pushStack(&S, *(s + i));
    };

    // While stack not empty
    int k = 0;
    char null_space = popStack(&S);
    while (S.length != 0) {
        // Pop char from stack
        char current = popStack(&S);
        // Append value to rv
        *(rv + k) = current;
        k ++;
    };

    *(rv + k) = null_space;

    // Return rv
    return rv;
}

#ifndef TESTING
int main(void)
{
    char quote1[] = "Don't forget to be awesome";
    char quote2[] = "a man a plan a canal panama";

    char rv[512];

    printf("The string 'Don't forget to be awesome' has %d characters.\n", string_length(quote1));
    printf("The string 'a man a plan a canal panama' reversed is: '%s'\n", reverse_string(rv, quote2));

    return 0;
}
#endif
