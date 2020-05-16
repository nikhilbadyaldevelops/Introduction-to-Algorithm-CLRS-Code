#include<bits/stdc++.h>
using namespace std;
#include"list.h"

int main(){  
    List l;
    l.insert(34);
    l.insert(3);
    l.tail_c();
    l.delete_(34);
    l.delete_(3);
    //l.tail_c();
    l.print();
    l.insert(4);
    l.insert(89);
    l.delete_(3);
    l.delete_(89);

    cout<<" Working.";
    return 0;
}
