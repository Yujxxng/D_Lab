#include "node.hpp"
#include <iostream>
#include <queue>

int Node::First()
{
	return Key;
}

DATA Node::Second()
{
	return data;
}

Node::~Node()
{
}

void Node::PrintNode(int n, std::vector<bool>ids)
{
	for (int i = 0; i < n; i++)
	{
		if (ids[i])
			std::cout << " |";
		else
			std::cout << "  ";
	}
	std::cout << " +-[ " << this->First() << " , " << this->Second().GetInt() << " ]" << n << std::endl;

	if (this->Left)
	{
		(this->Right != nullptr) ? ids.push_back(true) : ids.push_back(false);
		this->Left->PrintNode(n + 1, ids);
		ids.pop_back();
	}
	if (this->Right)
	{
		ids.push_back(false);
		this->Right->PrintNode(n + 1, ids);
		ids.pop_back();
	}
}

int Node::CalculateLenght()
{
	int l = 0;
	int r = 0;

	if (this->Left)
		l = this->Left->CalculateLenght();
	if (this->Right)
		r = this->Right->CalculateLenght();

	if (l > r) return l + 1;
	else return r + 1;
}

void Node::Insert(int k, DATA d)
{
	if (k < this->Key)
	{
		if (Left != nullptr)
			Left->Insert(k, d);
		else
		{
			Node* newNode = new Node(k, d);
			Left = newNode;
		}
	}

	else
	{
		if (Right != nullptr)
			Right->Insert(k, d);
		else
		{
			Node* newNode = new Node(k, d);
			Right = newNode;
		}
	}
}
