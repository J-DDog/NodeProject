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
    
    void insert(const Type& value);
    
private:
    bool balance;
    int height;
    TreeNode<Type>* root;
};

#endif /* CTECTree_hpp */
