#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strsum(const char *a, const char *b) {
  int lenA = strlen(a);
  int lenB = strlen(b);
  int len_max;
  int zero_count = abs(lenA - lenB);
  char *zeros = malloc(zero_count + 1);
  char *x = (char *)a;
  char *y = (char *)b;

  memset(zeros, '0', zero_count);
  zeros[zero_count] = '\0';

  if (lenA < lenB) {
    x = malloc(zero_count + lenA + 1);
    strcpy(x, zeros);
    strcat(x, a);
    len_max = strlen(x);
  } else {
    y = malloc(zero_count + lenB + 1);
    strcpy(y, zeros);
    strcat(y, b);
    len_max = strlen(y);
  }

  free(zeros);

  int len_sum = 0;
  int carry = 0;
  char *sum = malloc(len_max * sizeof(char) + 2);

  for (int i = 0; i < len_max; ++i) {
    int digitsum = (x[len_max - i - 1] - '0') + (y[len_max - i - 1] - '0');

    sum[i] = ((digitsum + carry) % 10) + '0';
    len_sum++;

    carry = (digitsum + carry) / 10;

    if ((i == len_max - 1) && carry) {
      sum[i + 1] = carry + '0';
      len_sum++;
    }
  }

  if (x != a) free(x);
  if (y != b) free(y);

  // reverse
  for (int i = 0, j = len_sum - 1; i < j; i++, j--) {
    char tmp = sum[i];
    sum[i] = sum[j];
    sum[j] = tmp;
  }

  sum[len_sum] = '\0';

  // strip zeros
  int start = 0;
  while (sum[start] == '0' && start < len_sum - 1) start++;

  if (start > 0) {
    len_sum -= start;
    memmove(sum, sum + start, len_sum + 1);
    char *trimmed = realloc(sum, len_sum + 1);
    sum = trimmed;
  }

  return sum;
}

int main() {
  char *buf = strsum("1950", "50");
  if (buf != NULL) {
    printf("%s\n", buf);
    free(buf);
  }
  return 0;
}

// https://www.codewars.com/kata/5324945e2ece5e1f32000370/train/c
