#include "dog_park.h"
using namespace std;

//Sally Xia CS163 04/10 Prog1
//This .cpp contains all the member functions for dog_park.h file
//It will add an amenity, sort amenity by its rating, display all amenitiies,and find if the amenity exists

//constructor: Initialize the dog_park class which contains head and tail pointer
dog_park::dog_park()
{
	head=tail=nullptr;
}

//deallocating the memory hold by the dog_park class
dog_park::~dog_park()
{
	node_amenity *temp = head;
	while(head)
	{
		temp = head->next;
		delete head;
		head = temp;
	}
	tail = nullptr;
}

//Wrapper function. it will catch the information entered by the suer. Then pass it to the sort function
//The sort function will then insert the information at the right place of LLL
int dog_park::add(char info_toadd[],int rating_toadd)
{
	//if rating is 0, or no info was passed here, it will return 0 and display error message
	if (!info_toadd || !rating_toadd)
		return 0;

	//a temp node is created to catch the information
	node_amenity * temp = new node_amenity;
	temp->data.info = new char [strlen(info_toadd)+1];
	strcpy(temp->data.info, info_toadd);
	temp->data.rating = rating_toadd;

	//Use the subprogram sort to insert the new amenity to the right place
	sort(temp);

	return 1;

}

//This is a sub program of the "add" function
//It will insert the temp node into the correct place of LLL
//It will rank by rating order
int dog_park::sort(node_amenity *temp)
{
	//empty list
	if(!head)
	{
		head = temp;
		head->next = nullptr;
		tail = head;
		return 1;
	}
	
	//add at the beginning
	if (head->data.rating<temp->data.rating)
	{
		temp->next = head;
		head = temp;
		return 1;
	}

	//Non-empty list
	node_amenity *current = head;
	while(current->next && current->next->data.rating>=temp->data.rating)
		current = current->next;

	//insert if it is not at the end of the list
	if (current->next)
	{
		temp->next = current->next;
		current ->next = temp;
		return 1;
	}

	//if at the end
	if (!current->next)
	{
		current->next = temp;
		temp->next = nullptr;
		tail = temp;
		return 1;
	}

	return 0; //info did not get inserted

}

//Will display all the amenity with its raiting entered so far. 
//return 0 if the LLL is empty
int dog_park::display()
{
	//empty list
	if (!head)
		return 0;

	node_amenity *temp = head;
	while(temp)
	{
		cout <<"Amenity: "<<temp->data.info<<'\t'<<"Rating: "<<temp->data.rating<<endl;
		temp=temp->next;
	}
	return 1;
}

//Find if this dog park has the amenity user is looking for
//return 1 is found. return 0 if it does not exist
int dog_park::find(char info_todisplay[])
{
	node_amenity *current = head;
	while(current && strcmp(current->data.info,info_todisplay)!=0)
		current = current->next;
	

	//return 0 if at the end of the list
	if (!current)
		return 0;
	return 1;
}
