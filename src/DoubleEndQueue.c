#include "DoubleEndQueue.h"

DECL_DYNARRAY(intDynarray, int)

struct DoubleEndedQueue
{
    int front;
    int back;
    int size;
    intDynarray *memory;
};

DoubleEndedQueue *deque_init(int size)
{
    DoubleEndedQueue *deque = (DoubleEndedQueue *)malloc(sizeof(DoubleEndedQueue));
    if (deque == NULL)
        return NULL;
    deque->memory = intDynarray_new(size);
    if (deque->memory == NULL)
    {
        free(deque);
        return NULL;
    }
    deque->front = 0;
    deque->back = 0;
    deque->size = size;
    return deque;
}

bool deque_empty(DoubleEndedQueue *deque)
{
    return (deque->front == deque->back);
}

bool deque_full(DoubleEndedQueue *deque)
{
    return !(deque_empty(deque));
}

int push_back(DoubleEndedQueue *deque, int element)
{
    if(deque_empty(deque))
        deque->front = (deque->front- 1) % 6;

    insertAt(deque->memory, deque->back, element);
    deque->back = (deque->back + 1) % 6;
    return getElementAt(deque->memory, (deque->back - 1) % 6);
}

int push_front(DoubleEndedQueue *deque, int element)
{
    if(deque_empty(deque))
        deque->back = (deque->back + 1) % 6;

    insertAt(deque->memory, deque->front, element);
    deque->back = (deque->back - 1) % 6;
    return getElementAt(deque->memory, (deque->back + 1) % 6);
}

int pop_back(DoubleEndedQueue *deque)
{
    deque->back = (deque->back - 1) % 6;
    return getElementAt(deque->memory, deque->back);
}

int pop_front(DoubleEndedQueue *deque, int element)
{
    deque->front = (deque->front + 1) % 6;
    return getElementAt(deque->memory, deque->front);
}

int back(DoubleEndedQueue *deque)
{
    return getElementAt(deque->memory, (deque->back - 1) % 6);
}

int front(DoubleEndedQueue *deque)
{
    return getElementAt(deque->memory, (deque->back + 1) % 6);

}

void deque_delete(DoubleEndedQueue *deque)
{
    if(deque != NULL)
    {
        intDynarray_delete(deque->memory);
        free(deque);
    }
}

void printArray(intDynarray *dynarr)
{
    printf("\n( ");
    for (int i = 0; i < dynarr->capacity; i++)
    {
        printf("%d ", *(dynarr->arr + i * sizeof(int)));
    }
    printf(")\n");
}

void printDeque(DoubleEndedQueue *deque)
{
    printArray(deque->memory);
}