#include "sphere.h"
#include "fastmath.h"
#include "common.h"

roots intersection_with_ray(sphere s, ray r)
{
	// We need r in sphere-coordinates

	ray r_sphere_coordinates;
	matrix s_transform_inverse = inverse_of_matrix(s.transform);
	r_sphere_coordinates.point     = transform_point(s_transform_inverse, r.point);
	r_sphere_coordinates.direction = transform_ray(s_transform_inverse, r.direction);

	vector point_minus_center = subtract_vectors(r_sphere_coordinates.point, s.center);

	float polynomials[3];

	polynomials[2] = square_of_magnitude_of_vector(r_sphere_coordinates.direction);
	polynomials[1] = 2 * dot_product(point_minus_center, r_sphere_coordinates.direction);
	polynomials[0] = square_of_magnitude_of_vector(point_minus_center) - s.radius * s.radius;

	roots quad_roots;

	quad_roots = quadratic(polynomials[2], polynomials[1], polynomials[0]);

	return quad_roots;
}

bool point_lies_inside(sphere s, vector point)
{
	vector point_sphere_coordinates;
	matrix s_transform_inverse = inverse_of_matrix(s.transform);

	point_sphere_coordinates = transform_point(s_transform_inverse, point);
	
	float x = point_sphere_coordinates.x;
	float y = point_sphere_coordinates.y;
	float z = point_sphere_coordinates.z;

	if((x * x + y * y + z * z) < s.radius * s.radius)
	{
		return true;
	}
	return false;
}