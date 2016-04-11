/*
 * CTECArray.h
 *
 *  Created on: Feb 2, 2016
 *      Author: Alex Huntsman
 */


#ifndef MODEL_CTECARRAY_H_
#define MODEL_CTECARRAY_H_

#include "ArrayNode.h"
template <class Type>
class CTECArray
{
private:
	int size;
	int length;
	int innerLoop, outerLoop;
	ArrayNode<Type> * head;
public:
	CTECArray(int size);
	virtual ~CTECArray();
	int getSize();
	Type get(int position);
	void set(int position,const Type& value);
	int nextIndexOf(int startingIndex, Type value);
	void selectonSort();
    void swap(int indexOne, int indexTwo);
};

#endif /* MODEL_CTECARRAY_H_ */
