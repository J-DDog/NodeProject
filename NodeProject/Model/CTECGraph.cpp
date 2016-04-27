//
//  CtecGraph.cpp
//  NodeProject
//
//  Created by Kerr, Jared on 4/27/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "CTECGraph.h"

template <class Type>
const int CTECGraph<Type> :: MAXIMUM;

template <class Type>
void CTECGraph<Type> :: addVertex(const Type& value)
{
    assert(size() < MAXIMUM);
    int newVertexNumber = manyVertices;
    manyVertices++;
    
    for(int otherVertexNumber = 0; otherVertexNumber < manyVertices; otherVertexNumber++)
    {
        adjacencyMatx[otherVertexNumber][newVertexNumber] = false;
        adjacencyMatx[newVertexNumber][otherVertexNumber] = false;
    }
    labels[newVertexNumber] = value;
    
}

template <class Type>
void CTECGraph<Type>:: addEdge(int source, int target)
{
    assert(source < size() && target < size());
    adjacencyMatx[source][target] = true;
}

template <class Type>
bool CTECGraph<Type> :: isEdge(int source, int target) const
{
    assert(source < size() && target < size());
    
    bool isAnEdge = false;
    isAnEdge = adjacencyMatx[source][target];
    
    return isAnEdge;
}

template <class Type>
Type& CTECGraph<Type>:: operator[](int vertex)
{
    assert(vertex < size());
    return labels[vertex];
}

template <class Type>
Type CTECGraph<Type>:: operator[](int vertex) const
{
    assert(vertex < size());
    return labels[vertex];
}

template <class Type>
std::set<int> CTECGraph<Type>:: neighbors(int vertex) const
{
    assert(vertex < size());
    std::set<int> vertexNeighbors;
    
    for(int index = 0; index < size(); index++)
    {
        if(adjacencyMatx[vertex][index])
        {
            vertexNeighbors.insert(index);
        }
    }
    return vertexNeighbors;
}

template <class Type>
void CTECGraph<Type>:: removeEdge(int source, int target)
{
    assert(source < size() && target < size());
    adjacencyMatx[source][target] = false;
}