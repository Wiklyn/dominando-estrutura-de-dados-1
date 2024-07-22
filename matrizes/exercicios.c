#include <stdio.h>
#include <stdlib.h>

int **create_int_matrix(int n_rows, int n_columns) {
    int **matrix = (int**) calloc(n_rows, sizeof(int*));

    for (int i = 0; i < n_rows; i++)
    {
        matrix[i] = (int*) calloc(n_columns, sizeof(int));
    }

    return matrix;
}

void print_int_matrix(const int **matrix, int n_rows, int n_columns) {
    printf("&matrix = %p, matrix = %p\n\n", &matrix, matrix);

    for (int i = 0; i < n_rows; i++)
    {
        printf("&matrix[%d] = %p, matrix[%d] = %p\n",
            i, &matrix[i],
            i, matrix[i]
        );

        for (int j = 0; j < n_columns; j++)
        {
            printf(
                "&matrix[%d][%d] = %p, matrix[%d][%d] = %d\n",
                i, j, &matrix[i][j],
                i, j, matrix[i][j]
            );
        }
        puts("");
    }
}

void add_scalar_to_int_matrix(
    int scalar, int **matrix, int n_rows, int n_columns
) {
    for (int i = 0; i < n_rows; i++)
    {
        for (int j = 0; j < n_columns; j++)
        {
            matrix[i][j] += scalar;
        }
    }
}

void destroy_int_matrix(int ***matrix, int n_rows) {
    int **aux = *matrix;

    for (int i = 0; i < n_rows; i++)
    {
        free(aux[i]);
    }
    free(aux);
    *matrix = NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 4)
    {
        printf("ERROR\n%s n_rows n_columns scalar\n", argv[0]);
        exit(-1);
    }

    int n_rows = atoi(argv[1]);
    int n_columns = atoi(argv[2]);
    int scalar = atoi(argv[3]);
    
    int **matrix = create_int_matrix(n_rows, n_columns);

    int count = 1;

    for (int i = 0; i < n_rows; i++)
    {
        for (int j = 0; j < n_columns; j++)
        {
            matrix[i][j] += count++;
        }
    }

    print_int_matrix((const int **) matrix, n_rows, n_columns);
    
    add_scalar_to_int_matrix(scalar, matrix, n_rows, n_columns);

    print_int_matrix((const int **) matrix, n_rows, n_columns);

    destroy_int_matrix(&matrix, n_rows);

    printf("matrix is null? %d", matrix == NULL);
}
