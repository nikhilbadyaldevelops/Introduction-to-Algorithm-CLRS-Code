#include<bits/stdc++.h>
using namespace std;
#include"../linked_list/singly/list.h"

class Stack{
private:
    List l;
public:
    Stack():l(){}

    void push(int value){
        l.insert(value);
    }
    void pop(){
        try{
            l.delete_();
        }catch(std::underflow_error err){
            throw std::underflow_error("Underflow.");
        }
    }
    void print(){
        l.print();
    }
};

int main(){
    Stack s;
    s.push(34);
    s.push(67);
    s.push(3);
    s.pop();
    s.print();
    cout<<"\nWorking.";
    return 0;
}
