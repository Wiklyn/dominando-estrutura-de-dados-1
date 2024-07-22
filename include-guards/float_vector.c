#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "float_vector.h"

/***************************** PRIVATE INTERFACE *****************************/

struct float_vector
{
    int capacity;
    int size;
    float *data;
};

bool _FloatVector_is_full(const FloatVector *vector)
{
    return vector->size == vector ->capacity;
}

/****************************** PUBLIC INTERFACE ******************************/

FloatVector *FloatVector_create(int capacity)
{
    FloatVector *vector = (FloatVector*) calloc(1, sizeof(FloatVector));
    vector->size = 0;
    vector->capacity = capacity;
    vector->data = (float*) calloc(capacity, sizeof(float));

    return vector;
}

void FloatVector_destroy(FloatVector **vector_ref)
{
    FloatVector *vector = *vector_ref;
    free(vector->data);
    free(vector);
    *vector_ref = NULL;
}

int FloatVector_size(const FloatVector *vector)
{
    return vector->size;
}

int FloatVector_capacity(const FloatVector *vector)
{
    return vector->capacity;
}

float FloatVector_at(const FloatVector *vector, int index)
{
    if (index < 0 || index == vector->size)
    {
        fprintf(stderr, "ERROR in 'at'\n");
        fprintf(
            stderr, "Index [%d] is out of bounds: [0, %d]\n",
            index, vector->capacity
        );
        exit(EXIT_FAILURE);
    }
    
    return vector->data[index];
}

float FloatVector_get(const FloatVector *vector, int index)
{
    return vector->data[index];
}

void FloatVector_append(FloatVector *vector, float val)
{
    if (_FloatVector_is_full(vector))
    {
        fprintf(stderr, "ERROR in 'append'\n");
        fprintf(stderr, "Vector is full\n");
        exit(EXIT_FAILURE);
    }
    
    vector->data[vector->size] = val;
    vector->size++;
}

void FloatVector_set(FloatVector *vector, int index, float val)
{
    if (index < 0 || index == vector->size)
    {
        fprintf(stderr, "ERROR in 'at'\n");
        fprintf(
            stderr, "Index [%d] is out of bounds: [0, %d]\n",
            index, vector->capacity
        );
        exit(EXIT_FAILURE);
    }

    vector->data[index] = val;
}

void FloatVector_print(const FloatVector *vector)
{
    puts("-----------------------------");
    printf("Size: %d\n", vector->size);
    printf("Capacity: %d\n", vector->capacity);
    puts("-----------------------------");

    for (int i = 0; i < vector->size; i++)
    {
        printf("[%d] = %f\n", i, vector->data[i]);
    }
    puts("-----------------------------\n");
}
