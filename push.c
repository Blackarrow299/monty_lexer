#include "monty.h"

void push(stack_t **stack, unsigned int line_number) {
  stack_t *newNode = malloc(sizeof(stack_t));
  
  TokenNode* token = getTokensByLine(TokenNodeHead, line_number);
  (void)stack;
  (void)line_number;
   
  if(token->next->data.tokenType != INT || token->next == NULL) {
    fprintf(stderr, "L%i: usage: push integer\n", line_number);
    exit(EXIT_FAILURE);
  }

  if (newNode == NULL) {
    _mallocFailed();
  }

  newNode->n = atoi(token->next->data.value);
  newNode->prev = NULL;
  newNode->next = *stack;

  if (*stack != NULL) {
    (*stack)->prev = newNode;
  }

  *stack = newNode;

  freeTokens(token);
}
