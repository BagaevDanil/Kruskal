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
		this->parent = other.parent;
		this->name = other.name;
	}

	friend ostream& operator<<(ostream& os, const MyVertex& dt)
	{
		if (dt.parent)
			os << dt.name << "|" << (dt.parent)->name << "";
		else
			os << dt.name << "|" << 0 << "";
		return os;
	}
};
