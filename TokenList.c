#include "monty.h"

void appendTokenList(TokenNode** head, Token data) {
  TokenNode* lastNode = *head;
  TokenNode* newNode = (TokenNode*)malloc(sizeof(TokenNode));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
    return;
  }

  while (lastNode->next != NULL) {
    lastNode = lastNode->next;
  }

  lastNode->next = newNode;
}
