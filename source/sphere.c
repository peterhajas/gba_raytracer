#include "sphere.h"
#include "fastmath.h"
#include "common.h"

roots intersection_with_ray(sphere s, ray r)
{
	// We need r in sphere-coordinates

	ray r_sphere_coordinates;
	s_transform_inverse = inverse_of_matrix(s.transform);
	r_sphere_coordinates.point     = transform_point(s_transform_inverse, r.point);
	r_sphere_coordinates.direction = transform_direction(s_transform_inverse, r.direction);

	vector point_minus_center = subtract_vector(r_sphere_coordinates.point, s.center);

	float s[3];

	s[2] = square_of_magnitude_of_vector(r_sphere_coordinates.direction);
	s[1] = 2 * dot_product(point_minus_center, r_sphere_coordinates.direction);
	s[0] = square_of_magnitude_of_vector(point_minus_center) - s.radius * radius;

	roots quad_roots;

	quad_roots = quadratic(s[2],s[1],s[0]);

	return quad_roots;
}

bool point_lies_inside(sphere s, vector point)
{
	vector point_sphere_coordinates;
	s_transform_inverse = inverse_of_matrix(s.transform);

	point_sphere_coordinates = transform_point(s_transform_inverse, point);
	
	float x = point_sphere_coordinates.x;
	float y = point_sphere_coordinates.y;
	float c = point_sphere_coordinates.z;

	if((x * x + y * y + z * z) < radius * radius)
	{
		return true;
	}
	return false;
}