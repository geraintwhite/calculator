#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "stack.c"
#include "string.c"
#include "calculator.c"


int
main(int argc, char **argv)
{
  if (argc < 2)
  {
    printf("Usage: %s expression\n", argv[0]);
    printf("e.g    %s '5 1 2 + 4 * + 3 -'\n", argv[0]);
    return 1;
  }

  int i;
  char **expression;

  split(argv[1], " ", &expression, &i);

  printf("Result: %d\n", evaluate_rpn(expression, i));

  return 0;
}
