#include "DoubleEndQueue.h"

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

bool empty()
{
    int n=1;
    DoubleEndedQueue *deque;
    printf("\nfor initializing a deque of size %d", n);
    deque = deque_init(n);
    check(deque != NULL, "Expecting enough memory.");
    printDeque(deque);

    check(deque_empty(deque), "Expecting an empty dynamic array.");
    deque_delete(deque);
    printf("\n");
    return true;

fail:
    if (deque != NULL)
        deque_delete(deque);
    return false;
}

int main(void)
{
    run_test(empty);
    return 0;
}