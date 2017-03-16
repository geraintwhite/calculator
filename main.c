#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "stack.c"
#include "string.c"
#include "calculator.c"


int
main(int argc, char **argv)
{
  if (argc < 2)
  {
    printf("Usage: %s expression in infix\n", argv[0]);
    printf("e.g    %s '10 + 3 * 5 / ( 16 - 4 )'\n", argv[0]);
    return 1;
  }

  int i = 0;
  int j = 0;
  float result = 0;
  char **infix = 0;
  char **postfix = 0;

  split(argv[1], " ", &infix, &i);

  infix_to_rpn(infix, i, &postfix, &j);
  evaluate_rpn(postfix, j, &result);

  printf("Result: %f\n", result);

  return 0;
}
