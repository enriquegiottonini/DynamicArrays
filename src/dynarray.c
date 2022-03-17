#include "dynarray.h"

/*  Pre:    none. 
    Post:   */
Dynarray* initializeArray(size_t element_size, size_t init_size)
{
    Dynarray *newDynarr = (Dynarray*)malloc(sizeof(Dynarray));
    void *arr = calloc(init_size * element_size, element_size);
    // free if one is null but no the other...
    if (newDynarr != NULL && arr != NULL) {
        newDynarr->size = init_size;
        newDynarr->avalaible_size = init_size;
        newDynarr->element_size = element_size;
        newDynarr->memory = arr;
    }
    return newDynarr;
}

/*  Pre:    
    Post:    */
bool isEmpty(const Dynarray * dynarr)
{
    return (dynarr->avalaible_size == dynarr->size);
}

/*  Pre:    
    Post:    */
bool isFull(const Dynarray * dynarr)
{
    return (dynarr->avalaible_size > 0);
}

int* getAddressAt(Dynarray *dynarr, int pos)
{
    return dynarr->memory + (pos * dynarr->element_size);
}

int getElementAt(Dynarray *dynarr, int pos)
{
    return *(getAddressAt(dynarr, pos));
}

/*  Pre:    
    Post:    */
int addAt(Dynarray *dynarr, int pos, int element)
{
    if (isFull(dynarr)) {
        // Aumentar?
    }
    memcpy(getAddressAt(dynarr, pos), &element, dynarr->element_size);
    dynarr->avalaible_size--;
    return element;
}

/*  Pre:    
    Post:    */
int deleteAt(Dynarray *dynarr, int pos)
{
    int centinela = 0;
    int element = getElementAt(dynarr, pos);
    memcpy(getAddressAt(dynarr, pos), &centinela, dynarr->element_size);
    dynarr->avalaible_size++;
    return element;
}

void resize(Dynarray *dynarr, size_t factor)
{
    int occupied = dynarr->size - dynarr->avalaible_size;
    void* ok = realloc(dynarr->memory, factor * dynarr->size);
    if (ok != NULL) {
        dynarr->memory = (int *)ok;
        dynarr->size = factor * dynarr->size;
        dynarr->avalaible_size = dynarr->size - occupied;
    }
    
}


void delete(Dynarray *dynarr) 
{
    if (dynarr != NULL) {
        free(dynarr->memory);
        free(dynarr);
    }
}