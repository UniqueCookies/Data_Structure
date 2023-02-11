#include "table.h"
#include <fstream>

using namespace std;

//Sally Xia CS163 Remote 05/09
//This is the testing program to explore bugs and efficiency of the program

//PROTOTYPE
//Testing animal class
int add_animal(animal &an_animal);
void display_animal(animal &an_animal);
void retrieve_animal(animal &an_animal, animal &find);
//again
bool again();
//Testing table class
void add(table &a_table,animal &an_animal);
int retrieve_animals(table &a_table,animal found[]);
int retrieve_personality(table &table2);
int delete_animals(table &a_table);
//Load from Exeternal Data File
int load(table &table1);

int main()
{
	animal animal1;
	animal find;	
	animal found [100];	
	animal library[100];
	int size = 0; //record the retrieval information size
	table table1;	
	int choice =0;
	do
	{
		cout <<"1. Add an animal."<<endl;
		cout <<"2. Display all added animal with simi sorted by keyword."<<endl;
		cout <<"3. Find animals that match a certain keyword."<<endl;
		cout <<"4. Display animals found that match the keyword."<<endl;	
		cout <<"5. Delete animals with a certain keyword."<<endl;
		cout <<"6. Load aniamls from animal.txt"<<endl;
		cout <<"7. Display animals that match a certain personality."<<endl;
		cout <<"0. Quit."<<endl<<endl;
		cin>>choice; cin.ignore(100,'\n');
	
		if(choice ==1)
		{
			if(add_animal(animal1))
				add(table1,animal1);
		}
		else if(choice==2)
		{
			if(!table1.display_all())
				cout <<"Sorry the table is empty."<<endl;
			
		}
		else if(choice==3)
			size=retrieve_animals(table1,found);
		else if(choice==4)
		{
			if(!table1.display_keyword(found,size)) //functions in the table class
				cout <<"There was no matching results with the keyword."<<endl;
		}
		else if(choice ==5)
			delete_animals(table1);
		else if(choice ==6)
		{
			if(!load(table1))
				cout <<"Error: Unable to load the file."<<endl;
		}
		else if(choice ==7)
		{
			retrieve_personality(table1);
		}		
			
	}while(choice!=0);
	
	return 0;
}
//read info from the txt file and load the information into the animal
int load(table &table1)
{
	ifstream file_in;
	
	file_in.open("animals.txt");

	if(!file_in)
		return 0; //connection is not made


	//create varilable
	char breed[100];
	char category[100];
	char personality[100];
	char purpose [100];
	char size[100];
	char keyword[100];
	char price[100];
	animal to_add;

	file_in.get(breed,100, '|');
	file_in.ignore(100,'|');
	while (!file_in.eof())
	{	
		file_in.get(category,100,'|'); file_in.ignore(100,'|');	
		file_in.get(personality,100,'|'); file_in.ignore(100,'|');	
		file_in.get(purpose,100,'|'); file_in.ignore(100,'|');	
		file_in.get(size,100,'|'); file_in.ignore(100,'|');	
		file_in.get(keyword,100,'|'); file_in.ignore(100,'|');	
		file_in.get(price,100,'\n'); file_in.ignore(100,'\n');	
		
		if(to_add.create_animal(breed,category,personality,purpose,size,keyword,price))
			add(table1,to_add);
		file_in.get(breed,100,'|'); file_in.ignore(100, '|');
	}

	file_in.close();

	return 1;

}
//delete animals with a certain keyword
int delete_animals(table &a_table)
{
	char keyword[100];
	cout <<"Please enter the keyword you would like to delete: "<<endl;
	cin.get(keyword,100,'\n'); cin.ignore(100,'\n');

	int result=a_table.delete_animals(keyword);
	cout <<"There is/are " <<result <<" animals that match with this keyword was/were deleted."<<endl;
	return result;
}
//retrieve a keyword
int retrieve_animals(table &a_table, animal found[])
{
	char keyword[100];
	cout <<"Please enter the keyword you want to find for this animal:"<<endl;
	cin.get(keyword,100,'\n'); cin.ignore(100,'\n');
	int result = a_table.retrieve(keyword,found);	 //function in the table class
	if(!result)
		cout <<"There could be no matching result or the keyword is smaller than 4 letters."<<endl;
	else	
		cout <<"There are "<<result<<" results that match with this keyword."<<endl;	
	return result;
}
		
int retrieve_personality(table &table2)
{
	char key[100];
	cout <<"Please enter the personality you wish to find in an animal: "<<endl;
	cin.get(key,100,'\n'); cin.ignore(100,'\n');

	int result = table2.display_personality(key);
	if(!result)
		cout <<"There could be no matching result or the personality word is smaller than 3 letters."<<endl;
	return result;
}
//Add an animal to the table
void add(table &a_table, animal &an_animal)
{
	char key[100];
	char key2[100];
	if(!an_animal.key(key) || !an_animal.key2(key2))
	{
		cout <<"Error: This animal has no keyword or personality."<<endl;
		return;
	}
	if(!a_table.insert(key,key2,an_animal))
		cout <<"Error: The animal cannot be added to the list."<<endl;
}
//create loop
bool again()
{
	char result = 'N';
	cout <<"Do it again? ";
	cin>>result; cin.ignore(100, '\n');
	
	if(result == 'Y')
		return 1;
	return 0;
}


//retreive an animal
void retrieve_animal(animal &an_animal, animal &find)
{
	char keyword[100];
	
	cout <<"Please enter the keyword of the dog you want to find: ";
	cin.get(keyword, 100, '\n'); cin.ignore(100, '\n');

	if(an_animal.retrieve(keyword, find))
		find.display();
	else
		cout <<"Error: This animal does not exist."<<endl;
}

//adding a new aniaml
int add_animal(animal &an_animal)
{
	char breed[100];
	char category[100];
	char personality[100];
	char purpose[100];
	char size[100];
	char keyword[100];
	char price[100];

	cout <<"Please enter the category for this animal: ";
	cin.get(category,100,'\n'); cin.ignore(100,'\n');
	
	cout <<"Please enter the breed for this animal: ";
	cin.get(breed, 100, '\n'); cin.ignore(100,'\n');

	cout <<"Please enter the personality for this animal: ";
	cin.get(personality,100,'\n'); cin.ignore(100,'\n');

	cout <<"Please enter the purpose for this animal: ";
	cin.get(purpose, 100, '\n'); cin.ignore(100, '\n');

	cout <<"Please enter the size for this animal: ";
	cin.get(size, 100,'\n'); cin.ignore(100, '\n');

	cout <<"Please enter the keyword for this animal: ";
	cin.get(keyword, 100, '\n'); cin.ignore(100,'\n');

	cout <<"Please enter the price to purchase this animal: $";
	cin.get(price,100,'\n'); cin.ignore(100, '\n');

	int result = an_animal.create_animal(breed,category,personality,purpose,size,keyword,price);
	if(!result)
		cout <<"Error: Was not able to add the animal. Make sure the keyword has more than 4 characters"<<endl;
	return result;
}

//display an animal
void display_animal(animal &an_animal)
{
	if(!an_animal.display())
		cout <<"Sorry, this animal does not exist."<<endl;
		
}

