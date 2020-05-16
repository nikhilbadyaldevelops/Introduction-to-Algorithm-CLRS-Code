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
    vector<int> nums{3,23,36,324,456,25,-67,25,22,23,-3};
    cout<<linear_search(nums,22);
    cout<<"\nWorking.";
    return 0;
}
