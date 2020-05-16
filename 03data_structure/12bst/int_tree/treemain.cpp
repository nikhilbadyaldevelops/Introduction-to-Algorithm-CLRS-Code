#include<bits/stdc++.h>
#include "tree.h"
using namespace std;


int main(){
    Tree Tree_obj;
    int i = 0 ;   
    while( i < 10){
        int a = rand() % 1000 + i++;
        //cout<<a<<"  ";
        //cout<<endl;
        Tree_obj.insert(a);
    }
    //Tree_obj.print2D();cout<<endl;
  //  Tree_obj.print();cout<<endl;
  //  Tree_obj.in_order_walk();
    Tree_obj.print_in_shape();
    return 0;
}
