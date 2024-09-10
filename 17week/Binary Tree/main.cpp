#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>

#include "tree.hpp"
#include "node.hpp"

int main()
{
	Tree* a = new Tree();
	a->Insert(13, 26);
	a->Insert(6, 12);
	a->Insert(14, 28);
	a->Insert(4, 8);
	a->Insert(9, 18);
	a->Insert(1, 2);
	a->Insert(5, 10);
	a->Insert(8, 16);
	a->Insert(11, 22);
	a->Insert(0, 0);
	a->Insert(2, 4);
	a->Insert(7, 14);
	a->Insert(10, 20);
	a->Insert(12, 24);
	a->Insert(3, 6);


	std::cout << "Tree Length = " << a->Length() << std::endl;
	//a->Print();

	a->Clear();
	a->Print();
	return 0;
}