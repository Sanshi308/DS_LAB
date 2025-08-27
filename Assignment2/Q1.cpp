1) Implement the binary search algorithm regarded as a fast search algorithm
with run-time complexity of Ο(log n) in comparison to the Linear Search.
ans:- 
#include <iostream>
using namespace std;


int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key)
            return i; 
    }
    return -1; 
}


int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == key)
            return mid; 
        else if(arr[mid] < key)
            low = mid + 1; 
        else
            high = mid - 1; 
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    int key = 30;

    cout << "Linear Search result: " << linearSearch(arr, n, key) << endl;
    cout << "Binary Search result: " << binarySearch(arr, n, key) << endl;
    return 0;
}
