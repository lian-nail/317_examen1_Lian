#include <iostream>
#include <mpi.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rango, tam;
    MPI_Comm_rank(MPI_COMM_WORLD, &rango);
    MPI_Comm_size(MPI_COMM_WORLD, &tam);

    const int puntos = 1000000;
    int puntosDentro = 0;

    // Semilla diferente para cada proceso
    srand(time(NULL) + rango);

    for (int i = 0; i < puntos / tam; ++i) {
        double x = (double) rand() / RAND_MAX;
        double y = (double) rand() / RAND_MAX;

        if (x * x + y * y <= 1.0) {
            puntosDentro++;
        }
    }

    // Sumamos el número de puntos dentro del círculo de todos los procesos
    int puntosExt;
    MPI_Reduce(&puntosDentro, &puntosExt, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rango == 0) {
        double pi = 4.0 * puntosExt / puntos;
        cout << "Valor estimado de pi: " << pi << endl;
    }

    MPI_Finalize();
    return 0;
}
