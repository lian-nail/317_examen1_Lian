#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rango, tam;
    int N = 30;

    MPI_Init(&argc, &argv);
    MPI_Comm_rango(MPI_COMM_WORLD, &rango);
    MPI_Comm_tam(MPI_COMM_WORLD, &tam);

    int proc = N / tam;
    int com = rango * proc + 1;
    int fin = com + proc - 1;

    // Ajuste para el último proceso si N no es divisible por tam
    if (rango == tam - 1) {
        fin = N;
    }

    printf("Proceso %d generando la serie de %d a %d:\n", rango, com * 2, fin * 2);
    for (int i = com; i <= fin; i++) {
        printf("%d ", i * 2); // Imprimir números pares
    }
    printf("\n");

    MPI_Finalize();
    return 0;
}
