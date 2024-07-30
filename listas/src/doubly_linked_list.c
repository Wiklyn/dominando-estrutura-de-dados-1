#include "doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _doubly_node
{
    int value;
    struct _doubly_node *next;
    struct _doubly_node *previous;
} DoublyNode;

typedef struct _doubly_linked_list
{
    DoublyNode *begin;
    DoublyNode *end;
    size_t size;
} DoublyLinkedList;

DoublyNode *DoublyNode_create(int value)
{
    DoublyNode *node = (DoublyNode*) calloc(1, sizeof(DoublyNode));
    node->value = value;
    node->previous = NULL;
    node->next = NULL;

    return node;
}

DoublyLinkedList *DoublyLinkedList_create()
{
    DoublyLinkedList *list = (DoublyLinkedList*) calloc(
        1, sizeof(DoublyLinkedList)
    );
    list->begin = NULL;
    list->end = NULL;
    list->size = 0;

    return list;
}

void DoublyLinkedList_destroy(DoublyLinkedList **list_ref)
{
    DoublyLinkedList *list = *list_ref;
    DoublyNode *current_node = list->begin;
    DoublyNode *aux_pointer = NULL;

    while (current_node != NULL)
    {
        aux_pointer = current_node;
        current_node = current_node->next;
        free(aux_pointer);
    }
    
    free(list);
    *list_ref = NULL;
}

bool DoublyLinkedList_is_empty(const DoublyLinkedList *list)
{
    return list->size == 0;
}

void DoublyLinkedList_add_first(DoublyLinkedList *list, int val)
{
    DoublyNode *new_node = DoublyNode_create(val);
    new_node->next = list->begin;
    
    if (DoublyLinkedList_is_empty(list))
        list->end = new_node;
    else
        list->begin->previous = new_node;
    
    list->begin = new_node;
    list->size++;
}

void DoublyLinkedList_add_last(DoublyLinkedList *list, int value)
{
    DoublyNode *new_node = DoublyNode_create(value);

    if (DoublyLinkedList_is_empty(list))
        list->begin = new_node;
    else
    {
        new_node->previous = list->end;
        list->end->next = new_node;
    }

    list->end = new_node;
    list->size++;
}

void DoublyLinkedList_print(const DoublyLinkedList *list)
{
    DoublyNode *node = list->begin;

    printf("L -> ");

    while (node != NULL)
    {
        printf("%d -> ",node->value);
        node = node->next;
    }

    printf("NULL\n");

    if (list->end == NULL)
    {
        printf("list->end = NULL\n");
    }
    else
    {
        printf("list->end = %d\n", list->end->value);
    }

    printf("Size: %lu\n", list->size);
}

void DoublyLinkedList_inverted_print(const DoublyLinkedList *list)
{
    DoublyNode *node = list->end;

    printf("L -> ");

    while (node != NULL)
    {
        printf("%d -> ",node->value);
        node = node->previous;
    }

    printf("NULL\n");

    if (list->begin == NULL)
    {
        printf("list->begin = NULL\n");
    }
    else
    {
        printf("list->begin = %d\n", list->begin->value);
    }

    printf("Size: %lu\n", list->size);
}

void DoublyLinkedList_remove(DoublyLinkedList *list, int value)
{
    if (!DoublyLinkedList_is_empty(list))
    {
        DoublyNode *current_node = NULL;
        
        if (list->begin->value == value)
        {
            current_node = list->begin;
            list->begin = current_node->next;

            if (list->size == 1)
                list->end = NULL;
            else
                list->begin->previous = NULL;
        }
        else if (list->end->value == value)
        {
            current_node = list->end;
            list->end = current_node->previous;
            current_node->previous->next = NULL;
        }
        else
        {
            current_node = list->begin->next;

            while (current_node->value != value)
            {
                current_node = current_node->next;
            }
            
            current_node->previous->next = current_node->next;
            current_node->next->previous = current_node->previous;
        }

        free(current_node);
        list->size--;
    }
}

size_t DoublyLinkedList_size(const DoublyLinkedList *list)
{
    return list->size;
}

int DoublyLinkedList_first_val(const DoublyLinkedList *list)
{
    if (DoublyLinkedList_is_empty(list))
    {
        fprintf(stderr, "ERROR in 'DoublyLinkedList_is_empty'\n");
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }
    
    return list->begin->value;
}

int DoublyLinkedList_last_val(const DoublyLinkedList *list)
{
    if (DoublyLinkedList_is_empty(list))
    {
        fprintf(stderr, "ERROR in 'DoublyLinkedList_last_val'\n");
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }
    
    return list->end->value;
}

int DoublyLinkedList_get_val(const DoublyLinkedList *list, int index)
{
    if (DoublyLinkedList_is_empty(list))
    {
        fprintf(stderr, "ERROR in 'DoublyLinkedList_get_val'\n");
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }
    else if (index < 0 || index > list->size - 1)
    {
        fprintf(stderr, "ERROR in 'DoublyLinkedList_get_val'\n");
        fprintf(stderr, "Invalid Index: %d\n", index);
        fprintf(stderr, "Try an index within [0, %lu]:\n", list->size -1);
        exit(EXIT_FAILURE);
    }

    DoublyNode *node = list->begin;

    for (int i = 0; i != index; i++)
        node = node->next;
    
    return node->value;    
}
