#include <iostream>
#include "SymmetricMatrix.hpp"

using namespace std;


int main(){
    size_t n =10;
    SymmetricMatrix<int> s(n);

    for(size_t i=0;i<n;i++){
        for(size_t j=0;j<=i;j++){
            s[i][j]=i-j;
        }
    }
    for(size_t i=0;i<n;i++){
        for(size_t j=0;j<n;j++){
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    vector<int> temp(n);
    fill(temp.begin(),temp.end(),100);

    s[9]=temp;

    for(size_t i=0;i<n;i++){
        for(size_t j=0;j<n;j++){
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
}
