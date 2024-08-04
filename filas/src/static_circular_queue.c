#include "static_circular_queue.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct _static_circular_queue
{
    int *data;
    long capacity;
    long size;
    long begin;
    long end;
} StaticCircularQueue;

StaticCircularQueue *StaticCircularQueue_create(long capacity)
{
    StaticCircularQueue *queue = (StaticCircularQueue*) calloc(
        1, sizeof(StaticCircularQueue)
    );
    queue->capacity = capacity;
    queue->size = 0;
    queue->begin = 0;
    queue->end = 0;
    queue->data = (int*) calloc(queue->capacity, sizeof(int));

    return queue;
}

void StaticCircularQueue_destroy(StaticCircularQueue **queue_ref)
{
    StaticCircularQueue *queue = *queue_ref;
    free(queue->data);
    free(queue);
    *queue_ref = NULL;
}

bool StaticCircularQueue_is_empty(const StaticCircularQueue *queue)
{
    return queue->size == 0;
}

bool StaticCircularQueue_is_full(const StaticCircularQueue *queue)
{
    return queue->size == queue->capacity;
}

long StaticCircularQueue_size(const StaticCircularQueue *queue)
{
    return queue->size;
}

void StaticCircularQueue_enqueue(StaticCircularQueue *queue, int value)
{
    if (StaticCircularQueue_is_full(queue))
    {
        fprintf(stderr, "ERROR in 'StaticCircularQueue_enqueue'\n");
        fprintf(stderr, "Queue is full\n");
        exit(EXIT_FAILURE);
    }

    queue->data[queue->end] = value;
    queue->end = (queue->end + 1) % queue->capacity;
    queue->size++;
}

int StaticCircularQueue_peek(const StaticCircularQueue *queue)
{
    if (StaticCircularQueue_is_empty(queue))
    {
        fprintf(stderr, "ERROR in 'StaticCircularQueue_peek'\n");
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }

    return queue->data[queue->begin];
}

int StaticCircularQueue_dequeue(StaticCircularQueue *queue)
{
    if (StaticCircularQueue_is_empty(queue))
    {
        fprintf(stderr, "ERROR in 'StaticCircularQueue_dequeue'\n");
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }

    int first_value = queue->data[queue->begin];
    queue->begin = (queue->begin + 1) % queue->capacity;
    queue->size--;

    return first_value;
}

void StaticCircularQueue_print(const StaticCircularQueue *queue)
{
    printf("Capacity: %ld\n", queue->capacity);
    printf("Size: %ld\n", queue->size);
    printf("Begin Index: %ld\n", queue->begin);
    printf("End Index: %ld\n", queue->end);
    printf("Data: ");

    long s, i;

    for (
        s = 0, i = queue->begin;
        s < queue->size;
        s++, i = (i + 1) % queue->capacity
    )
    {
        printf("%d", queue->data[i]);

        if (s < queue->size - 1)
            printf(", ");
    }
}
