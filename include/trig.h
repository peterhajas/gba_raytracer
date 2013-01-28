#ifndef _TRIG_
#define _TRIG_

// pi declarations

#define M_PI (3.14159265359)
#define M_PI_OVER_2 (M_PI/2)
#define M_PI_OVER_4 (M_PI_OVER_2/2)

#define M_PI_TIMES_2 (M_PI * 2)
#define M_PI_TIMES_3 (M_PI * 3)
#define M_PI_TIMES_4 (M_PI * 4)

float degrees_in_radians(float degrees);
float radians_in_degrees(float radians);

float fast_sin(float radians);
float fast_cos(float radians);

#endif