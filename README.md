# DynamicArrays
Pequeña biblioteca de arreglos dinamicos e implementación de una cola doblemente terminada, de tal forma que si el tamaño es insuficiente para una inserción esta se reajusta en un factor de 2, y si se elimina un elemento y más de la mitad no se utiliza se reduce la capacidad a la mitad.

## Autór
Enrique Alejandro Giottonini Herrera.
Estructura de Datos.
LCC.

## Descripción
El projecto incluye dos folders:
    - include, para los headers.
    - src, para el código fuente.

Para el arreglo dinámico lo diseñe con macros para que fuera tipe safe en el header DynamicArrays.h
con las operaciones básicas de insertar como verificar si está lleno, vacio, insertar y obtener elemento en una posición. Algunas operaciones auxiliares como copiar de un arreglo a otro o resize el arreglo. No incluí eliminar porque el espacio de memoria es creada en heap con calloc y para la implementación de deques los elementos son inaccesibles cuando no se apuntan a ellos, su valor "basura" es irrelevante. La estructura está construída con atributos de tamaño(capacidad) y de memoria disponible.

Las deques son circulares, dinámicas y de tipo int, estan implementedas con la biblioteca de arreglos dinámicos. Cuando se hace un resize de la memoria, ya sea por falta de espacio o por que sobra espacio, primero se itera la desde la posición del header "front" y las copia a un nuevo arreglo dinámico, por lo que enrealidad no estoy explotando los arreglos dinámicos con esta implementación. La razón de esto es porque me parece más comodo trabajar con listas circulares que estar reordenando los elementos y los headers -front- y -back-. El deque tiene un centinela en la posicion -1 y los headers son valores entre el centinela y el tamaño del deque, para acceder a los elementos lo hago con el método del arreglo dinámico obteniendo el elemento en la posición de los headers.

Están bajo contrato que no se puede/debe eliminar de un deque vacio o insertar en un arreglo lleno.

### Ejecutar el programa
Se utiliza GNU Makefile donde:

    make,
    make all: Genera todas los ejecutables de las pruebas.

    Para las prueba de cada implementación.
    make testDynarr.
    make testDeque.

    Para limpiar los ejecutables:
    make clean.