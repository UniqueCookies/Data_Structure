#include "queue.h"
using namespace std;

//Sally Xia CS163-remote
//This is where testing happens. User interface is created to test all functions

//PROTOTYPE - for each choice
void add_assignment(queue &queue1);
void add_books(queue &queue1);
void delete_books(queue &queue1);
void display_all(queue &queue1);
void display_a_book(queue &queue1);

int main()
{
	stack stack1;
	queue queue1;
	//choice for the interface menu
	int choice =0;
	//menu interface
	do
	{
		cout<<"1. Add an assignment."<<endl;
		cout<<"2. Add books to an assignment. "<<endl;
		cout<<"3. Delete a book from an assignment. "<<endl;
		cout<<"4. Display all assignments with its reference books."<<endl;
		cout<<"5. Display the book on the top for a particular assignment."<<endl;
		cout<<"6. Dequeue the first assignment. "<<endl;
		cout<<"7. Peak the first assignment."<<endl;
		cout<<"0. quit."<<endl;
		cin>>choice; cin.ignore(100, '\n');
		if (choice ==1)
			add_assignment(queue1);
		if (choice ==2)
			add_books(queue1);
		if (choice ==3)
			delete_books(queue1);
		if (choice ==4)
			display_all(queue1);
		if (choice ==5)
			display_a_book(queue1);
		if (choice ==6)
		{
			if(!queue1.dequeue())
				cout <<"There is nothhing to dequeue. The queue is already empty."<<endl;
			else
				cout <<"The first assignment is sucessfully deleted."<<endl;
		}
		if (choice==7)
		{
			if(!queue1.peek())
				cout <<"The queue is empty. Nothing to peek."<<endl;
		}
			
		cout<<endl;
	}while(choice!=0);

	return 0;
}
//choice 1: add assignment to the queue. does not add books	
void add_assignment(queue &queue1)
{
	assignment add;
	char name[100];
        char course[100];
        char date[100];
		
	cout<<"Please enter the assignment's name: ";
	cin.get(name,100,'\n'); cin.ignore(100, '\n');
        cout<<"Please enter the course number for this assignment: ";       
	cin.get(course,100,'\n'); cin.ignore(100, '\n');
        cout<<"Please enter the date for this assignment: ";
        cin.get(date,100,'\n'); cin.ignore(100, '\n');
	
	if(add.create_assignment(name,course,date))
		queue1.enqueue(add);
	else
		cout <<"Error: the assignment was not added succesfully."<<endl;
}
//choice 2. add a book to a certain assignment
void add_books(queue &queue1)
{
	book toadd;
	//book info
      	char title[100];
        char author[100];
        char publisher[100];
        int last_page_leftoff=0;
	//find assignment
	char name_tomatch[100];
	cout <<"Please enter the assignment name you would like to modify: ";
	cin.get(name_tomatch,100,'\n'); cin.ignore(100, '\n');
	
	//enter book info
	cout <<"Please enter the title of the book: ";
        cin.get(title,100,'\n');
        cin.ignore(100,'\n');
        cout <<"Please enter the author for this book: ";
        cin.get(author,100,'\n');
        cin.ignore(100,'\n');
        cout <<"Please enter the publisher for this book:";
        cin.get(publisher,100,'\n');
        cin.ignore(100,'\n');
        cout <<"Please enter the page where you left off: ";
        cin>>last_page_leftoff;
        cin.ignore(100,'\n');
	
	//create a book
	toadd.create_book(title,author,publisher,last_page_leftoff);
	if(queue1.enqueue_books(toadd,name_tomatch))
		cout <<"The book is succesfully added to assignment "<<name_tomatch<<endl;
	else
		cout <<"Error: this assignment may not exist."<<endl;
}
//choice 3. delete the top of stack from a certain assignment
void delete_books(queue &queue1)
{
	//find assignment
	char name_tomatch[100];
	cout <<"Please enter the assignment name you want to modify: ";
	cin.get(name_tomatch,100,'\n'); cin.ignore(100,'\n');
	
	if(queue1.dequeue_books(name_tomatch))
		cout <<"The book on top of the stack is deleted." <<endl;
	else
		cout <<"Error: this assignment may not exist or the book stack is empty."<<endl;
}

//choice 4. display everything including the stack of books
void display_all(queue &queue1)
{
	if(!queue1.display_queue())
		cout<<"Error: assignments queue could be empty."<<endl;

}	
//display the top of stack from a certain book
void display_a_book(queue &queue1)
{
	book tofind;
	char name_tomatch[100];
	cout <<"Please enter the assigment's name to display its book stack."<<endl;
	cin.get(name_tomatch,100,'\n');	cin.ignore(100,'\n');

	if(queue1.display_a_book(name_tomatch,tofind))
		tofind.display();
	else
		cout <<"Error: the assignment may not exist or the book stack is empty."<<endl;

	
}
	
