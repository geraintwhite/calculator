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
    printf("Usage: calculator expression\n");
    printf("e.g    calculator '5 1 2 + 4 * + 3 -'\n");
    return 1;
  }

  int i;
  char **expression;

  split(argv[1], " ", &expression, &i);

  printf("Result: %d\n", evaluate_rpn(expression, i));

  return 0;
}
