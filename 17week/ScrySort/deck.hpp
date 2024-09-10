#pragma once

#include <vector>

struct deck
{
private:
	std::vector<int> v;
public:

	deck(const std::vector<int>& V) : v(V) { Shuffle(); };

	std::vector<int>::iterator begin();
	std::vector<int>::iterator end();

	int Top() const;
	int Other() const;

	void Pushback();
	void Swap();

	void Print() const;

	void Shuffle();
};