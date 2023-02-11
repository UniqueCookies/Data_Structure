#include "animal.h"

//Sally Xia CS163-Remote Prog 4 05/09
//This is the header file for the table class. It is able to insert, retrieve, remove data and it contains the hash function to implement the key. 

struct node
{
	animal data;
	node *next;
};

class table
{
	public:
		table(int size = 11, int size2 = 11); //Table needs to be prime numbers
		~table(void);
		int insert(char *key_value, char *valeu2, const animal &to_add);
		int retrieve (char *keyword, animal found[]) const;
		int display_personality(char *key) const;
		int display_keyword(animal found[], int size);
		int display_all(void)const; 
		int delete_animals(char *keyword);

	private:
		node **hash_table;
		int hash_table_size;
		node **hash_table2;
		int hash_table_size2;
		int hash_function( char *key) const; //hash function
		int hash_function2(char *key2) const; //hash function #2
		int delete_animals(node *&head,char *keyword);

};

