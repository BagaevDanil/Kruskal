#pragma once
#include "MyVertex.h"

class Edge
{
public:
	MyVertex* firstVertex;
	MyVertex* secondVertex;
	int weight;

	Edge(MyVertex* FirstVertex, MyVertex* SecondVertex, int Weight)
	{
		this->firstVertex = FirstVertex;
		this->secondVertex = SecondVertex;
		this->weight = Weight;
	}

	Edge()
	{
		this->firstVertex = nullptr;
		this->secondVertex = nullptr;
		this->weight = -1;
	}

	bool operator>(const Edge& RightValue)
	{
		return this->weight > RightValue.weight;
	}
	bool operator<(const Edge& RightValue)
	{
		return this->weight < RightValue.weight;
	}

	friend ostream& operator<<(ostream& os, const Edge& dt)
	{
		os << *dt.firstVertex << "_-_" << *dt.secondVertex << endl;
		return os;
	}

};

//bool operator>(const Edge& LeftValue, const Edge& RightValue)
//{
//	return LeftValue.weight > RightValue.weight;
//}
//
//bool operator<(const Edge& LeftValue, const Edge& RightValue)
//{
//	return LeftValue.weight < RightValue.weight;
//}
