#include <iostream>
#include <vector>

using namespace std;

void findMissingAndDuplicate(const vector<int>& arr) {
    int n = arr.size();
    int xorAll = 0;
    
    for (int i = 0; i < n; i++) {
        xorAll ^= arr[i];
        xorAll ^= (i + 1);
    }
    
    // Find the rightmost set bit in xorAll
    int rightmostSetBit = xorAll & -xorAll;

    int missing = 0, duplicate = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] & rightmostSetBit) {
            missing ^= arr[i];
        } else {
            missing ^= (i + 1);
        }
    }

    duplicate = xorAll ^ missing;
    
    cout << "Missing Number: " << missing << endl;
    cout << "Duplicate Number: " << duplicate << endl;
}

// Test Cases
// ->Test Case1:
// {4, 2, 7, 1, 5, 6, 2, 3}
// Missing Number: 8
// Duplicate Number: 2

// ->Test Case2:
// {1, 1, 3, 3, 5, 6, 6, 8}
// Missing Number: 4
// Duplicate Number: 1

// ->Test Case3:
// {9, 8, 7, 6, 5, 4, 3, 2, 1, 1}
// Missing Number: 10
// Duplicate Number: 1

// ->Test Case4:
// {10, 9, 8, 6, 5, 4, 3, 2, 1, 7}
// Missing Number: 6
// Duplicate Number: 7


int main() {
    vector<int> arr = {4, 3, 2, 7, 8, 2, 1, 5};
    findMissingAndDuplicate(arr);
    
    return 0;
}
