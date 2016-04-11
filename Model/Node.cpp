/*
 * Node.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: ahun0442
 */

#include "Node.h"
#include <iostream>

using namespace std;

template <class Type>
Node<Type> ::Node()
{
	pointers = nullptr;
}

template <class Type>
Node<Type> ::Node(const Type& value)
{
	this->setValue(value);
}

template <class Type>
Node<Type>::~Node()
{

}

template <class Type>
Type Node<Type> :: getValue()
{
	return this -> value;
	pointers = nullptr;
}

template <class Type>
void Node<Type> :: setValue(const Type& value)
{
	this->value = value;
}

template <class Type>
Node<Type> * Node<Type> :: getPointers()
{
	return this->pointers;
}
