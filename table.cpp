#include "table.h"
using namespace std;

//Sally Xia CS163-Remote Prog 4 05/09
//This is the member function file for the table class. It is able to insert, retrieve, remove data and it contains the hash function to implement the key. 
/* Node include:
	animal data;
	node *next;
    Table class include:
	node **hash_table;
	int hash_table_size;
*/

//Constructor: Initalize table array
table::table(int size, int size2) //Table needs to be prime numbers
{

	hash_table = new node *[size];
	for (int i =0; i<size; ++i)
		*(hash_table+i) = nullptr;

	hash_table_size = size;

	//hash table 2
	hash_table2 = new node *[size2];
	for (int i=0; i<size2; ++i)
		*(hash_table2+i) = nullptr;
	hash_table_size2 = size2;
	
}
		
//destructor: deallocate dynamic memory
table::~table(void)
{
	for (int i=0; i<hash_table_size; ++i)
	{
		//if that particular array elemeht is not nullptr 
		if(hash_table[i])
		{
			//hold the head pointer	and delete all the nodes from the collisions
			node *hold = hash_table[i];
			node *temp = hold->next;
			while(temp)
			{
				delete hold;
				hold = temp;
				temp = temp->next;
			}
			delete hold;
			hash_table[i]=nullptr;
		}
	}

	delete []hash_table;
	hash_table_size=0;

	//2nd hash table
	for (int i  =0; i<hash_table_size2; ++i)
	{
		if(hash_table2[i])
		{
			node *hold = hash_table2[i];
			node *temp = hold->next;
			while(temp)
			{
				delete hold;
				hold = temp;
				temp = temp->next;
			}
			delete hold;
			hash_table2[i]=nullptr;
		}
	}
	
	delete []hash_table2;
	hash_table_size2=0;

}

//Insert an animal into the table 
//Will find the key value first using hash function first.
//If the animal does not exist, then it will return 0 to show error.
int table::insert(char *key_value,char *value2, const animal &to_add)
{
	int i = hash_function(key_value); //find which array element to add
	int j = hash_function2(value2); //2nd key
	//temp node to hold animal info
	node *temp = new node;
	if(!temp->data.copy_animal(to_add))
	{
		delete temp;
		return 0; //unable to add
	}

	temp->next = hash_table[i];
	hash_table[i]=temp;

	//add to 2nd hash function
	node *hold = new node;
	hold->data.copy_animal(to_add);
	hold->next = hash_table2[j];
	hash_table2[j] = hold;
	return 1;
}

//retrieve an information with a matching keyword
int table::retrieve (char *keyword, animal found[]) const
{
	if (strlen(keyword)<5)
		return 0; //cannot find a value that is lower than 4
	//find key
	int i = hash_function(keyword);
	node *temp = hash_table[i];	
	if(!temp)
		return 0; //the chain is empty, no match find

	//traverse
	int result =0;
	while(temp)
	{
		if(temp->data.retrieve(keyword,found[result]))
			++result;
		temp = temp->next;
	}
	return result;
}

int table::display_personality(char *key) const
{
	if(strlen(key)<4)
		return 0; //key has to be at least 3 letter long
	int j = hash_function2(key);
	node *temp = hash_table2[j]; 

	if(!temp)
		return 0; //chain is emtpy
	
	//traverse
	int result = 0;
	animal find; //create object

	while(temp)
	{
		if(temp->data.retrieve_personality(key,find))
		{
			find.display();
			++result;
		}
		temp = temp->next;
	}
	return result;
}

//delete animals with a certain keyword
int table::delete_animals(char *keyword)
{
	//find key
	int i = hash_function(keyword);
	node *head = hash_table[i];
	node *previous = head;

	int result = delete_animals(head,keyword);
	hash_table[i] = head;
	return result;


}
//delete animals with a certain keyword with head pointer
int table::delete_animals(node *&head, char *keyword)
{
	//end of list or no head		
	if(!head)
		return 0;
	int result =0;
	//delete head until head does not match the data
	while(head &&!head->data.retrieve(keyword))
	{
		node *temp = head->next;
		delete head;
		head = temp;
		++result;
	}
	if(!head)
		return result;	
	node *previous = head;
	node *current = head->next;
	
	while(current)
	{
		if(!current->data.retrieve(keyword))
		{
			previous->next = current->next;
			delete current;
			current = previous->next;
			++result;
		}
		else
		{
			previous = current;
			current = current->next;
		}
	}
	return result;
	
}
	

//display information matching the keyword	
int table::display_keyword(animal found[],int size)
{
	if(!size)
		return 0; //there was no match to the keyword
	for (int i =0; i<size; ++i)
		found[i].display();
	return 1;
}
//private hash function #1: Key is using the keywords of interest 
//Assuming data uses lower letters only.
//1st * 1000 + 3rd *100 + 4th *10 + 5th *1 
//skipping 2nd letter because it is mostly a vowel
int table::hash_function(char *key) const
{
	int sum = 1000 * int (*key) + 100 * int (*(key+2)) + 10* int( *(key+3));
	sum = sum % hash_table_size;
	return sum;
}

//private hash function #2: Key is using personality
//assume data uses lower letters only. 
//(1st^3 + 2nd^10)*3rd
int table::hash_function2(char *key2) const
{
	int sum =( (int (*key2))^2 + (int(*(key2+1)))^10) *(int( *(key2+2)));
	sum = sum %hash_table_size2;
	return sum;
}
//Display all items in the table 
//Will show which member it is from
int table::display_all(void)const
{
	cout <<"Display in terms of keyword: "<<endl;

	int count = 0;
	for (int i =0; i<hash_table_size; ++i)
	{
		int display = i+1;
		if(hash_table[i])
		{
			cout <<"Chain "<<display<<" :"<<endl;
			node *temp = hash_table[i];
			while(temp)
			{
				temp->data.display();
				temp = temp->next;
			}
			++count;
		}
	}

	cout <<"Display in terms of personalities: "<<endl;
	for (int i =0; i<hash_table_size2; ++i)
	{
		int display=i+1;
		if(hash_table2[i])
		{
			cout <<"Chain "<<display<<" :"<<endl;	
			node *temp = hash_table2[i];
			while(temp)
			{
				temp->data.display();
				temp = temp->next;
			}
		}
	}
	return count;
}	


			

 
