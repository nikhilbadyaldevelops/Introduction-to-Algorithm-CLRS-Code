#include<bits/stdc++.h>
using namespace std;
#include "stack.h"


int main(){
    Stack s(5);
    for(int i = 0 ; i <= 5;  ++i){
        s.push(i);
    }
    for(int i = 0 ; i <= 5; ++i){ 
        s.pop();
    }
    s.print();
    return 0 ;
}
