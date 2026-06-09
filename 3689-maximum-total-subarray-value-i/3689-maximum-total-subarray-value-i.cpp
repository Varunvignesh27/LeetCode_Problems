class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mini = INT_MAX,maxi = 0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            mini = min(mini,nums[i]);
            maxi = max(maxi,nums[i]);
        }

        long long ans = (maxi - mini) * 1ll * k ;
        return ans;
    }
};