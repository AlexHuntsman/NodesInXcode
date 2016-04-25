//
//  Graph.cpp
//  NodesInXcode
//
//  Created by Huntsman, Alexander on 4/25/16.
//  Copyright © 2016 Huntsman, Alexander. All rights reserved.
//

#include "Graph.h"

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





