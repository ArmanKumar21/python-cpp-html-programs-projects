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
