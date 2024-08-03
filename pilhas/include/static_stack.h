#ifndef STATIC_STACK_H
#define STATIC_STACK_H


#include <stdbool.h>
#include <stddef.h>

typedef struct _static_stack StaticStack;

StaticStack *StaticStack_create(long capacity);
void StaticStack_destroy(StaticStack **stack_ref);
bool StaticStack_is_empty(const StaticStack *stack);
bool StaticStack_is_full(const StaticStack *stack);
long StaticStack_size(const StaticStack *stack);
void StaticStack_push(StaticStack *stack, int value);
int StaticStack_peek(const StaticStack *stack);
int StaticStack_pop(StaticStack *stack);
void StaticStack_print(const StaticStack *stack);


#endif