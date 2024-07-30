#include "doubly_linked_list.h"

#include <stdio.h>

int main() {
    DoublyLinkedList *list = DoublyLinkedList_create();

    puts("Mostra que a lista está vazia");
    DoublyLinkedList_print(list);
    puts("");

    puts("Tenta remover o elemento 45 da lista vazia");
    DoublyLinkedList_remove(list, 45);
    DoublyLinkedList_print(list);
    puts("\n");


    puts("Adiciona o elemento 2 na cabeca da lista");
    DoublyLinkedList_add_first(list, 2);
    DoublyLinkedList_print(list);
    puts("");

    puts("Remove o elemento 2 da lista");
    DoublyLinkedList_remove(list, 2);
    DoublyLinkedList_print(list);
    puts("\n");


    puts("Adiciona o elemento 8 na cabeca da lista");
    DoublyLinkedList_add_first(list, 8);
    DoublyLinkedList_print(list);
    puts("");

    puts("Adiciona o elemento 16 na cabeca da lista");
    DoublyLinkedList_add_first(list, 16);
    DoublyLinkedList_print(list);
    puts("");

    puts("Adiciona o elemento 32 na cabeca da lista");
    DoublyLinkedList_add_first(list, 32);
    DoublyLinkedList_print(list);
    puts("");

    puts("Adiciona o elemento 4 na cauda da lista");
    DoublyLinkedList_add_last(list, 4);
    DoublyLinkedList_print(list);
    puts("");

    puts("Adiciona o elemento 2 na cauda da lista");
    DoublyLinkedList_add_last(list, 2);
    DoublyLinkedList_print(list);
    puts("\n");

    puts("Remove elemento 32 da lista (primeiro elemento)");
    DoublyLinkedList_remove(list, 32);
    DoublyLinkedList_print(list);
    puts("");

    puts("Remove elemento 2 da lista (ultimo elemento)");
    DoublyLinkedList_remove(list, 2);
    DoublyLinkedList_print(list);
    puts("");

    puts("Remove o elemento 8 da lista");
    DoublyLinkedList_remove(list, 8);
    DoublyLinkedList_print(list);
    puts("\n");


    puts("Adiciona o elemento 32 na cabeca da lista");
    DoublyLinkedList_add_first(list, 32);
    DoublyLinkedList_print(list);
    puts("");

    puts("Adiciona o elemento 16 na cauda da lista");
    DoublyLinkedList_add_last(list, 16);
    DoublyLinkedList_print(list);
    puts("");

    puts("Adiciona o elemento 8 na cauda da lista");
    DoublyLinkedList_add_last(list, 8);
    DoublyLinkedList_print(list);
    puts("");

    puts("Remove o primeiro elemento 16 encontrado da lista");
    DoublyLinkedList_remove(list, 16);
    DoublyLinkedList_print(list);
    puts("\n");

    puts("Lista invertida");
    DoublyLinkedList_inverted_print(list);
    puts("");

    puts("Destrói a lista");
    DoublyLinkedList_destroy(&list);
    printf("list == NULL? %d\n", list == NULL);

    return 0;
}
