//
//  HashTable.h
//  NodesInXcode
//
//  Created by Huntsman, Alexander on 5/5/16.
//  Copyright © 2016 Huntsman, Alexander. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h

#include <stdio.h>

#endif /* HashTable_h */

template <class Type>
class HashTable
{
private:
    int capacity;
    double efficiencyPercentile;
    int size;
    Type * internalStorage;
    
    
    void updateSize();
    int findPosition(const Type& value);
    int handleCollision(const Type& value);
public:
    HashTable();
    ~HashTable();
    void add(const Type& value);
    bool remove(const Type& value);
    bool contains(const Type& value);
    int getSize();
    
};