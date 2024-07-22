#include <stdio.h>

#define N_ROWS 2
#define N_COLS 3

int main() {
    int matrix[N_ROWS][N_COLS] = {{1, 2, 3}, {4, 5, 6}};

    printf("$matrix = %p, m = %p\n\n", &matrix, matrix);

    for (int i = 0; i < N_ROWS; i++)
    {
        for (int j = 0; j < N_COLS; j++)
        {
            printf(
                "&matrix[%d][%d] = %p, matrix[%d][%d] = %d\n",
                i, j, &matrix[i][j],
                i, j, matrix[i][j]
            );
        }
        puts("");
    }
    
    return 0;
}
