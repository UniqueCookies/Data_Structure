#include "animal.h"

//Sally Xia CS163-remote Prog4
//This is the header function for the BST 

struct node
{
	animal data;
	node *left;
	node *right;
};

class table
{
	public:
		table();
		~table();
		int add(const animal &toadd);
		int display() const;
		int display_breed(char *breed_tofind);
		int retrieve (animal *array, char *breed_tofind, char *personality_tofind) const;
		int remove(char *breed_remove);
		int display_size(char *size) const;


	private:
		node *root;
		int add(const animal &toadd, node *&root);
		void remove_all(node *&root); //deconstructor
		int display(node *root) const;
		int display_size(char *size, node *root) const;
		int display_breed(char *breed_tofind, node *root);
		int retrieve(animal *array, char *breed_tofind, char *personality_tofind, node *root) const;
		int remove(char *breed_remove, node *&root);

};
