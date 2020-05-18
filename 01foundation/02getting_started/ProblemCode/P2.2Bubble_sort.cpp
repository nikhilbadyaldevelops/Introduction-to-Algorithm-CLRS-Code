#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

void input(vector<int> & nums){
    // Random number generator
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<int> dist(-6236316,4363457);

    for(int i = 1 ; i <= 5000 ; ++i){
        nums.push_back(dist(rng));
    }
}
void print(vector<int>& nums){
    for(int x : nums){
        cout<<x<<" ";
    }
    cout<<endl;
}


bool is_sort(vector<int>&nums){
    int n = nums.size();
    for(int i =1 ; i < n ; ++i){
        if(nums[i]<nums[i-1]){
            return false;
        }
    }
    return true;
}
int bubble_sort(vector<int>& nums){
    int size = static_cast<int>(nums.size());
    int pass = 0 ;
    int i , j ;
    for(i = 0; i< size; i++) {
       for(j = i+1; j< size; j++){
          if(nums[j] < nums[i]) {
             int temp = nums[i];
             nums[i] = nums[j];
             nums[j] = temp;
          }
       }
        pass++;
    }
    return pass;
}
int main (){
    vector<int>nums;
    high_resolution_clock::time_point startTime,endTime;

    //Input numbers
    input(nums);

    //Start the clock
    startTime = high_resolution_clock::now();

    //Call the function
    cout<<"No. of passes are : "<<bubble_sort(nums)<<endl;
    //Utility to check if algo worked fine.
    //cout<<(is_sort(nums) ? "Array is sorted.\n" : " Unsorted array.\n");

    //Stop the clock
    endTime = high_resolution_clock::now();

    //Calculate the time taken
    auto duration = duration_cast<nanoseconds>(endTime - startTime).count();

    //Print Sorted array.
    print(nums);

    cout << "Time : " << duration << " nanoseconds." <<std::endl;
    cout << "============================================\n";

    cout<<"\nWorking.";
    return 0 ;

}
