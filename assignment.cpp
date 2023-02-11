#include "assignment.h"
using namespace std;
//Sally Xia CS163-remote 04/28
//This file contains member functions for assignment class
/*members:
  char *name;
  char *course;
  char *due_date;
  stack books;
 */
//Initialize information
assignment::assignment(void)
{
	name=course=due_date=nullptr;
}
//destructor Deallocate all dynamic information
assignment::~assignment(void)
{
	if(name)
		delete[]name;
	if(course)
		delete[]course;
	if(due_date)
		delete[]due_date;
	name=course=due_date=nullptr;
}
//create a new assignment. it does not input data for books. 
int assignment::create_assignment(char name_toadd[], char course_toadd[], char date_toadd[])
{
	if(!name_toadd)
		return 0; //assignment must have a name
	
	if(name)
		delete[]name;
	if(course)
		delete[]course;
	if(due_date)
		delete[]due_date;

	name = new char [strlen(name_toadd)+1];
	strcpy(name, name_toadd);

	if(course_toadd)
	{
		course = new char[strlen(course_toadd)+1];
		strcpy(course,course_toadd);
	}

	if(date_toadd)
	{
		due_date = new char[strlen(date_toadd)+1];
		strcpy(due_date,date_toadd);
	}

	
	return 1;	
}
//copy over assignments. It will not copy the book stack
int assignment::copy_assignment(const assignment &new_assignment)
{ 
	return create_assignment(new_assignment.name,new_assignment.course,new_assignment.due_date);
}
//display information in the assignment 
//It will also dispaly the stack of books. and information user if the book stack is empty
int assignment::display(void) const
{
	if(!name)
		return 0; //cannot display when there is no name
	cout<<"Assignment: "<<name<<'\t';
	if(course)
		cout<<"Coure: "<<course<<'\t';
	if(due_date)
		cout <<"Due date: "<<due_date<<endl;
	cout<<"Books related to this assignments are: "<<endl;
	if(!books.display_all())
		cout <<"Sorry the book list is empty."<<endl;	
	return 1;
}
//call the stack push function
//push the book on top of the stack
int assignment::add_books(const book &to_add)
{
	return books.push(to_add);
}
//call the stack pop function
//pop the book on top of the stack
int assignment::delete_books()
{
	return books.pop();
}
//call the stack function peek
//peek the book on top of the stack for this assignment
//modify the book found
int assignment::peek_book(book &found_at_top)
{
	return books.peek(found_at_top);
}

//find if the assignment matches
//return 1 if the assignment is found
int assignment::match_assignment(char name_tomatch[])
{
	if(strcmp(name,name_tomatch)==0)
		return 1;
	
	return 0;
}

