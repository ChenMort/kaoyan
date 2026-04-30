#pragma once

#include<iostream>
#include<vector>

#include"../matrix/SymmetricMatrix.hpp"

template<typename VertexType>
class UndirectedGraph{
private:
    std::vector<VertexType> vertex_;
    SymmetricMatrix<size_t> edge_;   //边的最大数量由sizetype决定
public:

};