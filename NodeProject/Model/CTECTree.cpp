//
//  CTECTree.cpp
//  NodeProject
//
//  Created by Kerr, Jared on 4/11/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "CTECTree.h"
using namespace std;

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
    TreeNode<Type>* newNode = new TreeNode<Type>(value);
    assert(newNode != nullptr);
    TreeNode<Type>* current = root;
    TreeNode<Type>* trailCurrent;
    if(root == nullptr)
    {
        root = newNode;
        return true;
    }
    else
    {
        
        while(current != nullptr)
        {
            trailCurrent = current;
            if(current-> getValue() == value)
            {
                return false;
            }
            else if(current->getValue > value)
            {
                current = current-> getLeftChild();
            }
            else
            {
                current = current-> getRightChild();
            }
        }
        
        if(trailCurrent-> getValue > value)
        {
            trailCurrent-> setLeftChild(newNode);
        }
        else
        {
            trailCurrent-> setRightChild(newNode);
        }
        return true;
        
    }
};

template <class Type>
bool CTECTree<Type>:: contains(Type value)
{
    if(root-> getValue() == value)
    {
        return true;
    }
    
    else if(value < root-> getValue())
    {
        return contains(value, root-> getLeftChild());
    }
    
    else
    {
        return contains(value, root-> getRightChild());
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
    
    if(currentTree-> getRoot-> getValue() == value)
    {
        return true;
    }
    
    else if(value < currentTree-> getRoot-> getValue())
    {
        return contains(value, currentTree-> getRoot-> getLeftChild());
    }
    
    else
    {
        return contains(value, currentTree-> getRoot-> getRightChild());
    }
    
    return false;
};

template <class Type>
void CTECTree<Type>:: remove(const Type& value)
{
    TreeNode<Type>* current = root;
    TreeNode<Type>* trailing = current;
    if(!contains(value))
    {
        return;
    }
    else
    {
        while(current != nullptr && current-> getValue() != value)
        {
            trailing = current;
            if(current-> getValue() > value)
            {
                current = current-> getLeftChild();
            }
            else
            {
                current = current-> getRightChild();
            }
        }
        
        if(current == root)
        {
            remove(root);
        }
        else if(trailing-> getLeftChild() > value)
        {
            remove(trailing-> getLeftChild());
        }
        else
        {
            remove(trailing-> getRightChild());
        }
    }

};

template <class Type>
void CTECTree<Type>:: remove(TreeNode<Type>* nodeToRemove)
{
    TreeNode<Type>* current;
    TreeNode<Type>* trailing;
    TreeNode<Type>* temp;
    
    if(nodeToRemove == nullptr)
    {
        cerr << "cant Remove an empty non existent thing" << endl;
    }
    else if(nodeToRemove-> getRgihtChild() == nullptr && nodeToRemove-> getLeftChild() == nullptr)
    {
        temp == nodeToRemove;
        nodeToRemove = nullptr;
        delete temp;
    }
    else if(nodeToRemove-> getRightChild() == nullptr)
    {
        temp == nodeToRemove;
        nodeToRemove = temp-> getLeftChild();
        delete temp;
    }
    else if(nodeToRemove-> getLeftChild() == nullptr)
    {
        temp == nodeToRemove;
        nodeToRemove = temp->getRightChild;
        delete temp;
    }
    else
    {
        current = nodeToRemove-> getLeftChild();
        trailing = nullptr;
        
        while(current-> getRightChild != nullptr)
        {
            trailing = current;
            current = current-> getRightChild();
        }
        
        
        nodeToRemove-> setValue(current-> getValue);
        
        if(trailing == nullptr)
        {
            nodeToRemove-> setLeftChild(current-> getLeftChild());
        }
        else
        {
            trailing-> setRightChild(current-> getLeftChild());
        }
        
        delete current();
    }
}

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
TreeNode<Type>* CTECTree<Type>:: getLeftMostChild(CTECTree<Type>* leftSubTree)
{
    TreeNode<Type>* leftNode = leftSubTree-> getRoot();
    while(leftNode-> getLeftChild != nullptr)
    {
        leftNode = leftNode-> getLeftChild();
    }
    return leftNode;
};

template <class Type>
TreeNode<Type>* CTECTree<Type>:: getRightMostChild(CTECTree<Type> rightSubTree)
{
    TreeNode<Type>* rightNode = rightSubTree-> getRoot();
    while(rightNode-> getLeftChild != nullptr)
    {
        rightNode = rightNode-> getLeftChild();
    }
    return rightNode;
}

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