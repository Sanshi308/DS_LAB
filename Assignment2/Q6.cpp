6) Write a program to implement the following operations on a Sparse Matrix,
assuming the matrix is represented using a triplet.
(a) Transpose of a matrix.
ans:-
    
#include <iostream>
using namespace std;

#define MAX 50

// Function to compute transpose
void transpose(int A[MAX][3], int B[MAX][3]) {
    int i, j, k = 1;
    B[0][0] = A[0][1]; // rows become cols
    B[0][1] = A[0][0]; // cols become rows
    B[0][2] = A[0][2]; // non-zero count remains same

    for (i = 0; i < A[0][1]; i++) {
        for (j = 1; j <= A[0][2]; j++) {
            if (A[j][1] == i) { // find column i
                B[k][0] = A[j][1];
                B[k][1] = A[j][0];
                B[k][2] = A[j][2];
                k++;
            }
        }
    }
}

// Function to display sparse matrix
void display(int A[MAX][3]) {
    for (int i = 0; i <= A[0][2]; i++) {
        cout << A[i][0] << " " << A[i][1] << " " << A[i][2] << endl;
    }
}

int main() {
    int A[MAX][3] = {
        {4, 4, 4},
        {0, 0, 5},
        {1, 2, 8},
        {2, 3, 10},
        {3, 1, 12}
    };

    int B[MAX][3];

    cout << "Original Matrix (Triplet form):\n";
    display(A);

    transpose(A, B);

    cout << "\nTranspose Matrix (Triplet form):\n";
    display(B);

    return 0;
}





b)Addition of two matrices.
#include <iostream>
using namespace std;

#define MAX 50

// Function to add two sparse matrices
void add(int A[MAX][3], int B[MAX][3], int C[MAX][3]) {
    int i = 1, j = 1, k = 1;
    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    while (i <= A[0][2] && j <= B[0][2]) {
        if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++; k++;
        }
        else if (B[j][0] < A[i][0] || (B[j][0] == A[i][0] && B[j][1] < A[i][1])) {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++; k++;
        }
        else {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2] + B[j][2];
            i++; j++; k++;
        }
    }

    while (i <= A[0][2]) {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++; k++;
    }
    while (j <= B[0][2]) {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++; k++;
    }

    C[0][2] = k - 1;
}

// Function to display sparse matrix
void display(int A[MAX][3]) {
    for (int i = 0; i <= A[0][2]; i++) {
        cout << A[i][0] << " " << A[i][1] << " " << A[i][2] << endl;
    }
}

int main() {
    int A[MAX][3] = {
        {3, 3, 2},
        {0, 0, 5},
        {1, 1, 8}
    };

    int B[MAX][3] = {
        {3, 3, 2},
        {0, 0, 3},
        {2, 2, 6}
    };

    int C[MAX][3];

    cout << "Matrix A:\n";
    display(A);

    cout << "\nMatrix B:\n";
    display(B);

    add(A, B, C);

    cout << "\nResult of A + B:\n";
    display(C);

    return 0;
}




c) Multiplication of two matrices.
#include <iostream>
using namespace std;

#define MAX 50

// Function to multiply two sparse matrices
void multiply(int A[MAX][3], int B[MAX][3], int C[MAX][3]) {
    if (A[0][1] != B[0][0]) {
        cout << "Matrix multiplication not possible!" << endl;
        return;
    }

    int result[MAX][MAX] = {0};

    for (int i = 1; i <= A[0][2]; i++) {
        for (int j = 1; j <= B[0][2]; j++) {
            if (A[i][1] == B[j][0]) {
                result[A[i][0]][B[j][1]] += A[i][2] * B[j][2];
            }
        }
    }

    int k = 1;
    C[0][0] = A[0][0];
    C[0][1] = B[0][1];

    for (int i = 0; i < A[0][0]; i++) {
        for (int j = 0; j < B[0][1]; j++) {
            if (result[i][j] != 0) {
                C[k][0] = i;
                C[k][1] = j;
                C[k][2] = result[i][j];
                k++;
            }
        }
    }
    C[0][2] = k - 1;
}

// Function to display sparse matrix
void display(int A[MAX][3]) {
    for (int i = 0; i <= A[0][2]; i++) {
        cout << A[i][0] << " " << A[i][1] << " " << A[i][2] << endl;
    }
}

int main() {
    int A[MAX][3] = {
        {2, 3, 2},
        {0, 0, 2},
        {1, 2, 3}
    };

    int B[MAX][3] = {
        {3, 2, 2},
        {0, 1, 4},
        {2, 0, 5}
    };

    int C[MAX][3];

    cout << "Matrix A:\n";
    display(A);

    cout << "\nMatrix B:\n";
    display(B);

    multiply(A, B, C);

    cout << "\nResult of A x B:\n";
    display(C);

    return 0;
}


