#include <stdio.h>

int sumar(int *a, int *b) {
  return *a + *b;
}
int restar(int *a, int *b) {
  return *a - *b;
}
int multiplicar(int *a, int *b) {
  int resultado = 0;
  for (int i = 0; i < *b; i++) {
    resultado += *a;
  }
  return resultado;
}
int dividir(int *a, int *b) {
  int cociente = 0;
  while (*a >= *b) {
    *a -= *b;
    cociente++;
  }
  return cociente;
}

int main() {
  int x = 10;
  int y = 5;

  int suma = sumar(&x, &y);
  int resta = restar(&x, &y);
  int multiplicacion = multiplicar(&x, &y);
  int division = dividir(&x, &y);

  printf("Suma: %d\n", suma);
  printf("Resta: %d\n", resta);
  printf("Multiplicacion: %d\n", multiplicacion);
  printf("Division: %d\n", division);

  return 0;
}
