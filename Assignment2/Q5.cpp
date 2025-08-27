Space required to store any two-dimensional array is 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ 𝑟𝑜𝑤𝑠 × 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ
𝑐𝑜𝑙𝑢𝑚𝑛𝑠. Assuming an array is used to store elements of the following matrices,
implement an efficient way that reduces the space requirement:
    
(a) Diagonal Matrix.
#include <iostream>
using namespace std;

class Diagonal {
    int n;      // size of matrix
    int *arr;   // to store diagonal elements
public:
    Diagonal(int n) {
        this->n = n;
        arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = 0;
    }

    void set(int i, int j, int x) {
        if (i == j) arr[i] = x;   // store only diagonal elements
    }

    int get(int i, int j) {
        if (i == j) return arr[i];
        else return 0;
    }

    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Diagonal d(4);
    d.set(0,0,5);
    d.set(1,1,8);
    d.set(2,2,3);
    d.set(3,3,6);

    cout << "Diagonal Matrix:\n";
    d.display();
    return 0;
}



b) (b) Tri-diagonal Matrix.
#include <iostream>
using namespace std;

class TriDiagonal {
    int n;
    int *arr;  // store 3n-2 elements
public:
    TriDiagonal(int n) {
        this->n = n;
        arr = new int[3*n - 2];
        for (int i = 0; i < 3*n-2; i++) arr[i] = 0;
    }

    void set(int i, int j, int x) {
        if (i - j == 1) arr[i-1] = x;         // lower diagonal
        else if (i == j) arr[n-1 + i] = x;    // main diagonal
        else if (j - i == 1) arr[2*n -1 + i] = x; // upper diagonal
    }

    int get(int i, int j) {
        if (i - j == 1) return arr[i-1];
        else if (i == j) return arr[n-1 + i];
        else if (j - i == 1) return arr[2*n -1 + i];
        else return 0;
    }

    void display() {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    TriDiagonal td(4);
    td.set(0,0,5);
    td.set(0,1,7);
    td.set(1,0,2);
    td.set(1,1,9);
    td.set(1,2,6);
    td.set(2,1,4);
    td.set(2,2,8);
    td.set(2,3,1);
    td.set(3,2,3);
    td.set(3,3,2);

    cout << "Tri-diagonal Matrix:\n";
    td.display();
    return 0;
}




c)Lower triangular Matrix.
#include <iostream>
using namespace std;

class LowerTriangular {
    int n;
    int *arr;
public:
    LowerTriangular(int n) {
        this->n = n;
        arr = new int[n*(n+1)/2];
        for (int i = 0; i < n*(n+1)/2; i++) arr[i] = 0;
    }

    void set(int i, int j, int x) {
        if (i >= j) arr[i*(i+1)/2 + j] = x;
    }

    int get(int i, int j) {
        if (i >= j) return arr[i*(i+1)/2 + j];
        else return 0;
    }

    void display() {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    LowerTriangular lt(4);
    lt.set(0,0,5);
    lt.set(1,0,2); lt.set(1,1,6);
    lt.set(2,0,3); lt.set(2,1,7); lt.set(2,2,8);
    lt.set(3,0,4); lt.set(3,1,1); lt.set(3,2,9); lt.set(3,3,5);

    cout << "Lower Triangular Matrix:\n";
    lt.display();
    return 0;
}



d) Upper triangular Matrix.
#include <iostream>
using namespace std;

class UpperTriangular {
    int n;
    int *arr;
public:
    UpperTriangular(int n) {
        this->n = n;
        arr = new int[n*(n+1)/2];
        for (int i=0; i<n*(n+1)/2; i++) arr[i]=0;
    }

    void set(int i, int j, int x) {
        if (i <= j) arr[i*n - (i*(i-1))/2 + (j-i)] = x;
    }

    int get(int i, int j) {
        if (i <= j) return arr[i*n - (i*(i-1))/2 + (j-i)];
        else return 0;
    }

    void display() {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    UpperTriangular ut(4);
    ut.set(0,0,5); ut.set(0,1,2); ut.set(0,2,7); ut.set(0,3,6);
    ut.set(1,1,3); ut.set(1,2,8); ut.set(1,3,4);
    ut.set(2,2,9); ut.set(2,3,1);
    ut.set(3,3,2);

    cout << "Upper Triangular Matrix:\n";
    ut.display();
    return 0;
}




e)symmetric matrix.
#include <iostream>
using namespace std;

class UpperTriangular {
    int n;
    int *arr;
public:
    UpperTriangular(int n) {
        this->n = n;
        arr = new int[n*(n+1)/2];
        for (int i=0; i<n*(n+1)/2; i++) arr[i]=0;
    }

    void set(int i, int j, int x) {
        if (i <= j) arr[i*n - (i*(i-1))/2 + (j-i)] = x;
    }

    int get(int i, int j) {
        if (i <= j) return arr[i*n - (i*(i-1))/2 + (j-i)];
        else return 0;
    }

    void display() {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    UpperTriangular ut(4);
    ut.set(0,0,5); ut.set(0,1,2); ut.set(0,2,7); ut.set(0,3,6);
    ut.set(1,1,3); ut.set(1,2,8); ut.set(1,3,4);
    ut.set(2,2,9); ut.set(2,3,1);
    ut.set(3,3,2);

    cout << "Upper Triangular Matrix:\n";
    ut.display();
    return 0;
}










