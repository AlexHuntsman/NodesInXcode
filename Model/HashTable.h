//
//  HashTable.h
//  NodesInXcode
//
//  Created by Huntsman, Alexander on 5/5/16.
//  Copyright © 2016 Huntsman, Alexander. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h

#include "CTECList.cpp"
#include "HashNode.cpp"

#endif /* HashTable_h */

template <class Type>
class HashTable
{
private:
    int capacity;
    int tableCapacity;
    double efficiencyPercentile;
    int size;
    HashTable<Type> * internalStorage;
    CTECList<HashNode <Type>> * tableStorage;
    
    int findPosition(HashNode<Type> currentNode);//done
    int findTablePosition(HashNode<Type> currentNode);
    
    int handleCollision(HashNode<Type> currentNode);//done

    void updateSize();// sort of
    void updateTableCapacity();//done
    int getNextPrime();//done
    bool isPrime(int canidateNumber);//done
public:
    HashTable();//done
    ~HashTable();//done
    
    void add(HashNode<Type> currentNode);//done
    void addToTable(HashNode<Type> currentNode);//done
    
    bool remove(HashNode<Type> currentNode);
    bool contains(HashNode<Type> currentNode);
    int getSize();//done

};