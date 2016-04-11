//
//  TreeNode.cpp
//  NodeProject
//
//  Created by Kerr, Jared on 4/11/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "TreeNode.h"

template <class Type>
TreeNode<Type>:: TreeNode()
{
    this->value = nullptr;
    this->parent = nullptr;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
};

template <class Type>
TreeNode<Type>:: TreeNode(const Type& value)
{
    this->value = value;
    this->parent = nullptr;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
};

template <class Type>
TreeNode<Type>:: TreeNode(const Type& value, TreeNode<Type>* parent)
{
    this->value = value;
    this->parent = parent;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
};