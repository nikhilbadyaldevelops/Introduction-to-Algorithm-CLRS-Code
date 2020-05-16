#include<bits/stdc++.h>
using namespace std;
#include "list.h"

int main(){
    List l;
    l.insert(34);
    l.insert(4);
    l.insert(68);
    l.insert(48);
    //l.delete_node(34);
//    l.print();
    cout<<l.search(34);
    cout<<endl<<"Working ";
    return 0;
}
