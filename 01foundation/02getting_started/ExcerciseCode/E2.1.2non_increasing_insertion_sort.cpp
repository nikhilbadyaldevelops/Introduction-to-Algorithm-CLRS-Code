#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> & nums){
    for(int i = 1 ; i < static_cast<int>(nums.size()); ++i){
        int key = nums[i];
        int j = i -1;
        while(j>= 0 && nums[j]< key){
            nums[j+1] = nums[j];
            --j;
        }
        nums[j+1] = key;
    }
}
int main(){
    vector<int> nums;
    for(int i = 1 ; i <= 20 ; ++i){
        nums.push_back(rand() % 74576);
    }
    insertion_sort(nums);
    for(int x : nums){
        cout<<x<<" ";
    }
    cout<<"\nWorking.";
    return 0 ;
}
