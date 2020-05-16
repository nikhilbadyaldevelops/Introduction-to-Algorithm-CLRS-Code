#include<bits/stdc++.h>
using namespace std;

void selection_sort(vector<int>& nums ){
    for(int i = 0 ; i < static_cast<int>(nums.size()-1) ; ++i){
        int smallest_pos = i ;
        int j = i +1;
        for(; j <  static_cast<int>(nums.size()); ++j){
            if(nums[j] < nums[smallest_pos]){
                smallest_pos = j;
            }
        }
        if(i != smallest_pos){
            iter_swap(nums.begin()+i,nums.begin()+smallest_pos);
        }
    }
}

int main(){
    vector<int> nums{-346,3,66,23,-5,22,-34,57,225,-44};
    selection_sort(nums);
    for(int x : nums){
        cout<<x<<" ";
    }
    cout<<"\nWorking.";
    return 0;
}
