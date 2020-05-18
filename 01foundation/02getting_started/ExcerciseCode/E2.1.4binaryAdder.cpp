#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

//void sum(int *arr1 , int size1 ,int *arr2 ,int *arr3 );

vector<int> sum_(vector<int>& a , vector<int> & b){
    int carry = 0 ;
    vector<int>::reverse_iterator itr1;
    vector<int>::reverse_iterator itr2;
    vector<int>nums(a.size()+1);
    auto itr3 = nums.rbegin();
    for(itr1 = a.rbegin() , itr2 = b.rbegin() ; itr1 != a.rend() ; ++itr1,++itr2,++itr3){
        *itr3 = (*itr1 + *itr2 + carry )%2;
        carry =  (*itr1 + *itr2 + carry )/2;
    }
    itr3[0] = carry;
    return nums;
}

//Another way 

vector<int> sum__(vector<int>& a , vector<int> & b){
    int carry = 0 ;
    int size = a.size();
    vector<int>nums(size+1);
    auto itr3 = nums.rbegin();
    for(int i =0  ; i < size ; ++i ){
        carry = a[i] ^ b[i] ^ carry;
        nums[i] = (a[i] & b[i])  ^ (a[i] & carry) ^ (b[i] & carry);
    }
    return nums;
}

void input(vector<int> & nums){
    // Random number generator
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<int> dist(0,1);

    for(int i = 1 ; i <= 200000 ; ++i){
        nums.push_back(dist(rng));
    }
}
void print(vector<int>& nums){
    for(int x : nums){
        cout<<x<<" ";
    }
    cout<<endl;
}

void print_dash(int size){
    for(int i =0 ; i < 2*size+2 ; ++i){
        cout << "-";
    }
    cout<<endl;
}

int main(){
    vector<int>bool_array1;
    vector<int>bool_array2;
    high_resolution_clock::time_point startTime,endTime;

    //Input numbers
    input(bool_array1);
    input(bool_array2);

    //Start the clock
    startTime = high_resolution_clock::now();

    //Call the function
    auto c = sum_(bool_array1,bool_array2);
    auto d = sum__(bool_array1,bool_array2);

    //Stop the clock
    endTime = high_resolution_clock::now();

    //Calculate the time taken
    auto duration = duration_cast<nanoseconds>(endTime - startTime).count();


    //Print the result
    // cout<<"  ";
    // print(bool_array1);
    // cout<<"  ";
    // print(bool_array2);
    // print_dash(bool_array2.size());
    // print(c);
    //
    // cout<<"     2nd solution.\n";;
    // cout<<"  ";
    // print(bool_array1);
    // cout<<"  ";
    // print(bool_array2);
    // print_dash(bool_array2.size());
    // print(d);


    // To check if both solution give same result.
    cout<<((c==d) ? "Both algo are correct." : "One is wrong.");

    //Print Time
    cout << "\nTime taken: " << duration<< " nanoseconds." <<std::endl;
    cout << "============================================\n";

    cout<<"\nWorking.";
    return 0 ;
}



//Some inputs to check code.
// int arr1[5]  = {1,0,0,1,0};   //  1 0 1 1  0
// int arr2[5] =  {0,1,0,1,1};
// int arr3[6];
// sum(a,5,arr2,arr3);
// for(auto i : arr3)
//     cout<<i<<" ";

// C approach
/*
void sum(int *arr1 , int size1 ,int *arr2 ,int *arr3 )
{
    int carry = 0;
    int i ;
    for(i = (size1-1) ; i >=  0;--i)
    {
        arr3[i+1] = (carry + arr2[i] + arr1[i])%2;
        carry = (carry + arr2[i] + arr1[i])/2;

    }
    arr3[i+1] = carry;
}
*/
