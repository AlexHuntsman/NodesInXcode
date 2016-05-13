//
//  HashTable.cpp
//  NodesInXcode
//
//  Created by Huntsman, Alexander on 5/5/16.
//  Copyright © 2016 Huntsman, Alexander. All rights reserved.
//

#include "HashTable.h"
#include <cmath>

template <class Type>
HashTable<Type> :: HashTable()
{
    this->capacity = 101;
    this->efficiencyPercentile = .667;
    this->size = 0;
    this->internalStorage = new HashNode<Type>*[capacity];
}

template <class Type>
HashTable<Type> :: ~HashTable<Type>()
{
    delete [] internalStorage;
}

template <class Type>
int HashTable<Type>:: getSize()
{
    return this->size;
}

template <class Type>
void HashTable<Type>:: add(HashNode<Type> currentNode)
{
    if(!contains(currentNode))
    {
        if(this->size/this->capacity >= this->efficiencyPercentile)
        {
            updateSize();
        }
        int positionToInsert = findPosition(currentNode);
        
        if(internalStorage[positionToInsert] != nullptr)
        {
            while(internalStorage[positionToInsert] != nullptr)
            {
                positionToInsert = (positionToInsert +1) % size;
            }
            internalStorage[positionToInsert] = &currentNode;
        }
        else
        {
            internalStorage[positionToInsert] = &currentNode;
        }
    }
}
template <class Type>
bool HashTable<Type> :: isPrime(int canidateNumber)
{
    bool isPrime = true;
    
    if(canidateNumber <= 1)
    {
        return false;
    }
    else if(canidateNumber == 2 || canidateNumber == 3)
    {
        isPrime = true;
    }
    else
    {
        for(int next = 3; next <=sqrt(canidateNumber) +1; next += 2)
        {
            if(canidateNumber % next == 0)
            {
                isPrime =false;
                break;
            }
        }
    }
    return isPrime;
}

template <class Type>
int HashTable<Type> :: getNextPrime()
{
    int nextPrime = (capacity * 2) + 1;
    
    while(!isPrime(nextPrime))
    {
        nextPrime++;
    }
    return nextPrime;
}

template <class Type>
int HashTable<Type> :: handleCollision(HashNode<Type> currentNode)
{
    int reHashedPosition = findPosition(currentNode);
    int random = rand(capacity);
    reHashedPosition = random + (reHashedPosition * reHashedPosition) % capacity;
    
    return reHashedPosition;
    
}
template<class Type>
void HashTable<Type> :: updateSize()
{
    int updatedCapacity = getNextPrime();
    HashNode<Type> ** updatedStorage = new HashNode<Type>*[updatedCapacity];
    
    int oldCapacity = capacity;
    capacity = updatedCapacity;
    
    for(int index = 0; index < oldCapacity; index++)
    {
        if(internalStorage[index] != nullptr)
        {
            int updatedPosition = findPosition(*internalStorage[index]);
            updatedStorage[updatedPosition] = internalStorage[index];
        }
    }
    
    internalStorage = updatedStorage;
}

template<class Type>
void HashTable<Type> :: updateTableCapacity()
{
    int updatedCapacity = getNextPrime();
    CTECList<HashNode<Type>> * updateTable = new CTECList<HashNode<Type>> [updatedCapacity];
    
    int oldTableCapacity = tableCapacity;
    tableCapacity = updatedCapacity;
    
    for(int index = 0; index < oldTableCapacity; index++)
    {
        if (tableStorage[index] != nullptr)
        {
            CTECList<HashNode<Type>> temp = tableStorage[index];
            for(int innerIndex = 0; innerIndex < temp.getSize(); innerIndex++)
            {
                int updatedTablePosition = findPosition(temp.get(index));
                if(updateTable[updatedTablePosition] == nullptr)
                {
                    CTECList<HashTable<Type>> updatedList;
                    updatedList.addEnd(temp.get(index));
                }
                else
                {
                    updateTable[updatedTablePosition].addEnd(temp.get(index));
                }
                
            }
        }
    }
        
}

template<class Type>
int HashTable<Type> :: findPosition(HashNode<Type> currentNode)
{
    int position = 0;
    
    position = currentNode.getKey() % capacity;
    
    return position;
}

template<class Type>
void HashTable<Type> :: addToTable(HashNode<Type> currentNode)
{
    if(!contains(currentNode))
    {
        if(this->size/this->tableCapacity >= this->efficiencyPercentage)
        {
            updateTableCapacity();
        }
        
        int positionToInsert = findTablePosition(currentNode);
        
        if(tableStorage[positionToInsert] == nullptr)
        {
            CTECList<HashNode<Type>> hashList;
            hashList.addEnd(currentNode);
        }
        else
        {
            tableStorage[positionToInsert].addEnd(currentNode);
        }
    }

}

template<class Type>
bool HashTable<Type> :: contains(HashNode<Type> currentNode)
{
    bool wasRemoved = false;
    if(contains(currentNode))
    {
        int index = findPosition(currentNode);
        while(internalStorage[index] != nullptr && !wasRemoved)
        {
            if(internalStorage[index]->getValue() == currentNode.getValue())
            {
                wasRemoved = true;
                internalStorage[index] = nullptr;
                size--;

            }
            else
            {
                index =(index +1) %capacity;
            }
        }
    }
    return wasRemoved;
}