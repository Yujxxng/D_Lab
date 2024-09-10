#include "tree.hpp"
#include <iostream>
#include <queue>
#include <stack>

void Tree::Remove(int key)
{
	if (root == nullptr)
		return;

	Node* tmp = Find(key);
	delete tmp;
}

void Tree::Print()
{
	if (root == nullptr)
	{
		std::cout << "Empty Tree!" << std::endl;
		return;
	}

	int n = 0;
	int depth = 0;
	std::vector<bool> ids;

	std::stack<Node*> s;
	s.push(root);
	ids.push_back(false);

	while (!s.empty())
	{
		Node* tmp = s.top();
		tmp->PrintNode(n, ids);
		s.pop();
		
		if (tmp->Left && tmp->Right)
			ids.push_back(true);
		else
			ids.push_back(false);

		if (tmp->Right != nullptr)
		{
			s.push(tmp->Right);
			n++;
		}

		if (tmp->Left != nullptr)
		{
			s.push(tmp->Left);
			n++;
		}
		//n++;


	}
}

Tree::Tree(const std::vector<std::pair<int, int>>& Nodes)
{
	int n = Nodes.size();
	int i = 0;

	while (i < n)
	{
		Insert(Nodes[i].first, Nodes[i].second);
		i++;
	}
}

Tree::~Tree()
{
}

void Tree::Insert(int key, DATA data)
{
	if (root == nullptr)
	{
		root = new Node(key, data);
		return;
	}

	root->Insert(key, data);
}

Node* Tree::Find(int key)
{
	if (root == nullptr)
		return nullptr;

	Node* tmp = Root();
	while (tmp != nullptr)
	{
		if (tmp->Key == key)
			return tmp;

		else if (tmp->Key > key)
			tmp = tmp->Left;

		else
			tmp = tmp->Right;

	}
	return nullptr;
}

Node* Tree::Root()
{
	return root;
}

int Tree::Length()
{
	return root->CalculateLenght();
}

void Tree::Clear()
{
	if (root == nullptr)
		return;

	std::stack<Node*> s;
	s.push(root);

	while (!s.empty())
	{
		Node* tmp = s.top();
		s.pop();

		if (tmp->Right != nullptr)
			s.push(tmp->Right);

		if (tmp->Left != nullptr)
			s.push(tmp->Left);
		
		//std::cout << "delete : " << tmp->Key << std::endl;
		delete tmp;
	}

	root = nullptr;
}
