#include "stack.h"


Stack *
create_stack()
{
  Stack *stack;

  stack = malloc(sizeof(Stack));

  stack->size = MAX_SIZE;
  stack->top = -1;
  stack->stack = malloc(sizeof(int) * stack->size);

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


int
peek(Stack *stack)
{
  return stack->stack[stack->top];
}


int
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
push(Stack *stack, int data)
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
