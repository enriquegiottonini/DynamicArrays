#ifndef DYNAMICARRAYS_H
#define DYNAMICARRAYS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*  Implementation of a type safe dynamic array using macros.
    typename: intDynarray, doubleDynarray, floatDynarray, etc.
    type: int, double, float, etc.
*/
#define DECL_DYNARRAY(typename, type)                                                        \
                                                                                             \
    typedef struct                                                                           \
    {                                                                                        \
        int capacity, available;                                                             \
        type *arr;                                                                           \
    } typename;                                                                              \
    /* initialize a dynamic array of (type) elements.                                        \
        Pre: size >= 1.                                                                           \
        Post: pointer to a dynamic array, NULL if there is no memory available.              \
             all the elements are set to 0.                                                  \
        O(n)                                                                                 \
    */                                                                                       \
    typename *typename##_new(int size)                                                       \
    {                                                                                        \
        typename *newDynarr = malloc(sizeof(typename));                                      \
        if (newDynarr == NULL)                                                               \
        {                                                                                    \
            return NULL;                                                                     \
        }                                                                                    \
        type *arr = calloc(size * sizeof(type), sizeof(type));                               \
        if (arr == NULL)                                                                     \
        {                                                                                    \
            free(newDynarr);                                                                 \
            return NULL;                                                                     \
        }                                                                                    \
        newDynarr->capacity = size;                                                          \
        newDynarr->available = size;                                                         \
        newDynarr->arr = arr;                                                                \
        return newDynarr;                                                                    \
    }                                                                                        \
    /*                                                                                       \
        Pre: pointer to an initialized, no NULL, dynamic array (valid dynamic array).        \
        Post: returns True if its empty, False otherwise.                                    \
        O(1)                                                                                 \
     */                                                                                      \
    bool isEmpty(const typename *dynarr) { return (dynarr->available == dynarr->capacity); } \
    /*                                                                                       \
       Pre: pointer to an initialized, no NULL, dynamic array (valid dynamic array).         \
       Post: returns True if its full, False otherwise.                                      \
       O(1)                                                                                  \
    */                                                                                       \
    bool isFull(const typename *dynarr) { return (dynarr->available > 0); }                  \
    /*                                                                                       \
        Pre: valid dynamic array, position within the size of dynarray,                       \
            and element at position previously inserted.                                     \
        Post: value of element at that position.                                              \
        O(1)                                                                                  \
    */                                                                                       \
    type getElementAt(const typename *src, int pos)                                          \
    {                                                                                        \
        return *(src->arr + (pos * sizeof(type)));                                           \
    }                                                                                        \
    /*                                                                                       \
       Pre: valid dynamic array, valid position,                                             \
            and element of the same type as defined at initializing the dynamic array.       \
       Post: element from the dynamic array at that position.                                \
       O(1)                                                                                  \
    */                                                                                       \
    type insertAt(typename *dest, int pos, type element)                                     \
    {                                                                                        \
        memcpy(dest->arr + (pos * sizeof(type)), &element, sizeof(type));                    \
        dest->available--;                                                                   \
        return getElementAt(dest, pos);                                                      \
    }                                                                                        \
    /* copy the values of a dynamic array to an other one.                                   \
        Pre: both dynamic arrays are valid, the capacity(size) of the                        \
            destination dynamic array is larger then the capacity of                         \
            the source dyanmic array.                                                        \
        Post: all the elements have been copied from one dynamic array to the other.          \
        O(n)                                                                                  \
    */                                                                                       \
    void copyTo(typename *src, typename *dest)                                               \
    {                                                                                        \
        for (int i = 0; i < src->capacity; i++)                                              \
        {                                                                                    \
            insertAt(dest, i, getElementAt(src, i));                                         \
        }                                                                                    \
        dest->available += src->available; /* The method is also copying elements            \
                                              from the source dynamic array that             \
                                              are set to the initial value of 0.             \
                                              We resize the available capacity               \
                                              accordingly. */                                \
    }                                                                                        \
    /*                                                                                       \
        Pre: valid dynamic array.                                                            \
        Post: all the elements and the dynamic array has been deleted, liberated, vanished.  \
        Unspecified time complexity (?)                                                      \
    */                                                                                       \
    void typename##_delete(typename *dynarr)                                                 \
                                                                                             \
    {                                                                                        \
        if (dynarr != NULL)                                                                  \
        {                                                                                    \
            free(dynarr->arr);                                                               \
            free(dynarr);                                                                    \
        }                                                                                    \
    }                                                                                        \
    /*                                                                                       \
        Pre: a valid dynamic array.                                                          \
        Post: inmutable and persistent first dynamic array, returns a new one                \
              with copy of the elements of the first and a new capacity(size).               \
        O(n)                                                                                 \
    */                                                                                       \
    typename *typename##_resize(typename *dynarr, int factor)                                \
                                                                                             \
    {                                                                                        \
        typename *newDynarr = typename##_new(factor * dynarr->capacity);                     \
        if (newDynarr == NULL)                                                               \
        {                                                                                    \
            return dynarr;                                                                   \
        }                                                                                    \
        copyTo(dynarr, newDynarr);                                                           \
        return newDynarr;                                                                    \
    }                                                                                        \
                                                                                             \
    /*                                                                                       \
       Pre: valid dynamic array.                                                             \
       Post: shows in console a representation of the dynamic array.                         \
       O(n)                                                                                  \
    */                                                                                       \
    void printArray(typename *dynarr)                                                        \
    {                                                                                        \
        printf("\n( ");                                                                      \
        for (int i = 0; i < dynarr->capacity; i++)                                           \
        {                                                                                    \
            printf("%d ", *(dynarr->arr + i * sizeof(type)));                                \
        }                                                                                    \
        printf(")\n");                                                                       \
    }

#endif