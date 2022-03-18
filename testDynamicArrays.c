#include "DynamicArrays.h"

/*
  Cortesía de nuestro querido maestro de Estructura de Datos:
  Prof. Eduardo Acuñá.

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

bool empty()
{
    int n;
    intDynarray *dynarr;
    for (n = 1; n<=1024; n = n*2)
    {
        printf("\nfor initializing a dynamic array of size %d", n);
        dynarr = intDynarray_new(n);
        check(dynarr != NULL, "Expecting enough memory.");
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
/*
bool append() {
    list l = make_list();
    check(l != NULL, "Expecting enough memory");

    check(list_append(l, 4) == 0, "Expecting successful append 4");
    check(list_key(l) == 4, "Expecting first element with key 4");
    check(list_append(l, 3) == 0, "Expecting successful append 3");
    check(list_key(list_rest(l)) == 3, "Expecting second element with key 3");
    check(list_append(l, 2) == 0, "Expecting successful append 2");
    check(list_key(list_rest(list_rest(l))) == 2, "Expecting third element with key 2");

    check(list_key(l) == 4, "Expecting the same first element");
    check(list_key(list_rest(l)) == 3, "Expecting the same second element");

    check(free_list(l) == 3, "Expecting 4 deleted elements");
    return true;

 fail:
    if (l != NULL) free_list(l);
    return false;
}

bool remove_good() {
    list l = make_list();
    check(l != NULL, "Expecting enough memory");

    for (int i = 1; i <= 8; i++)
        list_append(l, i);

    check(list_remove(l, 7) == 0, "Expecting successful removal of last element");
    check(list_remove(l, 0) == 0, "Expecting successful removal of first element");
    check(list_remove(l, 2) == 0, "Expecting successful removal of middle element");

    check(list_key(l) == 2, "Expecting first element 2");
    check(list_key(list_rest(l)) == 3, "Expecting second element 3");
    check(list_key(list_rest(list_rest(l))) == 5, "Expecting third element 5");
    check(list_key(list_rest(list_rest(list_rest(l)))) == 6, "Expecting fourth element 6");
    check(list_key(list_rest(list_rest(list_rest(list_rest(l))))) == 7, "Expecting fifth element 7");

    check(free_list(l) == 5, "Expecting 5 deleted elements");
    return true;

 fail:
    if (l != NULL) free_list(l);
    return false;
}

bool remove_bad() {
    list l = make_list();
    check(l != NULL, "Expecting enough memory");

    check(list_remove(l, 0) == 1, "Expecting empty list error");
    check(list_remove(l, 666) == 1, "Expecting empty list error");

    for (int i = 1; i <= 8; i++)
        list_append(l, i);

    check(list_remove(l, -20) == 2, "Expecting out of bounds error with position -20");
    check(list_remove(l, -1) == 2, "Expecting out of bounds error with position -1");

    check(list_remove(l, 20) == 2, "Expecting out of bounds error with position 20");
    check(list_remove(l, 8) == 2, "Expecting out of bounds error with position 8");

    check(free_list(l) == 8, "Expecting 8 deleted elements");
    return true;

 fail:
    if (l != NULL) free_list(l);
    return false;
}

bool insert_good() {
    list l = make_list();
    check(l != NULL, "Expecting enough memory");

    check(list_insert(l, 24, 0) == 0, "Expecting successful insertion into empty list");
    check(list_insert(l, 32, 1) == 0, "Expecting successful insertion of last element into non-empty list");
    check(list_insert(l, 12, 0) == 0, "Expecting successful insertion of first element into non-empty list");
    check(list_insert(l, 5, 2) == 0, "Expecting successful insertion of middle element into non-empty list");

    check(list_key(l) == 12, "Expecting first element 12");
    check(list_key(list_rest(l)) == 24, "Expecting second element 24");
    check(list_key(list_rest(list_rest(l))) == 5, "Expecting third element 5");
    check(list_key(list_rest(list_rest(list_rest(l)))) == 32, "Expecting fourth element 32");

    check(free_list(l) == 4, "Expecting 4 deleted elements");
    return true;

 fail:
    if (l != NULL) free_list(l);
    return false;
}

bool insert_bad() {
    list l = make_list();
    check(l != NULL, "Expecting enough memory");

    check(list_insert(l, 666, -10) == 1, "Expecting out of bounds error with position -10 (empty list)");
    check(list_insert(l, 666, -1) == 1, "Expecting out of bounds error with position -1 (empty list)");

    check(list_insert(l, 666, 10) == 1, "Expecting out of bounds error with position 10 (empty list)");
    check(list_insert(l, 666, 1) == 1, "Expecting out of bounds error with position 1 (empty list)");

    for (int i = 1; i <= 8; i++)
        list_append(l, i);

    check(list_insert(l, 666, -10) == 1, "Expecting out of bounds error with position -10 (non-empty list)");
    check(list_insert(l, 666, -1) == 1, "Expecting out of bounds error with position -1 (non-empty list)");

    check(list_insert(l, 666, 20) == 1, "Expecting out of bounds error with position 20 (non-empty list)");
    check(list_insert(l, 666, 9) == 1, "Expecting out of bounds error with position 9 (non-empty list)");

    check(free_list(l) == 8, "Expecting 8 deleted elements");
    return true;

 fail:
    if (l != NULL) free_list(l);
    return false;
}

bool reverse() {
    list l = make_list();
    check(l != NULL, "Expecting enough memory");

    check(list_reverse(l) == 0, "Expecting successful reverse for empty list");
    check(list_empty(l), "Expecting correct reversal of empty list");

    list_append(l, 5);
    check(list_reverse(l) == 0, "Expecting successful reverse for singleton list");
    check(list_key(l) == 5, "Expecting first element 5");

    list_append(l, 4);
    check(list_reverse(l) == 0, "Expecting successful reverse of list with two elements");
    check(list_key(l) == 4, "Expecting first element 4");
    check(list_key(list_rest(l)) == 5, "Expecting second element 5");

    list_append(l, 6);
    check(list_reverse(l) == 0, "Expecting successful reverse of list with three elements");
    check(list_key(l) == 6, "Expecting first element 6");
    check(list_key(list_rest(l)) == 5, "Expecting second element 5");
    check(list_key(list_rest(list_rest(l))) == 4, "Expecting third element 4");

    list_append(l, 3);
    check(list_reverse(l) == 0, "Expecting successful reverse of list with three elements");
    check(list_key(l) == 3, "Expecting first element 3");
    check(list_key(list_rest(l)) == 4, "Expecting second element 4");
    check(list_key(list_rest(list_rest(l))) == 5, "Expecting third element 5");
    check(list_key(list_rest(list_rest(list_rest(l)))) == 6, "Expecting fourth element 6");

    check(free_list(l) == 4, "Expecting 4 deleted elements");
    return true;

 fail:
    if (l != NULL) free_list(l);
    return false;
} */

int main(void)
{
    run_test(empty);
    
    return 0;
}