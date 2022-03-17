#ifndef DYNARRAY_H
#define DYNARRAY

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    size_t size;
    size_t avalaible_size;
    size_t element_size;
    int *memory;

} Dynarray;

/*  Pre:    
    Post:    */
bool isEmpty(const Dynarray *);

/*  Pre:    
    Post:    */
bool isFull(const Dynarray *);

int* getAddressAt(Dynarray *, int);

int getElementAt(Dynarray *, int);

/*  Pre:    none. 
    Post:   */
Dynarray* initializeArray(size_t, size_t);

/*  Pre:    
    Post:    */
int addAt(Dynarray *, int, int);

/*  Pre:    
    Post:    */
int deleteAt(Dynarray *, int);

void resize(Dynarray *dynarr, size_t factor);

void delete(Dynarray *);

#endif