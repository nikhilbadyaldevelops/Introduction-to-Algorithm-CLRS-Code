#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;


void input(vector<int> & nums){
    // Random number generator
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<int> dist(-7576,533626);

    for(int i = 1 ; i <= 20000 ; ++i){
        nums.push_back(dist(rng));
    }
}
void print(vector<int>& nums){
    for(int x : nums){
        cout<<x<<" ";
    }
    cout<<endl;
}


int merge(vector<int>&nums , int low , int mid , int high){
    int size1 = mid - low +1;
    int size2= high - mid;
    vector<int>left;
    vector<int>right;
    for(int i = 0  ; i < size1 ; ++i){
        left.push_back(nums[low+i]);
    }
    for(int i = 0 ; i <size2 ; ++i){
        right.push_back(nums[mid+i+1]);
    }
    int i = 0 ;
    int j = 0;
    int start  = low;
    long long int inversion = 0 ;
    while(i < size1 && j < size2){
        if(left[i]<right[j]){
            nums[start] = left[i];
            start++;
            i++;
        }else{
            // To print position of inverted elements.
            // for(int l = i ; l < size1; ++l){
            //     cout<<"("<<left[l]<<","<<right[j]<<")"<<endl;
            // }
            inversion += size1 - i;
            nums[start] = right[j];
            start++;
            j++;
        }
    }

    if(i == size1){
        for(int c = j ; c< size2 ; ++c){
            nums[start] = right[c];
            start++;
        }
    }
    if(j == size2){
        for(int c =  i ; c< size1 ; ++c){
            nums[start] = left[c];
            start++;
        }
    }
    return inversion;
}
int inversion_count(vector<int>& nums , int low , int high){
    if(high>low){
        int mid = low + (high-low)/2;
        int left = inversion_count(nums,low,mid);
        int right = inversion_count(nums,mid+1,high);
        int inversion = merge(nums,low,mid,high) + left + right;
        return inversion;
    }
    return 0 ;
}
int main(){
    vector<int>nums;
    high_resolution_clock::time_point startTime,endTime;

    //Input numbers
    input(nums);

    //Start the clock
    startTime = high_resolution_clock::now();

    //Call the function
    cout<<"Total no. of counts : "<<inversion_count(nums,0, static_cast<int >(nums.size()-1))<<endl;

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
