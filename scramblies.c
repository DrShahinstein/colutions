#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool scramble(const char *str1, const char *str2) {
  int length = strlen(str2);
  char needed_chars[strlen(str1) + 1];

  strcpy(needed_chars, str1);

  for (int i = 0; i < length; i++) {
    char *p = strchr(needed_chars, str2[i]);

    if (p) {
      *p = '*';
    } else {
      return false;
    }
  }

  return true;
}

int main() {
  char *str1 = "scriptingjava";
  char *str2 = "javascript";

  bool result = scramble(str1, str2);

  if (result) {
    printf("+: You can make '%s' using '%s'", str2, str1);
  } else {
    printf("-: You can't make '%s' using '%s'", str2, str1);
  }

  printf("\n");

  return 0;
}

// https://www.codewars.com/kata/55c04b4cc56a697bb0000048/train/c
