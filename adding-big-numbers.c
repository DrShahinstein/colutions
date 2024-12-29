#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *add(const char *num1, const char *num2) {
  int len1     = strlen(num1);
  int len2     = strlen(num2);
  int len_max  = len1 > len2 ? len1 : len2;
  char *result = (char *)malloc(len_max + 2);

  if (!result)
    return NULL;

  int carry = 0, i = 0;
  int p1 = len1 - 1, p2 = len2 - 1;

  while (p1 >= 0 || p2 >= 0 || carry > 0) {
    int digit1 = (p1 >= 0) ? num1[p1--] - '0' : 0; // - '0' is to convert the char digit to an int digit
    int digit2 = (p2 >= 0) ? num2[p2--] - '0' : 0; // - '0' is to convert the char digit to an int digit
    int sum = digit1 + digit2 + carry;

    carry = sum / 10;
    result[i++] = (sum % 10) + '0'; // + '0' is to convert the int digit back to a char digit
  }

  result[i] = '\0';

  // reverse the result string, since the digits were added in reverse order
  for (int j = 0; j < i / 2; j++) {
    char temp = result[j];
    result[j] = result[i - j - 1];
    result[i - j - 1] = temp;
  }

  return result;
}

int main() {
  char *result = add("123", "321");
  printf("%s\n", result);
  free(result);

  result = add("11", "99");
  printf("%s\n", result);
  free(result);

  return 0;
}

// https://www.codewars.com/kata/525f4206b73515bffb000b21/train/c
