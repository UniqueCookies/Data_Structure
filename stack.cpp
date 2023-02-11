#include "stack.h"
//Sally Xia 04/27 Wed CS163-online
//This file contains all the member functions for the stack class
/* In a node contains:
	book *books;
	node *next;
   Stack class contains:
   	node *head;
	int top_index; -- cannot be bigger than 3
*/

//constructor: initialize top_index and set head to null
stack::stack()
{
	head=nullptr;
	top_index=0;
}

//Deallocate all dynamic memory. It will go through every node;
stack::~stack()
{
	while(head)
	{
		node *temp = head->next;
		delete []head->books;
		delete head;
		head=temp;
	}

	head=nullptr;
	top_index=0;


}

//add a new book to the top, if it is impossible to add a book will return 0
int stack::push(const book &to_add)
{
	//If there is no entry
	if (!head)
	{
		head = new node;
		head->next=nullptr;
		top_index=0;
		head->books = new book[MAX];
		if(!head->books[top_index].copy_book(to_add))
			return 0; //adding was not succesfull
		++top_index;
		return 1;
	}

	//If the list is not empty
	if(top_index<MAX)
	{
		if(!head->books[top_index].copy_book(to_add))
			return 0;
		++top_index;
		return 1;
	}

	//If the list is full. Ready to make a new node
	if(top_index==MAX)
	{
		node*temp=head;
		head=new node;
		head->books = new book[MAX];
		head->next=temp;
		top_index=0;
		if(!head->books[top_index].copy_book(to_add))
			return 0;
		++top_index;
		return 1;
	}

	return 0;
}

//delete books stored at the top of the stack
//return 0 if the stack is empty
int stack::pop(void)
{
	//empty list
	if (!head)
	{	
		top_index=0;
		return 0; //Nothing to delete
	}
	
	//if the index is greater than 1
	if(top_index>1)
	{
		--top_index;
		return 1;
	}

	//If the index is 0. Need to release dynamic memory
	if(top_index==1)
	{
		node*temp = head->next;
		if (head->books)
			delete []head->books;
		delete head;
		head = temp;
		top_index=MAX;
		if(!head)
		{
			top_index=0;
			return 0;
		}
		return 1;
	}
	return 0;
}
//peak the book on top of the stack and then modefy book &found_at_top to get the book info
int stack::peek(book &found_at_top) const
{
	//empty list
	if(!head)
		return 0;
	
	//if the top_index=0 go to the next node;
	if(top_index==0 && head->next)
		return found_at_top.copy_book(head->next->books[MAX]);

	//if the top_index!=0
	if(top_index>0)
		return found_at_top.copy_book(head->books[top_index-1]);
	
	return 0;
		


}

//This function will display all the books from the most recent entry to the first entry
int stack::display_all(void) const
{
	int tracking = top_index-1;
	if(!head)
		return 0;
	node*temp = head;
	while(temp)
	{
		while(tracking>=0)
		{
			temp->books[tracking].display();
			--tracking;
		}
		temp=temp->next;
		tracking=MAX-1;
	}
	return 1;
		

}

