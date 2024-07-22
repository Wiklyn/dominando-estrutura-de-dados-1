#include <stdio.h>
#include <stdlib.h>

void soma_vetor_com_escalar(int v[], int n, int escalar) {
    for (int i = 0; i < n; i++) {
        v[i] += escalar;
    }
}

void print_vetor(const int *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("&v[%d] = %p, v[%d] = %d\n", i, &v[i], i, v[i]);
    }
    puts("");
}

void desaloca_vetor(int **v) {
    free(*v);
    *v = NULL;
}

int main() {
    // Alocação de um vetor estático (memória Stack)
    puts("### VETOR ESTATICO");
    int v_stack[5] = {0, 10, 20, 30, 40};

    print_vetor(v_stack, 5);
    soma_vetor_com_escalar(v_stack, 5, 9);
    print_vetor(v_stack, 5);

    // Alocação de um vetor dinâmico com Calloc (memória Heap)
    puts("### VETOR DINAMICO COM CALLOC");
    int *v_calloc_heap = calloc(5, sizeof(int));
    for (int i = 0; i < 5; i++) {
        v_calloc_heap[i] = i * 100;
    }

    print_vetor(v_calloc_heap, 5);
    soma_vetor_com_escalar(v_calloc_heap, 5, 9);
    print_vetor(v_calloc_heap, 5);

    // Desalocação de um vetor dinâmico com Free (memória Heap)
    desaloca_vetor(&v_calloc_heap);

    return 0;
}
