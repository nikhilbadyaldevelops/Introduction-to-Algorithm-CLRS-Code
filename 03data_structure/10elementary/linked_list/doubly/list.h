class List;
class Node{
    friend class List;
private:

    int info;
    Node * next ;
    Node * prev;
public:
    Node(): info(0), next(nullptr), prev(nullptr){}

};

class List{
private:
    Node * head_ptr;

public:
    List():head_ptr(nullptr){}

    Node * new_node(int value){
        Node * new_ = new Node;
        new_->info =  value ;
        new_->next = nullptr;
        new_->prev = nullptr;
        return new_;
    }

    void insert(int value){
        Node * new_node_ = new_node(value);
        new_node_->next = head_ptr;
        if(head_ptr != nullptr){
            head_ptr->prev =  new_node_;
        }
        head_ptr = new_node_;
        new_node_->prev = nullptr;
    }

    void delete_node(int value){
        Node * temp = search(value);
        if(temp!= nullptr){
            if(temp->prev != nullptr){
                temp->prev->next = temp->next;
            }else{
                head_ptr = temp->next;
            }
            if(temp->next != nullptr){
                temp->next->prev = temp->prev ;
            }
            delete temp;
        }
    }

    void print(){
        Node * temp = head_ptr;
        while(temp != nullptr){
            cout<<temp->info<<"  ";
            temp = temp->next;
        }
    }

    Node *search(int value){
        Node * temp = head_ptr;
        while(temp != nullptr && ! (temp->info == value )){
            temp = temp->next;
        }
        return temp;
    }

};
