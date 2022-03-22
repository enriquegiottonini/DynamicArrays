#ifndef DOUBLEENDQUEUE_H
#define DOUBLEENDQUEUE_H

#include "DynamicArrays.h"

typedef struct DoubleEndedQueue DoubleEndedQueue;

/*                                                                                       
    Pre: none.       
    Post: returns a pointer to an initialized deque.                                    
    O(1)                                                                                 
*/
DoubleEndedQueue *deque_init(int size);

/*                                                                                       
    Pre: a valid deque.       
    Post: returns True if its empty, False otherwise.                                     
    O(1)                                                                                 
*/
bool deque_empty(DoubleEndedQueue *deque);

/*                                                                                       
    Pre: a valid deque.        
    Post: returns True if its full, False otherwise.                                     
    O(1)                                                                                 
*/
bool deque_full(DoubleEndedQueue *deque);

/*                                                                                       
    Pre: none.       
    Post: push the element to the back of the deque and returns the element at the back.
          if the deque is empty it will resize the capacity by a factor of 2.                                 
    O(n)                                                                                 
*/
int push_back(DoubleEndedQueue *deque, int element);

/*                                                                                       
    Pre: none.       
    Post: push the element to the front of the deque and returns the element at the back.
          if the deque is empty it will resize the capacity by a factor of 2.                                 
    O(n)                                                                                 
*/
int push_front(DoubleEndedQueue *deque, int element);

/*                                                                                       
    Pre: not an empty deque.       
    Post: pop the element from the back of the deque and returns it.
          if the deque has less than half of the capacity used
          it will resize the capacity by a factor of 1/2.                                 
    O(n)                                                                                 
*/
int pop_back(DoubleEndedQueue *deque);

/*                                                                                       
    Pre: not an empty deque.       
    Post: pop the element from the front of the deque and returns it.
          if the deque has less than half of the capacity used
          it will resize the capacity by a factor of 1/2,.                                 
    O(n)                                                                                 
*/
int pop_front(DoubleEndedQueue *deque, int element);

/*                                                                                      
    Pre: valid deque.     
    Post: returns the element at the back of the deque.                                    
    O(1)                                                                                
*/
int back(DoubleEndedQueue *deque);

/*                                                                                      
    Pre: valid deque.     
    Post: returns the element at the front of the deque.                                    
    O(1)                                                                                
*/
int front(DoubleEndedQueue *deque);

/*                                                                                      
    Pre: a valid deque.       
    Post: deque has been freed from heap memory.                                   
    O(n)                                                                                
*/
void deque_delete(DoubleEndedQueue *deque);

/*  Aux.                                                                                    
    Pre: valid deque.      
    Post: shows in console a representation of the dynamic arrat where the elements
          of the deque are.                                  
    O(1)                                                                                
*/
void printDeque(DoubleEndedQueue *deque);

#endif