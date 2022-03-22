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
    int n=5;
    DoubleEndedQueue *deque;
    printf("\nfor initializing a deque of size %d", n);
    deque = deque_init(n);
    check(deque != NULL, "Expecting enough memory.");
    printDeque(deque);

    check(deque_empty(deque), "Expecting an empty deque.");
    deque_delete(deque);
    printf("\n");
    return true;

fail:
    if (deque != NULL)
        deque_delete(deque);
    return false;
}

bool full()
{
    int n=5;
    DoubleEndedQueue *deque;
    printf("\nfor initializing a deque of size %d", n);
    deque = deque_init(n);
    check(deque != NULL, "Expecting enough memory.");
    printDeque(deque);
    check(deque_empty(deque), "Expecting an empty deque.");

    printf("Fill deque from the back");
    for (int i=1; i<=n; i++)
    {
        push_back(deque, 3);
        printDeque(deque);
    }
    check(deque_full(deque), "Expecting deque to be full.");

    printf("Pop deque from the back");
    for (int i=1; i<=n; i++)
    {
        check((pop_back(deque) == 3), "Expecting to pop the back.");
        printDeque(deque);
    }
    check(deque_empty(deque), "Expecting to have emptied the deque.");
    printDeque(deque);
  
    printf("Fill deque from the front");
    for (int i=1; i<=n; i++) 
    {
        push_front(deque, 7);
        printDeque(deque);
    }

    printf("Pop deque from the front");
    for (int i=1; i<=n; i++)
    {
        check((pop_back(deque) == 7), "Expecting to pop the back.");
    }
    check(deque_empty(deque), "Expecting to have emptied the deque.");
    printDeque(deque);

    deque_delete(deque);
    printf("\n");
    return true;

fail:
    if (deque != NULL)
        deque_delete(deque);
    return false;
}

bool resize()
{
    int n=5;
    DoubleEndedQueue *deque;
    printf("\nfor initializing a deque of size %d", n);
    deque = deque_init(n);
    check(deque != NULL, "Expecting enough memory.");
    printDeque(deque);
    check(deque_empty(deque), "Expecting an empty deque.");

    printf("Fill deque from the back");
    for (int i=1; i<=n; i++) 
    {
        push_back(deque, i);
        printDeque(deque);
    }
    check(deque_full(deque), "Expecting deque to be full.");

    // Add one more element from the back 
    push_back(deque, 6);
    check(!deque_full(deque), "Expecting deque to not be full, since there is a resize."); 
    printDeque(deque);

    printf("Fill deque from the front");
    for (int i=1; i<=n; i++) 
    {
        push_front(deque, 7);
        printDeque(deque); 
    } 
     
    printf("Delete three arguments and expect resize"); 
    check((pop_back(deque) == 6), "Expecting to pop the back."); 
    check((pop_back(deque) == 5), "Expecting to pop the back.");
    check((pop_back(deque) == 4), "Expecting to pop the back.");
    printDeque(deque);

    printf("Insert three arguments and expect resize");
    push_front(deque, 8);
    push_front(deque, 5);
    push_back(deque, 5);
    check((back(deque) == 5), "Expecting to pop the back.");
    check((front(deque) == 5), "Expecting to pop the back.");
    printDeque(deque);

    deque_delete(deque);
    return true;
 
fail:
    if (deque != NULL)
        deque_delete(deque);
    return false;
}

int main(void)
{
    run_test(empty);
    run_test(full);
    run_test(resize);
    return 0;
}