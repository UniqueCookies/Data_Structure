#include <iostream>
#include <cstring>
#include <cctype>

//Sally Xia CS163-Remote Prog5 
//This is the header file for the graph


struct vertex
{
	char *data; //nullptr if the vertex is not set
	struct node *head;
};

struct node
{
	vertex *adj;
	node *next;
};

class graph
{
	public:
		graph(int size); //constructor
		~graph(void); //destructor
	 	int insert_vertex(const char *to_add);	
		int insert_edge(char *current, char *attach);
		int display_all(void) const;
	private:
		vertex *adj_list;
		int list_size;
		int find_location(char *key);
};
