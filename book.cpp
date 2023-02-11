#include "book.h"
using namespace std;
//Sally Xia CS163-Remote 04/27 Wed
//This file contains the member functions of the book class
/* members contains:
   char *author
   char *title
   char *publisher
   int last_page_leftof
*/

//Initialize all the varilables
book::book(void)
{
	author=title=publisher=nullptr;
	last_page_leftoff=0;
}

//Deallocate dynamic memory and set integer to 0
book::~book(void)
{
	if(author)
		delete []author;
	if(title)
		delete []title;
	if(publisher)
		delete []publisher;
	author=title=publisher = nullptr;
	last_page_leftoff=0;
}

//Create a new book using the information entered
//Will return 0 if the book has no title. The rest of the book information is not required.
int book::create_book(char author_toadd [], char title_toadd[], char publisher_toadd[], int last_page_leftoff_toadd)
{
	if(!title_toadd)
		return 0; //the book must have a title
	if(author)
		delete []author;
	if(title)
		delete []title;
	if(publisher)
		delete []publisher;
	author=title=publisher=nullptr;

	if(author_toadd)
	{
		author = new char [strlen(author_toadd)+1];
		strcpy(author,author_toadd);
	}

	title = new char [strlen(title_toadd)+1];
	strcpy(title,title_toadd);
	
	if(publisher_toadd)
	{
		publisher = new char[strlen(publisher_toadd)+1];
		strcpy(publisher,publisher_toadd);
	}

	last_page_leftoff=last_page_leftoff_toadd;
	return 1;

}
//copy a new book to the current book
int book::copy_book(const book &a_new_book)
{
	return create_book(a_new_book.author,a_new_book.title,a_new_book.publisher,a_new_book.last_page_leftoff);
}

//display book information
//return 0 if the title does not exist
int book::display(void)const
{
	if(!title)
		return 0;
	cout <<"Title: "<<title<<'\t';
	if(author)
	cout <<"Author: "<<author<<'\t';
	if(publisher)
	cout <<"Publisher: "<<publisher<<'\t';
	cout <<"Last page left of: "<<last_page_leftoff<<endl;

	return 1;
	
}
