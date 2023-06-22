#include "monty.h"

int main(int argc, char* argv[]) {
    FILE* file;
    char line[256];
    int lineNumber = 1;
    
    if(argv[1] == NULL || argc > 2) {
      printf("USAGE: monty file\n");
      return (EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    
    if (file == NULL) { 
      printf("Error: Can't open file %s\n", argv[1]);
      return (EXIT_FAILURE);
    }
    /* read line by line */
    while (fgets(line, sizeof(line), file) != NULL) {
      TokenNode *head = tokinizer(line);
      TokenNode* currentNode = head;
      TokenNode* nextNode;
      while (currentNode != NULL) {
        nextNode= currentNode->next;
        printf("line[%i] : %s -> %s \n",lineNumber ,TokenLiteral[currentNode->data.tokenType], currentNode->data.value);
        free(currentNode->data.value);
        free(currentNode);
        currentNode = nextNode;
      }
      lineNumber++;
    }

    fclose(file);
    return (EXIT_SUCCESS);
}
