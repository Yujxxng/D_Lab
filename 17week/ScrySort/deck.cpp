#include "deck.hpp"
#include "q.hpp"
#include <algorithm>

std::vector<int>::iterator deck::begin()
{
	return v.begin();
}

std::vector<int>::iterator deck::end()
{
	return v.end();
}

int deck::Top() const
{
	return this->v[0];
}

int deck::Other() const
{
	return this->v[1];
}

void deck::Pushback()
{
	v.push_back(Top());
	v.erase(v.begin());
}

void deck::Swap()
{
	int t = Top();

	v[0] = v[1];
	v[1] = t;
}

void deck::Print() const
{
	PrintVec(v);
}

void deck::Shuffle()
{
	std::random_shuffle(v.begin(), v.end());
}
