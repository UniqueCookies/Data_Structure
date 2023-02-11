#include "graph.h"
using namespace std;
//Sally Xia CS163-Remote Prog5 
//This is the member function for the graph
/* struct info:
struct vertex
	char *data; //nullptr if the vertex is not set
	struct node *head;
struct node
	vertex *adj;
	node *next;
private:
	vertex *adj_list;
	int list_size;
*/

//constructor for the graph
graph::graph(int size)
{
	adj_list = new vertex[size];
	for(int i=0; i<size; ++i)
	{
		adj_list[i].head=nullptr;
		adj_list[i].data=nullptr;
	}
	list_size = size;
}
//destructor for the graph
graph::~graph(void)
{
	for(int i=0; i<list_size; ++i)
	{
		//delete the char
		if(adj_list[i].data)
			delete [] adj_list[i].data;
		adj_list[i].data = nullptr;


		//make sure the edge list is deallocated 
		
		node *temp = adj_list[i].head;
		node *hold = nullptr;
		while(temp)
		{
			hold = temp->next;
			delete temp;
			temp = hold;
		}
		adj_list[i].head=nullptr;
	}
	delete []adj_list;
	adj_list = nullptr;
	list_size=0;
}
//insert vertex: find the 1st empty spot
int graph::insert_vertex(const char *to_add)
{
	for(int i =0; i<list_size; ++i)
	{
		if(adj_list[i].data==nullptr)
		{
			//add info
			adj_list[i].data = new char [strlen(to_add)+1];
			strcpy(adj_list[i].data,to_add); 
			return 1;
		}
	}

	return 0; //the graph is already full
}
//find a vertex. return the location or return the list_size = not found
int graph::find_location(char *key)
{
	if(!adj_list) //empty list
		return list_size; //data not found

	for(int i =0; i<list_size;++i)
	{
		if(strcmp(key,adj_list[i].data)==0) //match
			return i;
	}	
	return list_size; //not found
}

//insert edges: this is a directed graph - one direction at a time
int graph::insert_edge(char *current, char *attach)
{
	int i = find_location(current); //the vertice we want to insert edges
	int j = find_location(attach); //edges we want
	//item find?
	if(i==list_size ||j==list_size)
		return 0; //cannot add edges. no matching info
	
	node *hold = adj_list[i].head;
	//add info
	node *add = new node;
	add->adj = &adj_list[j]; //location of the attach
	add->next = adj_list[i].head;
	
	adj_list[i].head = add;
	return 1;
}
//display every vertex with its adjacent edges
int graph::display_all(void) const
{
	if(!adj_list)
		return 0; //empty list
	for(int i =0; i<list_size; ++i)
	{
		if(adj_list[i].data)
		{
			cout <<"Vertex "<<i<<": "<<endl
			     <<adj_list[i].data<<endl
			     <<"Its connecting decisions are: "<<endl;
			node *temp = adj_list[i].head;
			if(!temp)
				cout <<"This vertex has no connecting decisions."<<endl;
			while(temp)
			{
				cout <<temp->adj->data<<endl;
				temp = temp->next;
			}
		}
		else
			cout <<"Vertex "<<i<<": empty."<<endl;
	
	}
	return 1;
}








