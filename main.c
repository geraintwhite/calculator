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
    printf("Expression required\n");
    return 1;
  }

  char *expression[argc - 1];

  int i;
  for (i = 1; i < argc; ++i)
  {
    expression[i - 1] = argv[i];
  }

  printf("Result: %d\n", evaluate_rpn(expression, argc - 1));

  return 0;
}
