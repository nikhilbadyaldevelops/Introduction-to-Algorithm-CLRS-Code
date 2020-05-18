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


tuple<int,int,int> brute_force(vector<int>& nums){
    long long int max_sum = INT_MIN;
    int left = 1 ;
    int right= 1 ;
    long long int current_sum = 0 ;
    for(int i = 0 ; i < static_cast<int>(nums.size()) ; ++i){
        current_sum =0 ;
        for(int j = i ; j < static_cast<int>(nums.size()); ++j){
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

int main(){
    vector<int>nums;
    high_resolution_clock::time_point startTime,endTime;

    //Input numbers
    input(nums);
    //print(nums);

    //Start the clock
    startTime = high_resolution_clock::now();

    //Call the function
    auto max_subarray = brute_force(nums);
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
