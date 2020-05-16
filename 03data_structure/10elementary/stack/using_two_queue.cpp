#include<bits/stdc++.h>
using namespace std;
#include "../queue/queue.h"

class Stack{
private:
    Queue q1;
    Queue q2;
    int size_;
public:
    Stack(int size): q1(size+1) , q2(size+1){
        this->size_ = size;
    }
    void push(int value){
        if(!q1.isFull()){
            q1.enqueue(value);
            return;
        }
        throw std::overflow_error("Overflow.");
    }
    void pop(){
        if(!q1.isEmpty() && q2.isEmpty()){
            while(q1.size() != 1){
                q2.enqueue(q1.front());
                q1.dequeue();
            }
            cout<<q1.front()<<endl;
            q1.dequeue();
            return ;
        }else if(!q2.isEmpty() && q1.isEmpty()){
            while(q2.size() != 1){
                q1.enqueue(q2.front());
                q2.dequeue();
            }
            cout<<q2.front()<<endl;
            q2.dequeue();
            return ;
        }
        throw std::underflow_error("Underflow.");
    }

};
int main(){
    Stack s(2);
    for(int i = 0 ; i < 2; ++i){
        s.push(i);
    }
    cout<<"\nWorking.";
    return 0;
}
