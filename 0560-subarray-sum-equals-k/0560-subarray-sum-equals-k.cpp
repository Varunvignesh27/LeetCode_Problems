class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int ans = 0,curr= 0;

        mp[0] = 1;
        for(int r =0 ;r<n;r++){
            curr += nums[r];
            if(mp.find(curr-k) != mp.end())
                ans += mp[curr-k];

            mp[curr]++;
        }
        return ans;
    }
};