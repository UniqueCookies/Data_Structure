#include "table.h"
using namespace std;
//Sally Xia CS163-remote Prog4
//This is the member function for the BST 
/*
	animal *data;
	node *left;
	node *right;
	private: node *root;
*/

//constructor for the BST
table::table()
{
	root = nullptr;
}

//destructor: deallocate all dynamic allocated memory
table::~table()
{
	remove_all(root);
}


//recursive function for destructor
void table::remove_all(node *&root)
{
	if(!root)
		return;
	remove_all(root->left);
	remove_all(root->right);
	delete root;
	root = nullptr;
}

//wrapper function to add an animal to the table
int table::add(const animal &toadd)
{
	return add(toadd,root); //call recursive function
}

//recursive function for adding an animal to the list
int table::add(const animal &toadd, node *&root)
{
	//base condition
	if(!root)
	{
		root = new node;
		if(!root->data.copy_animal(toadd))
			return 0; //unable to copy over the animal
		root->left = root->right = nullptr;
		return 1;
	}

	if(toadd.compare_breed(root->data)<0)
		add(toadd,root->left);
	else
		add(toadd,root->right);
	return 1;

}

//display all animal by breed and personality
int table::display() const
{
	return display(root);
}

//recursive function for display all
int table::display(node *root) const
{
	if(!root)
		return 0;
	int counter = display(root->left);
	++counter;
	root->data.display();
	counter+=display(root->right);
	return counter;
}	
//display all animals that has a matching breed
int table::display_breed(char *breed_tofind)
{
	return display_breed(breed_tofind,root); 
}

//recursive function to find a matching breed
int table::display_breed(char *breed_tofind, node *root)
{
	if(!root)
		return 0;
	int count = display_breed(breed_tofind,root->left);
	if(!root->data.find_breed(breed_tofind)) //matching breed
	{
		root->data.display();
		++count;
	}
	count +=display_breed(breed_tofind,root->right);
	return count;
}

//retrieve dogs with a particular breed and personality		
int table::retrieve (animal *array, char *breed_tofind, char *personality_tofind) const
{
	return retrieve(array,breed_tofind,personality_tofind,root);
}

//recursive function to find the matching dog
int table::retrieve(animal *array, char *breed_tofind, char *personality_tofind, node *root) const
{
	if(!root)
		return 0;
	int count = retrieve(array,breed_tofind,personality_tofind, root->left);
	count +=retrieve(array,breed_tofind,personality_tofind,root->right);
	if(!root->data.find_dogs() &&!root->data.find_breed(breed_tofind) && !root->data.find_personality(personality_tofind))
	{
		array[count].copy_animal(root->data);
		++count;
	}
		

	return count;



}

//remove a certain breed
int table::remove(char *breed_remove)
{
	if(!root)
		return 0; //empty

	return remove(breed_remove,root);
}

//recursive function for removal
int table::remove(char *breed_remove, node *&root)
{
	if(!root)
		return 0; //no matching data
	int count = remove(breed_remove,root->left);	
	count +=remove(breed_remove,root->right);

	if(!root->data.find_breed(breed_remove))
	{
		++count;
		//case 1: remove at leaf
		if(!root->left && !root->right)
		{
			delete root;
			root = nullptr;
		}
		//case 2: delete a node with 1 child - left is the succesor
		else if(root->left &&!root->right)
		{
			node *hold = root->left;
			delete root;
			root = hold;
		}
		//case 2b: delete a node with 1 child - right is the succesor
		else if(!root->left && root->right)
		{
			node *hold = root->right;
			delete root;
			root = hold;
		}
		//case 3: delete a node with 2 children - not special case
		else if (root->right->left)
		{
			//find the successor
			node *current = root->right;
			node *previous = nullptr;
			while (current->left)
			{
				previous = current;
				current = current->left;
			}

			//replace previous data
			root->data.copy_animal(current->data);
			//delete subtree
			node *hold = current ->right;
			delete current;
			previous->left = hold;
		}
		//case 3: delete a node with 2 children - special case
		else
		{
			node *current = root->right;
			root->data.copy_animal(current->data); 
			node *hold = current->right;
			delete current;
			root->right = hold;

		}	
	}

	return count;		
}


//display pet with a particular size
int table::display_size(char *size) const
{
	if(!root) return 0; //empty table
	return display_size(size,root);
}

//recursive function to display pet with a particular size
int table::display_size(char *size, node *root) const
{
	if(!root)
		return 0;
	int count = display_size(size,root->left);
	if(!root->data.compare_size(size))
	{
		root->data.display();
		++count;
	}
	count +=display_size(size,root->right);
	return count;

}



	








