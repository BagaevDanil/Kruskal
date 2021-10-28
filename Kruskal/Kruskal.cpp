#include <iostream>
#include "TreeAVL.h"
#include "Queue.h"
#include "Vertex.h"
#include "MyVector.h"
#include "Edge.h"

using namespace std;

Vertex* find(Vertex* x)
{
    if (x->parent != nullptr)
    {
        x->parent = find(x->parent);
    }
    if (x->parent)
        return x->parent;
    return x;
}

int main()
{
    TreeAVL<Vertex, string> arrVertex;
    int nVertex;
    MyVector<Edge> queueVertex;
    cout << "Num Vertex: ";
    cin >> nVertex;

    for (int i = 0; i < nVertex; i++)
    {
        string keyVertexFirst, keyVertexSecond;
        int weight;

        cin >> keyVertexFirst >> keyVertexSecond >> weight;

        if (!arrVertex.GetExists(keyVertexFirst))
        {
            Vertex newVertex(keyVertexFirst);
            arrVertex.Insert(keyVertexFirst, newVertex);
        }
        if (!arrVertex.GetExists(keyVertexSecond))
        {
            Vertex newVertex(keyVertexSecond);
            arrVertex.Insert(keyVertexSecond, newVertex);
        }    

        Vertex *x = (arrVertex.GetExists(keyVertexFirst));
        Vertex *y = (arrVertex.GetExists(keyVertexSecond));

        Edge newEdge(x, y, weight);
        queueVertex.AddBack(newEdge);
    }
    
    queueVertex.BubbleSort();

    while (queueVertex.GetSizeVector() > 0)
    {
        Edge newEdge = queueVertex.GetBack();
        Vertex* x = find(newEdge.firstVertex);
        Vertex* y = find(newEdge.secondVertex);
        cout << newEdge.firstVertex->name << "::::" << newEdge.secondVertex->name << endl;
        cout << x->name  << "::::" << y->name << endl;
        if (x != y)
        {
            
            x->parent = y;
            cout << newEdge.firstVertex->name << " " << newEdge.secondVertex->name << " " << newEdge.weight << endl;
        }
        //queueVertex.Print();
        arrVertex.Print();
        cout << "\n\n";
        queueVertex.DeleteBack();
    }
} 
//a e 30
//a b 1
//a d 8
//a c 2
//b e 4
//b c 6
//e c 9
//e d 11
//d c 20

//a b 1
//d a 1
//a c 1
//b f 1
//c f 1
//d c 1
//d e 1
//e f 1

    //MyVertex a("a");
    //MyVertex b("b");
    //MyVertex c("c");
    //MyVertex d("d");
    //MyVertex e("e");
    //cout << a.name << " " << a.parent << " " << &a << endl;
    //cout << b.name << " " << b.parent << " " << &b << endl;
    //cout << c.name << " " << c.parent << " " << &c << endl;
    //cout << d.name << " " << d.parent << " " << &d << endl;
    //cout << e.name << " " << e.parent << " " << &e << endl;
    
    //TreeAVL<MyVertex, string> arrVertex;
    //arrVertex.Insert(a.name, a);
    //arrVertex.Print();
    //cout << endl;
    //arrVertex.Insert(b.name, b);
    //arrVertex.Print();
    //cout << endl;
    //arrVertex.Insert(c.name, c);
    //arrVertex.Print();
    //cout << endl;
    //arrVertex.Insert(d.name, d);
    //arrVertex.Print();
    //cout << endl;
    //arrVertex.Insert(e.name, e);
    //arrVertex.Print();
    //cout << endl;

    //Edge edge1(&a, &b, 1);
    //Edge edge2(&a, &e, 1);
    //Edge edge3(&a, &d, 1);

    //Edge edge4(&b, &c, 1);
    //Edge edge5(&b, &d, 1);

    //Edge edge6(&c, &e, 1);
    //Edge edge7(&c, &d, 1);

    //Edge edge8(&e, &d, 1);


    //cout << edge1.firstVertex->name << " " << edge1.firstVertex->parent << " " << edge1.firstVertex << endl;
    //cout << edge1.secondVertex->name << " " << edge1.secondVertex->parent << " " << edge1.secondVertex << endl;
    //cout << edge1.weight << endl << endl;

    //cout << edge2.firstVertex->name << " " << edge2.firstVertex->parent << " " << edge2.firstVertex << endl;
    //cout << edge2.secondVertex->name << " " << edge2.secondVertex->parent << " " << edge2.secondVertex << endl;
    //cout << edge2.weight << endl << endl;

    //cout << edge3.firstVertex->name << " " << edge3.firstVertex->parent << " " << edge3.firstVertex << endl;
    //cout << edge3.secondVertex->name << " " << edge3.secondVertex->parent << " " << edge3.secondVertex << endl;
    //cout << edge3.weight << endl << endl;

    //cout << edge4.firstVertex->name << " " << edge4.firstVertex->parent << " " << edge4.firstVertex << endl;
    //cout << edge4.secondVertex->name << " " << edge4.secondVertex->parent << " " << edge4.secondVertex << endl;
    //cout << edge4.weight << endl << endl;

    //cout << edge5.firstVertex->name << " " << edge5.firstVertex->parent << " " << edge5.firstVertex << endl;
    //cout << edge5.secondVertex->name << " " << edge5.secondVertex->parent << " " << edge5.secondVertex << endl;
    //cout << edge5.weight << endl << endl;
   
    //MyVector<Edge> queueVertex;
    //queueVertex.AddBack(edge1);
    //queueVertex.AddBack(edge2);
    //queueVertex.AddBack(edge3);
    //queueVertex.AddBack(edge4);
    //queueVertex.AddBack(edge5);
    //queueVertex.AddBack(edge6);
    //queueVertex.AddBack(edge7);
    //queueVertex.AddBack(edge8);

    /*for (int i = 0; i < 5; i++)
    {
        Edge newEdge = queueVertex.GetBack();
        cout << newEdge.firstVertex->name << " " << newEdge.firstVertex->parent << " " << newEdge.firstVertex << endl;
        cout << newEdge.secondVertex->name << " " << newEdge.secondVertex->parent << " " << newEdge.secondVertex << endl;
        cout << newEdge.weight << endl << endl;

        if (queueVertex.GetSizeVector() != 0)
            queueVertex.DeleteBack();
    }*/