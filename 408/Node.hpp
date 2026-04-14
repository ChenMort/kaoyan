#pragma once

#include<iostream>

/**
 * @brief 单链表节点类 
 * 20260414节点后插入
 */
template<typename ElemType>     // 数据元素类型
class Node {           //单链表
public:
    ElemType data;      //数据
    Node* next;         //下一节点
    Node(){Node=NULL}
    Node(ElemType data):data(data){};
    Node(ElemType data,Node* next):data(data),next(next){};

    //在节点后插入新节点
    bool insert(Node*node,ElemType x){
        if (Node==nullptr)return false;
        
        try{
            Node* new_node = new Node(x);
            
            new_node->next=node->next;
            node->next=new_node;
        }catch(const std::bad_alloc& e){
            //std::cerr << "[ERROR] Node 内存分配失败: " << e.what() << std::endl;
            return false;
        }
        
    }
    bool insert(Node*node,Node*new_node){
        if (Node==nullptr)return false;
        
        new_node->next=node->next;
        node->next=new_node;
        return true
    }

};
