#include "static_stack.h"

#include <stdio.h>

int main()
{
    puts("Cria uma pilha\n");
    StaticStack *stack = StaticStack_create(5);

    printf("A pilha está vazia? %d", StaticStack_is_empty(stack));
    puts("");

    printf("A pilha está cheia? %d", StaticStack_is_full(stack));
    puts("\n");

    // puts("Tenta ver o elemento do topo de uma pilha vazia");
    // printf("Top: %d", StaticStack_peek(stack));
    // puts("\n");

    // puts("Tenta fazer um pop em uma pilha vazia");
    // printf("Previous Top: %d", StaticStack_pop(stack));
    // puts("\n");

    puts("Adiciona o elemento 2 na pilha");
    StaticStack_push(stack, 2);
    StaticStack_print(stack);
    puts("\n");

    puts("Adiciona o elemento 4 na pilha");
    StaticStack_push(stack, 4);
    StaticStack_print(stack);
    puts("\n");

    puts("Adiciona o elemento 6 na pilha");
    StaticStack_push(stack, 6);
    StaticStack_print(stack);
    puts("\n");

    puts("Ve o elemento do topo da pilha");
    printf("Top: %d", StaticStack_peek(stack));
    puts("\n");

    puts("Faz um pop na pilha");
    printf("Previous Top: %d", StaticStack_pop(stack));
    puts("\n");

    puts("Imprime a pilha depois do pop");
    StaticStack_print(stack);
    puts("\n");

    printf("A pilha está vazia? %d", StaticStack_is_empty(stack));
    puts("");

    printf("A pilha está cheia? %d", StaticStack_is_full(stack));
    puts("\n");

    puts("Adiciona o elemento 8 na pilha");
    StaticStack_push(stack, 8);
    StaticStack_print(stack);
    puts("\n");

    puts("Adiciona o elemento 16 na pilha");
    StaticStack_push(stack, 16);
    StaticStack_print(stack);
    puts("\n");

    puts("Adiciona o elemento 32 na pilha");
    StaticStack_push(stack, 32);
    StaticStack_print(stack);
    puts("\n");

    printf("A pilha está vazia? %d", StaticStack_is_empty(stack));
    puts("");

    printf("A pilha está cheia? %d", StaticStack_is_full(stack));
    puts("\n");

    // puts("Tenta adicionar um elemento em uma pilha cheia");
    // StaticStack_push(stack, 64);

    puts("Destroi a pilha");
    StaticStack_destroy(&stack);
    printf("stack == NULL? %d\n", stack == NULL);

    return 0;
}
