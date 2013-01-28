#include "common.h"

/*
 The following is Copyright id Software, under the terms of their Quake III
 Arena open source license.

 That code file is visible on the web here:

 ftp://ftp.idsoftware.com/idstuff/source/quake3-1.32b-source.zip

 in q_math.c. I claim no ownership over fast_inv_sqrt().

 I think Carmack's an awesome dude.
 */

float fast_inv_sqrt(float n)
{
	// Thanks, Carmack!
	// (his comments, not mine!)

    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = n * 0.5F;
    y  = n;
    i  = * ( long * ) &y;                       // evil floating point bit level hacking
    i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
    y  = * ( float * ) &i;
    y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration

    return y;

}

/*
 This ends code that is copyright id Software. The rest of this file is subject
 to the copyright statement at the License.txt file in the root of this project
 */


float fast_sqrt(float n)
{
	// Yeah...
	return 1/fast_inv_sqrt(n);
}

roots quadratic(float a, float b, float c)
{
    roots result;
    result.one = 0.0;
    result.two = 0.0;

    float discriminant = b*b - (4 * a * c);

    if(discriminant < 0)
    {
        // No real roots
        return result;
    }

    float one_over_two_a = 1 / (2 * a);
    float negative_b = -1 * b;


    if(float_equals(discriminant, 0))
    {
        // Only one root, -b/2a
        result.one = negative_b * one_over_two_a;
        return result;
    }

    // We have two roots in this case

    float root1 = (negative_b + discriminant) * one_over_two_a;
    float root2 = (negative_b - discriminant) * one_over_two_a;

    return result;
}