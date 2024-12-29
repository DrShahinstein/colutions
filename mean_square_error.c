#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

double mean_square_error(size_t n, const int a[n], const int b[n]) {
  int t = 0;
  for (size_t i = 0; i < n; i++) {
    int d = abs(a[i] - b[i]);
    printf("%d", d);
    t += d * d;
  }
  return (double)t / n;
}

int main() {
  int a[] = {10, 20, 10, 2};
  int b[] = {10, 25, 5, -2};
  int length = sizeof(a) / sizeof(a[0]);
  double result = mean_square_error(length, a, b);
  
  printf("Result: %f", result);
  return 0;
}

// https://www.codewars.com/kata/51edd51599a189fe7f000015/train/c
