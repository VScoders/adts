#include "StackV.h"
#include <vector>

int Stack::size()
{
	return data.size();
}

void Stack::push(int val)
{

	data.push_back(val);
}

void Stack::pop()
{
	data.pop_back();
}

int Stack::top()
{
	return data.front();
}

void Stack::clear()
{
	data.clear();
}

