#pragma once

#include <iostream>
#include <vector>

/**
 * @brief 对称矩阵类 (Symmetric Matrix)
 * 采用下三角压缩存储空间，空间复杂度 O(n^2 / 2)
 * 20260414基本实现索引存取，索引赋值
 */
template<typename ElemType>
class SymmetricMatrix{
private:
    //对称矩阵阶数
    size_t dimension_;
    //存储矩阵的数组
    std::vector<ElemType> data;

    size_t getIndex(size_t row,size_t col){
        if(row>=col)
            return row*(row+1)/2+col;
        else
            return col*(col+1)/2+row;
    }

public:
    SymmetricMatrix(size_t n):dimension_(n),data(n*(n+1)/2){}


    // --- 实现 [i][j] 的关键：代理类 ，意味着第一次索引返回的是此类，使用auto避免出错---
    struct RowProxy {
        SymmetricMatrix& parent;
        size_t row;

        // 第二个 [] 会调用这个函数
        ElemType& operator[](size_t col) {
            return parent.data[parent.getIndex(row, col)];
        }

        RowProxy& operator=(std::vector<ElemType>& rowData){
            if (rowData.size()!=parent.dimension_)
            throw std::invalid_argument("Vector size mismatch");

            for (size_t j = 0; j < parent.dimension_; ++j) {
            (*this)[j] = rowData[j]; 
            }
            return *this;
        }
    };

    // 第一个 [] 返回代理类对象
    RowProxy operator[](size_t row) {
        return RowProxy{*this, row};
    }

};