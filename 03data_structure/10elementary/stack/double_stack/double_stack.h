class DoubleStack{
private:
    int size ;
    vector<int> dbstack;
    int top1;
    int top2;
public:
    DoubleStack(int size){
        this->size = size-1;
        this->top1 = -1;
        this->top2 = size;
        this->dbstack.resize(size);
    }
    bool push(int which , int value){
        if(which ==1 ){
            if(top1 +1 == top2){
                return false;
            }else{
                dbstack[++top1];
                return true;
            }
        }else if(which ==2 ){
            if(top2 -1 == top1){
                return false;
            }else{
                dbstack[--top2];
                return true;
            }
        }else{
            throw std::invalid_argument( "Illegeal argument." );
        }
        throw std::invalid_argument( "Illegeal argument." );
    }

    bool pop(int which){
        if(which ==1 ){
            if(top1 == -1){
                return false;
            }else{
                top1--;
                return true;
            }
        }else if(which ==2 ){
            if(top2 == size){
                return false;
            }else{
                top2++;
                return true;
            }
        }else{
            throw std::invalid_argument( "Illegeal argument." );
        }
        throw std::invalid_argument( "Illegeal argument." );
    }

    int peek(int which){
        if(which == 1){
            if(top1 == -1){
                return false;
            }else{
                return dbstack[top1];
            }
        }else{
            if(top2 == size){
                return false;
            }else{
                return dbstack[top2];
            }
        }
        throw std::invalid_argument( "Illegeal argument." );
    }

    void print(int first = -1 , int second = -1){
        if(first != -1){

        }
        if(second != -1){

        }
    }
};
