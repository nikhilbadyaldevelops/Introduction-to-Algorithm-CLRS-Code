class Deque{
private:
    int size ;
    int head ;
    int tail;
    vector<int> deque;
public:
    Deque(int size){
        this->size = size+1;
        this->head = 0;
        this->tail = 0;
        this->deque.resize(size+1);
    }
    bool isFull(){
        if(head == tail +1 || (head == 0 && tail == size -1)){
            return true;
        }
        return false;
    }
    bool isEmpty(){
        if(head == tail){
            return true;
        }
        return false;
    }
    bool push_front(int value){
        if(!isFull()){
            if(head == 0 ){
                head = size -1;
            }else{
                head--;
            }
            deque[head]= value;
            return true;
        }
        throw std::overflow_error( "Overflow." );
    }
    bool push_back(int value){
        if(!isFull()){
            deque[tail] = value;
            if(tail == size -1){
                tail = 0 ;
            }else{
                tail++;
            }
            return true;
        }
        throw std::overflow_error( "Overflow." );
    }
    bool pop_front(){
        if(!isEmpty()){
            if(head == size-1){
                head = 0 ;
            }else{
                head++;
            }
            return true;
        }
        throw std::underflow_error( "Underflow." );
    }
    bool pop_back(){
        if(!isEmpty()){
            if(tail == 0){
                tail =  size -1;
            }else{
                tail --;
            }
            return true;
        }
        throw std::underflow_error( "Underflow." );
    }

    void print(){
        if(tail>head){
                for(int i = head ; i < tail ; ++i){
                    cout<<deque[i]<<"  ";
            }
        }else{
            for (int i = head; i < this->size; i++){
                cout<<deque[i]<<"  ";
            }
            for (int i = 0; i < tail; i++){
                cout<<deque[i]<<"  ";
            }
        }
    }
};
