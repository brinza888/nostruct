#ifndef __CVOID_MAGIC_H
#define __CVOID_MAGIC_H

#include <stdlib.h>


typedef void* var;
typedef var pair[2];
typedef pair* object;


#define DECL_STRUCT(NAME, COUNT)\
    object NAME() {\
        object st = calloc(sizeof(var), 2 * (COUNT + 1));\
        st[0][0] = calloc(sizeof(size_t), 1);\
        *((size_t*)st[0][0]) = COUNT;\
        size_t i = 1;


#define FIELD(NAME, TYPE, N)\
        st[i][0] = calloc(sizeof(NAME), 1);\
        strcpy((char*)st[i][0], NAME);\
        st[i][1] = calloc(sizeof(TYPE), N);\
        i += 1;


#define END_STRUCT()\
        return st;\
    }


var get(const object st, const char* name) {
    for (size_t i = 1; i <= *((size_t*)st[0][0]); i++) {
        if (strcmp(name, st[i][0]) == 0) {
            return st[i][1];
        }
    }
    return NULL;
}

void del(object st) {
    for (size_t i = 1; i <= *((size_t*)st[0][0]); i++) {
        if (st[i][1] != NULL)
            free(st[i][1]);
        if (st[i][0] != NULL)
            free(st[i][0]);
    }
    free(st[0][0]);
    free(st);
}


#define Sp(NAME, FIELD, TYPE) ((TYPE*)get(NAME, FIELD))
#define S(NAME, FIELD, TYPE) (*(TYPE*)get(NAME, FIELD))


#endif