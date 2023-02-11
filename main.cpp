#include "graph.h"
using namespace std;

//this is the testing program 


//PROTOTYPE
void option1(graph &graph1);
void option2(graph &graph1);

int main()
{
	int choice =0;
	int size =0;
	
	//make the graph
	cout <<"How many items do you plan to enter: ";
	cin>>size;	cin.ignore(100,'\n');
	graph graph1(size);

//	graph graph1;

	do
	{
		cout <<"1. add a decision."<<endl;
		cout <<"2. insert connection."<<endl;
		cout <<"3. display all info."<<endl;
		cout <<"0. quit."<<endl;
		cin>>choice;	cin.ignore(100, '\n');
		if(choice ==1)
			option1(graph1);
		if(choice ==2)
			option2(graph1);
		if(choice ==3)
		{
			if(!graph1.display_all())
				cout <<"The list is empty."<<endl;
		}
	}while(choice !=0);


	return 0;
}

//Option2: add an edge
void option2(graph &graph2)
{
	char decision[100];
	char add[100];

	cout<<"Enter the decision you would like to add a connection with: ";
	cin.get(decision,100,'\n');	cin.ignore(100, '\n');
	cout <<"Enter the consequential deicion: ";
	cin.get(add,100,'\n');	cin.ignore(100,'\n');

	if(!graph2.insert_edge(decision,add))
		cout <<"Error: The decision you entered is not in the graph."<<endl;	
}
//Option1: add a vertex - alert user if the table is full
void option1(graph &graph1)
{
	char decision[100];

	cout <<"Please enter a decision for the graph: ";
	cin.get(decision,100,'\n');	cin.ignore(100,'\n');
	if(!graph1.insert_vertex(decision))
		cout <<"Sorry the table is full. Can no longer enter more info."<<endl;
}
