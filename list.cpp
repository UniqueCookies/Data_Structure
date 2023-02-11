#include "list.h"
using namespace std;

//Sally Xia CS163 04/11 Prog1
//This is the .cpp file to keep the member functions for a list of dog parks. 
/*node struct contains:
	char *name;
	node *next;
	node *head;
the private section contains
	node *head;
	node *tail;
*/

//constructor: It will initialize the head and tail pointer
list::list()
{
	head = tail = nullptr;

}
//destructor: It will deallocate memory for the dog_parks_unlimited class
list::~list()
{
	node *temp = head;
	while (head)
	{
		temp = head->next;
		delete head;
		head = temp;
	}
	tail = nullptr;
}
	
//Will add the name into the LLL. Will sort it by alphabeticall order
int list::add(char add_name[])
{
	//catch the information entered into a new node
	node *temp = new node;
	temp->name = new char [strlen(add_name)+1];
	strcpy(temp->name, add_name);

	//call sort subfunction
	return sort(temp);
}

//subfunction of add: check if the name exists and add it into the correct place
int list::sort (node *temp)
{
	//empty list add at the beginning
	if(!head)
	{
		head = temp;
		head->next = nullptr;
		tail = head;
		return 1;
	}

	//add at the beginning
	if (strcmp(head->name,temp->name)>0)
	{
		temp->next = head;
		head = temp;
		return 1;
	}

	node*current = head->next;
	node *previous = head;
	while (current && strcmp(current->name,temp->name)<0)
	{
		previous = current;
		current = current->next;
	}

	//add the node at last if it has traversed to NULL
	if (!current)
	{
		tail->next = temp;
		temp->next = nullptr;
		tail = temp;
		return 1;
	}

	//name has appeared. Does not add to the list
	if (strcmp(current->name,temp->name)==0)
	{
		return 0;
	}

	previous->next = temp;
	temp->next = current;
	return 1;
}

//display all park names
int list::display()
{
	//empty list. return 0
	if (!head)
		return 0;
	
	//traverse through the list to display information
/*	node *temp = head;
	while (temp)
	{
		cout <<"Park Name: "<<temp->name<<endl;
		temp =temp->next;
	}*/

	return display(head);
}

//display function using recursive method
int list::display(node *head)
{
	if(!head)
		return 0;

	cout <<"Park Name: "<<head->name<<endl;
	return 1+display(head->next);
}

//Find if the park exists
int list::add_amenity(char find_name[], char amenity_toadd[],int rating)
{
	node *current = head;
	while (current && strcmp(current->name, find_name)!=0)
		current = current->next;

	if (!current)
		return 0;
	
	
	return current->a_dog_park.add(amenity_toadd,rating);

}

//Display all amenity for a park
int list::display_amenity(char find_name[])
{
	node *current = head;
	while(current &&strcmp(current->name,find_name)!=0)
		current = current->next;
	if (!current)
		return 0;
	return current->a_dog_park.display();
}

//remove a specific park
int list::remove_park(char delete_park[])
{
	//emptry list - cannot be deleted
	if (!head)
		return 0;

	//delete first item
	if (strcmp(head->name,delete_park)==0)
	{
		node *temp = head;
		head = head->next;
		delete temp;
		if(!head)
			tail=nullptr;
		return 1;
	}

	//part of the list
	node *previous = head;
	node *current = head;
	while(current &&strcmp(current->name,delete_park)!=0)
	{
		previous = current;
		current = current->next;
	}
	if (!current)
		return 0;
	previous->next = current ->next;
	delete current;
	if (!previous->next)
		tail = previous;
	return 1;

}

//Find the park that has its amenity and then display it 
int list:: find_amenity_park(char amenity[])
{
	node *temp = head;
	int count =0;
	while(temp)
	{
		if(temp->a_dog_park.find(amenity))
		{
			cout<<"Dog Park: "<<temp->name<<endl;
			count++;
		}
		temp = temp->next;
	}

	return count;
}

