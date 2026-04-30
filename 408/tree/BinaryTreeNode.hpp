#pragma once

#include<iostream>

/**
 * @brief 常规二叉树树节点类
 * 请以指针形式声名
 * 链式存储
 */
template<typename ElemType>     // 数据元素类型
class BinaryTreeNode{
public:
    ElemType data_;
    BinaryTreeNode *lchild,*rchild;

    BinaryTreeNode():lchild(nullptr),rchild(nullptr){}
    BinaryTreeNode(ElemType data):data_(data),BinaryTreeNode(){}
    ~BinaryTreeNode(){
        delete lchild;
        delete rchild;
    }

    ElemType& getdata(){
        return data_;
    }
};