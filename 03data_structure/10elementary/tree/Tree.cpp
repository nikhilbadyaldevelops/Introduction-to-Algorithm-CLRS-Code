#include<bits/stdc++.h>
using namespace std;

#define COUNT 10

struct Node{
    Node * left ;
    Node * right ;
    Node * parent;
    int info;
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

    void print(Node * node){
        if(node != nullptr){
            print(node->left);
            cout<<node->info<<"  ";
            print(node->right);
        }
    }
    void in_order_walk(Node * node){
        stack<Node *  > stack;
        while(node != nullptr || !stack.empty()){
            while(node != nullptr){
                stack.push(node);
                node = node->left;
            }
              node = stack.top();
            stack.pop();

            cout<<node->info<<"  ";
            node = node->right;
        }
    }
    void pre_order_walk(Node *node){
        if(node != nullptr){
            cout<<node->info<<"  ";
            pre_order_walk(node->left);
            pre_order_walk(node->right);
        }
    }

    void post_order_walk(Node * node){
        if(node != nullptr){
            post_order_walk(node->left);
            post_order_walk(node->right);
            cout<<node->info<<"  ";
        }
    }

    void print2D(Node * node , int space){
        if (node == NULL)
            return;
        space += COUNT;
        print2D(node->right, space);
        cout<<endl;
        for (int i = COUNT; i < space; i++)
            cout<<" ";
        cout<<node->info<<"\n";
        print2D(node->left, space);
    }

    void  print_parent(Node * node){
        if(node != nullptr){
            print_parent(node->left);
            if(node->parent ==  nullptr){
                cout<<"-1   ";
                cout<<node->info<<endl;
            }else{
                cout<<node->parent->info<<"  ";
                cout<<node->info<<endl;
            }
            print_parent(node->right);
        }
    }

    Node * search(Node * node , int value){
        cnt++;
        if(node == nullptr || node->info == value){
            return node;
        }
        if(node->info > value){
            return search(node->left,value);
        }else{
            return search(node->right,value);
        }
    }

    Node* iterative_search(Node * node , int value){
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
    Node * min_node(Node * node){
        while(node->left != nullptr ){
            node = node->left;
        }
        return node;

    }
    Node * max_node(Node * node){
        while(node->right != nullptr ){
            node = node->right;
        }
        return node;
    }

    Node  * successor(Node * node){
        if(node->right != nullptr){
            return min_node(node->right);
        }
        Node *  succ =  node->parent;
        while(succ != nullptr  && node ==  succ->right){
            node = succ ;
            succ = succ->parent;
        }
        return succ;
    }

    Node * successor_with_parent_node(Node * node){
        if(node->right != nullptr){
            return min_node(node->right);
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

    void  delete_node(Node * node){
        if(node->left == nullptr){
            transplant( node , node->right);
        }else if(node->right == nullptr){
            transplant( node , node->left);
        }else{
            Node* suc = min_node(node->right);
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

public:
    int cnt=  0 ;
    Tree(){
        root = nullptr;
    }

    bool is_empty(){
        return root==nullptr;
    }

    Node* create_node(int info,Node * node );
    void insert(int info);
    void print();
    void pre_order_walk();
    void post_order_walk();
    void print2D();
    void print_parent();
    Node * search(int value);
    Node * iterative_search(int value);
    Node * min_node();
    Node * max_node();
    Node * successor();
    Node * successor_with_parent_node();
    void  delete_node();
    void transplant(Node * first , Node * second );
    void in_order_walk();
};
void Tree::in_order_walk(){
    in_order_walk(root);
}
void Tree::transplant(Node * first , Node * second ){
    if(first->parent  == nullptr){
        root = second;
    }else if(first == first->parent->left){
        first->parent->left = second;
    }else{
        first->parent->right =  first ;
    }
    if(second != nullptr){
        second->parent = first->parent;
    }
}
void Tree::delete_node(){
    delete_node(root);
}
Node * Tree::successor_with_parent_node(){
    return successor_with_parent_node(root->right->left->left);
}
Node * Tree::successor(){
    return successor(root->right->left->left);
}
Node * Tree::max_node(){
   return  max_node(root);
}
Node * Tree::min_node(){
    return min_node(root);
}
Node * Tree::iterative_search(int value){
    return iterative_search(root,value);
}
Node* Tree::search(int value){
    return search(root,value);
}
 void Tree::print_parent(){
     print_parent(root);
 }
void Tree::print2D(){
    print2D(root,0);
}
void Tree::post_order_walk(){
    post_order_walk(root);
}

void Tree::pre_order_walk(){
    pre_order_walk(root);
}
void Tree::print(){
    print(root);
}

Node * Tree::create_node(int info,Node * parent_node){
    Node * new_node = new Node;
    new_node->info = info;
    new_node->left = nullptr;
    new_node->right = nullptr ;
    new_node->parent = parent_node;

    return new_node;
}
void Tree::insert(int info){
    if(root!=  nullptr){
        insert(root , info);
    }else{
        root = create_node(info,nullptr);
    }
}

int main(){
    Tree Tree_obj;
    int i = 0 ;
    while( i < 10){
        int a = rand() % 1000 + i++;
        //cout<<a<<"  ";
        //cout<<endl;
        Tree_obj.insert(a);
    }
    Tree_obj.in_order_walk();
    cout<<endl;
    Tree_obj.print();
    cout<<endl<<" Working ";
    return 0;
}
