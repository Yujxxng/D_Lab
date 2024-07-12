#define _USE_MATH_DEFINES

#include "polygon.hpp"
#include <sstream>
#include <iostream>
#include <math.h>
#include <vector>

int Polygon::count = 0;
Polygon::Polygon(std::string& line) : Shape(line)
{
	std::istringstream is(line);

	std::string str;
	int i = 0;
	while (is >> str)
	{
		if (i < 2)
		{
			i++;
			continue;
		}

		char cm;
		int x, y;

		std::istringstream iss(str);
		iss >> x >> cm >> y;
		this->vertices.push_back(Point{ x, y });
	}

	Polygon::count++;
}

Polygon::~Polygon()
{
	Polygon::count--;
}

std::vector<Point>& Polygon::getVertices()
{
	std::vector<Point> vp;

	for (int i = 0; i < this->vertices.size(); i++)
		vp.push_back(vertices[i]);

	return vp;
}

int Polygon::getCount()
{
	return count;
}

void Polygon::print_details() const
{
	Shape::print_details();
	std::cout << "Type = Polygon Shape" << std::endl;
	std::cout << "Vertices = ";
	for (int i = 0; i < this->vertices.size(); i++)
		std::cout << vertices[i].x << "," << vertices[i].y << " ";
	std::cout << '\n';
}

Point Polygon::getCenter() const
{
	int centerX = 0, centerY = 0;
	for (int i = 0; i < this->vertices.size(); i++)
	{
		centerX += vertices[i].x;
		centerY += vertices[i].y;
	}

	centerX = centerX / vertices.size();
	centerY = centerY / vertices.size();

	return Point{ centerX, centerY };
}

double Polygon::getArea() const
{
	double area = 1234.0;

	//not complete

	return area;
}
