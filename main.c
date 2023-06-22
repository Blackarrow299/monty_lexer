#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
TokenNode *TokenNodeHead = NULL;

char* TokenLiteral[] = {
  "int",
  "push", 
  "pall",
  "illegal"
};

instruction_t* getInstructions() {
  instruction_t *instructions = malloc(sizeof(instruction_t) * instructions_number);

  instructions[0].opcode = "push";
  instructions[0].f = push;

  instructions[1].opcode = "pall";
  instructions[1].f = pall;
  
  return instructions;
}

int main(int argc, char* argv[]) {
    FILE* file;
    char line[256];
    int lineNumber = 1; 
    stack_t *stack = NULL;
    instruction_t* instructions = getInstructions();
    TokenNode* currentNode = NULL;
    TokenNode* nextNode;

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
      instruction_t* instruction = NULL;
      TokenNode* tokens = NULL;  

      tokinizer(&TokenNodeHead, line,lineNumber);
      
      tokens = getTokensByLine(TokenNodeHead,lineNumber);
      instruction = getInstructionByOpcode(instructions,tokens->data.value);
      
      if(instruction == NULL) {
         /* theres no instruction TODO handle that */ 
        printf("L%i: unknown instruction %s \n", lineNumber, tokens->data.value);
        exit(EXIT_FAILURE);
      }else {
        instruction->f(&stack , lineNumber);
      }
      freeTokens(tokens);
      lineNumber++;
    }

    freeStack(&stack);
    currentNode = TokenNodeHead;
    while (currentNode != NULL) {
      nextNode= currentNode->next;
     /* printf("line[%i] : %s -> %s \n",currentNode->data.line_number ,TokenLiteral[currentNode->data.tokenType], currentNode->data.value); */
      free(currentNode->data.value);
      free(currentNode);
      currentNode = nextNode;
    }

    free(instructions);
    fclose(file);
    return (EXIT_SUCCESS);
}
