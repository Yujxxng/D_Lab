#include <cstddef>
#include <iostream>
#include <initializer_list>
#include <iomanip>

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
		ListInt(const ListInt& other);
		ListInt(const std::initializer_list<value_type> l);
		~ListInt();

		ListInt& operator=(const ListInt& other);
		ListInt& operator=(const std::initializer_list<value_type> l);
		ListInt& operator+=(const ListInt& other);
		ListInt& operator+=(const std::initializer_list<value_type> l);

		reference operator[](const int pos);
		const_reference operator[](const int pos) const;

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

	ListInt operator+(const ListInt& A, const ListInt& B);
	ListInt operator+(const ListInt& A, const std::initializer_list<int> l);
	ListInt operator+(const std::initializer_list<int> l, const ListInt& A);

	std::ostream& operator<<(std::ostream& os, const ListInt& rhs);
}