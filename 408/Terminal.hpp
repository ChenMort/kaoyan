#pragma once

#include<iostream>
#include<vector>

/**
 * @brief 额外的终端函数
 * 
 */
namespace Terminal{

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i != vec.size() - 1) os << ", ";
    }
    os << "]";
    return os;
}
}