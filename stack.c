#include "stack.h"


Stack *
create_stack()
{
  Stack *stack;

  stack = malloc(sizeof(Stack));

  stack->size = MAX_SIZE;
  stack->top = -1;
  stack->stack = (void **) malloc(sizeof(void *) * stack->size);

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


void
peek(Stack *stack, void *result)
{
  result = stack->stack[stack->top];
}


void
pop(Stack *stack, void *result)
{
  if (!is_empty(stack))
  {
    result = stack->stack[stack->top--];
  }
  else
  {
    printf("Stack empty.\n");
  }
}


void
push(Stack *stack, void *data)
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
