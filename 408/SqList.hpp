#pragma once

#include <iostream>

template<typename ElemType>     // 数据元素类型
class SqList {
private:
    ElemType* data;             // 表头指针
    int length;                 // 表长 
public:
    SqList(int length = 0) {
        data = new ElemType[length];
        this->length = length;
    }
    ~SqList() {
        delete[] data;
    }

    // 在索引 location 处插入元素 e
    bool insert(int location, ElemType e) {
  
        if (location < 0 || location > length) {
            return false;
        }

        ElemType* NewData = new ElemType[length+1];     //创建新的表，长度加1

        for(int i=0;i<location;i++){       
            NewData[i]=data[i];             //之前元素照常插入
        }
        NewData[location]=e;                //插入元素
        for(int i=location;i<length;i++){   
            NewData[i+1]=data[i];           //插入之后的元素
        }
        data=NewData;
        length++;
        return true;
    }

    // 打印函数，方便调试
    void display() {
        for (int i = 0; i < length; i++) {
            std::cout << data[i] << (i == length - 1 ? "" : ", ");
        }
        std::cout << " [Current Length: " << length << "]" << std::endl;
    }
};