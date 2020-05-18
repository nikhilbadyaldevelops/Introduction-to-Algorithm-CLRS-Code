#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

#define  INSERTION_THRESHOLD 20
#define  SELECTION_THRESHOLD 15

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

bool is_sort(vector<int>&nums){
    int n = nums.size();
    for(int i =1 ; i < n ; ++i){
        if(nums[i]<nums[i-1]){
            return false;
        }
    }
    return true;
}

void selection_sort(vector<int>& nums ){
    for(int i = 0 ; i < static_cast<int>(nums.size()-1) ; ++i){
        int smallest_pos = i ;
        int j = i +1;
        for(; j <  static_cast<int>(nums.size()); ++j){
            if(nums[j] < nums[smallest_pos]){
                smallest_pos = j;
            }
        }
        if(i != smallest_pos){
            iter_swap(nums.begin()+i,nums.begin()+smallest_pos);
        }
    }
}

void insertion_sort(vector<int> & nums){
    for(int i = 1 ; i < static_cast<int>(nums.size()); ++i){
        int key = nums[i];
        int j = i -1;
        while(j>= 0 && nums[j]> key){
            nums[j+1] = nums[j];
            --j;
        }
        nums[j+1] = key;
    }
}


void merge_using_sentinals(vector<int>& nums , int low ,int mid , int high){
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
    left.push_back(INT_MAX);
    right.push_back(INT_MAX);
    int i = 0 ;
    int j = 0;
    for(int start = low ; start <= high ; ++start){
        if(left[i]<right[j]){
            nums[start] = left[i];
            i++;
        }else{
            nums[start] = right[j];
            j++;
        }
    }
}
void merge_sort(vector<int>&nums ,int low, int high){
    if(high>low){
        int mid = low+ (high-low)/2;
        merge_sort(nums,low,mid);
        merge_sort(nums,mid+1,high);
        merge_using_sentinals(nums,low,mid,high);
    }
}

void selection_merge_sort(vector<int>&nums ,int low, int high){
    if(low>=high){
        return ;
    }else if(high-low < SELECTION_THRESHOLD){
        selection_sort(nums);
    }else{
        int mid = low+ (high-low)/2;
        merge_sort(nums,low,mid);
        merge_sort(nums,mid+1,high);
        merge_using_sentinals(nums,low,mid,high);
    }
}

void insertion_merge_sort(vector<int>&nums ,int low, int high){
    if(low>=high){
        return ;
    }else if(high-low < INSERTION_THRESHOLD){
        insertion_sort(nums);
    }else  {
        int mid = low+ (high-low)/2;
        merge_sort(nums,low,mid);
        merge_sort(nums,mid+1,high);
        merge_using_sentinals(nums,low,mid,high);
    }
}


int main(){
    vector<int>nums;
    high_resolution_clock::time_point startTime,endTime;

    //Input numbers
    input(nums);

    //Start the clock
    startTime = high_resolution_clock::now();

    //Call the function
    //merge_sort(nums,0, static_cast<int>(nums.size()-1));
    //insertion_merge_sort(nums,0, static_cast<int>(nums.size()-1));
    //selection_merge_sort(nums,0, static_cast<int>(nums.size()-1));

    //Utility to check if algo worked fine.
    //cout<<(is_sort(nums) ? "Array is sorted.\n" : " Unsorted array.\n");

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
