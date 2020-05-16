#include<bits/stdc++.h>
using namespace std;


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
        //merge_without_sentinals(nums,low,mid,high);
        merge_using_sentinals(nums,low,mid,high);
    }
}
int main(){
    vector<int>nums;
    for(int i = 1 ; i <= 20 ; ++i){
        nums.push_back(rand() % 74576);
    }
    merge_sort(nums,0, static_cast<int>(nums.size()-1));
    for(int x : nums){
        cout<<x<<" ";
    }
    cout<<"\nWorking.";
    return 0;
}

// Some extra inputs to check code.
//vector<int>nums{3,2,1};//{8,4,2,1};//{1, 20, 6, 4, 5 };// {69,45,23,6,22,88,-33,-145,457,688,566};
//vector<int>nums {69,45,23,6,22,88,-33,-145,457,688,566};
