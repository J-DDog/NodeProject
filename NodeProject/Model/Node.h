/*
 * Node.h
 *
 *  Created on: Jan 29, 2016
 *      Author: jker3169
 */

#ifndef MODEL_NODE_H_
#define MODEL_NODE_H_

#include <iostream>

template <class Type>
class Node
{
public:
	Node();
	Node(const Type& value);
	virtual ~Node();
	Type getValue();
	void setValue(const Type& value);
	Node * getPointers();
private:
	Type value;			//Container for the value stored in the node
	Node * pointers;	//Pointer to the array of Nodes that are linked to this node
};


#endif /* MODEL_NODE_H_ */
