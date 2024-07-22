#include <stdio.h>

#define N_SLICES 2
#define N_ROWS 2
#define N_COLUMNS 3

int main() {
    int matrix[N_SLICES][N_ROWS][N_COLUMNS] = {
        {{1, 2, 3}, {4, 5, 6}},
        {{7, 8, 9}, {10, 11, 12}}
    };

    printf("$matrix = %p, m = %p\n\n", &matrix, matrix);

    for (int k = 0; k < N_SLICES; k++)
    {
        for (int i = 0; i < N_ROWS; i++)
        {
            for (int j = 0; j < N_COLUMNS; j++)
            {
                printf(
                    "&matrix[%d][%d][%d] = %p, matrix[%d][%d][%d] = %d\n",
                    i, j, k, &matrix[k][i][j],
                    i, j, k, matrix[k][i][j]
                );
            }
            puts("");
        }
        puts("");
    }
    return 0;
}
