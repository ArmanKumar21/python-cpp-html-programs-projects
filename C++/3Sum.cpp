/*
The key idea is the same as the TwoSum problem. When we fix the 1st number, the 2nd and 3rd number can be found following the same reasoning as TwoSum.

The only difference is that, the TwoSum problem of LEETCODE has a unique solution. However, in ThreeSum, we have multiple duplicate solutions that can be found. Most of the OLE errors happened here because you could've ended up with a solution with so many duplicates.

The naive solution for the duplicates will be using the STL methods like below :

std::sort(res.begin(), res.end());
res.erase(unique(res.begin(), res.end()), res.end());

But according to my submissions, this way will cause you double your time consuming almostly.

A better approach is that, to jump over the number which has been scanned, no matter it is part of some solution or not.

If the three numbers formed a solution, we can safely ignore all the duplicates of them.

We can do this to all the three numbers such that we can remove the duplicates.

Here's my AC C++ Code:
*/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &num)
    {
        vector<vector<int>> rs;
        sort(num.begin(), num.end());
        int i, j, k;
        int n = num.size();
        for (i = 0; i < n - 2; i++)
        {
            j = i + 1;
            k = n - 1;
            while (j < k)
            {
                int sum = num[i] + num[j] + num[k];
                if (sum == 0)
                {
                    vector<int> tmp(3);
                    tmp[0] = num[i];
                    tmp[1] = num[j];
                    tmp[2] = num[k];
                    rs.push_back(tmp);
                    while (j < k && num[j] == tmp[1])
                        j++;
                    while (j < k && num[k] == tmp[2])
                        k--;
                }
                else if (sum > 0)
                {
                    k--;
                }
                else if (sum < 0)
                {
                    j++;
                }
            }
            while (i + 1 < num.size() && num[i + 1] == num[i])
                i++;
        }
        return rs;
    }
};
