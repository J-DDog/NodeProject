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
    this->setValue(nullptr);
    this->parent = nullptr;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
};

template <class Type>
TreeNode<Type>:: TreeNode(const Type& value)
{
    this->setValue(value);
    this->parent = nullptr;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
};

template <class Type>
TreeNode<Type>:: TreeNode(const Type& value, TreeNode<Type>* parent)
{
    this->setValue(value);
    this->parent = parent;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
};

template <class Type>
TreeNode<Type>* TreeNode<Type>:: getParent()
{
    return this->parent;
};

template <class Type>
TreeNode<Type>* TreeNode<Type>:: getLeftChild()
{
    return this->leftChild;
};

template <class Type>
TreeNode<Type>* TreeNode<Type>:: getRightChild()
{
    return this->rightChild;
};

template <class Type>
void TreeNode<Type>:: setParent(TreeNode<Type>* parent)
{
    this->parent = parent;
};

template <class Type>
void TreeNode<Type>:: setLeftChild(TreeNode<Type>* leftChild)
{
    this->leftChild = leftChild;
};

template <class Type>
void TreeNode<Type>:: setRightChild(TreeNode<Type>* rightChild)
{
    this->rightChild = rightChild;
};
