#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "stack.c"


int
calculate(int a, int b, char token)
{
  int result = 0;

  if (token == '+')
  {
    result = a + b;
  }
  else if (token == '-')
  {
    result = a - b;
  }
  else if (token == '*')
  {
    result = a * b;
  }
  else if (token == '/')
  {
    result = a / b;
  }

  return result;
}


int
evaluate_rpn(char **expression, int num)
{
  Stack *stack = create_stack();

  int i;
  for (i = 0; i < num; ++i)
  {
    char *token = expression[i];

    if (*token == '+' || *token == '-' || *token == '*' || *token == '/')
    {
      int b = pop(stack);
      int a = pop(stack);
      int result = calculate(a, b, *token);
      push(stack, result);
    }
    else
    {
      push(stack, atoi(token));
    }
  }

  return pop(stack);
}


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
