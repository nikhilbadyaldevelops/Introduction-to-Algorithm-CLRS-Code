#include<bits/stdc++.h>
using namespace std;
#include "queue.h"

int main(){
    Queue q(5);
    for(int i = 0 ; i<4 ; ++i){
        q.enqueue(i);
    }
    try{
        q.enqueue(45);
    }catch(std::exception err){
        cout<<"Error";
    }
    q.print();
    cout<<"Working";
    return 0;
}
