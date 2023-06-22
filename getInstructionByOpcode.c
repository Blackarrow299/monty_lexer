#include "monty.h"
#include <string.h>

instruction_t* getInstructionByOpcode(instruction_t* instructions, char* opcode) {
  while (instructions->opcode != NULL && instructions != NULL) {
    if (strcmp(instructions->opcode, opcode) == 0) {
      return instructions;
    }
    instructions++;
  }
  return NULL;
}
