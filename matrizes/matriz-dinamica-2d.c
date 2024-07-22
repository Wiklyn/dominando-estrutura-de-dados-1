#include <stdio.h>
#include <stdlib.h>


int main() {
    int n_rows = 2;
    int n_cols = 3;

    int **matrix = (int **) calloc(n_rows, sizeof(int*));

    for (int i = 0; i < n_rows; i++)
    {
        matrix[i] = (int*) calloc(n_cols, sizeof(int));
    }
    
    int count = 0;

    printf("&matrix = %p, matrix = %p\n\n", &matrix, matrix);

    for (int i = 0; i < n_rows; i++)
    {
        printf("&matrix[%d] = %p, matrix[%d] = %p\n",
            i, &matrix[i],
            i, matrix[i]
        );

        for (int j = 0; j < n_cols; j++)
        {
            matrix[i][j] = count++;

            printf(
                "&matrix[%d][%d] = %p, matrix[%d][%d] = %d\n",
                i, j, &matrix[i][j],
                i, j, matrix[i][j]
            );
        }
        puts("");
    }

    for (int i = 0; i < n_rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    matrix = NULL;

    return 0;
}
