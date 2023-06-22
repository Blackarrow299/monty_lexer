#include "monty.h"
void freeTokens(TokenNode* head) {
  TokenNode *currentNode = head;
  TokenNode *nextNode;
  while (currentNode != NULL) {
      nextNode= currentNode->next;
      free(currentNode);
      currentNode = nextNode;
    }
}
