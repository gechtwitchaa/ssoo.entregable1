#include <stdio.h>

//ejercicio1 se declara la estructura arrayLenght que tiene tres campos, un array de enteros con capacidad para 10 valores, un entero que almacen el numero de elementos almacenados en el array y un entero que almacena la sumna de los elementos del array  
typedef struct {
    int arrInt[10]; // Array de enteros con capacidad para 10 valores
    int arrSize; // Número de elementos almacenados en el array
    int arrAdd; // Suma de los elementos contenidos en el array
} arrayLength_t;

//ejercio2 se implementa la funcion initArray para iniciar el array y la funcion printArrr para imprimirlo
int initArray(arrayLength_t *arr) {
    if (arr == NULL) return -1;// Verifica si el puntero es NULL
    for (int i = 0; i < 10; i++) {
        arr->arrInt[i] = -1; // Inicia todas las posiciones del array con -1
    }
    arr->arrSize = 0;  // Inicia arrSize con 0
    arr->arrAdd = 0;// Inicializa arrAdd con 0
    return 0;  // Devuelve 0 si no hay errores
}

void printArr(const arrayLength_t *arr) {
    printf("{[");
    for (int i = 0; i < 10; i++) {
        printf("%d", arr->arrInt[i]);// Imprime cada elemento del array
        if (i < 9) printf(", ");
    }
    printf("], %d, %d}\n", arr->arrSize, arr->arrAdd); // Imprime arrSize y arrAdd
}

//ejercicio3 se implementa la funcion addElement para añadir un elemento al array
int addElement(arrayLength_t *arr, int value) {
    if (value < 0 || arr->arrSize >= 10) return -1;// Verifica si el valor es negativo o si el array está lleno
    for (int i = 0; i < 10; i++) {
        if (arr->arrInt[i] == -1) {// Encuentra la primera posición vacía
            arr->arrInt[i] = value; // Añade el valor al array
            arr->arrSize++; // aumenta el tamaño del array
            arr->arrAdd += value;  // Suma el valor total
            return 0;
        }
    }
    return -1; // Devuelve -1 si no se pudo añadir el valor
}

//ejercicio4 se implementa la funcion getArrsize para obtener el tamaño del array
int getArrSize(const arrayLength_t *arr) {
    if (arr == NULL) return -1; // Verifica si el puntero es NULL
    return arr->arrSize;// Devuelve el tamaño del array
}

//ejercicio5 se implementa la funcion getArrrAdd para sumar los elementos del array
int getArrAdd(const arrayLength_t *arr) {
    if (arr == NULL) return -1;  // Verifica si el puntero es NULL
    return arr->arrAdd;  // Devuelve la suma de los elementos del array
}

//ejercio6 se implementa la funion getElenment para conseguir el valor de un elemento en una posicion especifica
int getElement(const arrayLength_t *arr, int position) {
    if (arr == NULL || position < 0 || position >= 10 || arr->arrInt[position] == -1) return -1;// Verifica si hay errores
    return arr->arrInt[position]; // Devuelve el valor en la posición especificada
}

//ejercicio7 se implementa la funcion setElement para actualizar el valor de un elemento en una osicion especifica
int setElement(arrayLength_t *arr, int position, int value) {
    if (arr == NULL || position < 0 || position >= 10 || value < 0 || arr->arrInt[position] == -1) return -1; // Verifica si hay errores
    arr->arrAdd = arr->arrAdd - arr->arrInt[position] + value;// Actualiza la suma total
    arr->arrInt[position] = value;  // Actualiza el valor en la posición especificada
    return 0;
}

//ejercicio8 en este ejercicio se implementa la funcion resetArr
int resetArr(arrayLength_t *arr) {
    return initArray(arr);  // Reinicia el array usando initArray
}

//ejercio10 el obetivo es implementar la funcion main para comprobar el correcto funcionamiento de las funciones anteriores, cumpliendo con los sub-apartados del ejercio 10 (a-h)
int main() {
    arrayLength_t al1, al2;

    // a) Inicia al1 y al2
    if (initArray(&al1) != 0) {
        printf("Error en inicialización de al1\n");
        return -1;
    }
    if (initArray(&al2) != 0) {
        printf("Error en inicialización de al2\n");
        return -1;
    }

    // b) Añadir valores a al1
    for (int i = 0; i < 10; i++) {
        if (addElement(&al1, i * 10) != 0) {
            printf("Error al añadir elemento %d a al1\n", i * 10);
            return -1;
        }
    }

    // c) Mostrar al1
    printArr(&al1);

    // d) Actualiza las posiciones impares de al1
    for (int i = 1; i < 10; i += 2) {
        if (setElement(&al1, i, i) != 0) {
            printf("Error al actualizar elemento en posición %d de al1\n", i);
            return -1;
        }
    }

    // e) Mostrar al1 actualizado
    printArr(&al1);

    // f) Añade posiciones pares de al1 a al2
    for (int i = 0; i < 10; i += 2) {
        if (addElement(&al2, al1.arrInt[i]) != 0) {
            printf("Error al añadir elemento %d de al1 a al2\n", al1.arrInt[i]);
            return -1;
        }
    }

    // g) Añade valores 0 a 4 a al2
    for (int i = 0; i < 5; i++) {
        if (addElement(&al2, i) != 0) {
            printf("Error al añadir elemento %d a al2\n", i);
            return -1;
        }
    }

    // h) Mostrar al2
    printArr(&al2);

    return 0;
}
