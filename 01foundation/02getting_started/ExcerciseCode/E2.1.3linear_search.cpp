#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

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

void input(vector<int> & nums){
    // Random number generator
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<int> dist(-9475,396045);

    for(int i = 1 ; i <= 2000 ; ++i){
        nums.push_back(dist(rng));
    }
}
void print(vector<int>& nums){
    for(int x : nums){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int>nums;
    high_resolution_clock::time_point startTime,endTime;

    //Input numbers
    input(nums);

    //Start the clock
    startTime = high_resolution_clock::now();

    //Call the function
    cout<<((linear_search(nums,218313)!= -1) ? "Element found." : "Not found.");

    //Stop the clock
    endTime = high_resolution_clock::now();

    //Calculate the time taken
    auto duration = duration_cast<nanoseconds>(endTime - startTime).count();


    cout << "Time : " << " nanoseconds." <<std::endl;
    cout << "============================================\n";

    cout<<"\nWorking.";
    return 0 ;
}
