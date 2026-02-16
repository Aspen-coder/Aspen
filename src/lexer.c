#include "../include/lexer.h"
#include <assert.h>
#include <ctype.h>
//TODO: add redundancy checks


Lexer* lexer_create(char* text, int text_len){
    Lexer* lex = (Lexer*)malloc(sizeof(Lexer));
    assert(lex != NULL);
    lex->text = text;
    lex->length = text_len;
    lex->index = 0;
    return lex;
}

char lexer_get(Lexer* lexer){
    assert(lexer->index < lexer->length);
    return lexer->text[lexer->index];
}

bool lexer_advance(Lexer* lexer){
    lexer->index++;
    if(lexer->index >= lexer->length)
        return false;
    return true; 
}

bool lexer_end(Lexer* lexer){return lexer->index >= lexer->length;}

//NOTE: the real big function
Token* lexer_parse_next_token(Lexer* lexer){
    assert(lexer != NULL);
    if(lexer_end(lexer)){
        printf("[LEXER]: At end, cannot parse next token\n");
        return NULL;
    }
    
    char c = lexer_get(lexer);
    
    while(c == ' ' || c == '\n' || c == '\0'){
        lexer_advance(lexer);
        if(lexer_end(lexer)){
            return NULL;
        }
        c = lexer_get(lexer);
    }

    if(c == '+'){
        lexer_advance(lexer);
        return token_create(TT_PLUS, -1);
    }
    else if(c == '-'){
        lexer_advance(lexer);
        return token_create(TT_SUB, -1);
    }
    else if(c == '*'){
        lexer_advance(lexer);
        return token_create(TT_MUL, -1);
    }
    else if(c == '/'){
        lexer_advance(lexer);
        return token_create(TT_DIV, -1);
    }
    else if(isdigit(c)){
        size_t res = 0;
        while(!lexer_end(lexer) && isdigit(c)){
            res *= 10;
            res += (c - '0');
            lexer_advance(lexer);
            c = lexer_get(lexer);
        }
        return token_create(TT_NUM, res);
    }
    else{
        perror("[LEXER]: parsing invalid token");
        return NULL;
    }
}

bool lexer_destroy(Lexer* lexer){
    free(lexer);
    return true;
}

