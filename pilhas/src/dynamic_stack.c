#include "dynamic_stack.h"

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

typedef struct _stack_node
{
    int value;
    struct _stack_node *next;
    struct _stack_node *previous;
} StackNode;

typedef struct _dynamic_stack
{
    StackNode *begin;
    StackNode *end;
    size_t size;
} DynamicStack;

StackNode *StackNode_create(int value)
{
    StackNode *node = (StackNode*) calloc(1, sizeof(StackNode));
    node->value = value;
    node->previous = NULL;
    node->next = NULL;

    return node;
}

DynamicStack *DynamicStack_create()
{
    DynamicStack *stack = (DynamicStack*) calloc(
        1, sizeof(DynamicStack)
    );
    stack->begin = NULL;
    stack->end = NULL;
    stack->size = 0;

    return stack;
}

void DynamicStack_destroy(DynamicStack **stack_ref)
{
    DynamicStack *stack = *stack_ref;
    StackNode *current_node = stack->begin;
    StackNode *aux_pointer = NULL;

    while (current_node != NULL)
    {
        aux_pointer = current_node;
        current_node = current_node->next;
        free(aux_pointer);
    }
    
    free(stack);
    *stack_ref = NULL;
}

bool DynamicStack_is_empty(const DynamicStack *stack)
{
    return stack->size == 0;
}

size_t DynamicStack_size(const DynamicStack *stack)
{
    return stack->size;
}

void DynamicStack_push(DynamicStack *stack, int value)
{
    StackNode *new_node = StackNode_create(value);

    if (DynamicStack_is_empty(stack))
        stack->begin = new_node;
    else
    {
        new_node->previous = stack->end;
        stack->end->next = new_node;
    }

    stack->end = new_node;
    stack->size++;
}

int DynamicStack_peek(const DynamicStack *stack)
{
    if (DynamicStack_is_empty(stack))
    {
        fprintf(stderr, "ERROR in 'DynamicStack_peek'\n");
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }

    return stack->end->value;
}

int DynamicStack_pop(DynamicStack *stack)
{
    if (DynamicStack_is_empty(stack))
    {
        fprintf(stderr, "ERROR in 'DynamicStack_pop'\n");
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }

    int top_value = stack->end->value;

    StackNode *current_node = stack->end;

    if (DynamicStack_size(stack) == 1)
    {
        stack->begin = NULL;
        stack->end = NULL;
    }
    else
    {
        stack->end = current_node->previous;
        current_node->previous->next = NULL;
    }

    free(current_node);
    stack->size--;

    return top_value;
}

void DynamicStack_print(const DynamicStack *stack)
{
    StackNode *node = stack->begin;

    size_t size = DynamicStack_size(stack);

    printf("Size: %lu\n", size);    

    printf("Data: ");

    if (size == 0)
    {
        printf("Stack is empty");
    }
    else
    {
        while (node->next != NULL)
        {
            printf("%d, ", node->value);
            node = node->next;
        }

        printf("%d\n", node->value);
        printf("Top: %d", stack->end->value);
    }
}
