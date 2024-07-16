#include <iostream>
#include <cstddef>

// See the spec for structure and interface definitions!!!
namespace hlp2 {
	struct node
	{
		int value;
		node *next;
	};
	
	int			data(node const *p)			{ return p->value; }
	void		data(node *p, int newval) 	{ p->value = newval; }
	node*		next(node *p)				{ return p->next; }
	node const* next(node const *p)			{ return p->next; }
	
	
	struct sllist
	{
		node *head;
	};
	
	sllist* construct()
	{
		return new sllist { nullptr };
	}
	
	void destruct(sllist *ptr_sll)
	{
		node *q, *p;
		q = ptr_sll->head;
		p = q;
		
		while(q)
		{
			q = next(q);
			delete p;
			
			p = q;
		}
		
		delete ptr_sll;
	}
	
	bool empty(sllist const *ptr_sll)
	{
		if(ptr_sll->head == nullptr)
			return true;
		
		return false;
	}
	
	size_t size(sllist const *ptr_sll)
	{
		size_t cnt {};
		for(node *head = ptr_sll->head; head; head = next(head))
			++cnt;
		
		return cnt;
	}
	
	void push_front(sllist *ptr_sll, int value)
	{
		node* n = new node;
		n->value = value;
		
		if(empty(ptr_sll))
		{
			n->next = nullptr;
			ptr_sll->head = n;
			return;
		}
		
		n->next = ptr_sll->head;
		ptr_sll->head = n;
	}
	
	void push_back(sllist *ptr_sll, int value)
	{
		node* n = new node;
		n->value = value;
		n->next = nullptr;
		
		if(empty(ptr_sll))
		{
			ptr_sll->head = n;
			return;
		}
		
		node* tmp = ptr_sll->head;
		while(tmp->next)
		{
			tmp = next(tmp);
		}
		tmp->next = n;
	}
	
	void remove_first(sllist *ptr_sll, int value)
	{
		if(empty(ptr_sll)) return;
		
		node *p, *q;
		p = ptr_sll->head;
		q = ptr_sll->head;
		
		if(data(p) == value)
		{
			ptr_sll->head = next(p);
			delete q;
			return;
		}
		
		while(q)
		{
			if(data(q) == value)
			{
				p->next = next(q);
				delete q;
				return;
			}
			p = q;
			q = next(q);
		}
	}
	void insert(sllist *ptr_sll, int value, size_t index)
	{
		if(empty(ptr_sll))
			return;
		
		if(size(ptr_sll) < index)
		{
			push_back(ptr_sll, value);
			return;
		}
		if(index == 0)
		{
			push_front(ptr_sll, value);
			return;
		}
		
		node* tmp = new node;
		tmp->value = value;
		
		node* p = ptr_sll->head;
		node* q = p;
		
		size_t i {};
		while(q)
		{
			if( i == index )
			{
				tmp->next = next(p);
				p->next = tmp;
				return;
			}
			
			i++;
			p = q;
			q = next(q);
		}
	}
	
	node* front(sllist *ptr_sll)
	{
		if(empty(ptr_sll))
			return nullptr;
		
		return ptr_sll->head;
	}
	
	node const* front(sllist const *ptr_sll)
	{
		if(empty(ptr_sll))
			return nullptr;
		
		return (node const*)ptr_sll->head;
	}
	
	node* find(sllist const *ptr_sll, int value)
	{
		if(empty(ptr_sll))
			return nullptr;
		
		node* p;
		p = ptr_sll->head;
		
		while(p)
		{
			if(data(p) == value)
				return p;
			
			p = next(p);
		}
		
		return nullptr;
	}
}

/*
// Private functions must be declared and defined in an anonymous namespace!!!
namespace {
	hlp2::node* create_node(int value, hlp2::node* next)
	{
		return new hlp2::node {value, next};
	}
}
*/