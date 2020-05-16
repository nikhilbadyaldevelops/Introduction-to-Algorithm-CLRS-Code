enum color_n {Black, Red};
class RedBlack;
class Node{
    friend class RedBlack;
private:
    int key;
    Node * left;
    Node * right ;
    Node *p;
    color_n color;
    int size ;
public:
    Node():key(0),left(nullptr),right(nullptr),p(nullptr),color(Black),size(0){}

};
class RedBlack{
private:
    Node * nil;

    Node * create_node(int value = -1){
        Node * new_ = new Node;
        new_->key = value;
        new_->left = nullptr;
        new_->right = nullptr;
        new_->p = nullptr;
        new_->color = Black;
        new_->size = 0 ;
        return new_;
    }
    void insert_(Node *root , Node * new_){
        Node *prev = nil;
        while(root != nil){
            root->size +=1;
            prev = root;
            if(root->key >= new_->key){
                root = root->left;
            }else{

                root = root->right;
            }

        }
        new_->p = prev;
        if(prev == nil){
            root->size +=1;
            nil->right = new_;
        }else if(prev->key >= new_->key){
            prev->left =  new_;
        }else{
            prev->right = new_;
        }
        new_->right = nil;
        new_->left =  nil;
        new_->color = Red;
        new_->size = 1;
        color_fix(new_);

    }
    void color_fix(Node * z){
        while(z->p->color == Red && z != nil->right){
            if(z->p == z->p->p->left){  // node's p is left child of its p
                Node* y = z->p->p->right;
                if(y->color == Red){
                    z->p->color = Black;  // Black p , red child
                    y->color = Black;
                    z->p->p->color = Red;
                    z= z->p->p;
                }else{ // zig zag case . z is right child but its p is left child
                    if(z == z->p->right){
                        z = z ->p ;
                        left_rotate(z);
                    }
                    z->p->color = Black;
                    z->p->p->color = Red;
                    right_rotate(z->p->p);
                }
            }else{
                Node* y = z->p->p->left;
                if(y->color == Red){
                    z->p->color = Black;  // Black p , red child
                    y->color = Black;
                    z->p->p->color = Red;
                    z= z->p->p;
                }else{ // zig zag case . z is left child but its p is right child
                    if(z == z->p->left){
                        z = z ->p ;
                        right_rotate(z);
                    }
                    z->p->color = Black;
                    z->p->p->color = Red;
                    left_rotate(z->p->p);
                }
            }
        }
        nil->right->color = Black;
    }
    void print_(Node *root){
        if(root!= nil){
            print_(root->left);
            cout<<root->key<<"  ";
            print_(root->right);
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
            y->left->p = x;
        }
        y->p =  x->p;
        if(x->p == nil){  // x is root
            nil->right = y;
        }else if(x == x->p->left){  // x is someone's left child
            x->p->left = y;
        }else{
            x->p->right = y;  // x is someone's right child
        }
        y->left = x;
        x->p = y;
        y->size = x->size;
        x->size = x->left->size + x->right->size +1;
    }
    void right_rotate(Node *y){
        Node *x =  y->left;
        y->left = x->right;
        if(x->right != nil){
            x->right->p = y;
        }
        x->p = y->p;
        if(y->p == nil){ // if y is root
            nil->right = x;
        }else if(y == y->p->left){ // y is someone's left child
            y->p->left = x;
        }else{   // y  is someone's right child
            y->p->right = x;
        }
        x->right = y;
        y->p = x;
        x->size = y->size;
        y->size = y->left->size + y->right->size +1;
    }
    Node * search_(Node *root , int key){
        while(root != nil){
            if(root->key == key){
                return root;
            }else if(root->key > key){
                root = root->left;
            }else{
                root = root->right;
            }
        }
        return root;
    }
    Node * min_node_(Node * node){
        while(node->left != nil ){
            node = node->left;
        }
        return node;
    }
    void transplant(Node * u , Node * v){
        if(u->p == nil){
            nil->right = v;
        }else if(u == u->p->left){
            u->p->left = v;
        }else{
            u->p->right = v;
        }
        v->p = u->p;
    }
    void delete_node_(Node * z){
        Node * y = z;
        Node * x ;
        color_n y_original_color = y->color;
        if(z->left == nil){
            x = z->right;
            transplant(z,z->right);
        }else if(z->right == nil){
            x = z->left;
            transplant(z,z->left);
        }else{
            y = min_node_(z->right);
            y_original_color = y->color;
            x = y->right;
            if(y->p == z){
                x->p = y;
            }else{
                transplant(y,y->right);
                y->right = z->right;
                y->right->p = y;
            }
            transplant(z,y);
            y->left = z->left ;
            y->left->p = y;
            y->color = z->color;
        }
        if(y_original_color == Black){
            delete_color_fix(x);
        }
    }
    void delete_color_fix(Node *x){
        Node *w ;
        while(x != nil->right && x->color == Black){
            if(x==x->p->left){
                w = x->p->right;
                if(w->color == Red){
                    w->color = Black;
                    x->p->color = Red;
                    left_rotate(x->p);
                    w = x->p->right;
                }
                if(w->left->color == Black && w->right->color == Black){
                    w->color = Red;
                    x = x->p;
                }else{
                    if(w->right->color == Black){
                        w->left->color = Black;
                        w->color = Red;
                        right_rotate(w);
                        w = x->p->right;
                    }
                    w->color = x->p->color;
                    x->p->color = Black;
                    w->right->color = Black;
                    left_rotate(x->p);
                    x = nil->right;
                }
            }else{
                w = x->p->left;
                if(w->color == Red){
                    w->color = Black;
                    x->p->color = Red;
                    right_rotate(x->p);
                    w = x->p->left;
                }
                if(w->left->color == Black && w->right->color == Black){
                    w->color = Red;
                    x = x->p;
                }else{
                    if(w->left->color == Black){
                        w->right->color = Black;
                        w->color = Red;
                        left_rotate(w);
                        w = x->p->left;
                    }
                    w->color = x->p->color;
                    x->p->color = Black;
                    w->left->color = Black;
                    right_rotate(x->p);
                    x = nil->right;
                }
            }
        }
        x->color = Black;
    }

public:
    RedBlack(){
        nil = create_node();
        nil->right = nil;
        nil->left = nullptr;
        nil->p = nullptr;
        nil->color = Black;
        nil->size = 0;
    }
    void print_with_color(Node * root){
        if(root!= nil){
            print_with_color(root->left);
            cout<<root->key;
            if(root->color == Black){
                cout<<" Black ";
            }else{
                cout<<" red ";
            }
            cout<<endl;
            print_with_color(root->right);
        }
    }
    void size__(Node * root){
        if(root != nil){
            size__(root->left);
            cout<<root->key<<"  "<<root->size<<endl;
            size__(root->right);
        }
    }
    void size_(){
         size__(nil->right);
    }
    void visual(){
        print_with_color(nil->right);
    }
    void insert(int value){
        Node * new_ = create_node(value);
        insert_(nil->right,new_);
    }
    void print(){
        if(nil->right!= nil){
            print_(nil->right);
        }
    }
    bool search(int key){
        if(search_(nil->right,key) != nil){
            return true;
        }
        return false;
    }
    void left(){
        left_rotate(nil->right->right);
    }
    bool delete_node(int key){
        Node * node = search_(nil->right,key);
        if(node != nil){
            delete_node_(node);
            return true;
        }
        return false;
    }
    int os_select__(Node * x , int i){
        int r = x->left->size +1;
        if(r== i){
            return r;
        }
        if(r>i){
            return os_select__(x,i);
        }
        return os_select__(x,i-r);
    }

    // return pointer to ith smallest element in the subtree rooted at node.
    int os_select( int i, int subtree_key = 0){
        Node * node ;
        if(subtree_key == 0){
            node = nil->right;
        }else{
            node = search_(nil->right,subtree_key);
        }
        if(node != nil){
            return os_select__(node,i);
        }
        throw "No Subtree rooted at "+subtree_key;
    }


    int os_rank_(Node *x){
        int r= x->left->size +1;
        while(x != nil->right){
            if(x == x->p->right){
                r += x->p->left->size +1;
            }
            x = x->p;
        }
        return r;
    }

    //Return pos of nums in the subtree rooted at num.
    int os_rank(int num){
        Node * node = search_(nil->right, num);
        if(node != nil){
            return os_rank_(node);
        }
        throw ("Element "+ to_string(num)+" not found in the tree.");
    }
};
