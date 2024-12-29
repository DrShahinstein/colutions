#include <stdio.h>

#define btoa(x) ((x) ? "true" : "false")

int find_even_index(const int *values, int length) {
  if (length == 0) {
    return 0;
  }

  for (int i = 0; i < length; i++) {
    int left  = 0;
    int right = 0;

    for (int j = 0; j < i; j++) {
      left += values[j];
    }

    for (int j = i + 1; j < length; j++) {
      right += values[j];
    }

    if (left == right) {
      return i;
    }
  }

  return -1;
}

int main() {
  int arr[]      = {1, 2, 3, 4, 3, 2, 1};
  int length     = sizeof(arr) / sizeof(int);
  int result     = find_even_index(arr, length);
  char *expected = btoa(result == 3);

  printf("returned: %d\n", result);
  printf("solved: %s\n", expected);

  return 0;
}

// https://www.codewars.com/kata/5679aa472b8f57fb8c000047/train/c
