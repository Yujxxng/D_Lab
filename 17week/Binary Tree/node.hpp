#pragma once

#include <vector>

//YOU MAY EDIT THIS FUNCTIONS, OR ADD NEW ONES

class DATA
{
	int i;

public:
	DATA(int I) : i(I) {}
	int GetInt() { return i; };
};

class Node
{
	Node* Left;
	Node* Right;
	int Key;
	DATA data;

	friend class Tree;
public:

	int First();
	DATA Second();

	Node(int K, DATA d) : Key(K), data(d), Left(nullptr), Right(nullptr) {}
	~Node();

	void PrintNode(int n, std::vector<bool>ids);
	int CalculateLenght();

	void Insert(int k, DATA d);

};