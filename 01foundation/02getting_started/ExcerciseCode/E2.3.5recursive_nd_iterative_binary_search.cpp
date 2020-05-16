#include<bits/stdc++.h>
using namespace std;

bool binary_search(vector<int>& nums, int key){
    int low = 0 ;
    int high = static_cast<int>(nums.size()-1);
    while(high>=low){
        int mid = low+ (high-low)/2;
        if(nums[mid] == key){
            return true;
        }else if(nums[mid]>key){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return false;
}

bool recursive_binary_search(vector<int>&nums ,int low, int high,int key){
    if(low>high){
        return false;
    }
    int mid = low+ (high-low)/2;
    if(nums[mid] == key){
        return true;
    }else if(nums[mid]>key){
        high = mid-1;
    }else{
        low = mid+1;
    }
    return recursive_binary_search(nums,low,high,key);
}
int main(){
    vector<int> nums{34,56,78,99,134,157,194,457,746,946};
    cout<<recursive_binary_search(nums,0,static_cast<int>(nums.size()-1) , 946);
    cout<<"\n Working.";
    return 0;
}
