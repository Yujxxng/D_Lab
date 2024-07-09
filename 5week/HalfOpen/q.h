// TODO: File documentation block required

// NOTE 1: This file should not contain any standard library includes.
// The auto-grader will not accept your submission if this file
// contains include directives.

// NOTE 2: A function documentation block provides information that is crucial
// for clients to correctly use the function. Provide a documention block
// for each declared function that contains the following information:
// What does the function do?
// What are the (types) of the parameters?
// What is the (type) of value returned by function?
// Is there any particular input that will break the function?

// NOTE 3: When uploading this file for grading, make sure to remove
// all references to the subscript operator or the [ or ] symbols. 
// It is important that even your comments should not include these symbols.

// TODO: Now, declare the necessary functions.
char const* find(char const *begin, char const *end, char val);
char const* find_any(char const *begin, char const *end, char const *vals, int len);
int count(char const *begin, char const *end, char val);
int count_any(char const *begin, char const *end, char const *vals, int len);
int compare(char const *begin1, char const *begin2, int len);
void exchange(char *begin1, char *begin2, int len);
void copy(char *dst, char *src, int len);