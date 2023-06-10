// Left Rotation by d positions/
#include <iostream>

void rotate(int arr[], int d, int n)
{
    int count = 1;
    while (count <= d) {
        int last = arr[0];
        for (int i = 0; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        arr[n - 1] = last;
        count++;
    }
}
 
// Function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
}
 
int main()
{   int n ;
    std::cout<<"Enter Size of the Array :/";
    std::cin>>n;
    int arr[n],d;
    std::cout<<std::endl<<"Enter "<<n<<" Elements in the Array :/";
    for(short i=0;i < n;i++){
        std::cin>>arr[i];
    }
    std::cout<<std::endl<<"Enter the Left Rotation Offset (d) :/";
    std::cin>>d;
    std::cout<<std::endl<<"Before Rotation :/";
    printArray(arr, n);
    rotate(arr, d, n);
    std::cout<<std::endl<<"After Rotation :/";
    printArray(arr, n);
 
    return 0;
}