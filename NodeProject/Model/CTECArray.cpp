/*
 * CTECArray.cpp
 *
 *  Created on: Feb 2, 2016
 *      Author: jker3169
 */

#include "CTECArray.h"
#include <assert.h>
using namespace std;

// Constructor
template <class Type>
CTECArray<Type>::	CTECArray(int size)
{
	this->size = size;
	this->head = nullptr;

	assert(size > 0);


	head = nullptr;
	for(int spot = 0; spot < size; spot++)
	{

		if(head != nullptr) // make the next one
		{
			 ArrayNode<Type> * nextNode = new ArrayNode<Type>();
			 nextNode->setNext(head);
			 head = nextNode;
		}
		else
		{
			ArrayNode<Type> * first = new ArrayNode<Type>();
			head = first;
		}

	}


}

// Destructor
template <class Type>
CTECArray<Type>::	~CTECArray()
{
	ArrayNode<Type> * deleteNode = head;
	for(int spot = this->size; spot < 0; spot--)
	{
		if(deleteNode->getNext() != nullptr)
		{
			head = deleteNode->getNext();
			deleteNode->setNext(nullptr);
		}
		delete deleteNode->getNext();
		deleteNode = head;

	}
	delete head;
}

template <class Type>
int CTECArray<Type>:: Length()
{
	return this->size;

}

template <class Type>
int CTECArray<Type>::indexOf(Type value)
{
    assert(this->size > 0);
    int returnIndexOfValue;
    returnIndexOfValue = -1;
    ArrayNode<Type>* current = head;
    for(int index = 0; index < size; index++)
    {
        if(current->getValue() != value)
        {
            current = current->getNext();
        }
        else
        {
            returnIndexOfValue = index;
            break;
        }
        
    }
    return returnIndexOfValue;
}

template <class Type>
Type CTECArray<Type>::	get(int position)
{

	assert(position < size && position >=0);

	ArrayNode<Type> * current = head;
	for(int spot = 0; spot <= position; spot++) //Inclusive (inbounds)
	{

		if(spot != position) //Check if we have the desired position
		{
			current = current->getNext(); //Moving to next position
		}
		else
		{
			Type temp = current->getValue(); //Grabbing the value in the node
			return temp; //Returning a pointer to the value
		}
        
	}
    return current->getValue();
}

template <class Type>
void CTECArray<Type>::	set(int position, const Type& value)
{

	assert(position < size && position >=0);

	ArrayNode<Type> * current = head;
	for(int spot = 0; spot <= position; spot++) //Inclusive (inbounds)
	{

		if(spot != position) //Check if we have the desired position
		{
			current = current->getNext(); //Moving to next position
		}
		else
		{
			current->setValue(value); //Returning the current value because it has the position we want
		}
	}

}
