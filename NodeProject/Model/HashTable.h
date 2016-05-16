//
//  HashTable.hpp
//  NodeProject
//
//  Created by Kerr, Jared on 5/5/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "CTECArray.h"
#include "CTECList.h"

#include "HashNode.h"

#include <cmath>

template <class Type>
class HashTable
{
public:
    HashTable();
    ~HashTable();
    
    void addTable(HashNode<Type> currentNode);
    
    void add(HashNode<Type> currentNode);
    bool remove(HashNode<Type> currentNode);
    bool contains(HashNode<Type> currentNode);
    int getSize();
    
private:
    int capacity;
    int tableCapacity;
    double efficiencyPercentage;
    int size;
    int tableSize;
    Type * internalStorage;
    HashNode<Type> ** internalArray;
    CTECList<HashNode<Type>> tableStorage;
    
    int findPosition(HashNode<Type> currentNode);
    int handleCollision(HashNode<Type> currentNode);
    void updateSize();
    void updateTableCapacity();
    
    int getNextPrime();
    bool isPrime(int candidateNumber);
    
};

#endif /* HashTable_hpp */
