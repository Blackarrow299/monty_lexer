#include "monty.h"
TokenNode *TokenNodeHead = NULL;

char* TokenLiteral[] = {
  "int",
  "push", 
  "pall",
  "pint"
  "illegal"
};

instruction_t* getInstructions() {
  instruction_t *instructions = malloc(sizeof(instruction_t) * instructions_number);

  instructions[0].opcode = "push";
  instructions[0].f = push;

  instructions[1].opcode = "pall";
  instructions[1].f = pall;

  instructions[2].opcode = "pint";
  instructions[2].f = pint;
  
  return instructions;
}

int main(int argc, char* argv[]) {
    FILE* file;
    char line[1024];
    unsigned int lineNumber = 1; 
    stack_t *stack = NULL;
    instruction_t* instructions = getInstructions();
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
      instruction_t* instruction = NULL;
      TokenNode* tokens = NULL;  

      tokinizer(&TokenNodeHead, line,lineNumber);
      
      tokens = getTokensByLine(TokenNodeHead,lineNumber);
      instruction = getInstructionByOpcode(instructions,tokens->data.value);
      
      if(instruction == NULL) {
         /* theres no instruction TODO handle that */  
        fprintf(stderr, "L%d: unknown instruction %s\n", lineNumber, tokens->data.value);
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
      free(currentNode->data.value);
      free(currentNode);
      currentNode = nextNode;
    }

    free(instructions);
    fclose(file);
    exit(EXIT_SUCCESS);
}
