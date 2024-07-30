#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _simple_node
{
    int val;
    struct _simple_node *next;
} SimpleNode;

typedef struct _linked_list
{
    SimpleNode *begin;
    SimpleNode *end;
    size_t size;
} LinkedList;

SimpleNode *SimpleNode_create(int val)
{
    SimpleNode *node = (SimpleNode*) calloc(1, sizeof(SimpleNode));
    node->val = val;
    node->next = NULL;

    return node;
}

LinkedList *LinkedList_create()
{
    LinkedList *list = (LinkedList*) calloc(1, sizeof(LinkedList));
    list->begin = NULL;
    list->end = NULL;
    list->size = 0;

    return list;
}

void LinkedList_destroy(LinkedList **list_ref)
{
    LinkedList *list = *list_ref;
    SimpleNode *current_node = list->begin;
    SimpleNode *aux_pointer = NULL;

    while (current_node != NULL)
    {
        aux_pointer = current_node;
        current_node = current_node->next;
        free(aux_pointer);
    }
    
    free(list);
    *list_ref = NULL;
}

bool LinkedList_is_empty(const LinkedList *list)
{
    return list->size == 0;
}

void LinkedList_add_first(LinkedList *list, int val)
{
    SimpleNode *node = SimpleNode_create(val);
    node->next = list->begin;
    
    if (LinkedList_is_empty(list))
        list->end = node;
    
    list->begin = node;
    list->size++;
}

void LinkedList_add_last(LinkedList *list, int val)
{
    SimpleNode *new_node = SimpleNode_create(val);

    if (LinkedList_is_empty(list))
    {
        list->begin = new_node;
        list->end = new_node;
    }
    else
    {
        list->end->next = new_node;
        list->end = new_node;
    }

    list->size++;
}

void LinkedList_print(const LinkedList *list)
{
    SimpleNode *node = list->begin;

    printf("L -> ");

    while (node != NULL)
    {
        printf("%d -> ",node->val);
        node = node->next;
    }

    printf("NULL\n");

    if (list->end == NULL)
    {
        printf("list->end = NULL\n");
    }
    else
    {
        printf("list->end = %d\n", list->end->val);
    }

    printf("Size: %lu\n", list->size);
}

void LinkedList_remove(LinkedList *list, int val)
{
    if (!LinkedList_is_empty(list))
    {
        SimpleNode *previous_node = NULL;
        SimpleNode *current_node = list->begin;

        while (current_node != NULL && current_node->val != val)
        {
            previous_node = current_node;
            current_node = current_node->next;
        }
        
        if (current_node != NULL)
        {
            if (list->end == current_node)
                list->end = previous_node;
            
            if (list->begin == current_node)
                list->begin = current_node->next;
            else
                previous_node->next = current_node->next;
            
            free(current_node);
            list->size--;
        }
    }
}

size_t LinkedList_size(const LinkedList *list)
{
    return list->size;
}

int LinkedList_first_val(const LinkedList *list)
{
    if (LinkedList_is_empty(list))
    {
        fprintf(stderr, "ERROR in 'LinkedList_first_node'\n");
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }

    return list->begin->val;
}

int LinkedList_last_val(const LinkedList *list)
{
    if (LinkedList_is_empty(list))
    {
        fprintf(stderr, "ERROR in 'LinkedList_last_val'\n");
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }

    return list->end->val;
}

int LinkedList_get_val(const LinkedList *list, int index)
{
    if (LinkedList_is_empty(list))
    {
        fprintf(stderr, "ERROR in 'LinkedList_get_val'\n");
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }
    else if (index < 0 || index >= list->size)
    {
        fprintf(stderr, "ERROR in 'LinkedList_get_val'\n");
        fprintf(stderr, "Invalid Index: %d\n", index);
        fprintf(stderr, "Try an index within [0, %lu]:\n", list->size);
        exit(EXIT_FAILURE);
    }

    SimpleNode *node = list->begin;

    for (int i = 0; i != index; i++)
        node = node->next;

    return node->val;
}
