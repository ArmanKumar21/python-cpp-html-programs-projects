#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0),
        cin.tie(0);

    int n;
    cin >> n;

    int arr[n + 2];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    int res = 0;

    for (int mask = 0; mask < (1LL << n); mask++)
    {
        int curr = 0;
        for (int j = 0; j < n; j++)
            if (mask & (1 << j))
                curr = curr ^ arr[j + 1];

        res = max(res, curr);
    }

    cout << "MAX XOR is : " << res;
}
