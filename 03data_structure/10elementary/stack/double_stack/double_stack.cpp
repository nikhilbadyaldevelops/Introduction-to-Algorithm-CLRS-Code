#include<bits/stdc++.h>
using namespace std;
#include "double_stack.h"

int main(){
    DoubleStack d(4);
    try{
        cout<<d.push(1,4);
        cout<<d.push(1,5);
        cout<<d.push(1,34);
        cout<<d.push(2,6);
        cout<<d.push(3,7);
    }catch(const std::invalid_argument& e ){
        cout<<"Error."<<endl;
    }
    return 0;
}
