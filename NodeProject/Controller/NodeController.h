/*
 * NodeController.h
 *
 *  Created on: Jan 29, 2016
 *      Author: jker3169
 */

#ifndef COM_CTEC_CONTROLLER_NODECONTROLLER_H_
#define COM_CTEC_CONTROLLER_NODECONTROLLER_H_

#include <iostream>
#include <string>
#include "../Model/Node.h"
#include "../Model/Node.cpp"
#include "../Model/ArrayNode.h"
#include "../Model/ArrayNode.cpp"
#include "../Model/CTECArray.h"
#include "../Model/CTECArray.cpp"
#include "../Model/CTECList.h"
#include "../Model/CTECList.cpp"
#include "../Model/Timer.h"

using namespace std;

class NodeController
{
public:
	NodeController();
	virtual ~NodeController();
	void start();
private:
	CTECArray<int>* notHipsterInts;
    CTECList<int>* sortable;
	CTECList<string>* coolStrings;
	Timer arrayTimer;

    void sortData();
    void testList();
    void searchTest();
    
    int * mergeData;
    void doMergesort();
    void mergeSort(int data [], int size);
    void merge(int data [], int sizeOne, int sizeTwo);
    void doQuickSort();
    void quickSort(int first, int last);
    int partition(int first, int last);
    void swap(int first, int last);
    void print();
};

#endif /* COM_CTEC_CONTROLLER_NODECONTROLLER_H_ */
