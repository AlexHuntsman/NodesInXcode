//
//  Graph.cpp
//  NodesInXcode
//
//  Created by Huntsman, Alexander on 4/25/16.
//  Copyright © 2016 Huntsman, Alexander. All rights reserved.
//

#include "Graph.h"
#include <queue>
using namespace std;

template <class Type>
const int Graph<Type> :: MAXIMUM;

template <class Type>
void Graph<Type> :: addEdge(int source, int target)
{
    assert(source < size());
    assert(target < size());
    edges[source] [target] = true;
}

template <class Type>
void Graph<Type> :: addVertex(const Type& label)
{
    int newVertexNumber;
    int otherNumber;
    
    assert(size() < MAXIMUM);
    
    newVertexNumber = manyVerticies;
    ++manyVerticies;
    
    for(otherNumber = 0; otherNumber < manyVerticies; otherNumber++)
        
    {
        edges[otherNumber] [newVertexNumber] = false;
        edges [newVertexNumber] [otherNumber] = false;
    }
    
    label[newVertexNumber] = label;
}

template<class Type>
bool Graph<Type> :: isEdge(int source, int target) const
{
    bool connected = false;
    
    assert(source < size() && target < size());
    connected = edges [source] [target];
    
    return connected;
}

template<class Type>
Type& Graph<Type> :: operator[](int vertex)
{
    assert (vertex < size());
    return labels[vertex];
}

template<class Type>
Type Graph<Type> :: operator[](int vertex) const
{
    assert (vertex < size());
    return labels[vertex];
}

template <class Type>
std::set<int> Graph<Type> :: neighbors(int vertex) const
{
    std::set<int> answer;
    assert(vertex < size());
    
    for (int index=0; index < size(); index++)
    {
        if(edges[vertex] [index])
        {
            answer.insert(index);
        }
    }
    return answer;
}

template<class Type>
void Graph<Type> :: depthFirstTravsal(Graph<Type> currentGraph, int vertex)
{
    bool markedVerticies[MAXIMUM];
    assert(vertex < currentGraph.size());
    std::fill_n(markedVerticies, currentGraph.size(), false);
    depthFirstTravsal(currentGraph, vertex, markedVerticies);
}

template<class Type>
void Graph<Type> :: depthFirstTravsal(Graph<Type> currentGraph, int vertex, bool * markedVerticies)
{
    std::set<int> connections = currentGraph.neighbors(vertex);
    std::set<int>::iterator setIterator;
    
    markedVerticies[vertex] = true;
    cout<< currentGraph[vertex] << endl;
    
    for(setIterator = connections.begin(); setIterator != connections.end(); setIterator++)
    {
        if(!markedVerticies[*setIterator])
        {
            depthFirstTravsal(currentGraph, *setIterator, markedVerticies);
        }
    }
    
    
}

template<class Type>
void Graph<Type> :: breadthFirstTravsal(Graph<Type> currentGraph, int vertex)
{
    bool markedVerticies[MAXIMUM];
    std::set<int> conections;
    std::set<int>::iterator setIterator;
    std::queue<int> vertexQueue;
    assert(vertex < currentGraph.size());
    
    std::fill_n(markedVerticies, currentGraph.size(),false);
    markedVerticies[vertex] = true;
    cout<< currentGraph[vertex]<< endl;
    vertexQueue.push(vertex);
    while(!vertexQueue.empty())
    {
        conections = currentGraph.neighbors(vertexQueue.front());
        vertexQueue.pop();
        
        for(setIterator = conections.begin(); setIterator != conections.end(); setIterator++)
        {
            if(!markedVerticies[*setIterator])
            {
                markedVerticies[*setIterator] = true;
                cout << currentGraph[*setIterator] << endl;
                vertexQueue.push(*setIterator);
            }
        }
    }
}





