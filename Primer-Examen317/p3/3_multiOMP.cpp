#include <iostream>
#include <omp.h>

int main() {
  int a = 15;
  int b = 3;
  int c = 0;

  //Multiplicacion
  #pragma omp parallel for
  for (int i = 0; i < b; ++i) {
    c += a;
  }
  printf("Resultado de la multiplicacion: %d\n", c);
 
  //Division
  int count = 0;
  #pragma omp parallel for
  for (int i = a; i >= b; i -= b) {
    ++count;
  }
  c = count;
  printf("Resultado de la division: %d\n", c);

  return 0;
}