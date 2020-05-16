#include<bits/stdc++.h>
using namespace std;
void sum(int *arr1 , int size1 ,int *arr2 ,int *arr3 );

vector<int> sum_(vector<int>& a , vector<int> & b){
    int carry = 0 ;
    vector<int>::reverse_iterator itr1;
    vector<int>::reverse_iterator itr2;
    vector<int>nums(a.size()+1);
    vector<int>::reverse_iterator itr3 = nums.rbegin();
    for(itr1 = a.rbegin() , itr2 = b.rbegin() ; itr1 != a.rend() ; ++itr1,++itr2,++itr3){
        *itr3 = (*itr1 + *itr2 + carry )%2;
        carry =  (*itr1 + *itr2 + carry )/2;
    }
    itr3[0] = carry;
    return nums;
}

int main()
{
    vector<int>a  {1,0,0,1,0};
    vector<int>b {0,1,0,1,1};
    auto c = sum_(a,b);
    for(auto d: c){
        cout<<d<<" ";
    }
    return 0;
}



//Some inputs to check code.
// int arr1[5]  = {1,0,0,1,0};   //  1 0 1 1  0
// int arr2[5] =  {0,1,0,1,1};
// int arr3[6];
// sum(a,5,arr2,arr3);
// for(auto i : arr3)
//     cout<<i<<" ";

// C approach
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
