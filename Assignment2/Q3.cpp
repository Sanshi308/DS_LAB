a) linear time :-
  
#include <iostream>
using namespace std;

int findMissingLinear(int arr[], int n) {
    int total = (n+1) * (n+2) / 2; 
    for(int i = 0; i < n; i++)
        total -= arr[i];
    return total;
}

int main() {
    int arr[] = {1, 2, 3, 5, 6};
    int n = 5;
    cout << "Missing Number = " << findMissingLinear(arr, n);
    return 0;
}

b) using binary search:-

#include <iostream>
using namespace std;

int findMissingBinary(int arr[], int n) {
    int low = 0, high = n-1;
    while(low <= high) {
        int mid = (low+high)/2;
        if(arr[mid] == mid+1) 
            low = mid+1;
        else 
            high = mid-1;
    }
    return low+1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8};
    int n = 7;
    cout << "Missing Number = " << findMissingBinary(arr, n);
    return 0;
}
