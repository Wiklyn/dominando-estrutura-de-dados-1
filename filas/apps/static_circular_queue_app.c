#include "static_circular_queue.h"

#include <stdio.h>

int main()
{
    puts("Cria uma fila\n");
    StaticCircularQueue *queue = StaticCircularQueue_create(5);

    printf("A fila está vazia? %d", StaticCircularQueue_is_empty(queue));
    puts("");

    printf("A fila está cheia? %d", StaticCircularQueue_is_full(queue));
    puts("\n");

    // puts("Tenta ver o primeiro elemento da fila vazia");
    // printf("Top: %d", StaticCircularQueue_peek(queue));

    // puts("Tenta desenfileirar o primeiro elemento da fila vazia");
    // printf("Previous Top: %d", StaticCircularQueue_dequeue(queue));

    puts("Adiciona o elemento 2 na fila");
    StaticCircularQueue_enqueue(queue, 2);
    StaticCircularQueue_print(queue);
    puts("\n");

    puts("Adiciona o elemento 4 na fila");
    StaticCircularQueue_enqueue(queue, 4);
    StaticCircularQueue_print(queue);
    puts("\n");

    puts("Adiciona o elemento 6 na fila");
    StaticCircularQueue_enqueue(queue, 6);
    StaticCircularQueue_print(queue);
    puts("\n");

    puts("Ve o primeiro elemento da fila");
    printf("First: %d", StaticCircularQueue_peek(queue));
    puts("\n");

    puts("Desenfileira o primeiro elemento da fila");
    printf("Previous First: %d", StaticCircularQueue_dequeue(queue));
    puts("\n");

    puts("Imprime a fila depois do dequeue");
    StaticCircularQueue_print(queue);
    puts("\n");

    printf("A fila está vazia? %d", StaticCircularQueue_is_empty(queue));
    puts("");

    printf("A fila está cheia? %d", StaticCircularQueue_is_full(queue));
    puts("\n");

    puts("Adiciona o elemento 8 na fila");
    StaticCircularQueue_enqueue(queue, 8);
    StaticCircularQueue_print(queue);
    puts("\n");

    puts("Adiciona o elemento 10 na fila");
    StaticCircularQueue_enqueue(queue, 10);
    StaticCircularQueue_print(queue);
    puts("\n");

    puts("Adiciona o elemento 12 na fila");
    StaticCircularQueue_enqueue(queue, 12);
    StaticCircularQueue_print(queue);
    puts("\n");

    printf("A fila está vazia? %d", StaticCircularQueue_is_empty(queue));
    puts("");

    printf("A fila está cheia? %d", StaticCircularQueue_is_full(queue));
    puts("\n");

    // puts("Tenta adicionar um elemento em uma fila cheia");
    // StaticCircularQueue_enqueue(queue, 64);

    puts("Destroi a fila");
    StaticCircularQueue_destroy(&queue);
    printf("queue == NULL? %d\n", queue == NULL);

    return 0;
}
