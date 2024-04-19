#include <stdio.h>

int main() {
    printf("Hola Mundo\n");
    return 0;
}


// #include <stdio.h>

// // Definición de una macro para imprimir caracteres
// #define PRINT_CHAR(c) putchar(c)

// // Definición de una macro para imprimir una cadena
// #define PRINT_STRING(s) do { const char *p = s; while (*p) PRINT_CHAR(*p++); } while (0)

// // Definición de una macro para imprimir "Hola"
// #define PRINT_HOLA() PRINT_STRING("\x48\x6f\x6c\x61")

// // Definición de una macro para imprimir "Mundo"
// #define PRINT_MUNDO() PRINT_STRING("\x4d\x75\x6e\x64\x6f")

// // Función principal
// int main() {
//     // Definición de un puntero a función
//     typedef void (*PrinterFunc)();

//     // Arreglo de punteros a funciones
//     PrinterFunc printers[] = { PRINT_HOLA, PRINT_MUNDO };

//     // Recorremos el arreglo e invocamos cada función
//     for (int i = 0; i < sizeof(printers) / sizeof(printers[0]); ++i) {
//         printers[i]();
//         PRINT_CHAR(' ');
//     }

//     PRINT_CHAR('\n'); // Imprimir un salto de línea al final
//     return 0;
// }
