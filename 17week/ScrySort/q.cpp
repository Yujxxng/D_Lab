#include "q.hpp"
#include "deck.hpp"
#include <iostream>

//TODO:
void Scry2Sort(const std::vector<int>& target, deck& obj)
{
	int total = (int)target.size();
	int cnt = 0;

	while (obj.Top() != target[0]) //Track the target[0] value
		obj.Pushback();

	for (int i = 1; i < (int)target.size(); i++)
	{
		while (obj.Top() != target[i])
		{
			obj.Pushback();
			cnt++;
		}

		for (int j = 0; j < (total - cnt); j++)
		{
			obj.Swap();
			obj.Pushback();
		}

		cnt = 0;
		//std::cout << i << " : ";
		//obj.Print();
		//std::cout << "\n";
	}
	obj.Pushback();
}


void PrintVec(const std::vector<int>& v)
{
	for (auto i : v)
		std::cout << i << ' ';

	std::cout << std::endl;
}
