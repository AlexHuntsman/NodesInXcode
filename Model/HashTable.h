//
//  HashTable.h
//  NodesInXcode
//
//  Created by Huntsman, Alexander on 5/5/16.
//  Copyright © 2016 Huntsman, Alexander. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h

#include "CTECList.h"
#include "HashNode.cpp"

#endif /* HashTable_h */

template <class Type>
class HashTable
{
private:
    int capacity;//- done
    int tableCapacity;//- done
    double efficiencyPercentile;//- done
    int size;//- done
    HashNode<Type> ** internalStorage;//- done
    CTECList<HashNode <Type>> * tableStorage;//- done
    
    int findPosition(HashNode<Type> currentNode);//done -
    int findTablePosition(HashNode<Type> currentNode);
    
    int handleCollision(HashNode<Type> currentNode);//done -

    void updateSize();//done - same as updateCapacity
    void updateTableCapacity();//done -
    int getNextPrime();//done -
    bool isPrime(int canidateNumber);//done -
public:
    HashTable();//done -
    ~HashTable();//done -
    
    void add(HashNode<Type> currentNode);//done -
    void addToTable(HashNode<Type> currentNode);//done -
    
    bool remove(HashNode<Type> currentNode);// -
    bool contains(HashNode<Type> currentNode);// - done
    int getSize();//done -
/*
 Table is the same as Chained
 */
};