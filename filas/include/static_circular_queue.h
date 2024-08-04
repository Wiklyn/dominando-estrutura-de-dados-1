#ifndef STATIC_CIRCULAR_QUEUE_H
#define STATIC_CIRCULAR_QUEUE_H


#include <stdbool.h>

typedef struct _static_circular_queue StaticCircularQueue;

StaticCircularQueue *StaticCircularQueue_create(long capacity);
void StaticCircularQueue_destroy(StaticCircularQueue **queue_ref);
bool StaticCircularQueue_is_empty(const StaticCircularQueue *queue);
bool StaticCircularQueue_is_full(const StaticCircularQueue *queue);
long StaticCircularQueue_size(const StaticCircularQueue *queue);
void StaticCircularQueue_enqueue(StaticCircularQueue *queue, int value);
int StaticCircularQueue_peek(const StaticCircularQueue *queue);
int StaticCircularQueue_dequeue(StaticCircularQueue *queue);
void StaticCircularQueue_print(const StaticCircularQueue *queue);


#endif
