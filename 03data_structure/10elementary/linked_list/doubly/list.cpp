#include<bits/stdc++.h>
using namespace std;
#include "list.h"

int main(){
    List l;
    l.insert(23);
    l.insert(33);
    l.insert(34);
    l.insert(67);
    l.delete_node(67);
    l.print();
    cout<<endl<<"Working ";

    return 0;
}
