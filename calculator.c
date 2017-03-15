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
precedence(char token)
{
  int result = 0;

  if (token == '(')
  {
    result = 1;
  }
  else if (token == '+')
  {
    result = 2;
  }
  else if (token == '-')
  {
    result = 2;
  }
  else if (token == '*')
  {
    result = 3;
  }
  else if (token == '/')
  {
    result = 3;
  }

  return result;
}


void
evaluate_rpn(char **expression, int num, int *result)
{
  Stack *stack = create_stack();

  int i;
  for (i = 0; i < num; ++i)
  {
    char *token = expression[i];
    printf("token %s\n", token);

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

  *result = pop(stack);
}


void
infix_to_rpn(char **expression, int num)
{
  Stack *stack = create_stack();

  int i;
  for (i = 0; i < num; ++i)
  {
    char *token = expression[i];

    if (*token == '+' || *token == '-' || *token == '*' || *token == '/')
    {
      while (!is_empty(stack) && precedence(peek(stack)) >= precedence(*token))
      {
        printf("%c ", pop(stack));
      }
      push(stack, *token);
    }
    else if (*token == '(')
    {
      push(stack, *token);
    }
    else if (*token == ')')
    {
      char topToken = pop(stack);
      while (topToken != '(')
      {
        printf("%c ", pop(stack));
        topToken = pop(stack);
      }
    }
    else
    {
      printf("%s ", token);
    }
  }

  while (!is_empty(stack))
  {
    printf("%c ", pop(stack));
  }

  printf("\n");
}
