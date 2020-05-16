class Queue{
private:
    int size_ ;
    int head ;
    int tail;
    int count;
    vector<int> queue;
public:
    Queue(int size){
        this->size_ = size;
        this->head = 0;
        this->tail = 0;
        this->count = 0;
        this->queue.resize(size);
    }
    int size(){
        return count ;
    }
    bool isFull(){
        if(head == tail +1  || (head == 0 && tail == size_-1)){
            return true;
        }
        return false;
    }
    bool isEmpty(){
        if(this->tail == this->head){
            return true;
        }
        return false;
    }
    void enqueue(int value){
        if(!isFull()){
            queue[tail] = value;
            if(tail ==  size_ -1 ){
                tail =  0 ;
            }else{
                tail++;
            }
            count++;
            return ;
        }
        throw std::overflow_error("Overflow.");
    }

    int front(){
        if(!isEmpty()){
            return queue[head];
        }
        throw std::underflow_error("Underflow.");
    }
    void dequeue(){
        if(!isEmpty()){
            if(head == size_ -1 ){
                head = 0;
            }else{
                head++;
            }
            count--;
            return ;
        }
        throw std::underflow_error("Underflow.");
    }
    void print(){
        if(!isEmpty()){
            if(tail>head){
                for(int i = head ; i < tail ; ++i){
                    cout<<queue[i]<<"  ";
                }
            }else{
                for (int i = head; i < size_; i++){
                    cout<<queue[i]<<"  ";
                }
                for (int i = 0; i < tail; i++){
                    cout<<queue[i]<<"  ";
                }
            }
        }
    }
};
