#include <iostream>
#include <cctype>
#include <cstring>

//Sally Xia CS163 remote 05/09
//This is the header file for the animal class
//You are able to add an animal profile, copy over an animal profile, retrieve an animal file and display an animal file

class animal
{
	public:
		animal(void);
		~animal(void);
		int create_animal(char *breed_toadd, char *category_toadd, char *personality_toadd, char *purpose_toadd, char *size_toadd, char *keyword_toadd, char *price_toadd);
		int copy_animal(const animal &new_animal);
		int retrieve(char *keyword_tofind, animal &found) const; //It will retrieve animals with the same keyword
		int retrieve(char *keyword_tofind) const; 
		int retrieve_personality(char *key, animal &found) const;
		int display(void) const;
		int key(char *key_value); //get keyword keyword
		int key2(char *value2); //get personality keyword
	private:
		char *breed;
		char *category;
		char *personality;
		char *purpose;
		char *size;
		char *keyword;
		char *price;
};
