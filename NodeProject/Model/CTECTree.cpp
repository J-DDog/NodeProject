//
//  CTECTree.cpp
//  NodeProject
//
//  Created by Kerr, Jared on 4/11/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "CTECTree.h"

template <class Type>
CTECTree<Type>::CTECTree()
{
    this-> balance = true;
    this-> height = 0;
    this-> root = nullptr;
};

template <class Type>
CTECTree<Type>::CTECTree(const Type& value)
{
    this-> balance = true;
    this-> height = 0;
    this-> root = new TreeNode<Type>(value);
};

template <class Type>
bool CTECTree<Type>:: insert(const Type& value)
{
    if(this-> root == nullptr)
    {
        this-> root = new TreeNode<Type>(value);
    }
    else
    {
        TreeNode<Type>* current;
        for(int level = 0; level < height; level++)
        {
            if(current->getValue >= value)
            {
                
            }
            else
            {
                
            }
        }
    }
    return false;
};

template <class Type>
bool CTECTree<Type>:: contains(Type value)
{
    
};

template <class Type>
Type CTECTree<Type>:: remove(const Type& value)
{
    
};

template <class Type>
int CTECTree<Type>:: getHeight()
{
    return this-> height;
};

template <class Type>
bool CTECTree<Type>:: isBalanced()
{
    return this-> balance;
};

template <class Type>
TreeNode<Type>* CTECTree<Type>:: getRoot()
{
    return this-> root;
};