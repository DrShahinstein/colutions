#include <limits.h>
#include <stdio.h>

int gimme(const int triplet[3]) {
  int min = INT_MAX;
  int max = INT_MIN;

  for (int i = 0; i < 3; i++) {
    if (triplet[i] > max) {
      max = triplet[i];
    }
    if (triplet[i] < min) {
      min = triplet[i];
    }
  }

  for (int i = 0; i < 3; i++) {
    if (triplet[i] != min && triplet[i] != max) {
      return i;
    };
  }

  return 0;
}

int main() {
  int triplet[] = {-329, 247, 224};
  int result = gimme(triplet);
  printf("Index: %d\n", result);
}

// https://www.codewars.com/kata/545a4c5a61aa4c6916000755/train/c
