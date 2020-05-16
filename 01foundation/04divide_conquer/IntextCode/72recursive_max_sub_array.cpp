#include<bits/stdc++.h>
using namespace std;


tuple<int,int,int> max_sub_array_crossing_mid(vector<int>& nums,int low, int mid , int high){
    int left_sum = INT_MIN;
    int right_sum = INT_MIN;
    int sum = 0 ;
    int max_left ;
    int max_right ;
    for(int i = mid ;i >= low ; --i ){
        sum += nums[i];
        if(sum > left_sum){
            left_sum = sum;
            max_left = i ;
        }
    }
    sum = 0 ;
    for(int i = mid+1 ; i <= high; ++i){
        sum += nums[i];
        if(sum > right_sum){
            right_sum = sum;
            max_right = i;
        }
    }
    return make_tuple(left_sum + right_sum , max_left , max_right);

}
tuple<int,int,int> max_sub_array(vector<int>&nums,int low , int high){
    tuple<int,int,int> left_array ;
    tuple<int,int,int> right_array ;
    tuple<int,int,int> crossing_array;
    if(low == high){
        return make_tuple(nums[low],low,high);
    }else{
        int mid = low + (high-low)/2;
        left_array = max_sub_array(nums,low,mid);
        right_array = max_sub_array(nums,mid+1,high);
        crossing_array = max_sub_array_crossing_mid(nums,low,mid,high);
    }
    if((get<0>(left_array) > get<0>(right_array)) && (get<0>(left_array) > get<0>(crossing_array))){
        return left_array;
    }else if((get<0>(right_array) > get<0>(left_array)) && (get<0>(right_array) > get<0>(crossing_array))){
        return right_array;
    }
    return crossing_array;
}

int main(){
    vector<int>nums{13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};

    // Added these function to measure run-time of my functions. You can remove these if you want.
    auto t1 = std::chrono::high_resolution_clock::now();

    auto max_subarray = max_sub_array(nums,0,nums.size()-1);  // Main call
    
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << duration<<" is the time taken.\n";
    cout<<(get<0>(max_subarray))<<endl;
    cout<<(get<1>(max_subarray))<<endl;
    cout<<(get<2>(max_subarray))<<endl;
    cout<<"\nWorking.";
    return 0;
}

//Some more inputs to check code
//vector<int>nums{100,113,110,85,105,102,86,63,81,101,94,106,101,79,94,90,97};
// int mid = 0 + (nums.size()-1)/2;
// auto c = max_sub_array_crossing_mid(nums,0,mid,nums.size()-1);
//vector<int>nums{-3,-5,-35,-678,-35,-245};
