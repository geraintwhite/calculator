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
      int a, b;
      pop(stack, &a);
      pop(stack, &b);
      int result = calculate(a, b, *token);
      printf("%d %c %d = %d\n", a, *token, b, result);
      push(stack, &result);
    }
    else
    {
      int num = atoi(token);
      push(stack, &num);
    }
  }

  pop(stack, result);
}
