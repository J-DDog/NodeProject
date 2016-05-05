//
//  HashTable.hpp
//  NodeProject
//
//  Created by Kerr, Jared on 5/5/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef HASHTABLE_H
#define HASHTABLE_H

template <class Type>
class HashTable
{
public:
    HashTable();
    ~HashTable();
    void add(const Type& value);
    bool remove(const Type& value);
    bool contains(const Type& value);
    int getSize();
    
private:
    int capacity;
    double efficiencyPercentage;
    int size;
    Type * internalStorage;
    
    int findPosition(const Type& value);
    int handleCollision(const Type& value);
    void updateSize();
    
};

#endif /* HashTable_hpp */
