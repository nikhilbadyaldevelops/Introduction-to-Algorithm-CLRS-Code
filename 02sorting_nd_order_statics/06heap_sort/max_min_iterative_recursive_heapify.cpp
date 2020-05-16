#include<bits/stdc++.h>
using namespace std;

//O(n lg n ) algo. In sort algo

int parent(int pos){
    if(pos%2){
        pos++;
    }
    //return pos/2;
    return pos>>1;    // Bitwise operator
}

int left(int pos){
    pos += 1;
    return ((pos<<1)-1);
    //return 2*pos-1;
}

int right(int pos){
    pos += 1;
    return (pos<<1);
    //return 2*pos;
}


void max_heapify(vector<int> & nums , int pos ){
    int left_ = left(pos);
    int right_ = right(pos);
    int largest = pos;
    if(left_ < static_cast<int>(nums.size()) && nums[left_] > nums[pos]){
        largest = left_;
    }
    if(right_ < static_cast<int>(nums.size()) && nums[right_] > nums[largest]){
        largest = right_;
    }
    if(largest != pos ){
        iter_swap(nums.begin() + pos , nums.begin() + largest);
        max_heapify(nums,largest);
    }
}

void max_heapify_iterative(vector<int> & nums , int pos){
    while(true){
        int left_ = left(pos);
        int right_ = right(pos);
        int largest = pos;
        if(left_ < static_cast<int>(nums.size()) && nums[left_] > nums[pos]){
            largest = left_;
        }
        if(right_ < static_cast<int>(nums.size()) && nums[right_] > nums[largest]){
            largest = right_;
        }
        if(largest == pos ){
            return ;
        }
        iter_swap(nums.begin() + pos , nums.begin() + largest);
        pos = largest;
    }
}
void min_heapify(vector<int> & nums , int pos){
    int left_ = left(pos);
    int right_ = right(pos);
    int smallest = pos;
    if(left_< static_cast<int>(nums.size()) && nums[left_]< nums[smallest]){
        smallest = left_;
    }
    if(right_ < static_cast<int>(nums.size()) && nums[right_] > nums[smallest]){
        smallest = right_;
    }
    if(smallest != pos){
        iter_swap(nums.begin() + pos, nums.begin() + smallest);
        min_heapify(nums,smallest);
    }
}
void build_max_heap(vector<int>& nums){
    int size = static_cast<int>(nums.size());
    for(int i = size/2 ; i >= 0 ; --i){
        max_heapify(nums,i);
    }
}
int main(){
    vector<int> vec{27,17,3,16,13,10,1,5,7,12,4,8,9,0};
    max_heapify_iterative(vec,2);
    for(int x : vec){
        cout<<x<<"  ";
    }
    cout<<"\nWorkign";
    return 0;
}
//Some more functions to check code.
//heap_sort(vec,1);
//max_heapify(vec,2);
//cout<<left(3);
//cout<<right(3);
//cout<<parent(5);

// vector<int>vec;
// for(int i = 0 ; i < 10 ; ++i){
//     vec.push_back();
// }
//vector<int> vec{16,4,10,14,7,9,3,2,8,1};
