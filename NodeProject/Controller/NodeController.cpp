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
    doQuickSort();
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
    
    for(int spot = 0; spot < 50; spot++)
    {
        cout << mergeData[spot] << ", " ;
    }
    
    Timer mergeTimer;
    mergeTimer.startTimer();
    mergeSort(mergeData, 5000);
    mergeTimer.stopTimer();
    mergeTimer.displayTimerInformation();
    
    for(int spot = 0; spot < 50; spot++)
    {
        cout << mergeData[spot] << ", " ;
    }
    
    delete [] mergeData;
    
}

void NodeController:: mergeSort(int data [], int size)
{
    int sizeOne;
    int sizeTwo;
    
    if(size > 1)
    {
        sizeOne = size/2;
        sizeTwo = size-sizeOne;
        
        mergeSort(data, sizeOne);
        mergeSort((data+sizeOne), sizeTwo);
        
        merge(data, sizeOne, sizeTwo);
    }
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


void NodeController:: doQuickSort()
{
    mergeData = new int[50000000];
    
    for(int spot = 0; spot < 50000000; spot++)
    {
        int myRandom = rand();
        mergeData[spot] = myRandom;
    }
    
    Timer mergeTimer;
    mergeTimer.startTimer();
    quickSort(0, 4999999);
    mergeTimer.stopTimer();
    mergeTimer.displayTimerInformation();
    
    delete [] mergeData;
    
}

void NodeController:: quickSort(int first, int last)
{
    int pivotIndex;
    
    if(first < last)
    {
        pivotIndex = partition(first, last);
        quickSort(first, pivotIndex-1);
        quickSort(pivotIndex+1, last);
        
    }
}

int NodeController:: partition(int first, int last)
{
    int pivot;
    
    int index, smallIndex;
    swap(first, (first + last)/2);
    
    pivot = mergeData[first];
    smallIndex = first;
    
    for(index = first + 1; index <= last; index++)
    {
        if(mergeData[index] < pivot)
        {
            smallIndex++;
            swap(smallIndex, index);
        }
        
    }
    swap(first, smallIndex);
    
    return smallIndex;
    
}

void NodeController:: swap(int first, int last)
{
    
}

void NodeController:: testHashTable()
{
    HashTable<int> tempTable;
    HashNode<int> tempArray[10];
    for(int spot = 0; spot < 10; spot++)
    {
        int randomValue = rand();
        int randomkey = rand();
        HashNode<int> temp = HashNode<int>(randomkey, randomValue);
        tempTable.add(temp);
        tempArray[spot] = temp;
    }
    bool test = tempTable.contains(tempArray[0]);
    string result;
    if(test)
    {
        result = "its there";
    }
    else
    {
        result = "not anywhere";
    }
    cout << result << endl;
}