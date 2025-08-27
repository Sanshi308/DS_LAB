6) Write a program to implement the following operations on a Sparse Matrix,
assuming the matrix is represented using a triplet.
(a) Transpose of a matrix.
(b) Addition of two matrices.
(c) Multiplication of two matrices.
ans:-
    
#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

int main() {
    // Example: Matrix 3x3 with only few non-zero values
    Element mat[3] = {{0,1,5}, {1,0,8}, {2,2,9}};

    // (a) Transpose
    cout << "Transpose Triplet: ";
    for(int i=0;i<3;i++)
        cout << "("<<mat[i].col<<","<<mat[i].row<<","<<mat[i].val<<") ";
    cout << endl;
    return 0;
}
