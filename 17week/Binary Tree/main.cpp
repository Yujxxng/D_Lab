#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <algorithm>

#include "tree.hpp"
#include "node.hpp"
#include <vector>

int main()
{
	std::vector<int> temp;
	std::vector<std::pair<int, int>> v;

	for (int i = 0; i < 10; i++)
	{
		temp.push_back(i);
	}

	std::random_shuffle(temp.begin(), temp.end());

	for (int i = 0; i < 10; i++)
		v.push_back({ temp[i], 1 });

	Tree b(v);
	b.Print();


	return 0;
}