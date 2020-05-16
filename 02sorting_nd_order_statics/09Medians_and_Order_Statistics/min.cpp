#include<bits/stdc++.h>
using namespace std;


int min(vector<int> & vec){
    int min = vec[0];
    int size = vec.size();
    for(int i = 1; i < size ; ++i){
        if(vec[i] < min){
            min = vec[i];
        }
    }
    return min ;
}

pair<int,int>  max_min(vector<int> & vec){
    int min , max ;
    int size = vec.size();
    int i ;
    if(!(size%2)){
        if(vec[0]>vec[1]){
            max = vec[0];
            min = vec[1];
        }else{
            max = vec[1];
            min = vec[0];
        }
        i = 2;
    }else{
        min = max = vec[0];
        i = 1;
    }
    int l;
    int s ;
    for( ; i< size ; i = i+2){
        if(vec[i]>vec[i+1]){
            l = vec[i];
            s = vec[i+1];
        }else{
            l = vec[i+1];
            s = vec[i];
        }
        if(l> max){
            max = l;
        }
        if(s<min){
            min = s;
        }
    }
    return {min,max};
}


pair<int ,int> maxmin_(vector<int> & nums , int low , int high){
    if(low == high){
        return {nums[low],nums[high]};
    }
    if(low == high +1){
        if(nums[low]>nums[high]){
            return {nums[low],nums[high]};
        }else{
            return {nums[high],nums[low]};
        }
    }
    int mid = low + (high-low)/2;
    auto c = maxmin_(nums, low , mid);
    auto d = maxmin_(nums,mid+1,high);

    int low_ ,high_;
    if(c.first > d.first){
        high_ = c.first;
    }else{
        high_ = d.first;
    }

    if(c.second < d.second){
        low_ = c.second;
    }else{
        low_ = d.second;
    }
    return {high_,low_};
}
int main(){
    vector<int> vec {598079,-6782,5454667,33,6,-67867546,-48,53,-3,34,6,85,948,3,223,-66};
//    vector<int> vec{1,2,3,4,5,6,7,8};
//    cout<<min(vec)<<" is the min element.";
    auto c = max_min(vec);
    cout<<c.first<<" is the min element.\n";
    cout<<c.second<<" is the max element.\n";
    auto d = maxmin_(vec,0,vec.size()-1);
    cout<<d.first<<" is the max element.\n";
    cout<<d.second<<" is the min element.";
    cout<<endl<<" Working.";
    return 0;
}
