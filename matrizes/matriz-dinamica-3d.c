#include <stdio.h>
#include <stdlib.h>


int main() {
    int n_slices = 2;
    int n_rows = 2;
    int n_columns = 3;

    int ***matrix = (int ***) calloc(n_slices, sizeof(int**));

    for (int k = 0; k < n_slices; k++)
    {
        matrix[k] = (int**) calloc(n_rows, sizeof(int*));

        for (int i = 0; i < n_rows; i++)
        {
            matrix[k][i] = (int*) calloc(n_columns, sizeof(int));
        }
    }

    int count = 1;

    printf("&matrix = %p, matrix = %p\n\n", &matrix, matrix);

    for (int k = 0; k < n_slices; k++)
    {
        printf("&matrix[%d] = %p, matrix[%d] = %p\n",
                k, &matrix[k],
                k, matrix[k]
            );
        
        for (int i = 0; i < n_rows; i++)
        {
            printf("&matrix[%d][%d] = %p, matrix[%d][%d] = %p\n",
                k, i, &matrix[k][i],
                k, i, matrix[k][i]
            );

            for (int j = 0; j < n_columns; j++)
            {
                matrix[k][i][j] = count++;

                printf(
                    "&matrix[%d][%d][%d] = %p, matrix[%d][%d][%d] = %d\n",
                    k, i, j, &matrix[k][i][j],
                    k, i, j, matrix[k][i][j]
                );
            }
            puts("");
        }
        puts("");
    }

    for (int k = 0; k < n_slices; k++)
    {
        for (int i = 0; i < n_rows; i++)
        {
            free(matrix[k][i]);
        }
        free(matrix[k]);
    }
    free(matrix);
    matrix = NULL;

    return 0;
}
