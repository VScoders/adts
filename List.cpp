#include "List.h"
#include <iostream>
#include <stdexcept>//used to be able to "throw" exceptions

using namespace std;


class List::Node //self-referential Node class
{
	public:
	   int data = 0;
	   Node* link = nullptr;
	   //link is a data member which is a pointer 
	   //to an object of the same type (i.e. Node)
	
	Node()
	{
		data = 0;
		link = nullptr;
	}

	Node(int new_data)
	{
		data = new_data;
		link = nullptr;
	}

	Node(int new_data, Node* new_link)
	{
		data = new_data;
		link = new_link;
	}

	};//end Node class definition (can only be seen by the List class)

List::List(){
    frontPtr = nullptr;
    num_elements = 0;
}

List::~List()
{
    while(num_elements > 0)
      remove(1);
}
	
int List::size()
 {
    return num_elements;
 }

void List::insert(int val, int k)
{
	if (k < 1 or k > num_elements +1) //if the location is invalid
	     throw out_of_range("List::insertAt(...)");//throw an "out_of_range" exception
	
	
	Node* newPtr = new Node{val};
	
	if(k == 1)
	{
	  newPtr->link = frontPtr;
	  frontPtr = newPtr;
	 }
	else
	 {  
	
	  Node* tmpPtr = frontPtr;
	  int loc = 1; 
	  
	    while( loc != k-1) //get pointer to (k-1)th node
	     {
		tmpPtr = tmpPtr->link;
		loc++;
	     }
	
	  newPtr->link = tmpPtr->link;
	  tmpPtr->link = newPtr;  
        }//end else

     num_elements++;
 }

void List::remove(int k)
{
	if (k < 1 or k > num_elements)//if the location is invalid 
	     throw out_of_range("List::removeAt(...)");//throw an "out_of_range" exception
	
	Node* delPtr;
	
	if(k == 1)
	{
	  delPtr = frontPtr;
	  frontPtr = frontPtr->link;
	 }
	 else
	 {
	    Node* tmpPtr = frontPtr;
		
	    int loc = 1;
            
            while(loc != k-1)//get pointer to (k-1)th node
	    {
	       tmpPtr = tmpPtr->link;
		loc++;
	    }
	
	    delPtr = tmpPtr->link;
	    tmpPtr->link = delPtr->link;
	  }
	
	delete delPtr;
	num_elements--;
	}
	
void List::display(){
	for(Node* curPtr = frontPtr; curPtr != nullptr; curPtr = curPtr->link){
	cout << curPtr->data << " ";
	}
}

void List::clear(){
	while(num_elements != 0){
		remove(1);
	}
}

int List::getAt(int k)
{
	Node* curPtr = frontPtr;
	for(int loc = 1; loc != k; loc++)
	{
		curPtr = curPtr->link;
	}
      return curPtr->data;
}
	//Implementations of missing operations
	
