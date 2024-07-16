// Provide include guards
// Don't include either of the following two headers: <forward_list> and <list>
// You may need to include <cstddef> for size_t [which is the largest unsigned type from the C standard library]

// All names from here on must be in namespace hlp2.
// Don't add any names that are private to the implementation source file sllist.cpp in this file.
// Necessary declarations are described in the spec.
namespace hlp2 {
	struct node;
	struct sllist;

	int			data(node const *p);
	void		data(node *p, int newval);
	node*		next(node *p);
	node const* next(node const *p);

	sllist* construct();
	void 	destruct(sllist *ptr_sll);
	bool	empty(sllist const *ptr_sll);
	size_t	size(sllist const *ptr_sll);
	void 	push_front(sllist *ptr_sll, int value);
	void	push_back(sllist *ptr_sll, int value);
	void	remove_first(sllist *ptr_sll, int value);
	void	insert(sllist *ptr_sll, int value, size_t index);
	node*	front(sllist *ptr_sll);
	node const* front(sllist const *ptr_sll);
	node*	find(sllist const *ptr_sll, int value);
}