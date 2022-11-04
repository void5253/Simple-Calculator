#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX1 32

double stk1[MAX1];
int top1 = -1;

void push1(double n) {
  if (top1 < MAX1 - 1) {
    stk1[++top1] = n;
  } else {
    printf("Calculate: Overflow!\n");
    puts("Insufficient Memory!");
    exit(1);
  }
}

double pop1() {
  double val;
  if (top1 == -1) {
    printf("Calculate: Underflow\n");
    puts("Invalid Expression!");
    exit(1);
  }
  val = stk1[top1--];
  return val;
}

long long factorial(int n) {
  if (n >= 0) {
    int prod = 1;
    for (int i = 1; i <= n; i++) {
      prod *= i;
    }
    return prod;
  }
  puts("Error: factorial of non-whole number!");
  exit(1);
}

double calculateValue(double *a, int size) {
  int i;
  double x, y;
  char c;
  for (i = 1; i < size; i += 2) {
    if (!a[i - 1]) {
      c = (char)(int)a[i];
      switch (c) {
      case '+':
        x = pop1();
        y = pop1();
        push1(x + y);
        break;
      case '-':
        x = pop1();
        y = pop1();
        push1(y - x);
        break;
      case '*':
        x = pop1();
        y = pop1();
        push1(x * y);
        break;
      case '/':
        x = pop1();
        y = pop1();
        push1(y / x);
        break;
      case '^':
        x = pop1();
        y = pop1();
        push1(pow(y, x));
        break;
      case '%':
        x = pop1();
        y = pop1();
        if ((int)x == floor(x) && (int)y == floor(y))
          push1((int)y % (int)x);
        else
          puts("Modulo operator works only on integer arguments!");
        break;
      case '!':
        x = pop1();
        if ((int)x == floor(x))
          push1(factorial(x));
        else
          puts("FActorial of a float!");
        break;
      }
    } else {
      push1(a[i]);
    }
  }
  return stk1[top1];
}