#include <cstddef>
#include <iostream>
#include <initializer_list>
#include <iomanip>
#include <array>
#include "str.hpp"

namespace hlp2 {
	template <typename T> class sllist;
	template <typename T> std::ostream& operator<< ( std::ostream&, const sllist<T>& );
	
	template <typename T>
	class sllist {
	public: //type aliases
		typedef size_t size_type;
		typedef T value_type;
		typedef T& reference;
		typedef const T& const_reference;
		typedef T* pointer;
		typedef const T* const_pointer;

	public:
		static size_type object_count();
		static size_type node_count();

		sllist();
		sllist(const_pointer a, const_pointer b);
		sllist(const sllist& other);
		sllist(const std::initializer_list<value_type> l);
		~sllist();

		sllist& operator=(const sllist& other);
		sllist& operator=(const std::initializer_list<value_type> l);
		sllist& operator+=(const sllist& other);
		sllist& operator+=(const std::initializer_list<value_type> l);

		reference operator[](const int pos);
		const_reference operator[](const int pos) const;

		void push_front(const_reference val);
		void push_back(const_reference val);

		reference front();
		const_reference front() const;
		value_type pop_front();
		void clear();
		void swap(sllist& other);
		size_type size() const;
		bool empty() const;
		
		friend std::ostream& operator<< <T>(std::ostream& os, sllist<T> const& list);

	private:
		struct Node {
			Node* next{ nullptr };
			value_type data;
			Node(const_reference);
			~Node();

			static size_type node_counter;
		};

		Node* head{ nullptr };
		Node* tail{ nullptr };
		size_type counter{ 0 };

		static size_type object_counter;

		Node* new_node(const_reference data) const;
	};

	template <typename T> 
	void swap(sllist<T>& A, sllist<T>& B);
	template <typename T>
	sllist<T> operator+(const sllist<T>& A, const sllist<T>& B);
	template <typename T>
	sllist<T> operator+(const sllist<T>& A, const std::initializer_list<T> l);
	template <typename T>
	sllist<T> operator+(const std::initializer_list<T> l, const sllist<T>& A);
	
	// add this non-member, non-friend function template declaration:
	//template <typename T>
	//std::ostream& operator<<(std::ostream& os, sllist<T> const& list);
}

#include "sllist.tpp"