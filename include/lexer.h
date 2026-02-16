#ifndef LEXER_H
#define LEXER_H 
#include <stdlib.h>
#include <stdio.h>
#include "token.h"
#include <stdbool.h>

typedef struct {
    char* text;
    int length;
    int index;
} Lexer;

Lexer* lexer_create(char* text, int text_len);

char lexer_get(Lexer* lexer);

bool lexer_advance(Lexer* lexer);

bool lexer_end(Lexer* lexer);

Token* lexer_parse_next_token(Lexer* lexer);

bool lexer_destroy(Lexer* lexer);

#endif //LEXER_H
