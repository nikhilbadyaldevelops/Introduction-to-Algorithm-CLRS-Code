class Stack{
private:
    int top_pos = -1;
    int size = 0 ;
    vector<int> stack;
public:

    Stack(int size){
        this->top_pos =-1;
        this->size = size;
    }
    bool isEmpty(){
        if(top_pos == -1 || size == 0 ){
            return true;
        }
        return false;
    }
    bool isFull(){
        if(top_pos == size -1){
            return true;
        }
        return false;
    }
    void push(int value){
        if(!isFull()){
            stack.push_back(value);
            top_pos++;
            return ;
        }
        throw std::overflow_error("Overflow.");
    }
    void pop(){
        if(!isEmpty()){
            stack.pop_back();
            top_pos--;
            return ;
        }
        throw std::underflow_error("Uderflow.");
    }
    int top(){
        if(!isEmpty()){
            return stack.back();
        }
        throw std::underflow_error("Uderflow.");
    }
    void print(){
        for(auto x =  stack.crbegin() ; x!= stack.crend() ; x++){
            cout<<*x<<" ";
        }
    }
    void printt(){
        for(int x : stack){
            cout<<x<<"  ";
        }
    }

};
