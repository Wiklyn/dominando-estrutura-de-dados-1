#include "static_stack.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct _static_stack
{
    int *data;
    long capacity;
    long top;
} StaticStack;

StaticStack *StaticStack_create(long capacity)
{
    StaticStack *stack = (StaticStack*) calloc(1, sizeof(StaticStack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (int*) calloc(stack->capacity, sizeof(int));

    return stack;
}

void StaticStack_destroy(StaticStack **stack_ref)
{
    StaticStack *stack = *stack_ref;
    free(stack->data);
    free(stack);
    *stack_ref = NULL;
}

bool StaticStack_is_empty(const StaticStack *stack)
{
    return stack->top == -1;
}

bool StaticStack_is_full(const StaticStack *stack)
{
    return stack->top == stack->capacity - 1;
}

long StaticStack_size(const StaticStack *stack)
{
    return stack->top + 1;
}

void StaticStack_push(StaticStack *stack, int value)
{
    if (StaticStack_is_full(stack))
    {
        fprintf(stderr, "ERROR in 'StaticStack_push'\n");
        fprintf(stderr, "Stack is full\n");
        exit(EXIT_FAILURE);
    }

    stack->top++;
    stack->data[stack->top] = value;
}

int StaticStack_peek(const StaticStack *stack)
{
    if (StaticStack_is_empty(stack))
    {
        fprintf(stderr, "ERROR in 'StaticStack_peek'\n");
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }

    return stack->data[stack->top];
}

int StaticStack_pop(StaticStack *stack)
{
    if (StaticStack_is_empty(stack))
    {
        fprintf(stderr, "ERROR in 'StaticStack_pop'\n");
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }

    int top_value = stack->data[stack->top];
    stack->top--;

    return top_value;
}

void StaticStack_print(const StaticStack *stack)
{
    printf("Capacity: %ld\n", stack->capacity);
    printf("Size: %ld\n", StaticStack_size(stack));
    printf("Top: %ld\n", stack->top);
    printf("Data: ");

    for (long i = 0; i < stack->top; i++)
    {
        printf("%d, ", stack->data[i]);
    }

    printf("%d", stack->data[stack->top]);
}
