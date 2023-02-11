#include "stack.h"
//Sally Xia CS163-remote 04/28
//This is the header file for assignment class
//assignment class is able to create an assignment, add books to the assignment, delete the book on the top of the asssignment
//peek the first book in the assignment, copy over an assignment, and display all information in the assignment including the stack of books
//It can decide if there is a matching assignment
//each assignment has a stack object which contains a stack of books

class assignment
{
	public:
		assignment(void); 
		~assignment(void);
		int create_assignment(char name_toadd[], char course_toadd[], char date_toadd[]); //combine user input into an assignment object
		int add_books(const book &to_add);//add the book to an assignment
		int delete_books(); //pop the top of the book off the stack
		int peek_book(book &found_at_top);//peek the book on the top of the stack
		int copy_assignment(const assignment &new_assignment);//copy assignment over to another assignment
		int display(void) const;
		int match_assignment(char name_tomatch[]); //find matching assignment
			

	private:
		char *name;
		char *course;
		char *due_date;
		stack books;
};
