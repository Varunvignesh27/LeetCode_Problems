class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int ans = 0;
        int n = nums.size();
        int curr = 0;
        for(int i=0;i<n;i++){
            curr += nums[i];
            if(curr > 0)
                ans++;
        }

        return ans;
    }
};