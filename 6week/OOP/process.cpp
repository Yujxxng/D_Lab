///////////////////////////////////////////////////////////////////////////////
// File Name:      process.cpp
//
// Author:         <your name>
// Email:          <your email>
//
// Description:    Methods to perform some processing on containers of
//                 type std::vector<Shape*>.
///////////////////////////////////////////////////////////////////////////////

#include "process.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

void parse_file(std::ifstream &ifs, std::vector<Shape*>& vs,
                std::vector<Shape*>& ves, std::vector<Shape*>& vps) {
  // TODO: Implement this method.
  // See function header in process.hpp for additional information
  
  std::string line;
  while(std::getline(ifs, line))
  {
	  char c = line[0];
	  line = line.substr(2);
	  
	  //Ellipse
	  if(c == 'E')
	  {
		  Shape *p = new Ellipse(line);
		  vs.push_back(p);
		  ves.push_back(p);
	  }
	
	  //Polygon
	  else if(c == 'P')
	  {
		  Shape *p = new Polygon(line);
		  vs.push_back(p);
		  vps.push_back(p);
	  }
	  else
		  break; 
  }
}

void print_records(std::vector<Shape*> const& vs) {
  // TODO: Implement this method.
  // See function header in process.hpp for additional information
	for (int i = 0; i < (int)vs.size(); i++)
	{
		vs[i]->print_details();
		std::cout << '\n';
	}
}

void print_stats(std::vector<Shape*> const& vs) {
  // TODO: Implement this method.
  // See function header in process.hpp for additional information
	
	int cnt = Shape::getCount();
	
	if ((int)vs.size() == Ellipse::getCount())
		cnt = Ellipse::getCount();
	else if ((int)vs.size() == Polygon::getCount())
		cnt = Polygon::getCount();
	
	double area = 0.0;
	std::vector<std::pair <double, int>> tmp;

	for (int i = 0; i < (int)vs.size(); i++)
	{
		tmp.push_back(std::make_pair(vs[i]->getArea(), i));
		area += vs[i]->getArea();
	}

	area = area / vs.size();
	std::sort(tmp.begin(), tmp.end());

	std::cout << "Number of shapes = " << cnt << std::endl;
	std::cout << "The mean of the areas = " << area << std::endl;
	std::cout << "The sorted list of shapes (id,center,area) in ascending order of areas:" << std::endl;
	for (int i = 0; i < (int)vs.size(); i++)
	{
		int idx = tmp[i].second;
		std::cout << vs[idx]->getId() << "," << vs[idx]->getCenter().x << "," << vs[idx]->getCenter().y <<
			"," << vs[idx]->getArea() << std::endl;
	}
}

/**
* @brief Return memory allocated by operator new ONLY using pointers contained
* in container specified by first parameter. Why? Because containers specified
* in the next two containers reference the same memory locations as elements of
* first container, double deletion will cause undefined run-time behavior.
* Next, clear contents of all 3 containers.
*
* @param vs Reference to vector<Shape*> containing pointers to all shapes.
* @param ves Reference to vector<Shape*> containing pointers to ellipses.
* @param vps Reference to vector<Shape*> containing pointers to polygons.
*/
void cleanup(std::vector<Shape*>& vs, std::vector<Shape*>& ves, std::vector<Shape*>& vps) {
  // delete memory previously allocated by operator new
  for (Shape *ps : vs)
    delete ps;

  // avoid double deletion!!!
  vs.clear();
  ves.clear();
  vps.clear();
  
  for (Shape *ps : ves)
    delete ps;

  for (Shape *ps : vps)
    delete ps;
}
