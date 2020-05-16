#include<bits/stdc++.h>
using namespace std;

tuple<int,int,int> max_subarray(vector<int>&nums){
    int max_sum = 0 ;
    int low = -1;
    int high= -1;
    int temp_left = 0 ;
    int current_sum = 0 ;
    for(int i = 0 ; i < static_cast<int>(nums.size());++i){
        current_sum += nums[i];
        if(current_sum>max_sum){
            low = temp_left;
            high = i;
            max_sum = current_sum;
        }
        if(current_sum<0){
            current_sum = 0 ;
            temp_left = i+1;
        }
    }
    return make_tuple(max_sum,low,high);
}



//or


tuple<int,int,int> max_subarray__(vector<int>&nums){
    int left = 0 ;
    int right = 0 ;
    int temp_left = 0;
    int current_max = 0 ;
    int max_sum = 0 ;
    for(int i =0 ; i < static_cast<int>(nums.size());++i){
        current_max = max(nums[i],current_max+ nums[i]);
        if(current_max > max_sum){
            max_sum = current_max ;
            right = i;
            left = temp_left;
        }
        if(current_max == nums[i]){
            temp_left = i;
        }
    }
    return make_tuple(max_sum,left,right);
}


int main(){

    vector<int>nums{13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    auto t1 = std::chrono::high_resolution_clock::now();
    auto max_subarray_ = max_subarray__(nums);
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << duration<<" is the time taken.\n";
    cout<<(get<0>(max_subarray_))<<endl;
    cout<<(get<1>(max_subarray_))<<endl;
    cout<<(get<2>(max_subarray_))<<endl;
    cout<<"\nWorking.";
    return 0;
}
