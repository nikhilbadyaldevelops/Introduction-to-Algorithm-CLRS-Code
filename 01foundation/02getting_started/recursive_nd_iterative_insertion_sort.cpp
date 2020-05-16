#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> & nums){
    for(int i = 1 ; i < static_cast<int>(nums.size()); ++i){
        int key = nums[i];
        int j = i -1;
        while(j>= 0 && nums[j]> key){
            nums[j+1] = nums[j];
            --j;
        }
        nums[j+1] = key;
    }
}

void recursive_insertion_sort(vector<int>& nums, int size){
    if(size == 0){
        return ;
    }
    recursive_insertion_sort(nums,size-1);
    int key = nums[size];
    int j =  size-1;
    while(j>=0 && nums[j]>key){
        nums[j+1] = nums[j];
        --j;
    }
    nums[j+1] = key;
}
int main(){
    vector<int> nums {-3,16,12,39,-45,45,65,79,84,98,-23};
    recursive_insertion_sort(nums,nums.size()-1);
    for(int x : nums){
        cout<<x<<" ";
    }
    cout<<"\nWorking.";
    return 0 ;
}
