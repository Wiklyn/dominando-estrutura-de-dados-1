#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "circular_doubly_linked_list.h"

typedef struct _circular_doubly_node
{
    int value;
    struct _circular_doubly_node *previous;
    struct _circular_doubly_node *next;
} CircularDoublyNode;

typedef struct _circular_doubly_linked_list
{
    CircularDoublyNode *begin;
    CircularDoublyNode *end;
    size_t size;
} CircularDoublyLinkedList;

CircularDoublyNode *CircularDoublyNode_create(int value)
{
    CircularDoublyNode *node = (CircularDoublyNode*) calloc(
        1, sizeof(CircularDoublyNode)
    );
    node->value = value;
    node->previous = node;
    node->next = node;

    return node;
}

void CircularDoublyNode_destroy(CircularDoublyNode **node_ref)
{
    CircularDoublyNode *node = *node_ref;
    free(node);
    *node_ref = NULL;
}

CircularDoublyLinkedList *CircularDoublyLinkedList_create()
{
    CircularDoublyLinkedList *list = (CircularDoublyLinkedList*) calloc(
        1, sizeof(CircularDoublyLinkedList)
    );
    list->begin = NULL;
    list->end = NULL;
    list->size = 0;

    return list;
}

void CircularDoublyLinkedList_destroy(CircularDoublyLinkedList **list_ref)
{
    CircularDoublyLinkedList *list = *list_ref;
    CircularDoublyNode *current_node = list->begin;
    CircularDoublyNode *aux_node = NULL;

    while (current_node != list->end)
    {
        aux_node = current_node;
        current_node = current_node->next;
        CircularDoublyNode_destroy(&aux_node);
    }

    CircularDoublyNode_destroy(&current_node);
    free(list);
    *list_ref = NULL;
}

bool CircularDoublyLinkedList_is_empty(const CircularDoublyLinkedList *list)
{
    return list->size == 0;
}

void CircularDoublyLinkedList_add_first(
    CircularDoublyLinkedList *list, int value
)
{
    CircularDoublyNode *node = CircularDoublyNode_create(value);

    if (CircularDoublyLinkedList_is_empty(list))
    {
        list->end = node;
    }
    else
    {
        node->next = list->begin;
        list->begin->previous = node;
        node->previous = list->end;
        list->end->next = node;
    }

    list->begin = node;
    list->size++;
}

void CircularDoublyLinkedList_add_last(
    CircularDoublyLinkedList *list, int value
)
{
    CircularDoublyNode *node = CircularDoublyNode_create(value);

    if (CircularDoublyLinkedList_is_empty(list))
    {
        list->begin = node;
    }
    else
    {
        list->end->next = node;
        node->previous = list->end;
        list->begin->previous = node;
        node->next = list->begin;
    }

    list->end = node;
    list->size++;
}

void CircularDoublyLinkedList_print(const CircularDoublyLinkedList *list)
{
    if (CircularDoublyLinkedList_is_empty(list))
    {
        printf("L->begin -> NULL\n");
        printf("L->end -> NULL\n");
    }
    else
    {
        CircularDoublyNode *node = list->begin;

        printf("L -> ");

        do
        {
            printf("%d -> ", node->value);
            node = node->next;
        } while (node != list->begin);

        printf("begin\n");

        printf("L->begin -> %d\n", list->begin->value);
        printf("L->end -> %d\n", list->end->value);
    }

    printf("Size: %lu\n", list->size);
}

void CircularDoublyLinkedList_inverted_print(
    const CircularDoublyLinkedList *list
)
{
    if (CircularDoublyLinkedList_is_empty(list))
    {
        printf("L->begin -> NULL\n");
        printf("L->end -> NULL\n");
    }
    else
    {
        CircularDoublyNode *node = list->end;

        printf("L -> ");

        do
        {
            printf("%d -> ", node->value);
            node = node->previous;
        } while (node != list->end);

        printf("end\n");

        printf("L->begin -> %d\n", list->begin->value);
        printf("L->end -> %d\n", list->end->value);
    }

    printf("Size: %lu\n", list->size);
}

void CircularDoublyLinkedList_remove(CircularDoublyLinkedList *list, int value)
{
    if (!CircularDoublyLinkedList_is_empty(list))
    {
        CircularDoublyNode *current_node = list->begin;

        if (list->begin->value == value)
        {
            if (list->size == 1)
            {
                list->begin = NULL;
                list->end = NULL;
            }
            else
            {
                list->begin = current_node->next;
                current_node->previous->next = current_node->next;
                current_node->next->previous = current_node->previous;
            }

            CircularDoublyNode_destroy(&current_node);
            list->size--;
        }
        else
        {
            current_node = current_node->next;

            while (current_node != list->begin)
            {
                if (current_node->value == value)
                {
                    if (current_node == list->end)
                        list->end = current_node->previous;

                    current_node->previous->next = current_node->next;
                    current_node->next->previous = current_node->previous;

                    CircularDoublyNode_destroy(&current_node);
                    list->size--;
                    break;
                }
                else
                    current_node = current_node->next;
            }
        }
    }
}

size_t CircularDoublyLinkedList_size(const CircularDoublyLinkedList *list)
{
    return list->size;
};

int CircularDoublyLinkedList_first_val(const CircularDoublyLinkedList *list)
{
    if (CircularDoublyLinkedList_is_empty(list))
    {
        fprintf(stderr, "ERROR in 'CircularDoublyLinkedList_first_val'\n");
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }

    return list->begin->value;
};

int CircularDoublyLinkedList_last_val(const CircularDoublyLinkedList *list)
{
    if (CircularDoublyLinkedList_is_empty(list))
    {
        fprintf(stderr, "ERROR in 'CircularDoublyLinkedList_last_val'\n");
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }

    return list->end->value;
};

int CircularDoublyLinkedList_get_val(
    const CircularDoublyLinkedList *list, int index
)
{
    if (CircularDoublyLinkedList_is_empty(list))
    {
        fprintf(stderr, "ERROR in 'CircularDoublyLinkedList_get_val'\n");
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }
    else if (index < 0 || index > list->size - 1)
    {
        fprintf(stderr, "ERROR in 'CircularDoublyLinkedList_get_val'\n");
        fprintf(stderr, "Invalid Index: %d\n", index);
        fprintf(stderr, "Try an index within [0, %lu]:\n", list->size -1);
        exit(EXIT_FAILURE);
    }

    CircularDoublyNode *node = list->begin;

    for (int i = 0; i != index; i++)
        node = node->next;
    
    return node->value;
}
