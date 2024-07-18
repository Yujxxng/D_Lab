#ifndef POINT_HPP
#define POINT_HPP


#include <iostream> // istream, ostream

namespace hlp2 {
	
class Point {
public:
	// declare constructors (3)
	Point();
	Point(double x, double y);
	//Point(const Point& other);
	Point(const double* value);

	// declare overloaded operators (8 member functions)
	double& operator[](const int index);
	const double& operator[](const int index) const;

	Point& operator+=(const double value);
	Point& operator+=(const Point& other);

	Point& operator++();
	const Point operator++(int);

	Point& operator--();
	const Point operator--(int);

private:
	double x; // The x-coordinate of a Point
	double y; // The y-coordinate of a Point
};
  
// declare 15 non-member, non-friend functions
Point operator%(const Point& A, const double degree);
double operator/(const Point& A, const Point& B);
Point operator+(const Point& A, const Point& B);
Point operator+(const Point& A, const double value);
Point operator+(const double value, const Point& A);
Point operator-(const Point& A, const Point& B);
Point operator-(const Point& A, const double value);
Point operator-(const double value, const Point& A);
Point operator-(const Point& A);
Point operator^(const Point& A, const Point& B);
double operator*(const Point& A, const Point& B);
Point operator*(const Point& A, const double value);
Point operator*(const double value, const Point& A);

std::ostream& operator<<(std::ostream& os, const Point& A);
std::istream& operator>>(std::istream& is, Point& A);

} // end namespace hlp2

#endif // end POINT_HPP
////////////////////////////////////////////////////////////////////////////////
