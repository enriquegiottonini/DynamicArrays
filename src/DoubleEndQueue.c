#include "DoubleEndedQueue.h"

DECL_DYNARRAY(intDynarray, int)

typedef struct {
    int *head;
    int *tail;
    intDynarray *dynarr;
} DoubleEndedQueue;
