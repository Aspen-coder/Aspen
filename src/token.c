#include "../include/token.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

Token* token_create(TokenType tok_type, int value){
    Token* tok = (Token*)malloc(sizeof(Token));
    assert(tok != NULL);

    tok->type = tok_type;
    tok->value = value;
    return tok;
}

bool token_destroy(Token* tok){
    free(tok);
    return true;
}

void token_print(Token* tok){ //NOTE: pass by ref
    printf("[TOK TYPE = %s, VALUE = %d]\n", token_type_to_string(tok->type), tok->value);
}


const char* token_type_to_string(TokenType tok_type){
    switch(tok_type){
        case TT_NUM:
            return "TT_NUM";
        case TT_PLUS:
            return "TT_PLUS";
        case TT_SUB:
            return "TT_SUB";
        case TT_MUL:
            return "TT_MUL";
        case TT_DIV:
            return "TT_DIV";
        default:
            return "Unidentified Token Type";
    }
}
