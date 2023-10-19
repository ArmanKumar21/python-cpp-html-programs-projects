#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2*i + 1;  // Left child
    int right = 2*i + 2;  // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);  // Swap the elements
        heapify(arr, n, largest);  // Recursively heapify the affected subtree
    }
}

void buildHeap(int arr[], int n) {
    // Build max heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void heapSort(int arr[], int n) {
    buildHeap(arr, n);  // Build a max heap

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);  // Move current root to end
        heapify(arr, i, 0);  // call max heapify on the reduced heap
    }
}

int main() {
    int arr1[] = {4, 1, 3, 9, 7};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);

    heapSort(arr1, n1);

    cout << "Sorted array: ";
    for (int i = 0; i < n1; i++)
        cout << arr1[i] << " ";
    cout << endl;

    int arr2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    heapSort(arr2, n2);

    cout << "Sorted array: ";
    for (int i = 0; i < n2; i++)
        cout << arr2[i] << " ";
    cout << endl;

    return 0;
}