#include<bits/stdc++.h>
using namespace std;
#include"tree_declare.h"



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
void Tree::delete_node(int value){
    Node *temp = search(value);
    delete_node_(temp);
}
Node * Tree::successor_with_parent_node(){
    return successor_with_parent_node_(root->right->left->left);
}
Node * Tree::successor(){
    return successor_(root->right->left->left);
}
Node * Tree::max_node(){
   return  max_node_(root);
}
Node * Tree::min_node(){
    return min_node_(root);
}
Node * Tree::iterative_search(int value){
    return iterative_search_(root,value);
}
Node* Tree::search(int value){
    return search_(root,value);
}
 void Tree::print_parent(){
     print_parent_(root);
 }
void Tree::in_order_walk(){
     in_order_walk_(root);
}
void Tree::post_order_walk(){
    post_order_walk_(root);
}
void Tree::pre_order_walk(){
    pre_order_walk_(root);
}
void Tree::print(){
    print_(root);
}
void Tree::insert(int info){
    if(root!=  nullptr){
        insert(root , info);
    }else{
        root = create_node(info,nullptr);
    }
}
