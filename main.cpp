#include "list.h"
using namespace std;

//Sally Xia CS163 04/10
//This is the cleint program where the program will be tested. 
//It will display an user interface where users can choose which program he would like to run

//Prototypes for all the details for each choice
void choice_1(list &parks);
void choice_3(list &parks);
void choice_4(list &parks);
void choice_5(list &parks);
void choice_6(list &parks); 

int main()
{
	int choice = 0;
	list parks;

	do
	{
		cout <<"1. add a new park 2. display all stored parks 3.add amenity to a park"<<endl
		     <<"4.display amenities of a park 5. delete a specific park 6.find a park with certain amenity 0. quit"<<endl;
		cin>>choice;
		cin.ignore(100, '\n');

		if (choice ==1)
			choice_1(parks);
		
		if (choice ==2)
		{
			int result = parks.display();
			if (!result)
				cout<<"Sorry, there is no park stored. Please enter a new park name."<<endl;
			cout<<endl;
		}

		if (choice ==3)
			choice_3(parks);
		if (choice ==4)
			choice_4(parks);

		if (choice ==5)
			choice_5(parks);
		if (choice ==6)
			choice_6(parks);

	} while (choice!=0);
	return 0;
}
//Choice 1 adds a new park to the park list
void choice_1(list &parks)
{
	char name [100]="\0";

	cout <<"Please enter the new park's name: ";
	cin.get(name,100, '\n');
	cin.ignore(100, '\n');

	int result = parks.add(name);
	if (result==0)
		cout<<"This park's name is already in the list. It cannot be added again."<<endl;
	cout<<endl;
}
//choice 3 add an amenity to an existing park
void choice_3(list &parks)
{
	char name[100]="\0";
	cout <<"Please enter the park's name you want to add: ";
	cin.get(name,100,'\n');
	cin.ignore(100, '\n');

	char info [100]="/0";
	int rating = 0;

	cout <<"Please enter the amenity for this park: ";
	cin.get(info, 100, '\n');
	cin.ignore(100, '\n');

	cout <<"Please enter the rating for this amenity(1-10): ";
	cin>>rating;
	cin.ignore(100, '\n');
	int message = parks.add_amenity(name,info, rating);
	if (!message)
		cout <<"Information you entered cannot be added. Please make sure this park exists and the rating for amenity is between 1-10."<<endl;
	cout<<endl;
}

//choice 4 display all amenities for a certain park
void choice_4(list &parks)
{
	char name[100]="\0";
	cout <<"Please enter the park's name you want to display amenities for: ";
	cin.get(name,100, '\n');
	cin.ignore(100, '\n');

	int message = parks.display_amenity(name);
	if(!message)
		cout<<"The amenity list could be empty or the park may not exist."<<endl;
	cout <<endl;
}

//choice 5 delete a park from the stored list
void choice_5(list &parks)
{
	char name[100]="\0";
        cout <<"Please enter the park's name you want to delete: ";
        cin.get(name,100,'\n');
        cin.ignore(100, '\n');

        int message=parks.remove_park(name);
        if(!message)
        	cout<<"This park name does not exist. Unable to delete."<<endl;
        else
                cout<<"Delete is succssful."<<endl;
	cout <<endl;
}

//choice 6 searches for an amenity from all dog parks
void choice_6(list &parks)
{
	char amenity[100]="\0";
	cout <<"Please enter the amenity you want to find from the dog parks: ";
	cin.get(amenity,100, '\n');
	cin.ignore(100, '\n');
	cout <<"The parks with amenity "<<amenity<<" are: "<<endl;
	int message =parks.find_amenity_park(amenity);
	if (!message)
		cout<<"Sorry, there is no park recorded that matches this amenity."<<endl;
	cout <<endl;
}

