8) Write a program to count the total number of distinct elements in an array of
length n.
ans:-
    
#include <iostream>
using namespace std;

int countDistinct(int arr[], int n) {
    int count = 0;
    for(int i=0;i<n;i++) {
        bool flag = false;
        for(int j=0;j<i;j++) {
            if(arr[i] == arr[j]) { flag=true; break; }
        }
        if(!flag) count++;
    }
    return count;
}

int main() {
    int arr[] = {1,2,2,3,4,4,5};
    int n = 7;
    cout << "Distinct Elements = " << countDistinct(arr, n);
    return 0;
}
