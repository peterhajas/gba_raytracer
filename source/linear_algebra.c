#include "linear_algebra.h"
#include "trig.h"
#include "generic_types.h"
#include "fastmath.h"

// Initializers
vector new_vector(float x, float y, float z)
{
	vector vec;
	vec.x = x;
	vec.y = y;
	vec.z = z;
	return vec;
}

// Vector operations

float dot_product(vector a, vector b)
{
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

vector cross_product(vector a, vector b)
{
	float x = a.y * b.z - a.z * b.y;
	float y = a.z * b.x - a.x * b.z;
	float z = a.x * b.y - a.y * b.x;

	return new_vector(x,y,z);
}

vector add_vectors(vector a, vector b)
{
	return new_vector(a.x + b.x, a.y + b.y, a.z + b.z);
}

vector subtract_vectors(vector a, vector b)
{
	return(add_vectors(a, negate_vector(b)));
}

vector vector_times_scalar(vector v, float s)
{
	return new_vector(v.x * s, v.y * s, v.z * s);
}

vector negate_vector(vector v)
{
	return vector_times_scalar(v, -1.0);
}

float magnitude_of_vector(vector v)
{
	return fast_sqrt(square_of_magnitude_of_vector(v));
}

vector unit_vector_of_vector(vector v)
{

}

float square_of_magnitude_of_vector(vector v)
{
	float magnitude = 0.0;
	magnitude += v.x * v.x;
	magnitude += v.y * v.y;
	magnitude += v.z * v.z;
	return magnitude;
}

// Matrix operations
matrix add_matrices(matrix a, matrix b)
{
	matrix sum;

	int i,j;

	for(i = 0; i < matrix_dimension; i++)
	{
		for(j = 0; j < matrix_dimension; j++)
		{
			sum.data[i][j] = a.data[i][j] + b.data[i][j];
		}
	}

	return sum;
}

matrix subtract_matrices(matrix a, matrix b)
{
	return add_matrices(a, matrix_times_scalar(b, -1.0));
}

matrix multiply_matrices(matrix a, matrix b)
{
	matrix result;

	int i,j,k;

	for(i = 0; i < matrix_dimension; i++)
	{
		for(j = 0; j < matrix_dimension; j++)
		{
			float sum = 0;

			for(k = 0; k < matrix_dimension; k++)
			{
				sum += a.data[i][k] * b.data[k][j];
			}

			result.data[i][j] = sum;
		}
	}

	return result;
}

matrix matrix_times_scalar(matrix m, float s)
{
	matrix result;

	int i,j;

	for(i = 0; i < matrix_dimension; i++)
	{
		for(j = 0; j < matrix_dimension; j++)
		{
			result.data[i][j] = m.data[i][j] * s;
		}
	}

	return result;
}

float determinant_of_matrix_3_by_3(matrix m)
{
	float a = m.data[0][0];
	float b = m.data[0][1];
	float c = m.data[0][2];
	float d = m.data[1][0];
	float e = m.data[1][1];
	float f = m.data[1][2];
	float g = m.data[2][0];
	float h = m.data[2][1];
	float i = m.data[2][2];

	a = a * (e * i - f * h);
	b = b * (d * i - f * g);
	c = c * (d * h - e * g);

	return a - b + c;
}

float determinant_of_matrix(matrix x)
{
	float a = x.data[0][0];
	float b = x.data[0][1];
	float c = x.data[0][2];
	float d = x.data[0][3];
	float e = x.data[1][0];
	float f = x.data[1][1];
	float g = x.data[1][2];
	float h = x.data[1][3];
	float i = x.data[2][0];
	float j = x.data[2][1];
	float k = x.data[2][2];
	float l = x.data[2][3];
	float m = x.data[3][0];
	float n = x.data[3][1];
	float o = x.data[3][2];
	float p = x.data[3][3];

	matrix a_m = identity_matrix();
	matrix b_m = identity_matrix();
	matrix c_m = identity_matrix();
	matrix d_m = identity_matrix();

	a_m.data[0][0] = f;
	a_m.data[0][1] = g;
	a_m.data[0][2] = h;
	a_m.data[1][0] = i;
	a_m.data[1][1] = k;
	a_m.data[1][2] = l;
	a_m.data[2][0] = n;
	a_m.data[2][1] = o;
	a_m.data[2][2] = p;

	b_m.data[0][0] = e;
	b_m.data[0][1] = g;
	b_m.data[0][2] = h;
	b_m.data[1][0] = i;
	b_m.data[1][1] = k;
	b_m.data[1][2] = l;
	b_m.data[2][0] = m;
	b_m.data[2][1] = o;
	b_m.data[2][2] = p;

	c_m.data[0][0] = e;
	c_m.data[0][1] = f;
	c_m.data[0][2] = h;
	c_m.data[1][0] = i;
	c_m.data[1][1] = j;
	c_m.data[1][2] = l;
	c_m.data[2][0] = m;
	c_m.data[2][1] = n;
	c_m.data[2][2] = p;

	d_m.data[0][0] = e;
	d_m.data[0][1] = f;
	d_m.data[0][2] = g;
	d_m.data[1][0] = i;
	d_m.data[1][1] = j;
	d_m.data[1][2] = k;
	d_m.data[2][0] = m;
	d_m.data[2][1] = n;
	d_m.data[2][2] = o;

	a = a * determinant_of_matrix_3_by_3(a_m);
	b = b * determinant_of_matrix_3_by_3(b_m);
	c = c * determinant_of_matrix_3_by_3(c_m);
	d = d * determinant_of_matrix_3_by_3(d_m);

	return a - b + c - d;
}

matrix inverse_of_matrix(matrix m)
{

}

// Vector and matrix operations

vector multiply_matrix_and_vector_position(matrix m, vector p)
{
	vector result;

	result.x = m.data[0][0]*p.x + m.data[0][1]*p.y + m.data[0][2]*p.z + m.data[0][3];
	result.y = m.data[1][0]*p.x + m.data[1][1]*p.y + m.data[1][2]*p.z + m.data[1][3];
	result.z = m.data[2][0]*p.x + m.data[2][1]*p.y + m.data[2][2]*p.z + m.data[2][3];

	return result;
}

vector multiply_matrix_and_vector_direction(matrix m, vector d)
{
	vector result;

	result.x = m.data[0][0]*d.x + m.data[0][1]*d.y + m.data[0][2]*d.z;
	result.x = m.data[1][0]*d.x + m.data[1][1]*d.y + m.data[1][2]*d.z;
	result.x = m.data[2][0]*d.x + m.data[2][1]*d.y + m.data[2][2]*d.z;

	return result;
}

vector transform_point(matrix m, vector p)
{
	return multiply_matrix_and_vector_position(m,p);
}

vector transform_ray(matrix m, vector d)
{
	return multiply_matrix_and_vector_direction(m,d);
}

vector transform_normal(matrix m, vector n)
{
	vector result;
	matrix i = inverse_of_matrix(m);

	result.x = n.x*i.data[0][0] + n.y*i.data[1][0] + n.z*i.data[2][0];
	result.y = n.x*i.data[0][1] + n.y*i.data[1][1] + n.z*i.data[2][1];
	result.z = n.x*i.data[0][2] + n.y*i.data[1][2] + n.z*i.data[2][2];

	return result;
}

// Common matrices

matrix identity_matrix()
{
	matrix result;

	result.data[0][0] = 1;
	result.data[0][1] = 0;
	result.data[0][2] = 0;
	result.data[0][3] = 0;
	result.data[1][0] = 0;
	result.data[1][1] = 1;
	result.data[1][2] = 0;
	result.data[1][3] = 0;
	result.data[2][0] = 0;
	result.data[2][1] = 0;
	result.data[2][2] = 1;
	result.data[2][3] = 0;
	result.data[3][0] = 0;
	result.data[3][1] = 0;
	result.data[3][2] = 0;
	result.data[3][3] = 1;

	return result;
}

matrix translation_matrix(vector v)
{
	matrix result;

	result.data[0][0] = 1;
	result.data[0][1] = 0;
	result.data[0][2] = 0;
	result.data[0][3] = v.x;
	result.data[1][0] = 0;
	result.data[1][1] = 1;
	result.data[1][2] = 0;
	result.data[1][3] = v.y;
	result.data[2][0] = 0;
	result.data[2][1] = 0;
	result.data[2][2] = 1;
	result.data[2][3] = v.z;
	result.data[3][0] = 0;
	result.data[3][1] = 0;
	result.data[3][2] = 0;
	result.data[3][3] = 1;

	return result;
}

matrix x_rotation_matrix(float theta)
{
	matrix result = identity_matrix();

	result.data[1][1] = fast_cos(-1 * theta);
	result.data[1][2] = -1 * fast_sin(-1 * theta);
	result.data[2][1] = fast_sin(-1 * theta);
	result.data[2][2] = fast_cos(-1 * theta);

	return result;
}

matrix y_rotation_matrix(float theta)
{
	matrix result = identity_matrix();

	result.data[0][0] = fast_cos(-1 * theta);
	result.data[0][2] = fast_sin(-1 * theta);
	result.data[2][0] = -1 * fast_sin(-1 * theta);
	result.data[2][2] = fast_cos(-1 * theta);

	return result;
}

matrix z_rotation_matrix(float theta)
{
	matrix result = identity_matrix();

	result.data[0][0] = fast_cos(-1 * theta);
	result.data[0][1] = -1 * fast_sin(-1 * theta);
	result.data[1][0] = fast_sin(-1 * theta);
	result.data[1][1] = fast_cos(-1 * theta);

	return result;
}

bool float_equals(float a, float b)
{
	float diff = a - b;
	if(diff < 0)
	{
		diff = -1 * diff;
	}

	if(diff < 0.001)
	{
		return true;
	}
	return false;
}

bool float_is_zero(float f)
{
	return(float_equals(f, 0.0));
}

matrix rotation_matrix(vector theta)
{
	float x = theta.x;
	float y = theta.y;
	float z = theta.z;

	bool did_rotate_x = false;
	bool did_rotate_y = false;
	bool did_rotate_z = false;

	matrix x_rotation;
	matrix y_rotation;
	matrix z_rotation;

	matrix rotation = identity_matrix();

	if(!float_is_zero(x))
	{
		x_rotation = x_rotation_matrix(x);
		did_rotate_x = true;
	}
	if(!float_is_zero(y))
	{
		y_rotation = y_rotation_matrix(y);
		did_rotate_y = true;
	}
	if(!float_is_zero(z))
	{
		z_rotation = z_rotation_matrix(y);
		did_rotate_z = true;
	}

	if(did_rotate_x)
	{
		rotation = multiply_matrices(rotation, x_rotation);
	}
	if(did_rotate_y)
	{
		rotation = multiply_matrices(rotation, y_rotation);
	}
	if(did_rotate_z)
	{
		rotation = multiply_matrices(rotation, z_rotation);
	}

	return rotation;
}

matrix scale_matrix(vector scale_vector)
{
	float x = scale_vector.x;
	float y = scale_vector.y;
	float z = scale_vector.z;

	matrix result = identity_matrix();

	result.data[0][0] = x;
	result.data[1][1] = y;
	result.data[2][2] = z;
	result.data[3][3] = 0;
	
	return result;
}
