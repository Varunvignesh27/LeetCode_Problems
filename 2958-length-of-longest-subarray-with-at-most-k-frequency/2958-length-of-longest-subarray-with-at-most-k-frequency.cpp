class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int l=0,r=0;
        int len = 0;

        while(r < n){
            mp[nums[r]]++;

            while(mp[nums[r]] > k){
                mp[nums[l]]--;
                l++;
            }
            
            len = max(len,r-l+1);
            r++;
        }

        return len;
    }
};