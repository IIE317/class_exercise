#include "Point.h"
#include <iostream>

Point::Point()
{
	_coord = new int[2];
	_coord[0] = _coord[1] = 0;
}

Point::Point(int x, int y)
{
	_coord = new int[2];
	_coord[0] = x;
	_coord[1] = y;
}

Point::Point(const Point& other)
{
	delete _coord;
	_coord = other._coord;
}

Point::~Point()
{
	delete _coord;
}

Point& Point::operator=(const Point& other)
{
	// old code. issue- creating new coord with no value (so copied the address)
	/*delete _coord;
	_coord = new int[2];
	memcpy(_coord, other._coord, 2);
	*/

	// this will update the value correct, but os will throw an exception.
	// this->_coord = other._coord;

	// correct version:
	_coord[0] = other.getX();
	_coord[1] = other.getY();


	/// ---Explenation---
	///		If we delete the existing _coord, then we delete
	///		the points (x, y) we already have.
	///		So instead of deleting it and creating a new one (and when -
	///		- copying it we will actually copy the address), 
	///		we WONT delete the existing _coord, and copy it 
	///		by ourself (most times I prefer to copy things like this by myself).

	return *this;
}

int Point::getX() const 
{ 
	return _coord[0]; 
}

int Point::getY() const
{ 
	return _coord[1]; 
}


std::ostream& operator<<(std::ostream& os, const Point& p)
{
	os << "(" << p._coord[0] << "," << p._coord[1] << ")";
	return os;
}
