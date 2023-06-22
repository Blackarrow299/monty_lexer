#include "monty.h"

void pall(stack_t **stack,unsigned int line_number)
{
    stack_t *currentNode = *stack;
    (void)line_number;
    while (currentNode != NULL)
    {
        printf("%d\n", currentNode->n);
        currentNode = currentNode->next;
    }
}
