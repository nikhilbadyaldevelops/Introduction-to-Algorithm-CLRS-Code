#include<bits/stdc++.h>
using namespace std;
#include "tree.h"


int main(){
    RedBlack tree;
    int j = 0 ;
    for(int i = 1 ; i <= 20 ; ++i){
        int a = rand() % 9999 + j++;
        cout<<a<<"  ";
        //cout<<endl;
        tree.insert(a);
    }
    cout<<endl;
//    tree.print();
    tree.visual();
    // if(tree.delete_node(6972)){
    //     cout<<" Done deletion.\n";
    // }else{
    //     cout<<" Element not found.\n";
    // }
    //tree.size_();
    cout<<endl<<" Working ";
    return 0;
}
