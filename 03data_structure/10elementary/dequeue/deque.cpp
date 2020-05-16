#include<bits/stdc++.h>
using namespace std;
#include "deque.h"


int main(){
    Deque deque(5);
    try{
        deque.push_back(45);
        deque.push_front(2);
        deque.push_front(5);
        deque.push_front(7);
        deque.push_back(50);
      //deque.push_back(45);
    }catch(const std::overflow_error err){
        cout<<err.what()<<endl;
    }
    deque.print();
    //Code ends here
    cout<<endl<<" Working.";
    return 0;
}
