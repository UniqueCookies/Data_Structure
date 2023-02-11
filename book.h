#include <iostream>
#include <cctype>
#include <cstring>
//Sally Xia CS163-Remote 04/27 Wed
//This is the header file for the book class 
//Book class can create a new book, copy a book over, and display its content
//its members are author, title, publsiher and the last page left off

class book
{
	public:
		book(void); //constrcutor
		~book(void); //destructor
		
		int create_book(char author_toadd [], char title_toadd [], char publisher_toadd[], int last_page_leftoff_toadd);
		int copy_book(const book &a_new_book);
		int display(void) const;
	
	private:
		char *author;
		char *title;
		char *publisher;
		int last_page_leftoff;
};

