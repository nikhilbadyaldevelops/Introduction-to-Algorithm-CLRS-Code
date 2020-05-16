#include<bits/stdc++.h>
using namespace std;
#include"../linked_list/singly/list.h"


class Queue{
private:
    List l;

public:
    Queue(): l(){}

    void enque(int value){
        l.insert_(value);
    }
    void deque(){
        l.delete_();
    }
    int top(){
        return l.head_();
    }

};
int main(){
    Queue s;
    s.enque(23);
    s.enque(56);
    s.enque(221);
    s.deque();
    s.deque();
    s.deque();
    //cout<<s.top();

    cout<<endl<<"Working.";
    return 0;
}
