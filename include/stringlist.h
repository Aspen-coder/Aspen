#ifndef STRINGLIST_H
#define STRINGLIST_H
#include <stdbool.h>

typedef struct {
    char* string;
    int capacity;
    int size;
} StringList;

StringList* stringlist_init();

bool stringlist_add(StringList* stringlist, char c);

bool stringlist_add(StringList* stringlist, char* c);

void stringlist_print(StringList* stringlist);

bool stringlist_destroy(StringList* stringlist);

#endif // STRINGLIST_H 
