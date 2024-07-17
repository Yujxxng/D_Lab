// File header documentation is required!!!

// Provide include guards
// Don't include either of the following two headers: <forward_list> and <list>
// You may need to include <cstddef> for size_t [which is the largest unsigned type from the C standard library]
#include <cstddef>
#include <iostream>
#include <initializer_list>
#include <iomanip>
// All names from here on must be in namespace hlp2.
// Don't add any names that are private to the implementation source file listint.cpp in this file.
// Necessary declarations are described in the spec.
namespace hlp2 {
	class ListInt {
	public: //type aliases
		typedef int size_type;
		typedef int value_type;
		typedef int& reference;
		typedef const int& const_reference;
		typedef int* pointer;
		typedef const int* const_pointer;

	public:
		static size_type object_count();
		ListInt();
		ListInt(const ListInt& other) : head(other.head), tail(other.tail), counter(other.counter) {}
		ListInt(std::initializer_list<value_type> l);
		~ListInt();

		ListInt& operator=(ListInt& other);
		ListInt& operator=(std::initializer_list<value_type> l);
		ListInt& operator+=(const ListInt& other);
		ListInt& operator+=(std::initializer_list<value_type> l);

		reference operator[](const value_type pos);
		const_reference operator[](const value_type pos) const;

		void push_front(value_type val);
		void push_back(value_type val);
		value_type pop_front();
		void clear();
		void swap(ListInt& other);
		size_type size();
		bool empty();

		friend std::ostream& operator<<(std::ostream& os, const ListInt& rhs);

	private:
		struct Node {
			int data;
			Node* next;
		};

		Node* head{ nullptr };
		Node* tail{ nullptr };
		size_type counter{ 0 };
		static size_type object_counter;

		Node* new_node(value_type data) const;
	};

	ListInt& operator+(const ListInt& A, const ListInt& B);
	ListInt& operator+(const ListInt& A, std::initializer_list<int> l);
	ListInt& operator+(std::initializer_list<int> l, ListInt& A);

	std::ostream& operator<<(std::ostream& os, const ListInt& rhs);
}

// Ensure every member function declared in class ListInt has a header!!!

// Declare this as a friend function in class ListInt:
