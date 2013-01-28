#ifndef _LINEAR_ALGEBRA_
#define _LINEAR_ALGEBRA_

typedef struct
{
	float x;
	float y;
	float z;
} vector;

#define matrix_dimension 4

typedef struct
{
    float data[matrix_dimension][matrix_dimension];
} matrix;

typedef struct
{
    vector point;
    vector direction;
} ray;

typedef struct
{
    vector position;
    // needed: pointer to intersected primitive
} intersect;

/*
 A note on matrices and storage:
 
 While I'd like it to be the case, it's simply
 *not* that matrices are referred to by [x][y],
 it's the other way round ([y][x], or [c][r]).

 This is how matrices are expressed here.
*/

// Initializers
vector new_vector(float x, float y, float z);

// Vector operations
float dot_product(vector a, vector b);
vector cross_product(vector a, vector b);
vector add_vectors(vector a, vector b);
vector subtract_vectors(vector a, vector b);
vector vector_times_scalar(vector v, float s);
vector negate_vector(vector v);
float magnitude_of_vector(vector v);
vector unit_vector_of_vector(vector v);
float square_of_magnitude_of_vector(vector v);

// Matrix operations
matrix add_matrices(matrix a, matrix b);
matrix subtract_matrices(matrix a, matrix b);
matrix multiply_matrices(matrix a, matrix b);
matrix matrix_times_scalar(matrix m, float s);
float determinant_of_matrix(matrix x);
matrix inverse_of_matrix(matrix m);

// Vector and matrix operations

vector multiply_matrix_and_vector_position(matrix m, vector p);
vector multiply_matrix_and_vector_direction(matrix m, vector d);

vector transform_point(matrix m, vector p);
vector transform_ray(matrix m, vector d);
vector transform_normal(matrix m, vector n);

// Common matrices

matrix identity_matrix();
matrix translation_matrix(vector v);
matrix rotation_matrix(vector theta);
matrix scale_matrix(vector scale_vector);

#endif