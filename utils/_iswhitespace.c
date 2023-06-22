#include "../monty.h"

int _iswhitespace(char ch) {
  if(ch == ' ' || ch == '\t' || ch == '\n') {
    return 1;
  }
  return 0;
}
