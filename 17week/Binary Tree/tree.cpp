#include "tree.hpp"
#include <iostream>
#include <queue>
#include <stack>

void Tree::Remove(int key)
{
	if (root == nullptr)
		return;

	Node* tmp = Find(key);
	if (tmp == nullptr)
		return;

	Node* CurNode = root;
	Node* PreNode = nullptr;
	Node* PreTmp = nullptr;

	//Find
	while (CurNode->Key != key)
	{
		if (CurNode->Key > key)
		{
			PreNode = CurNode;
			CurNode = CurNode->Left;
		}
		else
		{
			PreNode = CurNode;
			CurNode = CurNode->Right;
		}
	}
	if (CurNode->Left == nullptr && CurNode->Right == nullptr)
	{
		if (PreNode->Left == CurNode)
			PreNode->Left = nullptr;
		else if (PreNode->Right == CurNode)
			PreNode->Right = nullptr;

		delete CurNode;
	}
	else
	{
		if (CurNode->Left == nullptr)
		{
			PreTmp = CurNode;
			tmp = CurNode->Right;
		}
		else if (CurNode->Right == nullptr)
		{
			PreTmp = CurNode;
			tmp = CurNode->Left;
		}
		else
		{
			tmp = CurNode->Right;
			PreTmp = CurNode;
			while (tmp->Left != nullptr)
			{
				PreTmp = tmp;
				tmp = tmp->Left;
			}
		}
		if (CurNode == root)
			root = tmp;
		else
		{
			if (PreTmp->Left == tmp)
				PreTmp->Left = nullptr;
			else if (PreTmp->Right == tmp)
				PreTmp->Right = nullptr;

			tmp->Left = CurNode->Left;
			tmp->Right = CurNode->Right;

			if (PreNode->Left == CurNode)
				PreNode->Left = tmp;
			else if (PreNode->Right == CurNode)
				PreNode->Right = tmp;
		}

		delete CurNode;
	}
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


Tree::Tree(const std::vector<std::pair<int, int>>& Nodes)
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
