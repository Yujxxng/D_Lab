#include "shape.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

int Shape::count = 0;

Shape::Shape(std::string& line)
{
	std::istringstream is(line);
	std::string border, fill;

	is >> border >> fill;

	this->border = border;
	this->fill = fill;
	this->id = count + 1;

	Shape::count++;
}

Shape::~Shape()
{
	Shape::count--;
}

int Shape::getId() const
{
	return this->id;
}

std::string Shape::getBorder() const
{
	return this->border;
}

std::string Shape::getFill() const
{
	return this->fill;
}

int Shape::getCount()
{
	return count;
}

void Shape::print_details() const
{
	std::cout << "Id = " << this->getId() << std::endl;
	std::cout << "Border = " << this->getBorder() << std::endl;
	std::cout << "Fill = " << this->getFill() << std::endl;
}
