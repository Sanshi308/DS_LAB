Q1.Write a program to implement following sorting techniques:
a. Selection Sort
b. Insertion Sort
c. Bubble Sort
d. Merge Sort
e. Quick Sort


#include <iostream>
using namespace std;

void display(int arr[], int n) {
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    cout << endl;
}

//selection sort
void selectionSort(int arr[], int n) {
    for(int i=0;i<n-1;i++) {
        int min=i;
        for(int j=i+1;j<n;j++) {
            if(arr[j] < arr[min])
                min = j;
        }
        swap(arr[i], arr[min]);
    }
}

// insertion sort
void insertionSort(int arr[], int n) {
    for(int i=1;i<n;i++) {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

//bubble sort
void bubbleSort(int arr[], int n) {
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}

//merge sort
void merge(int arr[], int low, int mid, int high) {
    int i=low, j=mid+1, k=0;
    int temp[100];

    while(i<=mid && j<=high) {
        if(arr[i] < arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while(i<=mid) temp[k++] = arr[i++];
    while(j<=high) temp[k++] = arr[j++];

    for(i=low;i<=high;i++)
        arr[i] = temp[i-low];
}

void mergeSort(int arr[], int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

//quick sort
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low+1, j = high;

    while(i <= j) {
        while(arr[i] <= pivot && i <= high)
            i++;
        while(arr[j] > pivot)
            j--;

        if(i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p-1);
        quickSort(arr, p+1, high);
    }
}


int main() {
    int n, choice;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100], temp[100];
    cout << "Enter array elements:\n";
    for(int i=0;i<n;i++)
        cin >> arr[i];

    do {
        for(int i=0;i<n;i++)
            temp[i] = arr[i];   

        cout << "\n--- SORTING MENU ---\n";
        cout << "1. Selection Sort\n";
        cout << "2. Insertion Sort\n";
        cout << "3. Bubble Sort\n";
        cout << "4. Merge Sort\n";
        cout << "5. Quick Sort\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
        case 1:
            selectionSort(temp,n);
            cout << "Selection Sort: ";
            display(temp,n);
            break;
        case 2:
            insertionSort(temp,n);
            cout << "Insertion Sort: ";
            display(temp,n);
            break;
        case 3:
            bubbleSort(temp,n);
            cout << "Bubble Sort: ";
            display(temp,n);
            break;
        case 4:
            mergeSort(temp,0,n-1);
            cout << "Merge Sort: ";
            display(temp,n);
            break;
        case 5:
            quickSort(temp,0,n-1);
            cout << "Quick Sort: ";
            display(temp,n);
            break;
        }
    } while(choice != 0);

    return 0;
}
