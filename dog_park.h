#include <iostream>
#include <cctype>
#include <cstring>

//Sally Xia CS163 04/10 
//This is the header file for a single dog park
//It will maintain a LLL of amenities that are offered in this single dog park
//Each amenity will keep the information about that amenitiy and the rating for how useful this amentiy is in a scale of 1-10. 1 being poorly done. 
//The amenities are ordered by their usefullness. 

struct amenity
{
        char *info;
        int rating;
	~amenity(){delete []info;} //deallocate dynamic memory for the char *info
};
struct node_amenity
{
	amenity data;
	node_amenity *next;
};

class dog_park
{
	public:
		dog_park(); //default constructor. It will set all information to null
		~dog_park(); //deallocate dynamic memory for this class
		int add(char info_toadd[], int rating_toadd); //add the new amenity into the amenity LLL. Sort by raiting- wrapper function
		int display();//display all amenity with its ratings
		int find(char info_todisplay[]);//check if there is matching info stored in the amenity LLL, return 1 to show that it was found

	
	private:
		node_amenity *head;
		node_amenity *tail;
		int sort(node_amenity *temp); //subfunction of "add". Sort the LLL to insert the new amenity info at the correct location of LLL
};
