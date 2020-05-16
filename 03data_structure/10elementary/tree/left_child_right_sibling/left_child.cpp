#include<bits/stdc++.h>
using namespace std;

class Tree;
class Node{
    friend class Tree;
private:
    int info;
    Node * left_child;
    Node * right_sibling ;
public:
    Node():info(0),left_child(nullptr),right_sibling(nullptr){}

};
class Tree{
private:
    Node * root;

    void add_sibling(Node * node, int value){
        while(node->right_sibling != nullptr){
            node = node->right_sibling;
        }
        node->right_sibling = new_node(value);
    }
    void insert_(Node * root , int value){
        if(root->left_child != nullptr){
            add_sibling(root->left_child , value);
        }else{
            root->left_child = new_node(value);
        }
    }
public:
    Tree(): root(nullptr){}

    Node * new_node(int value){
        Node * new_ =  new Node;
        new_->info = value;
        new_->left_child =  new_->right_sibling = nullptr;
        return new_;
    }
    void insert(int value){
        if(root == nullptr){
            root = new_node(value);
            return ;
        }else{
            insert_(root , value);
        }
    }
    void print(){
        print_(root);
        cout<<endl;
        print__(root);
    }
    void print_(Node * root)
    {
        if (root == NULL){
            return;
        }
        while (root)
        {
            cout<< root->info<<"  ";
            if (root->left_child)
                print_(root->left_child);
            root = root->right_sibling;
        }
    }
    void print__(Node *root){
        if(root == nullptr){
            return ;
        }else{
            cout<<root->info<<"  ";
            root = root->left_child;
            while(root != nullptr ){
                print__(root);
                root = root->right_sibling;
            }
        }
    }
};
int main(){
    Tree tree;
    tree.insert(3);
    tree.insert(33);
    tree.insert(35);
    tree.insert(34);
    tree.insert(57);
    tree.insert(32);
    tree.print();
    cout<<endl<<" Working. ";
    return 0;
}
