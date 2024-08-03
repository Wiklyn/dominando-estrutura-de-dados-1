#include "dynamic_stack.h"

#include <stdio.h>

int main()
{
    puts("Cria uma pilha\n");
    DynamicStack *stack = DynamicStack_create();

    printf("A pilha está vazia? %d", DynamicStack_is_empty(stack));
    puts("\n");

    // puts("Tenta ver o elemento do topo de uma pilha vazia");
    // printf("Top: %d", DynamicStack_peek(stack));
    // puts("\n");

    // puts("Tenta fazer um pop em uma pilha vazia");
    // printf("Previous Top: %d", DynamicStack_pop(stack));
    // puts("\n");

    puts("Adiciona o elemento 2 na pilha");
    DynamicStack_push(stack, 2);
    DynamicStack_print(stack);
    puts("\n");

    puts("Faz um pop na pilha");
    printf("Previous Top: %d\n", DynamicStack_pop(stack));
    DynamicStack_print(stack);
    puts("\n");

    puts("Adiciona o elemento 2 na pilha novamente");
    DynamicStack_push(stack, 2);
    DynamicStack_print(stack);
    puts("\n");

    puts("Adiciona o elemento 4 na pilha");
    DynamicStack_push(stack, 4);
    DynamicStack_print(stack);
    puts("\n");

    puts("Adiciona o elemento 6 na pilha");
    DynamicStack_push(stack, 6);
    DynamicStack_print(stack);
    puts("\n");

    puts("Ve o elemento do topo da pilha");
    printf("Top: %d", DynamicStack_peek(stack));
    puts("\n");

    puts("Faz um pop na pilha");
    printf("Previous Top: %d", DynamicStack_pop(stack));
    puts("\n");

    puts("Imprime a pilha depois do pop");
    DynamicStack_print(stack);
    puts("\n");

    puts("Adiciona o elemento 8 na pilha");
    DynamicStack_push(stack, 8);
    DynamicStack_print(stack);
    puts("\n");

    puts("Adiciona o elemento 16 na pilha");
    DynamicStack_push(stack, 16);
    DynamicStack_print(stack);
    puts("\n");

    puts("Adiciona o elemento 32 na pilha");
    DynamicStack_push(stack, 32);
    DynamicStack_print(stack);
    puts("\n");

    printf("A pilha está vazia? %d", DynamicStack_is_empty(stack));
    puts("\n");

    puts("Destroi a pilha");
    DynamicStack_destroy(&stack);
    printf("stack == NULL? %d\n", stack == NULL);

    return 0;
}
