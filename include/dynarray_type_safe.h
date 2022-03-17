#ifndef DYNARRAY_TYPE_SAFE_H
#define DYNARRAY_TYPE_SAFE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define DECL_DYNARRAY(typename, type)                                                        \
    /*                                                                                       \
        Pre:                                                                                 \
        Post:                                                                                \
        */                                                                                   \
    typedef struct                                                                           \
    {                                                                                        \
        int capacity, available;                                                             \
        type *arr;                                                                           \
    } typename;                                                                              \
    /*                                                                                       \
       Pre:                                                                                  \
       Post:                                                                                 \
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
        Pre:                                                                                 \
        Post:                                                                                \
     */                                                                                      \
    bool isEmpty(const typename *dynarr) { return (dynarr->available == dynarr->capacity); } \
    /*                                                                                       \
       Pre:                                                                                  \
       Post:                                                                                 \
    */                                                                                       \
    bool isFull(const typename *dynarr) { return (dynarr->available > 0); }                  \
    /*                                                                                       \
       Pre:                                                                                  \
       Post:                                                                                 \
    */                                                                                       \
    type getElementAt(typename *dynarr, int pos)                                             \
    {                                                                                        \
        return *(dynarr->arr + (pos * sizeof(type)));                                        \
    }                                                                                        \
    /*                                                                                       \
       Pre:                                                                                  \
       Post:                                                                                 \
    */ \
    type insertAt(typename *dynarr, int pos, type element)                                   \
    {                                                                                        \
        memcpy(dynarr->arr + (pos * sizeof(type)), &element, sizeof(type));                  \
        dynarr->available--;                                                                 \
        return getElementAt(dynarr, pos);                                                    \
    }                                                                                        \
    /*                                                                                       \
       Pre:                                                                                  \
       Post:                                                                                 \
    */                                                                                       \
    void copyTo(typename *src, typename *dest)                                               \
    {                                                                                        \
        for (int i = 0; i < src->capacity; i++)                                              \
        {                                                                                    \
            insertAt(dest, i, getElementAt(src, i));                                         \
        }                                                                                    \
        dest->available += src->available;                                                   \
    }                                                                                        \
        /*                                                                                       \
       Pre:                                                                                  \
       Post:                                                                                 \
    */  \
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
       Pre:                                                                                  \
       Post:                                                                                 \
    */    \
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
       Pre:                                                                                  \
       Post:                                                                                 \
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