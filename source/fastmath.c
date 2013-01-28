

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