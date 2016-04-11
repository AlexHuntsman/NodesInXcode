/*
 * Node.h
 *
 *  Created on: Jan 27, 2016
 *      Author: ahun0442
 */

#ifndef MODEL_NODE_H_
#define MODEL_NODE_H_
#include <iostream>
#include <string>

template <class Type>
class Node
{
private:
	Type value; //Container for the value stored in the node.
	Node * pointers; //Pointer to the array of Nodes
public:
	Node();
	Node(const Type& value);
	virtual ~Node();
	Type getValue();
	void setValue(const Type& value);
	Node * getPointers();
};



#endif /* MODEL_NODE_H_ */
