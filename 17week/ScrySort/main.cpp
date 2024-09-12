#include "deck.hpp"
#include "q.hpp"
#include <iostream>
#include <vector>

int main()
{
	//std::vector<int> target{ 7, 0, 9, 8, 5, 4, 1, 3, 2, 6 };
	//std::vector<int> v{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	std::vector<int> target{ 1, 5, 2, 4, 3, 2, 4, 8, 13, 6 };
	std::vector<int> v{ 3, 6, 8, 2, 2, 5, 1, 13, 4, 4 };

	deck* d = new deck(v);
	d->Print();

	Scry2Sort(target, *d);
	d->Print();
}