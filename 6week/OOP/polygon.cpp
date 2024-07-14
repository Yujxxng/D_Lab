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
	return this->vertices;
}

int Polygon::getCount()
{
	return Polygon::count;
}

void Polygon::print_details() const
{
	Shape::print_details();
	std::cout << "Type = Polygon Shape" << std::endl;
	std::cout << "Vertices = ";
	for (int i = 0; i < (int)vertices.size(); i++)
		std::cout << vertices[i].x << "," << vertices[i].y << " ";
	std::cout << '\n';
}

Point Polygon::getCenter() const
{
	int centerX = 0, centerY = 0;
	for (int i = 0; i < (int)vertices.size(); i++)
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
	// fomular : 1/2 * (XiYi+1 - Xi+1Yi) 
	double area = 0.0;

	for (int i = 0; i < (int)vertices.size(); i++)
	{
		int a, b = 0;
		if (i == (int)((int)vertices.size() - 1))
		{
			a = vertices[i].x * vertices[0].y;
			b = vertices[0].x * vertices[i].y;
		}
		else
		{
			a = vertices[i].x * vertices[i + 1].y;
			b = vertices[i + 1].x * vertices[i].y;
		}

		area += (a - b);
	}

	area = area * 0.5;

	return area;
}
