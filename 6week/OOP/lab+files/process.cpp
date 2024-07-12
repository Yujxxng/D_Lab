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
#include <set>

void parse_file(std::ifstream &ifs, std::vector<Shape*>& vs,
                std::vector<Shape*>& ves, std::vector<Shape*>& vps) {
  // TODO: Implement this method.
  // See function header in process.hpp for additional information

}

void print_records(std::vector<Shape*> const& vs) {
  // TODO: Implement this method.
  // See function header in process.hpp for additional information

}

void print_stats(std::vector<Shape*> const& vs) {
  // TODO: Implement this method.
  // See function header in process.hpp for additional information

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
}
