#include <bits/stdc++.h>
using namespace std;

int partiton(int arr[], int start, int end)
{
    int i = start - 1;
    int j = start;
    int pivot = arr[end];

    for(;j < end; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[end]);
    return i+1;
}

void quick_sort(int arr[], int start, int end)
{
    if (start >= end)
        return;

    int p = partiton(arr, start, end);
    quick_sort(arr, start, p - 1);
    quick_sort(arr, p + 1, end);
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size;

    cout << "Enter the size of array" << endl;
    cin >> size;

    int *arr = new int[size];

    cout << "Enter array of size " << size << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    quick_sort(arr, 0, size - 1);
    printArray(arr, size);
    return 0;
}