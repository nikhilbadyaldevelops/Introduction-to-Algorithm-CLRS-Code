//
// Created by nikhi on 5/16/2020.
//
#include<bits/stdc++.h>
using namespace std;

tuple<int,int,int> brute_force(vector<int>& nums){
    int max_profit = INT_MIN;
    int day_to_buy = -1;
    int day_to_sell = -1;
    for(int i = 0 ; i < static_cast<int>(nums.size()) ; ++i){
        for(int j = i ; j < static_cast<int>(nums.size()); ++j){
            max_profit = max(max_profit,nums[j]-nums[i]);
            if(max_profit == nums[j]-nums[i]){
                day_to_buy=  nums[j];
                day_to_sell = nums[i];
            }
        }
    }
    return make_tuple(max_profit,day_to_buy,day_to_sell);
}

int main(){
    vector<int>nums{13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};

    // Added these function to measure run-time of my functions. You can remove these if you want.
    auto t1 = std::chrono::high_resolution_clock::now();

    auto max_subarray = brute_force(nums);  // Main call

    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << duration<<" is the time taken.\n";
    cout<<(get<0>(max_subarray))<<endl;
    cout<<(get<1>(max_subarray))<<endl;
    cout<<(get<2>(max_subarray))<<endl;
    cout<<"\nWorking.";
    return 0;
}



