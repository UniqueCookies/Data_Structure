#include "book.h"
//Sally Xia 04/27 Wed CS163-online
//This is the header file for the stack class
//It creates a LLL and in each node, it has a book array with size 3
//It is able to add a book to the stack, pop a book from th estack, peek the first book on the stack and display all the books from the stack
//its members are the head of the LLL and the top_index where it keeps track where information is in the array

struct node
{
	book *books;
	node *next;
};

const int MAX =3;

class stack
{
	public:
		stack();
		~stack();
		int push(const book &to_add);
		int pop(void);
		int peek(book &found_at_top) const;
		int display_all(void) const;
	private:
		node*head;
		int top_index;
};

