#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 64

char stk[MAX];
int top = -1;

void push(char c) {
  if (top == MAX - 1) {
    puts("Infix_Postfix: Overflow!");
    puts("Insufficient Memory!");
    exit(1);
  } else {
    stk[++top] = c;
  }
}

char pop() {
  if (top == -1) {
    puts("Infix_Postfix: Underflow");
    puts("Invalid Expression!");
    exit(1);
  } else {
    char c = stk[top--];
    return c;
  }
}

int priority(char c) {
  if (c == '!')
    return 3;
  else if (c == '^')
    return 2;
  else if (c == '/' || c == '*' || c == '%')
    return 1;
  else if (c == '+' || c == '-')
    return 0;
  else if (c == '(')
    return -1;
}

void infixToPostfix(double *source, double *res, int *size) {
  push('(');
  int i, n = *size, j = 0;
  char c, d;
  for (i = 1; i < n; i += 2) {
    if (!source[i - 1]) {
      c = (char)(int)source[i];
      if (c == '(') {
        push(c);
      } else if (c == ')') {
        while (stk[top] != '(') {
          d = pop();
          res[j++] = 0;
          res[j++] = (int)d;
        }
        pop();
      } else {
        while (priority(c) <= priority(stk[top])) {
          d = pop();
          res[j++] = 0;
          res[j++] = (int)d;
        }
        push(c);
      }
    } else {
      res[j++] = 1;
      res[j++] = source[i];
    }
  }
  *size = j;
}