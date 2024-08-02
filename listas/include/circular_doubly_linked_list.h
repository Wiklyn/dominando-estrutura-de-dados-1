#ifndef CIRCULAR_DOUBLY_LINKED_LIST_H
#define CIRCULAR_DOUBLY_LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct _circular_doubly_node CircularDoublyNode;
typedef struct _circular_doubly_linked_list CircularDoublyLinkedList;

CircularDoublyLinkedList *CircularDoublyLinkedList_create();
void CircularDoublyLinkedList_destroy(CircularDoublyLinkedList **list_ref);
bool CircularDoublyLinkedList_is_empty(const CircularDoublyLinkedList *list);
void CircularDoublyLinkedList_add_first(CircularDoublyLinkedList *list, int value);
void CircularDoublyLinkedList_add_last(CircularDoublyLinkedList *list, int value);
void CircularDoublyLinkedList_print(const CircularDoublyLinkedList *list);
void CircularDoublyLinkedList_inverted_print(const CircularDoublyLinkedList *list);
void CircularDoublyLinkedList_remove(CircularDoublyLinkedList *list, int value);
size_t CircularDoublyLinkedList_size(const CircularDoublyLinkedList *list);
int CircularDoublyLinkedList_first_val(const CircularDoublyLinkedList *list);
int CircularDoublyLinkedList_last_val(const CircularDoublyLinkedList *list);
int CircularDoublyLinkedList_get_val(const CircularDoublyLinkedList *list, int index);


#endif
