/*
 * CTECList.cpp
 *
 *  Created on: Feb 22, 2016
 *      Author: ahun0442
 */

#include "CTECList.h"


using namespace std;

template <class Type>
CTECList<Type>::CTECList()
{
	this->size = 0;
	this->head = nullptr;
	this->end = nullptr;
}

/**
 * Start at head
 * Iterate over nodes
 * update position
 * delete final
 * reset size, head, end to default
 */
template <class Type>
CTECList<Type>::~CTECList()
{

	ArrayNode<Type> *current = head;
	for(int deleteCount = 0; deleteCount < size; deleteCount++)
	{
		ArrayNode<Type> *temp = current;
		current = current->getNext();
		head = current;
		delete temp;
	}

	delete head;
	head = nullptr;
	end = nullptr;
	size = 0;
}
//Removes the node at the front
template<class Type>
void CTECList<Type> :: set(int index, const Type& value)
{
    //bounds cheack for size and negative
    assert(index < size && index >= 0);
    
    ArrayNode<Type> * current = head;
    for (int spot = 0; spot <= index; spot++)
    {
        if (spot != index)
        {
            current = current->getNext();
        } else
        {
            current->setValue(value);
        }
    }
}


template <class Type>
Type CTECList<Type> :: removeFromFront()
{
	assert(size >0);
	//Create a pointer to what is after head
	Type thingToRemove;
	ArrayNode<Type> * newHead = new ArrayNode<Type>();
	newHead = this->head->getNext();
	//get what was in the head node
	thingToRemove = head->getValue();
	//Delete what head is pointing to
	delete this->head;
	//Set head to the new head
	this->head = newHead;

	this->calculateSize();

	return thingToRemove;
}

template<class Type>
Type CTECList<Type> :: removeFromIndex(int index)
{
	Type thingToRemove; // In case we need to use value we are deleting

	assert (this->size > 0);
	assert(size > 0 && index >= 0 && index < size);


	ArrayNode<Type> * current = head;
		for(int spot = 0; spot <= index; spot++)
		{
			if(spot == index)
			{
				thingToRemove = current->getValue();
			}
			else
			{
				current = current->getNext();
			}
		}
		this->calculateSize();

	return thingToRemove;
}

template<class Type>
void CTECList<Type> :: calculateSize()
{
	assert(this->size > 0);
	assert(this->size >= 0);
	ArrayNode<Type> * counterPointer = head;
	int count = 0;

	if(counterPointer == nullptr)
	{
		this->size = 0;
		return;
	}
	else
	{
		count++;
		while(counterPointer->getNext() != nullptr)
		{
			counterPointer = counterPointer->getNext();
			count++;
		}

		this->size = count;
	}
}

template<class Type>
Type CTECList<Type> :: removeFromEnd()
{

	//Loop over size
	//or
	//Loop until getNext()-getNext() ==nullptr
	//grab the value from the last node
	//set the next to last node to point to nullptr
	//Before return the Cariable call calculateSize

	assert(size > 0);
	Type valueToRemove;


	ArrayNode<Type> * current = head;
	for(int spot = 0; spot < size-1; spot++)
	{
		current = current->getNext();
	}


    valueToRemove = current->getNext()->getValue();

	delete current->getNext();
	this->calculateSize();
	return valueToRemove;
}

template <class Type>
Type CTECList<Type> :: getFront()
{
	assert(this->size > 0);
	//Create a pointer to what is after head
	Type thingToReturn;
	ArrayNode<Type> * newHead = new ArrayNode<Type>();
	newHead = this->head->getNext();
	//get what was in the head node
	thingToReturn = this->head->getValue();

	this->calculateSize();

	return thingToReturn;
}
template <class Type>
Type CTECList<Type> :: getEnd()
{
assert(size > 0);
	Type valueToReturn;

	ArrayNode<Type> * current = head;
		for(int spot = 0; spot < size-1; spot++)
		{
			current = current->getNext();
		}


		valueToReturn = current->getNext()->getValue();

		this->calculateSize();
		return valueToReturn;

}

template<class Type>
Type CTECList<Type> :: getFromIndex(int index)
{
	Type thingToReturn; // In case we need to use value we are deleting

	assert (this->size > 0);
	assert(size > 0 && index >= 0 && index < size);

	ArrayNode<Type> * current = head;

		for(int spot = 0; spot <= index; spot++)
		{
			if(spot == index)
			{
				thingToReturn = current->getValue();
			}
				current = current->getNext();
		}
		this->calculateSize();

	return thingToReturn;
}

template<class Type>
void CTECList<Type> ::addToFront(const Type& value)
{

	ArrayNode<Type>  *newStuff = new ArrayNode<Type>(value, head);
	head = newStuff;

	calculateSize();
}

template<class Type>
void CTECList<Type> :: addToEnd(const Type& value)
{

	ArrayNode<Type> * newStuff = new ArrayNode<Type>(value, head);
	end-> setNext(newStuff);
	end = newStuff;

	calculateSize();
}

template<class Type>
void CTECList<Type> :: swap(int indexOne, int indexTwo)
{
	assert(indexOne < size && indexTwo < size);

	Type temp = getFromIndex(indexOne);
	set(indexOne, getFromIndex(indexTwo));
	set(indexTwo, temp);
}

template<class Type>
void CTECList<Type> ::selectonSort()
{
	for(innerLoop = 0; outerLoop < this->size-1; outerLoop++)
	{
		int selectedMinimum = outerLoop;

		for(int innerLoop = outerLoop+1; innerLoop < size; innerLoop++)
		{
			if(getFromIndex(innerLoop) < getFromIndex(selectedMinimum))
			{
				selectedMinimum = innerLoop;
			}
		}
		if(selectedMinimum != outerLoop)
		{
			swap(outerLoop, selectedMinimum);
		}
	}
}


