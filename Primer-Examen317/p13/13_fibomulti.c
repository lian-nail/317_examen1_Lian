#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define max_ter_fibo 1000
#define num_procesadores 4 // Número de procesadores

long fibo_vector[max_ter_fibo]; // Arreglo para almacenar la secuencia de Fibonacci

// Función para calcular Fibonacci
void *fibo(void *arg) {
    int inicio_punt = *((int *)arg);
    int com = inicio_punt * (max_ter_fibo / num_procesadores);
    int fin = (inicio_punt + 1) * (max_ter_fibo / num_procesadores);

    fibo_vector[com] = 0;
    fibo_vector[com + 1] = 1;

    for (int i = com + 2; i < fin; i++) {
        fibo_vector[i] = fibo_vector[i - 1] + fibo_vector[i - 2];
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads_vector[num_procesadores];
    int inicio_punt2[num_procesadores];

    for (int i = 0; i < num_procesadores; i++) {
        inicio_punt2[i] = i;
        pthread_create(&threads_vector[i], NULL, fibo, (void *)&inicio_punt2[i]);
    }

    for (int i = 0; i < num_procesadores; i++) {
        pthread_join(threads_vector[i], NULL);
    }

    // Imprimir la secuencia de Fibonacci
    printf("Secuencia de Fibonacci:\n");
    for (int i = 0; i < max_ter_fibo; i++) {
        printf("%ld ", fibo_vector[i]);
    }
    printf("\n");

    return 0;
}
