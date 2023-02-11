#include "animal.h"
using namespace std;

//This is the member function file for the animal class
//You are able to add an animal profile, copy over an animal profile, retrieve an animal file and display an animal file
/*member contains:
	char *breed;
	char *category;
	char *personality;
	char *purpose;
	char *size;
	char *keyword;
	char *price;
*/

//constructor: initalize for the animal class
animal::animal(void)
{
	breed = category = personality = purpose = size =keyword = price=nullptr;
}

//destructor: deallocate all dynamic memory
animal::~animal(void)
{
	if(breed)
		delete []breed;
	if(category)
		delete []category;
	if(personality)
		delete []personality;
	if(purpose)
		delete []purpose;
	if(size)
		delete []size;
	if(keyword)
		delete []keyword;
	if(price)
		delete []price;
}

//create an animal - create jsut the right size for each member function of the animal class
int animal::create_animal(char *breed_toadd, char *category_toadd, char *personality_toadd, char *purpose_toadd, char *size_toadd, char *keyword_toadd, char *price_toadd)
{
	if(!breed_toadd || !keyword_toadd)
		return 0; //unable to create since the breed info is blank or keyword is missing

	//make sure the member functions are null before adding
	if (breed)
		delete []breed;
	if(category)
		delete []category;
	if(personality)
		delete []personality;
	if(purpose)
		delete []purpose;
	if(size)
		delete []size;
	if(keyword)
		delete []keyword;
	if(price)
		delete []price;
	
	breed = category = personality = purpose = size =keyword = price=nullptr;

	//adding information
	breed = new char [strlen(breed_toadd)+1];
	strcpy(breed, breed_toadd); 

	if(category_toadd)
	{
		category = new char [strlen(category_toadd)+1];
		strcpy(category, category_toadd);
	}

	if(personality_toadd)
	{
		personality = new char[strlen(personality_toadd)+1];
		strcpy(personality, personality_toadd);
	}

	if(purpose_toadd)
	{
		purpose = new char [strlen(purpose_toadd)+1];
		strcpy(purpose, purpose_toadd);
	}

	if(size_toadd)
	{
		size = new char [strlen(size_toadd)+1];
		strcpy(size, size_toadd);
	}
	
	keyword = new char [strlen(keyword_toadd)+1];
	strcpy(keyword, keyword_toadd);
	
	if(price_toadd)
	{
		price = new char [strlen(price_toadd)+1];
		strcpy(price,price_toadd);
	}
	return 1;

}

//copy from an animal to another animal
int animal::copy_animal(const animal &new_animal)
{
	return create_animal(new_animal.breed, new_animal.category, new_animal.personality, new_animal.purpose, new_animal.size, new_animal.keyword, new_animal.price);
}	

//find if there is a matching breed
//return 0 if no find
//copy over data to animal &find if there is a match
int animal::retrieve(char *keyword_tofind, animal &found) const
{
	if(retrieve(keyword_tofind)!=0)
		return 0; //no match

	//match copy over data	
	return found.create_animal(breed,category,personality,purpose,size,keyword,price);
}

//see if there is a matching keyword
int animal::retrieve(char *keyword_tofind) const
{
	return strcmp(keyword,keyword_tofind);
}

//find matching keyword and then copy over data
int animal::retrieve_personality(char *key, animal &found) const
{
	if(strcmp(personality,key)==0)
		return found.create_animal(breed,category,personality,purpose,size,keyword,price);
	return 0; //no matching data
}

//display animal info	
int animal::display(void) const
{
	if(!breed)
		return 0; //animal does not exist
	

	cout <<"Category: "<<category<<'\t'<<"Breed: "<<breed<<'\t'<<"Personality: "<<personality<<endl
	     <<"Purpose: "<<purpose<<'\t'<<"Size: "<<size<<'\t'<<"Keyword: "<<keyword<<'\t'<<"Price: "<<price<<endl<<endl;
	return 1;
}

//provide keyword for hashtable
int animal::key(char *key_value)
{
	if(!keyword)
		return 0; //keyword does not exist
	strcpy(key_value,keyword);
	return 1;
}

//provide personality for hashtable2
int animal::key2(char *value2)
{
	if(!personality)
		return 0; //personality does not exist
	strcpy(value2,personality);
	return 1;
}

//compare the breed to decide if breed to add is bigger or smaller than the data.breed
//return a negative number when the compared data has a lower value ->
int animal::compare_breed(animal &data) const
{
	if(!breed || !data.breed||!data.personality || !personality)
		return 0; //animal is missing error

	int compare = strcmp(breed, data.breed);

	if(!compare) //breed matches
		return strcmp(personality,data.personality); //compare personality

	return strcmp(breed,data.breed); //compare breed
}


//find if the breed to find matches the breed
int animal::find_breed(char *breed_tofind) const
{
	return strcmp(breed,breed_tofind);
}

//compare if the size is an exact match
int animal::compare_size(char *size_tocompare) const
{
	return strcmp(size,size_tocompare);
}

//find a matching personality
int animal::find_personality(char *personality_tofind) const
{
	return strcmp(personality,personality_tofind);
}

//find if it is a dog
int animal::find_dogs() const
{
	char category_tofind [4] = "dog";
	return strcmp(category,category_tofind);
}
