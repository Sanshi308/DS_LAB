Space required to store any two-dimensional array is 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ 𝑟𝑜𝑤𝑠 × 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ
𝑐𝑜𝑙𝑢𝑚𝑛𝑠. Assuming an array is used to store elements of the following matrices,
implement an efficient way that reduces the space requirement.
(a) Diagonal Matrix.
(b) Tri-diagonal Matrix.
(c) Lower triangular Matrix.
(d) Upper triangular Matrix.
(e) Symmetric Matrix
ans:-
#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int diag[n] = {1, 2, 3, 4}; // only store diagonal elements

    cout << "Diagonal Matrix: " << endl;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i==j) cout<<diag[i]<<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
    return 0;
}


