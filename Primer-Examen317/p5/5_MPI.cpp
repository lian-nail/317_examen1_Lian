#include <mpi.h>
#include <iostream>
#include <vector>

using namespace std;

void multiplicacion(const vector<vector<int>>& matriz, const vector<int>& vec, vector<int>& res) {
    int tam = vec.size();
    res.resize(tam, 0);

    for (int i = 0; i < tam; ++i) {
        for (int j = 0; j < tam; ++j) {
            res[i] += matriz[i][j] * vec[j];
        }
    }
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rango, tam;
    MPI_Comm_rank(MPI_COMM_WORLD, &rango);
    MPI_Comm_size(MPI_COMM_WORLD, &tam);

    const int N = 4;

    vector<vector<int>> matriz(N, vector<int>(N));
    vector<int> vec(N);
    vector<int> localres(N);

    if (rango == 0) {
        //Iniciar la matriz y vector
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                matriz[i][j] = i * N + j; 
            }
            vec[i] = i + 1; 
        }
    }

    MPI_Bcast(vec.data(), N, MPI_INT, 0, MPI_COMM_WORLD);

    vector<int> localMatriz(N * (N / tam));
    MPI_Scatter(matriz.data(), N * (N / tam), MPI_INT, localMatriz.data(), N * (N / tam), MPI_INT, 0, MPI_COMM_WORLD);

    multiplicacion(vector<vector<int>>(N / tam, vector<int>(N, 0)), vec, localres);

    vector<int> res(N);
    MPI_Gather(localres.data(), N / tam, MPI_INT, res.data(), N / tam, MPI_INT, 0, MPI_COMM_WORLD);

    if (rango == 0) {
        cout << "Matriz:" << endl;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }

        cout << "Vector:" << endl;
        for (int i = 0; i < N; ++i) {
            cout << vec[i] << " ";
        }
        cout << endl;

        cout << "Res:" << endl;
        for (int i = 0; i < N; ++i) {
            cout << res[i] << " ";
        }
        cout << endl;
    }

    MPI_Finalize();
    return 0;
}
