#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

void merge_without_sentinals(vector<int>&nums , int low , int mid , int high){
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
    while(i < size1 && j < size2){
        if(left[i]<right[j]){
            nums[start] = left[i];
            start++;
            i++;
        }else{
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
}


void merge_sort(vector<int>&nums ,int low, int high){
    if(high>low){
        int mid = low+ (high-low)/2;
        merge_sort(nums,low,mid);
        merge_sort(nums,mid+1,high);
        merge_without_sentinals(nums,low,mid,high);
    }
}

int binary_search(vector<int>& nums, int key){
    int low = 0 ;
    int high = static_cast<int>(nums.size()-1);
    while(high>=low){
        int mid = low+ (high-low)/2;
        if(nums[mid] == key){
            return mid;
        }else if(nums[mid]>key){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return -1;
}

int recursive_binary_search(vector<int>&nums ,int low, int high,int key){
    if(low>high){
        return -1;
    }
    int mid = low+ (high-low)/2;
    if(nums[mid] == key){
        return mid;
    }else if(nums[mid]>key){
        high = mid-1;
    }else{
        low = mid+1;
    }
    return recursive_binary_search(nums,low,high,key);
}

void input(vector<int> & nums){
    // Random number generator
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<int> dist(-9475,396045);

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

int main(){
    vector<int>nums;
    high_resolution_clock::time_point startTime,endTime;

    //Input numbers
    input(nums);

    //Sorting the number
    merge_sort(nums,0, static_cast<int>(nums.size()-1));

    //Start the clock
    startTime = high_resolution_clock::now();

    //Call the function
    cout<<((recursive_binary_search(nums,0,static_cast<int>(nums.size()-1),159746)!= -1) ? "Element found." : "Not found.");
    // binary_search(nums,946)) ? "Element found." : "Not found.");


    //Stop the clock
    endTime = high_resolution_clock::now();

    //Calculate the time taken
    auto duration = duration_cast<nanoseconds>(endTime - startTime).count();


    cout << "Time : " << duration << " nanoseconds." <<std::endl;
    cout << "============================================\n";

    cout<<"\nWorking.";
    return 0 ;
}
