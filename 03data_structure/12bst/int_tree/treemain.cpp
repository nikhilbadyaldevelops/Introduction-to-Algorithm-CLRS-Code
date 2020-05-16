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
    return 0;
}
