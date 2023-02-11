#include "table.h"
using namespace std;

//Sally Xia CS163 - Remote
//This is where the table functions are tested 

//PROTOTYPE
int add_animal(animal &an_animal);
void add(table &table1);
void display(table &table1);
void display_breed(table &table1);
void display_size(table &table1);
void display_dogs(table &table1);
void delete_breed(table &table1);


int main()
{
	table table1;
	
	int choice =0;

	do
	{
		cout <<"1. add an animal."<<endl;
		cout <<"2. display all animals in sorted order."<<endl;
		cout <<"3. display animals with a certain breed."<<endl;
		cout <<"4. retrieve/display dogs with a certain breed and personality."<<endl;
		cout <<"5. delete animals with a certain breed."<<endl;
		cout <<"6. display all animals with a certain size."<<endl;
		cin>>choice; cin.ignore(100, '\n');	
	

		if(choice ==1)
			add(table1);
		if(choice ==2)
			display(table1);
		if(choice==3)
			display_breed(table1);
		if(choice ==4)
			display_dogs(table1);
		if(choice ==5)
			delete_breed(table1);

		if(choice==6)
			display_size(table1);
		
			
	}while(choice !=0);


	return 0;
}

//Option 5. Delete animals with a certain breed
void delete_breed(table &table1)
{
	char breed[100];
	cout <<"Please enter the breed of animal you would like to delete: ";
	cin.get(breed,100,'\n'); cin.ignore(100,'\n');
	int count =table1.remove(breed);
	cout <<"There are total of " <<count<<" animals deleted."<<endl;
}
//Option 4. Display dogs with a certain breed and personality
void display_dogs(table &table1)
{
	char breed[100];
	char personality[100];
	cout <<"Please enter the breed of the dog you would like to search: ";
	cin.get(breed,100, '\n'); cin.ignore(100, '\n');
	cout <<"Please enter the personality of the dog you would like to search: ";
	cin.get(personality,100,'\n'); cin.ignore(100, '\n');

	animal array[100];
	int count = table1.retrieve(array,breed,personality);		

	if(count)
	{
		cout <<"There are "<<count <<" matching dogs."<<endl;
		cout <<"Would you like to display? Y/N"<<endl;
		
		char response = 'N';
		cin>>response; cin.ignore(100,'\n');
		if(response =='Y')
		{
			for (int i =0; i<count; ++i)
				array[i].display();
		}
	}
	else
		cout <<"Sorry, there is no matching dogs."<<endl;

}
//Option 3. Display animals with a certain breed
void display_breed(table &table1)
{
	char breed[100];
	cout <<"Please enter the breed of the pet you would like to search: ";
	cin.get(breed,100,'\n'); cin.ignore(100, '\n');

	int match = table1.display_breed(breed);
	if(!match)
		cout <<"Sorry, there is no matching breed."<<endl;
	else
		cout <<"The total matching pets are: "<<match<<endl;
}

//Option 6. Display animals with a certain size
void display_size(table &table1)
{
	char size [100];
	cout <<"Please enter the size of the pet you would like to search: ";
	cin.get(size, 100, '\n'); cin.ignore(100, '\n');
	
	int match = table1.display_size(size);
	
	if(!match)
		cout <<"Sorry, there is no matching size."<<endl;
	else
		cout <<"The total matching pets are "<<match<<endl;
}
//Option 2: Display all animals
void display(table &table1)
{
	if(!table1.display())
		cout <<"Nothing to display. The list is empty."<<endl;
}

//add animal to the table
void add(table &table1)
{
	animal toadd;
	if(!add_animal(toadd))
		return;
	if(!table1.add(toadd))
		cout <<"Error: The animal cannot be added."<<endl;
	else
		cout <<"The animal is succesfully added."<<endl;
}


//add an animal
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
                cout <<"Error: Was not able to add the animal."<<endl;
        return result;
}

