#pragma once
#include <string>
#include <iostream>
using namespace std;

class Vertex
{
public:
	Vertex* parent;
	string name;

	Vertex(string Name)
	{
		this->name = Name;
		parent = nullptr;
	}

	Vertex()
	{
		parent = nullptr;
	}

	void operator=(const Vertex& other)
	{
		this->parent = other.parent;
		this->name = other.name;
	}

	friend ostream& operator<<(ostream& os, const Vertex& dt)
	{
		if (dt.parent)
			os << dt.name << "|" << (dt.parent)->name << "";
		else
			os << dt.name << "|" << 0 << "";
		return os;
	}
};
