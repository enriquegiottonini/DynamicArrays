#include "DynamicArrays.h"

/*
  Cortesía de nuestro querido maestro de Estructura de Datos:
  Prof. Eduardo Acuña.

  Macros para organizar pruebas.

  Las pruebas se escriben con check(expresión, mensaje), una prueba
  pasa cuando la expresión tiene valor verdadero y falla cuando tiene
  valor falso, en cuyo caso se imprime el mensaje como error.

  Las pruebas se agrupan en funciones de cero argumentos que regresan
  un booleano, si alguna de las pruebas falla esta función debe
  regresar falso, si todas pasan debe regresar verdadero.

  Dentro de estas funciones, utiliza una etiqueta fail para
  identificar el código que libera recursos (como la memoria) cuando
  una prueba falla.
 */
#define run_test(test)                             \
    do                                             \
    {                                              \
        fprintf(stderr, "* Testing " #test "..."); \
        bool ok = test();                          \
        if (!ok)                                   \
            return -1;                             \
        fprintf(stderr, "ok\n");                   \
    } while (0)

#define check(expr, message)                             \
    if (!(expr))                                         \
    {                                                    \
        fprintf(stderr, "\nError (%s:%d) " message "\n", \
                __FILE__, __LINE__);                     \
        goto fail;                                       \
    }

/* Test cases for an integer Dynamic Array. */
DECL_DYNARRAY(intDynarray, int)

void printArray(intDynarray *dynarr)
{
    printf("\n( ");
    for (int i = 0; i < dynarr->capacity; i++)
    {
        printf("%d ", *(dynarr->arr + i * sizeof(int)));
    }
    printf(")\n");
}

bool empty()
{
    int n;
    intDynarray *dynarr;
    for (n = 1; n <= 1024; n = 2 * n)
    {
        printf("\nfor initializing a dynamic array of size %d", n);
        dynarr = intDynarray_new(n);
        check(dynarr != NULL, "Expecting enough memory.");
        // printArray(dynarr);
        check(isEmpty(dynarr), "Expecting an empty dynamic array.");
        intDynarray_delete(dynarr);
    }
    printf("\n");
    return true;

fail:
    if (dynarr != NULL)
        intDynarray_delete(dynarr);
    return false;
}

bool insert()
{
    int n;
    intDynarray *dynarr;

    for (n = 1; n <= 1024; n = 2 * n)
    {
        printf("\nfor initializing a dynamic array of size %d", n);
        dynarr = intDynarray_new(n);
        check(dynarr != NULL, "Expecting enough memory.");
        check(isEmpty(dynarr), "Expecting an empty dynamic array.");
        for (int i = 0; i < n; i++)
        {
            check((insertAt(dynarr, i, i) == i), "Expecting to get the element inserted");
        }
        // printArray(dynarr);
        intDynarray_delete(dynarr);
    }
    printf("\n");
    return true;

fail:
    if (dynarr != NULL)
        intDynarray_delete(dynarr);
    return false;
}

bool full()
{
    int n;
    intDynarray *dynarr;

    for (n = 1; n <= 1024; n = 2 * n)
    {
        printf("\nfor a dynamic array of size %d", n);
        dynarr = intDynarray_new(n);
        check(dynarr != NULL, "Expecting enough memory.");
        check(isEmpty(dynarr), "Expecting an empty dynamic array.");

        for (int i = 0; i < n; i++)
        {
            check((insertAt(dynarr, i, i) == i), "Expecting to get the element inserted.");
        }
        check(isFull(dynarr), "Expecting to be full.)");
        intDynarray_delete(dynarr);
    }
    printf("\n");
    return true;

fail:
    if (dynarr != NULL)
        intDynarray_delete(dynarr);
    return false;
}

bool copy()
{
    int n;
    intDynarray *dynarr_1, *dynarr_2;

    for (n = 1; n <= 512; n = 2 * n)
    {
        printf("\nfor a dynamic array 1 of size %d", n);
        dynarr_1 = intDynarray_new(n);
        check(dynarr_1 != NULL, "Expecting enough memory.");
        check(isEmpty(dynarr_1), "Expecting an empty dynamic array.");

        printf("\n  and a dynamic array 2 of size %d", 2 * n);
        dynarr_2 = intDynarray_new(2 * n);
        check(dynarr_2 != NULL, "Expecting enough memory.");
        check(isEmpty(dynarr_2), "Expecting an empty dynamic array.");

        for (int i = 0; i < n; i++)
        {
            check((insertAt(dynarr_1, i, i) == i), "Expecting to get the element inserted.");
        }
        copyTo(dynarr_1, dynarr_2);
        int n_1 = getElementAt(dynarr_1, n - 1);
        int n_2 = getElementAt(dynarr_2, n - 1);
        check((n_1 == n_2), "Expecting to have the same element at position n.");
        intDynarray_delete(dynarr_1);
        intDynarray_delete(dynarr_2);
    }
    printf("\n");
    return true;

fail:
    if (dynarr_1 != NULL)
        intDynarray_delete(dynarr_1);
    if (dynarr_2 != NULL)
        intDynarray_delete(dynarr_2);
    return false;
}

bool resize()
{
    int n;
    intDynarray *dynarr_1, *dynarr_2;

    for (int factor = 2; factor <= 10; factor++)
    {
        for (n = 1; n <= 8; n = 2 * n)
        {
            printf("\nfor a dynamic array 1 of size %d", n);
            dynarr_1 = intDynarray_new(n);
            check(dynarr_1 != NULL, "Expecting enough memory.");
            check(isEmpty(dynarr_1), "Expecting an empty dynamic array.");

            for (int i = 0; i < n; i++)
            {
                check((insertAt(dynarr_1, i, i) == i), "Expecting to get the element inserted.");
            }

            printf("\n  a factor of %d and a dynamic array 2 of size %d", factor, factor * n);
            dynarr_2 = intDynarray_resize(dynarr_1, factor);
            check(dynarr_2 != dynarr_1, "Expecting enough memory.");

            int n_1 = getElementAt(dynarr_1, n - 1);
            int n_2 = getElementAt(dynarr_2, n - 1);
            check((n_1 == n_2), "Expecting to have the same element at position n.");

            int size_1 = dynarr_1->capacity;
            int size_2 = dynarr_2->capacity;
            check((size_2 == factor * size_1), "Expecting the size to be the greater by a factor.");

            intDynarray_delete(dynarr_1);
            intDynarray_delete(dynarr_2);
        }
    }
    printf("\n");
    return true;

fail:
    if (dynarr_1 != NULL)
        intDynarray_delete(dynarr_1);
    if (dynarr_2 != NULL)
        intDynarray_delete(dynarr_2);
    return false;
}

int main(void)
{
    run_test(empty);
    run_test(insert);
    run_test(full);
    run_test(copy);
    run_test(resize);
    return 0;
}