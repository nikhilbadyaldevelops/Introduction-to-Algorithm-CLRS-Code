#include<bits/stdc++.h>
using namespace std;
#include "../stack/stack.h"

class Queue{
private:
    Stack s1;
    Stack s2;
    int size ;

public:
    Queue(int size): s1(size/2) , s2(size-size/2){
        this->size = size;
    }

    bool isFull(){
        return s1.isFull();
    }
    bool isEmpty(){
        return false;
    }
    void enqueue(int value){
        if(!isFull()){
            s1.push(value);
            return ;
        }
        throw std::overflow_error("Overflow.");
    }
    void dequeue(){
        if(s1.isEmpty() && s2.isEmpty()){
            throw std::overflow_error("Underflow.");
        }
        if(s2.isEmpty()){
            while(!s1.isEmpty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        cout<<s2.top()<<endl;
        s2.pop();
    }

};

int main(){
    Queue q(5);
    try{
        for(int i = 0 ; i <2 ; ++i){
            q.enqueue(i);
        }
    }catch(const std::underflow_error under){
        cout<<under.what()<<endl;
    }catch(const std::overflow_error over){
        cout<<over.what()<<endl;
    }
    cout<<endl<<"Working ";
    return 0 ;

}
