#include<bits/stdc++.h>
using namespace std;
#include "set.h"

int main(){
    Set s1;
    Set s2;
    for(int i = 0 , j = 10; i < 5 ; j++, ++i){
        s1.insert(i);
        s2.insert(j);

    }
    s1.union_(s2);
    cout<<endl<<" Working.";
    return 0;
}
