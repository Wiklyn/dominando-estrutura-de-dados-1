#include "linked_list.h"
#include <stdio.h>

int main() {
    LinkedList *list = LinkedList_create();

    puts("Mostra que a lista está vazia");
    LinkedList_print(list);
    puts("");

    puts("Tenta remover o elemento 45 da lista vazia");
    LinkedList_remove(list, 45);
    LinkedList_print(list);
    puts("\n");


    puts("Adiciona o elemento 2 na cabeca da lista");
    LinkedList_add_first(list, 2);
    LinkedList_print(list);
    puts("");

    puts("Remove o elemento 2 da lista");
    LinkedList_remove(list, 2);
    LinkedList_print(list);
    puts("\n");


    puts("Adiciona o elemento 8 na cabeca da lista");
    LinkedList_add_first(list, 8);
    LinkedList_print(list);
    puts("");

    puts("Adiciona o elemento 16 na cabeca da lista");
    LinkedList_add_first(list, 16);
    LinkedList_print(list);
    puts("");

    puts("Adiciona o elemento 32 na cabeca da lista");
    LinkedList_add_first(list, 32);
    LinkedList_print(list);
    puts("");

    puts("Adiciona o elemento 4 na cauda da lista");
    LinkedList_add_last(list, 4);
    LinkedList_print(list);
    puts("");

    puts("Adiciona o elemento 2 na cauda da lista");
    LinkedList_add_last(list, 2);
    LinkedList_print(list);
    puts("\n");

    puts("Remove o primeiro elemento da lista (32)");
    LinkedList_remove(list, 32);
    LinkedList_print(list);
    puts("");

    puts("Remove o último elemento da lista (2)");
    LinkedList_remove(list, 2);
    LinkedList_print(list);
    puts("");

    puts("Remove o elemento 8 da lista");
    LinkedList_remove(list, 8);
    LinkedList_print(list);
    puts("\n");


    puts("Adiciona o elemento 32 na cabeca da lista");
    LinkedList_add_first(list, 32);
    LinkedList_print(list);
    puts("");

    puts("Adiciona o elemento 16 na cauda da lista");
    LinkedList_add_last(list, 16);
    LinkedList_print(list);
    puts("");

    puts("Remove o primeiro elemento 16 encontrado da lista");
    LinkedList_remove(list, 16);
    LinkedList_print(list);
    puts("\n");

    puts("Retorna o primeiro elemento da lista");
    printf("Primeiro elemento: %d\n", LinkedList_first_val(list));
    puts("");

    puts("Retorna o último elemento da lista");
    printf("Último elemento: %d\n", LinkedList_last_val(list));
    puts("");

    puts("Retorna o elemento no index 1 da lista");
    printf("list[1]: %d\n", LinkedList_get_val(list, 1));
    puts("");

    puts("Destrói a lista");
    LinkedList_destroy(&list);
    printf("list == NULL? %d\n", list == NULL);
}