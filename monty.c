#include "monty.h"
TokenNode *TokenNodeHead = NULL;

char* TokenLiteral[] = {
  "int",
  "push", 
  "pall",
  "pint"
  "illegal"
};

int main(int argc, char* argv[]) {
    FILE* file;
    char line[1024];
    unsigned int lineNumber = 1; 
    TokenNode* currentNode = NULL;
    TokenNode* nextNode;

    if(argv[1] == NULL || argc > 2) {
      fprintf(stderr, "USAGE: monty file\n");
      exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    
    if (file == NULL) { 
      fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
      exit(EXIT_FAILURE);
    }

    /* read line by line */
    while (fgets(line, sizeof(line), file) != NULL) { 
      tokinizer(&TokenNodeHead, line,lineNumber);
    }

    currentNode = TokenNodeHead;
    while (currentNode != NULL) {
      nextNode= currentNode->next;
      free(currentNode->data.value);
      free(currentNode);
      currentNode = nextNode;
    }

    free(instructions);
    fclose(file);
    exit(EXIT_SUCCESS);
}
