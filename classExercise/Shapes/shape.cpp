#include "Shape.h"
#include <exception>

Shape::Shape() : _area(0), _perimeter(0)
{

}

float Shape::get_area(bool has_depth) const
{
	if (has_depth)
	{
		throw std::exception("3D triangle is not implemented yet!");
	}
	return _area;
}
