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

	std::cout << " +-[ " << this->First() << " , " << this->Second().GetInt() << " ]" << n << std::endl;
	std::cout << "  ";
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
	if (d.GetInt() < this->data.GetInt())
	{
		if (Left != nullptr)
			Left->Insert(k, d);
		else
		{
			Node* newNode = new Node(k, d);
			Left = newNode;
		}
	}

	else //(d.GetInt() >= this->data.GetInt())
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
