#ifndef MAIN_H
#define MAIN_H
#define instructions_number 4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>
extern char* TokenLiteral[];
int _iswhitespace(char ch);
void _mallocFailed();

typedef enum TokenType {
  INT,
  PUSH,
  PALL,
  PINT,
  ILLEGAL
} TokenType;

typedef struct Token{
  TokenType tokenType;
  char* value;
  int line_number;
} Token;

typedef struct TokenNode{
  Token data;
  struct TokenNode* next;
} TokenNode;
void appendTokenList(TokenNode** head, Token data);

Token createToken(TokenType tokenType,char* value, int line_number);
void tokinizer(TokenNode** head, char* input,int line_number);
char* readIden(char* input ,size_t* pos);
char* readInt(char* input ,size_t* pos);
Token idenToToken(char* iden,int line_number);
TokenNode* getTokensByLine(TokenNode* head, int line_number);
extern TokenNode* TokenNodeHead;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

instruction_t* getInstructions();
instruction_t* getInstructionByOpcode(instruction_t* instructions, char* opcode);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void freeTokens(TokenNode *head);
void freeStack(stack_t **head);
#endif
