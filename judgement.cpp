#include "judgement.h"

bool HitCircle(float ax, float ay, float ar, float bx, float by, float br)
{
	float x = bx - ax;
	float y = by - ay;

	float l = x*x + y*y;
	return l<(ar+br)*(ar + br);
}
