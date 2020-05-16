#include<bits/stdc++.h>
using namespace std;

//Inefficient Solution
int rod_cut(vector<int>price_chart , int size){

    if(size==0){
        return 0 ;
    }
    int revenue = INT_MIN;
    for(int i = 0 ; i < size ; ++i){
        revenue = max(revenue, (price_chart[i]+ rod_cut(price_chart,size-i-1)));
    }
    return revenue;
}
int main(){
    vector<int> price_chart {1,5,8,9,10,17,17,20,24,30};
    cout<<rod_cut(price_chart,10);
    cout<<"\nWorking.";
    return 0;
}
