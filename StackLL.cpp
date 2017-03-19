#include "StackLL.h"

class Stack::Node 
{
	public:
	   int data = 0;
	   Node* link = nullptr;
	
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

	};

Stack::~Stack()
{
	while(num_elements > 0)
	{
		pop();
	}
}

int Stack::size()
{
	return num_elements;
}

void Stack::push(int val)
{
	Node* newPtr = new Node{val};
	
	newPtr->link = frontPtr;
	frontPtr = newPtr;

	num_elements++;
}

void Stack::pop()
{
	Node* delPtr;
	
	delPtr = frontPtr;
	frontPtr = frontPtr->link;
	
	delete delPtr;
	num_elements--;
}

int Stack::top()
{
	return frontPtr->data;
}

void Stack::clear()
{
	while(num_elements != 0){
		pop();
	}
}




