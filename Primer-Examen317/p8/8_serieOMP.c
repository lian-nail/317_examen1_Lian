#include <stdio.h>
#include <omp.h>

int main() {
    int M = 4; // Número de procesadores
    int N = 20; // Número de términos en la serie

    #pragma omp parallel num_threads(M)
    {
        int Punt = omp_get_thread_num(); // itentificador del hilo
        int com = (N / M) * Punt + 1; 
        int fin = (Punt == M - 1) ? N : (N / M) * (Punt + 1);
        
        // Generar la serie para el hilo actual
        printf("Hilo %d generando la serie de %d a %d:\n", Punt, com, fin);
        for (int i = com; i <= fin; i += 2) {
            printf("%d ", i * 2);
        }
        printf("\n");
    }

    return 0;
}
