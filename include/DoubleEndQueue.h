#ifndef DOUBLEENDQUEUE_H
#define DOUBLEENDQUEUE_H

#include "DynamicArrays.h"

typedef struct DoubleEndedQueue DoubleEndedQueue;

DoubleEndedQueue* deque_init(int size);

bool deque_empty(DoubleEndedQueue *deque);

bool deque_full(DoubleEndedQueue *deque);

int push_back(DoubleEndedQueue *deque, int element);

int push_front(DoubleEndedQueue *deque, int element);

int pop_back(DoubleEndedQueue *deque);

int pop_front(DoubleEndedQueue *deque, int element);

int back(DoubleEndedQueue *deque);

int front(DoubleEndedQueue *deque);

void deque_delete(DoubleEndedQueue *deque);

void printDeque(DoubleEndedQueue *deque);
#endif 