class Tree;
class Node{
    friend class Tree;
private:
    int info;
    Node * left;
    Node * right;
    Node * parent;
    int s
public:
    Node():info(0),left(nullptr),right(nullptr){}

};

class Tree{
private:
    Node * nil;
    Node * create_node(int value = -1){
        Node * new_ = new Node;
        new_->info = value;
        new_->left = nullptr;
        new_->right = nullptr;
        new_->parent = nullptr;
        return new_;
    }
    // void insert_(Node * node , Node * new_){
    //     if(node->info >= new_->info){
    //         if(node->left != nil){
    //             insert_(node->left , new_);
    //         }else{
    //             node->left = new_;
    //         }
    //     }else{
    //         if(node->right != nil){
    //             insert_(node->right , new_);
    //         }else{
    //             node->right = new_;
    //         }
    //     }
    //     new_->left = this->nil;
    //     new_->parent = node;
    //     new_->right = this->nil;
    // }
    void insert_(Node *root , Node * new_){
        Node *prev = nil;
        while(root != nil){
            prev = root;
            if(root->info >= new_->info){
                root = root->left;
            }else{
                root = root->right;
            }
        }
        new_->parent = prev;
        if(prev == nil){
            nil->right = new_;
        }else if(prev->info >= new_->info){
            prev->left =  new_;
        }else{
            prev->right = new_;
        }
        new_->right = nil;
        new_->left =  nil;
    }
    void print_(Node *root){
        if(root!= nil){
            print_(root->left);
            cout<<root->info<<"  ";
            print_(root->right);
        }
    }
    void parent_(Node * root){
        if(root != nil){
            parent_(root->left);
            cout<<root->parent->info<<"  ";
            parent_(root->right);
        }
    }

    /*
           x                                y
         /   \                            /   \
        /     y                          /     \
       /    /   \     ----->            x       c
      a    /     \                     / \
          /       \                   /   \
         b        c                  a     b

    */
    void left_rotate(Node * x){
        Node *y = x->right;  //  say y
        x->right = y->left; //
        if(y->left != nil){  // if y is not last internal node
            y->left->parent = x;
        }
        if(x->parent == nil){  // x is root
            nil->right = y;
        }else if(x == x->parent->left){  // x is someone's left child
            x->parent->left = y;
        }else{
            x->parent->right = y;  // x is someone's right child
        }
        y->left = x;
        x->parent = y;
    }


    void right_rotate(Node *y){
        Node *x =  y->left;
        y->left = x->right;
        if(x->right != nil){
            x->right->parent = y;
        }
        if(y->parent == nil){ // if y is root
            nil->right = x;
        }else if(y == y->parent->left){ // y is someone's left child
            y->parent->left = x;
        }else{   // y  is someone's right child
            y->parent->right = x;
        }
        x->right = y;
        y->parent = x;
    }
    Node * search_(Node *root , int key){
        nil->info = key;
        while(root != nil){
            if(root->info == key){
                return root;
            }else if(root->info > key){
                root = root->left;
            }else{
                root = root->right;
            }
        }
        return root;
    }

public:
    Tree(){
        nil = create_node();
        nil->right = nil;
        nil->left = nullptr;
        nil->parent = nullptr;
    }
    void insert(int value){
        // if(nil->right ==  nil){
        //     Node *new_ = create_node(value);
        //     nil->right = new_;
        //     new_->left = this->nil;
        //     new_->right = this->nil;
        //     new_->parent  = this->nil;
        // }else{
        Node * new_ = create_node(value);
        insert_(nil->right,new_);
        //}
    }
    void print(){
        if(nil->right!= nil){
            print_(nil->right);
        }
    }

    void parent(){
        parent_(nil->right);
    }

    bool search(int key){
        if(search_(nil->right,key) != nil){
            return true;
        }
        return false;
    }
    void transplant(Node *u , Node * v){
        if(u->parent == nil){
            nil->right=v;
        }else if(u = u->parent->left){
            u->parent->left = v;
        }else{
            u->parent->right = v;
        }
        if(v != nil){
            v->parent = u->parent;
        }
    }
    void delete_(){

    }
};
