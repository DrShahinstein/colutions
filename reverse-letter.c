#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverse_letter(const char *str) {
  int length      = strlen(str);
  char *final_str = (char *)malloc((length + 1) * sizeof(char));

  if (final_str == NULL) {
    printf("Memory allocation failed\n");
    return NULL;
  }

  int index = 0;
  for (int i = length - 1; i >= 0; i--) {
    if (isalpha(str[i])) {
      final_str[index++] = str[i];
    }
  }

  final_str[index] = '\0';

  return final_str;
}

int main() {
  char *result = reverse_letter("ultr53o?n");

  if (result != NULL) {
    printf("%s\n", result);
    free(result);
  }

  return 0;
}

// https://www.codewars.com/kata/58b8c94b7df3f116eb00005b/train/c
