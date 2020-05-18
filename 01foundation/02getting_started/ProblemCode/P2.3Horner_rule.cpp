#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

void input(vector<int> & nums){
    // Random number generator
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<int> dist(3,10);

    for(int i = 1 ; i <= 5 ; ++i){
        nums.push_back(dist(rng));
    }
}
void print(vector<int>& nums){
    for(int x : nums){
        cout<<x<<" ";
    }
    cout<<endl;
}

long  horner_rule(int x , vector<int>& nums){
    int n = nums.size();
    long y = 0 ;
    for(int i = n-1 ; i >= 0 ; --i){
        y = nums[i] +  x*y ;
    }
    return y ;
}

long naive1(int x , vector<int> & nums){
    long y = 0 ;
    int n = nums.size() ;
    for(int i = 0 ; i < n ; ++i){
        int k =1 ;
        for(int j = 0 ; j< i  ; ++j){
            k *= x;
        }
        y += nums[i] * k ;
    }
    return y;
}

long naive2(int x , vector<int>&nums){
    long y = 0 ;
    int k = 1;
    int n = nums.size() ;
    for(int i = 0 ; i < n ;++i){
        y += nums[i] * k;
        k = k*x;
    }
    return y;
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
    cout<<"Value of polynomial  : "<<horner_rule(2,nums)<<endl;
    cout<<"Value of polynomial  : "<<naive1(2,nums)<<endl;
    cout<<"Value of polynomial  : "<<naive2(2,nums)<<endl;

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
