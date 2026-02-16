#ifndef TOKEN_H
#define TOKEN_H 
#define TOKEN_NAME(a) #a 
#include <stdbool.h>


//NOTE: dont forget to update token_type_to_string
typedef enum {
    TT_NUM,
    TT_PLUS,
    TT_SUB,
    TT_MUL,
    TT_DIV
} TokenType;

typedef struct {
    TokenType type;
    int value; //TODO: change to size_t
} Token;

Token* token_create(TokenType tok_type, int value);

bool token_destroy(Token* tok);

void token_print(Token* tok); //NOTE: pass by ref

const char* token_type_to_string(TokenType tok_type);

#endif // TOKEN_H
