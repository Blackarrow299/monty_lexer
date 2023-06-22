#include "monty.h"
void pint(stack_t **stack, unsigned int line_number)
{
    (void)line_number;
    if (*stack == NULL)
    {
        fprintf(stderr, "Error: Stack is empty\n");
        return;
    }

    printf("%d\n", (*stack)->n);
}
