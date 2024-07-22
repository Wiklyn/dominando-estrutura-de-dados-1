#include "float_vector.h"

int main()
{
    FloatVector *vector = FloatVector_create(10);

    FloatVector_append(vector, 1.2);
    FloatVector_append(vector, 2.2);
    FloatVector_append(vector, 3.2);
    FloatVector_print(vector);

    FloatVector_destroy(&vector);
    return 0;
}
