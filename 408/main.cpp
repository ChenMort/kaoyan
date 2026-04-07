#include <iostream>
#include "SqList.hpp"

int main(){
   SqList<int>list(10);
   list.display();
   list.insert(0,10);
   list.insert(5,10);
   list.insert(12,10);
   list.display();

}