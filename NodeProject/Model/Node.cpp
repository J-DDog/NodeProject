/*
 * Node.cpp
 *
 *  Created on: Jan 29, 2016
 *      Author: jker3169
 */

#include "Node.h"
#include <iostream>

// Constructor
template <class Type>
Node<Type>::Node()
{
	pointers = nullptr;
}

// Constructor with the value
template <class Type>
Node<Type>::Node(const Type& value)
{
	this-> value = value;
	pointers = nullptr;
}

// Deconstructor
template <class Type>
Node<Type>::~Node()
{

}

template <class Type>
Type Node<Type>::getValue()
{
	return this->value;
}

template <class Type>
void Node<Type>::setValue(const Type& value)
{
	this->value = value;
}

template <class Type>
Node<Type> * Node<Type>::getPointers()
{
	return this->pointers;
}
