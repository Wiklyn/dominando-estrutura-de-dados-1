#include "dynamic_circular_queue.h"

#include <stdio.h>

int main()
{
    puts("Cria uma fila\n");
    DynamicCircularQueue *queue = DynamicCircularQueue_create();

    printf("A fila está vazia? %d", DynamicCircularQueue_is_empty(queue));
    puts("\n");

    // puts("Tenta ver o primeiro elemento da fila vazia");
    // printf("First: %d", DynamicCircularQueue_peek(queue));

    // puts("Tenta desenfileirar o primeiro elemento da fila vazia");
    // printf("Previous First: %d", DynamicCircularQueue_dequeue(queue));

    puts("Adiciona o elemento 2 na fila");
    DynamicCircularQueue_enqueue(queue, 2);
    DynamicCircularQueue_print(queue);
    puts("\n");

    puts("Ve o primeiro elemento da fila");
    printf("First: %d", DynamicCircularQueue_peek(queue));
    puts("\n");

    puts("Desenfileira o primeiro elemento da fila");
    printf("Previous First: %d", DynamicCircularQueue_dequeue(queue));
    puts("\n");

    puts("Imprime a fila depois do dequeue");
    DynamicCircularQueue_print(queue);
    puts("\n");

    printf("A fila está vazia? %d", DynamicCircularQueue_is_empty(queue));
    puts("\n");

    puts("Adiciona o elemento 4 na fila");
    DynamicCircularQueue_enqueue(queue, 4);
    DynamicCircularQueue_print(queue);
    puts("\n");

    puts("Adiciona o elemento 6 na fila");
    DynamicCircularQueue_enqueue(queue, 6);
    DynamicCircularQueue_print(queue);
    puts("\n");

    puts("Ve o primeiro elemento da fila");
    printf("First: %d", DynamicCircularQueue_peek(queue));
    puts("\n");

    puts("Desenfileira o primeiro elemento da fila");
    printf("Previous First: %d", DynamicCircularQueue_dequeue(queue));
    puts("\n");

    puts("Imprime a fila depois do dequeue");
    DynamicCircularQueue_print(queue);
    puts("\n");

    printf("A fila está vazia? %d", DynamicCircularQueue_is_empty(queue));
    puts("\n");

    puts("Adiciona o elemento 8 na fila");
    DynamicCircularQueue_enqueue(queue, 8);
    DynamicCircularQueue_print(queue);
    puts("\n");

    puts("Adiciona o elemento 10 na fila");
    DynamicCircularQueue_enqueue(queue, 10);
    DynamicCircularQueue_print(queue);
    puts("\n");

    puts("Adiciona o elemento 12 na fila");
    DynamicCircularQueue_enqueue(queue, 12);
    DynamicCircularQueue_print(queue);
    puts("\n");

    puts("Destroi a fila");
    DynamicCircularQueue_destroy(&queue);
    printf("queue == NULL? %d\n", queue == NULL);
    return 0;
}
