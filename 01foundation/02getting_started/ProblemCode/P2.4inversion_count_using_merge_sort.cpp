#include<bits/stdc++.h>
using namespace std;

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
    int inversion = 0 ;
    while(i < size1 && j < size2){
        if(left[i]<right[j]){
            nums[start] = left[i];
            start++;
            i++;
        }else{
            // To print position of inverted elements.
            for(int l = i ; l < size1; ++l){
                cout<<"("<<left[l]<<","<<right[j]<<")"<<endl;
            }
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
    for(int i = 1 ; i <= 20 ; ++i){
        nums.push_back((int)rand() % 74576);
    }
    cout<<"Total no. of counts :-"<<inversion_count(nums,0, static_cast<int >(nums.size()-1))<<endl;
    for(int x : nums){
        cout<<x<<" ";
    }
    cout<<"\nWorking.";
    return 0 ;
}

// Some extra inputs to check code.
//vector<int>nums{3,2,1};//{8,4,2,1};//{1, 20, 6, 4, 5 };// {69,45,23,6,22,88,-33,-145,457,688,566};
