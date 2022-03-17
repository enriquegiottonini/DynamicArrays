//#include "dynarray.h"
#include "dynarray_type_safe.h"

DECL_DYNARRAY(intDynarray, int)

int main(void)
{
    intDynarray *test = intDynarray_new(2);
    printf("Crear un dynarr de tamano: %d", test->available);
    printArray(test);

    insertAt(test, 1, 1);
    printf("a[1]=1, available: %d \n", test->available);
    printArray(test);

    intDynarray *test2 = intDynarray_resize(test, 100);
    printf("resize array to 8, avaible: %d, size: %d \n", test2->available, test2->capacity);
    printArray(test);
    printArray(test2);

    insertAt(test, 7, 44);
    printf("A[7] = 44, available: %d \n", test2->available);
    printArray(test2);

    intDynarray_delete(test);
    intDynarray_delete(test2);
    return 0;
}