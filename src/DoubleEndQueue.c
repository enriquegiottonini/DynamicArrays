#include "DoubleEndQueue.h"

DECL_DYNARRAY(intDynarray, int)

struct DoubleEndedQueue
{
    int front;
    int back;
    int num_elements;
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
    deque->front = -1;
    deque->back = -1;
    deque->num_elements = 0;
    deque->size = size;
    return deque;
}

bool deque_empty(DoubleEndedQueue *deque)
{
    return (deque->front == -1 && deque->back == -1);
}

bool deque_full(DoubleEndedQueue *deque)
{
    return (deque->num_elements == deque->size);
}

void copyToNewDeque(DoubleEndedQueue *deque, float factor)
{
    // Preparing to move elements to a larger array;
    intDynarray *new_memory = intDynarray_new((int)(deque->memory->capacity * factor));
    if (new_memory == NULL)
        return;

    // Copy the elements
    int target = deque->front;
    int dest = 0;
    while (target != deque->back)
    {
        insertAt(new_memory, dest, getElementAt(deque->memory, target));
        target = (target + 1) % deque->size;
        dest++;
    }
    insertAt(new_memory, dest, getElementAt(deque->memory, target));

    deque->front = 0;
    deque->back = deque->num_elements - 1;

    deque->size = (int)(deque->size * factor);

    intDynarray_delete(deque->memory);
    deque->memory = new_memory;
}

int push_back(DoubleEndedQueue *deque, int element)
{
    if (deque_full(deque))
    {
        copyToNewDeque(deque, 2);
    }
    else if (deque_empty(deque))
    {
        deque->front = 0;
        deque->back = 0;
        deque->num_elements++;
        insertAt(deque->memory, deque->back, element);
        return getElementAt(deque->memory, deque->back);
    }

    deque->back = (deque->back + 1) % deque->size;
    deque->num_elements++;
    insertAt(deque->memory, deque->back, element);
    return getElementAt(deque->memory, deque->back);
}

int push_front(DoubleEndedQueue *deque, int element)
{
    if (deque_full(deque))
    {
        copyToNewDeque(deque, 2);
    }
    else if (deque_empty(deque))
    {
        deque->front = 0;
        deque->back = 0;
        deque->num_elements++;
        insertAt(deque->memory, deque->front, element);
        return getElementAt(deque->memory, deque->front);
    }
    deque->front = (deque->front - 1 + deque->size) % deque->size;
    deque->num_elements++;
    insertAt(deque->memory, deque->front, element);
    return getElementAt(deque->memory, deque->front);
}

int pop_back(DoubleEndedQueue *deque)
{
    int temp = getElementAt(deque->memory, deque->back);

    // One element
    if (deque->front == deque->back)
    {
        deque->front = -1;
        deque->back = -1;
    }
    else
        deque->back = (deque->back - 1 + deque->size) % deque->size;

    deque->num_elements--;
    if (deque->num_elements < deque->size / 2)
    {
       copyToNewDeque(deque, 0.5);
    }
    return temp;
}

int pop_front(DoubleEndedQueue *deque, int element)
{
    int temp = getElementAt(deque->memory, deque->front);
    
    // One element
    if (deque->front == deque->back)
    {
        deque->front = -1;
        deque->back = -1;
    }
    else
        deque->front = (deque->back + 1) % deque->size;

    deque->num_elements--;
    if (deque->num_elements < deque->size / 2)
    {
        copyToNewDeque(deque, 0.5);
    }
    return temp;
}

int back(DoubleEndedQueue *deque)
{
    return getElementAt(deque->memory, deque->back);
}

int front(DoubleEndedQueue *deque)
{
    return getElementAt(deque->memory, deque->front);
}

void deque_delete(DoubleEndedQueue *deque)
{
    if (deque != NULL)
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