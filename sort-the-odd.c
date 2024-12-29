#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void sort_array(size_t n, int arr[n]) {
  int virtual_arr[n];

  for (size_t i = 0; i < n; i++) {
    int tmp = arr[i];
    virtual_arr[i] = tmp;
  }

  int tracker = 0;
  for (size_t _ = 0; _ < n; _++) {
    int min = INT_MAX;
    int min_index = -1;

    for (size_t i = 0; i < n; i++) {
      if (virtual_arr[i] < min) {
        min = virtual_arr[i];
        min_index = i;
      }
    }

    virtual_arr[min_index] = INT_MAX;

    while (tracker < n && arr[tracker] % 2 == 0) {
      tracker++;
    }

    if (tracker < n && min % 2 != 0) {
      arr[tracker] = min;
      tracker++;
    }
  }
}

int main() {
  int arr[] = {5, 3, 1, 8, 0}; // => { 1, 3, 5, 8, 0 }
  size_t length = sizeof(arr) / sizeof(arr[0]);

  sort_array(length, arr);

  printf("{ ");
  for (int i = 0; i < length; i++) {
    printf("%d, ", arr[i]);
  }
  printf(" }\n");

  return 0;
}

// https://www.codewars.com/kata/578aa45ee9fd15ff4600090d/train/c
