struct Node{
    Node * left ;
    Node * right ;
    Node * parent;
    int info;
    int size ;
};
class Tree{
private:
    Node * root ;
    void insert(Node * node, int info){
        if(info >= node->info){
            if(node->right != nullptr){
                insert(node->right,info);
            }else{
                node->right = create_node(info,node);
            }

        }else{
            if(node->left != nullptr){
                 insert(node->left,info);
            }else{
                node->left = create_node(info,node);
            }
        }
    }
    Node * create_node(int info,Node * parent_node){
        Node * new_node = new Node;
        new_node->info = info;
        new_node->left = nullptr;
        new_node->right = nullptr ;
        new_node->parent = parent_node;
        return new_node;
    }
    void print_(Node * node){
        if(node != nullptr){
            print_(node->left);
            cout<<node->info<<"  ";
            print_(node->right);
        }
    }
    void in_order_walk_(Node * node){
        stack<Node*> node_stack;
        while(node != nullptr || !node_stack.empty()){
            while(node != nullptr){
                node_stack.push(node);
                node = node->left;
            }
            node = node_stack.top();
            cout<<node->info<<"  ";
            node_stack.pop();
            node = node->right;
        }
    }
    void pre_order_walk_(Node *node){
        if(node != nullptr){
            cout<<node->info<<"  ";
            pre_order_walk_(node->left);
            pre_order_walk_(node->right);
        }
    }
    void post_order_walk_(Node * node){
        if(node != nullptr){
            post_order_walk_(node->left);
            post_order_walk_(node->right);
            cout<<node->info<<"  ";
        }
    }
    void  print_parent_(Node * node){
        if(node != nullptr){
            print_parent_(node->left);
            if(node->parent ==  nullptr){
                cout<<"-1   ";
                cout<<node->info<<endl;
            }else{
                cout<<node->parent->info<<"  ";
                cout<<node->info<<endl;
            }
            print_parent_(node->right);
        }
    }
    Node* search_(Node * node , int value){
        if(node == nullptr || node->info == value){
            return node;
        }
        if(node->info > value){
            return search_(node->left,value);
        }else{
            return search_(node->right,value);
        }
    }
    Node* iterative_search_(Node * node , int value){
        Node * temp = node;
        while(temp != nullptr && temp->info != value){
            if(node->info > value){
                temp = temp->left;
            }else{
                temp = temp->right;
            }
        }
        return temp;
    }
    Node * min_node_(Node * node){
        while(node->left != nullptr ){
            node = node->left;
        }
        return node;

    }
    Node * max_node_(Node * node){
        while(node->right != nullptr ){
            node = node->right;
        }
        return node;
    }
    Node  * successor_(Node * node){
        if(node->right != nullptr){
            return min_node_(node->right);
        }
        Node *  succ =  node->parent;
        while(succ != nullptr  && node ==  succ->right){
            node = succ ;
            succ = succ->parent;
        }
        return succ;
    }
    Node * successor_with_parent_node_(Node * node){
        if(node->right != nullptr){
            return min_node_(node->right);
        }
        Node * succ = nullptr;
        while(node != nullptr ){
            if(node->info < root->info){
                succ = root;
                root= root->left;
            }else if(node->info > root->info){
                root = root->right;
            }else{
                break;
            }
        }
        return succ;
    }
    void  delete_node_(Node * node){
        if(node->left == nullptr){
            transplant( node , node->right);
        }else if(node->right == nullptr){
            transplant( node , node->left);
        }else{
            Node* suc = min_node_(node->right);
            if(suc->parent != node){
                transplant(suc , suc->right);
                suc->right = node->right ;
                suc->left = node->left ;
            }
            transplant( node , suc);
            suc->left = node->left ;
            suc->left ->parent =  suc;
        }
    }
    void print_in_shape_(const string& prefix,Node* node, bool isLeft){
        if( node != nullptr )
        {
            std::cout << prefix;
            std::cout << (isLeft ? "├──" : "└──" );
            std::cout << node->info << std::endl;


            print_in_shape_(prefix + (isLeft ? " │   " : "    "), node->left, true);
            print_in_shape_(prefix + (isLeft ?  "│   " : "    "), node->right, false);
        }
    }
public:
    Tree():root(nullptr){}
    bool is_empty(){
        return root==nullptr;
    }
    void insert(int info);
    void print();
    void in_order_walk();
    void pre_order_walk();
    void post_order_walk();
    void print_parent();
    Node * search(int value);
    Node * iterative_search(int value);
    Node * min_node();
    Node * max_node();
    Node * successor();
    Node * successor_with_parent_node();
    void  delete_node(int value);
    void transplant(Node * first , Node * second );
    void print_in_shape(){
        print_in_shape_("", root,false);
    }

};
