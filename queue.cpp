#include "queue.h"
using namespace std;
//Sally Xia CS163-remote 04/28
//This contains the member functions for the queue class
/*struct q_node
	assignment project;
	q_node *next;
class queue
	q_node *rear;
*/

//Intialize queue class
queue::queue(void)
{
	rear = nullptr;
}

//deallocate all information
queue::~queue(void)
{
	if(!rear)
		return;
	q_node *temp = rear->next;

	while(temp && temp !=this->rear)
	{
		rear->next = temp->next;
		delete temp;
		temp = rear->next;
	}
	if (rear)
		delete rear;
	temp =rear = nullptr;
}

//add an assignment to the queue
int queue::enqueue(const assignment &to_add)
{
	//empty list
	if(!rear)
	{
		rear = new q_node;
		rear -> next = rear;
		//adding information		
		rear ->project.copy_assignment(to_add);
		return 1;
	}

	q_node *temp = rear ->next;
	//nonempty list
	rear->next = new q_node;
	if(!rear->next->project.copy_assignment(to_add))
		return 0;
	rear = rear->next;
	rear ->next = temp;

	return 1;
}

//add a book to a certain assignment
int queue::enqueue_books(const book &to_add, char name[])
{
	q_node *temp = rear;
	if(find_assignment(name,temp))
	{
		temp->project.add_books(to_add);
		return 1;
	}
	
	return 0;
}

//find the assignment that matches the user input 
//return 1 if the assignment is found and then modify temp
//return 0 if the assignment is not found
int queue::find_assignment(char name[], q_node *&temp)
{
	//empty list
	if(!rear)
		return 0;
	if(rear->project.match_assignment(name))
	{
		temp = rear;
		return 1;
	}
	//traverse through the list to find a matching assignment name
	q_node * traverse = rear->next;
	while(!traverse->project.match_assignment(name) && traverse!=rear)
		traverse = traverse->next;
	//if there is a mtach
	if(traverse->project.match_assignment(name))
	{
		temp=traverse;
		return 1;
	}
	return 0;
}
//dequeue the first assignment
int queue::dequeue()
{
	//empty list
	if(!rear)
		return 0;	

	//1 item list
	if (rear->next == rear)
	{
		delete rear;
		rear=nullptr;
		return 1;
	}

	q_node *temp = rear->next->next;
	delete rear->next;
	rear->next = temp;

	return 1;
}

//pop the book from a certain assignment
int queue::dequeue_books(char name[])
{
	q_node *temp = rear;
	if(find_assignment(name, temp))
	{
		temp->project.delete_books();
		return 1;
	}

	return 0;
}

//peek the first assignment with its stack of books
int queue::peek()
{
	//empty list
	if(!rear)
		return 0;
	if(rear->next->project.display())
		return 1;
	return 0;	
}
//display everything in the queue with its reference books
int queue::display_queue(void) const
{
	if(!rear)
		return 0; //empty list
	q_node *temp = rear->next;
	while(temp && temp !=this->rear)
	{
		temp->project.display();
		temp = temp->next;
	}
	rear->project.display();
	return 1;
}
//display the matching assignment's book on the top
int queue:: display_a_book(char name[], book &tofind)
{
	q_node *temp = rear;
	if(find_assignment(name,temp))
		return temp->project.peek_book(tofind);
	return 0;
}
