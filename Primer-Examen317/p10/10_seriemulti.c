#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 20 // Número de términos en la serie

void *serie(void *arg) {
    int inicio_punt = *((int *)arg);
    int com = inicio_punt + 1;
    int fin = N;

    printf("Proceso %d generando la serie de %d a %d:\n", inicio_punt, com * 2, fin * 2);
    for (int i = com; i <= fin; i++) {
        printf("%d ", i * 2); // Imprimir números pares
    }
    printf("\n");

    pthread_exit(NULL);
}

int main() {
    int M = 4; // Número de vectores (procesadores)
    pthread_t threads_vector[M];
    int inicio_punt2[M];

    for (int i = 0; i < M; i++) {
        inicio_punt2[i] = i;
        pthread_create(&threads_vector[i], NULL, serie, (void *)&inicio_punt2[i]);
    }

    for (int i = 0; i < M; i++) {
        pthread_join(threads_vector[i], NULL);
    }

    return 0;
}
