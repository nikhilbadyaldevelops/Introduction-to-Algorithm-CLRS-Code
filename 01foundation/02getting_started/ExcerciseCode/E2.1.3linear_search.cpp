#include<bits/stdc++.h>
using namespace std;

int linear_search(vector<int>& nums, int key){
    int ret = -1 ;
    for(int i = 0 ; i < static_cast<int>(nums.size()); ++i){
        if(nums[i] == key){
            ret =  i;
            break;
        }
    }
    return ret;
}
int main(){
    vector<int>nums;
    for(int i = 1 ; i <= 20 ; ++i){
        nums.push_back(rand() % 74576);
    }
    cout<<linear_search(nums,22);
    cout<<"\nWorking.";
    return 0;
}
