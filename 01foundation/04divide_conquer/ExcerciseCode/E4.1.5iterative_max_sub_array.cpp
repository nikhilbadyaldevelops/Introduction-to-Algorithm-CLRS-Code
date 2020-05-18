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


tuple<int,int,int> max_subarray_(vector<int>&nums){
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
    vector<int>nums;
    high_resolution_clock::time_point startTime,endTime;

    //Input numbers
    input(nums);
    //print(nums);

    //Start the clock
    startTime = high_resolution_clock::now();

    //Call the function
    //auto max_subarray = max_subarray_(nums);
    auto max_subarray = max_subarray__(nums);
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
