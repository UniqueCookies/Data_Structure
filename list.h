#include "dog_park.h"

//Sally Xia CS163 04/11 Prog1
//This is the .h file to keep a list of dog parks. 
//It contains a node struct where it keeps the name of the dog park, a head pointer for the amenities and a next pointer
//The list will be sorted by the name of the park


struct node
{
	char *name;
	dog_park a_dog_park;
	node *next;
};

class list
{
	public:
		list();
		~list();	
		int add(char add_name[]);//add a new park name into the sorted alphabetical order - wrapper function	
		int display();//display all park names-wrapper function
		int add_amenity(char find_name[], char amenity_toadd[], int rating); //Find the park's name and then add the amenity
		int display_amenity(char find_name[]); //Find the park's name and then display all the amenities stored

		int remove_park(char delete_park[]); //remove a particular dog park
		int find_amenity_park(char amenity[]); //Find the park that has this amenity and then display it
	private:
		node *head;
		node *tail;
		int display(node *head); //part of the display function
		int sort(node *temp);//subfunction of "add". Will check if the name exists and then add to the correct place of the list
};
