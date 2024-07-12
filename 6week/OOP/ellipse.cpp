#define _USE_MATH_DEFINES

#include "ellipse.hpp"
#include <sstream>
#include <iostream>
#include <math.h>

int Ellipse::count = 0;

Ellipse::Ellipse(std::string& line) : Shape(line)
{
	std::istringstream is(line);
	std::string border, fill;
	char cm;
	int x, y, major, minor;

	is >> border >> fill >> x >> cm >> y >> major >> minor;

	this->center.x = x;
	this->center.y = y;
	this->a = major;
	this->b = minor;

	Ellipse::count++;
}

Ellipse::~Ellipse()
{
	Ellipse::count--;
}

int Ellipse::getA() const
{
	return this->a;
}

int Ellipse::getB() const
{
	return this->b;
}

int Ellipse::getCount()
{
	return count;
}

void Ellipse::print_details() const
{
	Shape::print_details();
	std::cout << "Type = Ellipse Shape" << std::endl;
	std::cout << "Center = " << this->getCenter().x << "," << this->getCenter().y << std::endl;
	std::cout << "a-length = " << this->getA() << std::endl;
	std::cout << "b-length = " << this->getB() << std::endl;
}

Point Ellipse::getCenter() const
{
	Point tmp{ this->center.x, this->center.y };
	return tmp;
}

double Ellipse::getArea() const
{
	return M_PI * this->a * this->b;
}
