#include "circular_doubly_linked_list.h"

#include <stdio.h>

int main() {
    CircularDoublyLinkedList *list = CircularDoublyLinkedList_create();

    puts("Mostra que a lista está vazia");
    CircularDoublyLinkedList_print(list);
    puts("");

    puts("Tenta remover o elemento 45 da lista vazia");
    CircularDoublyLinkedList_remove(list, 45);
    CircularDoublyLinkedList_print(list);
    puts("\n");

    puts("Adiciona o elemento 2 na cabeca da lista");
    CircularDoublyLinkedList_add_first(list, 2);
    CircularDoublyLinkedList_print(list);
    puts("");

    puts("Remove o elemento 2 da lista");
    CircularDoublyLinkedList_remove(list, 2);
    CircularDoublyLinkedList_print(list);
    puts("\n");


    puts("Adiciona o elemento 8 na cabeca da lista");
    CircularDoublyLinkedList_add_first(list, 8);
    CircularDoublyLinkedList_print(list);
    puts("");

    puts("Adiciona o elemento 16 na cabeca da lista");
    CircularDoublyLinkedList_add_first(list, 16);
    CircularDoublyLinkedList_print(list);
    puts("");

    puts("Adiciona o elemento 32 na cabeca da lista");
    CircularDoublyLinkedList_add_first(list, 32);
    CircularDoublyLinkedList_print(list);
    puts("");

    puts("Adiciona o elemento 4 na cauda da lista");
    CircularDoublyLinkedList_add_last(list, 4);
    CircularDoublyLinkedList_print(list);
    puts("");

    puts("Adiciona o elemento 2 na cauda da lista");
    CircularDoublyLinkedList_add_last(list, 2);
    CircularDoublyLinkedList_print(list);
    puts("");

    puts("Remove elemento 32 da lista (primeiro elemento)");
    CircularDoublyLinkedList_remove(list, 32);
    CircularDoublyLinkedList_print(list);
    puts("");

    puts("Remove o elemento 8 da lista");
    CircularDoublyLinkedList_remove(list, 8);
    CircularDoublyLinkedList_print(list);
    puts("");

    puts("Remove elemento 2 da lista (ultimo elemento)");
    CircularDoublyLinkedList_remove(list, 2);
    CircularDoublyLinkedList_print(list);
    puts("\n");

    puts("Adiciona o elemento 8 na cauda da lista");
    CircularDoublyLinkedList_add_last(list, 8);
    CircularDoublyLinkedList_print(list);
    puts("");

    puts("Adiciona o elemento 16 na cauda da lista");
    CircularDoublyLinkedList_add_last(list, 16);
    CircularDoublyLinkedList_print(list);
    puts("");

    puts("Remove o primeiro elemento 16 encontrado da lista");
    CircularDoublyLinkedList_remove(list, 16);
    CircularDoublyLinkedList_print(list);
    puts("\n");

    puts("Adiciona o elemento 2 na cabeca da lista");
    CircularDoublyLinkedList_add_first(list, 2);
    CircularDoublyLinkedList_print(list);
    puts("");

    puts("Adiciona o elemento 32 na cauda da lista");
    CircularDoublyLinkedList_add_last(list, 32);
    CircularDoublyLinkedList_print(list);
    puts("");

    puts("Tenta remover o elemento 45 que nao existe na lista");
    CircularDoublyLinkedList_remove(list, 45);
    CircularDoublyLinkedList_print(list);
    puts("\n");

    puts("Lista:");
    CircularDoublyLinkedList_print(list);
    puts("");

    puts("Retorna o primeiro elemento da lista");
    printf("Primeiro elemento: %d\n", CircularDoublyLinkedList_first_val(list));
    puts("");

    puts("Retorna o último elemento da lista");
    printf("Último elemento: %d\n", CircularDoublyLinkedList_last_val(list));
    puts("");

    puts("Retorna o elemento no index 3 da lista");
    printf("list[3]: %d\n", CircularDoublyLinkedList_get_val(list, 3));
    puts("");

    puts("Retorna o numero de elementos da lista");
    printf("Size: %lu\n", CircularDoublyLinkedList_size(list));
    puts("\n");

    puts("Lista invertida");
    CircularDoublyLinkedList_inverted_print(list);
    puts("\n");

    puts("Destrói a lista");
    CircularDoublyLinkedList_destroy(&list);
    printf("list == NULL? %d\n", list == NULL);

    return 0;
}
