#include "../include/util.h"
#include <assert.h>

char* read_file(const char* filename){
    assert(filename != NULL);
    char* fcontent = NULL;
    int fsize = 0;
    FILE* fp;


    fp = fopen(filename, "r");
    if(fp){
        fseek(fp, 0, SEEK_END);
        fsize = ftell(fp);
        rewind(fp);

        fcontent = (char*)malloc(sizeof(char) * fsize);
        assert(fcontent != NULL);

        fread(fcontent, 1, fsize, fp);

        fclose(fp);
    }
    return fcontent;
}


