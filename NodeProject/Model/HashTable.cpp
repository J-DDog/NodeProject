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
    this->internalStorag = new HashNode<Type>*[capacity];
    this->tableStorage = new CTECList<HashNode<Type>>[capacity];
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
void HashTable<Type>:: addTable(HashNode<Type> currentNode)
{
    if(this->tableSize/this->tableCapacity >= this->efficencyPercentage)
    {
        updateTableCapacity();
    }
    int positionToInsert = findPosition(currentNode);
    
    if(tableStorage[positionToInsert] == nullptr)
    {
        CTECList<HashNode<Type>> hashList;
        tableStorage[positionToInsert] + hashList;
        hashList.addEnd(currentNode);
    }
    else
    {
        tableStorage[positionToInsert].addEnd(currentNode);
    }
};

template <class Type>
void HashTable<Type>:: updateTableCapacity()
{
    int updatedCapacity = getNextPrime();
    CTECList<HashNode<Type>>* updatedTableStorage = new CTECList<HashNode<Type>> [updatedCapacity];
    
    int oldTableCapacity = tableCapacity;
    tableCapacity = updatedCapacity;
    
    for(int index = 0; index < oldTableCapacity; index++)
    {
        if(tableStorage[index] != nullptr)
        {
            CTECList<HashNode<Type>> temp = tableStorage[index];
            for(int innerIndex = 0; innerIndex < temp.getSize(); innerIndex++)
            {
                int updatedTablePosition = findPosition(temp.getFromIndex(index));
                if(updatedTableStorage[updatedTablePosition] == nullptr)
                {
                    CTECList<HashNode<Type>> updatedList;
                    updatedList.addEnd(temp.getFromIndex(index));
                }
                else
                {
                    updatedTableStorage[updatedTablePosition].addEnd(temp.getFromIndex(index));
                }
                
            }
        }
    }
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
        }
        internalStorage[positionToInsert] = &currentNode;
        size++;
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

template <class Type>
int HashTable<Type>:: getNextPrime()
{
    int nextPrime = (capacity * 2) + 1;
    
    while(!isPrime(nextPrime))
    {
        nextPrime++;
    }
    
    return nextPrime;
};

template <class Type>
bool HashTable<Type> :: isPrime(int candidateNumber)
{
    bool isPrime = true;
    
    if(candidateNumber <= 1)
    {
        return false;
    }
    else if(candidateNumber == 2 || candidateNumber == 3)
    {
        isPrime = true;
    }
    else if(candidateNumber % 2 == 0)
    {
        
    }
    else
    {
        for(int next = 3; next <= sqrt(candidateNumber) + 1; next += 2)
        {
            if(candidateNumber % next == 0)
            {
                isPrime = false;
                break;
            }
        }
    }
    return isPrime;
};

template <class Type>
void HashTable<Type> :: updateSize()
{
    int updatedCapacity = getNextPrime();
    HashNode<Type>** updatedStorage = new HashTable<Type>*[updatedCapacity];
    
    int oldCapacity = capacity;
    capacity = updatedCapacity;
    
    for(int index = 0; index < oldCapacity; index++)
    {
        if( internalStorage[index] != nullptr)
        {
            int updatedPosition = findPosition(*internalStorage[index]);
            updatedStorage[updatedPosition] = internalStorage[index];
        }
    }
    internalStorage = updatedStorage;
};

template <class Type>
bool HashTable<Type>:: contains(HashNode<Type> currentNode)
{
    bool isInTable = false;
    
    int index = findPosition(currentNode);
    while(internalStorage[index] != nullptr && !isInTable)
    {
        if(internalStorage[index].getValue() == currentNode.getValue())
        {
            isInTable = true;
        }
        else
        {
            index = (index + 1) % capacity;
        }
        
    }
    
    return isInTable;
};

template <class Type>
bool HashTable<Type> :: remove(HashNode<Type> currentNode)
{
    bool wasRemoved = false;
    
    if(contains(currentNode))
    {
        int index = findPosition(currentNode);
        while(internalStorage[index] != nullptr && !wasRemoved)
        {
            if(internalStorage[index].getValue() == currentNode.getValue())
            {
                wasRemoved = true;
                internalStorage[index] = nullptr;
                size--;
            }
            else
            {
                index = (index + 1) % capacity;
            }
        }
    }
    
    return wasRemoved;
};

template <class Type>
int HashTable<Type>::handleCollision(HashNode<Type> currentNode)
{
    int reHashedPosition = findPosition(currentNode);
    int randomEven = rand(capacity);
    reHashedPosition = randomEven + (reHashedPosition * reHashedPosition) % capacity;
    
    return reHashedPosition;
};