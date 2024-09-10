#pragma once
#include "node.hpp"
#include <vector>

class Tree
{
	Node* root;

public:

	//Creates an empty tree
	Tree() : root(nullptr) {};

	//Creates a tree with some ORDERED values already.
	//The input vector IS NOT ordered
	Tree(const std::vector<std::pair<int, int>>& Nodes);

	//Destroys the Tree
	~Tree();

	//Creates a new node at the correct position
	void Insert(int key, DATA data);

	//Finds the node. If it does not exists, returns nullptr
	Node* Find(int key);

	//Returns the Root Node
	Node* Root();

	//Calculates the Length from Root Node
	int Length();

	//Clears all nodes
	void Clear();

	//Finds and removes a Node given by its key
	//Only remove ..?
	void Remove(int key);

	void Print();
};