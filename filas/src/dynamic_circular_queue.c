#include "dynamic_circular_queue.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct _queue_node
{
    int value;
    struct _queue_node *next;
    struct _queue_node *previous;
} QueueNode;

typedef struct _dynamic_circular_queue
{
    QueueNode *begin;
    QueueNode *end;
    size_t size;
} DynamicCircularQueue;

QueueNode *QueueNode_create(int value)
{
    QueueNode *node = (QueueNode*) calloc(1, sizeof(QueueNode));
    node->value = value;
    node->previous = NULL;
    node->next = NULL;

    return node;
}

DynamicCircularQueue *DynamicCircularQueue_create()
{
    DynamicCircularQueue *queue = (DynamicCircularQueue*) calloc(
        1, sizeof(DynamicCircularQueue)
    );
    queue->begin = NULL;
    queue->end = NULL;
    queue->size = 0;

    return queue;
}

void DynamicCircularQueue_destroy(DynamicCircularQueue **queue_ref)
{
    DynamicCircularQueue *queue = *queue_ref;
    QueueNode *current_node = queue->begin;
    QueueNode *aux_pointer = NULL;

    while (current_node != NULL)
    {
        aux_pointer = current_node;
        current_node = current_node->next;
        free(aux_pointer);
    }
    
    free(queue);
    *queue_ref = NULL;
}

bool DynamicCircularQueue_is_empty(const DynamicCircularQueue *queue)
{
    return queue->size == 0;
}

size_t DynamicCircularQueue_size(const DynamicCircularQueue *queue)
{
    return queue->size;
}

void DynamicCircularQueue_enqueue(DynamicCircularQueue *queue, int value)
{
    QueueNode *new_node = QueueNode_create(value);

    if (DynamicCircularQueue_is_empty(queue))
        queue->begin = new_node;
    else
    {
        new_node->previous = queue->end;
        queue->end->next = new_node;
    }

    queue->end = new_node;
    queue->size++;
}

int DynamicCircularQueue_peek(const DynamicCircularQueue *queue)
{
    if (DynamicCircularQueue_is_empty(queue))
    {
        fprintf(stderr, "ERROR in 'DynamicCircularQueue_peek'\n");
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }

    return queue->begin->value;
}

int DynamicCircularQueue_dequeue(DynamicCircularQueue *queue)
{
    if (DynamicCircularQueue_is_empty(queue))
    {
        fprintf(stderr, "ERROR in 'DynamicCircularQueue_dequeue'\n");
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }

    int first_value = queue->begin->value;

    QueueNode *current_node = queue->begin;

    if (DynamicCircularQueue_size(queue) == 1)
    {
        queue->begin = NULL;
        queue->end = NULL;
    }
    else
    {
        queue->begin = current_node->next;
        current_node->next->previous = NULL;
    }

    free(current_node);
    queue->size--;

    return first_value;
}

void DynamicCircularQueue_print(const DynamicCircularQueue *queue)
{
    QueueNode *node = queue->begin;

    size_t size = DynamicCircularQueue_size(queue);

    printf("Size: %ld\n", queue->size);

    if (size == 0)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Begin: %d\n", queue->begin->value);
        printf("End: %d\n", queue->end->value);
        printf("Queue: ");

        while (node->next != NULL)
        {
            printf("%d, ", node->value);
            node = node->next;
        }

        printf("%d", node->value);
    }
}
