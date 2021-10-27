#pragma once
#include <string>
#include <iostream>
using namespace std;

class MyVertex
{
public:
	MyVertex* parent;
	string name;

	MyVertex(string Name)
	{
		this->name = Name;
		parent = nullptr;
	}

	MyVertex()
	{
		parent = nullptr;
	}

	void operator=(const MyVertex& other)
	{
		//this->parent = this->parent;
		this->name = other.name;
	}

	friend ostream& operator<<(ostream& os, const MyVertex& dt)
	{
		os << dt.name << "|" << dt.parent << "|" << &dt;
		return os;
	}
};
