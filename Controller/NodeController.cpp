/*
 * NodeController.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: ahun0442
 */

#include "NodeController.h"
#include <CMath>

NodeController::NodeController()
{
	//this->intNode.setValue(5);
	//this->stringArrayNode.setValue("words are fun");
	//myStringArray = new CTECArray<string>(5);
	//myIntArray = new CTECArray<int>(5);
	//myDoubleArray = new CTECArray<double>(5);
	//myNumberList = new CTECList<int>();

}

NodeController::~NodeController()
{
	//TODO Auto-geerated deconstructor stub
}

void NodeController::checkSorts()
{
	CTECArray<int> numbersInArray(5000);
	CTECList<int> numbersInList;
	for (int spot = 0; spot < 5000; spot++)
	{
		int randomValue = rand();
		numbersInArray.set(spot, randomValue);
		numbersInList.addToEnd(randomValue);
	}
	Timer sortTimer;
	sortTimer.startTimer();
	numbersInList.selectonSort();
	sortTimer.stopTimer();
	sortTimer.displayTimerInformation();
    sortTimer.resetTimer();

}
void NodeController::start()
{
//	cout << intNode.getValue() << endl;
//	cout << stringArrayNode.getValue() << endl;
	//string first = "first";
	//string second = "second";
	//string third = "third";
	//string fourth = "fourth";
	//string fifth = "fifth";

	//myStringArray->set(0, first);
	//myStringArray->set(1, second);
	//myStringArray->set(2, third);
	//myStringArray->set(3, fourth);
	//myStringArray->set(4, fifth);

	//myIntArray->set(0, 1);
	//myIntArray->set(1, 2);
	//myIntArray->set(2, 3);
	//myIntArray->set(3, 4);
	//myIntArray->set(4, 5);

	//myIntArray->set(0, 1.1);
	//myIntArray->set(1, 2.2);
	//myIntArray->set(2, 3.3);
	//myIntArray->set(3, 4.4);
	//myIntArray->set(4, 5.5);

	//myNumberList->addToFront(1);
	//myNumberList->addToEnd(2);
	//myNumberList->set(2, 3);
	//myNumberList->set(3, 4);
	//myNumberList->set(4, 5);

	arrayTimer.startTimer();

	//for(int index = 0; index < myStringArray->getSize(); index++)
//{
	//	cout << "In my String array the contents at spot " << index << " are: " << myStringArray->get(index) << endl;
	//}
	//for(int index = 0; index < myIntArray->getSize(); index++)
	//{
	//	cout << "In my Int array the contents at spot " << index << " are: " << myIntArray->get(index) << endl;
	//}
	//for(int index = 0; index < myDoubleArray->getSize(); index++)
	//	{
	//		cout << "In my Double array the contents at spot " << index << " are: " << myDoubleArray->get(index) << endl;
	//	}

	arrayTimer.stopTimer();
	arrayTimer.displayTimerInformation();

}

void NodeController::doMergesort()
{
	mergeData = new int[5000];

	for (int spot = 0; spot < 5000; spot++)
	{
		int myRandom = rand();
		mergeData[spot] = myRandom;
	}
	for (int spot = 0; spot < 5000; spot++)
	{
		cout << mergeData[spot] << ", ";
	}
	Timer mergeTimer;
	mergeTimer.startTimer();

	mergesort(mergeData, 5000);

	mergeTimer.stopTimer();
	mergeTimer.displayTimerInformation();
	for (int spot = 0; spot < 5000; spot++)
		{
			cout << mergeData[spot] << ", ";
		}
    mergeTimer.resetTimer();
	delete mergeData;
}

void NodeController::mergesort(int data[], int size)
{
	int sizeOne;
	int sizeTwo;

	if(size > 1)
	{
		sizeOne = size/2;
		sizeTwo = size-sizeOne;

		mergesort(data, sizeOne);
		mergesort((data+sizeOne), sizeTwo);
		merge(data, sizeOne, sizeTwo);
	}
}

void NodeController::merge(int data[], int sizeOne, int sizeTwo)
{
	int * temp;
	int copied = 0;
	int copied1 = 0;
	int copied2 = 0;
	int index;

	temp = new int[sizeOne + sizeTwo];

	while ((copied1 < sizeOne) && (copied2 < sizeTwo))
	{
		if (data[copied1] < (data + sizeOne)[copied2])
		{
			temp[copied++] = data[copied++];
		} else
		{
			temp[copied++] = (data + sizeOne)[copied++];
		}
	}
	while (copied1 < sizeOne)
	{
		temp[copied++] = data[copied++];
	}
	while (copied2 < sizeTwo)
	{
		temp[copied++] = (data + sizeOne)[copied++];
	}
	for(index = 0; index < sizeOne + sizeTwo; index++)
	{
		data[index] = temp[index];
	}
	delete [] temp;
}

