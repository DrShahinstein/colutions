#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

bool small_enough(int *arr, size_t length, int limit) {
  for (int i = 0; i < length; i++) {
    if (arr[i] > limit)
      return false;
  }
  return true;
}

int main() {
  int arr[]     = {66, 101};
  size_t length = sizeof(arr) / sizeof(int);
  int limit     = 200;

  bool res = small_enough(arr, length, limit);
  printf("%d\n", res);
}

// https://www.codewars.com/kata/57cc981a58da9e302a000214/train/c
