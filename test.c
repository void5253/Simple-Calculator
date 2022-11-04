#include "calculate.h"
#include "infix_postfix.h"
#include "parser.h"
#include <stdio.h>

void testParseStringToNum(char *source, double *res, int *size) {
  parseStringToNum(source, res, size);
  for (int i = 1; i < *size; i += 2) {
    if (res[i - 1])
      printf("%.2lf", res[i]);
    else
      printf("%c", (int)res[i]);
  }
  puts("");
}

void testInfixToPostfix(double *source, double *res, int *size) {
  infixToPostfix(source, res, size);
  for (int i = 1; i < *size; i += 2) {
    if (res[i - 1]) {
      printf("%.2lf ", res[i]);
    } else
      printf("%c ", (int)res[i]);
  }
  puts("");
}

void testCalculateValue(double *a, int n) {
  printf("Value: %.3lf", calculateValue(a, n));
}

int main() {
  system("cls");
  char source[] = "(2.3 +5)*3 - 4!^2 * -1)";
  double res1[64], res2[64];
  int size;
  testParseStringToNum(source, res1, &size);
  // testInfixToPostfix(res1, res2, &size);
  // testCalculateValue(res2, size);
  return 0;
}