int search(vector<int>& nums, int target) {
    int n = nums.size();
    int lo = 0;
    int hi = n-1;
    while(lo<hi){
        int mid = lo+(hi-lo)/2;
        if(nums[mid]>nums[hi]) lo = mid+1;
        else hi = mid;
    }
    int res = bs(nums,0,n-1,target,lo,n);
    return res;

}
int bs(vector <int>& arr,int start,int end,int target,int lo,int n){
    while(start<=end){
        // start = (start+lo)%n;
        // end = (end+start)%n;
        int mid = start+((end-start)/2);
        int realmid = (mid+lo)%n;
        if(arr[realmid]==target) return realmid;
        else if(arr[realmid]>target) end = mid-1;
        else start = mid+1;
    }
    return -1;
}
