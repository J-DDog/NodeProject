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
    this-> size = 0;
    this-> root = nullptr;
};

template <class Type>
CTECTree<Type>::CTECTree(const Type& value)
{
    this-> balance = true;
    this-> height = 1;
    this-> size = 1;
    this-> root = new TreeNode<Type>(value);
};

template <class Type>
bool CTECTree<Type>:: insert(const Type& value)
{
    if(contains(value))
    {
        return false;
    }
    else
    {
        if(value < root->getValue())
        {
            insert(value, root->getLeftChild());
        }
        else
        {
            insert(value, root->getRightChild());
        }
        return true;
    }
};

template <class Type>
bool CTECTree<Type>:: contains(Type value)
{
    if(root->getValue() == value)
    {
        return true;
    }
    
    else if(value < root->getValue())
    {
        return contains(value, root->getLeftChild());
    }
    
    else
    {
        return contains(value, root->getRightChild());
    }
    
    return false;
};

template <class Type>
bool CTECTree<Type>:: contains(Type value, CTECTree<Type>* currentTree)
{
    if(currentTree == nullptr)
    {
        return false;
    }
    
    if(currentTree->getRoot->getValue() == value)
    {
        return true;
    }
    
    else if(value < currentTree->getRoot->getValue())
    {
        return contains(value, currentTree->getRoot->getLeftChild());
    }
    
    else
    {
        return contains(value, currentTree->getRoot->getRightChild());
    }
    
    return false;
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
int CTECTree<Type>:: getSize()
{
    this-> size = 0;
    calculateSize(root);
    return this-> size;
};

template <class Type>
void CTECTree<Type>:: calculateSize(TreeNode<Type>* currentNode)
{
    if(currentNode != nullptr)
    {
        calculateSize(currentNode->getLeftChild());
        calculateSize(currentNode->getRightChild());
        this-> size++;
    }
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

template <class Type>
void CTECTree<Type>:: inorderTraversal(TreeNode<Type>* currentNode)
{
    if(currentNode != nullptr)
    {
        inorderTraversal(currentNode->getLeftChild());
        std::cout << currentNode->getValue() << " ";
        inorderTraversal(currentNode->getRightChild());
    }
};

template <class Type>
void CTECTree<Type>:: postorderTraversal(TreeNode<Type>* currentNode)
{
    if(currentNode != nullptr)
    {
        std::cout << currentNode->getValue() << " ";
        inorderTraversal(currentNode->getLeftChild());
        inorderTraversal(currentNode->getRightChild());
    }
};

template <class Type>
void CTECTree<Type>:: preorderTraversal(TreeNode<Type>* currentNode)
{
    if(currentNode != nullptr)
    {
        inorderTraversal(currentNode->getLeftChild());
        inorderTraversal(currentNode->getRightChild());
        std::cout << currentNode->getValue() << " ";
    }
};