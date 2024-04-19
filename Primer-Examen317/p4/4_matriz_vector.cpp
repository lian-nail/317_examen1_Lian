#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;
#define N 3

int main() {
  // int n;
  // // Leer el tamaño de la matriz y el vector
  // cout << "Por favor ingrese el tamaño: " << "\n";
  // cin >> n;

  // Inicializar matrices
  float mat[N][N];
  float vec[N];
  float res[N];

  // Generar valores aleatorios para la matriz y el vector
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      mat[i][j] = rand() % 10 + 1;
    }
    vec[i] = rand() % 10 + 1;
  }
    // Mostrar la matriz
  printf("\nMatriz:\n");
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%.2f ", mat[i][j]);
    }
    printf("\n");
  }

  // Mostrar el vector
  printf("\nVector:\n");
  for (int i = 0; i < N; i++) {
    printf("%.2f ", vec[i]);
  }
  printf("\n");

  #pragma omp parallel for
  for (int i = 0; i < N; i++) {
    float suma = 0.0f;
    for (int j = 0; j < N; j++) {
      suma += mat[i][j] * vec[j];
    }
    res[i] = suma;
  }

  printf("\nResultado:\n");
  for (int i = 0; i < N; i++) {
    printf("%.2f ", res[i]);
  }

  return 0;
}
