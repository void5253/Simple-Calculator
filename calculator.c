#include "calculate.h"
#include "infix_postfix.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  system("cls");
  char expr[256], ch;
  int n;
  double expr_num[128], postfix[128];
  do {
    printf("Enter expression: ");
    fflush(stdin);
    fgets(expr, 256, stdin);
    expr[strlen(expr) - 1] = ')';
    n = strlen(expr);
    parseStringToNum(expr, expr_num, &n);
    infixToPostfix(expr_num, postfix, &n);
    printf("Value: %.3lf", calculateValue(postfix, n));
    printf("\nContinue(y/n)?: ");
    scanf("%c", &ch);
  } while (ch == 'y');
  return 0;
}
