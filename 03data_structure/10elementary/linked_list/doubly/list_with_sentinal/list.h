class List;
class Node{
    friend class List;
private:
public:

    int info;
    Node * next ;
    Node * prev;

    Node(): info(0), next(nullptr), prev(nullptr){}

};

class List{
private:


public:
    Node * nil;
    List(){
        nil = new_node(INT_MAX);
        nil->next = nil->prev = nil;
    }

    Node * new_node(int value){
        Node * new_ = new Node;
        new_->info =  value ;
        new_->next = nullptr ;
        new_->prev =  nullptr;
        return new_;
    }
    void insert(int value){
        Node * new_node_ = new_node(value);
        new_node_->next = nil->next;
        nil->next->prev = new_node_;
        nil->next = new_node_;
        new_node_->prev = nil;
    }

    Node * search_(int value){
        Node * temp = nil->next;
        nil->info = value;
        // while(temp != nil && temp->info != value){
        //     temp= temp->next;
        // }
        while(temp->info != value){
            temp= temp->next;
        }
        return temp;
    }

    bool search(int value){
        auto c = search_(value);
        if(c != nil){
            return true;
        }else{
            return false;
        }
    }

    void rename(List & l){
        l.nil = nil;
    }
    void print(){
        Node * temp = nil->next ;
        while(temp != nil){
            cout<<temp->info<<"  ";
            temp = temp->next;
        }
        cout<<endl;
    }

    void delete_node(int value){
        Node * temp = search_(value);
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

};
