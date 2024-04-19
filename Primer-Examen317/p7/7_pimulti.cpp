#include <iostream>
#include <thread>
#include <vector>
#include <atomic>

using namespace std;

// Función para calcular la cantidad de puntos dentro del círculo
void calcPunt(int num_puntos, atomic<int>& puntDentro) {
    int contador = 0;
    for (int i = 0; i < num_puntos; ++i) {
        double x = (double) rand() / RAND_MAX;
        double y = (double) rand() / RAND_MAX;
        if (x * x + y * y <= 1.0) {
            contador++;
        }
    }
    puntDentro += contador;
}

int main() {
    const int num = 4;
    const int total_puntos = 1000000;
    atomic<int> puntDentro(0);

    vector<thread> threads;

    // Iniciar los hilos
    for (int i = 0; i < num; ++i) {
        threads.push_back(thread(calcPunt, total_puntos / num, ref(puntDentro)));
    }

    // Esperar a que todos los hilos terminen
    for (auto& t : threads) {
        t.join();
    }

    // Calcular pi
    double pi = 4.0 * puntDentro / total_puntos;
    cout << "Valor estimado de pi: " << pi << endl;

    return 0;
}
