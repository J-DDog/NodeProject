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
    this->internalStorag = new HashNode<Type>[capacity];
    
};

template <class Type>
HashTable<Type>:: ~HashTable()
{
    delete [] internalStorage;
};

template <class Type>
int HashTable<Type>:: getSize()
{
    return this->size;
};

template <class Type>
void HashTable<Type>:: add(HashNode<Type> currentNode)
{
    if(!contains(currentNode))
    {
        if(this->size/this->capacity >= this->efficiencyPercentage)
        {
            updateSize();
        }
        int positionToInsert = findPosition(currentNode);
        
        if (internalStorage[positionToInsert] != nullptr)
        {
            //Loop to the next open postion.
            //Insert value there.
            
            while(internalStorage[positionToInsert] != nullptr)
            {
                positionToInsert = (positionToInsert + 1) % capacity;
            }
            internalStorage[positionToInsert] = currentNode;
        }
        else
        {
            internalStorage[positionToInsert] = currentNode;
        }
    }
};

template <class Type>
int HashTable<Type>:: findPosition(HashNode<Type> currentNode)
{
    // Hash the key of hashnode
    int position = 0;
    
    position = currentNode.getKe() % capacity;
    
    return position;
};