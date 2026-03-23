class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int curr = 0,minlen = INT_MAX;
        int l = 0 , r = 0;

        while(r < n){
            curr += nums[r];

            while(curr >= target){
                minlen = min(minlen,r-l+1);
                curr -= nums[l];
                l++;
            }

            r++;
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};