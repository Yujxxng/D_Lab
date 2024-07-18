#define _USE_MATH_DEFINES
#include "point.hpp"  // Point interface
#include <cmath>      // sin, cos, sqrt

namespace hlp2 {

// define 3 constructors
	Point::Point() : x(0.0), y(0.0) {}
	Point::Point(double x, double y) : x{ x }, y{ y } {}
	Point::Point(const double* value)
	{
		this->x = *value;
		this->y = *(value + 1);
	}

// define 8 member functions
	double& Point::operator[](const int index)
	{
		if (index == 0)
			return this->x;
		else
			return this->y;
	}

	const double& Point::operator[](const int index) const
	{
		if (index == 0)
			return this->x;
		else
			return this->y;
	}

	Point& Point::operator+=(const double value)
	{
		this->x += value;
		this->y += value;

		return *this;
	}

	Point& Point::operator+=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;

		return *this;
	}

	Point& Point::operator++()
	{
		++(this->x);
		++(this->y);

		return *this;
	}

	const Point Point::operator++(int)
	{
		Point tmp;
		tmp[0] = (*this)[0];
		tmp[1] = (*this)[1];

		++(this->x);
		++(this->y);

		return tmp;
	}

	Point& Point::operator--()
	{
		--(this->x);
		--(this->y);

		return *this;
	}

	const Point Point::operator--(int)
	{
		Point tmp;
		tmp[0] = (*this)[0];
		tmp[1] = (*this)[1];

		--(this->x);
		--(this->y);

		return tmp;
	}

// define 15 non-member, non-friend functions
	Point operator%(const Point& A, const double degree)
	{
		Point tmp = A;

		double d = degree * M_PI / 180.0;
		double x = (tmp[0] * cos(d)) - (tmp[1] * sin(d));
		double y = (tmp[1] * sin(d)) + (tmp[1] * cos(d));

		tmp[0] = x;
		tmp[1] = y;

		return tmp;
	}

	double operator/(const Point& A, const Point& B)
	{
		double x = B[0] - A[0];
		double y = B[1] - A[1];

		return sqrtf((x*x) + (y*y));
	}

	Point operator+(const Point& A, const Point& B)
	{
		Point tmp;
		tmp[0] = A[0] + B[0];
		tmp[1] = A[1] + B[1];

		return tmp;
	}
	Point operator+(const Point& A, const double value)
	{
		Point tmp;
		tmp[0] = A[0] + value;
		tmp[1] = A[1] + value;

		return tmp;
	}

	Point operator+(const double value, const Point& A)
	{
		Point tmp;
		tmp[0] = A[0] + value;
		tmp[1] = A[1] + value;

		return tmp;
	}

	Point operator-(const Point& A, const Point& B)
	{
		Point tmp;
		tmp[0] = A[0] - B[0];
		tmp[1] = A[1] - B[1];

		return tmp;
	}

	Point operator-(const Point& A, const double value)
	{
		Point tmp;
		tmp[0] = A[0] - value;
		tmp[1] = A[1] - value;

		return tmp;
	}

	Point operator-(const double value, const Point& A)
	{
		Point tmp;
		tmp[0] = value - A[0];
		tmp[1] = value - A[1];

		return tmp;
	}

	Point operator-(const Point& A)
	{
		Point tmp;
		tmp[0] = -A[0];
		tmp[1] = -A[1];

		return tmp;
	}

	Point operator^(const Point& A, const Point& B)
	{
		Point tmp;
		tmp[0] = (A[0] + B[0]) / 2.0;
		tmp[1] = (A[1] + B[1]) / 2.0;

		return tmp;
	}

	double operator*(const Point& A, const Point& B)
	{
		return (A[0] * B[0]) + (A[1] * B[1]);
	}

	Point operator*(const Point& A, const double value)
	{
		Point tmp;
		tmp[0] = A[0] * value;
		tmp[1] = A[1] * value;

		return tmp;
	}

	Point operator*(const double value, const Point& A)
	{
		Point tmp;
		tmp[0] = A[0] * value;
		tmp[1] = A[1] * value;

		return tmp;
	}

	std::ostream& operator<<(std::ostream& os, const Point& A)
	{
		std::cout << "(" << A[0] << ", " << A[1] << ")";
		return os;
	}

	std::istream& operator>>(std::istream& is, Point& A)
	{
		double x, y;
		std::cin >> x >> y;
		A[0] = x;
		A[1] = y;

		return is;
	}



} // end hlp2 namespace