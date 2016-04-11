/*
 * Timer.cpp
 *
 *  Created on: Feb 16, 2016
 *      Author: ahun0442
 */

#include "Timer.h"
#include <iostream>
#include <iomanip> //Make output look nicer!
using namespace std;

Timer::Timer()
{
	executionTime = 0;
}

Timer::~Timer()
{

}

void Timer::displayTimerInformation()
{
	cout << fixed;
	cout << setprecision(8);

	cout << executionTime << " µs (microseconds) for the code " << endl;;
	cout << "Which is " << float(executionTime)/CLOCKS_PER_SEC << " seconds" << endl;
}

void Timer::startTimer()
{
	executionTime = clock();
}

void Timer::stopTimer()
{
	executionTime = 0;
}

void Timer::resetTimer()
{
	executionTime = 0;
}

long Timer::getExicutionTimeInMicroseconds()
{
	return executionTime;
}
