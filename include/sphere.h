#ifndef _SPHERE_
#define _SPHERE_

#include "linear_algebra.h"
#include "generic_types.h"

typedef struct
{
	matrix transform;

	vector center;
	float radius;
} sphere;

roots intersection_with_ray(sphere s, ray r);
bool point_lies_inside(sphere s, vector point);

#endif