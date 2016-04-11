/*
 * NodeController.h
 *
 *  Created on: Jan 29, 2016
 *      Author: ahun0442
 */

#ifndef CONTROLLER_NODECONTROLLER_H_
#define CONTROLLER_NODECONTROLLER_H_

#include <iostream>
#include <string>
#include "../Model/Node.cpp"
#include "../Model/ArrayNode.cpp"
#include "../Model/CTECArray.cpp"
#include "../Model/Timer.h"

#include "../Model/CTECList.cpp"

using namespace std;

class NodeController
{
private:

	//CTECArray<string> * myStringArray;
	//CTECArray<int> * myIntArray;
	//CTECArray<double> * myDoubleArray;
	Timer arrayTimer;
	void sortData();
	void testList();
	void searchTest();

	int * mergeData;
	void doMergesort();
	void mergesort(int dataArray [], int size);
	void merge(int data [], int sizeOne, int sizeTwo);

	//CTECList<int> * myNumberList;
	CTECList<int> * numbersInList();
	CTECArray<int> * numbersInArray();


public:
	NodeController();
	virtual ~NodeController();
	void start();
	void checkSorts();
};

#endif /* CONTROLLER_NODECONTROLLER_H_ */
