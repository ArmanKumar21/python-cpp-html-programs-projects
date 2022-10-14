public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int i,low,high;
        if(nums.size()<3)
            return result;
        sort(nums.begin(),nums.end());
        for(i=0;i<nums.size()-2;i++)
        {
            low=i+1;high=nums.size()-1;
            while(low<high)
            {
                if(i!=0 && nums[i]==nums[i-1])
                {
                    break;
                }
                else if((nums[low]+nums[high])==-nums[i])
                {
                    vector<int> triplet;
                    triplet.push_back(nums[low]);
                    triplet.push_back(nums[high]);
                    triplet.push_back(nums[i]);
                    result.push_back(triplet);
                    while(low<high && nums[low]==nums[low+1])
                        low++;
                    while(low<high && nums[high]==nums[high-1])
                        high--;
                    low++;high--;
                }
                else if((nums[low]+nums[high])>-nums[i])
                {
                    high--;
                }
                else if((nums[low]+nums[high])<-nums[i])
                {
                    low++;
                }
            }
        }
        return result;
    }
};
