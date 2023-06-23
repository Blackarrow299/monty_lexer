#ifndef MAIN_H
#define MAIN_H
#define instructions_number 5
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
  unsigned int line_number;
} Token;

typedef struct TokenNode{
  Token data;
  struct TokenNode* next;
} TokenNode;
void appendTokenList(TokenNode** head, Token data);

Token createToken(TokenType tokenType,char* value,unsigned int line_number);
void tokinizer(TokenNode** head, char* input,unsigned int line_number);
char* readIden(char* input ,size_t* pos);
char* readInt(char* input ,size_t* pos);
Token idenToToken(char* iden,unsigned int line_number);
TokenNode* getTokensByLine(TokenNode* head,unsigned int line_number);

extern TokenNode* TokenNodeHead;

void freeStack(stack_t **head);
#endif
