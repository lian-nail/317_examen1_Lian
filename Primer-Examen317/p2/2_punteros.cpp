#include <iostream>

int sumita(int* a, int* b) {
  return *a + *b;
}
int restar(int* a, int* b) {
  return *a - *b;
}
int multiplicar(int* a, int* b) {
  int resultado = 0;
  for (int i = 0; i < *b; i++) {
    resultado += *a;
  }
  return resultado;
}
int dividir(int* a, int* b) {
  int cociente = 0;
  while (*a >= *b) {
    *a -= *b;
    cociente++;
  }
  return cociente;
}


int main() {
  int x = 15;
  int y = 7;

  int suma = sumita(&x, &y);
  int resta = restar(&x, &y);
  int multiplicacion = multiplicar(&x, &y);
  int division = dividir(&x, &y);

  std::cout << "Suma: " << suma << std::endl;
  std::cout << "Resta: " << resta << std::endl;
  std::cout << "Multiplicacion: " << multiplicacion << std::endl;
  std::cout << "Division: " << division << std::endl;

  return 0;
}