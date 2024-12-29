#include <stdbool.h>
#include <stdio.h>
#include <string.h>

char get_opposite_bracket(char c) {
  switch (c) {
  case '(': return ')';
  case '[': return ']';
  case '{': return '}';
  default:
    return '*';
  }
}

bool valid_braces(const char *braces) {
  int length = strlen(braces);
  char stack[length];
  int top = -1;

  for (int i = 0; i < length; i++) {
    char current = braces[i];

    if (current == '(' || current == '[' || current == '{') {
      stack[++top] = current;
    } else if (current == ')' || current == ']' || current == '}') {
      if (top == -1)
        return false;

      char last_open = stack[top--];

      if (get_opposite_bracket(last_open) != current)
        return false;
    }
  }
  return top == -1;
}

int main() {
  char *braces = "a([])";
  bool result = valid_braces(braces);

  if (result == 1) {
    printf("true\n");
  } else {
    printf("false\n");
  }

  return 0;
}

// https://www.codewars.com/kata/5277c8a221e209d3f6000b56/train/c
