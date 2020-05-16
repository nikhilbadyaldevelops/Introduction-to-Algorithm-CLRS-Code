#include<bits/stdc++.h>
using namespace std;
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
    vector<int> nums;
    for(int i = 1 ; i <= 20 ; ++i){
        nums.push_back(rand() % 74576);
    }
    recursive_insertion_sort(nums,static_cast<int>(nums.size()-1));
    for(int x : nums){
        cout<<x<<" ";
    }
    cout<<"\nWorking.";
    return 0 ;
}
