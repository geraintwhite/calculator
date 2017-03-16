float
calculate(float a, float b, char token)
{
  float result = 0;

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
evaluate_rpn(char **expression, int num, float *result)
{
  Stack *stack = create_stack();

  int i;
  for (i = 0; i < num; ++i)
  {
    char *token = expression[i];

    if (*token == '+' || *token == '-' || *token == '*' || *token == '/')
    {
      float b = pop(stack);
      float a = pop(stack);
      float result = calculate(a, b, *token);
      push(stack, result);
    }
    else
    {
      push(stack, atof(token));
    }
  }

  *result = pop(stack);
}


void
add_to_res(char *token, char ***res, int *num)
{
  *res = realloc(*res, sizeof(char*) * ++(*num));
  (*res)[*num - 1] = token;
}


char *
add_null_terminator(char token)
{
  char *s = (char*) malloc(sizeof(char) * 2);
  s[0] = token;
  s[1] = '\0';
  return s;
}


void
infix_to_rpn(char **expression, int num, char ***result, int *resnum)
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
        char *s = add_null_terminator(pop(stack));
        add_to_res(s, result, resnum);
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
        char *s = add_null_terminator(topToken);
        add_to_res(s, result, resnum);
        topToken = pop(stack);
      }
    }
    else
    {
      add_to_res(token, result, resnum);
    }
  }

  while (!is_empty(stack))
  {
    char *s = add_null_terminator(pop(stack));
    add_to_res(s, result, resnum);
  }
}
