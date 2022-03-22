# DynamicArrays

Pequeña biblioteca de arreglos dinamicos e implementación de una cola doblemente terminada, de tal forma que si el tamaño es insuficiente para una inserción esta se reajusta en un factor de 2, y si se elimina un elemento y más de la mitad no se utiliza se reduce la capacidad a la mitad.

## Authors
Enrique Alejandro Giottonini Herrera
Estructura de Datos
LCC

## Descripción

### Executing program

Se utiliza GNU Makefile donde:

-testDynarr.o: Genera el ejecutable para las pruebas de los arreglos dinámicos.

-testDynarr: Corre las pruebas de arreglos dinámicos con valgrind.

-cleanDynarr: Elimina el ejectuable de las pruebas de los arreglos dinámicos.


-testDeque.o: Genera el ejecutable para las pruebas de la cola doblemente terminada.

-testDeque: Corre las las pruebas de la cola doblemente terminada con valgrind.

-cleanDeque: Elimina el ejectuable de las pruebas de la cola doblemente terminada.

## License

This project is licensed under the [bbcita bblin]