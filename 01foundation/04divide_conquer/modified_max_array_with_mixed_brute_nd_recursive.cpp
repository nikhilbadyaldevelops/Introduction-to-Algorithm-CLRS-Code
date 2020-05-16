#include<bits/stdc++.h>
using namespace std;

tuple<int,int,int> modified_brute_force(vector<int>& nums,int low, int high){
    int max_profit = INT_MIN;
    int day_to_buy = -1;
    int day_to_sell = -1;
    for(int i = low ; i <=high ; ++i){
        for(int j = i ; j<= high; ++j){
            max_profit = max(max_profit,nums[j]-nums[i]);
            if(max_profit == nums[j]-nums[i]){
                day_to_buy=  nums[j];
                day_to_sell = nums[i];
            }
        }
    }
    return make_tuple(max_profit,day_to_buy,day_to_sell);
}

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
tuple<int,int,int> modified_max_sub_array(vector<int>&nums,int low , int high,int size){
    tuple<int,int,int> left_array ;
    tuple<int,int,int> right_array ;
    tuple<int,int,int> crossing_array;
    if(size<4){
        return modified_brute_force(nums,low,high);
    }else{
        int mid = low + (high-low)/2;
        size = mid-low+1;
        left_array = modified_max_sub_array(nums,low,mid,size);
        size = high-mid+1;
        right_array = modified_max_sub_array(nums,mid+1,high,size);
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
    int size = nums.size()-1;
    auto t1 = std::chrono::high_resolution_clock::now();


    auto max_subarray = modified_max_sub_array(nums,0,nums.size()-1,size);

    
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << duration<<" is the time taken.\n";
    cout<<(get<0>(max_subarray))<<endl;
    cout<<(get<1>(max_subarray))<<endl;
    cout<<(get<2>(max_subarray))<<endl;
    cout<<"\nWorking.";
    return 0;
}
