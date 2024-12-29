#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *diamond(int n) {
  if (n <= 0 || n % 2 == 0) {
    return NULL;
  }

  int total_chars = n * n;
  char *result = (char *)malloc(total_chars * sizeof(char));

  if (result == NULL)
    return NULL;

  int index = 0;

  for (int i = 1; i <= n; i += 2) {
    int spaces = (n - i) / 2;
    int stars = i;

    for (int j = 0; j < spaces; j++) {
      result[index++] = ' ';
    }

    for (int j = 0; j < stars; j++) {
      result[index++] = '*';
    }

    result[index++] = '\n';
  }

  for (int i = n - 2; i >= 1; i -= 2) {
    int spaces = (n - i) / 2;
    int stars = i;

    for (int j = 0; j < spaces; j++) {
      result[index++] = ' ';
    }

    for (int j = 0; j < stars; j++) {
      result[index++] = '*';
    }

    result[index++] = '\n';
  }

  result[index] = '\0';
  result = realloc(result, (index + 1) * sizeof(char));

  return result;
}

int main() {
  char *res = diamond(11);

  if (res == NULL) {
    printf("None\n");
  } else {
    printf("%s", res);
    free(res);
  }

  return 0;
}

// https://www.codewars.com/kata/5503013e34137eeeaa001648/train/c
