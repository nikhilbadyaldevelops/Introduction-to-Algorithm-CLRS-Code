#include<bits/stdc++.h>
using namespace std;


pair<int,int> second_maxmin(vector<int> & nums , int low , int high){
    if(low == high){
        return {nums[low],nums[low]};
    }
    if(low == high+1){
        if(nums[low]>nums[high]){
            return {nums[low],nums[high]};
        }
    }
    int mid = low + (high-low)/2;
    auto c = second_maxmin(nums, low , mid);
    auto d = second_maxmin(nums,mid+1,high);

    int low_ ,high_;
    if(c.first > d.first){
        high_ = d.first;
    }else{
        high_ = c.first;
    }

    if(c.second < d.second){
        low_ = d.second;
    }else{
        low_ = c.second;
    }
    return {high_,low_};
}
int main(){
    vector<int> vec{1,2,3,4,5,6,7,8};
    //MaxMin m ;
    try{
        auto c = second_maxmin(vec,0,vec.size()-1);
        cout<<c.first<<" is second max element.\n";
        cout<<c.second<<" is second min element.\n";
    }catch(...){
        cout<<"Oh! Fuck.\n";
    }

    cout<<endl<<" Working.";
    return 0;
}
