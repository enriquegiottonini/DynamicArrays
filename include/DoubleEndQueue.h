#ifndef DOUBLEENDQUEUE_H
#define DOUBLEENDQUEUE_H

#include "DynamicArrays.h"

typedef struct DoubleEndedQueue DoubleEndedQueue;

/*                                                                                       
    Pre: pointer to an initialized, no NULL, dynamic array (valid dynamic array).        
    Post: returns True if its full, False otherwise.                                     
    O(1)                                                                                 
*/
DoubleEndedQueue *deque_init(int size);

/*                                                                                       
    Pre: pointer to an initialized, no NULL, dynamic array (valid dynamic array).        
    Post: returns True if its full, False otherwise.                                     
    O(1)                                                                                 
*/
bool deque_empty(DoubleEndedQueue *deque);

/*                                                                                       
    Pre: pointer to an initialized, no NULL, dynamic array (valid dynamic array).        
    Post: returns True if its full, False otherwise.                                     
    O(1)                                                                                 
*/
bool deque_full(DoubleEndedQueue *deque);

/*                                                                                       
    Pre: pointer to an initialized, no NULL, dynamic array (valid dynamic array).        
    Post: returns True if its full, False otherwise.                                     
    O(1)                                                                                 
*/
int push_back(DoubleEndedQueue *deque, int element);

/*                                                                                       
    Pre: pointer to an initialized, no NULL, dynamic array (valid dynamic array).        
    Post: returns True if its full, False otherwise.                                     
    O(1)                                                                                 
*/
int push_front(DoubleEndedQueue *deque, int element);

/*                                                                                       
    Pre: pointer to an initialized, no NULL, dynamic array (valid dynamic array).        
    Post: returns True if its full, False otherwise.                                     
    O(1)                                                                                 
*/
int pop_back(DoubleEndedQueue *deque);

/*                                                                                       
    Pre: pointer to an initialized, no NULL, dynamic array (valid dynamic array).        
    Post: returns True if its full, False otherwise.                                     
    O(1)                                                                                 
*/
int pop_front(DoubleEndedQueue *deque, int element);

/*                                                                                      
    Pre: pointer to an initialized, no NULL, dynamic array (valid dynamic array).       
    Post: returns True if its full, False otherwise.                                    
    O(1)                                                                                
*/
int back(DoubleEndedQueue *deque);

/*                                                                                      
    Pre: pointer to an initialized, no NULL, dynamic array (valid dynamic array).       
    Post: returns True if its full, False otherwise.                                    
    O(1)                                                                                
*/
int front(DoubleEndedQueue *deque);

/*                                                                                      
    Pre: pointer to an initialized, no NULL, dynamic array (valid dynamic array).       
    Post: returns True if its full, False otherwise.                                    
    O(1)                                                                                
*/
void deque_delete(DoubleEndedQueue *deque);

/*                                                                                      
    Pre: pointer to an initialized, no NULL, dynamic array (valid dynamic array).       
    Post: returns True if its full, False otherwise.                                    
    O(1)                                                                                
*/
void printDeque(DoubleEndedQueue *deque);

#endif