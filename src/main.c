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
    Lexer* lexer = read_file(argv[1]);
    printf("%s", lexer->text);
    
    TokenList* tok_list = tokenlist_init();
    tokenlist_build(tok_list, lexer);
    tokenlist_print(tok_list);
     
    lexer_destroy(lexer);
    tokenlist_destroy(tok_list);

    return EXIT_SUCCESS;
   
}
