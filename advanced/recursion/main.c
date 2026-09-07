#include<stdio.h>

int tail_factorial(int n, int accumulator) {
  if (n == 0) return accumulator;
  return tail_factorial(n - 1 , accumulator * n);
}

int factorial(int n){
 return tail_factorial(n, 1); 
}

int main() {
  int number = 3;
  printf("factorial of %d is %d\n", number,factorial(number));
  return 0;
}
