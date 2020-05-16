class List;
class Node{
    friend class List;
private:
    int info;
    Node * next;
public:
    Node():info(0),next(nullptr){}
};

class List{
private:
    Node * head;
    Node * tail;
public:
    List(): head(nullptr), tail(nullptr){}

    Node * new_node(int value){
        Node * temp = new Node;
        temp->info = value ;
        temp->next = nullptr ;
        return temp;
    }

    void insert(int value){
        Node * new_ = new_node(value);
        if(head == nullptr){
            head = new_;
            tail  = new_;
            return ;
        }
        new_->next = head;
        head = new_;
    }

    void insert_(int value){
        Node * new_ = new_node(value);
        if(tail == nullptr){
            tail = new_;
            head = new_;
            return ;
        }
        tail->next = new_;
        tail = new_;
    }

    void print(){
        Node * temp = head;
        while(temp != nullptr ){
            cout<<temp->info<<"  ";
            temp = temp->next;
        }
    }

    Node * search(int value){
        Node * temp = head;
        while(temp != nullptr && temp->info != value){
            temp = temp->next;
        }
        return temp;
    }
    void tail_c(){
        if(tail != nullptr){
            cout<<tail->info<<"  ";
            return ;
        }
        throw std::underflow_error("Underflow T.");

    }
    void delete_(int value){
        if(head != nullptr){
            Node * temp = head ;
            if(temp->info ==  value){
                head = head ->next ;
                tail = nullptr;
                delete temp;
                return ;
            }
            Node * prev;
            while(temp != nullptr && temp->info != value){
                prev = temp;
                temp = temp->next;
            }
            if(temp==nullptr){
                return ;
            }
            prev->next = temp->next;
            if(temp->next == nullptr){
                tail = prev;
            }
            delete temp;
            return ;
        }
        throw std::underflow_error("Underflow D.");
    }
    void delete_(){
        if(head != nullptr){
            Node * temp = head ;
            head = head ->next ;
            delete temp;
            return ;
        }
        throw std::underflow_error("Underflow.");
    }
    int head_(){
        if(head != nullptr){
            return head->info;
        }
        throw std::underflow_error("Underflow.");
    }

};
