#include<bits/stdc++.h>
using namespace std;

void merge_(vector<int>&nums , int low , int mid , int high){
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

    
    // while(i < size1){
    //     nums[start] = left[i];
    //     start++;
    //     i++;
    // }
    // while(j < size2){
    //     nums[start] = right[j];
    //     start++;
    //     j++;
    // }


    ///OR


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
void merge(vector<int>& nums , int low ,int mid , int high){
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
        merge_(nums,low,mid,high);
        //merge(nums,low,mid,high);
    }
}
int main(){
    vector<int>nums {69,45,23,6,22,88,-33,-145,457,688,566};
    merge_sort(nums,0,nums.size()-1);
    for(int x: nums){
        cout<<x<<" ";
    }
    cout<<"\nWorking.";
    return 0;
}
