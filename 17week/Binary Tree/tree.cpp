#include "tree.hpp"
#include <iostream>
#include <queue>
#include <stack>

void Tree::Remove(int key)
{
	if (root == nullptr)
		return;

	Node* node = Find(key);
	if (node == nullptr)
		return;

	Node* preNode = nullptr;
	node = root;
	while (node->Key != key)
	{
		if (node->Key > key)
		{
			preNode = node;
			node = node->Left;
		}
		else
		{
			preNode = node;
			node = node->Right;
		}
	}
	if (preNode == nullptr)
		root = nullptr;
	else if (preNode->Left == node)
		preNode->Left = nullptr;
	else if (preNode->Right == node)
		preNode->Right = nullptr;

	std::vector<std::pair<int, int>> child;
	std::stack<Node*> s;
	s.push(node);
	while (!s.empty())
	{
		Node* tmp = s.top();
		s.pop();

		if (tmp != node)
			child.push_back(std::make_pair(tmp->First(), tmp->Second().GetInt()));
	
		if (tmp->Right != nullptr)
			s.push(tmp->Right);

		if (tmp->Left != nullptr)
			s.push(tmp->Left);

		delete tmp;
	}

	for (int i = 0; i < (int)child.size(); i++)
		Insert(child[i].first, child[i].second);
}

void Tree::Print()
{
	std::cout << "Tree Length = " << this->Length() << std::endl;
	if (root == nullptr)
	{
		return;
	}

	int n = 0;
	std::vector<bool> ids;
	Node* tmp = root;

	ids.push_back(false);
	tmp->PrintNode(n, ids);
}


Tree::Tree(const std::vector<std::pair<int, int>>& Nodes) : root(nullptr)
{
	for (int i = 0; i < (int)Nodes.size(); i++)
		Insert(Nodes[i].first, Nodes[i].second);
}

Tree::~Tree()
{
	Clear();
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
	if (root == nullptr) return 0;
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
