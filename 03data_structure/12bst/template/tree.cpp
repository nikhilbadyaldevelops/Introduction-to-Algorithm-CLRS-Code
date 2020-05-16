#include<bits/stdc++.h>
using namespace std;
#include "tree.h"

int main(){
    Tree tree;
    int i = 0 ;
    while( i < 10){
        int a = rand() % 768 + i++;
        cout<<a<<"  ";
        //cout<<endl;
        tree.insert(a);
    }
    // tree.print();
    // cout<<endl;
    // cout<<tree.search(41);
    cout<<endl<<"Working.";
    return 0;
}
