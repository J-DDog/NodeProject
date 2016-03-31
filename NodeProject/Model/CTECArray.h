/*
 * CTECArray.h
 *
 *  Created on: Feb 2, 2016
 *      Author: jker3169
 */

#ifndef MODEL_CTECARRAY_H_
#define MODEL_CTECARRAY_H_

#include "ArrayNode.h"

template <class Type>
class CTECArray {
public:
	CTECArray(int length);
	virtual ~CTECArray();
	int Length();
    int indexOf(Type searchValue);
    int nextIndexOf(int startingIndex, Type searchValue);
	Type get(int position);
	void set(int position, const Type& value);
    void selectionSort();
private:
    void swap(int indexOne, int indexTwo);
	int size;
	ArrayNode<Type>* head;
};

#endif /* MODEL_CTECARRAY_H_ */
