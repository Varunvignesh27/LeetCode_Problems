class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int  n = nums.size();
        int res = nums[0];
        int cur = nums[0];

        for(int i=1;i<n;i++){
            cur = max(nums[i],cur+nums[i]);
            res = max(res,cur);
        }
        return res;
    }
};