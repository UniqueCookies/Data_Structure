#include "assignment.h"
//Sally Xia CS163-remote 04/28
//This is the header file for queue class
//It is able to add an assignment, add a book to a certain assignment, delete an assignment, delete the book from the top from a certain assignment,
//peek the first assignment with its stack of books, display the entire queue with stacks of books and display only the book on the top for a certain assignment. 

struct q_node
{
	assignment project;
	q_node *next;
};
class queue
{
	public:
		queue(void); 
		~queue(void);
		int enqueue(const assignment &to_add);
		int enqueue_books(const book &to_add,char name[]);
		int dequeue();
		int dequeue_books(char name[]);
		int peek();
		int display_queue(void) const;
		int display_a_book(char name[], book &tofind);
	

	private:
		q_node *rear;
		int find_assignment(char name[], q_node *&temp);
};
