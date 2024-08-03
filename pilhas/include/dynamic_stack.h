#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H


#include <stdbool.h>
#include <stddef.h>

typedef struct _dynamic_stack DynamicStack;

DynamicStack *DynamicStack_create();
void DynamicStack_destroy(DynamicStack **stack_ref);
bool DynamicStack_is_empty(const DynamicStack *stack);
size_t DynamicStack_size(const DynamicStack *stack);
void DynamicStack_push(DynamicStack *stack, int value);
int DynamicStack_peek(const DynamicStack *stack);
int DynamicStack_pop(DynamicStack *stack);
void DynamicStack_print(const DynamicStack *stack);


#endif
