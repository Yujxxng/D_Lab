
#ifndef FT_H
#define FT_H
//-------------------------------------------------------------------------
#include <iostream>

namespace hlp2 {

template <typename T> void swap(T &lhs, T &rhs);
template <typename T> void display(const T* a, const T* b);
template <typename T> void swap_ranges(T* a, T* b, T* c);
template <typename T> T* remove(T* start, T* end, const T& n);
template <typename T1, typename T2> int count(T1* start, T1* end, const T2& n);
template <typename T1, typename T2> T1* find(T1* start, T1* end, const T2& value);
template <typename T1, typename T2> T2* copy(const T1* start, const T1* end, T2* value);
template <typename T1, typename T2> void fill(T1* start, T1* end, T2 value);
template <typename T1, typename T2> void replace(T1* start, T1* end, T2 olditem, T2 newitem);
template <typename T> T* min_element(T* start, T* end);
template <typename T> T* max_element(T* start, T* end);
template <typename T1, typename T2> bool equal(T1* start1, T1* end, T2* start2);
template <typename T> T sum(T* start, T* end);

template <typename T> void swap(T& lhs, T& rhs)
{
	T tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}
template <typename T> void display(const T* a, const T* b)
{
	for (auto it = a; it < b; it++)
	{
		if (it == (b - 1))
		{
			std::cout << *it;
			break;
		}
		std::cout << *it << ", ";
	}
	std::cout << "\n";
}
template <typename T> void swap_ranges(T* a, T* b, T* c)
{
	for (auto it = a; it < b; it++)
	{
		T tmp = *it;

		*it = *c;
		*c = tmp;
		c++;
	}
}
template <typename T> T* remove(T* start, T* end, const T& n)
{
	bool flag = true;
	while (true)
	{
		for (auto it = start; it < end - 1; it++)
		{
			if (*it == n)
			{
				swap(*it, *(it + 1));
				flag = false;
			}
		}

		if (flag)
			break;
		else
			flag = true;

		end--;
	}

	if (*(end - 1) == n)
		end--;

	return end;
}
template <typename T1, typename T2> int count(T1* start, T1* end, const T2& n)
{
	int cnt = 0;
	for (auto it = start; it != end; it++)
	{
		if (*it == n)
			cnt++;
	}

	return cnt;
}
template <typename T1, typename T2> T1* find(T1* start, T1* end, const T2& value)
{
	for (; start != end; ++start)
	{
		if (*start == value)
			return start;
	}

	return end;
}
template <typename T1, typename T2> T2* copy(const T1* start, const T1* end, T2* value)
{
	for (; start != end; ++start, ++value)
		*value = *start;

	return value;
}
template <typename T1, typename T2> void fill(T1* start, T1* end, T2 value)
{
	for (; start != end; ++start)
		*start = value;
}
template <typename T1, typename T2> void replace(T1* start, T1* end, T2 olditem, T2 newitem)
{
	for (; start != end; ++start)
	{
		if (*start == olditem)
			*start = newitem;
	}
}
template <typename T> T* min_element(T* start, T* end)
{
	if (start == end)
		return end;

	T* smallest = start;

	while (++start != end)
	{
		if (*start < *smallest)
			smallest = start;
	}

	return smallest;
}
template <typename T> T* max_element(T* start, T* end)
{
	if (start == end)
		return end;

	T* biggest = start;

	while (++start != end)
	{
		if (*biggest < *start)
			biggest = start;
	}

	return biggest;
}
template <typename T1, typename T2> bool equal(T1* start1, T1* end, T2* start2)
{
	for (; start1 != end; ++start1, ++start2)
	{
		if (!(*start1 == *start2))
			return false;
	}

	return true;
}
template <typename T> T sum(T* start, T* end)
{
	if (start == end)
		return *start;

	T res = *start;
	while (++start != end)
	{
		res = res + (*start);
	}
	return res;
}
}

#endif
