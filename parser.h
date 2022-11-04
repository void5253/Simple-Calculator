#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parseStringToNum(char *source, double *res,
                      int *size) { // End source with )
  int n = strlen(source), i, j = 0, flag = 0, dotflag = 0, neg = 1;
  double val = 0, mult = 1;
  char c;
  for (i = 0; i < n; i++) {
    c = source[i];
    if (!isdigit(c)) {
      if (flag && c != '.') {
        res[j++] = 1;
        res[j++] = neg * val;
        dotflag = 0, flag = 0, val = 0, mult = 1, neg = 1;
      }
      if (c == '%' || c == '!' || c == '*' || c == '/' || c == '+' ||
          c == '-' || c == '^' || c == '(' || c == ')') {
        if ((c == '-' && !res[j - 2]) || (c == '-' && j - 2 < 0)) {
          neg = -1;
        } else {
          res[j++] = 0;
          res[j++] = (int)c;
        }
      } else if (isblank(c))
        continue;
      else if (c == '.') {
        dotflag = 1;
      } else {
        puts("Parser: Invalid Expression!");
        exit(1);
      }
    } else {
      flag = 1;
      if (!dotflag)
        val = val * 10 + (c - '0');
      else {
        mult *= 0.1;
        val = val + mult * (c - '0');
      }
    }
  }
  *size = j;
}