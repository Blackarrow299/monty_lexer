#include "monty.h"

Token createToken(TokenType tokenType, char* value,unsigned int line_number) {
  Token token;
  token.tokenType = tokenType;
  token.value = value;
  token.line_number = line_number;
  return token;
}
 
char* readIden(char* input, size_t* pos) {
  char ch = input[*pos];
  int i = 0;
  char* out = (char*)malloc(sizeof(char) * 100);
  if(out == NULL) {
    return NULL;
  }
  /* TODO check if out is null */
  while(ch != '\0' && !_iswhitespace(ch)) {
    out[i] = ch;
    i++;
    (*pos)++; 
    ch = input[*pos];
  }
  out[i] = '\0';
  (*pos)--;
  return out;
}

char* readInt(char* input, size_t* pos){
  /* TODO return null if its not digit when looping  */
  char ch = input[*pos];
  int i = 0;
  char* out = (char*)malloc(sizeof(char) * 10);
  if(out == NULL) {
    return NULL;
  }
  while(ch != '\0' && !_iswhitespace(ch) && isdigit(ch)) {
    out[i] = ch;
    i++;
    (*pos)++;
    ch = input[*pos];
  }
  (*pos)--;
  out[i] = '\0';
  return out;
}

Token idenToToken(char* iden, unsigned int line_number) {
  TokenType tokenType;
  if(strcmp(iden, TokenLiteral[PUSH]) == 0) {
    tokenType = PUSH;
  }else if(strcmp(iden, TokenLiteral[PALL]) == 0) {
    tokenType = PALL;
  }else {
    tokenType = ILLEGAL;
  }
  return createToken(tokenType, iden, line_number);
}

void tokinizer(TokenNode** head,char* input, unsigned int line_number) {
  size_t pos = 0;
  char ch = input[pos];
  
  while (ch != '\0') {
    if(isdigit(ch)) {
      Token token;
      char* n = readInt(input, &pos);
      if(n == NULL) {
        _mallocFailed();
      }
      token = createToken(INT, n, line_number);
      appendTokenList(head, token);
    }else if(isalpha(ch)) {
      Token token;
      char* iden = readIden(input, &pos);
      if(iden == NULL) {
        _mallocFailed();
      }
      token = idenToToken(iden, line_number);
      appendTokenList(head, token);
    }else{
      /* ignore for now */
    }
    pos++;
    ch = input[pos];
  }
}
