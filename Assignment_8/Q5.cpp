Q5. Implement Heapsort (Increasing/Decreasing order).


#include <iostream>
using namespace std;


void heapifyMax(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyMax(arr, n, largest);
    }
}


void heapSortAsc(int arr[], int n) {

   
    for (int i = n/2 - 1; i >= 0; i--)
        heapifyMax(arr, n, i);


    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapifyMax(arr, i, 0);
    }
}


    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {40, 10, 30, 50, 60, 15};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSortAsc(arr, n);

    cout << "Ascending Order: ";
    display(arr, n);

    return 0;
}
