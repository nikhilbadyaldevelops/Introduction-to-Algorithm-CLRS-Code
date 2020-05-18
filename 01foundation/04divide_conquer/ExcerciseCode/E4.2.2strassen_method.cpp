#include<bits/stdc++.h>
using namespace std;


typedef vector<vector<int>>  Matrix;
typedef vector<int>  matrix;

void sub(Matrix& vector1, Matrix& vector2, Matrix& vector3, int size) {
    for(int i =0  ; i < size ; ++i){
        for(int j = 0 ; j < size ; ++j){
            vector3[i][j] = vector1[i][j] - vector2[i][j];
        }
    }
}

void add(Matrix& vector1, Matrix& vector2, Matrix& vector3, int size) {
    for(int i =0  ; i < size ; ++i){
        for(int j = 0 ; j < size ; ++j){
            vector3[i][j] = vector1[i][j] + vector2[i][j];
        }
    }
}


void strassen(Matrix &A, Matrix &B, Matrix &C , int size){
    if(size == 1){
        C[0][0] = A[0][0] * B[0][0];
        return ;
    }else{
        int newSize = size / 2;
        Matrix  a11(newSize, matrix(newSize)),
                a12(newSize, matrix(newSize)),
                a21(newSize, matrix(newSize)),
                a22(newSize, matrix(newSize)),
                b11(newSize, matrix(newSize)),
                b12(newSize, matrix(newSize)),
                b21(newSize, matrix(newSize)),
                b22(newSize, matrix(newSize)),
                c11(newSize, matrix(newSize)),
                c12(newSize, matrix(newSize)),
                c21(newSize, matrix(newSize)),
                c22(newSize, matrix(newSize)),
                s1(newSize, matrix(newSize)),
                s2(newSize, matrix(newSize)),
                s3(newSize, matrix(newSize)),
                s4(newSize, matrix(newSize)),
                s5(newSize, matrix(newSize)),
                s6(newSize, matrix(newSize)),
                s7(newSize, matrix(newSize)),
                s8(newSize, matrix(newSize)),
                s9(newSize, matrix(newSize)),
                s10(newSize, matrix(newSize)),
                p1(newSize, matrix(newSize)),
                p2(newSize, matrix(newSize)),
                p3(newSize, matrix(newSize)),
                p4(newSize, matrix(newSize)),
                p5(newSize, matrix(newSize)),
                p6(newSize, matrix(newSize)),
                p7(newSize, matrix(newSize)),
                temp1(newSize, matrix(newSize)),
                temp2(newSize, matrix(newSize));

        //Dividing matrix into 4 n/2 matrix
        for(int i = 0 ; i < newSize ; ++i){
            for(int j = 0 ; j < newSize ; ++j){
                a11[i][j] = A[i][j];
                a12[i][j] = A[i][j + newSize];
                a21[i][j] = A[i + newSize][j];
                a22[i][j] = A[i + newSize][j + newSize];

                b11[i][j] = B[i][j];
                b12[i][j] = B[i][j + newSize];
                b21[i][j] = B[i + newSize][j];
                b22[i][j] = B[i + newSize][j + newSize];
            }
        }


        //s1 = b12 - b22
        sub(b12, b22, s1, newSize);
        //s2 = a11 - a12
        add(a11, a12, s2, newSize);
        //s3 = a21- a22
        add(a21, a22, s3, newSize);
        // s4 = b21 - b11
        sub(b21, b11, s4, newSize);
        //s5 = a11 - a22
        add(a11, a22, s5, newSize);
        //s6 = b11 - b22
        add(b11, b22, s6, newSize);
        //s7 = a12 - a22
        sub(a12, a22, s7, newSize);
        //s8 = b21 - b22
        add(b21, b22, s8, newSize);
        //s9 = a11 - a21
        sub(a11, a21, s9, newSize);
        // s10 = b11 - b12
        add(b11, b12, s10, newSize);



        //Recursive calls

        //p1 = a11 * s1
        strassen(a11, s1, p1, newSize);
        //p2 = s2 * b22
        strassen(s2, b22, p2, newSize);
        //p3 = s3 * b11
        strassen(s3, b11, p3, newSize);
        //p4 = a22* s4
        strassen(a22, s4, p4, newSize);
        //p5 = s5 * s6
        strassen(s5, s6, p5, newSize);
        //p6 = s7 * s8
        strassen(s7, s8, p6, newSize);
        //p7 = s9 * s10
        strassen(s9, s10, p7, newSize);


        // C's calculations

        //c11 = p5 + p4 -p2 + p6
        add(p5, p4, temp1, newSize);
        sub(temp1, p2, temp2, newSize);
        add(temp2, p6, c11, newSize);

        //c12 = p1 + p2
        add(p1, p2, c12, newSize);
        //c21 = p3 + p4
        add(p3, p4, c21, newSize);
        //c22 = p5 + p1 - p3 - p7
        add(p5, p1, temp1, newSize);
        sub(temp1, p3, temp2, newSize);
        sub(temp2, p7, c22, newSize);


        //Copying C's in their proper position.
        for(int i = 0 ; i < newSize ; ++i){
            for(int j = 0 ; j < newSize ; ++j){
                C[i][j] = c11[i][j];
                C[i][j + newSize] = c12[i][j];
                C[i + newSize][j] = c21[i][j];
                C[i + newSize][j + newSize] = c22[i][j];
            }
        }

        //printing s values
        if (newSize == 2) {
            cout << endl;
            cout << "S1: " << s1[0][0] << endl;
            cout << "S2: " << s2[0][0] << endl;
            cout << "S3: " << s3[0][0] << endl;
            cout << "S4: " << s4[0][0] << endl;
            cout << "S5: " << s5[0][0] << endl;
            cout << "S6: " << s6[0][0] << endl;
            cout << "S7: " << s7[0][0] << endl;
            cout << "S8: " << s8[0][0] << endl;
            cout << "S9: " << s9[0][0] << endl;
            cout << "S10: " << s10[0][0] << endl;
        }

    }
}
int main(){
    // Matrix matrix1 {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    // Matrix matrix2 {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    Matrix matrix1 {{1,3},{7,5}};
    Matrix matrix2 {{6,8},{4,2}};
    int size = static_cast<int>(matrix1.size());
    Matrix matrix3(size,matrix(size));
    strassen(matrix1, matrix2, matrix3, size);
    for(const auto& x : matrix3){
        for(auto y : x){
            cout<<y<<"  ";
        }
        cout<<"\n";
    }
    cout<<"\nWorking.";
    return 0 ;
}
