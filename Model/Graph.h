//
//  Graph.h
//  NodesInXcode
//
//  Created by Huntsman, Alexander on 4/25/16.
//  Copyright © 2016 Huntsman, Alexander. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#include <set>

#endif /* Graph_h */

template <class Type>
class Graph
{
private:
    static const int MAXIMUM = 20;
    bool edges [MAXIMUM] [MAXIMUM];
    Type labels [MAXIMUM];
    int manyVerticies;
public:
   Graph();
    virtual ~Graph();
    
    void addVertex(const Type& label);
    void addEdge(int source, int target);
    void removeEdge(int source, int target);
    Type& operator [] (int vertex);
    
    bool isEdge(int source, int target) const;
    std::set<int> neighbors(int vertex);
    Type operator [] (int vertex) const;
};