#include "common.h"

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
