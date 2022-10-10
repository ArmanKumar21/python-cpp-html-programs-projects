#include <iostream>
#include <algorithm>

using namespace std;

int minimize_height_II(int arr[], int n, int k) {
	sort(arr, arr + n);
	// for (int i = 0 ; i < n ; i++) cout << arr[i] << " ";
	// cout << endl;
	int curr_min = arr[0];
	int curr_max = arr[n - 1];

	int ans = curr_max - curr_min;
	// cout << curr_max << " " << curr_min << endl;
	// cout << ans << endl;

	for (int i = 1; i < n; i++) {
		// increase
		curr_min = min(arr[i] - k, arr[0]+k);
		// decrease
		curr_max = max(arr[i-1] + k, arr[n-1]-k);

		// cout << curr_min << "   " << arr[i] << " - "<< k << "   "<< arr[i]-k << endl;
		// cout << curr_max << "   " << arr[i] << " + "<< k << "   "<< arr[i]+k << endl;
		// cout << endl;
		
		ans = min(curr_max - curr_min, ans);

	}

	return ans;

}

int main()
{
    int a[]{1, 5, 8, 10};
    int n{4};
    int k{2};

    cout << minimize_height_II(a, n, k);
    return 0;
}