#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdbool.h>

char *inputBuffer;

typedef struct Token {
  size_t size;
  char *token;
  bool isSpace;
} Token;

struct Token tokens[4];

int parse(char *buffer) {
  size_t numOfTokens;
  char *tok = strtok(buffer, " ");
  while (tok != NULL) {
    printf("%s\n", tok);
    Token token;
    token.size = sizeof(tok);
    token.token = tok;
    token.isSpace = strcmp(tok, " ") ? true : false;

    tokens[numOfTokens] = token;

    tok = strtok(NULL, " ");

    numOfTokens++;
  }

  return numOfTokens;
}

int repl_loop() {
  size_t capacity = 0;
  inputBuffer = malloc(capacity);

  while (1) {
    printf("> ");
    size_t len = getline(&inputBuffer, &capacity, stdin);
    printf("%s\n", inputBuffer);
    parse(inputBuffer);
    for (int i = 0; i < 4; i++) {
      printf("token found: %s\n", tokens[i].token);
    }
  }
}

int main() { repl_loop(); }
