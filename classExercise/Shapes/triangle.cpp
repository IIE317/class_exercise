#include "triangle.h"
#include <exception>
#include <iostream>


Triangle::Triangle(float base, float height) : _base(base), _height(height)
{
}

float Triangle::get_area(bool has_depth) const
{
	if (has_depth)
	{
		throw std::exception("3D triangle is not implemented yet!");
	}
	// for helping debugging
	// printf("ooga booga\n");
	return float(0.5 * _base * _height);
}
