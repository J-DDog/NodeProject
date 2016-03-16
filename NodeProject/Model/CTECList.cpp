/*
 * CTECList.cpp
 *
 *  Created on: Feb 22, 2016
 *      Author: jker3169
 */

#include "CTECList.h"
#include <assert.h>

template <class Type>
CTECList<Type>::CTECList()
{
	this->size = 0;
	this->head = nullptr;
	this->end = nullptr;

}

template <class Type>

CTECList<Type>::CTECList(int size)
{
	this->size = size;
	this->head = nullptr;
	this->end = nullptr;

	assert(size > 0);

	for(int spot = 0; spot < size; spot++)
	{

		if(this->head != nullptr) //Make the first one
		{
			 ArrayNode<Type> * nextNode = new ArrayNode<Type>();
			 nextNode->setNext(this->head);
			 this->head = nextNode;
			 this->end = nextNode;
		}
		else //Make the next one
		{
			ArrayNode<Type> * first = new ArrayNode<Type>();
			this->head = first;
		}

	}

}

/*
 * 1: Start at head
 * 2: Iterate over Nodes
 * 3: Update position, then delete
 * 4: Delete Final
 * 5: Reset size
 */
template <class Type>
CTECList<Type>::~CTECList()
{
	ArrayNode<Type>* current = head;

	for(int deleteCount = 0; deleteCount < size; deleteCount++)
	{
		ArrayNode<Type>* temp = current;

		current = current->getNext();
		head = current;
		delete temp;
	}

	delete head;
	head = nullptr;
	end = nullptr;
	size = 0;
}

template <class Type>
int CTECList<Type>::getSize()
{
	this->calculateSize();
	return this->size;
}

template <class Type>
int CTECList<Type>::indexOf(Type value)
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

//Private helper method
template <class Type>
void CTECList<Type>::calculateSize()
{
	//Make sure that the list has content
	assert(this->size >= 0);

	//Declare variables
	ArrayNode<Type>* counterPointer = this->head;
	int count = 0;

	//Check if there is anything in the list
	if(counterPointer == nullptr)
	{
		//sets the size to 0 and ends the method
		this->size = 0;
		return;

	}
	else
	{
		//If not then add 1 to count and begin the counting loop
		count++;
		while(counterPointer->getNext() != nullptr)
		{
			counterPointer = counterPointer->getNext();
			count++;
		}

		//Setting size after the list has been counted
		this->size = count;
	}

}

template <class Type>
void CTECList<Type>::addToFront(const Type& value)
{
	//Create newNode with value
	//Set newNode's next to head
	//Set head to newNode
	//calculate size

	ArrayNode<Type>* newNode = new ArrayNode<Type>(value);
	newNode->setNext(this->head);
	this->head->setNext(newNode);
	calculateSize();
}

template <class Type>
void CTECList<Type>::addToEnd(const Type& value)
{
	//Make newNode with value
	//set end's next to newNode
	//set end to newNode
	//calculate size

	ArrayNode<Type>* newNode = new ArrayNode<Type>(value);
	this->end->setNext(newNode);
	this->end = newNode;
	this->calculateSize();

}

template <class Type>
void CTECList<Type>::addAtIndex(int index, const Type& value)
{
	//check if index is 0 or size-1
	//call add methods if so
	//make newNode from value
	//else loop to before index
	//set newNode's next to currentNodes next
	//set currentNode's next to newNode
	//Calculate size

	assert(index >= 0 && index <= this->size);

	if(index == 0)
	{
		this->addToFront(value);
	}
	else if(index == this->size)
	{
		this->addToEnd(value);
	}
	else
	{
		ArrayNode<Type>* newNode = new ArrayNode<Type>(value);
		ArrayNode<Type>* currentNode = this->head;
		for(int spot = 0; spot < index; spot++)
		{
			currentNode = currentNode->getNext();
		}
		newNode->setNext(currentNode->getNext());
		currentNode->setNext(newNode);
		this->calculateSize();

	}

}

template <class Type>
Type CTECList<Type>::getFront()
{
	assert(this->size > 0);
	return this->head->getValue();
}

template <class Type>
Type CTECList<Type>::getEnd()
{
	assert(this->size > 0);
	return this->end->getValue();
}

template <class Type>
Type CTECList<Type>::getFromIndex(int index)
{
	//If its not front or back
	//loop to index
	//return value from index

	assert(this->size > 0 && index >= 0 && index < this->size);

	if(index == 0)
	{
		return this->getFront();
	}
	else if(index == this->size-1)
	{
		return this->getEnd();
	}
	else
	{
		ArrayNode<Type>* returnNode = this->head;
		for(int pos = 0; pos <= index; pos++)
		{
			returnNode = returnNode->getNext();
		}
        return returnNode->getValue();
	}
    
}

template <class Type>
Type CTECList<Type>::removeFromFront()
{
	assert(this->size > 0);
	//Declaring the the value to be returned
	Type returnValue;
	//Create a pointer to what is after head
	ArrayNode<Type>* newHead;
	//Setting the newHead as the next Node
	newHead = this->head->getNext();
	//Getting the value
	returnValue = this->head->getValue();
	//Delete what head is pointing to
	delete this->head;
	//Set head to the new head
	this->head = newHead;

	this->calculateSize();

	//Returning the value
	return returnValue;
}

template <class Type>
Type CTECList<Type>::removeFromEnd()
{
	//Loop over size
	//or
	//Loop until getNext()->getNext() == nullptr
	//Call calculate size before returning the value

	assert(this->size > 0);

	//Declaring variables
	ArrayNode<Type>* deleteNode = this->end;
	ArrayNode<Type>* previousNode = this->head;
	Type returnValue;

	//Looping up the the previous to last node
	for(int index = 0; index < this->size-1; index++)
	{
		previousNode = previousNode->getNext();
	}

	//Setting the previousNode pointer to null
	previousNode->setNext(nullptr);
	//Getting the last value
	returnValue = deleteNode->getValue();
	//Deleting the node
	delete deleteNode;

	this->end = previousNode;

	this->calculateSize();
	//Returning the value
	return returnValue;

}

template <class Type>
Type CTECList<Type>::removeFromIndex(int index)
{

	assert(this->size > 0 && index >= 0 && index < this->size);

	//Declaring variables
	ArrayNode<Type>* deleteNode = head;
	ArrayNode<Type>* previousNode;
	Type returnValue;

	if(index == 0)
	{
		returnValue = removeFromFront();
	}
	else if(index == this->size - 1)
	{
		returnValue = removeFromEnd();
	}
	else
	{
		for(int spot = 0; spot < index; spot++)
		{
			deleteNode = deleteNode->getNext();
		}

		previousNode = deleteNode;
		//Moving to the last node
		deleteNode = deleteNode->getNext();
		//Setting the previousNode pointer to the next Pointer or null
		previousNode->setNext(deleteNode->getNext());
		//Getting the last value
		returnValue = deleteNode->getValue();
		//Deleting the node
		delete deleteNode;
	}


	//Returning the value
	return returnValue;
}

template <class Type>
void CTECList<Type>::set(int index, const Type& value)
{
	//Check if index is 0
	//if so set head value to new value
	//else if index is size-1
	//if so set end value to new value
	//else loop to index
	//set index value to new value

	if(index == 0)
	{
		this->head->setValue(value);
	}
	else if(index == this->size-1)
	{
		this->end->setValue(value);
	}
	else
	{
		ArrayNode<Type>* currentNode = this->head;
		for(int spot = 0; spot <= index; spot++)
		{
			currentNode = currentNode->getNext();
		}
		currentNode->setValue(value);
	}
}
