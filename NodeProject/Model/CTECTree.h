//
//  CTECTree.hpp
//  NodeProject
//
//  Created by Kerr, Jared on 4/11/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef CTECTREE_h_
#define CTECTREE_h_

#include "TreeNode.h"

template <class Type>
class CTECTree
{
    CTECTree();
    CTECTree(const Type& value);
    
    bool insert(const Type& value);
    bool contains(Type value);
    void remove(const Type& value);
    int getHeight();
    int getSize();
    bool isBalanced();
    TreeNode<Type>* getRoot();
    TreeNode<Type>* getLeftMostChild(CTECTree<Type> leftSubTree);
    TreeNode<Type>* getRightMostChild(CTECTree<Type> rightSubTree);
    void inorderTraversal(TreeNode<Type>* currrentNode);
    void postorderTraversal(TreeNode<Type>* currentNode);
    void preorderTraversal(TreeNode<Type>* currentNode);
    
private:
    bool balance;
    int height;
    int size;
    TreeNode<Type>* root;
    void remove(TreeNode<Type>* nodeToRemove);
    bool contains(Type value, CTECTree<Type>* currentTree);
    void calculateSize(TreeNode<Type>* currentNode);
    TreeNode<Type>* getLeftMostChild(CTECTree<Type> * leftSubTree);
    TreeNode<Type>* getRightMostChild(CTECTree<Type> * rightSubTree);
};

#endif /* CTECTree_hpp */
