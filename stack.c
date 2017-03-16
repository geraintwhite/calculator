#include "stack.h"


Stack *
create_stack()
{
  Stack *stack;

  stack = malloc(sizeof(Stack));

  stack->size = MAX_SIZE;
  stack->top = -1;
  stack->stack = malloc(sizeof(float) * stack->size);

  return stack;
}


bool
is_empty(Stack *stack)
{
  return stack->top == -1;
}


bool
is_full(Stack *stack)
{
  return stack->top == stack->size;
}


float
peek(Stack *stack)
{
  return stack->stack[stack->top];
}


float
pop(Stack *stack)
{
  if (!is_empty(stack))
  {
    return stack->stack[stack->top--];
  }
  else
  {
    printf("Stack empty.\n");
  }
}


void
push(Stack *stack, float data)
{
  if (!is_full(stack))
  {
    stack->stack[++stack->top] = data;
  }
  else
  {
    printf("Stack full.\n");
  }
}
