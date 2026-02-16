#ifndef TOKENLIST_H
#define TOKENLIST_H
#include "token.h"
#include <stdlib.h>
#include "lexer.h"

typedef struct {
    Token** tokens;
    size_t size;
    size_t capacity;
} TokenList;

TokenList* tokenlist_init();

TokenList* tokenlist_build(TokenList* tokenlist, Lexer* lexer);

bool tokenlist_add(TokenList* tokenlist, Token* token);

bool tokenlist_destroy(TokenList* tokenlist);

void tokenlist_print(TokenList* tokenlist);

#endif // TOKENLIST_H 
