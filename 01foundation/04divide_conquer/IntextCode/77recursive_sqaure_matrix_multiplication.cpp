#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<int>>  Matrix;
typedef vector<int>  matrix;

void sum_sub_matrix(Matrix  m1, Matrix m2, Matrix& result, int row, int column);

Matrix recursive_matrix_multiplication(Matrix &matrix1, Matrix &matrix2, int rowA, int columnA , int rowB , int columnB, int size){
    Matrix result(size,matrix(size));
    if(size==1){
        result[0][0] = matrix1[rowA][columnA] * matrix2[rowB][columnB];
    }else{
        int newSize = size / 2;

        //C11
        sum_sub_matrix(
                recursive_matrix_multiplication(matrix1, matrix2, rowA, columnA, rowB, columnB, newSize),
                recursive_matrix_multiplication(matrix1, matrix2, rowA, columnA + newSize, rowB + newSize, columnB, newSize), result,
                0, 0);

        //C12
        sum_sub_matrix(
                recursive_matrix_multiplication(matrix1, matrix2, rowA, columnA, rowB, columnB + newSize, newSize),
                recursive_matrix_multiplication(matrix1, matrix2, rowA, columnA + newSize, rowB + newSize, columnB + newSize, newSize), result,
                0, newSize);

        //C21
        sum_sub_matrix(
                recursive_matrix_multiplication(matrix1, matrix2, rowA + newSize, columnA, rowB, columnB, newSize),
                recursive_matrix_multiplication(matrix1, matrix2, rowA + newSize, columnA + newSize, rowB + newSize, columnB, newSize), result,
                newSize, 0);

        //C22
        sum_sub_matrix(
                recursive_matrix_multiplication(matrix1, matrix2, rowA + newSize, columnA, rowB, columnB + newSize, newSize),
                recursive_matrix_multiplication(matrix1, matrix2, rowA + newSize, columnA + newSize, rowB + newSize, columnB + newSize, newSize), result,
                newSize, newSize);
    }
    return result;
}



void sum_sub_matrix(Matrix  m1, Matrix  m2, Matrix& result, int row, int column) {
    int n = m1.size();
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            result[i+row][j+column] = m1[i][j] + m2[i][j];
        }
    }
}
int main(){
    Matrix matrix1 {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    Matrix matrix2 {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int ra = 0 ;
    int ca = 0;
    int rb = 0;
    int cb = 0;
    int size = static_cast<int>(matrix1.size());
    auto c = recursive_matrix_multiplication(matrix1, matrix2, ra, ca, rb, cb, size);
    for(const auto& x : c){
        for(auto y : x){
            cout<<y<<"  ";
        }
        cout<<"\n";
    }
    cout<<"\nWorking.";
    return 0 ;
}
