#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> square_multiply(vector<vector<int>>&matrix1 , vector<vector<int>>& matrix2){
    vector<vector<int>> resulting_matrix(matrix1.size(), vector<int>(matrix1.size()));
    int n = matrix1.size();
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ;++j){
            for(int k = 0 ; k < n  ; ++k){
                resulting_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return resulting_matrix;
}
int main(){
    vector<vector<int>>matrix1 {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>>matrix2 {{10,11,12},{13,14,15},{16,17,18}};
    auto c = square_multiply(matrix1,matrix2);
    for(const auto& x : c){
        for(auto y : x){
            cout<<y<<"  ";
        }
        cout<<"\n";
    }
    cout<<"\nWorking.";
    return 0 ;
}
