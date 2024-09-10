#include "q.hpp"
#include "deck.hpp"
#include <iostream>

//TODO:
void Scry2Sort(const std::vector<int>& target, deck& obj)
{
	int size = target.size();
	int flag = target[0];
	while (flag != obj.Top())
	{
		for (int i = 0; i < size; i++)
		{
			while (target[i] != obj.Top())
			{
				if (target[i] == obj.Other())
					obj.Swap();
				else
					obj.Pushback();
			}

			if (target[i] == obj.Top())
				obj.Pushback();
		}
	}
}


void PrintVec(const std::vector<int>& v)
{
	for (auto i : v)
		std::cout << i << ' ';

	std::cout << std::endl;
}
