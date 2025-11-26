Q2.A slightly improved selection sort – We know that selection sort algorithm takes the minimum on
every pass on the array, and place it at its correct position. The idea is to take also the maximum on
every pass and place it at its correct position. So in every pass, we keep track of both maximum and
minimum and array becomes sorted from both ends. Implement this logic.


#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int minIndex = left;
        int maxIndex = right;

        // Find minimum and maximum in remaining array
        for (int i = left; i <= right; i++) {
            if (arr[i] < arr[minIndex])
                minIndex = i;
            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        // Swap minimum with left boundary
        swap(arr[left], arr[minIndex]);

        // If max was swapped, correct its index
        if (maxIndex == left)
            maxIndex = minIndex;

        // Swap maximum with right boundary
        swap(arr[right], arr[maxIndex]);

        left++;
        right--;
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {5, 2, 9, 1, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    improvedSelectionSort(arr, n);

    cout << "Sorted array: ";
    display(arr, n);

    return 0;
}
