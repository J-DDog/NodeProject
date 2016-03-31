/*
 * NodeController.cpp
 *
 *  Created on: Jan 29, 2016
 *      Author: jker3169
 */

#include <iostream>
#include "NodeController.h"

NodeController::		NodeController()
{
	this->notHipsterInts = new CTECArray<int>(5);
	this->coolStrings = new CTECList<string>(5);
}

NodeController::		~NodeController()
{

}

void NodeController::	start()
{
	arrayTimer.startTimer();

    cout<<coolStrings->getFront()<<endl;

	coolStrings->addAtIndex(2, "added to 2");
	coolStrings->addToEnd("added to end");
	coolStrings->addToFront("added to front");

	cout<<coolStrings<<endl;

	string temp = coolStrings->removeFromIndex(1);
	cout<<temp<<endl;

	temp = coolStrings->removeFromFront();
	cout<<temp<<endl;

	temp = coolStrings->removeFromEnd();
	cout<<temp<<endl;

	temp = coolStrings->getFromIndex(1);
	cout<<temp<<endl;

	temp = coolStrings->getFront();
	cout<<temp<<endl;

	temp = coolStrings->getEnd();
	cout<<temp<<endl;

	arrayTimer.stopTimer();
	arrayTimer.displayTimerInformation();
}

void NodeController:: print()
{
		cout << notHipsterInts->Length() << endl;
		for(int index = 0; index < notHipsterInts->Length(); index++)
		{
			notHipsterInts->set(index, (23 * index));
			cout << index << endl;
		}


		for(int index = 0; index < notHipsterInts->Length(); index++)
		{
			cout << notHipsterInts->get(index) << endl;
		}
}

void NodeController:: doMergesort()
{
    mergeData = new int[5000];
    
    for(int spot = 0; spot < 5000; spot++)
    {
        int myRandom = rand();
        mergeData[spot] = myRandom;
    }
    
    Timer mergeTimer;
    mergeTimer.startTimer();
    mergeSort(mergeData, 5000);
    mergeTimer.stopTimer();
    mergeTimer.displayTimerInformation();
}

void NodeController:: mergeSort(int data [], int size)
{
    
}

void NodeController:: merge(int data [], int sizeOne, int sizeTwo)
{
    int * temp;
    int copied = 0;
    int copied1 = 0;
    int copied2 = 0;
    int index;
    
    temp = new int[sizeOne + sizeTwo];
    
    while((copied1 < sizeOne) && (copied2 < sizeTwo))
    {
        if(data[copied1] < (data + sizeOne)[copied2])
        {
            temp[copied++] = data[copied1++];
        }
        else
        {
            temp[copied++] = (data + sizeOne)[copied2++];
        }
    
    }
    
    while(copied1 < sizeOne)
    {
        temp[copied++] = data[copied1++];
    }
    while(copied2 < sizeTwo)
    {
        temp[copied++] = (data + sizeOne)[copied2++];
    }
    
    for(index = 0; index < sizeOne + sizeTwo; index++)
    {
        data[index] = temp[index];
    }
    delete[] temp;
    
}
