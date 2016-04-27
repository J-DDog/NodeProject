//
//  CtecGraph.hpp
//  NodeProject
//
//  Created by Kerr, Jared on 4/27/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef CtecGraph_hpp
#define CtecGraph_hpp

#include <set>

template <class Type>
class CTECGraph
{
public:
    CTECGraph();
    ~CTECGraph();
    
    void addVertex(const Type& value);
    void addEdge(int source, int target);
    void removeEdge(int source, int target);
    Type& operator [] (int vertex);
    Type operator [] (int vertex) const;
    int size();
    bool isEdge(int source, int target) const;
    std::set<int> neighbors(int vertex) const;
    
private:
    static const int MAXIMUM = 20;
    bool adjacencyMatx [MAXIMUM][MAXIMUM];
    Type labels[MAXIMUM];
    int manyVertices;
    
};

#endif /* CtecGraph_hpp */
