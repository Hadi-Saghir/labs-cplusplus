#include "poly2.h"
#include <cmath>

Poly2::Poly2(float a, float b, float c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

float Poly2::eval(float x)
{
	return a * x * x + b * x + c;
}

std::vector<float> Poly2::findRoots()
{
	std::vector<float> roots;
	float discriminant = b * b - 4 * a * c;

    	const float epsilon = 1e-7;

	if (std::fabs(discriminant) < 0) {
           	return roots;
        } else if (std::fabs(discriminant) == 0) {
            	roots.push_back(-b / (2 * a));
        } else {
		float sqrtDiscriminant = std::sqrt(discriminant);
            	roots.push_back((-b + sqrtDiscriminant) / (2 * a));
		roots.push_back((-b - sqrtDiscriminant) / (2 * a));
	}

	return roots;

}

