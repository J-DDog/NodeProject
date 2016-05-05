//
//  HashTable.cpp
//  NodeProject
//
//  Created by Kerr, Jared on 5/5/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "HashTable.h"

template <class Type>
HashTable<Type>:: HashTable()
{
    this->capacity = 101;
    this->efficiencyPercentage = .667;
    this->size = 0;
    this->internalStorag = new Type[capacity];
    
};

template <class Type>
HashTable<Type>:: ~HashTable()
{
    delete [] internalStorage;
};

template <class Type>
int HashTable<Type>:: getSize()
{
    return this->size();
};

template <class Type>
void HashTable<Type>:: add(const Type &value)
{
    if(!contains(value))
    {
        int positionToInsert = findPosition(value);
        
        if (internalStorage[positionToInsert] != nullptr)
        {
            //Loop to the next open postion.
            //Insert value there.
            
            while(internalStorage[positionToInsert] != nullptr)
            {
                positionToInsert = positionToInsert +1 % size;
            }
            internalStorage[positionToInsert] = value;
        }
        else
        {
            internalStorage[positionToInsert] = value;
        }
    }
};