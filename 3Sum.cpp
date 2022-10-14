3Sum problem

// code

#include <bits/stdc++.h>
using namespace std;

void findTriplets(int arr[], int n)
{
	bool found = false;

	for (int i = 0; i < n - 1; i++) {
		unordered_set<int> s;
		for (int j = i + 1; j < n; j++) {
			int x = -(arr[i] + arr[j]);
			if (s.find(x) != s.end()) {
				printf("%d %d %d\n", x, arr[i], arr[j]);
				found = true;
			}
			else
				s.insert(arr[j]);
		}
	}

	if (found == false)
		cout << " No Triplet Found" << endl;
}
int main()
{
	int arr[] = { 0, -1, 2, -3, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	findTriplets(arr, n);
	return 0;
}
