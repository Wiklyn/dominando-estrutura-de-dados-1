#include <stdio.h>
#include <stdlib.h>

int main() {
    // Alocação de um vetor estático (memória stack)
    int v_stack[5] = {0, 10, 20, 30, 40};

    puts("### VETOR ESTATICO");
    printf("&v_stack = %p, v_stack = %d\n", &v_stack, v_stack);

    for (int i = 0; i < 5; i++)
    {
        printf(
            "&v_stack[%d] = %p, v_stack[%d] = %d\n",
            i, &v_stack[i],
            i, v_stack[i]
        );
    }
    puts("\n");

    // Alocação de um vetor dinâmico usando malloc (memória heap)
    int *v_heap_malloc = malloc(5 * sizeof(int));

    puts("### VETOR DINAMICO USANDO MALLOC");
    printf(
        "&v_heap_malloc = %p, v_heap_malloc = %p\n",
        &v_heap_malloc,
        v_heap_malloc
    );

    for (int i = 0; i < 5; i++)
    {
        printf(
            "&v_heap_malloc[%d] = %p, v_heap_malloc[%d] = %d\n",
            i, &v_heap_malloc[i],
            i, v_heap_malloc[i]
        );
    }
    puts("\n");

    // Alocação de um vetor dinâmico usando calloc (memória heap)
    int *v_heap_calloc = calloc(5, sizeof(int));

    puts("### VETOR DINAMICO USANDO CALLOC");
    printf(
        "&v_heap_calloc = %p, v_heap_malloc = %p\n",
        &v_heap_calloc,
        v_heap_calloc
    );

    for (int i = 0; i < 5; i++)
    {
        printf(
            "&v_heap_calloc[%d] = %p, v_heap_calloc[%d] = %d\n",
            i, &v_heap_calloc[i],
            i, v_heap_calloc[i]
        );
    }
    puts("\n");

    return 0;
}
