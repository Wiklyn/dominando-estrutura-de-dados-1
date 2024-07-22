#ifndef FLOAT_VECTOR_H
#define FLOAT_VECTOR_H


#include "dummy.h"

typedef struct float_vector FloatVector;

FloatVector *FloatVector_create(int capacity);
void FloatVector_destroy(FloatVector **vector_ref);
int FloatVector_size(const FloatVector *vector);
int FloatVector_capacity(const FloatVector *vector);
float FloatVector_at(const FloatVector *vector, int index);
float FloatVector_get(const FloatVector *vector, int index);
void FloatVector_append(FloatVector *vector, float val);
void FloatVector_set(FloatVector *vector, int index, float val);
void FloatVector_print(const FloatVector *vector);


#endif
