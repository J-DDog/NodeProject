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

    cout<<coolStrings<<endl;

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

void NodeController:: setupIntArray()
{

}

void NodeController:: setupStringArray()
{

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
