#include <stdio.h>
#include <errno.h>
#include "../include/tokenlist.h"
#include "../include/util.h"
int main(int argc, char** argv){
    
    if(argc < 2){
        //TODO: figure out why its always printing success 
        perror("Must pass file path as argument");
        return EXIT_FAILURE;
    }
    char* contents = read_file(argv[1]);
    printf("%s", contents);
    
    TokenList* tok_list = tokenlist_init();
    Token* tok = token_create(TT_NUM, 3);
    Token* tok2 = token_create(TT_NUM, 5);
    Token* tok3 = token_create(TT_PLUS, -1);

    tokenlist_add(tok_list, tok);
    tokenlist_add(tok_list, tok2);
    tokenlist_add(tok_list, tok3);
    tokenlist_print(tok_list);
     
    free(contents);
    tokenlist_destroy(tok_list);

    return EXIT_SUCCESS;
   
}
