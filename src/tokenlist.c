#include "../include/tokenlist.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


TokenList* tokenlist_init(){
    TokenList* tok_list = (TokenList*)malloc(sizeof(TokenList));
    assert(tok_list != NULL);
    tok_list->size = 0; tok_list->capacity = 1;
    tok_list->tokens = (Token**)malloc(sizeof(Token*));
    assert(tok_list->tokens != NULL);

    return tok_list;
}

TokenList* tokenlist_build(char* text){
    TokenList* tok_list = tokenlist_init();
    return tok_list; 
}

bool tokenlist_add(TokenList* tokenlist, Token* token){
    assert(tokenlist != NULL && token != NULL);
    if(tokenlist->size == tokenlist->capacity){
        tokenlist->capacity <<= 1;
        tokenlist->tokens = realloc(tokenlist->tokens, tokenlist->capacity *
                sizeof(Token*));
        assert(tokenlist->tokens != NULL);
    }
    tokenlist->tokens[tokenlist->size++] = token;
    return true;
}

bool tokenlist_destroy(TokenList* tokenlist){
    assert(tokenlist != NULL);
    for(size_t i = 0; i < tokenlist->size; i++){
        token_destroy(tokenlist->tokens[i]);
    }
    free(tokenlist);
    return true;
}

void tokenlist_print(TokenList* tokenlist){
    printf("-----PRINTING TOKEN LIST-----\n");
    for(size_t i = 0; i < tokenlist->size; i++){
        token_print(tokenlist->tokens[i]);
    }
    printf("-----END-----\n");
}
