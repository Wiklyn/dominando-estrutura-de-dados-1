#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct _simple_node SimpleNode;
typedef struct _linked_list LinkedList;

LinkedList *LinkedList_create();
void LinkedList_destroy(LinkedList **list_ref);
bool LinkedList_is_empty(const LinkedList *list);
void LinkedList_add_first(LinkedList *list, int val);
void LinkedList_add_last(LinkedList *list, int val);
void LinkedList_print(const LinkedList *list);
void LinkedList_remove(LinkedList *list, int val);
// void LinkedList_remove_all(LinkedList *list, int val);
size_t LinkedList_size(const LinkedList *list);
int LinkedList_first_val(const LinkedList *list);
int LinkedList_last_val(const LinkedList *list);
int LinkedList_get_val(const LinkedList *list, int index);

#endif
