#ifndef DYNAMIC_CIRCULAR_QUEUE_H
#define DYNAMIC_CIRCULAR_QUEUE_H


#include <stdbool.h>
#include <stddef.h>

typedef struct _dynamic_circular_queue DynamicCircularQueue;

DynamicCircularQueue *DynamicCircularQueue_create();
void DynamicCircularQueue_destroy(DynamicCircularQueue **queue_ref);
bool DynamicCircularQueue_is_empty(const DynamicCircularQueue *queue);
size_t DynamicCircularQueue_size(const DynamicCircularQueue *queue);
void DynamicCircularQueue_enqueue(DynamicCircularQueue *queue, int value);
int DynamicCircularQueue_peek(const DynamicCircularQueue *queue);
int DynamicCircularQueue_dequeue(DynamicCircularQueue *queue);
void DynamicCircularQueue_print(const DynamicCircularQueue *queue);


#endif
