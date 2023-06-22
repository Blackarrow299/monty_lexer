#include "monty.h"

TokenNode* getTokensByLine(TokenNode* head, int line_number) {
    TokenNode* filteredHead = NULL;
    TokenNode* filteredTail = NULL;

    TokenNode* currentNode = head;
    while (currentNode != NULL) {
        if (currentNode->data.line_number == line_number) {
            TokenNode* filteredNode = (TokenNode*)malloc(sizeof(TokenNode));
            if(filteredNode == NULL) {
              _mallocFailed();
            }
            filteredNode->data = currentNode->data;
            filteredNode->next = NULL;

            if (filteredHead == NULL) {
                filteredHead = filteredNode;
                filteredTail = filteredNode;
            } else {
                filteredTail->next = filteredNode;
                filteredTail = filteredNode;
            }
        }

        currentNode = currentNode->next;
    }

    return filteredHead;
}
