/*Hey ! Please help me with this issue. You can solve it with python or cpp then you need to make a pull request.

Given two arrays A and B of equal size N, the task is to find if given arrays are equal or not. Two arrays are said to be equal if both of them contain same set of elements, arrangements (or permutation) of elements may be different though.
Note : If there are repetitions, then counts of repeated elements must also be same for two array to be equal.

Example 1:

Input:
N = 5
A[ ] = {1,2,5,4,0}
B[ ] = {2,4,5,0,1}
Output: 1
Explanation: Both the array can be
rearranged to {0,1,2,4,5}
Example 2:

Input:
N = 3
A[ ] = {1,2,5}
B[ ] = {2,4,15}
Output: 0
Explanation: A[] and B[] have only
one common value.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, flag = 1;
    cin >> n;
    int arr[n], brr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> brr[i];
    }
    sort(arr, arr + n);
    sort(brr, brr + n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != brr[i])
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        cout << 1 << endl;
        return 0;
    }
    else
    {
        cout << 0 << endl;
        return 0;
    }
}