#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct _doubly_node DoublyNode;
typedef struct _doubly_linked_list DoublyLinkedList;

DoublyLinkedList *DoublyLinkedList_create();
void DoublyLinkedList_destroy(DoublyLinkedList **list_ref);
bool DoublyLinkedList_is_empty(const DoublyLinkedList *list);
void DoublyLinkedList_add_first(DoublyLinkedList *list, int value);
void DoublyLinkedList_add_last(DoublyLinkedList *list, int value);
void DoublyLinkedList_print(const DoublyLinkedList *list);
void DoublyLinkedList_inverted_print(const DoublyLinkedList *list);
void DoublyLinkedList_remove(DoublyLinkedList *list, int value);
size_t DoublyLinkedList_size(const DoublyLinkedList *list);
int DoublyLinkedList_first_val(const DoublyLinkedList *list);
int DoublyLinkedList_last_val(const DoublyLinkedList *list);
int DoublyLinkedList_get_val(const DoublyLinkedList *list, int index);


#endif