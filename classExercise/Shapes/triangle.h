#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include "shape.h"

class Triangle : public Shape 
{
private:
	float _base;
	float _height;
public:
	Triangle(float base, float height); 

	// Change - made function to override og function of shape.h
	float get_area(bool has_depth = false) const override;

	/// --Explenation--
	///		Appearntly, bcs the second triangle, is showned by a pointer
	///		pointer of Shape, so the when calling shape->get_area()
	///		the program will go to the method that belonogs to shape...
	///		to solve this, we needed to override this method, to make sure
	///		that everytime we making an appearance of triangle, even if its through shape
	///		the correct methods will be called.

};


#endif	// __TRIANGLE_H__
