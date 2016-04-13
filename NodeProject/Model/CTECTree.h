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
    Type remove(const Type& value);
    int getHeight();
    int getSize();
    bool isBalanced();
    TreeNode<Type>* getRoot();
    void inorderTraversal(TreeNode<Type>* currrentNode);
    void postorderTraversal(TreeNode<Type>* currentNode);
    void preorderTraversal(TreeNode<Type>* currentNode);
    
private:
    bool balance;
    int height;
    int size;
    TreeNode<Type>* root;
    bool contains(Type value, CTECTree<Type>* currentTree);
    void calculateSize(TreeNode<Type>* currentNode);
};

#endif /* CTECTree_hpp */
