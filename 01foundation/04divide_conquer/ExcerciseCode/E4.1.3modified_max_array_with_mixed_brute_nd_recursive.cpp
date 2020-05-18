#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;


void input(vector<int> & nums){
    // Random number generator
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<int> dist(-723519,63347);

    for(int i = 1 ; i <= 10000 ; ++i){
        nums.push_back(dist(rng));
    }
}
void print(vector<int>& nums){
    for(int x : nums){
        cout<<x<<" ";
    }
    cout<<endl;
}


tuple<int,int,int> modified_brute_force(vector<int>& nums,int low, int high){
    int max_sum = INT_MIN;
    int left = 1 ;
    int right= 1 ;
    int current_sum = 0 ;
    for(int i = low ; i <= high ; ++i){
        current_sum =0 ;
        for(int j = i ; j <= high; ++j){
            current_sum += nums[j];
            if(current_sum > max_sum ){
                max_sum = current_sum;
                left = i;
                right = j;
            }
        }
    }
    return make_tuple(max_sum,left,right);
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
    vector<int>nums;
    high_resolution_clock::time_point startTime,endTime;

    //Input numbers
    input(nums);
    //print(nums);

    //Start the clock
    startTime = high_resolution_clock::now();

    //Call the function
    auto max_subarray = modified_max_sub_array(nums,0,nums.size()-1,nums.size());
    cout<<"Maximum Profit : "<<(get<0>(max_subarray))<<endl;
    cout<<"Start : "<<(get<1>(max_subarray))<<endl;
    cout<<"End : "<<(get<2>(max_subarray))<<endl;


    //Stop the clock
    endTime = high_resolution_clock::now();

    //Calculate the time taken
    auto duration = duration_cast<nanoseconds>(endTime - startTime).count();

    //Print Sorted array.
    //print(nums);

    cout << "Time : " << duration << " nanoseconds." <<std::endl;
    cout << "============================================\n";

    cout<<"\nWorking.";
    return 0;
}
