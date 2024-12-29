#include <stdio.h>
#include <string.h>

#define ctoi(c) ((c) - '0')
#define itoc(n) ((n) + '0')

void dashatize(int number, char string[32]) {
  sprintf(string, "%d", number);

  if (number < 0)
    memmove(string, string + 1, strlen(string));

  size_t len = strlen(string);
  char stack[len * 2];

  int j = 0;
  for (size_t i = 0; i < len; ++i) {
    int n = ctoi(string[i]);
    if (n % 2 == 0) {
      stack[j++] = itoc(n);
      continue;
    }

    if (i != 0 && stack[j - 1] != '-')
      stack[j++] = '-';

    stack[j++] = itoc(n);

    if (i != len - 1)
      stack[j++] = '-';
  }

  stack[j] = '\0';
  strcpy(string, stack);
}

int main() {
  char buf[32];
  dashatize(974302, buf);
  printf("buf: %s\n", buf);
}

// https://www.codewars.com/kata/58223370aef9fc03fd000071/train/c

/*
  do_test(274, "2-7-4");
  do_test(5311, "5-3-1-1");
  do_test(86320, "86-3-20");
  do_test(974302, "9-7-4-3-02");
  do_test(INT_MAX, "2-1-4-7-48-3-64-7");
  do_test(INT_MIN, "2-1-4-7-48-3-648");
  do_test(-1111111111, "1-1-1-1-1-1-1-1-1-1");
*/
