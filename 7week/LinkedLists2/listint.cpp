// File header documentation is required!!!

// Other than listint.hpp, you really don't have to include any other files except when testing your code.
// When you're ready to submit, don't include either of the following two headers: <forward_list> and <list>
#include "listInt.hpp"
// Private functions must be declared and defined in an anonymous namespace!!!

namespace {

}
// This function definition is provided:
////////////////////////////////////////////////////////////////////////////////
// Function: operator<<
//  Purpose: Output the list into an ostream object
//   Inputs: os - ostream object
//           list - the List to output
//  Outputs: Returns an ostream object.
////////////////////////////////////////////////////////////////////////////////


namespace hlp2
{
	std::ostream& operator<<(std::ostream& os, const ListInt& rhs) {
		// Start at the first node
		ListInt::Node* pnode = rhs.head;

		// Until we reach the end of the list
		while (pnode != 0) {
			os << std::setw(4) << pnode->data; // print the data in this node
			pnode = pnode->next;               // move to the next node
		}

		os << std::endl; // extra newline for readability
		return os;
	}
}

hlp2::ListInt::size_type hlp2::ListInt::object_counter{ 0 };

hlp2::ListInt::size_type hlp2::ListInt::object_count()
{
	return object_counter;
}

hlp2::ListInt::ListInt()
{
	object_counter++;
}

hlp2::ListInt::ListInt(const ListInt& other)
{
	object_counter++;
	this->counter = other.counter;

	if (other.head == nullptr)
	{
		return;
	}

	Node* node = other.head;
	value_type v = node->data;

	while(node)
	{
		v = node->data;
		push_back(v);
		
		node = node->next;
	}
}

hlp2::ListInt::ListInt(const std::initializer_list<value_type> l)
{
	object_counter++;
	std::initializer_list<value_type>::iterator it;
	for (it = l.begin(); it != l.end(); it++)
	{
		push_back(*it);
	}
}

hlp2::ListInt::~ListInt()
{
	//delete
	object_counter--;
	clear();
}

hlp2::ListInt& hlp2::ListInt::operator=(const ListInt& other)
{
	if (!this->empty())
		this->clear();

	if (other.head == nullptr)
	{
		return *this;
	}

	Node* node = other.head;
	value_type v = node->data;

	while (node)
	{
		v = node->data;
		push_back(v);

		node = node->next;
	}

	return *this;
}

hlp2::ListInt& hlp2::ListInt::operator=(const std::initializer_list<value_type> l)
{
	if (!this->empty())
		this->clear();

	std::initializer_list<value_type>::iterator it;
	for (it = l.begin(); it != l.end(); it++)
	{
		push_back(*it);
	}

	return *this;
}

hlp2::ListInt& hlp2::ListInt::operator+=(const ListInt& other)
{

	return *this;
}

hlp2::ListInt& hlp2::ListInt::operator+=(const std::initializer_list<value_type> l)
{

	return *this;
}

void hlp2::ListInt::push_front(value_type value)
{
	counter++;
	Node* node = new_node(value);

	if (empty())
	{
		this->head = node;
		this->tail = node;
	}
	else
	{
		node->next = this->head;
		this->head = node;
	}
}

void hlp2::ListInt::push_back(value_type value)
{
	counter++;
	Node* node = new_node(value);

	if (empty())
	{
		this->head = node;
		this->tail = node;
	}
	else
	{
		tail->next = node;
		this->tail = node;
	}
}

hlp2::ListInt::value_type hlp2::ListInt::pop_front()
{
	value_type val = this->head->data;

	Node* tmp = this->head;
	this->head = tmp->next;
	delete tmp;

	return val;
}

void hlp2::ListInt::clear()
{
	if (empty()) return;

	Node *p, *q;
	p = this->head;
	q = p;

	while (q)
	{
		q = q->next;
		delete p;
		counter--;

		p = q;
	}

	this->head = nullptr;
	this->tail = nullptr;
}

void hlp2::ListInt::swap(ListInt& other)
{
	Node* th, * tt;
	th = other.head;
	tt = other.tail;

	other.head = this->head;
	other.tail = this->tail;

	this->head = th;
	this->tail = tt;
}

hlp2::ListInt::size_type hlp2::ListInt::size()
{
	size_type sz{ 0 };
	Node* p = this->head;

	while (p)
	{
		sz++;
		p = p->next;
	}

	return sz;
}

bool hlp2::ListInt::empty()
{
	if (this->head == nullptr)
		return true;

	return false;
}

hlp2::ListInt::Node* hlp2::ListInt::new_node(value_type data) const
{
	Node* node = new Node;
	node->data = data;
	node->next = nullptr;

	return node;
}
